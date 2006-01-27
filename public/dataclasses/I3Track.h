/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3Track.h
 * @version $Revision: 1.32 $
 * @date $Date$
 * @author pretz
 */


#ifndef I3TRACK_H
#define I3TRACK_H

#include <TObject.h>
#include "dataclasses/I3InIceParticle.h"
#include "dataclasses/I3Position.h"
#include "dataclasses/I3Direction.h"
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
class I3Track : public I3InIceParticle
{
 public:
  /**
   * constructor
   */
  I3Track() {};

  /**
   * destructor
   */
  virtual ~I3Track();

  /**
   * indicates that this track is not a cascade
   */
  virtual bool IsCascade() {return false;}

  /**
   * indicates that this track is a track.
   */
  virtual bool IsTrack() {return true;}

  /**
   * indicates that the 'StartX() ... ' parameters are valid
   */
  virtual bool IsStarting() const =0;

  /**
   * indicates that the 'StopX() ...' parameters are valid
   */
  virtual bool IsStopping() const  =0;

  /**
   * indicates that the particle is infinite
   */
  virtual bool IsInfinite() const =0;

  /**
   * indicates that the particle is starting and stopping
   */
  virtual bool IsContained() const  =0;

  /**
   * returns the direction of the track
   */
  virtual const I3Direction& GetDir() const =0;

  /**
   * returns the zenith of the track
   */
  virtual double GetZenith() const =0;

  /**
   * returns the azimuth of the track
   */
  virtual double GetAzimuth() const = 0;

  /**
   * indicates that the track has an energy
   */
  virtual bool HasEnergy() const =0;

  /**
   * indicates that the track is a composite track
   */
  virtual bool IsComposite() const =0;

  /**
   * the time the track was at X(), Y() and Z()
   */
  virtual double GetT() const =0;

  /**
   * the Position of the track at time T()
   */
  virtual const I3Position& GetPos() const =0;
  
  // speed 
  /**
   * the speed of the particle
   */
  virtual double GetSpeed() const =0;

  // length
  /**
   * the length of the particle
   */
  virtual double GetLength() const =0;

  /**
   * @todo implement 'PrintTrack()' as operator<<
   * Print all information about the I3track
   */
  //  void PrintTrack();

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
  virtual void ToStream (std::ostream &s) const {I3Particle::ToStream(s);}
 protected:

  ClassDef(I3Track, 1);

 private:
  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3InIceParticle", base_object<I3InIceParticle>(*this));
  }
};

BOOST_IS_ABSTRACT(I3Track);

/**
 * pointer type to insulate users from memory management
 */
typedef shared_ptr<I3Track>  I3TrackPtr;

#endif
