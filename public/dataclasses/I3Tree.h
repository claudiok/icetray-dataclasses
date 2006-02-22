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

#include <TObject.h>
#include <dataclasses/external/tree.hh>


template <typename T>
class I3Tree : public TObject, public tree<T>
{
private:
  friend class boost::serialization::access;
  /**
   * @todo need to implement serialization of tree!!!
   */
  template <class Archive>
  void serialize(Archive & ar, unsigned version)
  {
    // ...
  }
};


#endif // I3_TREE_H_INCLUDED
