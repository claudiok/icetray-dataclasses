/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCTrackData.h,v 1.21 2004/04/27 02:32:05 pretz Exp $
 *
 * @file I3MCTrackData.h
 * @version $Revision: 1.21 $
 * @date $Date: 2004/04/27 02:32:05 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3MCTRACKDATA_H
#define I3MCTRACKDATA_H

#include "dataclasses/I3MCTrackEvent.h"
#include "TObject.h"

/**
 * @brief This is a map of I3MCTrackEvents.  
 *
 * It is supposed to contain all the
 * MC information for the tracks in the Event.  
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
