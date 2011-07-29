#!/usr/bin/env python
from icecube.icetray.I3Test import *
from icecube import dataclasses as dc
import inspect
from icecube.icetray import test_disabling_of_python_dynamism as test_freeze

# the default is an empty list so this is really not needed, but
# is here as a reminder that you can skip classes
# not going to worry about these
skip_these = ["I3SuperDST","I3RecoPulseSeriesMapMask",\
              "map_indexing_suite_map_Subdetector_I3TriggerReadoutConfig_entry",
              "PairDoubleDouble"]
ENSURE( test_freeze.test_all_classes(dc, skip_these) , "not cool" )
