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

ostream& operator<<(ostream &s, const Hit& h) 
{
  s << "[Hit x:" << h.x << " y:" << h.y << " z:" << h.z << " t:" << h.t << "]";
  return s;
}

struct HitXGreaterThan
{
  float threshold_;
  HitXGreaterThan (float threshold)
  {
    threshold_ = threshold;
  }
  bool operator()(const Hit &h) 
  {
    return h.x > threshold_; 
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
					    HitXGreaterThan(500));
  hits.erase(new_end, hits.end());

  cout << "ONLY X <= 500" << endl;
  copy(hits.begin(), hits.end(), ostream_iterator<Hit>(cout, "\n"));

}
