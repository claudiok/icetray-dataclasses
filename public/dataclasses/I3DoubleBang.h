/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3DoubleBang.h,v 1.6 2004/08/01 00:41:01 pretz Exp $

    @file I3DoubleBang.h
    @version $Revision: 1.6 $
    @date $Date: 2004/08/01 00:41:01 $
    @author deyoung
*/

#include "I3TrackImpl.h"
#include "I3Contained.h"
#include "I3Composite.h"
#include "I3Energetic.h"

#ifndef I3DOUBLEBANG_H
#define I3DOUBLEBANG_H

#include "dataclasses/I3Track.h"

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
  /**
   * constructor
   */
  I3DoubleBang(){};

  /**
   * destructor
   */
  virtual ~I3DoubleBang(){}

 private:
  // ROOT macro
  ClassDef(I3DoubleBang,1);
};

#endif
