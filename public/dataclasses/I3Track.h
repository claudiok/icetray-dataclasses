/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3Track.h,v 1.10.2.9 2004/04/16 18:35:02 pretz Exp $

    @version $Revision: 1.10.2.9 $
    @date $Date: 2004/04/16 18:35:02 $
    @author

    @todo

*/

#ifndef I3TRACK_H
#define I3TRACK_H

#include <TObject.h>
#include "dataclasses/I3Particle.h"
#include <vector>
#include <cmath>

#include <iostream>

class I3Track : public I3Particle
{
 public:
  I3Track() {};

  virtual ~I3Track() {};

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
   * indicates that the track has an energy
   */
  virtual bool IsEnergetic() const =0;

  /**
   * indicates that the track is a composite track
   */
  virtual bool IsComposite() const =0;

  // starting 4-position
  virtual double StartX() const =0;
  virtual double StartY() const =0;
  virtual double StartZ() const =0;
  virtual double StartT() const =0;

  // stopping 4-position
  virtual double StopX() const =0;
  virtual double StopY() const =0;
  virtual double StopZ() const =0;
  virtual double StopT() const =0;

  // Some X position
  virtual double X() const =0;
  virtual double Y() const =0;
  virtual double Z() const =0;
  virtual double T() const =0;

  // energy
  virtual double Energy() const =0;

  // speed 
  virtual double Speed() const =0;

  // length
  virtual double Length() const =0;

  // composite particle stuff
  virtual int NumConstituents() const =0;
  virtual const I3Particle& Constituent(int i) const =0;

  //FIXME:  need fns like distancefromtrack, isontrack, etc.

  //I3Track& operator=(const I3Track&);
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
bool 
operator== (const I3Track& lhs, const I3Track& rhs);

// FIXME (rather, caution.) The "(NAN==NAN)==true" thing bothers me.
inline 
bool 
operator!= (const I3Track& lhs, const I3Track& rhs) 
{
  return !(lhs==rhs);
}

#endif
