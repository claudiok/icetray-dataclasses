#ifndef I3TRACKABSTRACTSTART_H
#define I3TRACKABSTRACTSTART_H

#include <TObject.h>

class I3TrackAbstractStart
{
  public:
  virtual float StartX()=0;
  virtual float StartY()=0;
  virtual float StartZ()=0;
  virtual float StartT()=0;
  virtual void StartX(float)=0;
  virtual void StartY(float)=0;
  virtual void StartZ(float)=0;
  virtual void StartT(float)=0;

  ClassDef(I3TrackAbstractStart, 1);
};
#endif
 
