/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3MCCascade.h,v 1.7 2004/05/05 20:48:24 pretz Exp $

    @file I3MCCascade.h
    @version $Revision: 1.7 $
    @date $Date: 2004/05/05 20:48:24 $
    @author deyoung
*/

#include "I3CascadeImpl.h"
#include "I3Directional.h"
#include "I3Localized.h"
#include "I3Energetic.h"

#ifndef I3MCCASCADE_H
#define I3MCCASCADE_H

#include "dataclasses/I3Cascade.h"

/**
 * @brief A cascade with full MC information.
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

typedef PtrPolicy<I3MCCascade>::ThePolicy I3MCCascadePtr;

#endif
