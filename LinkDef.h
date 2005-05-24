// testing svn overhaul

// LinkDef.h
// $Id$
// $Date$


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
#pragma link C++ namespace boost;

//#pragma link C++ class boost::count_type+;

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

#pragma link C++ class I3RecoResultSingleTopShower+;
//#pragma link C++ typedef I3RecoResultSingleTopShowerPtr;
//#pragma link C++ class boost::shared_ptr<I3RecoResultSingleTopShower>+;


#pragma link C++ class I3BasicTrack+;
#pragma link C++ class I3F2KRecoTrack+;
//#pragma link C++ typedef I3F2KRecoTrackPtr;
#pragma link C++ class I3DoubleBang+;
#pragma link C++ class I3MCTrack+;
//#pragma link C++ class JAMSFitTrack+;

#pragma link C++ class I3CascadeImpl<I3Directional,I3Localized,I3Energetic,I3Composite>+;
#pragma link C++ class I3CascadeImpl<I3NonDirectional,I3Localized,I3NonEnergetic,I3NonComposite>+;
#pragma link C++ class I3CascadeImpl<I3Directional,I3Localized,I3NonEnergetic,I3NonComposite>+;
#pragma link C++ class I3CascadeImpl<I3NonDirectional,I3Localized,I3Energetic,I3NonComposite>+;
#pragma link C++ class I3CascadeImpl<I3Directional,I3Localized,I3Energetic,I3NonComposite>+;

#pragma link C++ class I3BasicCascade+;
//#pragma link C++ typedef I3BasicCascadePtr;
//#pragma link C++ class boost::shared_ptr<I3BasicCascade>+;

#pragma link C++ class I3DirectionalCascade+;
//#pragma link C++ typedef I3DirectionalCascadePtr;
//#pragma link C++ class boost::shared_ptr<I3DirectionalCascade>+;

#pragma link C++ class I3F2KRecoCascade+;
//#pragma link C++ typedef I3F2KRecoCascadePtr;
//#pragma link C++ class boost::shared_ptr<I3F2KRecoCascade>+;

#pragma link C++ class I3CompleteCascade+;

#pragma link C++ class I3PrimaryImpl<I3Directional,I3CoreLocalized,I3Energetic>+;
#pragma link C++ class I3PrimaryImpl<I3Directional,I3Localized,I3Energetic>+;
#pragma link C++ class I3TopShowerImpl<I3NonDirectional, I3CoreLocalized, I3NonEnergetic>+;
#pragma link C++ class I3TopShowerImpl<I3Directional, I3CoreLocalized, I3Energetic>+;
#pragma link C++ class I3TopShowerImpl<I3Directional, I3NonLocalized, I3NonEnergetic>+;

#pragma link C++ class I3MCCorePrimary+;
//#pragma link C++ typedef I3MCCorePrimaryPtr;
//#pragma link C++ class boost::shared_ptr<I3MCCorePrimary>+;

#pragma link C++ class I3MCPrimary+;
//#pragma link C++ typedef I3MCPrimaryPtr;
//#pragma link C++ class boost::shared_ptr<I3MCPrimary>+;

#pragma link C++ class I3MCCascade+;
//#pragma link C++ typedef I3MCCascadePtr;
//#pragma link C++ class boost::shared_ptr<I3MCCascade>+;

#pragma link C++ class I3ShowerCore+;
//#pragma link C++ typedef I3ShowerCorePtr;
//#pragma link C++ class boost::shared_ptr<I3ShowerCore>+;

#pragma link C++ class I3ShowerDirection+;
//#pragma link C++ class I3ShowerDirectionPtr;
//#pragma link C++ class boost::shared_ptr<I3ShowerDirection>+;

//
// vector (series, list) types
// these must go from outermost to innermost
// otherwise you will get errors of the sort
// 'specializaton after instantiation', and
// 'prototype for blahblah does not match any in class blahblah'
//

#pragma link C++ class I3IceCubeStatus+;
//#pragma link C++ typedef MapPolicy<OMKey,I3OMStatusIceCubePtr>::ThePolicy;
//#pragma link C++ class MapPolicy<OMKey,I3OMStatusIceCubePtr>::ThePolicy+;
//#pragma link C++ typedef I3IceCubeStatusPtr;

#pragma link C++ class I3RecoResultDict+;
//#pragma link C++ typedef MapPolicy<string,I3RecoResultPtr>::ThePolicy;
//#pragma link C++ class MapPolicy<string,I3RecoResultPtr>::ThePolicy+;
//#pragma link C++ typedef I3RecoResultDictPtr;

#pragma link C++ class I3DataReadoutDict+;
//#pragma link C++ typedef MapPolicy<string,I3DataReadoutPtr>::ThePolicy;
//#pragma link C++ class MapPolicy<string,I3DataReadoutPtr>::ThePolicy+;
//#pragma link C++ typedef I3DataReadoutDictPtr;

#pragma link C++ class I3DetectorStatus;
//#pragma link C++ typedef I3DetectorStatusPtr;
//#pragma link C++ class boost::shared_ptr<I3DetectorStatus>+;

#pragma link C++ class I3DetectorStatusHeader;
//#pragma link C++ typedef I3DetectorStatusHeaderPtr;
//#pragma link C++ class boost::shared_ptr<I3DetectorStatusHeader>+;

#pragma link C++ class I3DigitalReadout+;
//#pragma link C++ typedef I3DigitalReadoutPtr;
//#pragma link C++ class boost::shared_ptr<I3DigitalReadout>+;


#pragma link C++ class I3InIceGeometry+;
//#pragma link C++ typedef MapPolicy<OMKey,I3OMGeoPtr>::ThePolicy;
//#pragma link C++ class MapPolicy<OMKey,I3OMGeoPtr>::ThePolicy+;
//#pragma link C++ typedef I3InIceGeometryPtr;
//#pragma link C++ class boost::shared_ptr<I3InIceGeometry>+;
//#pragma link C++ class pair<OMKey,boost::shared_ptr<I3OMGeo> >+;

// tpm: my addition
#pragma link C++ class I3InIceCalibration+;
//#pragma link C++ typedef MapPolicy<OMKey,I3DOMCalibPtr>::ThePolicy;
//#pragma link C++ class MapPolicy<OMKey,I3DOMCalibPtr>::ThePolicy+;
//#pragma link C++ typedef I3DOMCalibPtr;
//#pragma link C++ class I3DOMCalibPtr+;

#pragma link C++ class I3MCHitSeries+;
//#pragma link C++ typedef VectorPolicy<I3MCHit>::ThePolicy;
//#pragma link C++ class VectorPolicy<I3MCHit>::ThePolicy+;
//#pragma link C++ typedef I3MCHitSeriesPtr;
//#pragma link C++ class boost::shared_ptr<I3MCHitSeries>+;

#pragma link C++ class I3PMTPulseVect+;
//#pragma link C++ typedef VectorPolicy<I3PMTPulsePtr>::ThePolicy;
//#pragma link C++ class VectorPolicy<I3PMTPulsePtr>::ThePolicy+;
//#pragma link C++ typedef I3PMTPulseVectPtr;
//#pragma link C++ class boost::shared_ptr<I3PMTPulseVect>+;

#pragma link C++ class I3DigitalReadout+;
//#pragma link C++ typedef VectorPolicy<I3DigitalLaunchPtr>::ThePolicy;
//#pragma link C++ class VectorPolicy<I3DigitalLaunchPtr>::ThePolicy+;
//#pragma link C++ typedef I3DigitalReadoutPtr;
//#pragma link C++ class boost::shared_ptr<I3RecoHitSeries>+;

#pragma link C++ class I3RecoHitSeries+;
//#pragma link C++ typedef VectorPolicy<I3RecoHitPtr>::ThePolicy;
//#pragma link C++ class VectorPolicy<I3RecoHitPtr>::ThePolicy+;
//#pragma link C++ typedef I3RecoHitSeriesPtr;
//#pragma link C++ class boost::shared_ptr<I3RecoHitSeries>+;

#pragma link C++ class I3RecoPulseSeries+;

#pragma link C++ class I3Particle+;
//#pragma link C++ typedef I3ParticlePtr;
#pragma link C++ class shared_ptr<I3Particle>+;
//#pragma link C++ class vector<I3ParticlePtr>+;

#pragma link C++ class I3ParticleMultiMap+;
#pragma link C++ class STLMultiMapStoragePolicy< string,I3ParticlePtr>+;
//#pragma link C++ typedef MultiMapPolicy<string,I3ParticlePtr>::ThePolicy;
//#pragma link C++ class MultiMapPolicy<string,I3ParticlePtr>::ThePolicy+;
//#pragma link C++ typedef I3ParticleMultiMapPtr;
//#pragma link C++ class boost::shared_ptr<I3ParticleMultiMap>+;

//#pragma link C++ typedef TObjectPtr;
//#pragma link C++ class TObjectPtr+;
#pragma link C++ class I3Bag+;
//#pragma link C++ typedef MapPolicy<string,TObjectPtr>::ThePolicy;
//#pragma link C++ class MapPolicy<string,TObjectPtr>::ThePolicy+;
//#pragma link C++ typedef I3BagPtr;
//#pragma link C++ class boost::shared_ptr<I3Bag>+;

#pragma link C++ class I3OMResponseMap+;
//#pragma link C++ typedef MapPolicy<OMKey,I3OMResponsePtr>::ThePolicy;
//#pragma link C++ class MapPolicy<OMKey,I3OMResponsePtr>::ThePolicy+;
//#pragma link C++ typedef I3OMResponseMapPtr;
//#pragma link C++ class boost::shared_ptr<I3OMResponseMap>+;
//#pragma link C++ class pair<OMKey,boost::shared_ptr<I3OMResponse> >+;

#pragma link C++ class I3RecoHitSeriesDict+;
//#pragma link C++ typedef MapPolicy<string,I3RecoHitSeriesPtr>::ThePolicy;
//#pragma link C++ class MapPolicy<string,I3RecoHitSeriesPtr>::ThePolicy+;
//#pragma link C++ typedef I3RecoHitSeriesDictPtr;
//#pragma link C++ class boost::shared_ptr<I3RecoHitSeriesDict>+;

#pragma link C++ class I3RecoPulseSeriesDict+;

#pragma link C++ class I3MCWeightDict+;
//#pragma link C++ typedef MapPolicy<string,float>::ThePolicy;
//#pragma link C++ class MapPolicy<string,float>::ThePolicy+;
//#pragma link C++ typedef I3MCWeightDictPtr;
//#pragma link C++ class boost::shared_ptr<I3MCWeightDict>+;

#pragma link C++ class I3SurfModuleGeo+;
//#pragma link C++ typedef MapPolicy<OMKey, I3OMGeoPtr>::ThePolicy;
//#pragma link C++ class MapPolicy<OMKey, I3OMGeoPtr>::ThePolicy+;
//#pragma link C++ typedef I3SurfModuleGeoPtr;
//#pragma link C++ class I3SurfModuleGeoPtr+;
//#pragma link C++ class boost::shared_ptr<I3SurfModuleGeo>+;  

#pragma link C++ classs I3StationGeo+;
//#pragma link C++ typedef VectorPolicy<I3SurfModuleGeoPtr>::ThePolicy;
//#pragma link C++ class VectorPolicy<I3SurfModuleGeoPtr>::ThePolicy+;
//#pragma link C++ typedef I3StationGeoPtr;
//#pragma link C++ class I3StationGeoPtr+;
//#pragma link C++ class boost::shared_ptr<I3StationGeo>+;

#pragma link C++ class I3StationMap+;
//#pragma link C++ typedef MapPolicy<StationKey, I3StationGeoPtr>::ThePolicy;
//#pragma link C++ class MapPolicy<StationKey, I3StationGeoPtr>::ThePolicy+;
//#pragma link C++ typedef I3StationMapPtr;
//#pragma link C++ class I3StationMapPtr+;
//#pragma link C++ class boost::shared_ptr<I3StationMap>+;

#pragma link C++ class I3StationHit+;
//#pragma link C++ typedef VectorPolicy<I3TankHitPtr>::ThePolicy;
//#pragma link C++ class VectorPolicy<I3TankHitPtr>::ThePolicy+;
//#pragma link C++ typedef I3StationHitPtr;
//#pragma link C++ class I3StationHitPtr+;

//#pragma link C++ typedef VectorPolicy<I3StationHitPtr>::ThePolicy;
//#pragma link C++ class VectorPolicy<I3StationHitPtr>::ThePolicy+;

//
// simple types with full value semantics
//

#pragma link C++ class I3AMANDAAnalogReadout+;
//#pragma link C++ typedef I3AMANDAAnalogReadoutPtr;
//#pragma link C++ class boost::shared_ptr<I3AMANDAAnalogReadout>+;

#pragma link C++ class I3AnalogReadout+;
//#pragma link C++ typedef I3AnalogReadoutPtr;
//#pragma link C++ class boost::shared_ptr<I3AnalogReadout>+;

#pragma link C++ class I3Cascade+;
//#pragma link C++ typedef I3CascadePtr;
//#pragma link C++ class boost::shared_ptr<I3Cascade>+;

#pragma link C++ class I3Contained+;
#pragma link C++ class I3Composite+;
#pragma link C++ class I3CoreLocalized+;

#pragma link C++ class I3DataHeader+;
//#pragma link C++ typedef I3DataHeaderPtr;
//#pragma link C++ class boost::shared_ptr<I3DataHeader>+;

#pragma link C++ class I3DataReadout+;
//#pragma link C++ typedef I3DataReadoutPtr;
//#pragma link C++ class boost::shared_ptr<I3DataReadout>+;

#pragma link C++ class I3DetectorStatusHeader;
//#pragma link C++ typedef I3DetectorStatusHeaderPtr;
//#pragma link C++ class boost::shared_ptr<I3DetectorStatusHeader>+;

#pragma link C++ class I3DigitalReadout+;
//#pragma link C++ typedef I3DigitalReadoutPtr;
//#pragma link C++ class boost::shared_ptr<I3DigitalReadout>+;

#pragma link C++ class I3DigitalLaunch+;
//#pragma link C++ typedef I3DigitalLaunchPtr;
//#pragma link C++ class boost::shared_ptr<I3DigitalLaunch>+;

#pragma link C++ class I3DOMLaunch+;
//#pragma link C++ typedef I3DOMLaunchPtr;
//#pragma link C++ class boost::shared_ptr<I3DOMLaunch>+;

#pragma link C++ class I3TWRFrag+;
//#pragma link C++ typedef I3TWRFragPtr;
//#pragma link C++ class boost::shared_ptr<I3TWRFrag>+;

#pragma link C++ class I3TWRLaunch+;
//#pragma link C++ typedef VectorPolicy<I3TWRFragPtr>::ThePolicy;
//#pragma link C++ class VectorPolicy<I3TWRFragPtr>::ThePolicy+;
//#pragma link C++ typedef I3TWRLaunchPtr;
//#pragma link C++ class boost::shared_ptr<I3TWRLaunch>+;

#pragma link C++ class I3Direction+;
//#pragma link C++ typedef I3DirectionPtr;
//#pragma link C++ class boost::shared_ptr<I3Direction>+;

#pragma link C++ class I3Directional+;
#pragma link C++ class I3Energetic+;

#pragma link C++ class I3Event+;
//#pragma link C++ typedef I3EventPtr;
//#pragma link C++ class boost::shared_ptr<I3Event>+;

#pragma link C++ class I3EventHeader+;
//#pragma link C++ typedef I3EventHeaderPtr;
//#pragma link C++ class boost::shared_ptr<I3EventHeader>+;

#pragma link C++ class I3MCEvent+;
//#pragma link C++ typedef I3MCEventPtr;
//#pragma link C++ class boost::shared_ptr<I3MCEvent>+;

#pragma link C++ class I3MCEventHeader+;
//#pragma link C++ typedef I3MCEventHeaderPtr;
//#pragma link C++ class boost::shared_ptr<I3MCEventHeader>+;

#pragma link C++ class I3GeometryHeader+;
//#pragma link C++ typedef I3GeometryHeaderPtr;
//#pragma link C++ class boost::shared_ptr<I3GeometryHeader>+;

#pragma link C++ class I3CalibrationHeader+;
//#pragma link C++ typedef I3CalibrationHeaderPtr;
//#pragma link C++ class boost::shared_ptr<I3CalibrationHeader>+;

#pragma link C++ class I3Hit+;
//#pragma link C++ typedef I3HitPtr;
//#pragma link C++ class boost::shared_ptr<I3Hit>+;

#pragma link C++ class I3Infinite+;
#pragma link C++ class I3Localized+;

#pragma link C++ class I3MCHit+;
//#pragma link C++ typedef I3MCHitPtr;
//#pragma link C++ class boost::shared_ptr<I3MCHit>+;

#pragma link C++ class I3MCOMResponse+;
//#pragma link C++ typedef I3MCOMResponsePtr;
//#pragma link C++ class boost::shared_ptr<I3MCOMResponse>+;

#pragma link C++ class I3MCPMTResponse+;
//#pragma link C++ typedef I3MCPMTResponsePtr;
//#pragma link C++ class boost::shared_ptr<I3MCPMTResponse>+;

#pragma link C++ class I3MCPMTResponseRomeo+;
//#pragma link C++ typedef I3MCPMTResponseRomeoPtr;
//#pragma link C++ class boost::shared_ptr<I3MCPMTResponseRomeo>+;

#pragma link C++ class I3PMTPulse+;
//#pragma link C++ typedef I3PMTPulsePtr;
//#pragma link C++ class boost::shared_ptr<I3PMTPulse>+;

#pragma link C++ class I3GaussianPMTPulse+;
//#pragma link C++ typedef I3GaussianPMTPulsePtr;
//#pragma link C++ class boost::shared_ptr<I3GaussianPMTPulse>+;

#pragma link C++ class I3AMANDAPMTPulse+;
//#pragma link C++ typedef I3AMANDAPMTPulsePtr;
//#pragma link C++ class boost::shared_ptr<I3AMANDAPMTPulse>+;

#pragma link C++ class I3MCParticleData+;
//#pragma link C++ typedef I3MCParticleDataPtr;
//#pragma link C++ class boost::shared_ptr<I3MCParticleData>;

#pragma link C++ class I3NonComposite+;
#pragma link C++ class I3NonLocalized+;
#pragma link C++ class I3NonDirectional+;
#pragma link C++ class I3NonEnergetic+;

#pragma link C++ class I3InIceParticle+;
//#pragma link C++ typedef I3InIceParticlePtr;
//#pragma link C++ class boost::shared_ptr<I3InIceParticle>;

#pragma link C++ class I3IceTopParticle+;
//#pragma link C++ typedef I3IceTopParticlePtr;
//#pragma link C++ class boost::shared_ptr<I3IceTopParticle>+;


#pragma link C++ class I3MCTopShower+;
//#pragma link C++ typedef I3MCTopShowerPtr;
//#pragma link C++ class boost::shared_ptr<I3MCTopShower>+;

#pragma link C++ class I3OMGeoAMANDA+;
//#pragma link C++ typedef I3OMGeoAMANDAPtr;
//#pragma link C++ class boost::shared_ptr<I3OMGeoAMANDA>+;

#pragma link C++ class I3OMGeoIceTop+;
//#pragma link C++ typedef I3OMGeoIceTopPtr;
//#pragma link C++ class boost::shared_ptr<I3OMGeoIceTop>+;

#pragma link C++ class I3OMGeoIceCube+;
//#pragma link C++ typedef I3OMGeoIceCubePtr;
//#pragma link C++ class boost::shared_ptr<I3OMGeoIceCube>+;

#pragma link C++ class I3Geometry+;
//#pragma link C++ typedef I3GeometryPtr;
//#pragma link C++ class boost::shared_ptr<I3Geometry>+;

#pragma link C++ class I3OMResponse+;
//#pragma link C++ typedef I3OMResponsePtr;
//#pragma link C++ class boost::shared_ptr<I3OMResponse>+;

#pragma link C++ class I3OMResponseSelection+;
//#pragma link C++ typedef I3OMResponseSelectionPtr;
//#pragma link C++ class boost::shared_ptr<I3OMResponseSelection>+;

#pragma link C++ class I3OMSelectionDict+;
//#pragma link C++ typedef MapPolicy<string,I3OMResponseSelectionPtr>::ThePolicy;
//#pragma link C++ class MapPolicy<string,I3OMResponseSelectionPtr>::ThePolicy+;
//#pragma link C++ typedef I3OMSelectionDictPtr;
//#pragma link C++ class boost::shared_ptr<I3OMSelectionDict>+;

#pragma link C++ class I3OMListSelection+;
//#pragma link C++ typedef I3OMListSelectionPtr;
//#pragma link C++ class boost::shared_ptr<I3OMListSelection>+;

#pragma link C++ class I3GoodOMSelection+;
//#pragma link C++ typedef I3GoodOMSelectionPtr;
//#pragma link C++ class boost::shared_ptr<I3GoodOMSelection>+;

#pragma link C++ class I3BadOMSelection+;
//#pragma link C++ typedef I3BadOMSelectionPtr;
//#pragma link C++ class boost::shared_ptr<I3BadOMSelection>+;

//#pragma link C++ class VectorPolicy<OMKey>;
//#pragma link C++ typedef VectorPolicy<OMKey>::ThePolicy;
//#pragma link C++ class VectorPolicy<OMKey>::ThePolicy+;

// tpm: my additions
#pragma link C++ struct LinearFit+;

#pragma link C++ class I3TriggerDict+;
//#pragma link C++ typedef MapPolicy<string,I3TriggerPtr>::ThePolicy;
//#pragma link C++ class MapPolicy<string,I3TriggerPtr>::ThePolicy+;
//#pragma link C++ typedef I3TriggerDictPtr;
//#pragma link C++ class boost::shared_ptr<I3TriggerDict>+;

#pragma link C++ class I3Trigger+;
//#pragma link C++ typedef I3TriggerPtr;
//#pragma link C++ class boost::shared_ptr<I3Trigger>+;

#pragma link C++ class I3DOMCalibration+;
//#pragma link C++ typedef I3DOMCalibPtr;
//#pragma link C++ class boost::shared_ptr<I3DOMCalibration>+;

#pragma link C++ class I3Calibration+;
//#pragma link C++ typedef I3CalibPtr;
//#pragma link C++ class boost::shared_ptr<I3Calibration>+;

//#warning I3OMSlr problems, fixme
//#if 1
//#pragma link C++ class I3OMSlr+;
//#pragma link C++ typedef I3OMSlrPtr;
//#pragma link C++ class boost::shared_ptr<I3OMSlr>+;
//
//#pragma link C++ class I3OMSlrList+;
//#pragma link C++ typedef I3OMSlrListPtr;
//#pragma link C++ class boost::shared_ptr<I3OMSlrList>+;
//#endif

#pragma link C++ class I3Position+;
//#pragma link C++ typedef I3PositionPtr;
//#pragma link C++ class boost::shared_ptr<I3Position>+;

#pragma link C++ class I3Primary+;
#pragma link C++ class I3TopShower+;

#pragma link C++ class I3RecoHit+;
//#pragma link C++ typedef I3RecoHitPtr;
//#pragma link C++ class boost::shared_ptr<I3RecoHit>+;

#pragma link C++ class I3RecoPulse+;

#pragma link C++ class I3RecoResult+;
//#pragma link C++ typedef I3RecoResultPtr;
//#pragma link C++ class boost::shared_ptr<I3RecoResult>+;

#pragma link C++ class I3RecoResultRDMCFit+;
//#pragma link C++ typedef I3RecoResultRDMCFitPtr;
//#pragma link C++ class boost::shared_ptr<I3RecoResultRDMCFit>+;

#pragma link C++ class I3RecoResultSingleParticle+;
//#pragma link C++ typedef I3RecoResultSingleParticlePtr;
//#pragma link C++ class boost::shared_ptr<I3RecoResultSingleParticle>+;

#pragma link C++ class I3RecoResultSingleTrack+;
//#pragma link C++ typedef I3RecoResultSingleTrackPtr;
//#pragma link C++ class boost::shared_ptr<I3RecoResultSingleTrack>+;

#pragma link C++ class I3Starting+;
#pragma link C++ class I3Stopping+;

#pragma link C++ class I3TankGeo+;
//#pragma link C++ typedef I3TankGeoPtr;
//#pragma link C++ class boost::shared_ptr<I3TankGeo>+;

#pragma link C++ class I3TankHit+;
//#pragma link C++ typedef I3TankHitPtr;
//#pragma link C++ class boost::shared_ptr<I3TankHit>+;

#pragma link C++ class I3TopGeometry+;
//#pragma link C++ typedef I3TopGeometryPtr;
//#pragma link C++ class boost::shared_ptr<I3TopGeometry>+;

#pragma link C++ class I3Track+;
//#pragma link C++ typedef I3TrackPtr;
//#pragma link C++ class boost::shared_ptr<I3Track>+;

//#pragma link C++ class vector<I3OMGeoAMANDAPtr>+;

//#pragma link C++ class std::pair<OMKey,boost::shared_ptr<I3OMGeo> >;
//#pragma link C++ class pair<OMKey,boost::shared_ptr<I3OMResponse> >;
//#pragma link C++ class boost::shared_ptr<TObject>;

#pragma link C++ class OMKey+;
//#pragma link C++ typedef OMKeyPtr;
//#pragma link C++ class boost::shared_ptr<OMKey>+;

//#pragma link C++ typedef StationKey;

#pragma link C++ class I3OMGeo+;
//#pragma link C++ typedef I3OMGeoPtr;
//#pragma link C++ class boost::shared_ptr<I3OMGeo>+;

#pragma link C++ class I3Time+;

#pragma link C++ class I3Monitoring+;
#pragma link C++ class I3MonitoringHeader+;

#endif




