#/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCPhoton.h,v 1.1 2004/07/19 15:33:42 pretz Exp $
 *
 * @file I3MCPhoton.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/07/19 15:33:42 $
 * @author pretz
 */
#ifndef I3MCPHOTON_H
#define I3MCPHOTON_H

#include "TObject.h"

/**
 * @brief A class that indicates the arrival of a photon at a particular OM.
 *
 * @todo Perhaps should have stuff like 'Arrival Angle' and 'Wavelength'
 */
class I3MCPhoton : public TObject
{
  Double_t fTime;
 public:
  /**
   * default constructor
   */

  I3MCPhoton(){}

  /**
   * default destructor
   */
  virtual ~I3MCPhoton(){}

  /**
   * Gets the photon arrival time at a PMT
   * @return the photon arrival time
   */
  Double_t GetTime() { return fTime;}

  /**
   * Sets the photon arrival time at the PMT
   * @param time the new arrival time
   */
  void SetTime(Double_t time) { fTime = time;}
 private:
  //ROOT macro
  ClassDef(I3MCPhoton,1);
};

#include "dataclasses/StoragePolicy.h"
typedef PtrPolicy<I3MCPhoton>::ThePolicy I3MCPhotonPtr;

#endif //I3MCPHOTON_H
