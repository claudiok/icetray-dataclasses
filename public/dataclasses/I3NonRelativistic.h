#ifndef I3NONRELATIVISTIC_H
#define I3NONRELATIVISTIC_H

#include "I3Units.h"

/**
 * @todo implement the speed of light differently
 */
class I3NonRelativistic {
 private:
  double fSpeed;
 public:
  virtual bool IsSpeedy(){return true;}

  virtual double Speed(){ return fSpeed;}
  virtual void Speed(double speed){fSpeed = speed;}

  ClassDef(I3NonRelativistic,1);
};

#endif // I3NONRELATIVISTIC_H
