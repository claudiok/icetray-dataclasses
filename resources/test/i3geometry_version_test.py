#!/usr/bin/env python
#
# Version Checking Test:
#
# Attempts to read in an .i3 file that contains a dataclass
# instantiation with a version number (99) greater than the running
# software dataclass version.  Verifies that a fault is thrown
# by the dataclass.
#

from I3Tray import *

from os.path import expandvars

import os
import sys

load("libicetray")
load("libdataclasses")
load("libdataio")
load("libexamples")

tray = I3Tray()

workspace = expandvars("$I3_SRC")
infile = workspace + "/dataclasses/resources/testdata/vsn99_geometry.i3"

tray.AddModule("I3Reader","reader", Filename =  infile)    # should throw error due to version number

tray.AddModule("TrashCan","adios")

try:
	tray.Execute()  # should result in throw
except:
	sys.exit(0) # indicate successfully passed test
else:
	sys.exit(1)  # indicate failure (didn't throw when given bad vsn number)
