#!/usr/bin/env python

import unittest
from icecube import dataclasses
from I3Tray import I3Units

class Mytest(unittest.TestCase):

	def test_example(self):
		t = dataclasses.TriggerKey() 
		print t
		t2 = dataclasses.TriggerKey(dataclasses.I3Trigger.EXTERNAL, dataclasses.I3Trigger.STRING)
		print t2
		t3 =  dataclasses.TriggerKey(dataclasses.I3Trigger.AMANDA_MUON_DAQ, dataclasses.I3Trigger.STRING)
		print t3
		t4 =  dataclasses.TriggerKey(dataclasses.I3Trigger.AMANDA_TWR_DAQ, dataclasses.I3Trigger.STRING)
		print t4


unittest.main()
