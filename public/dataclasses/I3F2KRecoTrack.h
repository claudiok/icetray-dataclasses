/**
    copyright  (C) 2004
    the icecube collaboration
    $Id$

    @file I3F2KRecoTrack.h
    @version $Revision: 1.5 $
    @date $Date$
    @author deyoung
*/

#include "I3TrackImpl.h"
#include "I3Infinite.h"
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
class I3F2KRecoTrack : public I3TrackImpl<I3Infinite,
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

  friend class boost::serialization::access;

  template <class Archive>
    void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3F2KRecoTrack",
		  base_object< I3TrackImpl< I3Infinite,
                                              I3NonEnergetic,
                                              I3NonComposite> >(*this));
  }

  //ROOT macro
  ClassDef(I3F2KRecoTrack,1);
};

BOOST_SHARED_POINTER_EXPORT(I3F2KRecoTrack);

/**
 * pointer typedeffed away to insulate users from memory management
 */
typedef shared_ptr<I3F2KRecoTrack>  I3F2KRecoTrackPtr;

#endif
