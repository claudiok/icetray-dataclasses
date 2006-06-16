/**
    copyright  (C) 2004
    the icecube collaboration
    @version $Id: I3MCExtendedTree.h 15192 2006-02-02 01:02:05Z dule $
    @file I3MCExtendedTree.h
    @date $Date: 2006-02-01 20:02:05 -0500 (Wed, 01 Feb 2006) $
*/

#ifndef I3MCEXTENDEDTREE_H_INCLUDED
#define I3MCEXTENDEDTREE_H_INCLUDED

#include "dataclasses/physics/I3Particle.h"
#include "dataclasses/physics/I3MCParticle.h"
#include "dataclasses/I3Tree.h"

/**
 *I3MCExtendedTree - This goes into the frame and everyone can see it
 */
template <class T>
class I3MCExtendedTree : public I3Tree<I3MCParticle<T> >
{
 public:

  I3MCExtendedTree()
    {};
  
  virtual ~I3MCExtendedTree();

 private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

#endif 


