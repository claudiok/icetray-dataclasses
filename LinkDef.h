#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;

//#pragma link C++ function test1;
//#pragma link C++ function testtestvec;

//
// namespace
//

#pragma link C++ namespace I3Units;



//
// vector (series, list) types
// these must go from outermost to innermost
// otherwise you will get errors of the sort
// 'specializaton after instantiation', and
// 'prototype for blahblah does not match any in class blahblah'
//

#pragma link C++ typedef I3RecoTrackList;
#pragma link C++ class I3RecoTrackList+;
#pragma link C++ class I3RecoTrackList::iterator+;
#pragma link C++ typedef I3RecoTrackListStoragePolicy;
#pragma link C++ class I3RecoTrackListStoragePolicy+;
#pragma link C++ function operator!=(const I3RecoTrackList::iterator&, const I3RecoTrackList::iterator&);
#pragma link C++ typedef I3AnalogSeries;
#pragma link C++ class I3AnalogSeries+;
#pragma link C++ class I3AnalogSeries::iterator+;
#pragma link C++ typedef I3AnalogSeriesStoragePolicy;
#pragma link C++ class I3AnalogSeriesStoragePolicy+;
#pragma link C++ function operator!=(const I3AnalogSeries::iterator&, const I3AnalogSeries::iterator&)
// others which are just typedefs to this
#pragma link C++ typedef I3AnalogAmandaSeries;


#pragma link C++ typedef I3DataReadoutList;
#pragma link C++ class I3DataReadoutList+;
#pragma link C++ class I3DataReadoutList::iterator+;
#pragma link C++ typedef I3DataReadoutListStoragePolicy;
#pragma link C++ class I3DataReadoutListStoragePolicy+;
#pragma link C++ function operator!=(const I3DataReadoutList::iterator&, const I3DataReadoutList::iterator&)

#pragma link C++ typedef I3DigitalSeries;
#pragma link C++ class I3DigitalSeries+;
#pragma link C++ class I3DigitalSeries::iterator+;
#pragma link C++ typedef I3DigitalSeriesStoragePolicy;
#pragma link C++ class I3DigitalSeriesStoragePolicy+;
#pragma link C++ function operator!=(const I3DigitalSeries::iterator&, const I3DigitalSeries::iterator&)
// typedefs of I3DigitalSeries
#pragma link C++ typedef I3DigitalATWDSeries;
#pragma link C++ typedef I3DigitalFADCSeries;
#pragma link C++ typedef I3DigitalTWRSeries;


#pragma link C++ typedef I3Geometry;
#pragma link C++ class I3Geometry+;
#pragma link C++ class I3Geometry::iterator+;
#pragma link C++ typedef I3GeometryStoragePolicy;
#pragma link C++ class I3GeometryStoragePolicy+;
#pragma link C++ function operator!=(const I3Geometry::iterator&, const I3Geometry::iterator&)

#pragma link C++ typedef I3MCHitSeries;
#pragma link C++ class I3MCHitSeries+;
#pragma link C++ class I3MCHitSeries::iterator+;
#pragma link C++ typedef I3MCHitSeriesStoragePolicy;
#pragma link C++ class I3MCHitSeriesStoragePolicy+;
#pragma link C++ function operator!=(const I3MCHitSeries::iterator&, const I3MCHitSeries::iterator&)

#pragma link C++ typedef I3MCTrackList;
#pragma link C++ class I3MCTrackList+;
#pragma link C++ class I3MCTrackList::iterator+;
#pragma link C++ typedef I3MCTrackListStoragePolicy;
#pragma link C++ class I3MCTrackListStoragePolicy+;
#pragma link C++ function operator!=(const I3MCTrackList::iterator&, const I3MCTrackList::iterator&)

#pragma link C++ typedef I3MCTrackData;
#pragma link C++ class I3MCTrackData+;
#pragma link C++ class I3MCTrackData::iterator+;
#pragma link C++ typedef I3MCTrackDataStoragePolicy;
#pragma link C++ class I3MCTrackDataStoragePolicy+;
#pragma link C++ function operator!=(const I3MCTrackData::iterator&, const I3MCTrackData::iterator&)

#pragma link C++ typedef I3OMResponseData;
#pragma link C++ class I3OMResponseData+;
#pragma link C++ class I3OMResponseData::iterator+;
#pragma link C++ typedef I3OMResponseDataStoragePolicy;
#pragma link C++ class I3OMResponseDataStoragePolicy+;
#pragma link C++ function operator!=(const I3OMResponseData::iterator&, const I3OMResponseData::iterator&);
#pragma link C++ typedef I3RecoHitSeries;
#pragma link C++ class I3RecoHitSeries+;
#pragma link C++ class I3RecoHitSeries::iterator+;
#pragma link C++ typedef I3RecoHitSeriesStoragePolicy;
#pragma link C++ class I3RecoHitSeriesStoragePolicy+;
#pragma link C++ function operator!=(const I3RecoHitSeries::iterator&, const I3RecoHitSeries::iterator&)

#pragma link C++ typedef I3RecoHitSeriesData;
#pragma link C++ class I3RecoHitSeriesData+;
#pragma link C++ class I3RecoHitSeriesData::iterator+;
#pragma link C++ typedef I3RecoHitSeriesDataStoragePolicy;
#pragma link C++ class I3RecoHitSeriesDataStoragePolicy+;
#pragma link C++ function operator!=(const I3RecoHitSeriesData::iterator&, const I3RecoHitSeriesData::iterator&)

#pragma link C++ typedef I3RecoResult;
#pragma link C++ class I3RecoResult+;
#pragma link C++ class I3RecoResult::iterator+;
#pragma link C++ typedef I3RecoResultStoragePolicy;
#pragma link C++ class I3RecoResultStoragePolicy+;
#pragma link C++ function operator!=(const I3RecoResult::iterator&, const I3RecoResult::iterator&);

//#pragma link C++ typedef TestVecType;
//#pragma link C++ class TestVecType+;
//#pragma link C++ class TestVecType::iterator+;
//#pragma link C++ typedef policy;
//#pragma link C++ class policy+;
//#pragma link C++ class policy::type_iterator<Derived*>+;
//#pragma link C++ function policy::begin<Derived*>()+;
//#pragma link C++ template function policy::begin<Derived*>();
//#pragma link C++ function TestVecType::begin<Derived*>()+;
//#pragma link C++ template function TestVecType::begin<Derived*>();
//#pragma link C++ function operator!=(const policy::type_iterator<Derived*>&, const policy::type_iterator<Derived*>&);
//
//#pragma link C++ template class TestVecType::type_iterator<Base*>+;
//#pragma link C++ template class TestVecType::type_iterator<Derived*>+;
//#pragma link C++ class TestVecType::type_iterator<Derived*>+;
//#pragma link C++ function operator!=(const TestVecType::iterator<Derived*>&, const TestVecType::iterator<Derived*>&);

#pragma link C++ typedef I3TestHash;
#pragma link C++ class I3TestHash+;
#pragma link C++ class I3TestHash::iterator+;
#pragma link C++ typedef I3TestHashStoragePolicy;
#pragma link C++ class I3TestHashStoragePolicy+;
#pragma link C++ function hashtest;
#pragma link C++ class pair<string,I3MCHit>+;

#pragma link C++ class Base+;
#pragma link C++ class Derived+;

#pragma link C++ typedef I3TopGeometry;
#pragma link C++ class I3TopGeometry+;
#pragma link C++ class I3TopGeometry::iterator+;
#pragma link C++ typedef I3TopGeometryStoragePolicy;
#pragma link C++ class I3TopGeometryStoragePolicy+;
#pragma link C++ function operator!=(const I3TopGeometry::iterator&, const I3TopGeometry::iterator&);


//
// simple types with full value semantics
//

#pragma link C++ class I3Analog+;
#pragma link C++ class I3Bag+;
#pragma link C++ class I3DataExecution+;
#pragma link C++ class I3DataHeader+;
#pragma link C++ class I3DataReadout+;
#pragma link C++ class I3Digital+;
#pragma link C++ class I3Event+;
#pragma link C++ class I3EventHeader+;
#pragma link C++ class I3FilterData+;
#pragma link C++ class I3GeometryDataHeader+;
#pragma link C++ class I3Hit+;
#pragma link C++ class I3MCHit+;
#pragma link C++ class I3MCTrack+;
#pragma link C++ class I3OMGeo+;
#pragma link C++ class I3OMGeoAmanda+;
#pragma link C++ class I3OMGeoIcecube+;
#pragma link C++ class I3OMResponse+;
#pragma link C++ class I3RecoHit+;
#pragma link C++ class I3RecoResultLikelihood+;
#pragma link C++ class I3RecoResultSingleTrack+;
#pragma link C++ class I3RecoResultAlternativeSingleTracks+;
#pragma link C++ class I3RecoTrack+;
#pragma link C++ class I3RecoTrackComposite+;
#pragma link C++ class I3TankGeo+;
#pragma link C++ class I3TankMaterial+;
#pragma link C++ class I3Track+;
#pragma link C++ class I3TriggerData+;

#endif

