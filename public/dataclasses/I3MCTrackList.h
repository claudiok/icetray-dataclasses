#ifndef I3MCTRACKLIST_H
#define I3MCTRACKLIST_H

#include <TObject.h>
#include <TObjArray.h>

#include "I3MCTrack.h"
#include "I3Iterator.h"

class I3MCTrackList : public TObject
{
  TObjArray  *mctrack;
  
 public:
  I3MCTrackList();
  virtual ~I3MCTrackList();
  
  int GetNumberMCTracks() const;
  const I3MCTrack& GetMCTrack(unsigned short number) const;
  void AddMCTrack(I3MCTrack* mctrack_);
  I3Iterator<const I3MCTrack>* MakeMCTrackIterator() const;

  
  ClassDef(I3MCTrackList, 1);
};
#endif
