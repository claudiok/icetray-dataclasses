/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3BasicTrack.h,v 1.4 2004/04/27 02:32:05 pretz Exp $

    @file I3BasicTrack.h
    @version $Revision: 1.4 $
    @date $Date: 2004/04/27 02:32:05 $
    @author deyoung
*/

#include "I3TrackImpl.h"
#include "I3Starting.h"
#include "I3Energetic.h"
#include "I3NonComposite.h"

#ifndef I3BASICTRACK_H
#define I3BASICTRACK_H

#include "dataclasses/I3Track.h"

/**
 * @brief BasicTrack defines all the most common track member
 * variable.  
 * @todo Is this class needed anymore?
 */
class I3BasicTrack : public I3TrackImpl<I3Starting,
	                              I3Energetic,
                                      I3NonComposite>
{
 public:
  /**
   * constructor
   */
  I3BasicTrack(){};
  
  /**
   * destructor
   */
  virtual ~I3BasicTrack(){}
 private:
  // ROOT macro
  ClassDef(I3BasicTrack,1);
};

#endif
