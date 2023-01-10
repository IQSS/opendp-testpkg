% file testpkg/man/doFun.Rd
%
\name{createODP}
\alias{createODP}
\alias{setODP}
\alias{getODP}
\title{
Creating and managing external pointers
}
\description{
Creating and managing external pointers
}
\usage{
createODP(info = "My OpenDP obj")
setODP(x, str = "")
getODP(x)
}
\arguments{
  \item{x}{the external pointer}       
  \item{str}{a string}
  \item{info}{any R object, but we can use it to store the opendp library Type}
}
\value{
  The result is an External Pointer
}
\details{
  Test functions to create, set and get external pointer objects.
  Hard coded in C maximal string length equal to 15 chars.
}
\note{
 more sanity checks to be implemented
}
\author{S. M. Iacus}
\examples{
require(opendp)
x <- createODP("my info")
x # it's just a pointer to memory
str(x) # it says only <externalptr> 
getODP(x) # return default initialized string
setODP(x, "my own string") # sets the content, returns TRUE
getODP(x)
x <- NULL  
# we removed the object from R workspace
# the finalizer will be called internally from C
# when the R garbage collector frees memory
}
\keyword{nonparametric}

