# put a file in private containing main()
# add CXX_BIN_NAMES := myfile

ROOT_BIN_NAMES := 

# This will create two binaries which do the same thing due to the way
# things are linked in makev1 (and other projects like phys-services
# will run the tests from this library... This is a bug.  Things are
# set up this way for compatibility with makev2, which links things
# differently, doesn't have the bug
CXX_BIN_NAMES := dataclasses-test dataclasses-test-autogen
ROOT_EXCLUDE_NAMES := 
ROOT_NON_CLASSES := 
ROOT_TEMPLATES := 
USES_PROJECTS := icetray 
USES_TOOLS := root log4cplus
#HEADERONLY_TOOLS = roost
