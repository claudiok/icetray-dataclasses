/**
    copyright  (C) 2004
    the icecube collaboration
    $Id$

    @version $Revision: 1.1 $
    @date $Date$
    @author Troy D. Straszheim

*/

#include "icetray/test/serialization-test.h"
#include "dataclasses/I3Direction.h"
#include "dataclasses/I3Units.h"

TEST_GROUP(I3Direction);

I3_SERIALIZATION_TEST(I3Direction);

TEST(DataMembers)
{

  double zenith = 50.0 * I3Units::deg;
  double azimuth = 10.0 * I3Units::deg;

  I3Direction direction(zenith,azimuth);

  {
    std::ofstream ofs("/tmp/I3Direction-MemberTest.xml");
    string msg = "couldn't open temporary file /tmp/I3Direction-MemberTest.xml";
    ENSURE(ofs, msg.c_str());

    xml_oarchive oa(ofs);
    oa << make_nvp("I3Direction", direction);
    ofs.close();
  }
  {
    std::ifstream ifs("/tmp/I3Direction-MemberTest.xml");
    string msg = "couldn't open temporary file /tmp/I3Direction-MemberTest.xml";
    ENSURE(ifs, msg.c_str());
    xml_iarchive ia(ifs);
    I3Direction serializedDirection;
    ia >> make_nvp("I3Direction", serializedDirection);

    ENSURE(direction.GetZenith() == serializedDirection.GetZenith(),"Zenith read is not the same as was written");
    ENSURE(direction.GetAzimuth() == serializedDirection.GetAzimuth(),"Azimuth read is not the same as was written");
    ENSURE(direction.GetX() == serializedDirection.GetX(),"X read is not the same as was written");
    ENSURE(direction.GetY() == serializedDirection.GetY(),"Y read is not the same as was written");
    ENSURE(direction.GetZ() == serializedDirection.GetZ(),"Z read is not the same as was written");

    ifs.close();
  }
  unlink("/tmp/I3Direction-MemberTest.xml");
}
