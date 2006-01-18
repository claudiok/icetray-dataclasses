/**
    copyright  (C) 2004
    the IceCube collaboration
    @version $Id$
    @file I3DoubleBang.h
    @date $Date$
*/

#include "I3TrackImpl.h"
#include "I3Contained.h"
#include "I3Composite.h"
#include "I3Energetic.h"

#ifndef I3DOUBLEBANG_H_INCLUDED
#define I3DOUBLEBANG_H_INCLUDED

#include "dataclasses/physics/I3Track.h"

/**
 * @brief For representing contained tau events,
 *
 * consisting of two showers
 * (neutrino interaction and tau lepton decay), a tau lepton track,
 * and possibly stochastic showers along the lepton track.
 * Information in this object refers to the event as a whole, with
 * information about specific elements (e.g., the hadronic shower)
 * available in the constituent particles.
 */


class I3DoubleBang : public I3TrackImpl<I3Contained,
                                        I3Energetic,
                                        I3Composite>
{
 public:

  I3DoubleBang(){};

  virtual ~I3DoubleBang();

 private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
// ROOT macro
  //ClassDef(I3DoubleBang,1);
};

/**
 * pointer type to insulate users from memory management
 */
typedef shared_ptr<I3DoubleBang>  I3DoubleBangPtr;

#endif //I3DOUBLEBANG_H_INCLUDED

