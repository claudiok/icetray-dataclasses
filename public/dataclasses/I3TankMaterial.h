/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TankMaterial.h,v 1.6 2004/08/31 02:56:29 pretz Exp $
 *
 * @file I3TankMaterial.h
 * @version $Revision: 1.6 $
 * @date $Date: 2004/08/31 02:56:29 $
 * @author Peter Niessen Thu Feb 19 11:42:22 EST 2004
 */
#ifndef __I3TANKMATERIAL_H_
#define __I3TANKMATERIAL_H_

#include <TObject.h>
#include "StoragePolicy.h"

/**
 * @brief This class describes the materials inside the tank. It
 * describes the filling heights, the ice quality, the liner etc.
 *
 * This class is currently empty but will be filled in light of the
 * upcoming tank simulation.
 *
 * @todo Fill it with meaning
 */
class I3TankMaterial : public TObject
{

 public:
  
  I3TankMaterial () {}
  
  I3TankMaterial (const I3TankMaterial &right) { *this = right; }
  I3TankMaterial &operator= (const I3TankMaterial &right) { return *this; }

  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3TankMaterial ]\n";
    }

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }

 private:
  // ROOT macro
  ClassDef (I3TankMaterial, 1);

};

/**
 * @todo need to implement this better.
 */
inline ostream& operator<<(ostream& o, I3TankMaterial& material)
{
  material.ToStream(o);
  return o;
}

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3TankMaterial>::ThePolicy I3TankMaterialPtr;

#endif

