/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TWRLaunch.h,v 1.1 2004/07/30 15:11:00 blaufuss Exp $
 *
 * @file I3TWRLaunch.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/07/30 15:11:00 $
 * @author pretz
 * @author blaufuss
 *
 */
#ifndef I3TWRLAUNCH_H
#define I3TWRLAUNCH_H

#include "dataclasses/I3DigitalLaunch.h"
/**
 * @brief Implementation of the AMANDA TWR response
 * @todo This class isn't implemented yet.  It's just holding the place
 */
class I3TWRLaunch : public I3DigitalLaunch
{
 public:
  /**
   * constructor ... for when there's something to construct
   */ 
  I3TWRLaunch() {}

  /**
   * destructor
   */
  virtual ~I3TWRLaunch(){}

 private:
  // copy and assignment declared private
  I3TWRLaunch(const I3TWRLaunch&);
  const I3TWRLaunch& operator=(const I3TWRLaunch&);

  //ROOT macro
  ClassDef(I3TWRLaunch,1);
};


/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3TWRLaunch>::ThePolicy I3TWRLaunchPtr;

#endif

