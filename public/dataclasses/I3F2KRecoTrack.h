/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3F2KRecoTrack.h,v 1.3 2004/07/19 16:46:01 pretz Exp $

    @file I3F2KRecoTrack.h
    @version $Revision: 1.3 $
    @date $Date: 2004/07/19 16:46:01 $
    @author deyoung
*/

#include "I3TrackImpl.h"
#include "I3Contained.h"
#include "I3NonEnergetic.h"
#include "I3NonComposite.h"

#ifndef I3F2KRECOTRACK_H
#define I3F2KRECOTRACK_H

#include "dataclasses/I3Track.h"

/**
 * @brief F2KTrack contains the parameter set corresponding to the F2000
 * track variables.  
 *
 * It is intended primarily for backward compatibility.
 */
class I3F2KRecoTrack : public I3TrackImpl<I3Contained,
                                          I3NonEnergetic,
                                          I3NonComposite>
{
 public:
  /**
   * constructor
   */
  I3F2KRecoTrack(){};

  /**
   * destructor
   */
  virtual ~I3F2KRecoTrack(){}

 private:
  //ROOT macro
  ClassDef(I3F2KRecoTrack,1);
};

/**
 * pointer typedeffed away to insulate users from memory management
 */
typedef PtrPolicy<I3F2KRecoTrack>::ThePolicy I3F2KRecoTrackPtr;

#endif
