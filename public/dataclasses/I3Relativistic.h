#ifndef I3RELATIVISTIC_H
#define I3RELATIVISTIC_H

#include "I3Units.h"

/**
 * @todo implement the speed of light differently
 */
class I3Relativistic {
 public:
  virtual bool IsSpeedy() const {return true;}
  virtual double Speed() const { return 300000000 * I3Units::m / I3Units::s;}
  virtual void Speed(double) {return;}
  ClassDef(I3Relativistic,1);
};

#endif // I3RELATIVISTIC_H
