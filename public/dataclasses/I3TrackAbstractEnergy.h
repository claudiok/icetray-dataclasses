#ifndef I3TRACKABSTRACTENERGY_H
#define I3TRACKABSTRACTENERGY_H

#include <TObject.h>

class I3TrackAbstractEnergy
{
  public:
  virtual float Energy()=0;
  virtual void Energy(float)=0;

  ClassDef(I3TrackAbstractEnergy, 1);
};
#endif
 
