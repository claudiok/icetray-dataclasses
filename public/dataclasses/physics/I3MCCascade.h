/**
    copyright  (C) 2004
    the IceCube collaboration
    @version $Id$
    @file I3MCCascade.h
    @date $Date$
*/

#include "I3CascadeImpl.h"
#include "I3Directional.h"
#include "I3Localized.h"
#include "I3Energetic.h"
#include "I3Composite.h"

#ifndef I3MCCASCADE_H_INCLUDED
#define I3MCCASCADE_H_INCLUDED

#include "dataclasses/physics/I3Cascade.h"

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

  I3MCCascade() {weight_=1;};

  virtual ~I3MCCascade();
  
  /**
   * gives the mc weight that this cascade contributes
   */
  double GetWeight() const { return weight_; }

  /**
   * sets the weight that this cascade will contribute
   */
  void  SetWeight(double weight) { weight_ = weight; }

 private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
// ROOT macro
  //ClassDef(I3MCCascade,1);
};

/**
 * pointer typedeffed away to insulate users from memory management
 */
typedef shared_ptr<I3MCCascade>  I3MCCascadePtr;

#endif //I3MCCASCADE_H_INCLUDED

