/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MCEventTest.cxx,v 1.2 2004/07/03 18:40:58 troy Exp $

    @version $Revision: 1.2 $
    @date $Date: 2004/07/03 18:40:58 $
    @author pretz

    @todo

*/

#include "test/tut.h"

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
    I3MCEvent fEvent;
    I3MCEventTest() { }
    virtual ~I3MCEventTest() { }
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
#if 0
  // TDS FIXME:  these need mods for boost::shared_ptr<>

  // testing filling an event with tracks into a tree
  template<> template<>
  void object::test<1>() // dont need to start with 1
  {
    I3MCEvent *event = new I3MCEvent(); 
    
    I3BasicTrack *bt = new I3BasicTrack(); 
    bt->SetAzimuth(4.5);
    bt->SetX(3.4);
    
    event->GetMCParticleDict()["F2k"] = new I3MCParticleEvent();
    event->GetMCParticleDict()["F2k"]->GetInIceParticles().push_back(bt);
    
    TTree *t = new TTree("mytree","tree");
    
    t->Branch("branch","I3MCEvent",&event);
    
    t->Fill();
    
    I3MCEvent* event_out = new I3MCEvent();
    
    t->SetBranchAddress("branch",&event_out);
    
    t->GetEvent(0);

    ensure("checking the output data",
	   event_out
		->GetMCParticleDict()["F2k"]
		->GetInIceParticles()[0]
		->GetX()==3.4);
  }
  
#endif
}
