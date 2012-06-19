//
// I3TimeWindow.cxx
//
// A class to represent disjoint time spans within an event
// separately for each DOM, with rudimentary methods for
// logically combining such spans.
//
// Copyright (c) 2012 Jakob van Santen <vansanten@wisc.edu>
// and the IceCube Collaboration <http://www.icecube.wisc.edu>
//

#include "dataclasses/I3TimeWindow.h"

#include <boost/foreach.hpp>
#include <boost/serialization/list.hpp>

template <typename Archive>
void
I3TimeWindow::serialize(Archive &ar, unsigned version)
{
	ar & make_nvp("Start", start_);
	ar & make_nvp("Stop", stop_);
}

template <typename Archive>
void
I3TimeWindowSeries::serialize(Archive &ar, unsigned version)
{
	ar & make_nvp("TimeWindows",
	    base_object<std::list<I3TimeWindow> >(*this));
}

I3_SERIALIZABLE(I3TimeWindow);
I3_SERIALIZABLE(I3TimeWindowSeries);
I3_SERIALIZABLE(I3TimeWindowSeriesMap);

I3TimeWindow::OverlapType
I3TimeWindow::GetOverlapType(const I3TimeWindow &other) const
{
	if (start_ > other.start_) {
		if (start_ > other.stop_)
			return NONE;
		 else if (stop_ <= other.stop_)
			return WITHIN;
		 else
			return BEFORE;
	} else {
		if (stop_ < other.start_)
			return NONE;
		else if (stop_ <= other.stop_)
			return WITHIN;
		else
			return AFTER;
	}
}

bool
I3TimeWindow::operator<(const I3TimeWindow &other) const
{
	if (start_ < other.start_)
		return true;
	else if (start_ == other.start_)
		return (stop_ < other.stop_);
	else
		return false;
}

bool
I3TimeWindow::operator==(const I3TimeWindow &other) const
{
	return (start_ == other.start_ && stop_ == other.stop_);
}

void
I3TimeWindowSeries::push_back(const I3TimeWindow &other)
{
	I3TimeWindowSeries::iterator pos =
	    std::lower_bound(this->begin(), this->end(), other);
	if (pos == this->end())
		std::list<I3TimeWindow>::push_back(other);
	else
		this->insert(pos, other);
	this->coalesce();
}

// OR all our time windows, which are guaranteed to be ordered by start time.
void
I3TimeWindowSeries::coalesce()
{
	if (this->size() == 0)
		return;
	I3TimeWindowSeries::iterator current(this->begin()), next(current);
	next++;
	for ( ; next != this->end(); next++)
		if (current->GetOverlapType(*next) != I3TimeWindow::NONE) {
			current->start_ = std::min(current->start_, next->start_);
			current->stop_ = std::max(current->stop_, next->stop_);
			current = this->erase(next);
			next = current;
		} else {
			current++;
		}
}

I3TimeWindowSeries
I3TimeWindowSeries::operator|(const I3TimeWindowSeries &other) const
{
	I3TimeWindowSeries ored(*this);
	BOOST_FOREACH(const I3TimeWindow &w, other)
		ored.push_back(w);
	
	return ored;
}

I3TimeWindowSeriesMap
operator|(const I3TimeWindowSeriesMap &left, const I3TimeWindowSeriesMap &right)
{
	I3TimeWindowSeriesMap ored(left);
	
	BOOST_FOREACH(const I3TimeWindowSeriesMap::value_type &pair, right) {
		I3TimeWindowSeries &target = ored[pair.first];
		BOOST_FOREACH(const I3TimeWindow &w, pair.second)
			target.push_back(w); 
	}
	
	return ored;
}
