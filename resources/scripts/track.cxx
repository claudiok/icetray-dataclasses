{
gSystem->Load("libPhysics.so");
gSystem->Load("libicetray.so");
gSystem->Load("libdataclasses.so");
gSystem->Load("libroot-icetray.so");

cout <<"Creating I3ContainedTrack..."<<endl;
I3DoubleBang track_cont;

cout <<"Creating I3Position p..."<<endl;
I3Position p(1,1,2);

cout <<"Setting values for track..."<<endl;
track.SetStartPos(p);
track.SetStartT(10);
track.SetZenith(0);    // zenith=0 ==> theta=180 ==> going down
track.SetAzimuth(0);   // arbitrary for downward going...
track.SetLength(2);    // track goes only down to the x-y plane

cout <<"p:"<<endl; p.PrintPosition();
cout <<"track:"<<endl; track.PrintTrack();
cout <<endl;

cout <<"Calculating track's stop position..."<<endl;
I3Position q(&track.GetStopPos());
cout <<"Position q.X (1): "<<q.GetX()<<endl;
cout <<"Position q.Y (1): "<<q.GetY()<<endl;
cout <<"Position q.Z (0): "<<q.GetZ()<<endl;
cout <<endl;

}
