/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: UniqueID.h,v 1.6 2004/08/14 16:41:16 pretz Exp $
 *
 * @file UniqueID.h
 * @version $Revision: 1.6 $
 * @date $Date: 2004/08/14 16:41:16 $
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
 *class UniqueID
 *This  class should be used to assign a unique ID to each particle
 *relative to a given dataclass object, e.g.
 *my_particle->SetParticleID(UniqueID::ID(my_event))
 *gives my_particle an ID which doesn't exist yet in my_event or
 *my_particle->SetParticleID(UniqueID::ID(my_recoresult_dict)
 *gives my_particle an ID which doesn't exist yet in my_recoresult_dict.

 *This class gives also the option to assign a unique ID to all particles
 *of a dataclass object, e.g.
 *UniqueID::ID(my_mcevent, UniqueID::SET_ALL_UNIQUE_ID)
 *gives a unique ID to every particle in my_mcevent.

 *These unique IDs are used to identify particles, e.g. for
 *parent-child-relations, or to relate MC hits to a particular MC particle.

 *The IDs can be set and returned in I3MCHit and I3Particle by
 *Set/GetParticleID().
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
  Int_t ID(I3ParticleMultiMapPtr obj, IDOption option=GET_UNIQUE_ID);
  Int_t ID(I3EventPtr obj, IDOption option=GET_UNIQUE_ID);
  Int_t ID(I3RecoResultDictPtr obj, IDOption option=GET_UNIQUE_ID);
  Int_t ID(I3RecoResultPtr obj, IDOption option=GET_UNIQUE_ID);
  Int_t ID(I3ParticlePtr obj, IDOption option=GET_UNIQUE_ID);

  ClassDef(UniqueID,0);
};
#endif
