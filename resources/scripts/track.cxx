// #include "dataclasses/I3StartingTrack.h"
// #include "dataclasses/I3TrackImpl.h"
// #include "dataclasses/I3Starting.h"
// #include "dataclasses/I3NonEnergetic.h"
// #include "dataclasses/I3NonComposite.h"
{
gSystem->Load("libPhysics.so");
gSystem->Load("libicetray.so");
gSystem->Load("libdataclasses.so");
gSystem->Load("libroot-icetray.so");

  Double_t pi = 3.14159265358979323846;
  I3StartingTrack track;
  //  I3BasicTrack track2;
  I3StartingTrack track2;
  I3Position p(4,3,0);
  I3Position q;
  I3Position g(0,0,0);

  p.SetPosition(1,1,1,I3Position::car);
  q.SetPosition(2,2,2,I3Position::car);
  I3Position p2 = p;
  cout <<"p2: "<<endl;p2.PrintPosition();

  track.StartPos(p);
  track.StartT(10);
  track.Zenith(0.23);
  track.Azimuth(0.45);

  //  track2.Pos(-1,-1,-1,I3Position::car);
  track2.Pos(p);
  track2.Zenith(pi); // going down (-z)
  track2.Azimuth(0); // going along x-axis (+x)

  cout <<"track:"<<endl; track.PrintTrack();
  cout <<"p:"<<endl; p.PrintPosition();
  cout <<"q:"<<endl; q.PrintPosition();
  cout <<"track2:"<<endl; track2.PrintTrack();
  cout <<"g:"<<endl; g.PrintPosition();

  Double_t d = I3Distance::Distance(&track, q);
  cout <<"distance track,q: "<< d <<endl;

//------------
  I3Position T(track2.Pos());
  Double_t zenith = track2.Zenith();
  Double_t azimuth = track2.Azimuth();
  I3Position P(g);

  Double_t PT = P.CalcDistance(T);
  cout <<"PT "<< PT <<endl;
  P.Translate(T);
  P.RotateZ(-azimuth);
  P.RotateY(pi/2-zenith);
  Double_t TA = P.X();
  cout <<"TA "<< TA <<endl;
  Double_t PA = sqrt(PT*PT-TA*TA);
  cout <<"PA "<< PA <<endl;

  I3Position pos, cpos;
  Double_t dist, ctime;
  cout << "before ClosestApproach"<<endl;
  I3Distance::ClosestApproach(&track2,g,pos,dist,cpos,ctime,54.736*I3Units::degree);
  cout <<"closest approach distance track2,g: "<< dist <<endl;
  cout <<"point of cl.ap. track2,g: "<<endl;
  pos.PrintPosition();
  cout <<"Cherenkov time from track2 to point g: "<< ctime <<endl;
  cout <<"point of Cherenkov origin on track2: "<<endl;
  cpos.PrintPosition();

  

//---------------------------
  p.SetPosition(-1,-1,-1,I3Position::car);
  if (I3Distance::IsOnTrack(&track2,p)) cout <<"YES"<<endl;
  else cout <<"NO"<<endl;

//---------------------------

}
