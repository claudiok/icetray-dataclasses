#ifndef I3TRACKABSTRACTLENGTH_H
#define I3TRACKABSTRACTLENGTH_H

#include <TObject.h>

class I3TrackAbstractLength
{
  public:
  virtual float Length()=0;
  virtual void Length(float)=0;

  ClassDef(I3TrackAbstractLength, 1);
};
#endif
 
