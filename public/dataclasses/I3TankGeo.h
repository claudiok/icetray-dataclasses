/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TankGeo.h,v 1.6 2004/06/30 17:20:26 pretz Exp $
 *
 * @file I3TankGeo.h
 * @version $Revision: 1.6 $
 * @date $Date: 2004/06/30 17:20:26 $
 * @author PN Thu Feb 19 11:48:23 EST 2004
 */
#ifndef __I3TANKGEO_H_
#define __I3TANKGEO_H_

#include <TObject.h>

#include "dataclasses/I3TankMaterial.h"
#include "dataclasses/I3InIceGeometry.h"

/**
 * @brief Class which describes a single tank
 * @todo comment methods
 * @todo Should this class use something other than I3InIceGeometry?
 */
class I3TankGeo : public TObject
{
  public:

  I3TankGeo () {}

  UShort_t GetTankID () const {return fTankID;}
  void   SetTankID (UShort_t tank_id) { fTankID = tank_id; }

  Double_t GetX () const { return fX; }
  void   SetX(Double_t x) { fX = x; }

  Double_t GetY () const { return fY; }
  void   SetY (Double_t y) { fY = y; }

  Double_t GetR () const { return fR; }
  void     SetR (Double_t r) { fR = r; }

  Double_t  GetH () const { return fH; }
  void    SetH (Double_t h) { fH = h; }

  UChar_t GetVersion () const { return fVersion; }
  void    SetVersion (UChar_t version) { fVersion = version; }

  const I3TankMaterial &GetMaterial () const { return fMaterial; }
  I3TankMaterial& GetMaterial() {return fMaterial;}

  const I3InIceGeometry &GetOM () const { return fOM; }
  I3InIceGeometry& GetOM() {return fOM;}


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

