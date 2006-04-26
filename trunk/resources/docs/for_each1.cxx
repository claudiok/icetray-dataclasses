/**
    copyright (c) 2004
    troy d. straszheim
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
  double mass;
};

void printPair(const pair<string,Particle>& pr)
{
  cout << "Particle:" << pr.first << " mass:" << pr.second.mass << endl;
}

main()
{
  map<string,Particle> m;

  m["Electron"].mass = 0.000511;
  m["Muon"].mass = 0.1056;
  m["Tau"].mass = 1.777;  
  m["Proton"].mass = 0.938;
  m["Neutron"].mass = 0.940;

  for_each (m.begin(), m.end(), printPair);

}

