#ifndef I3MCTRACKLIST_H
#define I3MCTRACKLIST_H

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCTrackList.h,v 1.12 2004/02/25 20:57:14 pretz Exp $
 *
 * @version $Revision: 1.12 $
 * @date $Date: 2004/02/25 20:57:14 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo
 *
 */

#include "I3MCTrack.h"
#include "StoragePolicy.h"

class I3MCTrackList : public VectorPolicy<I3MCTrack>::ThePolicy
{
 public:
  virtual ~I3MCTrackList(){};
  ClassDef(I3MCTrackList,1);
};

#endif
