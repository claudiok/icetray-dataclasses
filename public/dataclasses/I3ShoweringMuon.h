/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3ShoweringMuon.h,v 1.3 2004/04/22 16:55:52 pretz Exp $

    @version $Revision: 1.3 $
    @date $Date: 2004/04/22 16:55:52 $
    @author deyoung

    @todo
*/

#include "I3TrackImpl.h"
#include "I3Infinite.h"
#include "I3NonEnergetic.h"
#include "I3Composite.h"

#ifndef I3SHOWERINGMUON_H
#define I3SHOWERINGMUON_H

#include "dataclasses/I3Track.h"

/**
 * For infinite muons with showers along their track.
 */
class I3ShoweringMuon : public I3TrackImpl<I3Infinite,
                                           I3NonEnergetic,
                                           I3Composite>
{
 public:
  I3ShoweringMuon(){};
  virtual ~I3ShoweringMuon(){}
  ClassDef(I3ShoweringMuon,1);
};

#endif
