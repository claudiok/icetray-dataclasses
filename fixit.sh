#!/bin/sh
# this script fixes the problem that log4cpp isn't loaded when an
# executable is run.  run this script from you workspace
# You don't need to if you're just building libraries.
# -J.Pretz

cd tools/Linux-i386/lib/ ; ln -sf liblog4cpp.so liblog4cpp.so.3
