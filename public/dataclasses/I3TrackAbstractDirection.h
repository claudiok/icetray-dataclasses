#ifndef I3TRACKABSTRACTDIRECTION_H
#define I3TRACKABSTRACTDIRECTION_H

#include <TObject.h>

class I3TrackAbstractDirection
{
  public:
  virtual float Theta()=0;
  virtual float Phi()=0;
  virtual void Theta(float)=0;
  virtual void Phi(float)=0;

  ClassDef(I3TrackAbstractDirection, 1);
};
#endif
 
