/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3BasicTrackTest.cxx,v 1.1.2.1 2004/04/15 10:33:19 troy Exp $

    @version $Revision: 1.1.2.1 $
    @date $Date: 2004/04/15 10:33:19 $
    @author Troy D. Straszheim

    @todo
*/

#include "test/tut.h"

// MODIFY: replace with include of the header file for the module you
// are testing, or whatever headers are necessary for this test.
#include "dataclasses/I3BasicTrack.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

namespace tut
{
  // MODIFY: change the name of this struct to I3MyClassTest, and
  // change its' contents.  Whatever you put inside this struct will
  // be visible from your test routines (the test routines will
  // inherit from it).  If this is a class with a constructor, it will
  // be run before every test (and the Destructor will be run after
  // every test).  So the values you leave in these variables do not
  // persist from test to test.See routines below for how access to
  // my_integer, my_string and my_hit work.

  struct I3BasicTrackTest
  {

  };

  typedef test_group<I3BasicTrackTest> factory;
  // leave this
  typedef factory::object object;
}

namespace
{
  // MODIFY: this is the identifier that you can use on the command
  // line to just run this test group, usually just the name of the
  // class you are testing.  It should have no spaces or things that
  // will confuse the shell in it, because you would have to escape
  // them when you want to run only this test.  e.g. I3MyClassTest
  tut::factory t("I3BasicTrack");
}

static void
randomize(I3BasicTrack& t) {
  t.X(rand() * M_PI);
  t.Y(rand() * M_PI);
  t.Z(rand() * M_PI);
  t.Time(rand() * M_PI);
  t.Length(rand() * M_PI);
  t.Zenith(rand() * M_PI);
  t.Azimuth(rand() * M_PI);
  t.Speed(rand() * M_PI);
}

namespace tut
{
  template<> template<>
  void object::test<1>() // dont need to start with 1
  {
    // supersimple construction/destruction
    I3BasicTrack t;
  }
  
  template<> template<>
  void object::test<2>() 
  {
    // basic output test

    I3BasicTrack t;

    // ostringstreams are basically streams that write to internal strings.
    // you can get the string out with the member function str()
    ostringstream directout, virtualout;
    // output directly through the class
    directout << t;
    // virtual output
    I3Track *base = &t;
    virtualout << *base;
    ensure(directout.str() == virtualout.str());
  }

  template<> template<>
  void object::test<3>() {
    // check nested calls to accessors
    I3BasicTrack t;
    randomize(t);
    double x = t.X();
    t.X(t.X()+1);
    ensure(x != t.X());
    
    double az = t.Azimuth();
    t.Azimuth(t.Azimuth()+M_PI);
    ensure(az != t.Azimuth());
  }

  template<> template<>
  void object::test<4>() 
  {
    // assignment
    I3BasicTrack t, u;
    ostringstream tout, uout;

    // not all fields are filled in
    t.X(1); t.Y(2); t.Z(3); t.Time(4); t.Azimuth(5); t.Speed(6);

    tout << t;
    u = t;
    uout << u;

    ensure(tout.str() == uout.str());

    // our assignment operator allows (NAN==NAN) == true.  dangerous
    // in the sense of the original meaning for NAN: (that inf/inf has
    // occurred, for instance.)
    ensure(u == t);
    ensure(t == u);
    randomize(u);
    t = u;
    ensure(t == u);
    ensure(u == t);
  }

  template<> template<>
  void object::test<5>()
  {
    I3BasicTrack t, u;
    I3Track &tref = t, &uref = u;

    // assignment and output through reference-to-base
    randomize(t);

    uref = tref;

    ensure(tref==uref);
    ensure(uref==tref);

    ostringstream tout, uout;
    tout << tref; 
    uout << uref; 
    ensure(tout.str() == uout.str());

    // tweak and be sure unequal
    tref.X(tref.X()*10.0);
    ensure(tref.X()!=uref.X());
    ensure(tref!=uref);
    ensure(uref!=tref);
    tout.str("");
    uout.str("");
    tout << tref; 
    uout << uref; 
    cout << t;
    // be careful here: if the change in X() isn't large enough to
    // cause a change in the way X() is *printed*, this will fail.
    // same below.  Seems like a factor of 10 is enough to change the
    // exponent no matter what.
    ensure(tout.str() != uout.str());

    randomize(t);
    uref = tref;
    uref.Azimuth(uref.Azimuth()*M_PI*10.0);
    ensure (tref!=uref);
    ensure (uref!=tref);
    ensure (t!=u);
    ensure (u!=t);
    tout.str(""); 
    uout.str("");
    tout << tref; 
    uout << uref; 
    ensure(tout.str() != uout.str());

  }



  template<> template<>
  void object::test<50>() 
  {
    //FIXME
    fail("NO ROOT I/O TEST EXISTS");
  }
}

