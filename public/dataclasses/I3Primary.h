#ifndef I3PRIMARY_H
#define I3PRIMARY_H

#include "Rtypes.h"
#include "I3Particle.h"

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Primary.h,v 1.1.2.1 2004/04/16 17:10:56 pretz Exp $
 *
 * @version $Revision: 1.1.2.1 $
 * @date $Date: 2004/04/16 17:10:56 $
 * @author pretz
 *
 * @todo implement fatal calls
 *
 */
class I3Primary : public I3Particle{
 public:
  virtual bool HasCorePosition() {return false;}

  virtual double CoreX() {return NAN;}

  virtual double CoreY() {return NAN;}

  virtual double CoreT() {return NAN;}

  ClassDef(I3Primary,1);
};


#endif
