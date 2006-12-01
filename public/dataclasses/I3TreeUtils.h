/**
    copyright  (C) 2004
    the icecube collaboration
    @file I3MCTreeUtils.h
*/

#ifndef I3TREEUTILS_H_INCLUDED
#define I3TREEUTILS_H_INCLUDED

#include "dataclasses/I3Tree.h"
#include "icetray/I3DefaultName.h"

namespace I3TreeUtils
{
  /**
   * Adds a primary (top-level node) to the tree.
   * The primary has no parent.
   * A tree can have multiple primaries.
   */
  template<class Type>
    void AddPrimary(I3Tree<Type>& t, const Type& p)
    {
      typename I3Tree<Type>::iterator si;
      si = t.end(t.begin());
      t.insert(si,p);
    }

  /**
   * Alternative way to add primary
   */
  template<class Type>
    void AddPrimary(shared_ptr<I3Tree<Type> > t, const Type& p)
    {
      AddPrimary<Type>(*t, p);
    }

  /**
   * Appends a child to an object
   */
  template<class Type>
    void AppendChild(I3Tree<Type>& t, const Type& parent, const Type& child)
    {
      //Need to find the iterator of the parent
      //do it bonehead-style first
      typename I3Tree<Type>::iterator i;
      typename I3Tree<Type>::iterator p_iter;
      for (i=t.begin(); i!=t.end(); ++i) {
	if (i->GetID() == parent.GetID()) {
	  p_iter = i;
	  break;
	}
      }
      if (p_iter != t.end()) {
	t.append_child(p_iter,child);
      } else {
	log_error("attempt to add a child to a non-existant parent.");
      }
    }

  /**
   * Alternative to append a child
   */
  template<class Type>
    void AppendChild(shared_ptr<I3Tree<Type> > t, 
		     const Type& parent, const Type& child)
    {
      AppendChild<Type>(*t, parent, child);
    }

  /**
   * Random access to the tree objects
   */
  template<class Type>
    Type& GetObject(const I3Tree<Type>& t, int id)
    {
      typename I3Tree<Type>::iterator i;
      for (i=t.begin(); i!=t.end(); ++i) {
	if (i->GetID() == id) {
	  return *i;
	}
      }
      log_fatal("There is no object with ID = %i",id);
      return *i;
    }

  /**
   * Alternative way to get object from tree
   */
  template<class Type>
    Type& GetObject(shared_ptr<const I3Tree<Type> > t, int id)
    {
      return GetObject<Type>(*t, id);
    }


  /**
   * Gets a list of primaries from the tree
   */
  template<class Type>
    const std::vector<Type> GetPrimaries(const I3Tree<Type>& t)
    {
      std::vector<Type> primaryList;
      typename I3Tree<Type>::sibling_iterator i;
      for (i=t.begin(); i!=t.end(); ++i)
	primaryList.push_back(*i);
      return primaryList;
    }

  /**
   * Alternative way to get primaries
   */
  template<class Type>
    const std::vector<Type> GetPrimaries(shared_ptr<const I3Tree<Type> > t)
    {
      return GetPrimaries<Type>(*t);
    }

  /**
   * Gets a list of daughters of the parent object.
   */
  template<class Type>
    const std::vector<Type> GetDaughters(const I3Tree<Type>& t, const Type& p)
    {
      std::vector<Type> daughterList;
      typename I3Tree<Type>::iterator i;
      for (i=t.begin(); i != t.end(); i++) {
	if (i->GetID() == p.GetID()) {
	  typename I3Tree<Type>::sibling_iterator j(i);
	  for (j=t.begin(i); j!=t.end(i); ++j)
	    daughterList.push_back(*j);
	  return daughterList;
	}
      }
      log_warn("No daughters found for this object.");
      return daughterList;
    }

  /**
   * Alternative way to get list of daugters
   */
  template<class Type>
    const std::vector<Type> GetDaughters(shared_ptr<const I3Tree<Type> > t, 
					 const Type& p)
    {
      return GetDaughters<Type>(*t, p);
    }

  /**
   * Returns true if the object is a primary
   */
  template<class Type>
    bool IsPrimary(const I3Tree<Type>& t, const Type& p)
    {
      typename I3Tree<Type>::sibling_iterator s;
      for (s=t.begin(); s!=t.end(); s++)
	if (s->GetID() == p.GetID()) return true;
      return false;
    }

  /**
   * Alternate way to check if object is a primary
   */
  template<class Type>
    bool IsPrimary(shared_ptr<const I3Tree<Type> > t, const Type& p)
    {
      return IsPrimary<Type>(*t, p);
    }

  /**
   * Returns true if the object has a parent
   */
  template<class Type>
    bool HasParent(const I3Tree<Type>& t, const Type& child)
    {
      typename I3Tree<Type>::iterator i = t.begin();
      for( ; i != t.end(); i++){
	if(i->GetID() == child.GetID() && !IsPrimary<Type>(t,child))
	  if(t.parent(i) != t.end()) return true;
      }
      return false;
    }

  /**
   * Alternative way to check if object has a parent
   */
  template<class Type>
    bool HasParent(shared_ptr<const I3Tree<Type> > t, const Type& child)
    {
      return HasParent<Type>(*t, child);
    }

  /**
   * Gets the parent of an object.  log_fatals if parent does not exist.
   */
  template<class Type>
    const Type& GetParent(const I3Tree<Type>& t, const Type& child)
    {
      typename I3Tree<Type>::iterator i = t.begin();
      for( ; i != t.end(); i++){
	if(i->GetID() == child.GetID() && !IsPrimary<Type>(t,child))
	  return *(t.parent(i));
      }
      log_fatal("No parent found for this object.");
    }

  /**
   * Alternative way to get parent
   */
  template<class Type>
    const Type& GetParent(shared_ptr<const I3Tree<Type> > t,
				const Type& child)
    {
      return GetParent<Type>(*t, child);
    }

}

#endif 


