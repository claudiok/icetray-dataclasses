/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TankMaterial.h,v 1.3 2004/04/27 13:35:23 pretz Exp $
 *
 * @file I3TankMaterial.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/04/27 13:35:23 $
 * @author Peter Niessen Thu Feb 19 11:42:22 EST 2004
 */
#ifndef __I3TANKMATERIAL_H_
#define __I3TANKMATERIAL_H_

#include <TObject.h>

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

  ClassDef (I3TankMaterial, 1);

};

#endif

