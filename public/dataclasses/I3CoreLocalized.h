/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3CoreLocalized.h,v 1.5 2004/06/30 17:20:26 pretz Exp $
 *
 * @file I3CoreLocalized.h
 * @version $Revision: 1.5 $
 * @date $Date: 2004/06/30 17:20:26 $
 * @author pretz
 */
#ifndef I3CORELOCALIZED_H
#define I3CORELOCALIZED_H

/**
 * @brief The core position part of an I3Primary implementation.  
 * 
 * Represents a a primary where the core location is known.
 */
class I3CoreLocalized 
{
  Double_t fCoreX;
  Double_t fCoreY;
  Double_t fCoreT;
 public:
  /**
   * indicates that the core position is known
   */
  Bool_t HasCorePosition() const { return kTRUE;}

  /**
   * gives the x position of the core
   */
  Double_t GetCoreX() const {return fCoreX;}

  /**
   * sets the x position of the core
   */ 
  void SetCoreX(Double_t corex) {fCoreX = corex;}

  /**
   * gives the y position of the core
   */
  Double_t GetCoreY() const {return fCoreY;}

  /**
   * sets the y position of the core
   */
  void SetCoreY(Double_t corey) {fCoreY = corey;}

  /**
   * gives the time of the core arrival
   */
  Double_t GetCoreT() const {return fCoreT;}

  /**
   * sets the time of the core arrival
   */
  void SetCoreT(Double_t coret) {fCoreT = coret;}

  /**
   * copys the data over to the destination particle if a dynamic_cast succeeds
   */
  void CopyTo(I3Particle& destination) const
    {
      I3CoreLocalized* dest = dynamic_cast<I3CoreLocalized*>(&destination);
      if(dest)
	{
	  dest->fCoreX = fCoreX;
	  dest->fCoreY = fCoreY;
	  dest->fCoreT = fCoreT;
	}
    }

 private:
  //ROOT macro
  ClassDef(I3CoreLocalized,1);
};

#endif
