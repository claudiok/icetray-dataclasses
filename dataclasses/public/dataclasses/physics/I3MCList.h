/**
    copyright  (C) 2004
    the icecube collaboration
    @version $Id: I3Track.h 15192 2006-02-02 01:02:05Z dule $
    @file dataclasses/public/dataclasses/physics/I3MCList.h
    @date $Date: 2006-02-01 20:02:05 -0500 (Wed, 01 Feb 2006) $
*/

#ifndef I3MCLLIST_H_INCLUDED
#define I3MCLLIST_H_INCLUDED

#include "dataclasses/physics/I3Particle.h"
#include "dataclasses/I3Vector.h"

/**
 * @brief Track is for vanilla track (i.e. not cascade)
  */
static const unsigned i3mclist_version_ = 0;

class I3MCList : public I3Vector<I3Particle>
{
 public:

  I3MCList()
    {};
  
  I3MCList(I3Vector<I3Particle>::iterator l,I3Vector<I3Particle>::iterator r) : I3Vector<I3Particle>(l, r) { }

  virtual ~I3MCList();

 private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

BOOST_CLASS_VERSION(I3MCList, i3mclist_version_);
I3_POINTER_TYPEDEFS(I3MCList);

#endif 


