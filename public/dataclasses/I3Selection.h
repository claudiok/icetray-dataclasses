/**
 * copyright  (C) 2004
 * the IceCube collaboration
 *  $Id: I3Selection.h,v 1.1 2004/11/10 20:24:15 dule Exp $
 *
 * @file I3Selection.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/11/10 20:24:15 $
 * @author dule
 */

#ifndef I3SELECTION_H
#define I3SELECTION_H

#include <TObject.h>

/**
 * This is the class that users will inherit from when they want to make a 
 * new selection
 */
template <class Container>
class I3Selection
{
 public:
  virtual bool operator()(typename Container::iterator iter) = 0;
};

#endif
