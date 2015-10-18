#!/usr/bin/env python

import unittest
from icecube import dataclasses
from I3Tray import I3Units

class Mytest(unittest.TestCase):

	def test_example(self):
		t = dataclasses.TriggerKey()
		print t
		#self.assertEqual(False, True, "these should be equal")

unittest.main()
