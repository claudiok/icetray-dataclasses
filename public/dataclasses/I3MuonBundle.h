/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3MuonBundle.h,v 1.1.2.2 2004/04/20 16:51:16 pretz Exp $

    @version $Revision: 1.1.2.2 $
    @date $Date: 2004/04/20 16:51:16 $
    @author deyoung

    @todo

    Class for representing a bundle of parallel muons from a cosmic
    ray air shower.  The class is composite, with the individual muons
    as constituent particles.  Variables at the top level refer to the
    bundle as a whole: total energy, direction of the bundle axis, etc.

*/

#include "I3TrackImpl.h"
#include "I3Stopping.h"
#include "I3Composite.h"
#include "I3Energetic.h"

#ifndef I3MUONBUNDLE_H
#define I3MUONBUNDLE_H

#include "dataclasses/I3Track.h"

class I3MuonBundle : public I3TrackImpl<I3Stopping,
                                        I3Energetic,
                                        I3Composite>
{
 public:
  I3MuonBundle(){};
  virtual ~I3MuonBundle(){}
  ClassDef(I3MuonBundle,1);
};

#endif
