/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TankGeo.h,v 1.7 2004/07/13 15:37:54 niessen Exp $
 *
 * @file I3TankGeo.h
 * @version $Revision: 1.7 $
 * @date $Date: 2004/07/13 15:37:54 $
 * @author PN Thu Feb 19 11:48:23 EST 2004
 */
#ifndef __I3TANKGEO_H_
#define __I3TANKGEO_H_

#include <iostream>

#include <TObject.h>

#include "dataclasses/I3TankMaterial.h"
#include "dataclasses/I3InIceGeometry.h"

using namespace std;

/**
 * @brief Class which describes a single tank
 * @todo comment methods
 * @todo Should this class use something other than I3InIceGeometry?
 */
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
  I3TankMaterial& Material() {return fMaterial;}

  const I3InIceGeometry &OM () const { return fOM; }
  I3InIceGeometry& OM() {return fOM;}


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
    return id == tg->TankID ();
  }
 private:
  UShort_t id;
  
};

#endif

