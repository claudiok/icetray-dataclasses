#ifndef I3CASCADE_H
#define I3CASCADE_H

#include "Rtypes.h"
#include "I3Particle.h"

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Cascade.h,v 1.1.2.1 2004/04/16 17:10:56 pretz Exp $
 *
 * @version $Revision: 1.1.2.1 $
 * @date $Date: 2004/04/16 17:10:56 $
 * @author pretz
 *
 * @todo implement fatal calls
 *
 */
class I3Cascade : public I3Particle{
 public:
  virtual bool IsLocalized() const =0;

  virtual double X() const =0;

  virtual double Y() const =0;

  virtual double Z() const =0;

  virtual double T() const =0;

  ClassDef(I3Cascade,1);
};


#endif
