{
gSystem->Load("libPhysics.so");
gSystem->Load("libicetray.so");
gSystem->Load("libdataclasses.so");
gSystem->Load("libroot-icetray.so");

I3Position p(0,4,3);
I3Position q(0,0,0);

// p.SetPosition(1,1,1,I3Position::car);
q.SetPosition(2,2,2,I3Position::car);

Double_t x[10],y[10],z[10],r[10],th[10],ph[10],rh[10];
p.GetPosition(x[1],y[1],z[1],I3Position::car);
cout <<"Position P in car: "<< x[1] <<" "<< y[1] <<" "<< z[1] <<endl;
p.GetPosition(r[1],th[1],ph[1],I3Position::sph);
cout <<"Position P in sph: "<< r[1] <<" "<< th[1]/3.141592*180 <<"^ "<< ph[1]/3.141592*180 <<"^\n";

p.GetPosition(rh[1],ph[1],z[1],I3Position::cyl);
cout <<"Position P in cyl: "<< rh[1] <<" "<< ph[1]/3.141592*180 <<"^ "<< z[1] <<endl;
q.GetPosition(x[2],y[2],z[2],I3Position::car);
cout <<"Position Q in car: "<< x[2] <<" "<< y[2] <<" "<< z[2] <<endl;

cout << "p-q Distance: " << p.CalcDistance(q) <<endl;
cout << "q-p Distance: " << q.CalcDistance(p) <<endl;

p.RotateZ(3.141592/4);
p.GetPosition(x[3],y[3],z[3],I3Position::car);
cout <<"New Position P in car: "<< x[3] <<" "<< y[3] <<" "<< z[3] <<endl;

}
