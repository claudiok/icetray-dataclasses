/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3AnalogReadout.h,v 1.10 2005/04/12 18:55:28 dule Exp $
 *
 * @file I3AnalogReadout.h
 * @version $Revision: 1.10 $
 * @date $Date: 2005/04/12 18:55:28 $
 * @author pretz
 */
#ifndef I3ANALOGREADOUT_H
#define I3ANALOGREADOUT_H

#include "dataclasses/I3DataReadout.h"
#include "StoragePolicy.h"

/**
 * @brief The base class for all the analog types of I3DataReadout
 * 
 * This class forms the base for specific types of analog
 * (non-digitizing) data readouts.  The basic information is just a
 * 'time' which records the first time the signal in the channel
 * crossed the discriminator threshold (the first 'leading edge').
 * Derived classes such as I3AMANDAAnalogReadout may provide
 * additional information.
 */
class I3AnalogReadout : public I3DataReadout { 
public:
    /**
     * constructor
     */
    I3AnalogReadout() { }
    
    /**
     * destructor
     */
    virtual ~I3AnalogReadout() {;}
    
    /**
     * @return the time of the first LE in the readout
     */
    virtual double GetFirstLE() const = 0;
  
    virtual void ToStream(ostream& o) const {
	I3DataReadout::ToStream(o);
	o << "First Leading Edge: " << GetFirstLE() << "\n";
    }

  
private:
    
    // ROOT macro
    ClassDef(I3AnalogReadout,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef shared_ptr<I3AnalogReadout>  I3AnalogReadoutPtr;
#endif

