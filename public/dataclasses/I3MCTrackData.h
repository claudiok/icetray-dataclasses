#ifndef I3MCTRACKDATA_H
#define I3MCTRACKDATA_H

#include <TObject.h>
#include <TObjArray.h>

#include "I3MCTrackList.h"
#include "dataclasses/I3Iterator.h"

class I3MCTrackData : public TObject
{
  TObjArray  *mctracklist;

  public:
           I3MCTrackData();
  virtual ~I3MCTrackData();

  int GetNumberMCTrackLists() const;
  const I3MCTrackList& GetMCTrackList(unsigned short number) const;
  void AddMCTrackList(I3MCTrackList* mctracklist_);
  I3Iterator<const I3MCTrackList>* MakeTrackListIterator();

  ClassDef(I3MCTrackData, 1);
};
#endif
