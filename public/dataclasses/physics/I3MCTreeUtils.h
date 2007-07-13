/**
    copyright  (C) 2004
    the icecube collaboration
    @file I3MCTreeUtils.h
*/

#ifndef I3MCTREEUTILS_H_INCLUDED
#define I3MCTREEUTILS_H_INCLUDED

#include "dataclasses/physics/I3Particle.h"
#include "dataclasses/physics/I3MCTree.h"
#include "dataclasses/physics/I3MCList.h"
#include "dataclasses/physics/I3MCHit.h"

namespace I3MCTreeUtils
{
  /**
   * Adds a primary (top-level node) to the tree.
   * The primary has no parent.
   * A tree can have multiple primaries.
   * Sets the shape to Primary
   */
  void AddPrimary(I3MCTree&, I3Particle&);
  void AddPrimary(I3MCTreePtr, I3Particle&);

  void AddPrimary(I3MCTree&,  const I3MCTree&);

  /**
   *Appends a child to the parent particle
   */
  void AppendChild(I3MCTree&,  const I3Particle&,  const I3Particle&);
  void AppendChild(I3MCTreePtr,  const I3Particle&,  const I3Particle&);

  /**
   *Gets a list of primaries from the tree
   */
  const std::vector<I3Particle> GetPrimaries(const I3MCTree&);
  const std::vector<I3Particle> GetPrimaries(I3MCTreeConstPtr);

  /**
   *Gets a list of daughters of the parent particle.
   */
  const std::vector<I3Particle> GetDaughters(const I3MCTree&, const I3Particle&);
  const std::vector<I3Particle> GetDaughters(I3MCTreeConstPtr, const I3Particle&);

  /**
   *Gets the parent of a particle.  log_fatals if parent does not exist.
   */
  const I3Particle& GetParent(const I3MCTree&, const I3Particle&);
  const I3Particle& GetParent(I3MCTreeConstPtr, const I3Particle&);

  /**
   *Returns true if the particle has a parent
   */
  bool HasParent(const I3MCTree&, const I3Particle&);
  bool HasParent(I3MCTreeConstPtr, const I3Particle&);

  /**
   * Function that converts am I3MCList to an I3MCTree.
   * NOTE: No attempt has been made to construct trees
   * from flat lists.  All particles in the I3MCList
   * go into the top level of the tree, so will be
   * considered a primary.  Particles in composite
   * lists become daughters in the tree.  The parentID
   * and primaryID remain unchanged in the conversion.
   */
  I3MCTreePtr ListToTree(const I3MCList&);
  I3MCTreePtr ListToTree(I3MCListConstPtr);

  /**
   * Gets either an I3MCList or an I3MCTree from the frame
   * with the specificed key.  If the object is an I3MCList
   * it is converted to an I3MCTree with ListToTree.
   */
  I3MCTreeConstPtr Get(I3FramePtr, const std::string&);

  /**
   * Will search for I3MCList and I3MCTree by either of two keys.
   * It's common for the key to change from someting like...
   * "MyList" to "MyTree"  Now you can give both to Get and it'll
   * look for both.
   */
  I3MCTreeConstPtr Get(I3FramePtr, const std::string&, const std::string&);

  /**
   * Used internally by ListToTree and called recursively.
   * The general population probably won't find this useful.
   * To use it properly, you need to...
   * 1) Copy the particle you want to add
   * 2) Clear the composite list of the copy
   * 3) Append the copy (with the empty composite list) to the tree with insert.
   * 4) Pass to ConvertComposite the tree, the iterator (return value from insert call),
        and the composite list of the original particle.
   *  Again probably not for general consumption.
   */
  namespace internal{
    void ConvertComposite(I3MCTree&, I3MCTree::iterator&, const vector<I3Particle>&);
    void DumpChildren(const I3MCTree&,I3MCTree::iterator);
  }

  /**
   *Returns the InIce particle with highest energy.
   *This is useful for example in extracting "the muon" from the 
   *atmospheric neutrino data.
   */
  //vector<I3Particle>::const_iterator GetMostEnergeticPrimary(const I3MCTree&);
  //vector<I3Particle>::const_iterator GetMostEnergeticPrimary(I3MCTreeConstPtr);
  I3MCTree::iterator GetMostEnergeticPrimary(const I3MCTree&);
  I3MCTree::iterator GetMostEnergeticPrimary(I3MCTreeConstPtr);

  I3MCTree::iterator GetMostEnergeticInIce(const I3MCTree&);
  I3MCTree::iterator GetMostEnergeticInIce(I3MCTreeConstPtr);

//----------Added by seo: Start-----------------------------------------

  I3MCTree::iterator GetMostEnergeticStochastics(const I3MCTree&);
  I3MCTree::iterator GetMostEnergeticStochastics(I3MCTreeConstPtr);

  int GetNumberOfStochastics(const I3MCTree&, double&);
  int GetNumberOfStochastics(I3MCTreeConstPtr, double&);

  int GetNumberOfAtmosphericMuons(const I3MCTree&);
  int GetNumberOfAtmosphericMuons(I3MCTreeConstPtr);

  bool IsCosmicRayParticle(const I3Particle&);
  bool IsCosmicRayParticle(I3ParticlePtr);

//----------Added by seo: End-----------------------------------------

  I3MCTree::iterator GetMostEnergetic(const I3MCTree&, I3Particle::ParticleType);
  I3MCTree::iterator GetMostEnergetic(I3MCTreeConstPtr, I3Particle::ParticleType);

  I3MCTree::iterator GetMostEnergeticTrack(const I3MCTree&);
  I3MCTree::iterator GetMostEnergeticTrack(I3MCTreeConstPtr);

  I3MCTree::iterator GetMostEnergeticCascade(const I3MCTree&);
  I3MCTree::iterator GetMostEnergeticCascade(I3MCTreeConstPtr);

  /**
   *Returns a vector of particles that are InIce.
   */
  const vector<I3Particle> Get(const I3MCTree&, I3Particle::LocationType);

  const vector<I3Particle> GetInIce(const I3MCTree&);
  const vector<I3Particle> GetInIce(I3MCTreeConstPtr);

  /**
   * This gets the particle that created the hit;
   */
  I3Particle Get(const I3MCTree&, const I3MCHit&);

  /**
   *Returns a vector of particles that are IceTop.
   */
  const vector<I3Particle> GetIceTop(const I3MCTree&);
  const vector<I3Particle> GetIceTop(I3MCTreeConstPtr);

  I3MCTree::iterator GetIterator(I3MCTreePtr, const I3Particle&);

  /**
   * This gets the primary that created the particle;
   */
  I3ParticlePtr GetPrimary(const I3MCTree&, const I3Particle&);
  I3ParticlePtr GetPrimary(I3MCTreePtr, const I3Particle&);
  I3ParticlePtr GetPrimary(I3MCTreeConstPtr, const I3Particle&);

  void Dump(const I3MCTree&);
  void Dump(I3MCTreeConstPtr);
  void Dump(I3MCTreePtr);

}

#endif 


