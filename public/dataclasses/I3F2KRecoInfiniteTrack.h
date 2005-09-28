/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3F2KRecoTrack.h 7676 2005-05-17 03:27:08Z olivas $

    @file I3F2KRecoTrack.h
    @version $Revision: 1.5 $
    @date $Date: 2005-05-16 23:27:08 -0400 (Mon, 16 May 2005) $
    @author deyoung
    @author ehrlichg
*/

#include "I3TrackImpl.h"
#include "I3Infinite.h"
#include "I3NonEnergetic.h"
#include "I3NonComposite.h"

#ifndef I3F2KRECOINFINITETRACK_H
#define I3F2KRECOINFINITETRACK_H

#include "dataclasses/I3Track.h"

/**
 * @brief F2KTrack contains the parameter set corresponding to the F2000
 * track variables.  
 *
 * It is intended primarily for backward compatibility.
 */
class I3F2KRecoInfiniteTrack : public I3TrackImpl<I3Infinite,
                                                  I3NonEnergetic,
                                                  I3NonComposite>
{
 public:
  /**
   * constructor
   */
  I3F2KRecoInfiniteTrack(){};

  /**
   * destructor
   */
  virtual ~I3F2KRecoInfiniteTrack(){}

 private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
//ROOT macro
  ClassDef(I3F2KRecoInfiniteTrack,1);
};

/**
 * pointer typedeffed away to insulate users from memory management
 */
typedef shared_ptr<I3F2KRecoInfiniteTrack>  I3F2KRecoInfiniteTrackPtr;

#endif

