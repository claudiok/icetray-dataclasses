/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3ShoweringMuon.h,v 1.5 2004/08/02 22:12:28 pretz Exp $

    @file I3ShoweringMuon.h
    @version $Revision: 1.5 $
    @date $Date: 2004/08/02 22:12:28 $
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

#endif
