/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Localized.h,v 1.9 2005/04/04 15:49:25 pretz Exp $
 *
 * @file I3Localized.h
 * @version $Revision: 1.9 $
 * @date $Date: 2005/04/04 15:49:25 $
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
  double fT;
  I3Position fPos;
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
  I3Position GetPos() const {return fPos;}

  /**
   * sets the position of the cascade 
   */
  void SetPos(I3Position p) {fPos.SetPosition(p);}

  /**
   * sets the position of the cascade 
   */
  void SetPos(double p1, double p2, double p3, 
	      I3Position::RefFrame frame=I3Position::car)
    {fPos.SetPosition(p1,p2,p3,frame);}

  /**
   * gets the time of the cascade
   */
  double GetT() const{return fT;}

  /**
   * sets the time of the cascade
   */
  void SetT(double t){fT = t;}

  /**
   * copies all of this cascade's data into 'destination' if a dynamic_cast
   * to I3Localized succeeds.
   */
  void CopyTo(I3Particle& destination) const
    {
      I3Localized *localized = dynamic_cast<I3Localized*>(&destination);
      if(localized)
	{
	  localized->fPos = fPos;
	  localized->fT = fT;
	}
    }

  virtual void ToStream(ostream& o) const
    {
      o<<"Position:\n"<<fPos
       <<"Time:"<<fT<<"\n";
    }
 private:
  //ROOT macro
  ClassDef(I3Localized,1);
};

#endif //I3LOCALIZED_H
