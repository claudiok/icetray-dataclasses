/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3HitTest.cxx,v 1.1.2.1 2005/02/04 22:35:16 troy Exp $

    @version $Revision: 1.1.2.1 $
    @date $Date: 2005/02/04 22:35:16 $
    @author Troy D. Straszheim

*/

#include "TUT/tut.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>

using boost::serialization::make_nvp;

#include "dataclasses/I3Hit.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

namespace tut
{
  struct I3HitTest { };
  typedef test_group<I3HitTest> factory;
  typedef factory::object object;
}

namespace
{
  static tut::factory t("I3Hit");
}

namespace tut
{

  // ensure_distance:  facilities for ensure with tolerances
  template<> template<>
  void object::test<1>() {

    I3Hit my_hit;
    my_hit.SetTime(0.42);
    ensure_distance(my_hit.GetTime(), // left side of equality
		    0.42, // right side of equality
		    0.00001); // tolerance

    // or the same with a failure message
    ensure_distance("Oh dear something is not right.  We'll never make it home now, Toto!",
		    my_hit.GetTime(), // left side of equality
		    0.42, // right side of equality
		    0.00001); // tolerance
  }

  template<> template<>
  void object::test<2>()
  {
    I3Hit h, j;
    ensure(h.GetTime() == 0);
    j.SetTime(rand()/0.3234);
    h = j;
    ensure_distance("simple assignment", j.GetTime(), h.GetTime(), 0.0001);
    ensure (h==j);
    I3Hit k(h);
    ensure (k==j);
  }

  template<> template<>
  void object::test<3>()
  {
    I3Hit u;

   // create and open a character archive for output
    std::ofstream txtofs("/tmp/filename.txt");
    std::ofstream binofs("/tmp/filename.bin");
    std::ofstream xmlofs("/tmp/filename.xml");

    boost::archive::text_oarchive txtoa(txtofs);
    boost::archive::binary_oarchive binoa(binofs);
    boost::archive::xml_oarchive xmloa(xmlofs);

    txtoa << u << u << u;
    binoa << u << u << u;
    xmloa << make_nvp("u", u) << make_nvp("u", u) << make_nvp("u", u);

    txtofs.close();
    binofs.close();
    xmlofs.close();

    std::ifstream txtifs("/tmp/filename.txt");
    std::ifstream binifs("/tmp/filename.bin");
    std::ifstream xmlifs("/tmp/filename.xml");

    boost::archive::text_iarchive txtia(txtifs);
    boost::archive::binary_iarchive binia(binifs);
    boost::archive::xml_iarchive xmlia(xmlifs);

    // read class state from archive

    I3Hit newhit;
    txtia >> newhit;
    ensure_equals("read in hit", newhit, u);

    binia >> newhit;
    ensure_equals("read in hit", newhit, u);

    xmlia >> make_nvp("newhit", newhit);
    ensure_equals("read in hit", newhit, u);
	
    // close archive
    txtifs.close();
    binifs.close();
    xmlifs.close();
  }

  template<> template<>
  void object::test<4>()
  {
    I3Hit u, v, w, x;
    x.SetTime(rand()/0.235234);
    u = u = v = v = w = x;
    ensure_distance("chain of assignment operators", u.GetTime(), x.GetTime(), 0.0001);
  }
}

