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
  //  I3BasicTrack t2;
  I3StartingTrack t2;
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

  //  t2.Pos(-1,-1,-1,I3Position::car);
  t2.Pos(p);
  t2.Zenith(pi); // going down (-z)
  t2.Azimuth(0); // going along x-axis (+x)

  cout <<"track:"<<endl; track.PrintTrack();
  cout <<"p:"<<endl; p.PrintPosition();
  cout <<"q:"<<endl; q.PrintPosition();
  cout <<"t2:"<<endl; t2.PrintTrack();
  cout <<"g:"<<endl; g.PrintPosition();

  Double_t d = I3Distance::Distance(&track, q);
  cout <<"distance track,q: "<< d <<endl;

//------------
  I3Position T(t2.Pos());
  Double_t zenith = t2.Zenith();
  Double_t azimuth = t2.Azimuth();
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

  I3Position pos;
  Double_t dist;
  Bool_t isontrack;
  I3Distance::ClosestApproach(&t2,g,pos,dist,isontrack);
  cout <<" "<<isontrack<<" "<<endl;
  cout <<"closest approach distance t2,g: "<< dist <<endl;
  cout <<"point of cl.ap. t2,g: "<<endl;
  pos.PrintPosition();
  cout <<"is point on track t2,g: ";
  if (isontrack) cout << "YES\n";
  else cout << "NO\n";

//---------------------------
  p.SetPosition(-1,-1,-1,I3Position::car);
  if (I3Distance::IsOnTrack(&t2,p)) cout <<"YES"<<endl;
  else cout <<"NO"<<endl;

//---------------------------

}
