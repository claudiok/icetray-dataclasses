/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3CoreLocalized.h
 * @version $Revision: 1.10 $
 * @date $Date$
 * @author pretz
 */
#ifndef I3CORELOCALIZED_H
#define I3CORELOCALIZED_H

#include "I3Constants.h"
#include "I3Position.h"
#include "I3Particle.h"
/**
 * @brief The core position part of an I3Primary implementation.  
 * 
 * Represents a a primary where the core location is known.
 */
class I3CoreLocalized 
{

  double coreT_;
  I3Position corePos_; //trying to make compatible with I3Position (dule)

 public:

  virtual ~I3CoreLocalized();
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
  const I3Position& GetCorePos() const {return corePos_;}

  /**
   * sets the position of the core
   */
  void SetCorePos(const I3Position& corepos)
    {
      corePos_.SetPosition(corepos);
      corePos_.SetZ(I3Constants::zIceTop); // ensure the position corresponds to IceTop
    }

  /**
   * sets the position of the core by using only X and Y
   */
  void SetCorePos(double corex, double corey) 
    {corePos_.SetPosition(corex,corey,I3Constants::zIceTop);}

  /**
   * gives the time of the core arrival
   */
  double GetCoreT() const {return coreT_;}

  /**
   * sets the time of the core arrival
   */
  void SetCoreT(double coret) {coreT_ = coret;}

  /**
   * copys the data over to the destination particle if a dynamic_cast succeeds
   */
  void CopyTo(I3Particle& destination) const
    {
      I3CoreLocalized* dest = dynamic_cast<I3CoreLocalized*>(&destination);
      if(dest)
	{
	  dest->corePos_ = corePos_;
	  dest->coreT_ = coreT_;
	}
    }

  virtual void ToStream(ostream& o) const
  {
    o<<"Position:\n"<<corePos_
     <<"Time:"<<coreT_<<"\n";
  }


 private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
//ROOT macro
  ClassDef(I3CoreLocalized,1);
};

#endif

