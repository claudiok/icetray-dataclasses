/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MCParticleVectTest.cxx,v 1.3 2004/07/04 06:03:32 troy Exp $

    @version $Revision: 1.3 $
    @date $Date: 2004/07/04 06:03:32 $
    @author pretz

    @todo

*/

#include "test/tut.h"

#include "dataclasses/I3MCParticleVect.h"
#include "dataclasses/I3TrackExtractor.h"
#include "dataclasses/I3MCTrack.h"
#include "dataclasses/I3MCCascade.h"
#include "dataclasses/I3F2KRecoTrack.h"
#include "dataclasses/I3CascadeExtractor.h"
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;

namespace tut
{
  struct I3MCParticleVectTest
  {
  };

  typedef test_group<I3MCParticleVectTest> factory;
  typedef factory::object object;
}

namespace
{
  tut::factory t("I3MCParticleVectTest");
}

namespace tut
{
  // testing the 'Track' extractor
  template<> template<>
  void object::test<1>()
  {
    I3MCParticleVect fParticles;

    fParticles.push_back(I3MCTrackPtr(new I3MCTrack));
    fParticles.push_back(I3MCCascadePtr(new I3MCCascade()));
    fParticles.push_back(I3MCTrackPtr(new I3MCTrack));
    fParticles.push_back(I3F2KRecoTrackPtr(new I3F2KRecoTrack));


    vector<I3TrackPtr> the_tracks;
    I3TrackExtractor extractor(the_tracks);
    for_each(fParticles.begin(),fParticles.end(),extractor);
    ensure("right size for the extraced list",the_tracks.size() == 3);

  }

  void object::test<2>()
  {
    I3MCParticleVect fParticles;

    fParticles.push_back(I3MCTrackPtr(new I3MCTrack));
    fParticles.push_back(I3MCCascadePtr(new I3MCCascade));
    fParticles.push_back(I3MCCascadePtr(new I3MCCascade));

    vector<I3CascadePtr> the_cascades;
    I3CascadeExtractor extractor(the_cascades);

    for_each(fParticles.begin(),fParticles.end(),extractor);
    ensure("right size for extracted list",the_cascades.size() == 2);
  }
}

