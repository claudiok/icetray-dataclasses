/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3TankGeo.h,v 1.2 2004/02/26 18:17:01 pretz Exp $

    @version $Revision: 1.2 $
    @date $Date: 2004/02/26 18:17:01 $
    @author PN Thu Feb 19 11:48:23 EST 2004

    @brief Class which describes a single tank

    @todo 

*/

#ifndef __I3TANKGEO_H_
#define __I3TANKGEO_H_

#include <TObject.h>

#include "dataclasses/I3TankMaterial.h"
#include "dataclasses/I3InIceGeometry.h"

class I3TankGeo : public TObject
{
  public:

  I3TankGeo () {}

  UShort_t TankID () const {return fTankID;}
  void   TankID (UShort_t tank_id) { fTankID = tank_id; }

  Double_t X () const { return fX; }
  void   X(Double_t x) { fX = x; }

  Double_t Y () const { return fY; }
  void   Y (Double_t y) { fY = y; }

  Double_t R () const { return fR; }
  void     R (Double_t r) { fR = r; }

  Double_t  H () const { return fH; }
  void    H (Double_t h) { fH = h; }

  UChar_t Version () const { return fVersion; }
  void    Version (UChar_t version) { fVersion = version; }

  const I3TankMaterial &Material () const { return fMaterial; }
  void Material (I3TankMaterial material) { fMaterial = material; }

  const I3InIceGeometry &OM () const { return fOM; }
  void OM (I3InIceGeometry om) { fOM = om; }

 private:

  UShort_t fTankID; // the tank id 

  Double_t fX; // the position along grid north
  Double_t fY; // the position along grid east
  Double_t fR; // radius of the tank
  Double_t fH; // height of the tank

  I3TankMaterial fMaterial;
  
  UChar_t fVersion; // some version number.

  I3InIceGeometry fOM; // the oms inside the tank
  
  ClassDef(I3TankGeo,1);
};
#endif

