#ifndef I3MCTRACK_H
#define I3MCTRACK_H

#include <TObject.h>
#include "dataclasses/I3Track.h"
/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCTrack.h,v 1.5 2004/03/14 15:07:12 pretz Exp $
 *
 * @version $Revision: 1.5 $
 * @date $Date: 2004/03/14 15:07:12 $
 * @author
 *
 * @todo
 *
 */
class I3MCTrack : public I3Track
{
  Double_t     fWeight;

  public:
  I3MCTrack() { fWeight=1; }

  Double_t Weight() const { return fWeight; }
  void  Weight(Double_t weight_) { fWeight = weight_; }

  ClassDef(I3MCTrack, 1);
};
#endif

