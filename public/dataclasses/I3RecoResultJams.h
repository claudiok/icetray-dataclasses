#ifndef I3RECORESULTJAMS_H
#define I3RECORESULTJAMS_H

#include "I3RecoResultSingleTrack.h"

class I3RecoResultJams : public I3RecoResultSingleTrack
{
  float qualityparameter;

  public:
  I3RecoResultJams();

  float GetQualityparameter() const;
  void  SetQualityparameter(float qualityparameter_);

  ClassDef(I3RecoResultJams, 1);
};
#endif
