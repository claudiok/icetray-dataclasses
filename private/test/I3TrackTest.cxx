/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3TrackTest.cxx,v 1.1.2.1 2004/04/15 10:33:19 troy Exp $

    @version $Revision: 1.1.2.1 $
    @date $Date: 2004/04/15 10:33:19 $
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

