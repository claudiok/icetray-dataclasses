/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoTrack.h,v 1.3.2.2 2004/04/10 16:38:59 troy Exp $
 *
 * @version $Revision: 1.3.2.2 $
 * @date $Date: 2004/04/10 16:38:59 $
 * @author
 *
 * @todo
 *
 */

#ifndef I3RECOTRACK_H
#define I3RECOTRACK_H

#include <TObject.h>

#include "dataclasses/I3BasicTrack.h"
#include "StoragePolicy.h"

class I3RecoTrack : public I3BasicTrack
{
  //FIXME: vectorvectorvector
  Int_t number_used_oms;
  Int_t *used_om;  //[number_used_oms]

  public:
           I3RecoTrack();
  virtual ~I3RecoTrack();

  Int_t        GetNumberusedoms() const;
  const Int_t* GetUsedoms() const;
  void         SetUsedoms(Int_t* used_om_, Int_t number_used_oms_);

  ClassDef(I3RecoTrack, 1);
};

typedef PtrPolicy<I3RecoTrack>::ThePolicy I3RecoTrackPtr;
#endif
