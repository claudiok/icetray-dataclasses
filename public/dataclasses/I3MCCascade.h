/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3MCCascade.h,v 1.9 2004/08/01 00:41:01 pretz Exp $

    @file I3MCCascade.h
    @version $Revision: 1.9 $
    @date $Date: 2004/08/01 00:41:01 $
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
  /**
   * constructor
   */
  I3MCCascade() {fWeight=1;};

  /**
   * destructor
   */
  virtual ~I3MCCascade() {}
  
  /**
   * gives the mc weight that this cascade contributes
   */
  Double_t Weight() const { return fWeight; }

  /**
   * sets the weight that this cascade will contribute
   */
  void  Weight(Double_t weight_) { fWeight = weight_; }

 private:
  // ROOT macro
  ClassDef(I3MCCascade,1);
};

/**
 * pointer typedeffed away to insulate users from memory management
 */
typedef PtrPolicy<I3MCCascade>::ThePolicy I3MCCascadePtr;

#endif
