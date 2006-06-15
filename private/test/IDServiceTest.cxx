#include <I3Test.h>

#include "icetray/I3Tray.h"

#include "phys-services/source/I3Muxer.h"
#include "phys-services/empty-streams/I3EmptyStreamsFactory.h"

// header files
#include "icetray/I3Module.h"
#include "icetray/I3Frame.h"

#include "phys-services/I3IDServiceFactory.h"
#include "phys-services/I3IDService.h"

class IDServiceTestModule : public I3Module
{
public:

  IDServiceTestModule(const I3Context& ctx) :
    I3Module(ctx){ AddOutBox("OutBox"); }

  ~IDServiceTestModule();
  void Configure(){};
  void Physics(I3FramePtr frame){
    I3IDServicePtr id_serv = frame->Get<I3IDServicePtr>();

    const int n_test = 100;
    vector<I3Particle> p_list;
    for(int i=0; i<n_test; i++){
      I3Particle p;
      p.SetID(id_serv);
      p_list.push_back(p);
    }
  };

private:
  
  IDServiceTestModule();
  IDServiceTestModule(const IDServiceTestModule& source);
  IDServiceTestModule& operator=(const IDServiceTestModule& source);

  SET_LOGGER("IDServiceTestModule");
  
};  // end of class IDServiceTestModule


// This is a test that checks that each of the frames that comes
// through is a.) created on the right stream and b.) has the 
// right classes in it.
TEST_GROUP(IDServiceTest);



I3_MODULE(IDServiceTestModule);

TEST(ev_stat_cal_geo)
{
  I3Tray tray;

  tray.AddService<I3EmptyStreamsFactory>("empty")
    ("NFrames",5);
  
  tray.AddService<I3IDService>("idservice")

  tray.AddModule<I3Muxer>("muxme");

  tray.AddModule<IDServiceTestModule("test_mod");
  
  tray.Execute();
  tray.Finish();
}

