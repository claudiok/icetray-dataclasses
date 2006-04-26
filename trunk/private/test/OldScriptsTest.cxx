/**
    copyright  (C) 2004
    the icecube collaboration
    $Id$

    @version $Revision: 1.1 $
    @date $Date$
    @author pretz

*/

#include <I3Test.h>

#include "dataclasses/I3Direction.h"
#include "dataclasses/I3Position.h"
#include "dataclasses/physics/I3Particle.h"
#include <string>
using std::string;
using std::cout;
using std::endl;


// used to be scripts hanging around in resources/scripts/
// moved them here since were moving away from root dictionaries.
TEST_GROUP(OldScriptsTest);


  // used to be dir.C
TEST(dir_C)
{
  cout <<"Creating I3Direction..."<<endl;
  I3Direction dir;
  cout <<"--------------------------------"<<endl;
  
  cout <<"Setting dir: zen=(180-54.74)deg, azi=-135deg (i.e. 1,1,1)..."<<endl;
  dir.SetDirection((180-54.73561)*deg, -135*deg);
  cout <<"dir's zen,azi: "<<dir.GetZenith()/deg<<" "<<dir.GetAzimuth()/deg<<"\n";
  cout <<"==> dir's x,y,z: "<<dir.GetX()<<" "<<dir.GetY()<<" "<<dir.GetZ()<<"\n";
  cout <<endl;
  
  cout 
    <<"Setting dir: x=1,y=1,z=0..."
    <<endl;
  dir.SetDirection(1,1,0);
  cout <<"dir's x,y,z: "<<dir.GetX()<<" "<<dir.GetY()<<" "<<dir.GetZ()<<"\n";
  cout <<"==> dir's zen,azi: "<<dir.GetZenith()/deg
       <<" "<<dir.GetAzimuth()/deg<<"\n";
  cout <<endl;
  
  cout <<"Setting values for dir in zen=0,azi=0 (i.e. down)..."<<endl;
  dir.SetDirection(0,0);
  cout <<"dir's zen,azi: "<<dir.GetZenith()/deg<<" "
       <<dir.GetAzimuth()/deg<<"\n";
  cout <<"==> dir's x,y,z: "<<dir.GetX()<<" "<<dir.GetY()<<" "
       <<dir.GetZ()<<"\n";
  cout <<endl;
  
  cout <<"Rotating direction around x-axis by +90deg... ==> +y-axis"<<endl;
  dir.RotateX(90*deg);
  cout <<"==> dir's x,y,z: "<<dir.GetX()<<" "<<dir.GetY()
       <<" "<<dir.GetZ()<<"\n";
  cout <<"==> dir's zen,azi: "<<dir.GetZenith()/deg<<" "
       <<dir.GetAzimuth()/deg<<"\n";
  cout <<endl;
  
  cout <<"Rotating direction around z-axis by -45deg..."
    " ==> x=1,y=1,z=0"<<endl;
  dir.RotateZ(-45*deg);
  cout <<"==> dir's x,y,z: "<<dir.GetX()<<" "<<dir.GetY()
       <<" "<<dir.GetZ()<<"\n";
  cout <<"==> dir's zen,azi: "<<dir.GetZenith()/deg<<" "
       <<dir.GetAzimuth()/deg<<"\n";
  cout <<endl;
  
  cout <<"Rotating direction around y-axis by -90deg..."
    " ==> x=0,y=1,z=1"<<endl;
  dir.RotateY(-90*deg);
  cout <<"==> dir's x,y,z: "<<dir.GetX()<<" "
       <<dir.GetY()<<" "<<dir.GetZ()<<"\n";
  cout <<"==> dir's zen,azi: "<<dir.GetZenith()/deg<<" "
       <<dir.GetAzimuth()/deg<<"\n";
  cout <<endl;
}

  // used to be pos.C
TEST(pos_C)
{
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
  cout <<"Position d.R (1.73205): "<<d.GetR()<<endl;
  cout <<"Position d.Theta (0.955317): "<<d.GetTheta()<<endl;
  cout <<"Position d.Phi (0.785398): "<<d.GetPhi()<<endl;
  cout <<endl;
  
  cout <<"Using the = operator on I3Position e=d..."<<endl;
  I3Position e = d;
  cout <<"Position e.R (1.73205): "<<e.GetR()<<endl;
  cout <<"Position e.Theta (0.955317): "<<e.GetTheta()<<endl;
  cout <<"Position e.Phi (0.785398): "<<e.GetPhi()<<endl;
  cout <<endl;
  
  cout <<"Creating position f from position d..."<<endl;
  I3Position f(d);
  cout <<"Position f.R (1.73205): "<<f.GetR()<<endl;
  cout <<"Position f.Theta (0.955317): "<<f.GetTheta()<<endl;
  cout <<"Position f.Phi (0.785398): "<<f.GetPhi()<<endl;
  cout <<endl;
  
  cout <<"Shifting coordinate system of f by s..."<<endl;
  f.ShiftCoordSystem(s);
  cout <<"Position f.X (0): "<<f.GetX()<<endl;
  cout <<"Position f.Y (0): "<<f.GetY()<<endl;
  cout <<"Position f.Z (0): "<<f.GetZ()<<endl;
  cout <<endl;
  
  cout <<"Shifting coordinate system of f by p..."<<endl;
  f.ShiftCoordSystem(p);
  cout <<"Position f.X (0): "<<f.GetX()<<endl;
  cout <<"Position f.Y (-0.707108): "<<f.GetY()<<endl;
  cout <<"Position f.Z (-4.94975): "<<f.GetZ()<<endl;
  cout <<"Position f.R (5): "<<f.GetR()<<endl;
  cout <<"Position f.Theta (2.9997): "<<f.GetTheta()<<endl;
  cout <<"Position f.Phi (4.71239): "<<f.GetPhi()<<endl;
  cout <<"Position f.Rho (0.707108): "<<f.GetRho()<<endl;
  cout <<endl;
}

  // used to be track.C
TEST(track_C)
{
  I3Particle track;

}

