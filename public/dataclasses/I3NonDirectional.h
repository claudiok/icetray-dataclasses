/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3NonDirectional.h
 * @version $Revision: 1.10 $
 * @date $Date$
 * @author pretz
 *
 * @todo implement fatal calls
 */
#ifndef I3NONDIRECTIONAL_H
#define I3NONDIRECTIONAL_H

#include "Rtypes.h"
#include "dataclasses/I3Particle.h"
#include "dataclasses/I3Direction.h"


 /**
  * @brief The directional part of an I3Cascade implementation, representing 
  * a cascade for which a direction hasn't been specified.
  */
class I3NonDirectional 
{
 public:
  /**
   * indicates that the cascade doesn't have a direction
   */
  virtual bool HasDirection() const {return false;}

  /**
   * Doesn't do anything.  There's nothing to copy.
   */
  void CopyTo(I3Particle&) const {}

  virtual void ToStream(ostream& o) const
    {
      o<<"Direction: NonDirectional\n";
    }

  virtual ~I3NonDirectional();

 private:

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version);

  //ROOT macro
  //ClassDef(I3NonDirectional,1);
};

#endif // I3NONDIRECTIONAL
