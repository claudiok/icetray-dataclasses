/**
 * copyright  (C) 2004
 * the IceCube collaboration
 *  $Id: I3Selector.h,v 1.1 2004/11/10 20:24:15 dule Exp $
 *
 * @file I3Selection.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/11/10 20:24:15 $
 * @author dule
 */

#ifndef I3SELECTOR_H
#define I3SELECTOR_H


/**
 * This is the 'selector.'  It is not an inherited type but rather a 
 * static simple type that has the same interface as Container::iterator
 */
template<class Container>
class I3Selector
{
private:
  typename Container::iterator wrapped;
  typename Container::iterator begin;
  typename Container::iterator end;
  I3Selection<Container>* selected;

public:
  I3Selector(typename Container::iterator b, 
	typename Container::iterator e,
	I3Selection<Container>* selection) : 
    begin(b),
    end(e),
    selected(selection)
  {}
    
  I3Selector<Container>& operator++()
  {
    wrapped++;
    while(wrapped != end && (!(*selected)(wrapped)))
      wrapped++;
    return *this;
  }

  I3Selector<Container>& operator++(int)
  {
    I3Selector::operator++();
    return *this;
  }
  
  I3Selector<Container>& operator=(typename Container::iterator iter)
  {
    wrapped = iter;
    while(wrapped != end && (!(*selected)(wrapped)))
      wrapped++;
    return *this;
  }

  bool operator==(typename Container::iterator iter)
  {
    return wrapped==iter;
  }

  typename Container::pointer operator->()
  {
   return wrapped.operator->();
  }
};

#endif
