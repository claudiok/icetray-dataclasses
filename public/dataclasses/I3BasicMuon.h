/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3BasicMuon.h,v 1.3 2004/04/27 02:32:05 pretz Exp $

    @file I3BasicMuon.h
    @version $Revision: 1.3 $
    @date $Date: 2004/04/27 02:32:05 $
    @author deyoung

*/

#include "I3TrackImpl.h"
#include "I3Infinite.h"
#include "I3NonEnergetic.h"
#include "I3NonComposite.h"

#ifndef I3BASICMUON_H
#define I3BASICMUON_H

#include "dataclasses/I3Track.h"
/**
 * @brief BasicMuon is intended for plain vanilla muon reconstruction
 * results -- infinite tracks, no energy information, etc.
 */
class I3BasicMuon : public I3TrackImpl<I3Infinite,
                                       I3NonEnergetic,
	                               I3NonComposite>
{
 public:
  /**
   * constructor
   */
  I3BasicMuon(){};

  /**
   * destructor
   */
  virtual ~I3BasicMuon(){}

 private:
  // ROOT macro
  ClassDef(I3BasicMuon,1);
};

#endif
