/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Primary.h,v 1.4 2004/04/27 13:35:23 pretz Exp $
 *
 * @file I3Primary.h
 * @version $Revision: 1.4 $
 * @date $Date: 2004/04/27 13:35:23 $
 * @author pretz
  */
#ifndef I3PRIMARY_H
#define I3PRIMARY_H

#include "Rtypes.h"
#include "I3Particle.h"

/**
 * @brief Represents a particle which induces an event in the detector.
 * @todo implement fatal calls
 * @todo make methods pure virtual
 * @todo comments

 */
class I3Primary : public I3Particle{
 public:
  virtual Bool_t IsObservable() {return false;}
   
  virtual Bool_t HasCorePosition() {return false;}

  virtual Double_t CoreX() {return NAN;}

  virtual Double_t CoreY() {return NAN;}

  virtual Double_t CoreT() {return NAN;}

  ClassDef(I3Primary,1);
};


#endif
