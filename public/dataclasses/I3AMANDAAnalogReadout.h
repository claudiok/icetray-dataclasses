/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3AMANDAAnalogReadout.h,v 1.9.2.2 2005/02/04 21:49:04 troy Exp $
 *
 * @file I3AMANDAAnalogReadout.h
 * @version $Revision: 1.9.2.2 $
 * @date $Date: 2005/02/04 21:49:04 $
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

    vector<Double_t> fLEs;
    vector<Double_t> fTOTs;
    vector<UShort_t> fHitNumbers;
    Double_t fAmp;
 
public:
    /**
     * constructor
     */
    I3AMANDAAnalogReadout(){}

    /**
     * destructor
     */
    virtual ~I3AMANDAAnalogReadout() {;}
    
    /**
     * @return the time of the first LE in the readout
     */
    virtual Double_t GetFirstLE() const {
	if(fLEs.size() >0)
	    return fLEs[0];
	return 0;
    }
    
    /**
     * @return the list of LEs as a const object
     */
    const vector<Double_t>& GetLEs() const {return fLEs;}
    
    /**
     * @return the list of LEs as a non-const object
     */
    vector<Double_t>& GetLEs(){return fLEs;}
    
    /**
     * @return the list of TOTs as const object
     */
    const vector<Double_t>& GetTOTs() const {return fTOTs;}
    
    /**
     * @return the list of TOTs as a non-const object
     */
    vector<Double_t>& GetTOTs() {return fTOTs;}
    
    /**
     * @return the list of TOTs as const object
     */
    const vector<UShort_t>& GetHitNumbers() const {return fHitNumbers;}
    
    /**
     * @return the list of TOTs as a non-const object
     */
    vector<UShort_t>& GetHitNumbers() {return fHitNumbers;}

    /**
     * @return the amplitude
     */
    Double_t GetAmplitude() const {return fAmp;}
    
    /**
     * @param amplitude the new amplitude of the readout
     */
    void SetAmplitude(Double_t amplitude) {fAmp=amplitude;}
    

    virtual void ToStream(ostream& o) const {
	I3AnalogReadout::ToStream(o);
	o << "Amplitude: " << fAmp << "\n"
	  << "Number of Pulses: " << fLEs.size() << "\n"
	  << "Leading Edges: ";
	for (unsigned i = 0; i < fLEs.size(); i++) {
	    o << fLEs[i] << " ";
	}
	o << "\nTOTs: ";
	for (unsigned i = 0; i < fLEs.size(); i++) {
	    o << fTOTs[i] << " ";
	}
	o << "\n";
    }
    

private:

    // ROOT macro
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3AMANDAAnalogReadout>::ThePolicy I3AMANDAAnalogReadoutPtr;
#endif

