#ifndef I3MCPRIMARY_H
#define I3MCPRIMARY_H

#include "dataclasses/I3MCTrack.h"
#include "dataclasses/StoragePolicy.h"

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCPrimary.h,v 1.1.2.1 2004/04/07 16:59:31 troy Exp $
 *
 * @version $Revision: 1.1.2.1 $
 * @date $Date: 2004/04/07 16:59:31 $
 * @author pretz
 *
 * @todo copy and assignment private??
 *
 */
class I3MCPrimary : public I3MCTrack {

  Double_t fSpectrumWeight;

 public:
  /**
   * constructor.  Defaults the weight to 1.0
   */
  I3MCPrimary(): fSpectrumWeight(1.0){}

  /**
   * destructor
   */
  virtual ~I3MCPrimary(){}

  /**
   * Gives the contribution to this event's weight as given by the spectrum 
   * from which the Primary was drawn
   * @return the weight from the primary, due to the spectrum sampling
   */
  Double_t SpectrumWeight() const {return fSpectrumWeight;}

  /**
   * @param weight the new spectrum weight
   */
  void SpectrumWeight(Double_t weight){fSpectrumWeight = weight;}
 private:
  /*   I3MCPrimary(const I3MCPrimary&); */
  /*   const I3MCPrimary& operator=(const I3MCPrimary&); */

// ROOT macro
  ClassDef(I3MCPrimary,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3MCPrimary>::ThePolicy I3MCPrimaryPtr;

#endif
