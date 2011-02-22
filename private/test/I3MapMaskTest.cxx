#include <I3Test.h>
#include "dataclasses/I3MapOMKeyMask.h"
#include "dataclasses/physics/I3RecoPulse.h"
#include "boost/make_shared.hpp"

TEST_GROUP(I3MapMask);

static I3RecoPulseSeriesMapPtr
manufacture_pulsemap()
{
	I3RecoPulseSeriesMapPtr pulsemap = boost::make_shared<I3RecoPulseSeriesMap>();
	I3RecoPulseSeries pulses;
	I3RecoPulse p;
	p.SetTime(1.0);
	p.SetWidth(2.0);
	p.SetCharge(3.141);
	pulses.push_back(p);
	
	p.SetTime(2.0); pulses.push_back(p);
	p.SetTime(12); pulses.push_back(p);
	p.SetTime(13); pulses.push_back(p);
	p.SetTime(14); pulses.push_back(p);
	p.SetTime(15); pulses.push_back(p);
	p.SetTime(16); pulses.push_back(p);
	p.SetTime(17); pulses.push_back(p);
	p.SetTime(18); pulses.push_back(p);
	
	
	
	pulsemap->operator[](OMKey(42, 42)) = pulses;
	
	pulsemap->operator[](OMKey(67, 12)) = pulses;
	
	return pulsemap;
}

TEST(Apply)
{
	I3RecoPulseSeriesMapPtr pulses, masked;
	pulses = manufacture_pulsemap();
		
	I3Frame frame;
	frame.Put("foo", pulses);
	I3RecoPulseSeriesMapMask mask(frame, "foo");
	
	ENSURE_EQUAL(mask.GetSum(), 18u);
	
	masked = mask.Apply(frame);
	
	ENSURE_EQUAL(pulses->size(), masked->size());
	ENSURE_EQUAL(masked->begin()->second.size(), 9u);
	
	/* Ensure that original and masked pulse series maps are identical. */
	I3RecoPulseSeriesMap::const_iterator mit1, mit2;
	mit1 = pulses->begin();
	mit2 = masked->begin();
	for ( ; mit1 != pulses->end(); mit1++, mit2++) {
		ENSURE_EQUAL(mit1->first, mit2->first);
		ENSURE_EQUAL(mit1->second.size(), mit2->second.size());
		I3RecoPulseSeries::const_iterator vit1, vit2;
		vit1 = mit1->second.begin();
		vit2 = mit2->second.begin();
		for ( ; vit1 != mit1->second.end(); vit1++, vit2++)
			ENSURE(*vit1 == *vit2);
	}
}

TEST(SetSinglePulse)
{
	I3RecoPulseSeriesMapPtr pulses, masked;
	pulses = manufacture_pulsemap();
		
	I3Frame frame;
	frame.Put("foo", pulses);
	I3RecoPulseSeriesMapMask mask(frame, "foo");
	
	/* Unset a pulse. */
	mask.Set(pulses->begin()->first, pulses->begin()->second[3], false);
	
	masked = mask.Apply(frame);
	ENSURE_EQUAL(mask.GetSum(), 17u);
	ENSURE_EQUAL(masked->begin()->second.size(), 8u);
	
	/* Re-set it, and make sure it comes back. */
	mask.Set(pulses->begin()->first, pulses->begin()->second[3], true);
	
	masked = mask.Apply(frame);
	ENSURE_EQUAL(mask.GetSum(), 18u);
	ENSURE_EQUAL(masked->begin()->second.size(), 9u);
	
	/* Unset a pulse, this time by index. */
	mask.Set(pulses->begin()->first, 3, false);
	
	masked = mask.Apply(frame);
	ENSURE_EQUAL(mask.GetSum(), 17u);
	ENSURE_EQUAL(masked->begin()->second.size(), 8u);
	
	/* Re-set it, and make sure it comes back. */
	mask.Set(pulses->begin()->first, 3, true);
	
	masked = mask.Apply(frame);
	ENSURE_EQUAL(mask.GetSum(), 18u);
	ENSURE_EQUAL(masked->begin()->second.size(), 9u);
}

TEST(SetOM)
{
	I3RecoPulseSeriesMapPtr pulses, masked;
	pulses = manufacture_pulsemap();
		
	I3Frame frame;
	frame.Put("foo", pulses);
	I3RecoPulseSeriesMapMask mask(frame, "foo");
	
	/* Unset an entire OM. */
	mask.Set(pulses->begin()->first, false);
	
	masked = mask.Apply(frame);
	ENSURE_EQUAL(mask.GetSum(), 9u);
	ENSURE_EQUAL(masked->size(), 1u);
	
	/* We dropped the right OM. */
	ENSURE(pulses->begin()->first != masked->begin()->first);
	
	/* Bring it back. */
	mask.Set(pulses->begin()->first, true);
	
	masked = mask.Apply(frame);
	ENSURE_EQUAL(mask.GetSum(), 18u);
	ENSURE_EQUAL(masked->size(), 2u);
	
	/* The masked version is identical again. */
	ENSURE(pulses->begin()->first == masked->begin()->first);
}

TEST(ConstructAsDiff)
{
	I3RecoPulseSeriesMapPtr pulses, masked;
	I3RecoPulseSeriesMap::const_iterator mit1, mit2;
	I3RecoPulseSeriesMapMask mask;
	pulses = manufacture_pulsemap();
		
	I3Frame frame;
	frame.Put("foo", pulses);
	
	I3RecoPulseSeriesMap subset(*pulses);
	
	
	mask = I3RecoPulseSeriesMapMask(frame, "foo", subset);
	
	
	
	/* Ensure that subset and masked pulse series maps are identical. */
	masked = mask.Apply(frame);
	mit1 = subset.begin();
	mit2 = masked->begin();
	for ( ; mit1 != subset.end(); mit1++, mit2++) {
		ENSURE_EQUAL(mit1->first, mit2->first);
		ENSURE_EQUAL(mit1->second.size(), mit2->second.size());
		I3RecoPulseSeries::const_iterator vit1, vit2;
		vit1 = mit1->second.begin();
		vit2 = mit2->second.begin();
		for ( ; vit1 != mit1->second.end(); vit1++, vit2++)
			ENSURE(*vit1 == *vit2);
	}
	
	/* Now, actually make a subset. */
	subset.erase(--subset.end());
	mask = I3RecoPulseSeriesMapMask(frame, "foo", subset);
	ENSURE_EQUAL(mask.GetSum(), 9u);
	
	/* Ensure that subset and masked pulse series maps are identical. */
	masked = mask.Apply(frame);
	mit1 = subset.begin();
	mit2 = masked->begin();
	for ( ; mit1 != subset.end(); mit1++, mit2++) {
		ENSURE_EQUAL(mit1->first, mit2->first);
		ENSURE_EQUAL(mit1->second.size(), mit2->second.size());
		I3RecoPulseSeries::const_iterator vit1, vit2;
		vit1 = mit1->second.begin();
		vit2 = mit2->second.begin();
		for ( ; vit1 != mit1->second.end(); vit1++, vit2++)
			ENSURE(*vit1 == *vit2);
	}
	
	/* Erase something in the middle. */
	subset = I3RecoPulseSeriesMap(*pulses);
	subset.begin()->second.erase(subset.begin()->second.begin()+5);
	mask = I3RecoPulseSeriesMapMask(frame, "foo", subset);
	ENSURE_EQUAL(mask.GetSum(), 17u);
	
	/* Ensure that subset and masked pulse series maps are identical. */
	masked = mask.Apply(frame);
	mit1 = subset.begin();
	mit2 = masked->begin();
	for ( ; mit1 != subset.end(); mit1++, mit2++) {
		ENSURE_EQUAL(mit1->first, mit2->first);
		ENSURE_EQUAL(mit1->second.size(), mit2->second.size());
		I3RecoPulseSeries::const_iterator vit1, vit2;
		vit1 = mit1->second.begin();
		vit2 = mit2->second.begin();
		for ( ; vit1 != mit1->second.end(); vit1++, vit2++)
			ENSURE(*vit1 == *vit2);
	}
	
}

TEST(Clear)
{
	I3RecoPulseSeriesMapPtr pulses, masked;
	pulses = manufacture_pulsemap();
		
	I3Frame frame;
	frame.Put("foo", pulses);
	I3RecoPulseSeriesMapMask mask(frame, "foo");
	
	mask.SetNone();
	
	ENSURE_EQUAL(mask.GetSum(), 0u);
	
	masked = mask.Apply(frame);
	
	ENSURE_EQUAL(masked->size(), 0u);
}

TEST(And)
{
	I3RecoPulseSeriesMapPtr pulses, masked;
	pulses = manufacture_pulsemap();
		
	I3Frame frame;
	frame.Put("foo", pulses);
	I3RecoPulseSeriesMapMask mask_1(frame, "foo");
	I3RecoPulseSeriesMapMask mask_2(frame, "foo");
	I3RecoPulseSeriesMapMask mask_3 = mask_1 & mask_2;
	
	ENSURE_EQUAL(mask_1.GetSum(), 18u);
	ENSURE_EQUAL(mask_2.GetSum(), 18u);
	ENSURE_EQUAL(mask_3.GetSum(), 18u);
	
	I3RecoPulseSeriesMap::const_iterator pit = pulses->begin();
	
	mask_1.Set(pit->first, false);
	
	mask_3 = mask_1 & mask_2;
	ENSURE_EQUAL(mask_3.GetSum(), 9u);
	
	pit++;
	mask_2.Set(pit->first, false);
	mask_3 = mask_1 & mask_2;
	ENSURE_EQUAL(mask_3.GetSum(), 0u);
}

TEST(Or)
{
	I3RecoPulseSeriesMapPtr pulses, masked;
	pulses = manufacture_pulsemap();
		
	I3Frame frame;
	frame.Put("foo", pulses);
	I3RecoPulseSeriesMapMask mask_1(frame, "foo");
	I3RecoPulseSeriesMapMask mask_2(frame, "foo");
	I3RecoPulseSeriesMapMask mask_3 = mask_1 | mask_2;
	
	ENSURE_EQUAL(mask_1.GetSum(), 18u);
	ENSURE_EQUAL(mask_2.GetSum(), 18u);
	ENSURE_EQUAL(mask_3.GetSum(), 18u);
	
	I3RecoPulseSeriesMap::const_iterator pit = pulses->begin();
	
	mask_1.Set(pit->first, false);
	
	mask_3 = mask_1 | mask_2;
	ENSURE_EQUAL(mask_3.GetSum(), 18u);
	
	mask_2.Set(pit->first, false);
	
	mask_3 = mask_1 | mask_2;
	ENSURE_EQUAL(mask_3.GetSum(), 9u);
	
	pit++;
	
	mask_1.Set(pit->first, false);
	
	mask_3 = mask_1 | mask_2;
	ENSURE_EQUAL(mask_3.GetSum(), 9u);
	
	mask_2.Set(pit->first, false);
	
	mask_3 = mask_1 | mask_2;
	ENSURE_EQUAL(mask_3.GetSum(), 0u);
}

TEST(XOr)
{
	I3RecoPulseSeriesMapPtr pulses, masked;
	pulses = manufacture_pulsemap();
		
	I3Frame frame;
	frame.Put("foo", pulses);
	I3RecoPulseSeriesMapMask mask_1(frame, "foo");
	I3RecoPulseSeriesMapMask mask_2(frame, "foo");
	I3RecoPulseSeriesMapMask mask_3 = mask_1 ^ mask_2;
	
	ENSURE_EQUAL(mask_1.GetSum(), 18u);
	ENSURE_EQUAL(mask_2.GetSum(), 18u);
	ENSURE_EQUAL(mask_3.GetSum(), 0u);
	
	I3RecoPulseSeriesMap::const_iterator pit = pulses->begin();
	
	mask_1.Set(pit->first, false);
	
	mask_3 = mask_1 ^ mask_2;
	ENSURE_EQUAL(mask_3.GetSum(), 9u);
	
	mask_2.Set(pit->first, false);
	
	mask_3 = mask_1 ^ mask_2;
	ENSURE_EQUAL(mask_3.GetSum(), 0u);
	
	
	pit++;
	
	mask_1.Set(pit->first, false);
	
	mask_3 = mask_1 ^ mask_2;
	ENSURE_EQUAL(mask_3.GetSum(), 9u);
	
	mask_2.Set(pit->first, false);
	
	mask_3 = mask_1 ^ mask_2;
	ENSURE_EQUAL(mask_3.GetSum(), 0u);
}

TEST(Not)
{
	I3RecoPulseSeriesMapPtr pulses, masked;
	pulses = manufacture_pulsemap();
		
	I3Frame frame;
	frame.Put("foo", pulses);
	const I3RecoPulseSeriesMapMask consty(frame, "foo");
	
	I3RecoPulseSeriesMapMask mask = ~consty;
	
	ENSURE_EQUAL(mask.GetSum(), 0u);
	
	masked = mask.Apply(frame);
	
	ENSURE_EQUAL(masked->size(), 0u);
}

#define ROUND_UP(num, denom) (num % denom == 0) ? num/denom : (num/denom) + 1

#if 1
TEST(Serialization)
{
	I3RecoPulseSeriesMapPtr pulses, masked;
	pulses = manufacture_pulsemap();
		
	I3Frame frame;
	frame.Put("foo", pulses);
	I3RecoPulseSeriesMapMask mask(frame, "foo");
	// I3RecoPulseSeriesMapMask mask;
	
	
	std::ostringstream oarchive_stream;
	/* This is the archive type instantiated by I3_SERIALIZABLE */
	boost::archive::portable_binary_oarchive oarchive(oarchive_stream);
	oarchive << mask;
	
	ENSURE_EQUAL( oarchive_stream.str().size(),
	    unsigned(12 + 2 + 1 + 2*2 + 1*(2)),
	    "Serialized size in bytes: 12 (I3FrameObject overhead) + 2 (OMKey bitmask overhead) "
	    "+ 1*(nchannel/8) (OMKey bitmask) + 2*(nchannel_selected) (vector bitmask overhead) "
	    "+ 1*(npulses/dom/8)");

	std::istringstream iarchive_stream(oarchive_stream.str());
	boost::archive::portable_binary_iarchive iarchive(iarchive_stream);
	I3RecoPulseSeriesMapMask maska;
	iarchive >> maska;
}
#endif
