/**
 * @file I3LinearizedMCTree.cxx
 * @date $Date$
 * @author jvansanten
 *
 * (c) 2012 Jakob van Santen <vansanten@wisc.edu>
 *          and the IceCube Collaboration
 * the IceCube Collaboration
 * $Id$
 *
 */

#include "dataclasses/physics/I3LinearizedMCTree.h"
#include "dataclasses/I3Constants.h"

#include <boost/foreach.hpp>
#include <queue>

template <class Archive>
void
I3LinearizedMCTree::I3Stochastic::serialize(Archive &ar, unsigned version)
{
	ar & make_nvp("Time", time_);
	ar & make_nvp("Energy", energy_);
	ar & make_nvp("MajorID", major_id_);
	ar & make_nvp("MinorID", minor_id_);
	ar & make_nvp("Type", type_);
}

template <class Archive>
void
I3LinearizedMCTree::serialize(Archive &ar, unsigned version)
{
	ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
	ar & make_nvp("I3MCTree", tree_);
	ar & make_nvp("Ranges", ranges_);
	ar & make_nvp("Stochastics", stochastics_);
}

I3_SERIALIZABLE(I3LinearizedMCTree::I3Stochastic);
I3_SERIALIZABLE(I3LinearizedMCTree);

I3LinearizedMCTree::I3Stochastic::I3Stochastic(const I3Particle &parent, const I3Particle &p)
{
	time_ = p.GetTime()-parent.GetTime();
	energy_ = p.GetEnergy();
	major_id_ = p.GetMajorID();
	minor_id_ = p.GetMinorID();
	type_ = p.GetType();
}

bool I3LinearizedMCTree::I3Stochastic::operator<(const I3LinearizedMCTree::I3Stochastic &other) const
{
	return time_ < other.time_;
}

bool
I3LinearizedMCTree::I3Stochastic::IsCompressible(const I3Particle &parent, const I3Particle &p)
{
	if ((p.IsCascade() && p.GetLocationType() == I3Particle::InIce)
	    && (p.GetFitStatus() == I3Particle::NotSet) && (p.GetLength() == 0.)
	    && (p.GetSpeed() == I3Constants::c) && (p.GetDir() == parent.GetDir())) {
		    I3Particle newp(p);
		    Propagate(newp, parent.GetTime() - p.GetTime());
		    double position_err = newp.GetPos().CalcDistance(parent.GetPos());
		    return (position_err < 0.5);
	} else {
		return false;
	}
}

I3Particle
I3LinearizedMCTree::I3Stochastic::Rehydrate(const I3Particle &parent) const
{
	I3Particle p;
	
	p.SetShape(I3Particle::Null);
	p.SetFitStatus(I3Particle::NotSet);
	p.SetLocationType(I3Particle::InIce);
	p.SetSpeed(I3Constants::c);
	p.SetLength(0.);
	
	p.SetEnergy(energy_);
	p.SetType(type_);
	
	// The uniqueness of I3Particle IDs is guaranteed by the constructor
	// and expected by client code (e.g. all of I3MCTreeUtils).
	// Handle with care.
	p.major_ID_ = major_id_;
	p.ID_ = minor_id_;
	
	p.SetDir(parent.GetDir());
	p.SetPos(parent.GetPos());
	p.SetTime(parent.GetTime());
	Propagate(p, time_);
	
	return p;
}

// I3Particle::ShiftAlongTrack() without stupid assert()s.
void
I3LinearizedMCTree::I3Stochastic::Propagate(I3Particle &p, double tick)
{
	I3Position pos = p.GetPos();
	const I3Direction &dir = p.GetDir();
	double distance = tick*p.GetSpeed();
		
	pos.SetX(pos.GetX() + distance*dir.GetX());
	pos.SetY(pos.GetY() + distance*dir.GetY());
	pos.SetZ(pos.GetZ() + distance*dir.GetZ());
	p.SetPos(pos);
	p.SetTime(p.GetTime() + tick);
}

namespace {

class pid {
private:
	uint64_t major_;
	int minor_;
public:
	pid(const I3Particle &p) : major_(p.GetMajorID()), minor_(p.GetMinorID()) {};
	bool operator<(const pid &other) const
	{
		if (major_ < other.major_)
			return true;
		else if (major_ > other.major_)
			return false;
		else if (minor_ < other.minor_)
			return true;
		else 
			return false;
	}
	bool operator!=(const I3Particle &p) const
	{
		return (major_ != p.GetMajorID()) || (minor_ != p.GetMinorID());
	}
};

}

I3LinearizedMCTree::I3LinearizedMCTree(const I3MCTree &source) : tree_(source)
{
	typedef I3MCTree::pre_order_iterator pre_iterator;
	typedef I3MCTree::post_order_iterator post_iterator;
	
	typedef std::map<pid, std::list<stochastic_t> > pid_map_t;
	typedef std::map<unsigned, std::list<stochastic_t> > idx_map_t;
	pid_map_t stripped;
	
	for (post_iterator it = tree_.begin_post(); it != tree_.end_post(); ) {
		pre_iterator parent = tree_.parent(it);
		// Strip out nodes that
		//    a) have a parent, and
		//    b) are leaf nodes, and
		//    c) are stochastic energy losses, and
		//    d) are not the parents of already-stripped nodes
		if (tree_.is_valid(parent) && (it.number_of_children() == 0) 
		    && I3Stochastic::IsCompressible(*parent, *it) && (stripped.find(*it) == stripped.end())) {
			stripped[*parent].push_back(stochastic_t(*parent, *it));
			it = tree_.erase(it);
		} else {
			it++;
		}
	}
	
	// Record the distance from the beginning of the tree and number of 
	// stripped nodes for each parent, and append the stripped nodes to
	// a flat vector.
	idx_map_t stripped_idx;
	BOOST_FOREACH(pid_map_t::value_type &pair, stripped) {
		pre_iterator pos = tree_.begin();
		unsigned idx = 0;
		for ( ; pos != tree_.end() && (pair.first != *pos); pos++, idx++) {}
		pair.second.sort();
		stripped_idx[idx].swap(pair.second);
	}
	
	size_t n_stochastics = 0;
	BOOST_FOREACH(const idx_map_t::value_type &pair, stripped_idx) {
		ranges_.push_back(std::make_pair(pair.first, pair.second.size()));
		std::copy(pair.second.begin(), pair.second.end(),
		    std::back_inserter(stochastics_));
		n_stochastics += pair.second.size();
	}
}

I3LinearizedMCTree::operator I3MCTree()
{
	typedef I3MCTree::pre_order_iterator pre_iterator;
	typedef I3MCTree::sibling_iterator sibling_iterator;
	
	I3MCTree retree(tree_);
	
	// Find the points in the *stripped* tree where
	// we should attach the stripped leaves.
	std::queue<pid> parents;
	BOOST_FOREACH(const range_t &span, ranges_) {
		pre_iterator it = retree.begin();
		std::advance(it, span.first);
		parents.push(*it);
	}
	
	std::vector<stochastic_t>::const_iterator leaf = stochastics_.begin();
	BOOST_FOREACH(const range_t &span, ranges_) {
		pre_iterator parent = retree.begin();
		unsigned idx = 0;
		for ( ; parent != retree.end() && (parents.front() != *parent); parent++, idx++) {}

		// Insert new leaves in time order relative to existing siblings
		sibling_iterator splice = parent.begin();
		for (unsigned i = 0; i < span.second; i++, leaf++) {
			I3Particle rehydrated = leaf->Rehydrate(*parent);
			while (splice != parent.end() && rehydrated.GetTime() >= splice->GetTime())
				splice++;
			if (splice == parent.end())
				splice = retree.append_child(parent, rehydrated);
			else
				splice = retree.insert(splice, rehydrated);
		}
		
		parents.pop();
	}
	
	return retree;
}

size_t
I3LinearizedMCTree::GetNumberOfStrippedParents() const
{
	return ranges_.size();
}

size_t
I3LinearizedMCTree::GetNumberOfStrippedStochastics() const
{
	size_t n_stochastics = 0;
	BOOST_FOREACH(const range_t &span, ranges_)
		n_stochastics += span.second;
	
	return n_stochastics;
}

