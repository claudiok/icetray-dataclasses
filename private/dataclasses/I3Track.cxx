#include "dataclasses/I3Track.h"
#include "dataclasses/I3DataExecution.h"

ClassImp(I3Track);

I3Track::I3Track()
{
  fTrackNumber=0;
  fParticleId=Null;
  fStartTime=0;
  fStartX=0;
  fStartY=0;
  fStartZ=0;
  fStopTime=0;
  fStopX=0;
  fStopY=0;
  fStopZ=0;
  fLength=0;
  fZenith=0;
  fAzimuth=0;
  fEnergy=0;
  fParent = 0;
}
  
I3Track::~I3Track() {}
    
