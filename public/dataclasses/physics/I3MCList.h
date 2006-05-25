
/**
    copyright  (C) 2004
    the icecube collaboration
    @version $Id: I3Track.h 15192 2006-02-02 01:02:05Z dule $
    @file I3Track.h
    @date $Date: 2006-02-01 20:02:05 -0500 (Wed, 01 Feb 2006) $
*/

#ifndef I3MCLLIST_H_INCLUDED
#define I3MCLLIST_H_INCLUDED

#include "dataclasses/physics/I3Particle.h"
#include "dataclasses/I3Vector.h"

/**
 * @brief Track is for vanilla track (i.e. not cascade)
  */
class I3MCList : public I3Vector<I3Particle>
{
 public:

  I3MCList()
    {};
  
  virtual ~I3MCList();

 private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

I3_POINTER_TYPEDEFS(I3MCList);

#endif 


