/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCTrackEvent.h,v 1.5 2004/05/04 17:56:38 pretz Exp $
 *
 * @file I3MCTrackEvent.h
 * @version $Revision: 1.5 $
 * @date $Date: 2004/05/04 17:56:38 $
 * @author pretz
 *
 */

#ifndef I3MCTRACKEVENT_H
#define I3MCTRACKEVENT_H

#include "dataclasses/I3MCPrimary.h"
#include "dataclasses/I3MCTrackList.h"
#include "dataclasses/StoragePolicy.h"

/**
 * @brief A set of causely-related MC Tracks. 
 *
 * The stuff at the surface, and the stuff in the ice
 * @todo work out how the copy and assignment can be private.
 */
class I3MCTrackEvent : public TObject 
{

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
/*   I3MCTrackEvent(const I3MCTrackEvent&){} */
/*   const I3MCTrackEvent& operator=(const I3MCTrackEvent&); */

  ClassDef(I3MCTrackEvent,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3MCTrackEvent>::ThePolicy I3MCTrackEventPtr;

#endif //I3MCTRACKEVENT_H
