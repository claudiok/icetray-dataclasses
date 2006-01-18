/**
    copyright  (C) 2004
    the IceCube collaboration
    @version $Id$
    @file I3MCTopShower.h
    @date $Date$
*/

#include "I3TopShowerImpl.h"
#include "I3Directional.h"
#include "I3CoreLocalized.h"
#include "I3Energetic.h"

#ifndef I3MCTOPSHOWER_H_INCLUDED
#define I3MCTOPSHOWER_H_INCLUDED

#include "dataclasses/physics/I3TopShower.h"

/**
 * @brief For representing IceTop tracks from Monte Carlo, where we have all
 * possible information.
 */
class I3MCTopShower : public I3TopShowerImpl<I3Directional,
	                                 I3CoreLocalized,
                                         I3Energetic>
{
  double     weight_;
  
  public:

  I3MCTopShower() {weight_=1;};

  virtual ~I3MCTopShower();
  
  /**
   * gives the weight of the track
   */
  double GetWeight() const { return weight_; }

  /**
   * sets the weight of the track
   */
  void  SetWeight(double weight_) { weight_ = weight_; }

 private:
  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
//ROOT macro
  //ClassDef(I3MCTopShower,1);
};

/** 
 * pointer type to insulate users from memory management
 */
typedef shared_ptr<I3MCTopShower>  I3MCTopShowerPtr;

#endif //I3MCTOPSHOWER_H_INCLUDED

