#!/usr/bin/env python

import unittest
from icecube import dataclasses

class TestI3MCHit(unittest.TestCase):


    def test_I3MCHit_string(self):
        hit1 = dataclasses.I3MCHit()
        hit2 = dataclasses.I3MCHit()

        self.assertEqual(hit1.__str__(), hit2.__str__(), "these should be the same.")


unittest.main()
