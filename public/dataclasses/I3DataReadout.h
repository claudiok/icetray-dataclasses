/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3DataReadout.h
 * @version $Revision: 1.23 $
 * @date $Date$
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3DATAREADOUT_H
#define I3DATAREADOUT_H

#include <iostream>
#include <sstream>
#include <TObject.h>
#include <TClass.h>
#include "StoragePolicy.h"

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
class I3DataReadout : public TObject 
{
    bool raw_;
    
public:
    /**
     * default constructor
     */
  I3DataReadout() : raw_(false) {}
    
    /**
     * default destructor
     */
    virtual ~I3DataReadout();
    
    /**
     * Indicates whether or not this readout came directly from the detector
     * or was put in later to emulate a particular kind of data.
     * @return kTRUE if this readout came directly from the detector
     */
    bool IsRaw() const {return raw_;}
    
    /**
     * establishes this I3DataReadout as either coming from the detector
     * or from some later processing.
     * @param raw kTRUE if it came straight from the detector
     */
    void SetRaw(bool raw) {raw_ = raw;}
    
    /**
     * @todo finish implementing this method
     */
    virtual void ToStream(ostream& o) const {
	o<<"[ I3DataReadout ] Output withheld\n";
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

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
// private copy constructors and assignment
  I3DataReadout(const I3DataReadout& other);
  I3DataReadout& operator=(const I3DataReadout& other);

  // ROOT Macro
  //ClassDef(I3DataReadout,1);
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
typedef shared_ptr<I3DataReadout> I3DataReadoutPtr;

#endif


