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

// this compares the times
bool operator<(const Hit& left, const Hit& right)
{
  return left.t < right.t;
}

bool compare_x(const Hit& left, const Hit& right)
{
  return left.x < right.x;
}

int main (void) 
{
  int i;

  vector<Hit> hits(12);

  for (i=0; i<hits.size(); i++)
    {
      hits[i].t = rand()%1000;
      hits[i].x = rand()%1000;
    }

  cout << "UNSORTED:" << endl;
  copy(hits.begin(), hits.end(), ostream_iterator<Hit>(cout, "\n"));

  // by default sort uses operator<
  sort(hits.begin(), hits.end());

  cout << "SORTED BY TIME:" << endl;
  copy(hits.begin(), hits.end(), ostream_iterator<Hit>(cout, "\n"));

  // but sort can also take an argument
  sort(hits.begin(), hits.end(), compare_x);

  cout << "SORTED BY X:" << endl;
  copy(hits.begin(), hits.end(), ostream_iterator<Hit>(cout, "\n"));
}
