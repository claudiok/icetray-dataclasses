#
#  $Id: localDefns.mk,v 1.9 2004/08/13 09:17:05 troy Exp $
#
#  See common.mk in the tools directory, look for -include localDefns.mk
#  to see what comes before (and after) this file.
#  OBSERVE THE DIFFERENCE between  
#     SOMEVAR = something
#  and
#     SOMEVAR := something
#  the former is recursively expanded
#  the latter is expanded only once, when it is seen for the first time.
#
CXX_SRC_SUFFIX := cxx
CXX_BIN_SUFFIX := exe

USES_TOOLS += roost TUT
DUMMY_TOOLS += roost TUT

DOXYFILE_EXAMPLE_PATH = resources/docs
DOXYFILE_IMAGE_PATH = resources/docs
