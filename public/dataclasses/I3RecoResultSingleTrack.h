/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResultSingleTrack.h,v 1.5 2004/02/25 21:36:49 pretz Exp $
 *
 * This is a reco result which just contains a single track
 *
 * @version $Revision: 1.5 $
 * @date $Date: 2004/02/25 21:36:49 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo
 *
 */
#ifndef I3RECORESULTSINGLETRACK_H
#define I3RECORESULTSINGLETRACK_H

#include "I3RecoResult.h"

class I3RecoResultSingleTrack : public I3RecoResult
{
  public:
  /**
   * constructor
   */
  I3RecoResultSingleTrack() {;}

  /**
   * destructor
   */
  virtual ~I3RecoResultSingleTrack(){}

  /**
   * operator[]
   * @todo won't this conflict with the operator[] from the base class?
   */
  const I3RecoTrack& operator[](unsigned short tracklistindex) const;
  
 private:
  // copy and assignment are private
  I3RecoResultSingleTrack(const I3RecoResultSingleTrack& rhs);
  const I3RecoResultSingleTrack& operator=(const I3RecoResultSingleTrack&);

  // ROOT macro
  ClassDef(I3RecoResultSingleTrack, 1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RecoResultSingleTrack>::ThePolicy I3RecoResultSingleTrackPtr;

#endif
