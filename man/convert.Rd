% file testpkg/man/doFun.Rd
%
\name{convert}
\alias{slice_as_object}
\title{
Convert functions
}
\description{
Convert functions
}
\usage{
slice_as_object(x)
}
\arguments{
  \item{x}{any R object}
}
\value{
  The result is an External Pointer
}
\details{
 Convert functions.
}
\note{
 more sanity checks and object types to be implemented
}
\author{S. M. Iacus}
\examples{
require(opendp)
x <- slice_as_object(c(1,2,3))
x
str(x)
y <- slice_as_object(c(1L,2L,3L))
y
str(y)
x <- NULL
}
\keyword{nonparametric}

