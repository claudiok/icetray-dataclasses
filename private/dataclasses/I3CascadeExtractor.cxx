#include "dataclasses/I3CascadeExtractor.h"

#include <iostream>
using namespace std;

I3CascadeExtractor::I3CascadeExtractor(vector<I3CascadePtr> &tracklist_to_fill) 
  : mytracks(tracklist_to_fill) { };

void I3CascadeExtractor::operator() (I3ObservableParticlePtr p) 
{
  I3CascadePtr track = boost::dynamic_pointer_cast<I3Cascade>(p);

  if (track) 
    mytracks.push_back(track);
}



