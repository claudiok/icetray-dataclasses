{
gSystem->Load("libPhysics.so");
gSystem->Load("libicetray.so");
gSystem->Load("libdataclasses.so");
gSystem->Load("libroot-icetray.so");

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
track.SetEnergy(10);

cout <<"p:"<< p.ToString() <<endl;
cout <<"track:"<< track.ToString() ; 
cout <<endl;

}
