{
gSystem->Load("libPhysics.so");
gSystem->Load("libicetray.so");
gSystem->Load("libdataclasses.so");
gSystem->Load("libroot-icetray.so");
using namespace I3Units;

cout <<"Creating I3Direction..."<<endl;
I3Direction dir;
cout <<"--------------------------------"<<endl;

cout <<"Setting dir: zen=(180-54.74)deg, azi=-135deg (i.e. 1,1,1)..."<<endl;
dir.SetDirection((180-54.73561)*deg, -135*deg);
cout <<"dir's zen,azi: "<<dir.GetZenith()/deg<<" "<<dir.GetAzimuth()/deg<<"\n";
cout <<"==> dir's x,y,z: "<<dir.GetX()<<" "<<dir.GetY()<<" "<<dir.GetZ()<<"\n";
cout <<endl;

cout <<"Setting dir: x=1,y=1,z=0..."<<endl;
dir.SetDirection(1,1,0);
cout <<"dir's x,y,z: "<<dir.GetX()<<" "<<dir.GetY()<<" "<<dir.GetZ()<<"\n";
cout <<"==> dir's zen,azi: "<<dir.GetZenith()/deg<<" "<<dir.GetAzimuth()/deg<<"\n";
cout <<endl;

cout <<"Setting values for dir in zen=0,azi=0 (i.e. down)..."<<endl;
dir.SetDirection(0,0);
cout <<"dir's zen,azi: "<<dir.GetZenith()/deg<<" "<<dir.GetAzimuth()/deg<<"\n";
cout <<"==> dir's x,y,z: "<<dir.GetX()<<" "<<dir.GetY()<<" "<<dir.GetZ()<<"\n";
cout <<endl;

cout <<"Rotating direction around x-axis by +90deg... ==> +y-axis"<<endl;
dir.RotateX(90*deg);
cout <<"==> dir's x,y,z: "<<dir.GetX()<<" "<<dir.GetY()<<" "<<dir.GetZ()<<"\n";
cout <<"==> dir's zen,azi: "<<dir.GetZenith()/deg<<" "<<dir.GetAzimuth()/deg<<"\n";
cout <<endl;

cout <<"Rotating direction around z-axis by -45deg... ==> x=1,y=1,z=0"<<endl;
dir.RotateZ(-45*deg);
cout <<"==> dir's x,y,z: "<<dir.GetX()<<" "<<dir.GetY()<<" "<<dir.GetZ()<<"\n";
cout <<"==> dir's zen,azi: "<<dir.GetZenith()/deg<<" "<<dir.GetAzimuth()/deg<<"\n";
cout <<endl;

cout <<"Rotating direction around y-axis by -90deg... ==> x=0,y=1,z=1"<<endl;
dir.RotateY(-90*deg);
cout <<"==> dir's x,y,z: "<<dir.GetX()<<" "<<dir.GetY()<<" "<<dir.GetZ()<<"\n";
cout <<"==> dir's zen,azi: "<<dir.GetZenith()/deg<<" "<<dir.GetAzimuth()/deg<<"\n";
cout <<endl;


}
