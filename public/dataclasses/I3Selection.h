/**
 * copyright  (C) 2004
 * the IceCube collaboration
 *  $Id: I3Selection.h,v 1.1.2.1 2005/01/26 03:59:37 troy Exp $
 *
 * @file I3Selection.h
 * @version $Revision: 1.1.2.1 $
 * @date $Date: 2005/01/26 03:59:37 $
 * @author dule
 */

#ifndef I3SELECTION_H
#define I3SELECTION_H

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
