#ifndef I3MCTRACKEVENT_H
#define I3MCTRACKEVENT_H

#include "dataclasses/I3MCPrimary.h"
#include "dataclasses/I3MCTrackList.h"
#include "dataclasses/StoragePolicy.h"

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCTrackEvent.h,v 1.1 2004/03/09 17:54:24 pretz Exp $
 *
 * @version $Revision: 1.1 $
 * @date $Date: 2004/03/09 17:54:24 $
 * @author pretz
 *
 * @todo 
 *
 */
class I3MCTrackEvent : public TObject{
  I3MCPrimary fPrimary;
  I3MCTrackList fInIceTracks;
  I3MCTrackList fIceTopTracks;
 public:
  /**
   * constructor
   */
  I3MCTrackEvent(){}

  /**
   * destructor
   */
  virtual ~I3MCTrackEvent(){}
  
  /**
   * @return the primary track as constant
   */
  const I3MCPrimary& Primary() const {return fPrimary;}

  /**
   * @return the primary track as non-const
   */
  I3MCPrimary& Primary() {return fPrimary;}

  /**
   * @return the In-Ice tracks as constant
   */
  const I3MCTrackList& InIceTracks() const {return fInIceTracks;}

  /**
   * @return the In-Ice tracks as non-constant
   */
  I3MCTrackList& InIceTracks() {return fInIceTracks;}

  /**
   * @return the IceTop tracks as constant
   */
  const I3MCTrackList& IceTopTracks() const {return fIceTopTracks;}

  /**
   * @return the IceTop tracks as non-constant
   */
  I3MCTrackList& IceTopTracks() {return fIceTopTracks;};

 private:
  // copy and assignment are private
  I3MCTrackEvent(const I3MCTrackEvent&){}
  const I3MCTrackEvent& operator=(const I3MCTrackEvent&);

  ClassDef(I3MCTrackEvent,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3MCTrackEvent>::ThePolicy I3MCTrackEventPtr;

#endif //I3MCTRACKEVENT_H
