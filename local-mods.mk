DOXYFILE_EXAMPLE_PATH = resources/docs
DOXYFILE_IMAGE_PATH = resources/docs

# suppression of non-virtual destructor warning from boost
# serialization (until the fix goes in to boost)
CXX_FLAGS += -Wno-non-virtual-dtor
