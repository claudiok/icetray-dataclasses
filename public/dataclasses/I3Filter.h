/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Filter.h,v 1.1 2004/07/29 15:35:46 blaufuss Exp $
 *
 * @file I3Filter.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/07/29 15:35:46 $
 * @author blaufuss
 */

#ifndef I3FILTER_H
#define I3FILTER_H

#include <TObject.h>
#include <TClass.h>
#include <string>
#include <iostream>

using namespace std; 

/**
 * @brief The basic Filter class.  
 * 
 * This is the base class for filter records that will live in the I3FilterDict.
 */
class I3Filter : public TObject
{
public:
    
private:
    Bool_t fPassFilter;         ///< kTrue if the filter condition was met
    
public:
    /**
     * constructor
     */
    I3Filter() {}
    
    /**
     * copy constructor just uses assignment
     */
    I3Filter(const I3Filter& rhs){*this = rhs;}
    
    /**
     * destructor
     */
    virtual ~I3Filter() {}
    
    /**
     * assignment is member-wise assignment
     */
    const I3Filter& operator=(const I3Filter& rhs) {
	if (this == &rhs) return *this; // check for assignment to self
	TObject::operator=(rhs); // call base class assignment operator
	fPassFilter = rhs.fPassFilter;
	return *this;
    }
    
    /**
     * @return whether this filter condition was met
     */
    Bool_t GetPassFilter() const {return fPassFilter;}
    
    /**
     * @param passed whether or not this filter condition was met
     */
    void SetPassFilter(Bool_t passed) { fPassFilter = passed; }

    /**
     * Standard output doo-hickey
     */
    virtual void ToStream(ostream& o) const
    {
	o<<"[ "
	 <<IsA()->GetName()
	 <<" Filter Status:"
	 <<fPassFilter
	 <<" ]\n";
    }
    
    
private:
    /**
     * resets the data to 0's.
     */
    
    //ROOT macro
    ClassDef(I3Filter,1);
};

inline ostream& operator<<(ostream& o,const I3Filter& g)
{
    g.ToStream(o); 
    return o;
}

#include "dataclasses/StoragePolicy.h"
typedef PtrPolicy<I3Filter>::ThePolicy I3FilterPtr;

#endif

