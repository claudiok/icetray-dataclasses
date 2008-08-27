Dataclasses documentation
=========================

Dataclasses needs docs.  One section I'm looking forward to writing is:

Python bindings to dataclasses
------------------------------

Examples
^^^^^^^^


Getting the energy of the most energetic primary
""""""""""""""""""""""""""""""""""""""""""""""""

.. code-block:: pycon

  In [1]: from icecube import icetray, dataclasses, dataio

  In [2]: f = dataio.I3File("/v/icecube/data/combinedMC600.i3")
  Logging configured from file log4cplus.conf
  
  In [3]: frame = f.pop_physics()
  
  In [4]: print frame
  [ I3Frame  (P):
    'BadOMSelection' [P] ==> I3Vector<OMKey>
    'CalibratedATWD' [P] ==> I3Map<OMKey, std::vector<I3Waveform, std::allocator<I3Waveform> > >
    'CalibratedFADC' [P] ==> I3Map<OMKey, std::vector<I3Waveform, std::allocator<I3Waveform> > >
    'DOMLaunch' [P] ==> I3Map<OMKey, std::vector<I3DOMLaunch, std::allocator<I3DOMLaunch> > >
    'DOMLaunch_rc' [P] ==> I3Map<OMKey, std::vector<I3DOMLaunch, std::allocator<I3DOMLaunch> > >
    'DrivingTime' [P] ==> I3Time
    'DrivingTimeUCR' [P] ==> I3Time
    'GlobalTriggerHierarchy' [P] ==> I3Tree<I3Trigger>
    'I3-mult' [P] ==> I3Tree<I3Trigger>
    'I3EventHeader' [P] ==> I3EventHeader
    'I3MCTree' [P] ==> I3Tree<I3Particle>
    'IIEventHead' [P] ==> I3EventHeader
    'IceTopRawData' [P] ==> I3Map<OMKey, std::vector<I3DOMLaunch, std::allocator<I3DOMLaunch> > >
    'MCHitSeriesMap' [P] ==> I3Map<OMKey, std::vector<I3MCHit, std::allocator<I3MCHit> > >
    'PrimaryTree' [P] ==> I3Tree<I3Particle>
    'TWRLaunchSeriesMap' [P] ==> I3Map<OMKey, std::vector<I3TWRLaunch, std::allocator<I3TWRLaunch> > >
    'icetop_trig' [P] ==> I3Tree<I3Trigger>
    'noisyMCMap' [P] ==> I3Map<OMKey, std::vector<I3MCHit, std::allocator<I3MCHit> > >
    'twrSelected' [P] ==> I3Map<OMKey, std::vector<I3TWRLaunch, std::allocator<I3TWRLaunch> > >
    'twrSelectedCleanedKeys' [P] ==> I3Vector<OMKey>
  ]
  
  
  In [5]: mctree = frame['I3MCTree']
  
  In [6]: prim = mctree.GetMostEnergeticPrimary()
  
  In [7]: prim
  Out[7]: <icecube.dataclasses.I3Particle object at 0x8372f7c>
  
  In [8]: prim.GetEnergy()
  Out[8]: 497.685


  





