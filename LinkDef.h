//
// LinkDef.h
// $Id: LinkDef.h,v 1.105 2004/07/31 22:31:10 pretz Exp $
// $Revision: 1.105 $
// $Date: 2004/07/31 22:31:10 $
//

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
#pragma link C++ class I3PrimaryImpl<I3NonDirectional, I3CoreLocalized, I3NonEnergetic>+;
#pragma link C++ class I3PrimaryImpl<I3Directional, I3NonCoreLocalized, I3NonEnergetic>+;

#pragma link C++ class I3MCPrimary+;
#pragma link C++ classs I3ShowerCore+;
#pragma link C++ typedef I3ShowerCorePtr;
#pragma link C++ class I3ShowerDirection+;
#pragma link C++ class I3ShowerDirectionPtr;
//
// vector (series, list) types
// these must go from outermost to innermost
// otherwise you will get errors of the sort
// 'specializaton after instantiation', and
// 'prototype for blahblah does not match any in class blahblah'
//

#pragma link C++ class I3IceTopStatus+;
#pragma link C++ typedef VectorPolicy<I3IceTopStationStatus>::ThePolicy;
#pragma link C++ class VectorPolicy<I3IceTopStationStatus>::ThePolicy+;
#pragma link C++ function operator!=(const I3IceTopStatus::iterator&, const I3IceTopStatus::iterator&);
#pragma link C++ typedef I3IceTopStatusPtr;

#pragma link C++ class I3InIceStatus+;
#pragma link C++ typedef VectorPolicy<I3OMStatusIceCube>::ThePolicy;
#pragma link C++ class VectorPolicy<I3OMStatusIceCube>::ThePolicy+;
#pragma link C++ function operator!=(const I3InIceStatus::iterator&, const I3InIceStatus::iterator&);
#pragma link C++ typedef I3InIceStatusPtr;

// below these are commented out because they are redundant in view of the
// InIceStatusData
#pragma link C++ class I3IceTopStationStatus+;
//#pragma link C++ class I3IceTopStationStatus::iterator+;
//#pragma link C++ typedef VectorPolicy<I3OMStatusIceCube>::ThePolicy;
//#pragma link C++ class VectorPolicy<I3OMStatusIceCube>::ThePolicy+;
//#pragma link C++ function operator!=(const I3IceTopStationStatus::iterator&, const I3IceTopStationStatus::iterator&);
#pragma link C++ typedef I3IceTopStationStatusPtr;


#pragma link C++ class I3RecoResultDict+;
#pragma link C++ typedef MapPolicy<string,I3RecoResultPtr>::ThePolicy;
#pragma link C++ class MapPolicy<string,I3RecoResultPtr>::ThePolicy+;
#pragma link C++ typedef I3RecoResultDictPtr;

#pragma link C++ class I3TriggerDict+;
#pragma link C++ typedef MapPolicy<string,I3TriggerPtr>::ThePolicy;
#pragma link C++ class MapPolicy<string,I3TriggerPtr>::ThePolicy+;
#pragma link C++ typedef I3TriggerDictPtr;

#pragma link C++ class I3FilterDict+;
#pragma link C++ typedef MapPolicy<string,I3FilterPtr>::ThePolicy;
#pragma link C++ class MapPolicy<string,I3FilterPtr>::ThePolicy+;
#pragma link C++ typedef I3FilterDictPtr;

#pragma link C++ class I3DataReadoutDict+;
#pragma link C++ typedef MapPolicy<string,I3DataReadoutPtr>::ThePolicy;
#pragma link C++ class MapPolicy<string,I3DataReadoutPtr>::ThePolicy+;
#pragma link C++ function operator!=(const I3DataReadoutDict::iterator&, const I3DataReadoutDict::iterator&);
#pragma link C++ typedef I3DataReadoutDictPtr;

#pragma link C++ class I3InIceGeometry+;
#pragma link C++ typedef MapPolicy<OMKey,I3OMGeoPtr>::ThePolicy;
#pragma link C++ class MapPolicy<OMKey,I3OMGeoPtr>::ThePolicy+;
#pragma link C++ function operator!=(const I3InIceGeometry::iterator&, const I3InIceGeometry::iterator&);
#pragma link C++ typedef I3OMGeoPtr;
#pragma link C++ class I3OMGeoPtr+;

#pragma link C++ class I3MCHitSeries+;
#pragma link C++ typedef VectorPolicy<I3MCHit>::ThePolicy;
#pragma link C++ class VectorPolicy<I3MCHit>::ThePolicy+;
#pragma link C++ function operator!=(const I3MCHitSeries::iterator&, const I3MCHitSeries::iterator&);
#pragma link C++ typedef I3MCHitSeriesPtr;

#pragma link C++ class I3MCPhotonVect+;
#pragma link C++ typedef VectorPolicy<I3MCPhoton>::ThePolicy;
#pragma link C++ class VectorPolicy<I3MCPhoton>::ThePolicy+;
#pragma link C++ function operator!=(const I3MCPhotonVect::iterator&, const I3MCPhotonVect::iterator&);
#pragma link C++ typedef I3MCPhotonVectPtr;

#pragma link C++ class I3DigitalReadout+;
#pragma link C++ typedef VectorPolicy<I3DigitalLaunch>::ThePolicy;
#pragma link C++ class VectorPolicy<I3DigitalLaunch>::ThePolicy+;
#pragma link C++ function operator!=(const I3DigitalReadout::iterator&, const I3DigitalReadout::iterator&);
#pragma link C++ typedef I3DigitalReadoutPtr;


#pragma link C++ class I3RecoHitSeries+;
#pragma link C++ typedef VectorPolicy<I3RecoHit>::ThePolicy;
#pragma link C++ class VectorPolicy<I3RecoHit>::ThePolicy+;
#pragma link C++ function operator!=(const I3RecoHitSeries::iterator&, const I3RecoHitSeries::iterator&);
#pragma link C++ typedef I3RecoHitSeriesPtr;
//#pragma link C++ class I3RecoHitSeriesPtr+;

#pragma link C++ class I3RecoResultAltTracks+;
#pragma link C++ typedef MapPolicy<string,I3ParticlePtr>::ThePolicy;
#pragma link C++ class MapPolicy<string,I3ParticlePtr>::ThePolicy+;
#pragma link C++ function operator!=(const I3RecoResultAltTracks::iterator&, const I3RecoResultAltTracks::iterator&);
#pragma link C++ typedef I3RecoResultAltTracksPtr;

#pragma link C++ class I3RecoResultMultiTracks;
#pragma link C++ typedef VectorPolicy<I3ParticlePtr>::ThePolicy;
#pragma link C++ class VectorPolicy<I3ParticlePtr>::ThePolicy+;
#pragma link C++ function operator!=(const I3RecoResultMultiTracks::iterator&, const I3RecoResultMultiTracks::iterator&);
#pragma link C++ typedef I3RecoResultMultiTracksPtr;

#pragma link C++ class I3MCParticleMultiMap+;
#pragma link C++ typedef MultiMapPolicy<string,I3ParticlePtr>::ThePolicy;
#pragma link C++ class MultiMapPolicy<string,I3ParticlePtr>::ThePolicy+;
#pragma link C++ function operator!=(const I3MCParticleMultiMap::iterator&, const I3MCParticleMultiMap::iterator&);
#pragma link C++ typedef I3MCParticleMultiMapPtr;

#pragma link C++ typedef TObjectPtr;
#pragma link C++ class I3Bag+;
#pragma link C++ typedef MapPolicy<string,TObjectPtr>::ThePolicy;
#pragma link C++ class MapPolicy<string,TObjectPtr>::ThePolicy+;
#pragma link C++ function operator!=(const I3Bag::iterator&, const I3Bag::iterator&);
#pragma link C++ typedef I3BagPtr;

#pragma link C++ class I3OMResponseMap+;
#pragma link C++ typedef VectorPolicy<I3OMResponsePtr>::ThePolicy;
#pragma link C++ class VectorPolicy<I3OMResponsePtr>::ThePolicy+;
#pragma link C++ function operator!=(const I3OMResponseMap::iterator&, const I3OMResponseMap::iterator&);
#pragma link C++ typedef I3OMResponseMapPtr;

#pragma link C++ class I3RecoHitSeriesDict+;
#pragma link C++ typedef MapPolicy<string,I3RecoHitSeriesPtr>::ThePolicy;
#pragma link C++ class MapPolicy<string,I3RecoHitSeriesPtr>::ThePolicy+;
#pragma link C++ function operator!=(const I3RecoHitSeriesDict::iterator&, const I3RecoHitSeriesDict::iterator&);
#pragma link C++ typedef I3RecoHitSeriesDictPtr;


// new IceTop stuff, PN
// took out the XXX::iterator+ stuff because it core dumps with
// rootcint's -p option.  Not PN's fault. -J.Pretz

#pragma link C++ class I3TopStationGeo+;
//#pragma link C++ class I3TopStationGeo::iterator+;
#pragma link C++ typedef VectorPolicy<I3TankGeoPtr>::ThePolicy;
#pragma link C++ class VectorPolicy<I3TankGeoPtr>::ThePolicy+;
#pragma link C++ function operator!= (const I3TopStationGeo::iterator &, const I3TopStationGeo::iterator &);
#pragma link C++ typedef I3TopStationGeoPtr;

#pragma link C++ class I3TopGeometry+;
//#pragma link C++ class I3TopGeometry::iterator+;
#pragma link C++ typedef VectorPolicy<I3TopStationGeoPtr>::ThePolicy;
#pragma link C++ class VectorPolicy<I3TopStationGeoPtr>::ThePolicy+;
#pragma link C++ function operator!=(const I3TopGeometry::iterator&, const I3TopGeometry::iterator&);

#pragma link C++ class I3MCTankHit+;
//#pragma link C++ class I3MCTankHit::iterator+;
#pragma link C++ typedef VectorPolicy<I3MCParticleDataPtr>::ThePolicy;
#pragma link C++ class VectorPolicy<I3MCParticleDataPtr>::ThePolicy;
#pragma link C++ function operator!= (const I3MCTankHit::iterator&, const I3MCTankHit::iterator&);
#pragma link C++ typedef I3MCTankHitPtr;

#pragma link C++ class I3StationHit+;
//#pragma link C++ class I3StationHit::iterator+;
#pragma link C++ typedef VectorPolicy<I3TankHitPtr>::ThePolicy;
#pragma link C++ class VectorPolicy<I3TankHitPtr>::ThePolicy+;
#pragma link C++ function operator!= (const I3StationHit::iterator &,
                                      const I3StationHit::iterator &);
#pragma link C++ typedef I3StationHitPtr;

#pragma link C++ class I3ArrayHit+;
//#pragma link C++ class I3ArrayHit::iterator+;
#pragma link C++ typedef VectorPolicy<I3StationHitPtr>::ThePolicy;
#pragma link C++ class VectorPolicy<I3StationHitPtr>::ThePolicy+;
#pragma link C++ function operator!= (const I3ArrayHit::iterator &,
                                      const I3ArrayHit::iterator &);
#pragma link C++ typedef I3ArrayHitPtr;

#pragma link C++ class I3ArrayHitDict+;
//#pragma link C++ class I3ArrayHitDict::iterator+;
#pragma link C++ typedef MapPolicy<string, I3ArrayHitPtr>::ThePolicy;
#pragma link C++ class MapPolicy<string, I3ArrayHitPtr>::ThePolicy+;
#pragma link C++ function operator!= (const I3ArrayHitDict::iterator &,
                                      const I3ArrayHitDict::iterator &);
#pragma link C++ typedef I3ArrayHitDictPtr;


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
//#pragma link C++ class I3DigitalReadout+;
//#pragma link C++ typedef I3DigitalReadoutPtr;
#pragma link C++ class I3DigitalLaunch+;
#pragma link C++ typedef I3DigitalLaunchPtr;
#pragma link C++ class I3DOMLaunch+;
#pragma link C++ typedef I3DOMLaunchPtr;
#pragma link C++ class I3TWRLaunch+;
#pragma link C++ typedef I3TWRLaunchPtr;
#pragma link C++ class I3Directional+;
#pragma link C++ class I3Energetic+;
#pragma link C++ class I3MCEvent+;
#pragma link C++ typedef I3MCEventPtr;
#pragma link C++ class I3MCPhoton+;
#pragma link C++ typedef I3MCPhotonPtr;
#pragma link C++ class I3Event+;
#pragma link C++ typedef I3EventPtr;
#pragma link C++ class I3EventHeader+;
#pragma link C++ typedef I3EventHeaderPtr;
#pragma link C++ class I3GeometryHeader+;
#pragma link C++ typedef I3GeometryHeaderPtr;
#pragma link C++ class I3Hit+;
#pragma link C++ typedef I3HitPtr;
#pragma link C++ class I3Infinite+;
#pragma link C++ class I3Localized+;
#pragma link C++ class I3MCHit+;
#pragma link C++ typedef I3MCHitPtr;
#pragma link C++ class I3MCOMResponse+;
#pragma link C++ typedef I3MCOMResponsePtr;
#pragma link C++ class I3MCPMTResponse+;
#pragma link C++ typedef I3MCPMTResponsePtr;
#pragma link C++ class I3MCParticleData+;
#pragma link C++ typedef I3MCParticleDataPtr;
#pragma link C++ class I3Monitoring+;
#pragma link C++ typedef I3MonitoringPtr;
#pragma link C++ class I3MonitoringHeader+;
#pragma link C++ typedef I3MonitoringHeaderPtr;
#pragma link C++ class I3NonComposite+;
#pragma link C++ class I3NonCoreLocalized+;
#pragma link C++ class I3NonDirectional+;
#pragma link C++ class I3NonEnergetic+;
#pragma link C++ class I3ObservableParticle+;
#pragma link C++ typedef I3ObservableParticlePtr;
#pragma link C++ class I3OMGeo+;

#pragma link C++ class I3OMGeoAMANDA+;

#pragma link C++ typedef I3OMGeoAMANDAPtr;
//#pragma link C++ class I3OMGeoAMANDAPtr+;
#pragma link C++ class I3OMGeoIceCube+;

#pragma link C++ typedef I3OMGeoIceCubePtr;
//#pragma link C++ class I3OMGeoIceCubePtr+;

//#pragma link C++ class I3RecoResultPtr+;

#pragma link C++ class I3Geometry+;
#pragma link C++ typedef I3GeometryPtr;
#pragma link C++ class I3OMResponse+;
#pragma link C++ typedef I3OMResponsePtr;`
#pragma link C++ class I3OMStatus+;
#pragma link C++ typedef I3OMStatusPtr;
#pragma link C++ class I3OMStatusIceCube+;
#pragma link C++ typedef I3OMStatusIceCube::OMTrigSource;
#pragma link C++ typedef I3OMStatusIceCube::OnOff;
#pragma link C++ typedef I3OMStatusIceCube::LCMode;
#pragma link C++ typedef I3OMStatusIceCubePtr;
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
#pragma link C++ class I3RecoResultTopCore+;
#pragma link C++ typedef I3RecoResultTopCorePtr;
#pragma link C++ class I3RecoResultTopDirection+;
#pragma link C++ typedef I3RecoResultTopDirectionPtr;
#pragma link C++ class I3SLCReadout+;
#pragma link C++ typedef I3SLCReadoutPtr;
#pragma link C++ class I3Starting+;
#pragma link C++ class I3Stopping+;
#pragma link C++ class I3SummaryPulseReadout+;
#pragma link C++ typedef I3SummaryPulseReadoutPtr;
#pragma link C++ class I3TankGeo+;
#pragma link C++ typedef I3TankGeoPtr;
#pragma link C++ class I3TankHit+;
#pragma link C++ typedef I3TankHitPtr;
#pragma link C++ class I3TankMaterial+;
#pragma link C++ class I3Track+;
#pragma link C++ typedef I3TrackPtr;
#pragma link C++ class I3Trigger+;
#pragma link C++ typedef I3TriggerPtr;
#pragma link C++ class I3Filter+;
#pragma link C++ typedef I3FilterPtr;

#pragma link C++ class I3AMANDAExtractor+;
#pragma link C++ class I3IceCubeExtractor+;
#pragma link C++ class I3RecoHitTimeWindowSelector+;
#pragma link C++ class I3OMGeoListedSelector+;
#pragma link C++ class I3TrackExtractor+;
#pragma link C++ class I3CascadeExtractor+;
#pragma link C++ class vector<I3OMGeoAMANDAPtr>+;
#pragma link C++ class OMKey+;

#pragma link C++ class UniqueID;


#endif




