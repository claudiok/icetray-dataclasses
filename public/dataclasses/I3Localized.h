/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Localized.h,v 1.10 2005/04/12 18:55:28 dule Exp $
 *
 * @file I3Localized.h
 * @version $Revision: 1.10 $
 * @date $Date: 2005/04/12 18:55:28 $
 * @author pretz
 *
 */
#ifndef I3LOCALIZED_H
#define I3LOCALIZED_H

#include "I3Cascade.h"

/**
 * @brief A class which satisfies the "Localization" part of an I3Cascade, and 
 * allows X,Y,Z, and T to be set and got.
 */
class I3Localized{
 private:
  double time_;
  I3Position pos_;

 public:

  virtual ~I3Localized() {}
  /**
   * indicates that the core position isn't known
   */
  bool IsCoreLocalized() const { return false;}

  /**
   * indicates that this class has a localization
   */
  bool IsLocalized() const { return true;}

  /**
   * gets the position of the cascade
   */
  I3Position GetPos() const {return pos_;}

  /**
   * sets the position of the cascade 
   */
  void SetPos(I3Position p) {pos_.SetPosition(p);}

  /**
   * sets the position of the cascade 
   */
  void SetPos(double p1, double p2, double p3, 
	      I3Position::RefFrame frame=I3Position::car)
    {pos_.SetPosition(p1,p2,p3,frame);}

  /**
   * gets the time of the cascade
   */
  double GetT() const{return time_;}

  /**
   * sets the time of the cascade
   */
  void SetT(double t){time_ = t;}

  /**
   * copies all of this cascade's data into 'destination' if a dynamic_cast
   * to I3Localized succeeds.
   */
  void CopyTo(I3Particle& destination) const
    {
      I3Localized *localized = dynamic_cast<I3Localized*>(&destination);
      if(localized)
	{
	  localized->pos_ = pos_;
	  localized->time_ = time_;
	}
    }

  virtual void ToStream(ostream& o) const
    {
      o<<"Position:\n"<<pos_
       <<"Time:"<<time_<<"\n";
    }
 private:
  //ROOT macro
  ClassDef(I3Localized,1);
};

#endif //I3LOCALIZED_H
