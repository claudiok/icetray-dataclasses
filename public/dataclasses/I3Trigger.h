/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Trigger.h,v 1.6 2005/04/04 15:49:25 pretz Exp $
 *
 * @file I3Trigger.h
 * @version $Revision: 1.6 $
 * @date $Date: 2005/04/04 15:49:25 $
 * @author blaufuss
 * @author deyoung
 */

#ifndef I3TRIGGER_H
#define I3TRIGGER_H

#include <TObject.h>
#include <TClass.h>
#include <string>
#include <iostream>
#include <sstream>

using namespace std; 

/**
 * @brief The basic Trigger class.  
 * 
 * This is the base class for trigger records that will live in the I3TriggerDict.
 */
class I3Trigger : public TObject
{
public:
    /**
     * An enumerated type for the Subdetector type that generated the trigger
     */
    enum TrigSubDetector {InIce,IceTop,Amanda,Global};
    
private:
    double fTriggerTime;      ///< Time at which the trigger was issued
    double fTriggerLength;    ///< Duration of triggered readout window
    bool fDidTrigger;         ///< kTrue if the trigger condition was met
    TrigSubDetector fSubDetector; ///< Subdetector (enum type) that initiated this trigger
    
public:
    /**
     * constructor
     */
    I3Trigger() {}
    
    /**
     * copy constructor just uses assignment
     */
    I3Trigger(const I3Trigger& rhs){*this = rhs;}
    
    /**
     * destructor
     */
    virtual ~I3Trigger() {}
    
    /**
     * assignment is member-wise assignment
     */
    const I3Trigger& operator=(const I3Trigger& rhs) {
	if (this == &rhs) return *this; // check for assignment to self
	TObject::operator=(rhs); // call base class assignment operator
	fTriggerTime = rhs.fTriggerTime;
	fTriggerLength = rhs.fTriggerLength;
	fDidTrigger = rhs.fDidTrigger;
	fSubDetector = rhs.fSubDetector;
	return *this;
    }
    
    /**
     * @return the time at which this trigger condition was met
     */
    double GetTriggerTime() const {return fTriggerTime;}
    
    /**
     * @param time the time at which this trigger condition was met
     */
    void SetTriggerTime(double time) { fTriggerTime = time; }

    /**
     * @return the width of this trigger window
     */
    double GetTriggerLength() const {return fTriggerLength;}
    
    /**
     * @param width the width of this trigger window
     */
    void SetTriggerLength(double width) { fTriggerLength = width; }

    /**
     * @return whether this trigger condition was met
     */
    bool GetDidTrigger() const {return fDidTrigger;}

    /**
     * @return whether this trigger condition was met
     */
    bool HasTrigger() const {return fDidTrigger;}
    
    /**
     * @param passed whether or not this trigger condition was met
     */
    void SetDidTrigger(bool passed) { fDidTrigger = passed; }

    /**
     * @return the subdetector on which this trigger ran
     */
    TrigSubDetector GetSubDetector() const {return fSubDetector;}
    
    /**
     * @param detector the subdetector on which this trigger ran
     */
    void SetSubDetector(TrigSubDetector detector) { fSubDetector = detector; }

    /**
     * @todo finish with all the data
     */
    virtual void ToStream(ostream& o) const
    {
	o<<"[ "
	 <<IsA()->GetName()
	 <<" Trigger Time:"
	 <<fTriggerTime
	 <<" Sub Detector ID:"
	 <<fSubDetector
	 <<" ]\n";
    }

    virtual string ToString() const
      {
	ostringstream out;
	ToStream(out);
	return out.str();
      }
    
private:
    /**
     * resets the data to 0's.
     */
    
    //ROOT macro
    ClassDef(I3Trigger,1);
};

/**
 * streams an I3Trigger to an arbitrary ostream
 */
inline ostream& operator<<(ostream& o,const I3Trigger& g)
{
    g.ToStream(o); 
    return o;
}

#include "dataclasses/StoragePolicy.h"
/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3Trigger>::ThePolicy I3TriggerPtr;

#endif

