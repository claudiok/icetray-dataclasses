#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;

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

#pragma link C++ class I3IceTopStatus+;
#pragma link C++ class I3IceTopStatus::iterator+;
#pragma link C++ typedef VectorPolicy<I3IceTopStationStatus>::ThePolicy;
#pragma link C++ class VectorPolicy<I3IceTopStationStatus>::ThePolicy+;
#pragma link C++ function operator!=(const I3IceTopStatus::iterator&, const I3IceTopStatus::iterator&);
#pragma link C++ typedef I3IceTopStatusPtr;

#pragma link C++ class I3InIceStatus+;
#pragma link C++ class I3InIceStatus::iterator+;
#pragma link C++ typedef VectorPolicy<I3OMStatusIcecube>::ThePolicy;
#pragma link C++ class VectorPolicy<I3OMStatusIcecube>::ThePolicy+;
#pragma link C++ function operator!=(const I3InIceStatus::iterator&, const I3InIceStatus::iterator&);
#pragma link C++ typedef I3InIceStatusPtr;

// below these are commented out because they are redundant in view of the
// InIceStatusData
#pragma link C++ class I3IceTopStationStatus+;
//#pragma link C++ class I3IceTopStationStatus::iterator+;
//#pragma link C++ typedef VectorPolicy<I3OMStatusIcecube>::ThePolicy;
//#pragma link C++ class VectorPolicy<I3OMStatusIcecube>::ThePolicy+;
//#pragma link C++ function operator!=(const I3IceTopStationStatus::iterator&, const I3IceTopStationStatus::iterator&);
#pragma link C++ typedef I3IceTopStationStatusPtr;


#pragma link C++ class I3RecoResultData+;
#pragma link C++ class I3RecoResultData::iterator+;
#pragma link C++ typedef MapPolicy<I3RecoResultPtr>::ThePolicy;
#pragma link C++ class MapPolicy<I3RecoResultPtr>::ThePolicy+;
#pragma link C++ typedef I3RecoResultDataPtr;

#pragma link C++ class I3RecoTrackList+;
#pragma link C++ class I3RecoTrackList::iterator+;
#pragma link C++ typedef VectorPolicy<I3RecoTrack>::ThePolicy;
#pragma link C++ class VectorPolicy<I3RecoTrack>::ThePolicy+;
#pragma link C++ function operator!=(const I3RecoTrackList::iterator&, const I3RecoTrackList::iterator&);
#pragma link C++ typedef I3RecoTrackListPtr;


#pragma link C++ class I3AnalogSeries+;
#pragma link C++ class I3AnalogSeries::iterator+;
#pragma link C++ typedef VectorPolicy<I3Analog>::ThePolicy;
#pragma link C++ class VectorPolicy<I3Analog>::ThePolicy+;
#pragma link C++ function operator!=(const I3AnalogSeries::iterator&, const I3AnalogSeries::iterator&);
// others which are just typedefs to this
#pragma link C++ typedef I3AnalogSeriesPtr;
#pragma link C++ typedef I3AnalogAmandaSeries;

#pragma link C++ class I3DataReadoutList+;
#pragma link C++ class I3DataReadoutList::iterator+;
#pragma link C++ typedef VectorPolicy<I3DataReadoutPtr>::ThePolicy;
#pragma link C++ class VectorPolicy<I3DataReadoutPtr>::ThePolicy+;
#pragma link C++ function operator!=(const I3DataReadoutList::iterator&, const I3DataReadoutList::iterator&);
#pragma link C++ typedef I3DataReadoutListPtr;

#pragma link C++ class I3DigitalSeries+;
#pragma link C++ class I3DigitalSeries::iterator+;
#pragma link C++ typedef VectorPolicy<I3Digital>::ThePolicy;
#pragma link C++ class VectorPolicy<I3Digital>::ThePolicy+;
#pragma link C++ function operator!=(const I3DigitalSeries::iterator&, const I3DigitalSeries::iterator&);
#pragma link C++ typedef I3DigitalSeriesPtr;

// typedefs of I3DigitalSeries
#pragma link C++ class I3DigitalATWDSeries;
#pragma link C++ typedef I3DigitalATWDSeriesPtr;
#pragma link C++ typedef I3DigitalFADCSeries;
#pragma link C++ typedef I3DigitalTWRSeries;
#pragma link C++ typedef I3DigitalTWRSeriesPtr;

#pragma link C++ class I3InIceGeometry+;
#pragma link C++ class I3InIceGeometry::iterator+;
#pragma link C++ typedef VecPointainerPolicy<I3OMGeoPtr>::ThePolicy;
#pragma link C++ class VecPointainerPolicy<I3OMGeoPtr>::ThePolicy+;
#pragma link C++ typedef VectorPolicy<I3OMGeoPtr>::ThePolicy;
#pragma link C++ class VectorPolicy<I3OMGeoPtr>::ThePolicy+;
#pragma link C++ function operator!=(const I3InIceGeometry::iterator&, const I3InIceGeometry::iterator&);
#pragma link C++ typedef I3OMGeoPtr;
//#pragma link C++ class I3OMGeoPtr+;

#pragma link C++ class I3MCHitSeries+;
#pragma link C++ class I3MCHitSeries::iterator+;
#pragma link C++ typedef VectorPolicy<I3MCHit>::ThePolicy;
#pragma link C++ class VectorPolicy<I3MCHit>::ThePolicy+;
#pragma link C++ function operator!=(const I3MCHitSeries::iterator&, const I3MCHitSeries::iterator&);
#pragma link C++ typedef I3MCHitSeriesPtr;

#pragma link C++ class I3RecoHitSeries+;
#pragma link C++ class I3RecoHitSeries::iterator+;
#pragma link C++ typedef VectorPolicy<I3RecoHit>::ThePolicy;
#pragma link C++ class VectorPolicy<I3RecoHit>::ThePolicy+;
#pragma link C++ function operator!=(const I3RecoHitSeries::iterator&, const I3RecoHitSeries::iterator&);
#pragma link C++ typedef I3RecoHitSeriesPtr;
//#pragma link C++ class I3RecoHitSeriesPtr+;


#pragma link C++ class I3MCTrackList+;
#pragma link C++ class I3MCTrackList::iterator+;
#pragma link C++ typedef VectorPolicy<I3MCTrack>::ThePolicy;
#pragma link C++ class VectorPolicy<I3MCTrack>::ThePolicy+;
#pragma link C++ function operator!=(const I3MCTrackList::iterator&, const I3MCTrackList::iterator&);
#pragma link C++ typedef I3MCTrackListPtr;

#pragma link C++ class I3MCTrackData+;
#pragma link C++ class I3MCTrackData::iterator+;
#pragma link C++ typedef MapPolicy<I3MCTrackEvent>::ThePolicy;
#pragma link C++ class MapPolicy<I3MCTrackEvent>::ThePolicy+;
#pragma link C++ function operator!=(const I3MCTrackData::iterator&, const I3MCTrackData::iterator&);
#pragma link C++ typedef I3MCTrackDataPtr;

#pragma link C++ class I3Bag+;
#pragma link C++ class I3Bag::iterator+;
#pragma link C++ typedef MapPolicy<TObjectPtr>::ThePolicy;
#pragma link C++ class MapPolicy<TObjectPtr>::ThePolicy+;
#pragma link C++ function operator!=(const I3Bag::iterator&, const I3Bag::iterator&);
#pragma link C++ typedef I3BagPtr;

#pragma link C++ class I3OMResponseData+;
#pragma link C++ class I3OMResponseData::iterator+;
#pragma link C++ typedef VectorPolicy<I3OMResponse>::ThePolicy;
#pragma link C++ class VectorPolicy<I3OMResponse>::ThePolicy+;
#pragma link C++ function operator!=(const I3OMResponseData::iterator&, const I3OMResponseData::iterator&);
#pragma link C++ typedef I3OMResponseDataPtr;

#pragma link C++ class I3RecoHitSeriesData+;
#pragma link C++ class I3RecoHitSeriesData::iterator+;
#pragma link C++ typedef MapPolicy<I3RecoHitSeriesPtr>::ThePolicy;
#pragma link C++ class MapPolicy<I3RecoHitSeriesPtr>::ThePolicy+;
#pragma link C++ function operator!=(const I3RecoHitSeriesData::iterator&, const I3RecoHitSeriesData::iterator&);
#pragma link C++ typedef I3RecoHitSeriesDataPtr;



#pragma link C++ class I3TopGeometry+;
#pragma link C++ class I3TopGeometry::iterator+;
#pragma link C++ typedef VectorPolicy<I3TankGeo>::ThePolicy;
#pragma link C++ class VectorPolicy<I3TankGeo>::ThePolicy+;
#pragma link C++ function operator!=(const I3TopGeometry::iterator&, const I3TopGeometry::iterator&);


//
// simple types with full value semantics
//
#pragma link C++ typedef TObjectPtr;

#pragma link C++ class I3AltTracksRecoResult+;
#pragma link C++ typedef I3AltTracksRecoResultPtr;
#pragma link C++ class I3Analog+;
#pragma link C++ typedef I3AnalogPtr;
#pragma link C++ class I3Atmosphere+;
#pragma link C++ typedef I3AtmospherePtr;
#pragma link C++ class I3DataExecution+;
#pragma link C++ class I3DataHeader+;
#pragma link C++ typedef I3DataHeaderPtr;
#pragma link C++ class I3DataReadout+;
#pragma link C++ typedef I3DataReadoutPtr;
#pragma link C++ class I3DetectorStatus;
#pragma link C++ typedef I3DetectorStatusPtr;
#pragma link C++ class I3DetectorStatusHeader;
#pragma link C++ typedef I3DetectorStatusHeaderPtr;
#pragma link C++ class I3Digital+;
#pragma link C++ typedef I3DigitalPtr;
#pragma link C++ class I3Event+;
#pragma link C++ typedef I3EventPtr;
#pragma link C++ class I3EventHeader+;
#pragma link C++ typedef I3EventHeaderPtr;
#pragma link C++ class I3FilterData+;
#pragma link C++ typedef I3FilterDataPtr;
#pragma link C++ class I3GeometryHeader+;
#pragma link C++ typedef I3GeometryHeaderPtr;
#pragma link C++ class I3Hit+;
#pragma link C++ typedef I3HitPtr;
#pragma link C++ class I3MCHit+;
#pragma link C++ typedef I3MCHitPtr;
#pragma link C++ class I3MCTrack+;
#pragma link C++ class I3MCTrackEvent+;
#pragma link C++ typedef I3MCTrackEventPtr;
#pragma link C++ class I3Monitoring+;
#pragma link C++ typedef I3MonitoringPtr;
#pragma link C++ class I3MonitoringHeader+;
#pragma link C++ typedef I3MonitoringHeaderPtr;
#pragma link C++ class I3MultiTrackRecoResult;
#pragma link C++ typedef I3MultiTrackRecoResultPtr;
#pragma link C++ class I3OMGeo+;

#pragma link C++ class I3OMGeoAmanda+;

#pragma link C++ typedef I3OMGeoAmandaPtr;
//#pragma link C++ class I3OMGeoAmandaPtr+;
#pragma link C++ class I3OMGeoIcecube+;

#pragma link C++ typedef I3OMGeoIcecubePtr;
//#pragma link C++ class I3OMGeoIcecubePtr+;

//#pragma link C++ typedef I3RecoResultPtr;
//#pragma link C++ class I3RecoResultPtr+;

#pragma link C++ class I3Geometry+;
#pragma link C++ typedef I3GeometryPtr;
#pragma link C++ class I3OMResponse+;
#pragma link C++ typedef I3OMResponsePtr;`
#pragma link C++ class I3OMStatus+;
#pragma link C++ typedef I3OMStatusPtr;
#pragma link C++ class I3OMStatusIcecube+;
#pragma link C++ typedef I3OMStatusIcecube::OMTrigSource;
#pragma link C++ typedef I3OMStatusIcecube::OnOff;
#pragma link C++ typedef I3OMStatusIcecube::LCMode;
#pragma link C++ typedef I3OMStatusIcecubePtr;
#pragma link C++ class I3RecoHit+;
#pragma link C++ typedef I3RecoHitPtr;
#pragma link C++ class I3RecoResult;
#pragma link C++ typedef I3RecoResultPtr;
#pragma link C++ class I3RecoResultLikelihood+;
#pragma link C++ typedef I3RecoResultLikelihoodPtr;
#pragma link C++ class I3RecoResultRDMCFit+;
#pragma link C++ typedef I3RecoResultRDMCFitPtr;
#pragma link C++ class I3RecoResultSingleTrack+;
#pragma link C++ typedef I3RecoResultSingleTrackPtr;
#pragma link C++ class I3RecoTrack+;
#pragma link C++ typedef I3RecoTrackPtr;
#pragma link C++ class I3RecoTrackComposite+;
#pragma link C++ class I3TankGeo+;
#pragma link C++ class I3TankMaterial+;
#pragma link C++ class I3Track+;
#pragma link C++ class I3TriggerData+;
#pragma link C++ typedef I3TriggerDataPtr;
#pragma link C++ class I3MCPrimary+;
#pragma link C++ typedef I3MCPrimaryPtr;

#pragma link C++ class AmandaExtractor+;
#pragma link C++ class vector<I3OMGeoAmandaPtr>+;

#endif




