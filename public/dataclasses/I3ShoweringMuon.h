/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3ShoweringMuon.h,v 1.6 2004/08/12 17:33:33 pretz Exp $

    @file I3ShoweringMuon.h
    @version $Revision: 1.6 $
    @date $Date: 2004/08/12 17:33:33 $
    @author deyoung
*/

#include "I3TrackImpl.h"
#include "I3Infinite.h"
#include "I3NonEnergetic.h"
#include "I3Composite.h"

#ifndef I3SHOWERINGMUON_H
#define I3SHOWERINGMUON_H

#include "dataclasses/I3Track.h"

/**
 * @brief For infinite muons with showers along their track.
 */
class I3ShoweringMuon : public I3TrackImpl<I3Infinite,
                                           I3NonEnergetic,
                                           I3Composite>
{
 public:
  /**
   * constructor
   */
  I3ShoweringMuon(){};

  /**
   * destructor
   */
  virtual ~I3ShoweringMuon(){}

 private:
  // ROOT macro
  ClassDef(I3ShoweringMuon,1);
};

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3ShoweringMuon>::ThePolicy I3ShoweringMuonPtr;

#endif
