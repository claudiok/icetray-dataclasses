/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3F2KRecoTrackTest.cxx,v 1.4 2004/07/03 18:40:58 troy Exp $

    @version $Revision: 1.4 $
    @date $Date: 2004/07/03 18:40:58 $
    @author pretz

    @todo

*/

#include "test/tut.h"

#include "dataclasses/I3F2KRecoTrack.h"
#include "TFile.h"
#include "TTree.h"
#include "TClass.h"
#include <string>
using std::string;
using std::cout;
using std::endl;

namespace tut
{
  struct I3F2KRecoTrackTest
  {
    I3F2KRecoTrack fTrack;
    I3F2KRecoTrackTest() { }
    virtual ~I3F2KRecoTrackTest() { }
  };
    
  typedef test_group<I3F2KRecoTrackTest> factory;

  typedef factory::object object;
}

namespace
{
  tut::factory t("I3F2KRecoTrackTest");
}

namespace tut
{
#if 0
  // testing writing to a tree
  template<> template<>
  void object::test<1>() // dont need to start with 1
  {
    //TDS FIXME: have to use T* boost::shared_ptr<T>::get() to get the 
    //raw pointers out (because you need the raw pointer to Branch() and Fill()
    I3F2KRecoTrackPtr track(&fTrack);
    TTree tree;
    tree.Branch("branch","I3F2KRecoTrack",&track);
    fTrack.SetStartX(9.5);
    tree.Fill();
    I3F2KRecoTrack track_out_obj;
    I3F2KRecoTrackPtr track_out = &track_out_obj;
    tree.SetBranchAddress("branch",&track_out);
    tree.GetEvent(0);
    ensure(track_out_obj.GetStartX() == 9.5);

  }

  // testing writing to a file
  template<> template<>
  void object::test<2>()
  {

    I3F2KRecoTrackPtr track = &fTrack;
    track->SetStartX(9.5);

    TFile file("test.out.root","RECREATE");
    fTrack.Write();
    file.Close();
    
    TFile file_in("test.out.root");

    TObject* object_out = file_in.FindObjectAny("I3F2KRecoTrack");    
    ensure("Can't find the object in the file",object_out);

    I3F2KRecoTrackPtr track_in = 
      dynamic_cast<I3F2KRecoTrackPtr>(object_out);

    ensure("dynamic cast fails",track_in != 0);
    
    ensure("the read-in data isn't right",track_in->GetStartX() == 9.5);

    delete track_in;
    track_in = 0;
  }

  // testing simple getting and setting
  template<> template<>
  void object::test<3>() 
  {
    fTrack.SetStartX(1.3);
    ensure(fTrack.GetX() == 1.3);
    ensure(fTrack.GetStartX() == 1.3);
  }

  // testing return;  ... I"m pretty sure it works.
  template<> template<>
  void object::test<4>()
  {
    return;
  }

#endif
}
