/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCTrack.h,v 1.5.2.2 2004/04/16 17:10:56 pretz Exp $
 *
 * @version $Revision: 1.5.2.2 $
 * @date $Date: 2004/04/16 17:10:56 $
 * @author
 *
 * @todo
 *
 */

#ifndef I3MCTRACK_H
#define I3MCTRACK_H

#include <TObject.h>
#include "dataclasses/I3BasicTrack.h"

class I3MCTrack : public I3BasicTrack
{
  Double_t     fWeight;

 public:
  
  I3MCTrack() { fWeight=1; }

  Double_t Weight() const { return fWeight; }
  void  Weight(Double_t weight_) { fWeight = weight_; }

  ClassDef(I3MCTrack, 1);
};
#endif

