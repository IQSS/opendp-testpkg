# .onAttach <- function(libname, pkgname) {
#     # we need to make this path configurable
#     Sys.setenv(OPENDP_LIB_DIR="/Users/jago/github/opendp/rust/target/debug/")
#     Pver <- read.dcf(file=system.file("DESCRIPTION", package=pkgname),
#                       fields="Version")
#     packageStartupMessage(paste(pkgname, Pver))
#     packageStartupMessage("OpenDP R binding test package")
#     packageStartupMessage("Please use") 
#     packageStartupMessage("") 
#     packageStartupMessage("Sys.setenv(OPENDP_LIB_DIR='path to libopendp.dylib dir')")
#     packageStartupMessage("") 
#     packageStartupMessage("to specify where the opendl dynamic library exists")
#     
#     dyld <- dyn.load(file.path(Sys.getenv("OPENDP_LIB_DIR"),"libopendp.dylib"), type="External")
#     getDLLRegisteredRoutines("libopendp.dylib")
#    # we should mimic _lib.py to support generic installations 
# }

