#include "dataclasses/hashtest.h"
#include "dataclasses/TestHash.h"

#include <iostream>
using namespace std;

void hashtest()
{

  I3TestHash hash;

  I3MCHit hit;

  hit.Weight(1.1);
  hash["first"] = hit;
  hit.Weight(2.1);
  hash["second"] = hit;
  hit.Weight(3.1);
  hash["third"] = hit;

  cout << "first: " << hash["first"].Weight() << endl;
  cout << "second: " << hash["second"].Weight() << endl;
  cout << "third: " << hash["third"].Weight() << endl;

}

