/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3AnalogReadout.h
 * @version $Revision: 1.13 $
 * @date $Date$
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
class I3AnalogReadout : public I3DataReadout 
{ 
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
    
  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3DataReadout", base_object<I3DataReadout>(*this) );
  }

  ClassDef(I3AnalogReadout,1);
};

BOOST_IS_ABSTRACT(I3AnalogReadout);

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef shared_ptr<I3AnalogReadout>  I3AnalogReadoutPtr;
#endif

