/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Track.h,v 1.20 2004/07/06 15:35:52 pretz Exp $
 *
 * @file I3Track.h
 * @version $Revision: 1.20 $
 * @date $Date: 2004/07/06 15:35:52 $
 * @author pretz
 */


#ifndef I3TRACK_H
#define I3TRACK_H

#include <TObject.h>
#include "dataclasses/I3ObservableParticle.h"
#include "dataclasses/I3Position.h"
#include "dataclasses/StoragePolicy.h"
#include "dataclasses/I3Units.h"
#include <vector>
#include <cmath>

#include <iostream>

/**
 * @brief The basic track class for IceCube. 
 *
 * Not all of the methods will work 
 * for any particular track, and so methods are provided to tell which
 * will work and which won't.
 * @todo implement the geometrical convenience functions
 */
class I3Track : public I3ObservableParticle
{
 public:
  /**
   * constructor
   */
  I3Track() {};

  /**
   * destructor
   */
  virtual ~I3Track() {};

  /**
   * indicates that this track is not a cascade
   */
  virtual Bool_t IsCascade() {return kFALSE;}

  /**
   * indicates that this track is a track.
   */
  virtual Bool_t IsTrack() {return kTRUE;}

  /**
   * indicates that the 'StartX() ... ' parameters are valid
   */
  virtual Bool_t IsStarting() const =0;

  /**
   * indicates that the 'StopX() ...' parameters are valid
   */
  virtual Bool_t IsStopping() const  =0;

  /**
   * indicates that the particle is infinite
   */
  virtual Bool_t IsInfinite() const =0;

  /**
   * indicates that the particle is starting and stopping
   */
  virtual Bool_t IsContained() const  =0;

  /**
   * indicates that the track has an energy
   */
  virtual Bool_t HasEnergy() const =0;

  /**
   * indicates that the track is a composite track
   */
  virtual Bool_t IsComposite() const =0;

  // starting 4-position
  /**
   * starting x position
   */
  virtual Double_t GetStartX() const =0;

  /**
   * starting y position
   */
  virtual Double_t GetStartY() const =0;

  /**
   * starting z position
   */
  virtual Double_t GetStartZ() const =0;

  /**
   * starting time
   */
  virtual Double_t GetStartT() const =0;

  /**
   * the starting position as an I3Position
   */
  virtual I3Position GetStartPos() const =0;
  
  // stopping 4-position
  /**
   * the stopping x position
   */
  virtual Double_t GetStopX() const =0;

  /**
   * the stopping y position
   */
  virtual Double_t GetStopY() const =0;

  /**
   * the stopping z position
   */
  virtual Double_t GetStopZ() const =0;

  /**
   * the stopping time
   */
  virtual Double_t GetStopT() const =0;


  /**
   * the stopping position as an I3Position
   */
  virtual I3Position GetStopPos() const =0;

  // Some 4 position on the track
  /**
   * some X position along the track, corresponding to Y(),Z(), and T()
   */
  virtual Double_t GetX() const =0;

  /**
   * some Y position along the track corresponding to X(), Z() and T()
   */
  virtual Double_t GetY() const =0;

  /**
   * some Z position along the track corresponding to X(), Y() and T()
   */
  virtual Double_t GetZ() const =0;

  /**
   * the time the track was at X(), Y() and Z()
   */
  virtual Double_t GetT() const =0;

  /**
   * the Position of the track at time T()
   */
  virtual I3Position GetPos() const =0;
  
  // energy
  /**
   * The energy of the particle
   */
  virtual Double_t GetEnergy() const =0;

  // speed 
  /**
   * the speed of the particle
   */
  virtual Double_t GetSpeed() const =0;

  // length
  /**
   * the length of the particle
   */
  virtual Double_t GetLength() const =0;

  // composite particle stuff
  /**
   * retrieves the constituent particles
   */
  virtual const vector<I3ParticlePtr>& GetConstituents() const = 0;

  /**
   * Print all information about the I3track
   */
  void PrintTrack();

 /**
  * copies over data from this particle to the destination particle
  * Only copies that data which the two have in common
  */
  virtual void CopyTo(I3Particle& destination) const 
    {
      I3Particle::CopyTo(destination);
    }

  /**
   * Copies over data from the source particle to this particle.
   * Only copies that data which the two have in common.
   */
  virtual void CopyFrom(const I3Particle& source)
    {
      source.CopyTo(*this);
    }

  /**
   * streams the track to an ostream.  Can be used, for instance, to dump
   * to stdout.  
   * @todo take Troy's implementation of this from the archive
   */
  virtual void ToStream (std::ostream &s) const {s<<"A Track\n";}
 protected:

  ClassDef(I3Track, 1);
};

inline 
std::ostream& 
operator<< (std::ostream& s, const I3Track& t) 
{
  // this is done through a reference, virtual call dispatch occurs.
  // need only this function to cover all subtypes of I3Track that define
  // the function  "void ToStream(std::ostream &) const"
  t.ToStream(s);
  return s;
}
  
// inside here the member variables are compared one-by-one.  Each one
// involves a virtual call dispatch.
/**
 * @todo fix implementation of this method
 */
bool 
operator== (const I3Track& lhs, const I3Track& rhs);

// FIXME (rather, caution.) The "(NAN==NAN)==true" thing bothers me.
inline 
bool 
operator!= (const I3Track& lhs, const I3Track& rhs) 
{
  return !(lhs==rhs);
}



typedef PtrPolicy<I3Track>::ThePolicy I3TrackPtr;

#endif
