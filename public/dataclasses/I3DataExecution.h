#ifndef I3DATAEXECUTION_H
#define I3DATAEXECUTION_H
/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DataExecution.h,v 1.3 2004/02/25 18:01:32 pretz Exp $
 *
 * The data structure's access to the framework.  If the 
 * data wants to get a message into the logging system or abort the job 
 * because of an illegal request, it does so through this class
 * The implementation is a bit fuzzy, since it depends on how icetray
 * implements logging.  Right now it calls icetray's private logger, but
 * there should be a logger for just the data.
 *
 * @version $Revision: 1.3 $
 * @date $Date: 2004/02/25 18:01:32 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo implement the 'Fatal' to actually 'Fatal' in the framework rather than exit(1)
 * @todo give the data its own logger rather than piggy-backing IceTray's 
 * @todo decide if this is really necessary
 * @todo if its not necessary, we can decouple dataclasses from icetray
 */

#include "Rtypes.h"

class I3Logger;

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
  void Fatal(const Char_t* message);

  /**
   * gets the logger for the data structure
   */
   I3Logger& GetLogger();

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

  // ROOT macro
  ClassDef(I3DataExecution,0);
};

// don't need this since its a singleton
// typedef I3DataExecution* I3DataExecutionPtr

#endif
