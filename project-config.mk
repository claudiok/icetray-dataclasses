CXX_BIN_SRCDIR_NAMES := 
TEST_SRCDIR_NAMES := test test-autogen

USES_PROJECTS := icetray 
USES_TOOLS := root log4cplus roost TUT boost

ROOT_DICTIONARY_HEADERS := dataclasses/I3AMANDAAnalogReadout.h	\
dataclasses/I3MCTopShower.h dataclasses/I3AMANDAExtractor.h	\
dataclasses/I3MCTrack.h dataclasses/I3AMANDAPMTPulse.h		\
dataclasses/I3Monitoring.h dataclasses/I3AnalogReadout.h	\
dataclasses/I3MonitoringHeader.h 				\
dataclasses/I3ArrayHit.h	      dataclasses/I3MonoTrack.h \
dataclasses/I3ArrayHitDict.h	      dataclasses/I3MuonBundle.h \
dataclasses/I3Atmosphere.h	      dataclasses/I3NonComposite.h \
dataclasses/I3BadOMSelection.h	      dataclasses/I3NonDirectional.h \
dataclasses/I3Bag.h		      dataclasses/I3NonEnergetic.h \
dataclasses/I3BasicCascade.h	      dataclasses/I3NonLocalized.h \
dataclasses/I3BasicMuon.h	      dataclasses/I3OMGeo.h \
dataclasses/I3BasicTrack.h	      dataclasses/I3OMGeoAMANDA.h \
dataclasses/I3Calibration.h	      dataclasses/I3OMGeoIceCube.h \
dataclasses/I3CalibrationHeader.h     dataclasses/I3OMGeoIceTop.h \
dataclasses/I3Cascade.h		      dataclasses/I3OMGeoListedSelector.h \
dataclasses/I3CascadeExtractor.h      dataclasses/I3OMListSelection.h \
dataclasses/I3CascadeImpl.h	      dataclasses/I3OMResponse.h \
dataclasses/I3Composite.h	      dataclasses/I3OMResponseMap.h \
dataclasses/I3Constants.h	      dataclasses/I3OMResponseSelection.h \
dataclasses/I3Contained.h	      dataclasses/I3OMSelectionDict.h \
dataclasses/I3CoreLocalized.h	      dataclasses/I3OMStatus.h \
dataclasses/I3DOMCalibration.h	      dataclasses/I3OMStatusIceCube.h \
dataclasses/I3DOMLaunch.h	      dataclasses/I3OddOMSelection.h \
dataclasses/I3DataExecution.h	      dataclasses/I3PMTPulse.h \
dataclasses/I3DataHeader.h	      dataclasses/I3PMTPulseVect.h \
dataclasses/I3DataReadout.h	      dataclasses/I3Particle.h \
dataclasses/I3DataReadoutDict.h       dataclasses/I3ParticleMultiMap.h \
dataclasses/I3DecayingMuon.h	      dataclasses/I3Position.h \
dataclasses/I3DetectorStatus.h	      dataclasses/I3Primary.h \
dataclasses/I3DetectorStatusHeader.h  dataclasses/I3PrimaryImpl.h \
dataclasses/I3DigitalLaunch.h	      dataclasses/I3RDMCLaunch.h \
dataclasses/I3DigitalReadout.h	      dataclasses/I3RecoHit.h \
dataclasses/I3Direction.h	      dataclasses/I3RecoHitSeries.h \
dataclasses/I3Directional.h	      dataclasses/I3RecoHitSeriesDict.h \
dataclasses/I3DirectionalCascade.h    dataclasses/I3RecoResult.h \
dataclasses/I3DoubleBang.h	      dataclasses/I3RecoResultAltTracks.h \
dataclasses/I3Energetic.h	      dataclasses/I3RecoResultDict.h \
dataclasses/I3EnergyCascade.h	      dataclasses/I3RecoResultLikelihood.h \
dataclasses/I3EnergyMuon.h	      dataclasses/I3RecoResultMultiTracks.h \
dataclasses/I3EvenOMSelection.h       dataclasses/I3RecoResultRDMCFit.h \
dataclasses/I3Event.h		      dataclasses/I3RecoResultSingleTrack.h \
dataclasses/I3RecoResultSingleTopShower.h dataclasses/I3RecoResultSingleParticle.h \
dataclasses/I3EventHeader.h \
dataclasses/I3F2KRecoCascade.h	\
dataclasses/I3F2KRecoTrack.h	      dataclasses/I3SLCReadout.h \
dataclasses/I3Filter.h		      dataclasses/I3SPASEModuleGeo.h \
dataclasses/I3FilterDict.h	      dataclasses/I3ShowerCore.h \
dataclasses/I3GaussianPMTPulse.h      dataclasses/I3ShowerDirection.h \
dataclasses/I3Geometry.h	      dataclasses/I3ShoweringMuon.h \
dataclasses/I3GeometryHeader.h	      dataclasses/I3Starting.h \
dataclasses/I3GoodOMSelection.h       dataclasses/I3StartingMuon.h \
dataclasses/I3Hit.h		      dataclasses/I3StationGeo.h \
dataclasses/I3IceCubeExtractor.h      dataclasses/I3StationHit.h \
dataclasses/I3IceTopCalibration.h     dataclasses/I3StationItr.h \
dataclasses/I3IceTopParticle.h	      dataclasses/I3StationMap.h \
dataclasses/I3IceTopStationStatus.h   dataclasses/I3Stopping.h \
dataclasses/I3IceTopStatus.h	      dataclasses/I3StoppingMuon.h \
dataclasses/I3InIceCalibration.h      dataclasses/I3SummaryPulseReadout.h \
dataclasses/I3InIceGeometry.h	      dataclasses/I3SurfModuleGeo.h \
dataclasses/I3InIceParticle.h	      dataclasses/I3TWRLaunch.h \
dataclasses/I3InIceStatus.h	      dataclasses/I3TankGeo.h \
dataclasses/I3Infinite.h	      dataclasses/I3TankHit.h \
dataclasses/I3Localized.h	      dataclasses/I3TankMaterial.h \
dataclasses/I3Lollipop.h	      dataclasses/I3TopGeometry.h \
dataclasses/I3MCCascade.h	      dataclasses/I3TopShower.h \
dataclasses/I3MCCorePrimary.h	      dataclasses/I3TopShowerImpl.h \
dataclasses/I3MCEvent.h		      dataclasses/I3Track.h \
dataclasses/I3MCEventHeader.h	      dataclasses/I3TrackExtractor.h \
dataclasses/I3MCHit.h		      dataclasses/I3TrackImpl.h \
dataclasses/I3MCHitSeries.h	      dataclasses/I3Trigger.h \
dataclasses/I3MCOMResponse.h	      dataclasses/I3TriggerDict.h \
dataclasses/I3MCPMTResponse.h	      dataclasses/I3Units.h \
dataclasses/I3MCPMTResponseRomeo.h    dataclasses/OMKey.h \
dataclasses/I3MCPMTResponseToy.h      dataclasses/STLMapStoragePolicy.h \
dataclasses/I3MCParticleData.h	      dataclasses/STLMultiMapStoragePolicy.h \
dataclasses/I3MCPhoton.h	      dataclasses/STLVectorStoragePolicy.h \
dataclasses/I3MCPhotonVect.h	      dataclasses/StationKey.h \
dataclasses/I3MCPrimary.h	      dataclasses/StoragePolicy.h \
dataclasses/I3MCTankHit.h	      
#	      dataclasses/I3RecoResultTopCore.h \
#      dataclasses/I3RecoResultTopDirection.h \
