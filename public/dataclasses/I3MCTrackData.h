#ifndef I3MCTRACKDATA_H
#define I3MCTRACKDATA_H

#include <TObject.h>
#include <TObjArray.h>

#include "dataclasses/I3Iterator.h"

class I3MCTrackList;

class I3MCTrackData : public TObject
{
 public:
  I3MCTrackData();
  virtual ~I3MCTrackData();
  int GetNumberMCTrackLists() const;
  const I3MCTrackList& GetMCTrackList(unsigned short number) const;
  Bool_t HasTrueMCTrackList() const;
  const I3MCTrackList& GetTrueMCTrackList() const;
  void AddMCTrackList(I3MCTrackList* mctracklist_);
  void SetTrueTrackList(I3MCTrackList& list);
  I3Iterator<const I3MCTrackList>* MakeTrackListIterator() const;
 private:
  TObjArray  *mctracklist;
  I3MCTrackList* fTrueTrackList;
  ClassDef(I3MCTrackData, 1);
};
#endif
