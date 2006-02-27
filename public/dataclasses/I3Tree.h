/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Tree.h 14347 2006-01-15 15:15:08Z  $
 *
 * @file I3Tree.h
 * @version $Revision:  $
 * @date $Date: 2005-12-01 16:45:55 -0500 (Thu, 01 Dec 2005) $
 * @author tschmidt
 */

#ifndef I3_TREE_H_INCLUDED
#define I3_TREE_H_INCLUDED

#include "icetray/I3FrameObject.h"
#include <dataclasses/external/tree.hh>


template <typename T>
struct I3Tree : public I3FrameObject , public tree<T>
{
  /**
   * @todo need to implement serialization of tree!!!
   */
  template <class Archive>
  void serialize(Archive & ar, unsigned version)
  {
    ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
    //ar & make_nvp("thetree", base_object< tree<Key, Value> >(*this));
  }

};


#endif // I3_TREE_H_INCLUDED
