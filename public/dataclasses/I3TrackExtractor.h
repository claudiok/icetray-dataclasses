/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TrackExtractor.h,v 1.4 2004/07/26 23:39:10 ehrlich Exp $
 *
 * @file I3TrackExtractor.h
 * @version $Revision: 1.4 $
 * @date $Date: 2004/07/26 23:39:10 $
 * @author pretz
 */
//#include "dataclasses/I3MCParticleVect.h"
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

