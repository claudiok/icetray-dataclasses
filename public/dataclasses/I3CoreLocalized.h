/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3CoreLocalized.h,v 1.9 2005/04/04 15:49:25 pretz Exp $
 *
 * @file I3CoreLocalized.h
 * @version $Revision: 1.9 $
 * @date $Date: 2005/04/04 15:49:25 $
 * @author pretz
 */
#ifndef I3CORELOCALIZED_H
#define I3CORELOCALIZED_H

#include "dataclasses/I3Constants.h"

/**
 * @brief The core position part of an I3Primary implementation.  
 * 
 * Represents a a primary where the core location is known.
 */
class I3CoreLocalized 
{

  double fCoreT;
  I3Position fCorePos; //trying to make compatible with I3Position (dule)

 public:

  virtual ~I3CoreLocalized() {}
  /**
   * indicates that the core position is known
   */
  bool IsCoreLocalized() const { return true;}

  /**
   * indicates that the inice position isn't known
   */
  bool IsLocalized() const { return false;}

  /**
   * gives the position of the core
   */
  I3Position GetCorePos() const {return fCorePos;}

  /**
   * sets the position of the core
   */
  void SetCorePos(I3Position corepos)
    {
      fCorePos.SetPosition(corepos);
      fCorePos.SetZ(I3Constants::zIceTop); // ensure the position corresponds to IceTop
    }

  /**
   * sets the position of the core by using only X and Y
   */
  void SetCorePos(double corex, double corey) 
    {fCorePos.SetPosition(corex,corey,I3Constants::zIceTop);}

  /**
   * gives the time of the core arrival
   */
  double GetCoreT() const {return fCoreT;}

  /**
   * sets the time of the core arrival
   */
  void SetCoreT(double coret) {fCoreT = coret;}

  /**
   * copys the data over to the destination particle if a dynamic_cast succeeds
   */
  void CopyTo(I3Particle& destination) const
    {
      I3CoreLocalized* dest = dynamic_cast<I3CoreLocalized*>(&destination);
      if(dest)
	{
	  dest->fCorePos = fCorePos;
	  dest->fCoreT = fCoreT;
	}
    }

 private:
  //ROOT macro
  ClassDef(I3CoreLocalized,1);
};

#endif
