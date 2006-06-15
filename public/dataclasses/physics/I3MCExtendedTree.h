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
#include "icetray/I3DefaultName.h"

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

  void AddPrimary(I3MCParticle<T>&);
  void AppendChild(I3MCParticle<T>&, I3MCParticle<T>&);
  std::vector<I3MCParticle<T> > GetPrimaries();
  I3Tree<I3MCParticle<T> > GetInIceParticles();
  I3Tree<I3MCParticle<T> > GetIceTopParticles();
  std::vector<I3Composite> GetComposites();

 private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

I3_POINTER_TYPEDEFS(I3MCExtendedTree);
I3_DEFAULT_NAME(I3MCExtendedTree);

#endif 


