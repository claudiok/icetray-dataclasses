/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3MCCascade.h,v 1.10.4.1 2005/02/04 21:49:05 troy Exp $

    @file I3MCCascade.h
    @version $Revision: 1.10.4.1 $
    @date $Date: 2005/02/04 21:49:05 $
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
  Double_t GetWeight() const { return fWeight; }

  /**
   * sets the weight that this cascade will contribute
   */
  void  SetWeight(Double_t weight_) { fWeight = weight_; }

};

/**
 * pointer typedeffed away to insulate users from memory management
 */
typedef PtrPolicy<I3MCCascade>::ThePolicy I3MCCascadePtr;

#endif
