/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3EnergyMuon.h,v 1.5.4.1 2005/02/04 21:49:05 troy Exp $

    @file I3EnergyMuon.h
    @version $Revision: 1.5.4.1 $
    @date $Date: 2005/02/04 21:49:05 $
    @author deyoung
*/

#ifndef I3ENERGYMUON_H
#define I3ENERGYMUON_H

#include "I3Track.h"
#include "I3TrackImpl.h"
#include "I3Infinite.h"
#include "I3NonComposite.h"
#include "I3Energetic.h"

/**
 * @brief Class for infinite muon tracks with a known energy. 
 */
class I3EnergyMuon : public I3TrackImpl<I3Infinite,
                                        I3Energetic,
                                        I3NonComposite>
{
 public:
  /**
   * constructor
   */
  I3EnergyMuon(){};

  /**
   * destructor
   */
  virtual ~I3EnergyMuon(){}
};

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3EnergyMuon>::ThePolicy I3EnergyMuonPtr;

#endif
