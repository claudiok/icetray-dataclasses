/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3AMANDAAnalogReadout.h,v 1.11 2005/04/04 15:49:25 pretz Exp $
 *
 * @file I3AMANDAAnalogReadout.h
 * @version $Revision: 1.11 $
 * @date $Date: 2005/04/04 15:49:25 $
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

    vector<double> fLEs;
    vector<double> fTOTs;
    vector<unsigned short> fHitNumbers;
    double fAmp;
 
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
    virtual double GetFirstLE() const {
	if(fLEs.size() >0)
	    return fLEs[0];
	return 0;
    }
    
    /**
     * @return the list of LEs as a const object
     */
    const vector<double>& GetLEs() const {return fLEs;}
    
    /**
     * @return the list of LEs as a non-const object
     */
    vector<double>& GetLEs(){return fLEs;}
    
    /**
     * @return the list of TOTs as const object
     */
    const vector<double>& GetTOTs() const {return fTOTs;}
    
    /**
     * @return the list of TOTs as a non-const object
     */
    vector<double>& GetTOTs() {return fTOTs;}
    
    /**
     * @return the list of TOTs as const object
     */
    const vector<unsigned short>& GetHitNumbers() const {return fHitNumbers;}
    
    /**
     * @return the list of TOTs as a non-const object
     */
    vector<unsigned short>& GetHitNumbers() {return fHitNumbers;}

    /**
     * @return the amplitude
     */
    double GetAmplitude() const {return fAmp;}
    
    /**
     * @param amplitude the new amplitude of the readout
     */
    void SetAmplitude(double amplitude) {fAmp=amplitude;}
    

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
    ClassDef(I3AMANDAAnalogReadout,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3AMANDAAnalogReadout>::ThePolicy I3AMANDAAnalogReadoutPtr;
#endif

