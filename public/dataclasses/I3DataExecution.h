#ifndef I3DATAEXECUTION_H
#define I3DATAEXECUTION_H

/**
 * Class: I3DataExecution
 *
 * Version: $Id: I3DataExecution.h,v 1.1 2004/01/28 22:08:01 pretz Exp $
 *
 * Date: 12 Jan 2004
 *
 * (c) 2004 IceCube Collaboration
 */

#include "Rtypes.h"

class I3Logger;

/**
 * I3DataExecution 
 * The data structure's access to the framework.  If the 
 * data wants to get a message into the logging system or abort the job 
 * because of an illegal request, it does so through this class
 * The implementation is a bit fuzzy, since it depends on how icetray
 * implements logging.  Right now it calls icetray's private logger, but
 * there should be a logger for just the data.
 * @version $Id: I3DataExecution.h,v 1.1 2004/01/28 22:08:01 pretz Exp $
 * @author pretz
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

  // assignment and copy private
  I3DataExecution(const I3DataExecution&);
  I3DataExecution& operator=(const I3DataExecution&);

  static I3DataExecution* fInstance;

  // ROOT macro
  ClassDef(I3DataExecution,0);
};

#endif
