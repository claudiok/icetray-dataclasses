/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3EventHeader.cxx 1382 2005-04-02 17:51:01Z olivas $

    @version $Revision: 1.1 $
    @date $Date: 2005-04-02 12:51:01 -0500 (Sat, 02 Apr 2005) $
    @author Troy D. Straszheim

*/

#include "icetray/test/serialization-test.h"
#include "dataclasses/I3EventHeader.h"

TEST_GROUP(I3EventHeader);

I3_SERIALIZATION_TEST(I3EventHeader);

TEST(DataMembers)
{

  unsigned long runID = 12345;
  unsigned long eventID = 67890;

  int year = 2005;
  long long int daqStartTime = 105743003998410000LL;
  long long int daqEndTime = 105743003998420000LL;

  {
    std::ofstream ofs("/tmp/I3EventHeader-MemberTest.xml");
    string msg = "couldn't open temporary file /tmp/I3EventHeader-MemberTest.xml";
    ENSURE(ofs, msg.c_str());

    I3EventHeader eventHeader;
    I3Time startTime(year,daqStartTime);
    I3Time endTime(year,daqEndTime);

    eventHeader.SetEventID(eventID);
    eventHeader.SetRunID(runID);
    eventHeader.SetStartTime(startTime);
    eventHeader.SetEndTime(endTime);

    xml_oarchive oa(ofs);
    oa << make_nvp("I3EventHeader", eventHeader);
    ofs.close();
  }
  {
    std::ifstream ifs("/tmp/I3EventHeader-MemberTest.xml");
    string msg = "couldn't open temporary file /tmp/I3EventHeader-MemberTest.xml";
    ENSURE(ifs, msg.c_str());
    xml_iarchive ia(ifs);
    I3EventHeader eventHeader;
    ia >> make_nvp("I3EventHeader", eventHeader);

    ENSURE(eventHeader.GetEventID() == eventID,"EventID read is not the same as was written");
    ENSURE(eventHeader.GetRunID() == runID,"RunID read is not the same as was written");
    ENSURE(eventHeader.GetStartTime().GetUTCYear() == year,
	   "StartTime.year read is not the same as was written");
    ENSURE(eventHeader.GetStartTime().GetUTCDaqTime() == daqStartTime,
	   "StartTime.DaqTime read is not the same as was written");
    ENSURE(eventHeader.GetEndTime().GetUTCYear() == year,
	   "EndTime.year read is not the same as was written");
    ENSURE(eventHeader.GetEndTime().GetUTCDaqTime() == daqEndTime,
	   "EndTime.DaqTime read is not the same as was written");
    ifs.close();
  }
  unlink("/tmp/I3EventHeader-MemberTest.xml");
}
