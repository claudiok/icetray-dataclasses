{
gSystem->Load("libPhysics.so");
gSystem->Load("libicetray.so");
gSystem->Load("libdataclasses.so");
gSystem->Load("libroot-icetray.so");

cout <<"Creating I3Direction..."<<endl;
I3Direction dir;

cout <<"Setting values for dir in zen=0,azi=0..."<<endl;
dir.SetDirection(0,0);

cout <<"dir's x,y,z: "<<dir.GetX()<<" "<<dir.GetY()<<" "<<dir.GetZ()<<"\n";
cout <<"dir's zen,azi: "<<dir.GetZenith()<<" "<<dir.GetAzimuth()<<"\n";
cout <<endl;

cout <<"Setting values for dir in x=1,y=1,z=1..."<<endl;
dir.SetDirection(1,1,1);

cout <<"dir's zen,azi: "<<dir.GetZenith()<<" "<<dir.GetAzimuth()<<"\n";
cout <<"dir's x,y,z: "<<dir.GetX()<<" "<<dir.GetY()<<" "<<dir.GetZ()<<"\n";
cout <<endl;

cout <<"Setting values for dir in zen,azi..."<<endl;
dir.SetDirection(-0.955317, -0.785398);

cout <<"dir's x,y,z: "<<dir.GetX()<<" "<<dir.GetY()<<" "<<dir.GetZ()<<"\n";
cout <<"dir's zen,azi: "<<dir.GetZenith()<<" "<<dir.GetAzimuth()<<"\n";
cout <<endl;

cout <<"Rotating direction around 

}
