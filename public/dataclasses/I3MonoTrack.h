/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MonoTrack.h,v 1.6 2005/04/04 15:49:25 pretz Exp $

    @file I3MonoTrack.h
    @version $Revision: 1.6 $
    @date $Date: 2005/04/04 15:49:25 $
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

  double fSpeed;

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
  virtual double GetSpeed() const { return fSpeed; }

  /**
   * sets the speed of the particle
   */
  virtual void SetSpeed(double arg) { fSpeed = arg; }

 private:
  // ROOT macro
  ClassDef(I3MonoTrack, 1);
};

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3MonoTrack>::ThePolicy I3MonoTrackPtr;

#endif
