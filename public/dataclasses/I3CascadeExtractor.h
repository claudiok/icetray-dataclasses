/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3CascadeExtractor.h,v 1.3 2004/07/01 01:31:06 pretz Exp $
 *
 * @file I3CascadeExtractor.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/07/01 01:31:06 $
 * @author pretz
 */
#include "dataclasses/I3MCParticleVect.h"
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

