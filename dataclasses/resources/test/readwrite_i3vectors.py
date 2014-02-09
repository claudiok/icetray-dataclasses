#!/usr/bin/env python

from icecube import icetray, dataclasses, dataio
from os.path import expandvars
from pprint import pprint
import md5

is_fail = False


def do_one(Type, name, gen, checksum):
    print "Writing", Type,
    global is_fail
    name += '.i3'
    i3f = dataio.I3File(name, dataio.I3File.Mode.Writing)
	
    tinst = Type()
    i = 0
    for value in gen:
	tinst.append(value)
	i += 1
    print i, "entries." 
    frame = icetray.I3Frame()
    frame[name] = tinst

    i3f.push(frame)
    i3f.close()

    f = open(name)
    data = f.read()
    hsh = md5.md5()
    hsh.update(data)
    hd = hsh.hexdigest()
    if (hd != checksum):
	print "****************** ERRORZ ERRORZ ***********************"
	print "%s != %s (file %s, %u bytes)" % ( hd, checksum, name, len(data) )
	is_fail = True

def check_on(Type, name, gen):
    print "Reading", Type,
    global is_fail
    name += '.i3'
    i3f = dataio.I3File(name, dataio.I3File.Mode.Reading)
    frame = i3f.pop_frame()
    thing = frame[name]

    i = 0
    for value in gen:
	if not (thing[i] == value):
	    print "********************* FAIL ***********************"
	    print "at ", i, ", ", thing[i], " != ", value
	    is_fail = True
	i += 1
    print "checked", i, "entries."

    
def gen(n):
    value = 0;
    while value < n:
	yield value
	value+= 1

def vc_gen():
    n = 0
    while n < 255:
	yield chr(n)
	n += 1
	
def bool_gen(max):
    n = 0
    while n < max:
	yield n % 3 == 0
	n += 1
	
checks = [(dataclasses.I3VectorBool, "vector_bool",
	   (bool_gen, [20000]), '0a21e6624b44552fdb5f986c58f90469'),
	  (dataclasses.I3VectorChar, "vector_char",
	   (vc_gen, []), '2c4b8295e7e527857d26d841d7878805'),
	  (dataclasses.I3VectorShort, "vector_short",
	   (gen, [5000]), '919f2278c67291bb9e5284a15bff2cc2'),
	  (dataclasses.I3VectorUShort, "vector_ushort",
	   (gen, [5000]), '56bf25882f4b6fc7044e493974c3de6e'),
	  (dataclasses.I3VectorInt, "vector_int",
	   (gen, [5000]), '8a4dcf279a0474df33d14758b886afa6'),
	  (dataclasses.I3VectorUInt, "vector_uint",
	   (gen, [5000]), '4444059dd3c507a317acf662f9a026b1'),
	  (dataclasses.I3VectorFloat, "vector_float",
	   (gen, [5000]), 'aa14bac776a4ef6cad7da33ec653ae00'),
	  (dataclasses.I3VectorDouble, "vector_double",
	   (gen, [5000]), '0adb7f5d91c06bfde9ebd6d3e9c38b42'),
	  (dataclasses.I3VectorInt64, "vector_int64",
	   (gen, [5000]), '37707be44fbb8e4aad4e3853638ae6c6'),
	  (dataclasses.I3VectorUInt64, "vector_uint64",
	   (gen, [5000]), '47a5dd7104618793e72e807fba819dea')]

for (T, N, (GEN,ARGS), CHECKSUM) in checks:
    do_one(T, N, GEN(*ARGS), CHECKSUM)
    check_on(T, N, GEN(*ARGS))
    

