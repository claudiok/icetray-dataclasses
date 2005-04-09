/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3MCTopShower.h,v 1.3 2005/04/09 03:02:10 olivas Exp $

    @file I3MCTopShower.h
    @version $Revision: 1.3 $
    @date $Date: 2005/04/09 03:02:10 $
    @author blaufuss
*/

#include "I3TopShowerImpl.h"
#include "I3Directional.h"
#include "I3CoreLocalized.h"
#include "I3Energetic.h"

#ifndef I3MCTOPSHOWER_H
#define I3MCTOPSHOWER_H

#include "dataclasses/I3TopShower.h"

/**
 * @brief For representing IceTop tracks from Monte Carlo, where we have all
 * possible information.
 */
class I3MCTopShower : public I3TopShowerImpl<I3Directional,
	                                 I3CoreLocalized,
                                         I3Energetic>
{
  double     fWeight;
  
  public:
  /**
   * constructor
   */
  I3MCTopShower() {fWeight=1;};

  /**
   * destructor
   */
  virtual ~I3MCTopShower(){}
  
  /**
   * gives the weight of the track
   */
  double GetWeight() const { return fWeight; }

  /**
   * sets the weight of the track
   */
  void  SetWeight(double weight_) { fWeight = weight_; }

 private:
  //ROOT macro
  ClassDef(I3MCTopShower,1);
};

/** 
 * pointer type to insulate users from memory management
 */
typedef shared_ptr<I3MCTopShower>  I3MCTopShowerPtr;

#endif
