/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MCEventTest.cxx,v 1.4 2004/08/09 12:13:10 troy Exp $

    @version $Revision: 1.4 $
    @date $Date: 2004/08/09 12:13:10 $
    @author pretz

    @todo

*/

#include "TUT/tut.h"

#include "dataclasses/I3MCEvent.h"
#include "dataclasses/I3BasicTrack.h"
#include "TFile.h"
#include "TTree.h"
#include "TClass.h"
#include <string>
using std::string;
using std::cout;
using std::endl;

namespace tut
{
  struct I3MCEventTest
  {
  };
    
  typedef test_group<I3MCEventTest> factory;

  typedef factory::object object;
}

namespace
{
  tut::factory t("I3MCEventTest");
}

namespace tut
{
  template<> template<>
  void object::test<1>()
  {
    // nothing of consequence, creation and deletion
    I3MCEventPtr event(new I3MCEvent), event2;
    event2 = event;
  }

  // branch empty 
  template<> template<>
  void object::test<2>() // dont need to start with 1
  {
    printf("FIXME: (test 2) root dumps core\n");

#if 0
    I3MCEvent *event = new I3MCEvent; 
    
    TTree *t = new TTree("mytree","tree");
    
    t->Branch("branch","I3MCEvent",&event);
    
    t->Fill();
    
    I3MCEvent *event_out = new I3MCEvent;
    t->SetBranchAddress("branch",&event_out);
    
    t->GetEvent(0);

    delete event;
    delete event_out;
#endif
  }

  //testing filling an event with tracks into a tree
  template<> template<>
  void object::test<3>() // dont need to start with 1
  {
    printf("FIXME: (test 3) root dumps core\n");
#if 0
    I3MCEventPtr event(new I3MCEvent); 
    
    I3BasicTrackPtr bt(new I3BasicTrack); 
    bt->SetAzimuth(4.5);
    bt->SetX(3.4);
    
    event->GetMCParticleDict()["F2k"] = I3MCParticleEventPtr(new I3MCParticleEvent);
    event->GetMCParticleDict()["F2k"]->GetInIceParticles().push_back(bt);
    
    TTree *t = new TTree("mytree","tree");
    
    I3MCEvent *baldptr = event.get();
    t->Branch("branch","I3MCEvent",&baldptr);

    
    t->Fill();
    
    I3MCEventPtr event_out(new I3MCEvent);
    baldptr = event_out.get();
    t->SetBranchAddress("branch",&baldptr);
    
    t->GetEvent(0);

    ensure("checking the output data",
	   event_out
		->GetMCParticleDict()["F2k"]
		->GetInIceParticles()[0]
		->GetX()==3.4);
#endif
  }
}
