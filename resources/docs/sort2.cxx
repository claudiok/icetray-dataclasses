#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;

struct Hit
{
  float x, y, z, t;
};

// this gets called when you do "cout << myhit"
ostream& 
operator<< (ostream &s, const Hit& h) 
{
  s << "[Hit x:" << h.x << " y:" << h.y << " z:" << h.z << " t:" << h.t << "]";
  return s;
}

bool operator<(const Hit& left, const Hit& right)
{
  return left.t < right.t;
}

int main (void) 
{
  int i;

  vector<Hit> hits(12);

  for (i=0; i<hits.size(); i++)
    {
      hits[i].t = rand()%1000;
    }

  printf("UNSORTED:\n");

  copy(hits.begin(), hits.end(), ostream_iterator<Hit>(cout, "\n"));

  sort(hits.begin(), hits.end());

  printf("SORTED:\n");

  copy(hits.begin(), hits.end(), ostream_iterator<Hit>(cout, "\n"));

}
