#ifndef I3RECORESULTSINGLETRACKLIST_H
#define I3RECORESULTSINGLETRACKLIST_H

#include "I3RecoResult.h"

class I3RecoResultSingleTrackList : public I3RecoResult
{
  public:
  I3RecoResultSingleTrackList();

  bool                   HasSingleTrackList() const;
  const I3RecoTrackList& GetSingleTrackList() const;
  bool                   SetSingleTrackList(I3RecoTrackList* recotracklist_);

  ClassDef(I3RecoResultSingleTrackList, 1);
};
#endif

