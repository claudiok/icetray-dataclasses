/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DataExecution.h,v 1.8.4.2 2005/02/04 21:49:05 troy Exp $
 *
 * @file I3DataExecution.h
 * @version $Revision: 1.8.4.2 $
 * @date $Date: 2005/02/04 21:49:05 $
 * @author pretz
 */
#ifndef I3DATAEXECUTION_H
#define I3DATAEXECUTION_H

#include "dataclasses/StoragePolicy.h"
//#include "icetray/I3TrayHeaders.h"

class I3Logger;
/**
 * @brief The data structure's access to the framework.  
 *
 * If the 
 * data wants to get a message into the logging system or abort the job 
 * because of an illegal request, it does so through this class
 * The implementation is a bit fuzzy, since it depends on how icetray
 * implements logging.  Right now it calls icetray's private logger, but
 * there should be a logger for just the data.
 *
 * @todo implement the 'Fatal' to actually 'Fatal' in the framework rather 
 * than exit(1)
 * @todo give the data its own logger rather than piggy-backing IceTray's 
 * @todo decide if this is really necessary
 * @todo if its not necessary, we can decouple dataclasses from icetray
 */
class I3DataExecution{
 public:
  /**
   * singleton access to the single instance of the class
   * @return the single I3DataExecution
   */
  static I3DataExecution& Instance();

  /**
   * aborts the job with the indicated message
   * @param message a message which indicates why the job is being aborted.
   */
  void Fatal(const char* message);

  /**
   * destructor  I'd like to make it private, but gcc complains.
   */
  virtual ~I3DataExecution();
 private:
  /**
   * constructor.  Private.  The only way to access the class is through 
   * Instance()
   */
  I3DataExecution();

  // assignment and copy private.  Not implemented
  I3DataExecution(const I3DataExecution&);
  I3DataExecution& operator=(const I3DataExecution&);

  static I3DataExecution* fInstance;

};

// don't need this since its a singleton
// typedef PtrPolicy<I3DataExecution>::ThePolciy I3DataExecutionPtr;

#endif
