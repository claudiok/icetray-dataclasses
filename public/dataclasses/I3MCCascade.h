/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3MCCascade.h,v 1.12 2005/04/04 15:49:25 pretz Exp $

    @file I3MCCascade.h
    @version $Revision: 1.12 $
    @date $Date: 2005/04/04 15:49:25 $
    @author deyoung
*/

#include "I3CascadeImpl.h"
#include "I3Directional.h"
#include "I3Localized.h"
#include "I3Energetic.h"
#include "I3Composite.h"

#ifndef I3MCCASCADE_H
#define I3MCCASCADE_H

#include "dataclasses/I3Cascade.h"

/**
 * @brief A cascade with full MC information.
 */
class I3MCCascade : public I3CascadeImpl<I3Directional,
                                         I3Localized,
                                         I3Energetic,
                                         I3Composite>
{
  double     fWeight;
  
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
  double GetWeight() const { return fWeight; }

  /**
   * sets the weight that this cascade will contribute
   */
  void  SetWeight(double weight_) { fWeight = weight_; }

 private:
  // ROOT macro
  ClassDef(I3MCCascade,1);
};

/**
 * pointer typedeffed away to insulate users from memory management
 */
typedef PtrPolicy<I3MCCascade>::ThePolicy I3MCCascadePtr;

#endif
