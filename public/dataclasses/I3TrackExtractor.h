#ifndef I3TRACK_EXTRACTOR_H
#define I3TRACK_EXTRACTOR_H
/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TrackExtractor.h,v 1.7 2004/11/17 23:36:42 ehrlich Exp $
 *
 * @file I3TrackExtractor.h
 * @version $Revision: 1.7 $
 * @date $Date: 2004/11/17 23:36:42 $
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

  // default constructor declared private
  I3TrackExtractor();
  public:
  /**
   * constructor.  
   * @param tracklist_to_fill the vector that you want to fill with tracks
   */
  I3TrackExtractor(vector<I3TrackPtr> &tracklist_to_fill); 

  /**
   * the operator that actualy does the extraction
   * @param p an InIceParticlePtr that you want that you want the 
   * extractor to decide whether or not it's a track
   */
  void operator()(I3InIceParticlePtr p);

};
#endif
