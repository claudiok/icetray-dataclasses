#ifndef I3MCTRACKDATA_H
#define I3MCTRACKDATA_H

#include "dataclasses/I3MCTrackEvent.h"
#include "TObject.h"
/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCTrackData.h,v 1.20 2004/03/14 15:07:12 pretz Exp $
 *
 * This is a map of I3MCTrackEvents.  It is supposed to contain all the
 * MC information for the tracks in the Event.  
 *
 * @version $Revision: 1.20 $
 * @date $Date: 2004/03/14 15:07:12 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo 
 *
 */
class I3MCTrackData : public TObject, public MapPolicy<I3MCTrackEvent>::ThePolicy
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
