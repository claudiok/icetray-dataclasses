/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3TankMaterial.h,v 1.1 2004/02/19 18:23:43 niessen Exp $

    @version $Revision: 1.1 $
    @date $Date: 2004/02/19 18:23:43 $
    @author Peter Niessen Thu Feb 19 11:42:22 EST 2004

    @brief This class describes the materials inside the tank. It
    describes the filling heights, the ice quality, the liner etc.

    This class is currently empty but will be filled in light of the
    upcoming tank simulation.

    @todo Fill it with meaning

*/
#ifndef __I3TANKMATERIAL_H_
#define __I3TANKMATERIAL_H_

#include <TObject.h>

class I3TankMaterial : public TObject
{

 public:
  
  I3TankMaterial () {}
  
  I3TankMaterial (const I3TankMaterial &right) { *this = right; }
  I3TankMaterial &operator= (const I3TankMaterial &right) { return *this; }

  ClassDef (I3TankMaterial, 1);

};

#endif

