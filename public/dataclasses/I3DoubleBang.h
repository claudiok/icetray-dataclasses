/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3DoubleBang.h,v 1.3 2004/04/22 16:55:52 pretz Exp $

    @file I3DoubleBang.h
    @version $Revision: 1.3 $
    @date $Date: 2004/04/22 16:55:52 $
    @author deyoung

    @todo
*/

#include "I3TrackImpl.h"
#include "I3Contained.h"
#include "I3Composite.h"
#include "I3Energetic.h"

#ifndef I3DOUBLEBANG_H
#define I3DOUBLEBANG_H

#include "dataclasses/I3Track.h"

/**
 * For representing contained tau events, consisting of two showers
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
  virtual ~I3DoubleBang(){}
  ClassDef(I3DoubleBang,1);
};

#endif
