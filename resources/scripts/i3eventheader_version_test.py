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

#
# Default configuration of the I3Muxer and the I3ReaderServices. 
# Streams from the test file that don't apply to current test are
# not read in.

workspace = expandvars("$I3_SRC")
infile = workspace + "/dataclasses/resources/testdata/vsn99_eventheader.i3"
tray.AddService("I3ReaderServiceFactory","i3reader")(
    ("Filename", infile)
    )

tray.AddModule("I3Muxer","muxer")    # should throw error due to version number

tray.AddModule("TrashCan","adios")

try:
	tray.Execute()  # should result in throw
except:
	sys.exit(0) # indicate successfully passed test

sys.exit(1)  # indicate failure (didn't throw when given bad vsn number)
