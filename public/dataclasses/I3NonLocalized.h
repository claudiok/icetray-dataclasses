/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3NonLocalized.h,v 1.1.2.1 2005/02/04 06:11:43 troy Exp $
 *
 * @file I3NonLocalized.h
 * @version $Revision: 1.1.2.1 $
 * @date $Date: 2005/02/04 06:11:43 $
 * @author ehrlich
 * @author Peter Niessen
 */
#ifndef I3NONLOCALIZED_H
#define I3NONLOCALIZED_H


/**
 * @brief The core position part of an I3Primary implementation.  
 * 
 * Represents a a primary where the core location is unknown.
 */
class I3NonLocalized 
{
 public:
  /**
   * indicates that the core position isn't known
   */
  Bool_t IsCoreLocalized() const { return false;}

  /**
   * indicates that the inice position isn't known
   */
  Bool_t IsLocalized() const { return false;}

  /**
   * nothing to copy. does nothing.
   */
  void CopyTo(I3Particle& destination) const {}

 private:
  //ROOT macro
  ClassDef(I3NonLocalized,1);
};

#endif
