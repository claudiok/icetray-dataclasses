#ifndef TI3RECOTRACKCOMPOSITE_H
#define TI3RECOTRACKCOMPOSITE_H

#include <TObject.h>
#include <TRefArray.h>
#include "I3RecoTrack.h"

class I3RecoTrackComposite : public I3RecoTrack
{
  TObjArray *constituent;

  public: 
           I3RecoTrackComposite();
  virtual ~I3RecoTrackComposite();

  unsigned short     GetNumberConstituents() const;
  const I3RecoTrack& GetConstituent(unsigned short number) const;
  void               AddConstituent(I3RecoTrack& constituent_);

  ClassDef(I3RecoTrackComposite, 1);
};
#endif

