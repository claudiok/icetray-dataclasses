#include <I3Test.h>
#include <dataclasses/I3TimeWindow.h>

#include <boost/next_prior.hpp>

TEST_GROUP(I3TimeWindowTest);

TEST(Coalesce)
{
	I3TimeWindowSeries windows;
	const double tstart = -std::numeric_limits<double>::infinity();
	
	// Add one window. This should act just like a vanilla std::list
	windows.push_back(I3TimeWindow(tstart, 1));
	ENSURE_EQUAL(windows.size(), 1u);
	ENSURE_EQUAL(windows.front().GetStart(), tstart);
	ENSURE_EQUAL(windows.front().GetStop(), 1);
	
	// Add a window that overlaps by equality; it gets merged.
	windows.push_back(I3TimeWindow(1, 2));
	ENSURE_EQUAL(windows.size(), 1u);
	ENSURE_EQUAL(windows.front().GetStart(), tstart);
	ENSURE_EQUAL(windows.front().GetStop(), 2);
	
	// Add a window that overlaps by quite a bit. Also merged.
	windows.push_back(I3TimeWindow(0, 3));
	ENSURE_EQUAL(windows.size(), 1u);
	ENSURE_EQUAL(windows.front().GetStart(), tstart);
	ENSURE_EQUAL(windows.front().GetStop(), 3);
	
	// Add a disjoint window. Now we have two.
	windows.push_back(I3TimeWindow(10, 12));
	ENSURE_EQUAL(windows.size(), 2u);
	ENSURE_EQUAL(boost::next(windows.begin())->GetStart(), 10);
	ENSURE_EQUAL(boost::next(windows.begin())->GetStop(), 12);
	
	// Add a bridging window; back to one.
	windows.push_back(I3TimeWindow(3, 10));
	ENSURE_EQUAL(windows.size(), 1u);
	ENSURE_EQUAL(windows.front().GetStart(), tstart);
	ENSURE_EQUAL(windows.front().GetStop(), 12);
}
