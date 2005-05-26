/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3Position.cxx 1382 2005-04-02 17:51:01Z olivas $

    @version $Revision: 1.1 $
    @date $Date: 2005-04-02 12:51:01 -0500 (Sat, 02 Apr 2005) $
    @author Troy D. Straszheim

*/

#include "icetray/test/serialization-test.h"
#include "dataclasses/I3Position.h"
#include "dataclasses/I3Units.h"

TEST_GROUP(I3Position);

I3_SERIALIZATION_TEST(I3Position);

TEST(DataMembers)
{

  double x = 50.0 * I3Units::meter;
  double y = 10.0 * I3Units::meter;
  double z = 20.0 * I3Units::meter;

  I3Position position(x,y,z);

  {
    std::ofstream ofs("/tmp/I3Position-MemberTest.xml");
    string msg = "couldn't open temporary file /tmp/I3Position-MemberTest.xml";
    ENSURE(ofs, msg.c_str());

    xml_oarchive oa(ofs);
    oa << make_nvp("I3Position", position);
    ofs.close();
  }
  {
    std::ifstream ifs("/tmp/I3Position-MemberTest.xml");
    string msg = "couldn't open temporary file /tmp/I3Position-MemberTest.xml";
    ENSURE(ifs, msg.c_str());
    xml_iarchive ia(ifs);
    I3Position serializedPosition;
    ia >> make_nvp("I3Position", serializedPosition);

    ENSURE(position.GetX() == serializedPosition.GetX(),"X read is not the same as was written");
    ENSURE(position.GetY() == serializedPosition.GetY(),"Y read is not the same as was written");
    ENSURE(position.GetZ() == serializedPosition.GetZ(),"Z read is not the same as was written");
    ENSURE(position.GetR() == serializedPosition.GetR(),"R read is not the same as was written");
    ENSURE(position.GetTheta() == serializedPosition.GetTheta(),"Theta read is not the same as was written");
    ENSURE(position.GetPhi() == serializedPosition.GetPhi(),"Phi read is not the same as was written");
    ENSURE(position.GetRho() == serializedPosition.GetRho(),"Rho read is not the same as was written");

    ifs.close();
  }
  unlink("/tmp/I3Position-MemberTest.xml");
}
