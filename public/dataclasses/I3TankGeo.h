/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TankGeo.h,v 1.8 2004/07/30 19:15:59 dule Exp $
 *
 * @file I3TankGeo.h
 * @version $Revision: 1.8 $
 * @date $Date: 2004/07/30 19:15:59 $
 * @author PN Thu Feb 19 11:48:23 EST 2004
 */
#ifndef __I3TANKGEO_H_
#define __I3TANKGEO_H_

#include <iostream>

#include <TObject.h>

#include "dataclasses/I3TankMaterial.h"
#include "dataclasses/I3InIceGeometry.h"
#include "dataclasses/I3Constants.h"

using namespace std;

/**
 * @brief Class which describes a single tank
 * @todo comment methods
 * @todo Should this class use something other than I3InIceGeometry?
 */
class I3TankGeo : public TObject
{
  public:

  I3TankGeo() {}

  UShort_t GetTankID() const {return fTankID;}
  void SetTankID(UShort_t tank_id) { fTankID = tank_id; }

/*   Double_t X () const { return fX; } */
/*   void   X(Double_t x) { fX = x; } */

/*   Double_t Y () const { return fY; } */
/*   void   Y (Double_t y) { fY = y; } */

  I3Position GetTankPos() const { return fTankPos; }
  void SetTankPos(I3Position pos) { fTankPos.SetPosition(pos); }
  void SetTankPos(Double_t x, Double_t y) {fTankPos.SetPosition(x,y,I3Constants::zIceTop);}

  Double_t GetTankRadius() const { return fTankR; }
  void SetTankRadius(Double_t r) { fTankR = r; }

  Double_t  GetTankHeight() const { return fTankH; }
  void SetTankHeight(Double_t h) { fTankH = h; }

  UChar_t Version() const { return fVersion; }
  void Version(UChar_t version) { fVersion = version; }

  const I3TankMaterial &Material () const { return fMaterial; }
  I3TankMaterial& Material() {return fMaterial;}

  const I3InIceGeometry &OM () const { return fOM; }
  I3InIceGeometry& OM() {return fOM;}


 private:

  UShort_t fTankID; // the tank id 
  I3Position fTankPos; //position of the tank
  Double_t fTankR; // radius of the tank
  Double_t fTankH; // height of the tank
/*   Double_t fX; // the position along grid north */
/*   Double_t fY; // the position along grid east */

  I3TankMaterial fMaterial;
  
  UChar_t fVersion; // some version number.

  I3InIceGeometry fOM; // the oms inside the tank
  
  ClassDef(I3TankGeo,1);

};

#include "dataclasses/StoragePolicy.h"
typedef PtrPolicy<I3TankGeo>::ThePolicy I3TankGeoPtr;

class I3TankGeoMatchesTankID {
  
 public:

  /**
   * Constructor.
   */
  I3TankGeoMatchesTankID (UShort_t tank_id) : id (tank_id) {
    cerr << "Got id " << tank_id << endl;
  }

  /**
   * Comparison operator.
   */
  bool operator () (I3TankGeoPtr tg) const {
    cerr << "trying to assess equality" << endl;
    return id == tg->GetTankID();
  }
 private:
  UShort_t id;
  
};

#endif

