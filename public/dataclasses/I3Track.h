/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3Track.h,v 1.10.2.13 2004/04/20 16:51:16 pretz Exp $

    @version $Revision: 1.10.2.13 $
    @date $Date: 2004/04/20 16:51:16 $
    @author

    @todo

*/

#ifndef I3TRACK_H
#define I3TRACK_H

#include <TObject.h>
#include "dataclasses/I3Particle.h"
#include "dataclasses/I3Position.h"
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
  virtual Bool_t IsEnergetic() const =0;

  /**
   * indicates that the track is a composite track
   */
  virtual Bool_t IsComposite() const =0;

  // starting 4-position
  virtual Double_t StartX() const =0;
  virtual Double_t StartY() const =0;
  virtual Double_t StartZ() const =0;
  virtual Double_t StartT() const =0;

  virtual I3Position StartPos() const =0;
  
  // stopping 4-position
  virtual Double_t StopX() const =0;
  virtual Double_t StopY() const =0;
  virtual Double_t StopZ() const =0;
  virtual Double_t StopT() const =0;

  virtual I3Position StopPos() const =0;

  // Some X position
  virtual Double_t X() const =0;
  virtual Double_t Y() const =0;
  virtual Double_t Z() const =0;
  virtual Double_t T() const =0;

  virtual I3Position Pos() const =0;
  
  // energy
  virtual Double_t Energy() const =0;

  // speed 
  virtual Double_t Speed() const =0;

  // length
  virtual Double_t Length() const =0;

  // composite particle stuff
  virtual int NumConstituents() const =0;
  virtual const I3Particle& Constituent(int i) const =0;

  virtual void CopyTo(I3Particle& destination) const 
    {
      I3Particle::CopyTo(destination);
    }

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
