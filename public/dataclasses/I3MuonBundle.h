/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3MuonBundle.h,v 1.6.4.1 2005/02/04 21:51:03 troy Exp $

    @file I3MuonBundle.h
    @version $Revision: 1.6.4.1 $
    @date $Date: 2005/02/04 21:51:03 $
    @author deyoung
*/

#include "I3TrackImpl.h"
#include "I3Stopping.h"
#include "I3Composite.h"
#include "I3Energetic.h"

#ifndef I3MUONBUNDLE_H
#define I3MUONBUNDLE_H

#include "dataclasses/I3Track.h"

/**
 * @brief Class for representing a bundle of parallel muons from a cosmic
 * ray air shower.  
 * 
 * The class is composite, with the individual muons
 * as constituent particles.  Variables at the top level refer to the
 * bundle as a whole: total energy, direction of the bundle axis, etc.
 */
class I3MuonBundle : public I3TrackImpl<I3Stopping,
                                        I3Energetic,
                                        I3Composite>
{
 public:
  /**
   * constructor
   */
  I3MuonBundle(){};

  /**
   * destructor
   */
  virtual ~I3MuonBundle(){}

};

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3MuonBundle>::ThePolicy I3MuonBundlePtr;

#endif
