/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCTrack.h,v 1.6 2004/04/22 15:55:44 pretz Exp $
 *
 * @version $Revision: 1.6 $
 * @date $Date: 2004/04/22 15:55:44 $
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

