/**
 * copyright (C) 2004
 * the icecube collaboration
 * $Id: I3SPASEModuleGeo.h,v 1.2.2.2 2005/02/04 21:49:05 troy Exp $
 *
 * @file I3SPASEModuleGeo.h
 * @version $Revision: 1.2.2.2 $
 * @date $Date: 2005/02/04 21:49:05 $
 * @author niessen Thu Sep  2 15:44:31 EDT 2004
 */

#ifndef I3SPASEMODULEGEO_H
#define I3SPASEMODULEGEO_H

#include <iostream>

#include "dataclasses/I3InIceGeometry.h"
#include "dataclasses/I3SurfModuleGeo.h"

using namespace std;

/**
 * @brief Class describing a SPASE module (these scintillator tiles)
 *
 * This class describes the SPASE module geometry. Usually, four SPASE
 * module make up one SPASE station.
 * 
 * @todo convert area to lenght dimension (which?) of a hexagon
 */
class I3SPASEModuleGeo : public I3SurfModuleGeo {

 public:

  /**
   * constructor
   */
  I3SPASEModuleGeo () {}

  /**
   * virtual destructor
   */
  virtual ~I3SPASEModuleGeo () {}

  /**
   * Get the area of the tile
   */
  Double_t GetArea () const {
    return fArea;
  }

  /**
   * Set the area of the tile
   */
  void SetArea (Double_t area) {
    fArea = area;
  }

  /**
   * @todo need more implementation here
   */
  virtual void ToStream (ostream &o) const {
    o << " [ I3SPASEModuleGeo ] " << endl;
  }

 private:

  Double_t fArea; // Was told by SZT that size of the module is
		  // measured in area, not in inner/outer radius of
		  // the hexagonal tiles.


};

/**
 * override the put-to operator
 */
inline ostream &operator<< (ostream &o, const I3SPASEModuleGeo spase_module) {
  spase_module.ToStream (o);
  return o;
}

/**
 * a pointer to insulate users from memory management
 */
typedef PtrPolicy<I3SPASEModuleGeo>::ThePolicy I3SPASEModuleGeoPtr;

#endif
