#ifndef I3RECORESULTDOUBLEMUON_H
#define I3RECORESULTDOUBLEMUON_H

#include "I3RecoResultSingleTrackList.h"

class I3RecoResultDoublemuon : public I3RecoResultSingleTrackList
{
  float qualityparameter;

  public:
  I3RecoResultDoublemuon();

  float GetQualityparameter() const;
  void  SetQualityparameter(float qualityparameter_);

  bool               AreTwotracks() const;
  const I3RecoTrack& GetFirstTrack() const;
  const I3RecoTrack& GetSecondTrack() const;
  bool               SetTracks(I3RecoTrack& firsttrack, I3RecoTrack& secondtrack);

  ClassDef(I3RecoResultDoublemuon, 1);
};
#endif
