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
  int om;
};

ostream& operator<<(ostream &s, const Hit& h) 
{
  s << "[Hit x:" << h.x << " y:" << h.y << " z:" << h.z 
    << " t:" << h.t << " om:" << h.om << "]";
  return s;
}

struct OMCleaner
{
  vector<int> noisy_oms;
  OMCleaner (vector<int> theoms)
  {
    noisy_oms=theoms;
  }
  bool operator()(const Hit &h) 
  {
    vector<int>::iterator iter;
    iter = find(noisy_oms.begin(), noisy_oms.end(), h.om);
    if (iter != noisy_oms.end())
      return true;
    else
      return false;
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
      hits[i].om = rand() % 1000;
    }

  cout << "UNSORTED:" << endl;
  copy(hits.begin(), hits.end(), ostream_iterator<Hit>(cout, "\n"));

  vector<int> noisyoms(1000);
  for (int i=0; i<noisyoms.size(); i++)
    noisyoms[i] = i*2;

  OMCleaner omcleaner(noisyoms);

  vector<Hit>::iterator new_end = remove_if(hits.begin(), 
					    hits.end(), 
					    omcleaner);
  hits.erase(new_end, hits.end());

  cout << "NOT NOISY (om number not even)" << endl;
  copy(hits.begin(), hits.end(), ostream_iterator<Hit>(cout, "\n"));

}
