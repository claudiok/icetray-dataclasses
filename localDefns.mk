CXX_SRC_SUFFIX := cxx
CXX_BIN_SUFFIX := exe
# this should be set here.  see common.mk and localTargets.mk for the workaround
#ROOTCINT_MINUS_P := -p
DUMMY_TOOLS += boost

BOOSTFLAGS := -DBOOST_DISABLE_THREADS -DBOOST_NO_MEMBER_TEMPLATES 
CXX_FLAGS += $(BOOSTFLAGS)

