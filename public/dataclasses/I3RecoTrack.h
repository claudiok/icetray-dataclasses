#ifndef I3RECOTRACK_H
#define I3RECOTRACK_H

#include <TObject.h>
#include <TObjArray.h>
#include "I3Track.h"
#include "StoragePolicy.h"

class I3RecoTrack : public I3Track
{
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
