#ifndef I3TRACKABSTRACTSTOP_H
#define I3TRACKABSTRACTSTOP_H

#include <TObject.h>

class I3TrackAbstractStop
{
  public:
  virtual float StopX()=0;
  virtual float StopY()=0;
  virtual float StopZ()=0;
  virtual float StopT()=0;
  virtual void StopX(float)=0;
  virtual void StopY(float)=0;
  virtual void StopZ(float)=0;
  virtual void StopT(float)=0;

  ClassDef(I3TrackAbstractStop, 1);
};
#endif
 
