/**
 * @file I3LinearizedMCTree.h
 * @date $Date$
 * @author jvansanten
 *
 * (c) 2012 Jakob van Santen <vansanten@wisc.edu>
 *          and the IceCube Collaboration
 * the IceCube Collaboration
 * $Id$
 *
 */

#ifndef DATACLASSES_I3LINEARIZEDMCTREE_H_INCLUDED
#define DATACLASSES_I3LINEARIZEDMCTREE_H_INCLUDED

#include "dataclasses/physics/I3Particle.h"
#include "dataclasses/physics/I3MCTree.h"

/**
 * @brief A compact I3MCTree
 * 
 * I3LinearizedMCTree is an alternate format for I3MCTree, optimized for
 * efficient on-disk storage in the case where the tree is dominated by
 * a large number of terminal nodes containing I3Particles that are
 * co-linear with their parents. In these cases the daughter particles
 * can be completely described by a time, energy, type, and minor/major ids,
 * as well as the parameters of the parent particle.
 *
 * Entries in the I3MCTree returned by I3LinearizedMCTree::operator I3MCTree
 * are guaranteed to be identical to the entries in the original tree, with
 * the following exceptions:
 * - Times and energies will only be identical to within single precision
 * - The positions of daughter particles may deviate by up to 50 cm.
 */
class I3LinearizedMCTree : public I3FrameObject {
public:
	I3LinearizedMCTree() {};
	explicit I3LinearizedMCTree(const I3MCTree &);
	
	operator I3MCTree();
	
	size_t GetNumberOfStrippedParents() const;
	size_t GetNumberOfStrippedStochastics() const;
	
	class I3Stochastic {
	public:
		I3Stochastic() : time_(0), energy_(0) {};
		I3Stochastic(const I3Particle &parent, const I3Particle &stochastic);
		
		static bool IsCompressible(const I3Particle &parent, const I3Particle &stochastic);
		bool operator<(const I3Stochastic &other) const;
	
		I3Particle Rehydrate(const I3Particle &parent) const;
		
	private:
		static void Propagate(I3Particle &p, double time);
	
		friend class boost::serialization::access;
	
		template <class Archive>
		void serialize(Archive &ar, unsigned version);
	
		float time_, energy_;
		uint64_t major_id_;
		int minor_id_;
		I3Particle::ParticleType type_;
	};
	
	
private:
	I3MCTree tree_;
	typedef std::pair<unsigned, unsigned> range_t;
	typedef I3Stochastic stochastic_t;
	std::vector<stochastic_t> stochastics_;
	std::vector<range_t> ranges_;
		
	friend class boost::serialization::access;
	
	template <class Archive>
	void serialize(Archive &ar, unsigned version);
};

I3_POINTER_TYPEDEFS(I3LinearizedMCTree);

#endif /* DATACLASSES_I3LINEARIZEDMCTREE_H_INCLUDED */
