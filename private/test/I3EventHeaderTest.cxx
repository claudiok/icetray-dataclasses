/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3EventHeaderTest.cxx,v 1.3.2.2 2005/04/18 12:45:13 pretz Exp $

    @version $Revision: 1.3.2.2 $
    @date $Date: 2005/04/18 12:45:13 $
    @author Peter Niessen Sun Apr 17 09:58:13 EDT 2005

    @todo
*/

#include "TUT/tut.h"

#include "dataclasses/I3EventHeader.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

namespace tut
{
  struct I3EventHeaderTest 
  {
    //    Double64_t my_time;
    ULong64_t my_time;
    string my_string;
    I3EventHeader my_header;
  };

  typedef test_group<I3EventHeaderTest> factory;

  typedef factory::object object;
}

namespace
{
  static tut::factory t("I3EventHeader");
}

namespace tut
{
  template<> template<>
  void object::test<2>() // dont need to start with 1
  {
    my_string = "initialized";
    my_header.SetRawStartTime(0xffffffffffffffe);
    my_time = 0xfffffffffffffffe;
  }
  
  // simple "ensure"
  template<> template<>
  void object::test<3>() 
  {
    ensure(my_string == ""); 
  }

  template<> template<>
  void object::test<4>() 
  {
    my_time = 0;
    ensure_equals(my_time, 0);
    
    ensure_equals("my_time is not zero!", my_time, 0);
  }

  template<> template<>
  void object::test<5>() {

    my_header.SetRawStartTime(1234567890);
    ensure(my_header.GetRawStartTime() == 1234567890);
//     ensure_distance(my_header.GetRawStartTime(), 
// 		    1234567809, 
// 		    100); 


  }

//   template<> template<>
//   void object::test<7>()
//   {
//     I3EventHeader h, j;
//     ensure(h.GetRawStartTime() == 0);
  // generate a 64 bit number by mulitplying two 32 bit numbers
//     j.SetRawStartTime((ULong64_t (rand())*(ULong64_t (rand()));
//     h = j;
//     ensure_distance("simple assignment",
// 		    j.GetRawStartTime(), h.GetRawStartTime(),
// 		    0);
//     ensure (h==j);
//     I3EventHeader k(h);
//     ensure (k==j);
//  }

//   template<> template<>
//   void object::test<42>()
//   {
//     I3EventHeader u, v, w, x;
//     x.SetRawStartTime(rand());
//     u = u = v = v = w = x;
//     ensure_distance("chain of assignment operators",
// 		    u.GetRawStartTime(), x.GetRawStartTime(), 0);
//  }
}

