/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TrackExtractor.h,v 1.3 2004/07/01 01:31:06 pretz Exp $
 *
 * @file I3TrackExtractor.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/07/01 01:31:06 $
 * @author pretz
 */
#include "dataclasses/I3MCParticleVect.h"
#include "dataclasses/I3Track.h"

/**
 * @brief An example extractor classes which can get tracks out of an
 * ObsTrackList in a type-safe way
 */
class I3TrackExtractor
{
  vector<I3TrackPtr> &mytracks;

  I3TrackExtractor();

  public:

  I3TrackExtractor(vector<I3TrackPtr> &tracklist_to_fill); 

  void operator()(I3ObservableParticlePtr p);

};

