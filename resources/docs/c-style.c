#include <stdio.h>

typedef struct 
{
  float x, y, z, t;
} Hit;


int 
hit_time_comparison (const Hit* left, const Hit* right)
{
  if (left->t < right->t)
    return -1;
  if (left->t == right->t)
    return 0;
  return 1;
}


#define NUMHITS 12
int main (void) 
{
  int i;

  Hit hits[NUMHITS];

  for (i=0; i<NUMHITS; i++)
    {
      hits[i].t = rand();
    }

  printf("UNSORTED:\n");

  for (i=0; i<NUMHITS; i++)
    printf("Hit, t=%f\n", hits[i].t);

  qsort(hits, NUMHITS, sizeof(Hit), hit_time_comparison);

  printf("SORTED:\n");

  for (i=0; i<NUMHITS; i++)
    printf("Hit, t=%f\n", hits[i].t);

}
