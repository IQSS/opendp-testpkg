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
   {NULL, NULL, 0},
};

void R_init_testpkg(DllInfo *info)
{
    R_registerRoutines(info, R_CDef, NULL, NULL, NULL);
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


 
