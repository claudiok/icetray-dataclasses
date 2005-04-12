/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3AMANDAAnalogReadout.h,v 1.13 2005/04/12 18:55:28 dule Exp $
 *
 * @file I3AMANDAAnalogReadout.h
 * @version $Revision: 1.13 $
 * @date $Date: 2005/04/12 18:55:28 $
 * @author pretz
 *
 */
#ifndef I3AMANDAANALOGREADOUT_H
#define I3AMANDAANALOGREADOUT_H

#include "I3AnalogReadout.h"
#include "I3DataReadout.h"
#include "StoragePolicy.h"

#include <vector>

using namespace std;

/**
 * @brief Old-style AMANDA ADC/TDC readout  
 *
 * This class represents an old-style AMANDA DAQ readout, with a
 * series of leading edges and times over threshold, and a single
 * amplitude measurement that represents the peak from the entire
 * event. 
 */
class I3AMANDAAnalogReadout : public I3AnalogReadout { 

    vector<double> LEs_;
    vector<double> TOTs_;
    vector<unsigned short> hitNumbers_;
    double amp_;
 
public:
    /**
     * constructor
     */
    I3AMANDAAnalogReadout() { }

    /**
     * destructor
     */
    virtual ~I3AMANDAAnalogReadout() {;}
    
    /**
     * @return the time of the first LE in the readout
     */
    virtual double GetFirstLE() const {
		 if(LEs_.size() >0)
			 return LEs_[0];
		 return 0;
    }
    
    /**
     * @return the list of LEs as a const object
     */
    const vector<double>& GetLEs() const { return LEs_; }
    
    /**
     * @return the list of LEs as a non-const object
     */
    vector<double>& GetLEs() { return LEs_; }
    
    /**
     * @return the list of TOTs as const object
     */
    const vector<double>& GetTOTs() const { return TOTs_; }
    
    /**
     * @return the list of TOTs as a non-const object
     */
    vector<double>& GetTOTs() { return TOTs_; }
    
    /**
     * @return the list of TOTs as const object
     */
    const vector<unsigned short>& GetHitNumbers() const { return hitNumbers_; }
    
    /**
     * @return the list of TOTs as a non-const object
     */
    vector<unsigned short>& GetHitNumbers() { return hitNumbers_; }

    /**
     * @return the amplitude
     */
    double GetAmplitude() const { return amp_; }
    
    /**
     * @param amplitude the new amplitude of the readout
     */
    void SetAmplitude(double amplitude) { amp_ = amplitude; }
    

    virtual void ToStream(ostream& o) const {
	I3AnalogReadout::ToStream(o);
	o << "Amplitude: " << amp_ << "\n"
	  << "Number of Pulses: " << LEs_.size() << "\n"
	  << "Leading Edges: ";
	for (unsigned i = 0; i < LEs_.size(); i++) {
	    o << LEs_[i] << " ";
	}
	o << "\nTOTs: ";
	for (unsigned i = 0; i < LEs_.size(); i++) {
	    o << TOTs_[i] << " ";
	}
	o << "\n";
    }
    

private:

    // ROOT macro
    ClassDef(I3AMANDAAnalogReadout,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef shared_ptr<I3AMANDAAnalogReadout> I3AMANDAAnalogReadoutPtr;
#endif

