#ifndef I3RECORESULT_H
#define I3RECORESULT_H

#include <TObject.h>
#include <TObjArray.h>
#include "I3RecoTrackList.h"

class I3RecoResult : public TObject
{
  protected:
  TObjArray     *recotracklist;
  TRef          bestrecotracklist;

  public:
           I3RecoResult();
  virtual ~I3RecoResult();

  const char* GetRecomethod() const;

  int                    GetNumberRecoTrackLists() const;
  const I3RecoTrackList& GetRecoTrackList(unsigned short index) const;
  void                   AddRecoTrackList(I3RecoTrackList* recotracklist_);

  bool                   HasBestRecoTrackList() const;
  const I3RecoTrackList& GetBestRecoTrackList() const;
  void                   SetBestRecoTrackList(I3RecoTrackList* bestrecotracklist_);

  ClassDef(I3RecoResult, 1);
};
#endif
