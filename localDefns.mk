#
#  $Id: localDefns.mk,v 1.7 2004/08/05 12:39:12 troy Exp $
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

USES_TOOLS += roost
DUMMY_TOOLS += roost

