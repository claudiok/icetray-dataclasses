/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: NanPolicy.h,v 1.3 2004/04/27 13:35:23 pretz Exp $
 *
 * @file NanPolicy.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/04/27 13:35:23 $
 * @author pretz
 */
#ifndef NANPOLICY_H
#define NANPOLICY_H

#include "dataclasses/I3DataExecution.h"

/**
 * @brief Probably a bad idea.  Experimentation with 'Policies'
 * @todo Find a better way to do this.  
 */
struct NanPolicy
{
  static void Fatal()
  {
    I3DataExecution::Instance().Fatal("Illegal access of initialized or invalid track parameter.");
  }
};

#endif
