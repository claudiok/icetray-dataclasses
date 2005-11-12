// LinkDef.h
// $Id$
// $Date$

#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;

// namespaces

#pragma link C++ namespace I3Units;
#pragma link C++ namespace I3Constants;
#pragma link C++ namespace boost;


#pragma link C++ class I3TrackImpl<I3Starting,I3Energetic,I3NonComposite>+;
#pragma link C++ class I3TrackImpl<I3Starting,I3NonEnergetic,I3NonComposite>+;
#pragma link C++ class I3TrackImpl<I3Contained,I3Energetic,I3Composite>+;
#pragma link C++ class I3TrackImpl<I3Stopping,I3Energetic,I3Composite>+;
#pragma link C++ class I3TrackImpl<I3Infinite,I3Energetic,I3Composite>+;
#pragma link C++ class I3TrackImpl<I3Infinite,I3Energetic,I3NonComposite>+;
#pragma link C++ class I3TrackImpl<I3Infinite,I3NonEnergetic,I3Composite>+;
#pragma link C++ class I3TrackImpl<I3Starting,I3NonEnergetic,I3Composite>+;
#pragma link C++ class I3TrackImpl<I3Stopping,I3NonEnergetic,I3NonComposite>+;
#pragma link C++ class I3TrackImpl<I3Contained,I3NonEnergetic,I3NonComposite>+;
#pragma link C++ class I3TrackImpl<I3Infinite,I3NonEnergetic,I3NonComposite>+;

#pragma link C++ class I3BasicTrack+;
#pragma link C++ class I3ContainedTrack+;

#pragma link C++ class I3DoubleBang+;
#pragma link C++ class I3MCTrack+;
#pragma link C++ class I3MCInfiniteTrack+;


#pragma link C++ class I3CascadeImpl<I3Directional,I3Localized,I3Energetic,I3Composite>+;
#pragma link C++ class I3CascadeImpl<I3NonDirectional,I3Localized,I3NonEnergetic,I3NonComposite>+;
#pragma link C++ class I3CascadeImpl<I3Directional,I3Localized,I3NonEnergetic,I3NonComposite>+;
#pragma link C++ class I3CascadeImpl<I3NonDirectional,I3Localized,I3Energetic,I3NonComposite>+;
#pragma link C++ class I3CascadeImpl<I3Directional,I3Localized,I3Energetic,I3NonComposite>+;

#pragma link C++ class I3BasicCascade+;

#pragma link C++ class I3DirectionalCascade+;

#pragma link C++ class I3PrimaryImpl<I3Directional,I3CoreLocalized,I3Energetic>+;
#pragma link C++ class I3PrimaryImpl<I3Directional,I3Localized,I3Energetic>+;
#pragma link C++ class I3TopShowerImpl<I3NonDirectional, I3CoreLocalized, I3NonEnergetic>+;
#pragma link C++ class I3TopShowerImpl<I3Directional, I3CoreLocalized, I3Energetic>+;
#pragma link C++ class I3TopShowerImpl<I3Directional, I3NonLocalized, I3NonEnergetic>+;

#pragma link C++ class I3MCCorePrimary+;

#pragma link C++ class I3MCPrimary+;

#pragma link C++ class I3MCCascade+;

#pragma link C++ class I3ShowerCore+;
#pragma link C++ class I3ShowerDirection+;

// vector (series, list) types
// these must go from outermost to innermost
// otherwise you will get errors of the sort
// 'specializaton after instantiation', and
// 'prototype for blahblah does not match any in class blahblah'

#pragma link C++ class I3IceCubeDOMStatusDict+;
#pragma link C++ class I3RecoResultDict+;
#pragma link C++ class I3DataReadoutDict+;
#pragma link C++ class I3DetectorStatus;
#pragma link C++ class I3DetectorStatusHeader;

#pragma link C++ class I3DigitalReadout+;
#pragma link C++ class I3InIceGeometry+;

// tpm: my addition
#pragma link C++ class I3InIceCalibration+;

#pragma link C++ class I3AMANDACalibration+;
#pragma link C++ class I3MCHitSeries+;
#pragma link C++ class I3PMTPulseVect+;
#pragma link C++ class I3DigitalReadout+;
#pragma link C++ class I3RecoHitSeries+;

#pragma link C++ class I3RecoPulseSeries+;

#pragma link C++ class I3Particle+;
#pragma link C++ class shared_ptr<I3Particle>+;

#pragma link C++ class I3ParticleMultiMap+;
#pragma link C++ class STLMultiMapStoragePolicy< string,I3ParticlePtr>+;

#pragma link C++ class I3Bag+;

#pragma link C++ class I3OMResponseMap+;

#pragma link C++ class I3RecoHitSeriesDict+;

#pragma link C++ class I3RecoPulseSeriesDict+;

#pragma link C++ class I3MCWeightDict+;

#pragma link C++ class I3SurfModuleGeo+;

#pragma link C++ classs I3StationGeo+;

#pragma link C++ class I3StationMap+;

#pragma link C++ class I3StationHit+;

// simple types with full value semantics

#pragma link C++ class I3AMANDAAnalogReadout+;

#pragma link C++ class I3AnalogReadout+;

#pragma link C++ class I3Cascade+;

#pragma link C++ class I3Contained+;
#pragma link C++ class I3Composite+;
#pragma link C++ class I3CoreLocalized+;

#pragma link C++ class I3DataHeader+;
#pragma link C++ class I3DataReadout+;
#pragma link C++ class I3DetectorStatusHeader;

#pragma link C++ class I3DigitalReadout+;
#pragma link C++ class I3DigitalLaunch+;
#pragma link C++ class I3DOMLaunch+;

#pragma link C++ class I3TWRFrag+;
#pragma link C++ class I3TWRLaunch+;


#pragma link C++ class I3Direction+;
#pragma link C++ class I3Directional+;
#pragma link C++ class I3Energetic+;

#pragma link C++ class I3Event+;
#pragma link C++ class I3EventHeader+;

#pragma link C++ class I3MCEvent+;
#pragma link C++ class I3MCEventHeader+;

#pragma link C++ class I3GeometryHeader+;
#pragma link C++ class I3CalibrationHeader+;

#pragma link C++ class I3Hit+;
#pragma link C++ class I3Infinite+;
#pragma link C++ class I3Localized+;

#pragma link C++ class I3MCHit+;

#pragma link C++ class I3MCOMResponse+;

#pragma link C++ class I3MCPMTResponse+;

#pragma link C++ class I3PMTPulse+;

#pragma link C++ class I3MCParticleData+;

#pragma link C++ class I3NonComposite+;
#pragma link C++ class I3NonLocalized+;
#pragma link C++ class I3NonDirectional+;
#pragma link C++ class I3NonEnergetic+;

#pragma link C++ class I3InIceParticle+;
#pragma link C++ class I3IceTopParticle+;
#pragma link C++ class I3MCTopShower+;

#pragma link C++ class I3OMGeoAMANDA+;

#pragma link C++ class I3OMGeoIceTop+;

#pragma link C++ class I3OMGeoIceCube+;
#pragma link C++ class I3Geometry+;

#pragma link C++ class I3OMResponse+;

#pragma link C++ class I3OMResponseSelection+;

#pragma link C++ class I3OMSelectionDict+;

#pragma link C++ class I3OMListSelection+;

#pragma link C++ class I3GoodOMSelection+;

#pragma link C++ class I3BadOMSelection+;

// tpm: my additions
#pragma link C++ struct LinearFit+;

#pragma link C++ class I3TriggerDict+;

#pragma link C++ class I3Trigger+;

#pragma link C++ class I3TriggerStatusDict+;
#pragma link C++ class I3TriggerStatus+;


#pragma link C++ class I3DOMCalibration+;

#pragma link C++ class I3AMANDAOMCalib+;

#pragma link C++ class I3AMANDAOMCalib_XTalk+;

#pragma link C++ class I3Calibration+;
#pragma link C++ class I3Position+;
#pragma link C++ class I3Primary+;
#pragma link C++ class I3TopShower+;

#pragma link C++ class I3RecoHit+;
#pragma link C++ class I3RecoPulse+;
#pragma link C++ class I3RecoResult+;
#pragma link C++ class I3RecoResultRDMCFit+;
#pragma link C++ class I3RecoResultSingleParticle+;

#pragma link C++ class I3RecoResultMultiTracks+;

#pragma link C++ class I3Starting+;
#pragma link C++ class I3Stopping+;

#pragma link C++ class I3TankGeo+;
#pragma link C++ class I3TankHit+;

#pragma link C++ class I3TopGeometry+;

#pragma link C++ class I3Track+;

#pragma link C++ class OMKey+;

#pragma link C++ class I3OMGeo+;

#pragma link C++ class I3Time+;

#pragma link C++ class I3Monitoring+;
#pragma link C++ class I3MonitoringHeader+;

#pragma link C++ class I3FlasherInfo+;

#endif




