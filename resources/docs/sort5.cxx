#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;

// here's our hit
struct Hit
{
  float x, y, z, t;
};

// this gets called when you do "cout << myhit"
ostream& operator<<(ostream &s, const Hit& h) 
{
  s << "[Hit x:" << h.x << " y:" << h.y << " z:" << h.z << " t:" << h.t << "]";
  return s;
}

class HitXGreaterThanT
{
public:

  bool operator()(const Hit &h) 
  {
    return h.x > h.t; 
  }
};

int main (void) 
{
  int i;

  vector<Hit> hits(12);

  for (i=0; i<hits.size(); i++)
    {
      hits[i].t = rand() % 1000;
      hits[i].x = rand() % 1000;
    }

  cout << "UNSORTED:" << endl;
  copy(hits.begin(), hits.end(), ostream_iterator<Hit>(cout, "\n"));

  vector<Hit>::iterator new_end = remove_if(hits.begin(), 
					    hits.end(), 
					    HitXGreaterThanT());
  hits.erase(new_end, hits.end());


  cout << "ONLY X <= T:" << endl;
  copy(hits.begin(), hits.end(), ostream_iterator<Hit>(cout, "\n"));

}
