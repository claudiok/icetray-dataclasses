#ifndef I3CASCADE_H
#define I3CASCADE_H

#include "Rtypes.h"
#include "I3Particle.h"

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Cascade.h,v 1.1.2.2 2004/04/19 18:15:33 pretz Exp $
 *
 * @version $Revision: 1.1.2.2 $
 * @date $Date: 2004/04/19 18:15:33 $
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

  virtual I3Position Pos() { return I3Position(X(),Y(),Z(),T());}

  ClassDef(I3Cascade,1);
};


#endif
