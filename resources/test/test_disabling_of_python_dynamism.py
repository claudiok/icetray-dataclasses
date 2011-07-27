#!/usr/bin/env python
from icecube.icetray.I3Test import *
from icecube import dataclasses as dc
import inspect
from icecube.icetray import test_disabling_of_python_dynamism as test_freeze

# the default is an empty list so this is really not needed, but
# is here as a reminder that you can skip classes
skip_these = [""]
ENSURE( test_freeze.test_all_classes(dc, skip_these) , "not cool" )
