/**
 * copyright  (C) 2004
 * the IceCube collaboration
 *  $Id: I3SelectionMap.h,v 1.1 2004/11/10 20:24:15 dule Exp $
 *
 * @file I3SelectionMap.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/11/10 20:24:15 $
 * @author dule
 */

#ifndef I3SELECTIONMAP_H
#define I3SELECTIONMAP_H

#include "I3Selector.h"

/**
 * This class is a map of all the selections that have been made.  
 * It has a helper method for creating a selector corresponding 
 * to the given Selection.
 */
template <class Container>
class I3SelectionMap : public MapPolicy<string,I3Selection<Container>*>::ThePolicy
{
public:
  I3Selector<Container> MakeSelector(Container& cont, const string& name)
  {
    I3Selection<Container>* selection = (*this)[name];
    assert(selection);
    I3Selector<Container> to_return(cont.begin(),cont.end(),selection);
    return to_return;
  }
};

#endif
