#ifndef I3MCTRACKLIST_H
#define I3MCTRACKLIST_H

#include <TObject.h>
#include <TObjArray.h>

#include "I3MCTrack.h"

class I3MCTrackList : public TObject
{
  TObjArray  *mctrack;

  public:
           I3MCTrackList();
  virtual ~I3MCTrackList();

  int              GetNumberMCTracks() const;
  const I3MCTrack& GetMCTrack(unsigned short number) const;
  void             AddMCTrack(I3MCTrack* mctrack_);

  ClassDef(I3MCTrackList, 1);
};
#endif
