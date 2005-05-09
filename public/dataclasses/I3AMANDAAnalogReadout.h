/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3AMANDAAnalogReadout.h
 * @version $Revision: 1.10 $
 * @date $Date$
 * @author pretz
 * @author ehrlich
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
 * @brief Old-style AMANDA ADC/TDC readout (uncalibrated) 
 *
 * This class represents an old-style AMANDA DAQ readout (uncalibrated), with a
 * series of LEs and TEs and a single amplitude measurement 
 * that represents the peak from the entire event. 
 */
class I3AMANDAAnalogReadout : public I3AnalogReadout 
{ 
  vector<double> LEs_;   //in counts
  vector<double> TEs_;   //in counts   //TOT = TE - LE
  vector<int>    HitNumbers_;
  double adc_;           //in voltage
  bool   overflow_;
 
  public:
  I3AMANDAAnalogReadout(){}
  virtual ~I3AMANDAAnalogReadout() {;}

  double GetFirstLE() {if(LEs_.size()) return LEs_[0]; else return NAN;}
    
  const vector<double>& GetLEs() const {return LEs_;}
  vector<double>& GetLEs(){return LEs_;}
    
  const vector<double>& GetTEs() const {return TEs_;}
  vector<double>& GetTEs() {return TEs_;}
    
  const vector<int>& GetHitNumbers() const {return HitNumbers_;}
  vector<int>& GetHitNumbers() {return HitNumbers_;}

  double GetADC() const {return adc_;}
  void SetADC(double adc) {adc_=adc;}
    
  bool GetOverflow() const {return overflow_;}
  void SetOverflow(bool overflow) {overflow_=overflow;}
    

  virtual void ToStream(ostream& o) const 
  {
    I3AnalogReadout::ToStream(o);
    o << "Amplitude: " << adc_ << "\n"
      << "Number of Pulses: " << LEs_.size() << "\n"
      << "Leading Edges: ";
    for(unsigned i=0; i<LEs_.size(); i++) 
    {
      o << LEs_[i] << " ";
    }
    o << "\nTEs: ";
    for(unsigned i=0; i<TEs_.size(); i++) 
    {
      o << TEs_[i] << " ";
    }
    o << "\n";
  }
    

  private:
  friend class boost::serialization::access;
  template <class Archive> void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3AnalogReadout", base_object<I3AnalogReadout>(*this));
    ar & make_nvp("LEs", LEs_);
    ar & make_nvp("TEs", TEs_);
    ar & make_nvp("HitNumbers", HitNumbers_);
    ar & make_nvp("ADC", adc_ );
    ar & make_nvp("Overflow", overflow_ );
  }

  // ROOT macro
  ClassDef(I3AMANDAAnalogReadout,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef shared_ptr<I3AMANDAAnalogReadout> I3AMANDAAnalogReadoutPtr;
#endif

