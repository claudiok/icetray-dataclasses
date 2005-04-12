/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3MCCascade.h,v 1.14 2005/04/12 18:55:28 dule Exp $

    @file I3MCCascade.h
    @version $Revision: 1.14 $
    @date $Date: 2005/04/12 18:55:28 $
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
  double weight_;
  
  public:
  /**
   * constructor
   */
  I3MCCascade() {weight_=1;};

  /**
   * destructor
   */
  virtual ~I3MCCascade() {}
  
  /**
   * gives the mc weight that this cascade contributes
   */
  double GetWeight() const { return weight_; }

  /**
   * sets the weight that this cascade will contribute
   */
  void  SetWeight(double weight) { weight_ = weight; }

 private:
  // ROOT macro
  ClassDef(I3MCCascade,1);
};

/**
 * pointer typedeffed away to insulate users from memory management
 */
typedef shared_ptr<I3MCCascade>  I3MCCascadePtr;

#endif
