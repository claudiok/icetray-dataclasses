#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Hit
{
  float x, y, z, t;
};

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
      hits[i].t = rand() % 1000;
    }

  printf("UNSORTED:\n");

  for (i=0; i<hits.size(); i++)
    printf("Hit, t=%f\n", hits[i].t);

  sort(hits.begin(), hits.end());

  printf("SORTED:\n");

  for (i=0; i<hits.size(); i++)
    printf("Hit, t=%f\n", hits[i].t);

}
