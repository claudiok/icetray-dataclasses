/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3TrackTest.cxx,v 1.4 2004/08/16 15:48:50 dule Exp $

    @version $Revision: 1.4 $
    @date $Date: 2004/08/16 15:48:50 $
    @author Troy D. Straszheim

    @todo
*/

#include "TUT/tut.h"

#include "dataclasses/I3Track.h"
#include "dataclasses/I3DoubleBang.h"
#include "dataclasses/I3StartingMuon.h"
#include <string>
using std::string;
using std::cout;
using std::endl;

namespace tut
{
  struct I3TrackTest
  {
  };

  typedef test_group<I3TrackTest> factory;
  typedef factory::object object;
}

namespace
{
  tut::factory t("I3TrackTest");
}

namespace tut
{ 
  /**
   * Check that the basic constructor works...
   */
  void object::test<1>() 
  {
    cout <<"Creating a new I3Starting Track"<<endl;
    I3TrackPtr ptr(new I3StartingMuon);
  }

  void object::test<2>() 
  {
    Double_t pi = 3.14159265358979323846;
    
    cout <<"Creating I3ContainedTrack..."<<endl;
    I3DoubleBang track;

    cout <<"Creating I3Position p..."<<endl;
    I3Position p(1,1,2);

    cout <<"Setting values for track..."<<endl;
    track.SetStartPos(p);
    track.SetStartT(10);
    track.SetZenith(0);    // zenith=0 ==> theta=180 ==> going down
    track.SetAzimuth(0);   // arbitrary for downward going...
    track.SetLength(2);    // track goes only down to the x-y plane

    cout <<"p:"<<endl; p.PrintPosition();
    //cout <<"track:"<<endl; track.PrintTrack();

    cout <<"Calculating track's stop position..."<<endl;
    I3Position q(track.GetStopPos());
    ensure_distance("q.GetX failed",q.GetX(),1.0,0.0001);
    ensure_distance("q.GetY failed",q.GetY(),1.0,0.0001);
    ensure_distance("q.GetZ failed",q.GetZ(),0.0,0.0001);


  }
}
