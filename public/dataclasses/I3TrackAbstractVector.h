#ifndef I3TRACKABSTRACTVECTOR_H
#define I3TRACKABSTRACTVECTOR_H

#include <TObject.h>

class I3TrackAbstractVector
{
  public:
  virtual float X()=0;
  virtual float Y()=0;
  virtual float Z()=0;
  virtual float T()=0;
  virtual void X(float)=0;
  virtual void Y(float)=0;
  virtual void Z(float)=0;
  virtual void T(float)=0;

  ClassDef(I3TrackAbstractVector, 1);
};
#endif
 
