#include "dataclasses/I3TrackExtractor.h"

#include <iostream>
using namespace std;

I3TrackExtractor::I3TrackExtractor(vector<I3TrackPtr> &tracklist_to_fill) 
  : mytracks(tracklist_to_fill) { };

void I3TrackExtractor::operator() (I3ObservableParticlePtr p) 
{
  I3TrackPtr track = dynamic_cast<I3TrackPtr>(p);

  if (track) 
    mytracks.push_back(track);
}



