#ifndef I3PRIMARY_H
#define I3PRIMARY_H

#include "Rtypes.h"
#include "I3Particle.h"

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Primary.h,v 1.2 2004/04/22 15:55:44 pretz Exp $
 *
 * @version $Revision: 1.2 $
 * @date $Date: 2004/04/22 15:55:44 $
 * @author pretz
 *
 * @todo implement fatal calls
 *
 */
class I3Primary : public I3Particle{
 public:
  virtual Bool_t HasCorePosition() {return false;}

  virtual Double_t CoreX() {return NAN;}

  virtual Double_t CoreY() {return NAN;}

  virtual Double_t CoreT() {return NAN;}

  ClassDef(I3Primary,1);
};


#endif
