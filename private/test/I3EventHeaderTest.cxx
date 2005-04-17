/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3EventHeaderTest.cxx,v 1.3.2.1 2005/04/17 14:07:04 niessen Exp $

    @version $Revision: 1.3.2.1 $
    @date $Date: 2005/04/17 14:07:04 $
    @author Peter Niessen Sun Apr 17 09:58:13 EDT 2005

    @todo

    SIMPLE TEST SUITE AND INSTRUCTIONS FOR BUILDING YOUR OWN


    This is an example of a minimal testsuite.  You can copy this file
    and make modifications where MODIFY is specified to build your own
    test suites.
    
    The home page for "TUT", the framework we are using, is at
    http://tut-framework.sourceforge.net

    So copy this file to e.g. I3MyClassTest.cxx or what-have-you, and
    follow along.
*/

#include "TUT/tut.h"

// MODIFY: replace with include of the header file for the module you
// are testing, or whatever headers are necessary for this test.
#include "dataclasses/I3EventHeader.h"
#include <string>
#include <iostream>
#include <fstream>
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

  struct I3EventHeaderTest 
  {
    Double64_t my_time;
    string my_string;
    I3EventHeader my_header;

    // MODIFY: if you need them, probably you wont
    // I3HitTest() { /* pre-each-test initialization */ };
    // ~I3HitTest() { /* after-each-test destruction */ );
  };

  // MODIFY: change the template parameter I3HitTest to be the
  // I3MyClassTest struct, above
  typedef test_group<I3EventHeaderTest> factory;
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
  static tut::factory t("I3EventHeader");
}

namespace tut
{

  // MODIFY: Change these functions to contain your tests.  They do
  // need the template<> template<> thing because they are
  // specializations of a fancy dual-template thing.  Note that the
  // template argument to object::test<> (the literal integer, 1, 2,
  // 3) specifies the test number.  These number need not be
  // sequential, though they will be run in order, but they must be
  // unique.  Notice that the last function in this module is
  // object::test<42>().  On the command line you will be able to run
  // just this one test by typing
  //
  //      runtests I3MyClass 42
  //
  // or you will be able to run all of them by typing
  //
  //      runtests I3MyClass
  //
  // or everything in the whole project with
  //     
  //      runtests all
  //
  // typing "runtests list" will list the test groups (e.g. I3Hit,
  // I3MyClass) that are compiled in, and "runtests help" will give
  // help similar to this.

  // MODIFY: make these do something useful for testing your class
  template<> template<>
  void object::test<2>() // dont need to start with 1
  {
    // this demonstrates that the contents of struct I3HitTest simply
    // appear as local variables in the test functions.  This saves
    // typing.
    my_string = "initialized";
    my_header.SetRawStartTime(0xffffffffffffffe);
    my_time = 0xfffffffffffffffe;
  }
  
  // simple "ensure"
  template<> template<>
  void object::test<3>() {
    // here is how to "assert" that a variable has some value.  in TUT
    // these are called "ensure".
    ensure(my_string == ""); 
    // Notice that it has been reset, this is not the same my_string as in
    // test<2>, above.

    // here is how to associate a string message with an "ensure".  If
    // the boolean fails the message will propagate back up to the
    // test driver program and be displayed.
    // ensure("this will be displayed if the ensure fails", my_integer == 0);

  }

  // ensure_equals and so forth
  template<> template<>
  void object::test<4>() {
    // this is how to ensure that two things are equal.  What the
    // difference is with just using ensure(a==b), I dunno.
    my_time = 0;
    ensure_equals(my_time, 0);

    // same as above, but with a message displayed on failure
    ensure_equals("my_time is not zero!", my_time, 0);
  }

  // ensure_distance:  facilities for ensure with tolerances
  template<> template<>
  void object::test<5>() {

    my_event.SetRawStartTime(1234567890);
    ensure_distance(my_event.GetGetRawStartTime(), // left side of equality
		    1234567809, // right side of equality
		    100); // tolerance

    // or the same with a failure message
    ensure_distance("Oh dear something is not right.  We'll never make it home now, Toto!",
		    my_header.GetRawStartTime(), // left side of equality
		    1234567809, // right side of equality
		    100); // tolerance
    
    // and here is how to simpy fail with a message
    // fail("This failure is for demonstration purposes.  No real failure has occurred.");
  }

  // END OF DEMO
  // Here start the real (though minimal) tests of I3Hit

  // FIXME:  need operator<<'s and a way to compare their output
  template<> template<>
  void object::test<7>()
  {
    I3EventHeader h, j;
    ensure(h.GetRawStartTime() == 0);
    // generate a 64 bit number by mulitplying two 32 bit numbers
    j.SetRawStartTime((ULong64_t (rand())*(ULong64_t (rand()));
    h = j;
    ensure_distance("simple assignment",
		    j.GetRawStartTime(), h.GetRawStartTime(),
		    0);
    ensure (h==j);
    I3EventHeader k(h);
    ensure (k==j);
  }

  template<> template<>
  void object::test<42>()
  {
    I3EventHeader u, v, w, x;
    x.SetRawStartTime(rand());
    u = u = v = v = w = x;
    ensure_distance("chain of assignment operators",
		    u.GetRawStartTime(), x.GetRawStartTime(), 0);
  }
}

