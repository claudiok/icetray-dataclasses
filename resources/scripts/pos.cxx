{
gSystem->Load("libPhysics.so");
gSystem->Load("libicetray.so");
gSystem->Load("libdataclasses.so");
gSystem->Load("libroot-icetray.so");

cout <<"Creating positions p(4,3,0) and q(1,2,3)..."<<endl;
I3Position p(4,3,0);
//    I3PositionPtr q_ptr(new I3Position(1,2,3));
I3Position q(1,2,3);

// p.SetPosition(1,1,1,I3Position::car);
cout <<"Setting position q to: 2,2,2 in car..."<<endl;
q.SetPosition(2,2,2,I3Position::car);

cout <<"Position p.X (4): "<<p.GetX()<<endl;
cout <<"Position p.Y (3): "<<p.GetY()<<endl;
cout <<"Position p.Z (0): "<<p.GetZ()<<endl;
cout <<"Position p.R (5): "<<p.GetR()<<endl;
cout <<"Position p.Theta (1.5708): "<<p.GetTheta()<<endl;
cout <<"Position p.Phi (0.6435): "<<p.GetPhi()<<endl;
cout <<"Position p.Rho (5): "<<p.GetRho()<<endl;
cout <<endl;

cout <<"Position q.X (2): "<<q.GetX()<<endl;
cout <<"Position q.Y (2): "<<q.GetY()<<endl;
cout <<"Position q.Z (2): "<<q.GetZ()<<endl;
cout <<endl;

cout << "p-q Distance (3): "<<p.CalcDistance(q)<<endl;
cout << "q-p Distance (3): "<<q.CalcDistance(p)<<endl;
cout <<endl;

cout <<"Rotating P by Pi/4 around z-axis..."<<endl;
p.RotateZ(3.141592/4);
cout <<"Rotated position p.X (0.707108): "<<p.GetX()<<endl;
cout <<"Rotated position p.Y (4.94975): "<<p.GetY()<<endl;
cout <<"Rotated position p.Z (0): "<<p.GetZ()<<endl;
cout <<endl;

cout <<"Rotating P by Pi/2 around y-axis..."<<endl;
p.RotateY(3.141592/2);
cout <<"Rotated position p.X (0): "<<p.GetX()<<endl;
cout <<"Rotated position p.Y (4.94975): "<<p.GetY()<<endl;
cout <<"Rotated position p.Z (-0.707108): "<<p.GetZ()<<endl;
cout <<endl;

cout <<"Rotating P by Pi/2 around x-axis..."<<endl;
p.RotateX(3.141592/2);
cout <<"Rotated position p.X (0): "<<p.GetX()<<endl;
cout <<"Rotated position p.Y (0.707108): "<<p.GetY()<<endl;
cout <<"Rotated position p.Z (4.94975): "<<p.GetZ()<<endl;
cout <<endl;

cout <<"Creating a new position (s) and setting coordinates in sph..."<<endl;
I3Position s;
s.SetPosition(1.732050808,0.955316618,3.141592/4,I3Position::sph);
cout <<"Position s.X (1): "<<s.GetX()<<endl;
cout <<"Position s.Y (1): "<<s.GetY()<<endl;
cout <<"Position s.Z (1): "<<s.GetZ()<<endl;
cout <<endl;

cout <<"Creating position d and setting coordinates in car..."<<endl;
I3Position d(1,1,1);
cout <<d.GetR()<<" "<<d.GetTheta()<<endl;
cout <<endl;

cout <<"Creating position f from position d..."<<endl;
I3Position f(d);
cout <<f.GetR()<<" "<<f.GetTheta()<<endl;
cout <<endl;

}
