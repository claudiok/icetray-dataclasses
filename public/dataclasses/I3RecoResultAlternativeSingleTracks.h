/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResultAlternativeSingleTracks.h,v 1.4 2004/02/26 18:53:12 pretz Exp $
 * Derived RecoResult class for storing the result of a reconstruction that
 * returns several alternative solutions (track lists), each of which contains
 * only one track.  Specific algorithms should derive their own RecoResult
 * classes from this class, specifiying the track type returned and adding any
 * additional algorithm-specific result information.
 *
 * @version $Revision: 1.4 $
 * @date $Date: 2004/02/26 18:53:12 $
 * @brief Reco result containing several track lists, each with a single track
 * @author deyoung
 *
 * @todo
 *
 */
#ifndef I3RECORESULTALTERNATIVESINGLETRACKS_H
#define I3RECORESULTALTERNATIVESINGLETRACKS_H

#include "I3RecoResult.h"

class I3RecoResultAlternativeSingleTracks : public I3RecoResult
{
  public:
  /**
   * constructor
   */ 
  I3RecoResultAlternativeSingleTracks() {;}

  /**
   * destructor
   */
  virtual ~I3RecoResultAlternativeSingleTracks(){};

  /**
   *  operator[] 
   * @todo won't this collide with RecoResult::operator[] which it gets from VectorPolicy<...>::ThePolciy??
   */
  const I3RecoTrack& operator[](UShort_t tracklistindex) const;

 private:
  // copy and assignment are private
  I3RecoResultAlternativeSingleTracks(const I3RecoResultAlternativeSingleTracks&);
  const I3RecoResultAlternativeSingleTracks& operator=
    (const I3RecoResultAlternativeSingleTracks&);

  // ROOT macro
  ClassDef(I3RecoResultAlternativeSingleTracks, 1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RecoResultAlternativeSingleTracks>::ThePolicy I3RecoResultAlternativeSingleTracksPtr;

#endif
