/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3CascadeExtractor.h,v 1.5 2004/08/01 00:41:01 pretz Exp $
 *
 * @file I3CascadeExtractor.h
 * @version $Revision: 1.5 $
 * @date $Date: 2004/08/01 00:41:01 $
 * @author pretz
 */
//#include "dataclasses/I3MCParticleVect.h"
#include "dataclasses/I3Cascade.h"

/**
 * @brief An example extractor classes which can get cascades out of an
 * ObsCascadeList in a type-safe way
 */
class I3CascadeExtractor
{
  vector<I3CascadePtr> &mytracks;

  // default constructor private
  I3CascadeExtractor();

  public:
  /**
   * creates the extractor with a specific vector<I3CascadePtr> which
   * is to be filled when the extractor is used
   * @param tracklist_to_fill is the vector that will be extracted into.
   */ 
  I3CascadeExtractor(vector<I3CascadePtr> &tracklist_to_fill); 

  /**
   * the operator that will do the extraction
   */
  void operator()(I3ObservableParticlePtr p);

};

