/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCTrackData.h,v 1.16 2004/02/26 21:04:09 pretz Exp $
 *
 * @version $Revision: 1.16 $
 * @date $Date: 2004/02/26 21:04:09 $
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
#include "dataclasses/I3MCPrimaryData.h"
#include "TObject.h"

class I3MCTrackData : public TObject, public MapPolicy<I3MCTrackList>::ThePolicy
{
  I3MCPrimaryData fPrimaryData;
 public:
  /**
   * constructor
   */
  I3MCTrackData(){}

  /**
   * destructor
   */
  virtual ~I3MCTrackData() {};

  /**
   * @return the list of primaries as a constant object
   */
  const I3MCPrimaryData& MCPrimaryData() const {return fPrimaryData;}

  /**
   * @return the list of primaries as a non-const object
   */
  I3MCPrimaryData& MCPrimaryData() {return fPrimaryData;}

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
