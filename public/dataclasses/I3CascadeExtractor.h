/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3CascadeExtractor.h,v 1.1 2004/05/05 15:20:48 pretz Exp $
 *
 * @file I3CascadeExtractor.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/05/05 15:20:48 $
 * @author pretz
 */
#include "dataclasses/I3ObsParticleList.h"
#include "dataclasses/I3Cascade.h"

/**
 * @brief An example extractor classes which can get cascades out of an
 * ObsCascadeList in a type-safe way
 */
class I3CascadeExtractor
{
  vector<I3CascadePtr> &mytracks;

  I3CascadeExtractor();

  public:

  I3CascadeExtractor(vector<I3CascadePtr> &tracklist_to_fill); 

  void operator()(I3ObservableParticlePtr p);

};

