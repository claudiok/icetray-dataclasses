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
#pragma link C++ namespace I3Constants;

#pragma link C++ class I3TrackImpl<I3Starting,I3Energetic,I3NonComposite>+;
#pragma link C++ class I3TrackImpl<I3Starting,I3NonEnergetic,I3NonComposite>+;
#pragma link C++ class I3TrackImpl<I3Contained,I3Energetic,I3Composite>+;
#pragma link C++ class I3TrackImpl<I3Stopping,I3Energetic,I3Composite>+;
#pragma link C++ class I3TrackImpl<I3Infinite,I3Energetic,I3NonComposite>+;
#pragma link C++ class I3TrackImpl<I3Infinite,I3NonEnergetic,I3Composite>+;
#pragma link C++ class I3TrackImpl<I3Starting,I3NonEnergetic,I3Composite>+;
#pragma link C++ class I3TrackImpl<I3Stopping,I3NonEnergetic,I3NonComposite>+;
#pragma link C++ class I3TrackImpl<I3Contained,I3NonEnergetic,I3NonComposite>+;
#pragma link C++ class I3TrackImpl<I3Infinite,I3NonEnergetic,I3NonComposite>+;

#pragma link C++ class I3BasicTrack+;
#pragma link C++ class I3F2KRecoTrack+;
#pragma link C++ typedef I3F2KRecoTrackPtr;
#pragma link C++ class I3BasicMuon+;
#pragma link C++ class I3DecayingMuon+;
#pragma link C++ class I3DoubleBang+;
#pragma link C++ class I3MCTrack+;
#pragma link C++ class I3Lollipop+;
#pragma link C++ class I3MuonBundle+;
#pragma link C++ class I3EnergyMuon+;
#pragma link C++ class I3ShoweringMuon+;
#pragma link C++ class I3StartingMuon+;
#pragma link C++ class I3StoppingMuon+;

#pragma link C++ class I3CascadeImpl<I3Directional,I3Localized,I3Energetic>+;
#pragma link C++ class I3CascadeImpl<I3NonDirectional,I3Localized,I3NonEnergetic>+;
#pragma link C++ class I3CascadeImpl<I3Directional,I3Localized,I3NonEnergetic>+;
#pragma link C++ class I3CascadeImpl<I3NonDirectional,I3Localized,I3Energetic>+;

#pragma link C++ class I3BasicCascade+;
#pragma link C++ class I3DirectionalCascade+;
#pragma link C++ class I3EnergyCascade+;
#pragma link C++ class I3MCCascade+;

#pragma link C++ class I3PrimaryImpl<I3Directional,I3CoreLocalized,I3Energetic>+;

#pragma link C++ class I3MCPrimary+;

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


#pragma link C++ class I3RecoResultDict+;
#pragma link C++ class I3RecoResultDict::iterator+;
#pragma link C++ typedef MapPointainerPolicy<I3RecoResultPtr>::ThePolicy;
#pragma link C++ class MapPointainerPolicy<I3RecoResultPtr>::ThePolicy+;
#pragma link C++ typedef I3RecoResultDictPtr;
#pragma link C++ function I3RecoResultDict::Get<I3RecoResultSingleTrackPtr>(const string&);
#pragma link C++ function I3RecoResultDict::Get<I3RecoResultAltTracksPtr>(const string&);
#pragma link C++ function I3RecoResultDict::Get<I3RecoResultMultiTracksPtr>(const string&);
#pragma link C++ function I3RecoResultDict::Get<I3RecoResultRDMCFitPtr>(const string&);
#pragma link C++ function I3RecoResultDict::Get<I3RecoResultLikelihoodPtr>(const string&);

#pragma link C++ class I3DataReadoutDict+;
#pragma link C++ class I3DataReadoutDict::iterator+;
#pragma link C++ typedef MapPointainerPolicy<I3DataReadoutPtr>::ThePolicy;
#pragma link C++ class MapPointainerPolicy<I3DataReadoutPtr>::ThePolicy+;
#pragma link C++ function operator!=(const I3DataReadoutDict::iterator&, const I3DataReadoutDict::iterator&);
#pragma link C++ typedef I3DataReadoutDictPtr;

#pragma link C++ class I3InIceGeometry+;
#pragma link C++ class I3InIceGeometry::iterator+;
#pragma link C++ typedef VecPointainerPolicy<I3OMGeoPtr>::ThePolicy;
#pragma link C++ class VecPointainerPolicy<I3OMGeoPtr>::ThePolicy+;
#pragma link C++ function operator!=(const I3InIceGeometry::iterator&, const I3InIceGeometry::iterator&);
#pragma link C++ typedef I3OMGeoPtr;
//#pragma link C++ class I3OMGeoPtr+;

#pragma link C++ class I3MCHitSeries+;
#pragma link C++ class I3MCHitSeries::iterator+;
#pragma link C++ typedef VectorPolicy<I3MCHit>::ThePolicy;
#pragma link C++ class VectorPolicy<I3MCHit>::ThePolicy+;
#pragma link C++ function operator!=(const I3MCHitSeries::iterator&, const I3MCHitSeries::iterator&);
#pragma link C++ typedef I3MCHitSeriesPtr;

#pragma link C++ class I3RecoHitVect+;
#pragma link C++ class I3RecoHitVect::iterator+;
#pragma link C++ typedef VectorPolicy<I3RecoHit>::ThePolicy;
#pragma link C++ class VectorPolicy<I3RecoHit>::ThePolicy+;
#pragma link C++ function operator!=(const I3RecoHitVect::iterator&, const I3RecoHitVect::iterator&);
#pragma link C++ typedef I3RecoHitVectPtr;
//#pragma link C++ class I3RecoHitVectPtr+;

#pragma link C++ class I3RecoResultAltTracks+;
#pragma link C++ class I3RecoResultAltTracks::iterator+;
#pragma link C++ typedef MapPointainerPolicy<I3ParticlePtr>::ThePolicy;
#pragma link C++ class MapPointainerPolicy<I3ParticlePtr>::ThePolicy+;
#pragma link C++ function operator!=(const I3RecoResultAltTracks::iterator&, const I3RecoResultAltTracks::iterator&);
#pragma link C++ typedef I3RecoResultAltTracksPtr;

#pragma link C++ class I3RecoResultMultiTracks;
#pragma link C++ class I3RecoResultMultiTracks::iterator+;
#pragma link C++ typedef VecPointainerPolicy<I3ParticlePtr>::ThePolicy;
#pragma link C++ class VecPointainerPolicy<I3ParticlePtr>::ThePolicy+;
#pragma link C++ function operator!=(const I3RecoResultMultiTracks::iterator&, const I3RecoResultMultiTracks::iterator&);
#pragma link C++ typedef I3RecoResultMultiTracksPtr;

#pragma link C++ class I3MCParticleVect+;
#pragma link C++ class I3MCParticleVect::iterator+;
#pragma link C++ typedef VecPointainerPolicy<I3ObservableParticlePtr>::ThePolicy;
#pragma link C++ class VecPointainerPolicy<I3ObservableParticlePtr>::ThePolicy+;
#pragma link C++ function operator!=(const I3MCParticleVect::iterator&, const I3MCParticleVect::iterator&);
#pragma link C++ typedef I3MCParticleVectPtr;

#pragma link C++ class I3MCParticleDict+;
#pragma link C++ class I3MCParticleDict::iterator+;
#pragma link C++ typedef MapPointainerPolicy<I3MCParticleEventPtr>::ThePolicy;
#pragma link C++ class MapPointainerPolicy<I3MCParticleEventPtr>::ThePolicy+;
#pragma link C++ function operator!=(const I3MCParticleDict::iterator&, const I3MCParticleDict::iterator&);
#pragma link C++ typedef I3MCParticleDictPtr;

#pragma link C++ typedef TObjectPtr;
#pragma link C++ class I3Bag+;
#pragma link C++ class I3Bag::iterator+;
#pragma link C++ typedef MapPointainerPolicy<TObjectPtr>::ThePolicy;
#pragma link C++ class MapPointainerPolicy<TObjectPtr>::ThePolicy+;
#pragma link C++ function operator!=(const I3Bag::iterator&, const I3Bag::iterator&);
#pragma link C++ typedef I3BagPtr;

#pragma link C++ class I3OMResponseVect+;
#pragma link C++ class I3OMResponseVect::iterator+;
#pragma link C++ typedef VecPointainerPolicy<I3OMResponsePtr>::ThePolicy;
#pragma link C++ class VecPointainerPolicy<I3OMResponsePtr>::ThePolicy+;
#pragma link C++ function operator!=(const I3OMResponseVect::iterator&, const I3OMResponseVect::iterator&);
#pragma link C++ typedef I3OMResponseVectPtr;

#pragma link C++ class I3RecoHitVectDict+;
#pragma link C++ class I3RecoHitVectDict::iterator+;
#pragma link C++ typedef MapPointainerPolicy<I3RecoHitVectPtr>::ThePolicy;
#pragma link C++ class MapPointainerPolicy<I3RecoHitVectPtr>::ThePolicy+;
#pragma link C++ function operator!=(const I3RecoHitVectDict::iterator&, const I3RecoHitVectDict::iterator&);
#pragma link C++ typedef I3RecoHitVectDictPtr;



#pragma link C++ class I3TopGeometry+;
#pragma link C++ class I3TopGeometry::iterator+;
#pragma link C++ typedef VectorPolicy<I3TankGeo>::ThePolicy;
#pragma link C++ class VectorPolicy<I3TankGeo>::ThePolicy+;
#pragma link C++ function operator!=(const I3TopGeometry::iterator&, const I3TopGeometry::iterator&);


//
// simple types with full value semantics
//

#pragma link C++ class I3AMANDAAnalogReadout+;
#pragma link C++ typedef I3AMANDAAnalogReadoutPtr;
#pragma link C++ class I3AnalogReadout+;
#pragma link C++ typedef I3AnalogReadoutPtr;
#pragma link C++ class I3Atmosphere+;
#pragma link C++ typedef I3AtmospherePtr;
#pragma link C++ class I3Cascade+;
#pragma link C++ typedef I3CascadePtr;
#pragma link C++ class I3Contained+;
#pragma link C++ class I3Composite+;
#pragma link C++ class I3CoreLocalized+;
#pragma link C++ class I3DataExecution+;
#pragma link C++ class I3DataHeader+;
#pragma link C++ typedef I3DataHeaderPtr;
#pragma link C++ class I3DataReadout+;
#pragma link C++ typedef I3DataReadoutPtr;
#pragma link C++ class I3DetectorStatus;
#pragma link C++ typedef I3DetectorStatusPtr;
#pragma link C++ class I3DetectorStatusHeader;
#pragma link C++ typedef I3DetectorStatusHeaderPtr;
#pragma link C++ class I3DigitalReadout+;
#pragma link C++ typedef I3DigitalReadoutPtr;
#pragma link C++ class I3DigitalATWDReadout+;
#pragma link C++ typedef I3DigitalATWDReadoutPtr;
#pragma link C++ class I3DigitalFADCReadout+;
#pragma link C++ typedef I3DigitalFADCReadoutPtr;
#pragma link C++ class I3DigitalTWRReadout+;
#pragma link C++ typedef I3DigitalTWRReadoutPtr;
#pragma link C++ class I3Directional+;
#pragma link C++ class I3Energetic+;
#pragma link C++ class I3MCEvent+;
#pragma link C++ typedef I3MCEventPtr;
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
#pragma link C++ class I3Infinite+;
#pragma link C++ class I3Localized+;
#pragma link C++ class I3MCHit+;
#pragma link C++ typedef I3MCHitPtr;
#pragma link C++ class I3MCOMResponse+;
#pragma link C++ class I3MCPMTResponse+;
#pragma link C++ class I3MCParticleEvent+;
#pragma link C++ typedef I3MCParticleEventPtr;
#pragma link C++ class I3Monitoring+;
#pragma link C++ typedef I3MonitoringPtr;
#pragma link C++ class I3MonitoringHeader+;
#pragma link C++ typedef I3MonitoringHeaderPtr;
#pragma link C++ class I3NonDirectional+;
#pragma link C++ class I3NonComposite+;
#pragma link C++ class I3NonEnergetic+;
#pragma link C++ class I3ObservableParticle+;
#pragma link C++ typedef I3ObservableParticlePtr;
#pragma link C++ class I3OMGeo+;

#pragma link C++ class I3OMGeoAmanda+;

#pragma link C++ typedef I3OMGeoAmandaPtr;
//#pragma link C++ class I3OMGeoAmandaPtr+;
#pragma link C++ class I3OMGeoIcecube+;

#pragma link C++ typedef I3OMGeoIcecubePtr;
//#pragma link C++ class I3OMGeoIcecubePtr+;

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
#pragma link C++ class I3Particle+;
#pragma link C++ typedef I3ParticlePtr;
#pragma link C++ class I3Position+;
#pragma link C++ class I3Primary+;
#pragma link C++ class I3RecoHit+;
#pragma link C++ typedef I3RecoHitPtr;
#pragma link C++ class I3RecoResult+;
#pragma link C++ typedef I3RecoResultPtr;
#pragma link C++ class I3RecoResultLikelihood+;
#pragma link C++ typedef I3RecoResultLikelihoodPtr;
#pragma link C++ class I3RecoResultRDMCFit+;
#pragma link C++ typedef I3RecoResultRDMCFitPtr;
#pragma link C++ class I3RecoResultSingleTrack+;
#pragma link C++ typedef I3RecoResultSingleTrackPtr;
#pragma link C++ class I3SLCReadout+;
#pragma link C++ typedef I3SLCReadoutPtr;
#pragma link C++ class I3Starting+;
#pragma link C++ class I3Stopping+;
#pragma link C++ class I3SummaryPulseReadout+;
#pragma link C++ typedef I3SummaryPulseReadoutPtr;
#pragma link C++ class I3TankGeo+;
#pragma link C++ class I3TankMaterial+;
#pragma link C++ class I3Track+;
#pragma link C++ typedef I3TrackPtr;
#pragma link C++ class I3TriggerData+;
#pragma link C++ typedef I3TriggerDataPtr;

#pragma link C++ class AmandaExtractor+;
#pragma link C++ class I3TrackExtractor+;
#pragma link C++ class I3CascadeExtractor+;
#pragma link C++ class vector<I3OMGeoAmandaPtr>+;

#pragma link C++ class I3StartingTrack+;

#endif




