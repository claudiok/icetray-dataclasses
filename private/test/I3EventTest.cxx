/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3EventTest.cxx,v 1.4 2004/05/14 18:35:53 deyoung Exp $

    @version $Revision: 1.4 $
    @date $Date: 2004/05/14 18:35:53 $
    @author pretz

    @todo

*/

#include "test/tut.h"

#include "dataclasses/I3Event.h"
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
  struct I3EventTest
  {
    I3Event fTrack;
    I3EventTest() { }
    virtual ~I3EventTest() { }
  };
    
  typedef test_group<I3EventTest> factory;

  typedef factory::object object;
}

namespace
{
  tut::factory t("I3EventTest");
}

namespace tut
{
  // testing filling an event with tracks into a tree
  template<> template<>
  void object::test<1>() // dont need to start with 1
  {
    I3Event *event = new I3Event(); 
    
    I3BasicTrack *bt = new I3BasicTrack(); 
    bt->Azimuth(4.5);
    bt->X(3.4);
    
    event->MCParticleData()["F2k"] = new I3MCParticleEvent();
    event->MCParticleData()["F2k"]->InIceParticles().push_back(bt);
    
    TTree *t = new TTree("mytree","tree");
    
    t->Branch("branch","I3Event",&event);
    
    t->Fill();
    
    I3Event* event_out = new I3Event();
    
    t->SetBranchAddress("branch",&event_out);
    
    t->GetEvent(0);

    ensure("checking the output data",
	   event_out->MCParticleData()["F2k"]->InIceParticles()[0]->X()==3.4);
  }
  
}
