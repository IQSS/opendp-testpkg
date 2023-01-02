### file opendp/R/doFun.R



# creates an external pointer
createODP <- function(info = "My OpenDP obj"){
  .Call("create",info, PACKAGE="opendp")
}

setODP <- function(x, str = ""){
  .Call("set", x, str, PACKAGE="opendp")
}

getODP <- function(x){
  .Call("get",x, PACKAGE="opendp")
}



# x : apply square function from C
squareIt <- function(x){
 .Call("square_It",x, PACKAGE="opendp")
}

# apply any function to x
applyFun <- function(x, fun = NULL){
  .Call("apply_Fun",x,fun, new.env(), PACKAGE="opendp")
}

