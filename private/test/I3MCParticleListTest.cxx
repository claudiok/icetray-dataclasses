/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MCParticleListTest.cxx,v 1.1 2004/05/05 19:34:54 pretz Exp $

    @version $Revision: 1.1 $
    @date $Date: 2004/05/05 19:34:54 $
    @author pretz

    @todo

*/

#include "test/tut.h"

#include "dataclasses/I3MCParticleList.h"
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
  struct I3MCParticleListTest
  {
    I3MCParticleList fParticles;
  };

  typedef test_group<I3MCParticleListTest> factory;
  typedef factory::object object;
}

namespace
{
  tut::factory t("I3MCParticleListTest");
}

namespace tut
{
  // testing the 'Track' extractor
  template<> template<>
  void object::test<1>()
  {
    fParticles.push_back(new I3MCTrack());
    fParticles.push_back(new I3MCCascade());
    fParticles.push_back(new I3MCTrack());
    fParticles.push_back(new I3F2KRecoTrack());


    vector<I3TrackPtr> the_tracks;
    I3TrackExtractor extractor(the_tracks);
    for_each(fParticles.begin(),fParticles.end(),extractor);
    ensure("right size for the extraced list",the_tracks.size() == 3);

  }

  void object::test<2>()
  {
    fParticles.push_back(new I3MCTrack());
    fParticles.push_back(new I3MCCascade());
    fParticles.push_back(new I3MCCascade());

    vector<I3CascadePtr> the_cascades;
    I3CascadeExtractor extractor(the_cascades);

    for_each(fParticles.begin(),fParticles.end(),extractor);
    ensure("right size for extracted list",the_cascades.size() == 2);


  }
}

