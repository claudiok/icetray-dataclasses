/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3TrackTest.cxx,v 1.2 2004/04/22 15:55:44 pretz Exp $

    @version $Revision: 1.2 $
    @date $Date: 2004/04/22 15:55:44 $
    @author Troy D. Straszheim

    @todo
*/

#include "test/tut.h"

#include "dataclasses/I3Track.h"
#include <string>
using std::string;
using std::cout;
using std::endl;

namespace tut
{
  struct I3TrackTest
  {
    I3TrackTest() {
      cout << "I3Track is abstract base class.  No tests exist." << endl;
    };

  };

  typedef test_group<I3TrackTest> factory;
  typedef factory::object object;
}

namespace
{
  tut::factory t("I3Track");
}

