/**
    copyright  (C) 2004
    the icecube collaboration
    $Id$

    @file I3BasicTrack.h
    @version $Revision: 1.8 $
    @date $Date$
    @author deyoung
*/

#include "I3TrackImpl.h"
#include "I3Infinite.h"
#include "I3NonEnergetic.h"
#include "I3NonComposite.h"

#ifndef I3BASICTRACK_H
#define I3BASICTRACK_H

#include "dataclasses/I3Track.h"

/**
 * @brief BasicTrack is for vanilla track (i.e. not cascade)
 * particles.  No starting, stopping points, no energy, etc.
  */
class I3BasicTrack : public I3TrackImpl<I3Infinite,
	                              I3NonEnergetic,
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
  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3TrackImpl<I3Infinite,I3NonEnergetic,I3NonComposite>", 
		  base_object< I3TrackImpl<I3Infinite,I3NonEnergetic,I3NonComposite> >(*this));
  }
  // ROOT macro
  ClassDef(I3BasicTrack,1);
};

BOOST_SHARED_POINTER_EXPORT(I3BasicTrack);

/**
 * pointer typedeffed away to insulate users from memory management
 */
typedef shared_ptr<I3BasicTrack>  I3BasicTrackPtr;
#endif
