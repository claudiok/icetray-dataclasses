/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TrackExtractor.h,v 1.5 2004/08/02 19:59:58 blaufuss Exp $
 *
 * @file I3TrackExtractor.h
 * @version $Revision: 1.5 $
 * @date $Date: 2004/08/02 19:59:58 $
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

  void operator()(I3InIceParticlePtr p);

};

