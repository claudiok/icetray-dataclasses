/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3StartingMuon.h,v 1.6.4.1 2005/02/04 21:49:05 troy Exp $

    @file I3StartingMuon.h
    @version $Revision: 1.6.4.1 $
    @date $Date: 2005/02/04 21:49:05 $
    @author deyoung
*/

#include "I3TrackImpl.h"
#include "I3Starting.h"
#include "I3NonEnergetic.h"
#include "I3Composite.h"

#ifndef I3STARTINGMUON_H
#define I3STARTINGMUON_H

#include "dataclasses/I3Track.h"

/**
 * @brief StartingMuon is to hold tracks which start inside the detector.
 *
 * It is composite so that the hadronic vertex can be added.
 */
class I3StartingMuon : public I3TrackImpl<I3Starting,
                                          I3NonEnergetic,
                                          I3Composite>
{
 public:
  /**
   * constructor
   */
  I3StartingMuon(){};

  /**
   * destructor
   */
  virtual ~I3StartingMuon(){}

 private:
  //ROOT macro

};

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3StartingMuon>::ThePolicy I3StartingMuonPtr;

#endif
