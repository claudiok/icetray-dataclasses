/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TankGeo.h,v 1.10 2004/08/02 22:09:05 blaufuss Exp $
 *
 * @file I3TankGeo.h
 * @version $Revision: 1.10 $
 * @date $Date: 2004/08/02 22:09:05 $
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
class I3TankGeo : public TObject,
		  public VectorPolicy<I3OMGeoPtr>::ThePolicy
{
  public:

  I3TankGeo() {}
  virtual ~I3TankGeo() {}

  I3Position GetTankPos() const { return fTankPos; }
  void SetTankPos(I3Position pos) { fTankPos.SetPosition(pos); }
  void SetTankPos(Double_t x, Double_t y) {fTankPos.SetPosition(x,y,I3Constants::zIceTop);}

  Double_t GetTankRadius() const { return fTankR; }
  void SetTankRadius(Double_t r) { fTankR = r; }

  Double_t  GetTankHeight() const { return fTankH; }
  void SetTankHeight(Double_t h) { fTankH = h; }

  UChar_t GetVersion() const { return fVersion; }
  void SetVersion(UChar_t version) { fVersion = version; }

  const I3TankMaterial &Material () const { return fMaterial; }
  I3TankMaterial& Material() {return fMaterial;}


 private:

  I3Position fTankPos; //position of the tank
  Double_t fTankR; // radius of the tank
  Double_t fTankH; // height of the tank

  I3TankMaterial fMaterial;
  
  UChar_t fVersion; // some version number.

  ClassDef(I3TankGeo,1);

};

#include "dataclasses/StoragePolicy.h"
typedef PtrPolicy<I3TankGeo>::ThePolicy I3TankGeoPtr;

#endif

