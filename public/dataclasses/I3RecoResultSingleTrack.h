/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResultSingleTrack.h,v 1.12 2004/07/28 19:10:34 ehrlich Exp $
 *
 * @file I3RecoResultSingleTrack.h
 * @version $Revision: 1.12 $
 * @date $Date: 2004/07/28 19:10:34 $
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
  
  // TDS FIXME most of this has/get/set stuff can go away.  You just
  // get the pointer out, it either points to something valid or it
  // points to nothing.

  public:
  /**
   * constructor
   */
  I3RecoResultSingleTrack() {fTrack=NULL;}

  /**
   * destructor
   */
  virtual ~I3RecoResultSingleTrack() {}

  /**
   * Retrieves the track in this reco result as a constant object
   */
  const I3ParticlePtr GetTrack() const 
  {
    if (fTrack) 
      return (fTrack);

    I3DataExecution::Instance().Fatal("I3RecoResultSingleTrack::Track() asked for a track which doesn't exist");
    return I3ParticlePtr();
  }

  /**
   * Retrieves the track of this solution as a non-const object
   */
  I3ParticlePtr GetTrack()
  {
    if (fTrack) 
      return fTrack;

    I3DataExecution::Instance().Fatal("I3RecoResultSingleTrack::Track() asked for a track which doesn't exist");
    return I3ParticlePtr();
  }

  bool HasTrack() const {
    //TDS: the smart pointer automagically converts to bool
    return fTrack;
  }
  
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
