/**
    copyright (c) 2004
    troy d. straszheim
    troy@resophonic.com
    http://www.resophonic.com
*/

#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

class Particle
{
public:
  string name;
  double mass;
};

ostream& operator<< (ostream& o, const Particle &particle)
{
  o << "[Particle name=" << particle.name << "\tmass=" << particle.mass << "]";
  return o;
}

main()
{
  Particle electron, tau;
  electron.name = "Electron";
  electron.mass = 0.000511;
  tau.name = "Tau";
  tau.mass = 1.777;
  cout << "The electron says: " << electron << endl 
       << " and the tau says: " << tau << endl;
}

