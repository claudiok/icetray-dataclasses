/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3MCCascade.h,v 1.4 2004/04/23 20:30:06 ehrlich Exp $

    @file I3MCCascade.h
    @version $Revision: 1.4 $
    @date $Date: 2004/04/23 20:30:06 $
    @author deyoung

    @todo
*/

#include "I3CascadeImpl.h"
#include "I3Directional.h"
#include "I3Localized.h"
#include "I3Energetic.h"

#ifndef I3MCCASCADE_H
#define I3MCCASCADE_H

#include "dataclasses/I3Cascade.h"

/**
 * A cascade with full MC information.
 */
class I3MCCascade : public I3CascadeImpl<I3Directional,
                                         I3Localized,
                                         I3Energetic>
{
  Double_t     fWeight;
  
  public:
  I3MCCascade() {fWeight=1;};
  virtual ~I3MCCascade() {}
  
  Double_t Weight() const { return fWeight; }
  void  Weight(Double_t weight_) { fWeight = weight_; }

  ClassDef(I3MCCascade,1);
};

#endif
