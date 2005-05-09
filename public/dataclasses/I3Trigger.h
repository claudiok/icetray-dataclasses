/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3Trigger.h
 * @version $Revision: 1.5 $
 * @date $Date$
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
    double triggerTime_;      ///< Time at which the trigger was issued
    double triggerLength_;    ///< Duration of triggered readout window
    bool didTrigger_;         ///< kTrue if the trigger condition was met
    TrigSubDetector subDetector_; ///< Subdetector (enum type) that initiated this trigger
    
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
	//TObject::operator=(rhs); // call base class assignment operator
	triggerTime_ = rhs.triggerTime_;
	triggerLength_ = rhs.triggerLength_;
	didTrigger_ = rhs.didTrigger_;
	subDetector_ = rhs.subDetector_;
	return *this;
    }
    
    /**
     * @return the time at which this trigger condition was met
     */
    double GetTriggerTime() const {return triggerTime_;}
    
    /**
     * @param time the time at which this trigger condition was met
     */
    void SetTriggerTime(double time) { triggerTime_ = time; }

    /**
     * @return the width of this trigger window
     */
    double GetTriggerLength() const {return triggerLength_;}
    
    /**
     * @param width the width of this trigger window
     */
    void SetTriggerLength(double width) { triggerLength_ = width; }

    /**
     * @return whether this trigger condition was met
     */
    bool GetDidTrigger() const {return didTrigger_;}

    /**
     * @return whether this trigger condition was met
     */
    bool HasTrigger() const {return didTrigger_;}
    
    /**
     * @param passed whether or not this trigger condition was met
     */
    void SetDidTrigger(bool passed) { didTrigger_ = passed; }

    /**
     * @return the subdetector on which this trigger ran
     */
    TrigSubDetector GetSubDetector() const {return subDetector_;}
    
    /**
     * @param detector the subdetector on which this trigger ran
     */
    void SetSubDetector(TrigSubDetector detector) { subDetector_ = detector; }

    /**
     * @todo finish with all the data
     */
    virtual void ToStream(ostream& o) const
    {
	o<<"[ "
	 <<IsA()->GetName()
	 <<" Trigger Time:"
	 <<triggerTime_
	 <<" Sub Detector ID:"
	 <<subDetector_
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

    friend class boost::serialization::access;

    template <class Archive>
      void serialize(Archive& ar, unsigned version){
        ar & make_nvp("TriggerTime",triggerTime_);
        ar & make_nvp("TriggerLength",triggerLength_);
        ar & make_nvp("DidTrigger",didTrigger_);
        ar & make_nvp("SubDetector",subDetector_);
      }
    
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
typedef shared_ptr<I3Trigger> I3TriggerPtr;

#endif

