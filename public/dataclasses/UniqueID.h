/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: UniqueID.h,v 1.3 2004/08/04 18:52:55 pretz Exp $
 *
 * @file UniqueID.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/08/04 18:52:55 $
 * @author ehrlich
 */
#ifndef UNIQUEID_H
#define UNIQUEID_H

#include "I3Bag.h"
#include "I3MCEvent.h"
#include "I3RecoResultSingleTrack.h"
#include "I3RecoResultMultiTracks.h"
#include "I3Particle.h"
#include "I3RecoResultDict.h"


/**
 * @todo document this class
 */
class UniqueID
{
  public:

  enum IDOption
  {
    GET_UNIQUE_ID = 0,
    SET_ALL_UNIQUE_ID = 1,
    SET_ALL_NULL = 2
  };

  UniqueID() {};
  ~UniqueID() {};
  Int_t ID(TObjectPtr obj, IDOption option=GET_UNIQUE_ID);
  Int_t ID(I3MCEventPtr obj, IDOption option=GET_UNIQUE_ID);
  Int_t ID(I3MCParticleDataPtr obj, IDOption option=GET_UNIQUE_ID);
  Int_t ID(I3MCParticleMultiMapPtr obj, IDOption option=GET_UNIQUE_ID);
  Int_t ID(I3EventPtr obj, IDOption option=GET_UNIQUE_ID);
  Int_t ID(I3RecoResultDictPtr obj, IDOption option=GET_UNIQUE_ID);
  Int_t ID(I3RecoResultPtr obj, IDOption option=GET_UNIQUE_ID);
  Int_t ID(I3ParticlePtr obj, IDOption option=GET_UNIQUE_ID);

  ClassDef(UniqueID,0);
};
#endif
