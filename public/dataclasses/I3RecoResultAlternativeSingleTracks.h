/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoResultAlternativeSingleTracks.h,v 1.1 2004/02/18 21:05:51 deyoung Exp $

    @version $Revision: 1.1 $
    @date $Date: 2004/02/18 21:05:51 $
    @author

    @todo

*/
#ifndef I3RECORESULTALTERNATIVESINGLETRACKS_H
#define I3RECORESULTALTERNATIVESINGLETRACKS_H

#include "I3RecoResult.h"

///Reco result containing several track lists, each with a single track.
/** 
 * Derived RecoResult class for storing the result of a reconstruction that
 * returns several alternative solutions (track lists), each of which contains
 * only one track.  Specific algorithms should derive their own RecoResult
 * classes from this class, specifiying the track type returned and adding any
 * additional algorithm-specific result information.
 */ 
class I3RecoResultAlternativeSingleTracks : public I3RecoResult
{
  public:
  I3RecoResultAlternativeSingleTracks() {;}

  const I3RecoTrack& operator[](unsigned short tracklistindex) const;
  
  ClassDef(I3RecoResultAlternativeSingleTracks, 1);
};
#endif
