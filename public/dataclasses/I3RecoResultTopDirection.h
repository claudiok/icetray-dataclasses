/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResultTopDirection.h,v 1.5 2004/08/05 13:00:21 troy Exp $
 *
 * @file I3RecoResultTopDirection.h
 * @version $Revision: 1.5 $
 * @date $Date: 2004/08/05 13:00:21 $
 * @author Peter Niessen
 */

#ifndef __I3RECORESULTTOPDIRECTION_H_
#define __I3RECORESULTTOPDIRECTION_H_

#include "I3DataExecution.h"
#include "I3RecoResult.h"
#include "I3ShowerDirection.h"

/**
 * @brief This is a reco result which just contains a single shower
 * direction first guess
 */
class I3RecoResultTopDirection : public I3RecoResult
{
  I3ShowerDirectionPtr fShowerDirection;
  
  public:
  /**
   * constructor
   */
  I3RecoResultTopDirection ()  { /* fShowerDirection = NULL; */ }

  /**
   * destructor
   */
  virtual ~I3RecoResultTopDirection() { }

  /**
   * Retrieves the track in this reco result as a constant object
   */
  const I3ShowerDirection& GetShowerDirection () const 
  {
    if(fShowerDirection)
      return (*fShowerDirection);
    I3DataExecution::Instance().Fatal("I3RecoResultTopDirection::ShowerDirection () const asked for a shower direction which doesn't exist");
    //return(*(I3ShowerDirectionPtr)NULL);
  }

  /**
   * Retrieves the track of this solution as a non-const object
   */
  I3ShowerDirection& GetShowerDirection ()
  {
    if(fShowerDirection)
      return (*fShowerDirection);
    I3DataExecution::Instance().Fatal("I3RecoResultSingleTopDirection::ShowerDirection() asked for a track which doesn't exist");
    //return(*(I3ShowerDirectionPtr)NULL);
  }

  bool HasShowerDirection () const { return fShowerDirection; }
  
  void SetShowerDirection (I3ShowerDirectionPtr shower_direction)
  {
    if(fShowerDirection)
    {
      I3DataExecution::Instance().Fatal("I3RecoResultTopDirection::SetShowerDirection () shower direction exists already");
      return;
    }
    fShowerDirection = shower_direction;
  }

  
  
  private:
  // copy and assignment are private
  //I3RecoResultTopDirection (const I3RecoResultTopDirection& rhs);
  //const I3RecoResultTopDirection& operator= (const I3RecoResultTopDirection&);

  // ROOT macro
  ClassDef(I3RecoResultTopDirection, 1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RecoResultTopDirection>::ThePolicy I3RecoResultTopDirectionPtr;

#endif
