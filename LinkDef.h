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

//classes

#pragma link C++ class I3CascadeImpl<I3Directional,I3Localized,I3Energetic,I3Composite>+; //
#pragma link C++ class I3CascadeImpl<I3Directional,I3Localized,I3Energetic,I3NonComposite>+; //
#pragma link C++ class I3CascadeImpl<I3Directional,I3Localized,I3NonEnergetic,I3NonComposite>+; //
#pragma link C++ class I3CascadeImpl<I3NonDirectional,I3Localized,I3Energetic,I3NonComposite>+; //
#pragma link C++ class I3CascadeImpl<I3NonDirectional,I3Localized,I3NonEnergetic,I3NonComposite>+; //
#pragma link C++ class I3PrimaryImpl<I3Directional,I3CoreLocalized,I3Energetic>+; //
#pragma link C++ class I3PrimaryImpl<I3Directional,I3Localized,I3Energetic>+; //
#pragma link C++ class I3TopShowerImpl<I3Directional, I3CoreLocalized, I3Energetic>+; //
#pragma link C++ class I3TopShowerImpl<I3Directional, I3NonLocalized, I3NonEnergetic>+; //
#pragma link C++ class I3TopShowerImpl<I3NonDirectional, I3CoreLocalized, I3NonEnergetic>+; //
#pragma link C++ class I3TrackImpl<I3Contained,I3Energetic,I3Composite>+; //
#pragma link C++ class I3TrackImpl<I3Contained,I3NonEnergetic,I3NonComposite>+; //
#pragma link C++ class I3TrackImpl<I3Infinite,I3Energetic,I3Composite>+; //
#pragma link C++ class I3TrackImpl<I3Infinite,I3Energetic,I3NonComposite>+; //
#pragma link C++ class I3TrackImpl<I3Infinite,I3NonEnergetic,I3Composite>+; //
#pragma link C++ class I3TrackImpl<I3Infinite,I3NonEnergetic,I3NonComposite>+; //
#pragma link C++ class I3TrackImpl<I3Starting,I3Energetic,I3NonComposite>+; //
#pragma link C++ class I3TrackImpl<I3Starting,I3NonEnergetic,I3Composite>+; //
#pragma link C++ class I3TrackImpl<I3Starting,I3NonEnergetic,I3NonComposite>+; //
#pragma link C++ class I3TrackImpl<I3Stopping,I3Energetic,I3Composite>+; //
#pragma link C++ class I3TrackImpl<I3Stopping,I3NonEnergetic,I3NonComposite>+; //


#pragma link C++ class I3AnalogReadout+;  //
#pragma link C++ class I3AMANDAAnalogReadout+;  //
#pragma link C++ class I3BasicCascade+; //
#pragma link C++ class I3BasicTrack+; //
#pragma link C++ class I3Cascade+; //
#pragma link C++ class I3Composite+; //
#pragma link C++ class I3Contained+; //
#pragma link C++ class I3ContainedTrack+; //
#pragma link C++ class I3CoreLocalized+; //
#pragma link C++ class I3DOMLaunch+; //
#pragma link C++ class I3DataReadout+; //
#pragma link C++ class I3DigitalLaunch+; //
#pragma link C++ class I3DigitalReadout+; //
#pragma link C++ class I3DigitalReadout+; //
#pragma link C++ class I3Direction+; //
#pragma link C++ class I3Directional+; //
#pragma link C++ class I3DirectionalCascade+; //
#pragma link C++ class I3DoubleBang+; //
#pragma link C++ class I3Energetic+; //
#pragma link C++ class I3FlasherInfo+; //
#pragma link C++ class I3Hit+; //
#pragma link C++ class I3IceTopParticle+; //
#pragma link C++ class I3InIceParticle+; //
#pragma link C++ class I3Infinite+; //
#pragma link C++ class I3Localized+; //
#pragma link C++ class I3MCCascade+; // 
#pragma link C++ class I3MCCorePrimary+; //
#pragma link C++ class I3MCHit+; //
#pragma link C++ class I3MCInfiniteTrack+; //
#pragma link C++ class I3MCOMResponse+; //
#pragma link C++ class I3MCPMTResponse+; //
#pragma link C++ class I3MCPrimary+; //
#pragma link C++ class I3MCTopShower+; //
#pragma link C++ class I3MCTrack+; //
#pragma link C++ class I3NonComposite+; //
#pragma link C++ class I3NonDirectional+; //
#pragma link C++ class I3NonEnergetic+; //
#pragma link C++ class I3NonLocalized+; //
#pragma link C++ class I3OMGeo+; //
#pragma link C++ class I3OMGeoAMANDA+; //
#pragma link C++ class I3OMGeoIceCube+; //
#pragma link C++ class I3OMGeoIceTop+; //
#pragma link C++ class I3OMResponse+; //
#pragma link C++ class I3PMTPulse+; //
#pragma link C++ class I3Particle+; //
#pragma link C++ class I3Position+; //
#pragma link C++ class I3Primary+; //
#pragma link C++ class I3RecoHit+; //
#pragma link C++ class I3RecoPulse+; //
#pragma link C++ class I3RecoResult+; //
#pragma link C++ class I3RecoResultMultiTracks+; //
#pragma link C++ class I3RecoResultRDMCFit+; //
#pragma link C++ class I3RecoResultSingleParticle+; //
#pragma link C++ class I3ShowerCore+; //
#pragma link C++ class I3ShowerDirection+; //
#pragma link C++ class I3Starting+; //
#pragma link C++ class I3Stopping+; //
#pragma link C++ class I3TWRFrag+; //
#pragma link C++ class I3TWRLaunch+; //
#pragma link C++ class I3TankHit+; //
#pragma link C++ class I3Time+; //
#pragma link C++ class I3TopShower+; //
#pragma link C++ class I3Track+; //
#pragma link C++ class I3Trigger+; //
#pragma link C++ class OMKey+; //

#endif




