/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3NonCoreLocalized.h,v 1.3 2004/07/26 13:53:55 pretz Exp $
 *
 * @file I3NonCoreLocalized.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/07/26 13:53:55 $
 * @author Peter Niessen
 */
#ifndef I3NONCORELOCALIZED_H
#define I3NONCORELOCALIZED_H


/**
 * @brief The core position part of an I3Primary implementation.  
 * 
 * Represents a a primary where the core location is unknown.
 */
class I3NonCoreLocalized 
{
 public:
  /**
   * indicates that the core position is known
   */
  Bool_t HasCorePosition() const { return kFALSE;}

  /**
   * nothing to copy. does nothing.
   */
  void CopyTo(I3Particle& destination) const {}

 private:
  //ROOT macro
  ClassDef(I3NonCoreLocalized,1);
};

#endif
