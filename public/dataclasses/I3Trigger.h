/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Trigger.h,v 1.1.2.1 2004/07/28 18:56:13 deyoung Exp $
 *
 * @file I3Trigger.h
 * @version $Revision: 1.1.2.1 $
 * @date $Date: 2004/07/28 18:56:13 $
 * @author blaufuss
 * @author deyoung
 */

#ifndef I3TRIGGER_H
#define I3TRIGGER_H

#include <TObject.h>
#include <TClass.h>
#include <string>
#include <iostream>

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
    Double_t fTriggerTime;      ///< Time at which the trigger was issued
    Double_t fTriggerLength;    ///< Duration of triggered readout window
    Bool_t fDidTrigger;         ///< kTrue if the trigger condition was met
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
    virtual ~I3Trigger(){}
    
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
    Double_t TriggerTime() const {return fTriggerTime;}
    
    /**
     * @param time the time at which this trigger condition was met
     */
    void TriggerTime(Double_t time) { fTriggerTime = time; }

    /**
     * @return the width of this trigger window
     */
    Double_t TriggerLength() const {return fTriggerLength;}
    
    /**
     * @param width the width of this trigger window
     */
    void TriggerLength(Double_t width) { fTriggerLength = width; }

    /**
     * @return whether this trigger condition was met
     */
    Bool_t DidTrigger() const {return fDidTrigger;}
    
    /**
     * @param passed whether or not this trigger condition was met
     */
    void DidTrigger(Bool_t passed) { fDidTrigger = passed; }

    /**
     * @return the subdetector on which this trigger ran
     */
    TrigSubDetector SubDetector() const {return fSubDetector;}
    
    /**
     * @param detector the subdetector on which this trigger ran
     */
    void SubDetector(TrigSubDetector detector) { fSubDetector = detector; }

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
    
    
private:
    /**
     * resets the data to 0's.
     */
    
    //ROOT macro
    ClassDef(I3Trigger,1);
};

inline ostream& operator<<(ostream& o,const I3Trigger& g)
{
    g.ToStream(o); 
    return o;
}

#include "dataclasses/StoragePolicy.h"
typedef PtrPolicy<I3Trigger>::ThePolicy I3TriggerPtr;

#endif

