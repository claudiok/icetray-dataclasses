#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;

#pragma link C++ namespace I3Units;

#pragma link C++ class I3Analog+;
#pragma link C++ class I3AnalogAmandaSeries+;
#pragma link C++ typedef I3AnalogSeries;
#pragma link C++ class I3Bag+;
#pragma link C++ class I3DataExecution+;
#pragma link C++ class I3DataHeader+;
#pragma link C++ class I3DataReadout+;
#pragma link C++ typedef I3DataReadoutList;
#pragma link C++ class I3DataReadoutList+;

#pragma link C++ class I3Digital+;
#pragma link C++ typedef I3DigitalATWDSeries;
#pragma link C++ typedef I3DigitalFADCSeries;
#pragma link C++ typedef I3DigitalSeries;
#pragma link C++ typedef I3DigitalTWRSeries;
#pragma link C++ class I3EventHeader+;
#pragma link C++ class I3FilterData+;
#pragma link C++ class I3Geometry+;
#pragma link C++ class I3GeometryDataHeader+;
#pragma link C++ class I3Hit+;
#pragma link C++ class I3MCHit+;
#pragma link C++ typedef I3MCHitSeries;

#pragma link C++ class I3MCHitSeries+;
#pragma link C++ class I3MCHitSeries::iterator;

#pragma link C++ typedef I3MCHitSeriesStoragePolicy;
#pragma link C++ class I3MCHitSeriesStoragePolicy+;

#pragma link C++ function operator!=(const I3MCHitSeries::iterator&, const I3MCHitSeries::iterator&)

#pragma link C++ class I3MCTrack+;
#pragma link C++ typedef I3MCTrackData;
#pragma link C++ class I3MCTrackData+;
#pragma link C++ typedef I3MCTrackList;
#pragma link C++ class I3MCTrackList+;
#pragma link C++ class I3OMGeo+;
#pragma link C++ class I3OMGeoAmanda+;
#pragma link C++ class I3OMGeoIcecube+;

#pragma link C++ typedef I3RecoHitSeriesData;
#pragma link C++ class I3RecoHitSeriesData+;

#pragma link C++ typedef I3RecoHitSeries;
#pragma link C++ class I3RecoHitSeries+;

#pragma link C++ class I3RecoHit+;

#pragma link C++ class I3RecoResult+;
#pragma link C++ class I3RecoResultLikelihood+;
#pragma link C++ class I3RecoResultSingleTrack+;
#pragma link C++ class I3RecoTrack+;
#pragma link C++ class I3RecoTrackComposite+;
#pragma link C++ class I3RecoTrackList+;
#pragma link C++ class I3Track+;
#pragma link C++ class I3TriggerData+;

#pragma link C++ typedef I3OMResponseData;
#pragma link C++ class I3OMResponseData+;
#pragma link C++ class I3OMResponse+;

#pragma link C++ class I3Event+;

#endif

