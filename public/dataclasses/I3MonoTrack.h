/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MonoTrack.h,v 1.5.4.1 2005/02/04 21:51:03 troy Exp $

    @file I3MonoTrack.h
    @version $Revision: 1.5.4.1 $
    @date $Date: 2005/02/04 21:51:03 $
    @author
*/

#ifndef I3MONOTRACK_H
#define I3MONOTRACK_H

#include "dataclasses/I3BasicTrack.h"

/**
 * @brief A basic monopole track
 */
class I3MonoTrack : public I3BasicTrack
{

  Double_t fSpeed;

 public:
  /**
   * constructor
   */
  I3MonoTrack() {
    fSpeed=NAN;
  };

  /**
   * destructor
   */
  virtual ~I3MonoTrack() {};
    
  /**
   * gets the speed of the particle
   */
  virtual Double_t GetSpeed() const { return fSpeed; }

  /**
   * sets the speed of the particle
   */
  virtual void SetSpeed(Double_t arg) { fSpeed = arg; }

};

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3MonoTrack>::ThePolicy I3MonoTrackPtr;

#endif
