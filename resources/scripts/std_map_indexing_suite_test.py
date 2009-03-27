#!/usr/bin/env python
#
# std_map_indexing_suite_test.py
#
# A test suite demonstrating the additional python-side features
# of the std_map_indexing_suite wrapper for std::map
# JvS 2009-03-26

import unittest

class I3MapStringDoubleTest(unittest.TestCase):
	"""A demonstration of the more pythonic features in std_map_index_suite"""
	def setUp(self):
		from icecube import icetray,dataclasses
		self.map = dataclasses.I3MapStringDouble()
		self.sourceDict = {'foo': 1.2, 'bar': 3.7, 'baz': 42.9}
		for k in self.sourceDict.keys(): self.map[k] = self.sourceDict[k]
	def testAssignment(self):
		"""The values in sourceDict were copied to map"""
		for k in self.sourceDict.keys():
			self.assertEquals(self.map[k],self.sourceDict[k])
	def testKeys(self):
		"""map.keys() returns a list of keys"""
		keys = self.map.keys()
		for k in keys:
			self.assertTrue(k in self.sourceDict.keys())
	def testKeyIterables(self):
		"""Various equivalent ways of getting the keys"""
		self.assertEquals(self.map.keys(), [ key           for key       in self.map.iterkeys() ])
		self.assertEquals(self.map.keys(), [ key           for key,value in self.map            ])
		self.assertEquals(self.map.keys(), [ entry.key()   for entry     in self.map            ])
		self.assertEquals(self.map.keys(), [ entry.first() for entry     in self.map            ])
	def testValueIterables(self):
		"""Various equivalent ways of getting the values"""
		self.assertEquals(self.map.values(), [ value          for value     in self.map.itervalues() ])
		self.assertEquals(self.map.values(), [ value          for key,value in self.map              ])
		self.assertEquals(self.map.values(), [ entry.data()   for entry     in self.map              ])
		self.assertEquals(self.map.values(), [ entry.second() for entry     in self.map              ])
	def testIterators(self):
		"""Iterators work for keys, values, and (k,v) tuples"""
		self.assertTrue( type( self.map.iteritems().next()  ) == tuple                             )
		self.assertTrue( type( self.map.iterkeys().next()   ) == type( self.sourceDict.keys()[0]   ))
		self.assertTrue( type( self.map.itervalues().next() ) == type( self.sourceDict.values()[0] ))
	def testHasKey(self):
		"""map.has_key() is equivalent to 'key in map'"""
		key = self.sourceDict.keys()[0]
		self.assertTrue(key in self.map)
		self.assertEquals(key in self.map, self.map.has_key(key))
	def testCopyKeys(self):
		"""can produce a new, equivalent dict from sourceDict via dict.update(map)"""
		d = dict(); d.update(self.map)
		self.assertEquals(self.sourceDict, d)
	def testPairUnpacking(self):
		"""the wrapped std::pair can be unpacked automatically"""
		for entry in self.map:
			key,value = entry
			self.assertEquals(key, entry.key())
			self.assertEquals(key, entry.first())
			self.assertEquals(value, entry.data())
			self.assertEquals(value, entry.second())
	def testPairIndexing(self):
		"""elements of the wrapped std::pair can be accessed by index"""
		for entry in self.map:
			self.assertEquals(entry[0], entry.key())
			self.assertEquals(entry[-1], entry.data())
			self.assertEquals(entry[-2], entry.key())
			self.assertEquals(entry[1], entry.data())
			self.assertRaises(IndexError, entry.__getitem__, -3)
			self.assertRaises(IndexError, entry.__getitem__, 2)
			self.assertEquals([entry.key(),entry.data()], list(entry))
			self.assertEquals(len(entry), 2)

class I3MapUnsignedUnsignedTest(I3MapStringDoubleTest):
	def setUp(self):
		from icecube import icetray,dataclasses
		self.map = dataclasses.I3MapUnsignedUnsigned()
		self.sourceDict = {2: 1, 7: 3, 11: 42}
		for k in self.sourceDict.keys(): self.map[k] = self.sourceDict[k]

class I3MapKeyDoubleTest(I3MapStringDoubleTest):
	def setUp(self):
		from icecube import icetray,dataclasses 
		i,d = icetray,dataclasses
		self.map = d.I3MapKeyDouble()
		self.sourceDict = {i.OMKey(0,1): 1.2, i.OMKey(7,19): 3.7, i.OMKey(11,42): 42.11}
		for k in self.sourceDict.keys(): self.map[k] = self.sourceDict[k]

# FIXME: the I3MapIntVectorInt wrapper will only take std::vector<int>, not I3VectorInt. why?
# class I3MapIntVectorIntTest(I3MapStringDoubleTest):
# 	def setUp(self):
# 		from icecube import icetray,dataclasses
# 		self.map = dataclasses.I3MapIntVectorInt()
# 		v1 = dataclasses.I3VectorInt() 
# 		v2 = dataclasses.I3VectorInt() 
# 		v3 = dataclasses.I3VectorInt() 
# 	  	for i in [1,2,3]: v1.append(i) 
#                 for i in [4,5,6]: v2.append(i) 
#                 for i in [7,8,9]: v3.append(i) 
# 		self.sourceDict = {1: v1, 2: v2, -42: v3}
# 		self.map[0] = v1
# 		for k in self.sourceDict.keys(): self.map[k] = self.sourceDict[k]

if __name__ == '__main__':
	unittest.main()
