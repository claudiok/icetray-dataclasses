/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TrackExtractor.h,v 1.1 2004/05/05 15:20:48 pretz Exp $
 *
 * @file I3TrackExtractor.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/05/05 15:20:48 $
 * @author pretz
 */
#include "dataclasses/I3ObsParticleList.h"
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

