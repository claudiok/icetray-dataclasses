/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3IDService.h 17239 2006-03-14 17:51:36Z troy $
 *
 * @file I3IDService.h
 * @version $Revision:$
 * @date $Date: 2006-03-14 11:51:36 -0600 (Tue, 14 Mar 2006) $
 * @author pretz
 */

#ifndef I3IDSERVICE_H
#define I3IDSERVICE_H

#include <icetray/I3FrameObject.h>
#include <icetray/I3DefaultName.h>

#include "dataclasses/Utility.h"

class I3Frame;

/**
 * @brief This services simply serves up integers
 * to guarantee all of the particle ids in an event 
 * are unique
 */
class I3IDService
{

 private:
  int id_;

 public:

  /**
   * @brief Serves up the current ID and increments it.
   */
  int ServeID(){ return id_++; }

  /**
   * @brief Serves up the current ID without incrementing it.
   */
  int GetCurrentID() const{ return id_; }    

  I3IDService():
    id_(0)
    {};

  ~I3IDService() { }
};

I3_DEFAULT_NAME(I3IDService);
I3_POINTER_TYPEDEFS(I3IDService);

#endif
