/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DataReadout.h,v 1.17.4.1 2005/01/26 03:59:37 troy Exp $
 *
 * @file I3DataReadout.h
 * @version $Revision: 1.17.4.1 $
 * @date $Date: 2005/01/26 03:59:37 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3DATAREADOUT_H
#define I3DATAREADOUT_H

#include "StoragePolicy.h"
#include <iostream>
#include <sstream>

using namespace std;

/**
 * @brief Base class for all the data readout types
 *
 * DataReadouts are part of an I3OMResponse record.  The I3OMResponse
 * contains all information associated with a particular OM in a
 * single event, including hit information as well as raw and derived
 * data readouts.  
 * 
 * Raw @c DataReadouts are those directly recorded by the actual
 * hardware, while other @c DataReadouts may be derived from that  
 * record in later processing -- e.g., producing an old-style AMANDA
 * record from a recorded waveform, for use by legacy reconstruction
 * software.  An I3OMResponse may contain any number of 
 * @c DataReadouts, although only one of them will be a raw readout
 * (except in the case of AMANDA hybrid OMs).  
 * 
 * The data readouts are stored in the I3DataReadoutDict, which is
 * a member of the I3OMResponse.  Each @c DataReadout in the
 * @c DataReadoutDict is identified by a name, given by the software
 * that added the readout to the event.
 *
 * Reconstructed hit information -- a series of photoelectron
 * production times -- is stored as a I3RecoHitSeries, not a 
 * @c DataReadout.
 */
class I3DataReadout : public TObject {
    Bool_t fRaw;
    
public:
    /**
     * default constructor
     */
    I3DataReadout(){};
    
    /**
     * default destructor
     */
    virtual ~I3DataReadout(){}
    
    /**
     * Indicates whether or not this readout came directly from the detector
     * or was put in later to emulate a particular kind of data.
     * @return kTRUE if this readout came directly from the detector
     */
    Bool_t IsRaw() const {return fRaw;}
    
    /**
     * establishes this I3DataReadout as either coming from the detector
     * or from some later processing.
     * @param raw kTRUE if it came straight from the detector
     */
    void SetRaw(Bool_t raw) {fRaw = raw;}
    
    /**
     * @todo finish implementing this method
     */
    virtual void ToStream(ostream& o) const {
	o<<"[ "<<IsA()->GetName()<<" ]\n";
    }
    
    /**
     * dumps the data readout to the given string
     */
    virtual string ToString() const {
	ostringstream out;
	ToStream(out);
	return out.str();
    }

 private:
  // copy and assignment are private
  I3DataReadout(const I3DataReadout& rhs); 
  const I3DataReadout& operator=(const I3DataReadout& rhs); 

  // ROOT Macro
  ClassDef(I3DataReadout,1);
};

/**
 * streaming operator
 */
inline ostream& operator<<(ostream& o,const I3DataReadout& readout)
{
  readout.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3DataReadout>::ThePolicy I3DataReadoutPtr;

#endif

