/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: UniqueID.h,v 1.2 2004/08/01 00:41:01 pretz Exp $
 *
 * @file UniqueID.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/08/01 00:41:01 $
 * @author ehrlich
 */
#ifndef UNIQUEID_H
#define UNIQUEID_H

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
  Int_t ID(TObject *obj, IDOption option=GET_UNIQUE_ID);
  Int_t ID(I3MCEvent *obj, IDOption option=GET_UNIQUE_ID);
  Int_t ID(I3MCParticleData *obj, IDOption option=GET_UNIQUE_ID);
  Int_t ID(I3MCParticleMultiMap *obj, IDOption option=GET_UNIQUE_ID);
  Int_t ID(I3Event *obj, IDOption option=GET_UNIQUE_ID);
  Int_t ID(I3RecoResultDict *obj, IDOption option=GET_UNIQUE_ID);
  Int_t ID(I3RecoResult *obj, IDOption option=GET_UNIQUE_ID);
  Int_t ID(I3Particle *obj, IDOption option=GET_UNIQUE_ID);

  ClassDef(UniqueID,0);
};
#endif
