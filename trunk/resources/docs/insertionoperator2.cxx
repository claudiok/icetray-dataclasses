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

ostream& operator<< (ostream& o, const Particle &p)
{
  o << "[Particle name=" << p.name << " mass=" << p.mass << "]";
  return o;
}

class Event
{
public:
  Particle particle;
  float x, y, z;
};

ostream& operator<< (ostream& o, const Event &e) 
{
  o << "[Event x=" << e.x << " y=" << e.y << " z=" << e.z << endl
    << "\t" << e.particle << endl << "]";
  return o;
}

int main()
{
  Particle elephantino;
  elephantino.name = "Elephantino!";
  elephantino.mass = 999999;

  Event event;
  event.x = event.y = event.z = 3.14159;
  event.particle = elephantino;

  cout << "My event looks like this: " 
       << endl << event << endl;

  return 0;
}

