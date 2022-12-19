### file testpkg/R/doFun.R

# x : apply square function from C
squareIt <- function(x){
 .Call("square_It",x, PACKAGE="testpkg")
}

# apply any function to x
applyFun <- function(x, fun = NULL){
  .Call("apply_Fun",x,fun, new.env(), PACKAGE="testpkg")
}

