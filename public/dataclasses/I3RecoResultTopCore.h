/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResultTopCore.h,v 1.6 2004/12/08 17:46:50 pretz Exp $
 *
 * @file I3RecoResultTopCore.h
 * @version $Revision: 1.6 $
 * @date $Date: 2004/12/08 17:46:50 $
 * @author Peter Niessen
 */

#ifndef __I3RECORESULTTOPCORE_H_
#define __I3RECORESULTTOPCORE_H_

#include "I3DataExecution.h"
#include "I3RecoResult.h"
#include "I3ShowerCore.h"

/**
 * @brief This is a reco result which just contains a single shower
 * core
 */
class I3RecoResultTopCore : public I3RecoResult
{
  I3ShowerCorePtr fShowerCore;
  
  public:
  /**
   * constructor
   */
  I3RecoResultTopCore () { /* fShowerCore = NULL; */ }

  /**
   * destructor
   */
  virtual ~I3RecoResultTopCore() {}

  /**
   * Retrieves the track in this reco result as a constant object
   */
  const I3ShowerCore& GetShowerCore () const 
  {
    if(fShowerCore)
      return (*fShowerCore);
    I3DataExecution::Instance().Fatal("I3RecoResultTopCore::ShowerCore () const asked for a shower core which doesn't exist");
    return(*(I3ShowerCore*)NULL);
  }

  /**
   * Retrieves the track of this solution as a non-const object
   */
  I3ShowerCore& GetShowerCore ()
  {
    if(fShowerCore)
      return (*fShowerCore);
    I3DataExecution::Instance().Fatal("I3RecoResultSingleTopCore::ShowerCore() asked for a track which doesn't exist");
    return(*(I3ShowerCore*)NULL);
  }

  bool HasShowerCore () const {return fShowerCore; } 
  
  void SetShowerCore (I3ShowerCorePtr shower_core)
  {
    if(fShowerCore)
    {
      I3DataExecution::Instance().Fatal("I3RecoResultTopCore::SetShowerCore () shower core exists already");
      return;
    }
    fShowerCore = shower_core;
  }

  
  
  private:
  // copy and assignment are private
  //I3RecoResultTopCore (const I3RecoResultTopCore& rhs);
  //const I3RecoResultTopCore& operator= (const I3RecoResultTopCore&);

  // ROOT macro
  ClassDef(I3RecoResultTopCore, 1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RecoResultTopCore>::ThePolicy I3RecoResultTopCorePtr;

#endif
