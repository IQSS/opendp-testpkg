/*
 *  R : A Computer Language for Statistical Data Analysis
 *  Copyright (C) 2001-2002	S. M. Iacus
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *
 * Exports
 *	ifs_df(...)
 *  ifs_df_flex(...)
 *
 * to be called as  .C(.)  in ../R/ifs.R
 */



#include <R.h>
#include <Rmath.h>
#include <R_ext/Boolean.h>
#include <R_ext/Rdynload.h>
#include <Rdefines.h>
#include <Rinternals.h>
#include <R_ext/Complex.h>

/* headers */
SEXP square_It(SEXP x);
SEXP apply_Fun(SEXP x, SEXP f, SEXP rho);


/* Two functions adapted from the code in man/doc/R-exts */
SEXP mkans(double x);
double feval(double x, SEXP f, SEXP rho);


static SEXP OPENDP_tag; // tag for external pointer objects
// we should change this later to AnyObject or similar

#define CHECK_OPENDP_OBJECT(s) do {          \
if (TYPEOF(s) != EXTPTRSXP ||             \
    R_ExternalPtrTag(s) !=  OPENDP_tag) \
  error("bad OpenDP object");           \
} while (0)


// new function headers 
SEXP create(SEXP info);
SEXP get(SEXP XPtr);
SEXP set(SEXP XPtr, SEXP str);
  
  
// taken from here with some changes
// https://stackoverflow.com/questions/7032617/storing-c-objects-in-r
// See also: http://homepage.divms.uiowa.edu/~luke/R/simpleref.html
// My old pkg RRP  https://github.com/siacus/rrp
// and of course R Devel guide
// https://cran.rstudio.com/doc/manuals/r-devel/R-exts.html#External-pointers-and-weak-references


// finalizer is call when the object is clear on the R side with
// something like obj <- NULL

static void _finalizer(SEXP XPtr){
  if (NULL == R_ExternalPtrAddr(XPtr))
    return;
  CHECK_OPENDP_OBJECT(XPtr); 
  Rprintf("finalizing\n");
  char *ptr = (char *) R_ExternalPtrAddr(XPtr);
  Free(ptr);
  R_ClearExternalPtr(XPtr);
}

const int N_MAX=15;

// this creates a C object and embeds it in an R object
SEXP create(SEXP info){
  char *x = Calloc(N_MAX, char);
  snprintf(x, N_MAX, "I am an OpenDP obj");
  SEXP XPtr = PROTECT(R_MakeExternalPtr(x, OPENDP_tag, info));
  R_RegisterCFinalizerEx(XPtr, _finalizer, TRUE); // important to register the proper fnalizer
  UNPROTECT(1);
  
  return XPtr;
}

SEXP get(SEXP XPtr){
  return mkString((char *) R_ExternalPtrAddr(XPtr));
}


SEXP set(SEXP XPtr, SEXP str){
  char *x = (char *) R_ExternalPtrAddr(XPtr);
  snprintf(x, N_MAX, CHAR(STRING_ELT(str, 0)));
  return ScalarLogical(TRUE);
}


/* function bodies */
SEXP apply_Fun(SEXP x, SEXP f, SEXP rho)
{
  SEXP ans;
  double *retval, *myx;
  if(!isNumeric(x)) error("`x' must be numeric");
  PROTECT(x = AS_NUMERIC(x));
  PROTECT(ans = NEW_NUMERIC(1));
  retval = NUMERIC_POINTER(ans);
  myx = NUMERIC_POINTER(x); /* maps myx double pointer to a R numeric pointer */

  *retval =  feval(*myx, f, rho);   
  UNPROTECT(2);
  return( ans ); 
}


SEXP square_It(SEXP x)
{
  double myx=0, *retval;
  SEXP ans;
  
  if(!isNumeric(x)) error("`x' must be numeric"); /* sanity check */
  PROTECT(x = AS_NUMERIC(x)); /* protects the input x */
  PROTECT(ans = NEW_NUMERIC(1)); /* creates and protects the return value */
  
  myx = *NUMERIC_POINTER(x); /* copies 'x' numericn into 'myx' */

  retval = NUMERIC_POINTER(ans); /* maps 'retval' double pointer to a the 'ans' R numeric pointer */
  /* here I could have done similarly to the above, just to show the pointer version */
  
  *retval = myx*myx; /* do the squaring */
  UNPROTECT(2); /* unprotect objects before returning to R */
  return(ans); 
}

/* dll entry points */
static R_CMethodDef R_CDef[] = {
   {"square_It", (DL_FUNC)&square_It, 1}, /* here you register the DLL entry points to local C functions and explicit the number of arguments */
   {"apply_Fun", (DL_FUNC)&apply_Fun, 3},
   {"create", (DL_FUNC)&create, 1},
   {"get", (DL_FUNC)&get, 1},
   {"set", (DL_FUNC)&set, 2},
   {NULL, NULL, 0},
};


void R_init_opendp(DllInfo *info)
{
    R_registerRoutines(info, R_CDef, NULL, NULL, NULL);
    OPENDP_tag = install("OPENDP_TAG");
    R_useDynamicSymbols(info, TRUE);
}

SEXP mkans(double x)
{
    SEXP ans;
    PROTECT(ans = allocVector(REALSXP, 1));
    REAL(ans)[0] = x;
    UNPROTECT(1);
    return ans;
}

double feval(double x, SEXP f, SEXP rho)
{
    double val;
    SEXP R_fcall;    
    SEXP sx = install("x");
    defineVar(sx, mkans(x), rho);
    PROTECT(R_fcall = lang2(f, mkans(x)));
    val = *NUMERIC_POINTER(eval(R_fcall, rho));
    UNPROTECT(1);
    return(val);
}


 
