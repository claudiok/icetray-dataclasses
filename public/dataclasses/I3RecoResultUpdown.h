#ifndef I3RECORESULTUPDOWN_H
#define I3RECORESULTUPDOWN_H

#include "I3RecoResult.h"

class I3RecoResultUpdown : public I3RecoResult
{
  float qualityparameter;

  public:
  I3RecoResultUpdown();

  float GetQualityparameter() const;
  void  SetQualityparameter(float qualityparameter_);

  bool                   IsUpdownTrackList() const;
  const I3RecoTrackList* GetUpTrackList() const;
  const I3RecoTrackList* GetDownTrackList() const;
  bool                   SetUpdownTrackList(I3RecoTrackList* uptracklist, I3RecoTrackList* downtracklist);

  ClassDef(I3RecoResultUpdown, 1);
};
#endif

