/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResultSingleTrack.h,v 1.10 2004/04/27 13:35:23 pretz Exp $
 *
 * @file I3RecoResultSingleTrack.h
 * @version $Revision: 1.10 $
 * @date $Date: 2004/04/27 13:35:23 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */

#ifndef I3RECORESULTSINGLETRACK_H
#define I3RECORESULTSINGLETRACK_H

#include "I3DataExecution.h"
#include "I3RecoResult.h"
#include "I3Particle.h"

/**
 * @brief This is a reco result which just contains a single track
 */
class I3RecoResultSingleTrack : public I3RecoResult
{
  I3ParticlePtr fTrack;
  
  public:
  /**
   * constructor
   */
  I3RecoResultSingleTrack() {fTrack=NULL;}

  /**
   * destructor
   */
  virtual ~I3RecoResultSingleTrack() {if(fTrack) {delete fTrack;}}

  /**
   * Retrieves the track in this reco result as a constant object
   */
  const I3Particle& Track() const 
  {
    if(fTrack) return (*fTrack);
    I3DataExecution::Instance().Fatal("I3RecoResultSingleTrack::Track() asked for a track which doesn't exist");
    return(*(I3ParticlePtr)NULL);
  }

  /**
   * Retrieves the track of this solution as a non-const object
   */
  I3Particle& Track()
  {
    if(fTrack) return (*fTrack);
    I3DataExecution::Instance().Fatal("I3RecoResultSingleTrack::Track() asked for a track which doesn't exist");
    return(*(I3ParticlePtr)NULL);
  }

  bool HasTrack() const {return((fTrack==NULL) ? false : true);}
  
  void SetTrack(I3ParticlePtr fTrack_)
  {
    if(fTrack)
    {
      I3DataExecution::Instance().Fatal("I3RecoResultSingleTrack::Track() track exists already");
      return;
    }
    fTrack=fTrack_;
  }

  
  
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
