/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCTrackData.h,v 1.15 2004/02/26 03:51:13 pretz Exp $
 *
 * @version $Revision: 1.15 $
 * @date $Date: 2004/02/26 03:51:13 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo include the primary track as a separate object
 *
 */
#ifndef I3MCTRACKDATA_H
#define I3MCTRACKDATA_H

#include "dataclasses/I3MCTrackList.h"
#include "TObject.h"

class I3MCTrackData : public TObject, public MapPolicy<I3MCTrackList>::ThePolicy
{
 public:
  /**
   * constructor
   */
  I3MCTrackData(){}

  /**
   * destructor
   */
  virtual ~I3MCTrackData() {};
 private:
  // copy and assignment private
  I3MCTrackData(const I3MCTrackData& rhs);
  const I3MCTrackData& operator=(const I3MCTrackData& rhs);

  // ROOT macro
  ClassDef(I3MCTrackData,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3MCTrackData>::ThePolicy I3MCTrackDataPtr;

#endif
