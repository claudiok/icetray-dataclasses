#ifndef NANPOLICY_H
#define NANPOLICY_H

#include "dataclasses/I3DataExecution.h"

struct NanPolicy
{
  static void Fatal()
  {
    I3DataExecution::Instance().Fatal("Illegal access of initialized or invalid track parameter.");
  }
};

#endif
