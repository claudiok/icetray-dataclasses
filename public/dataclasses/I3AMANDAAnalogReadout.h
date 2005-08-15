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
 * @brief Old-style AMANDA ADC/TDC readout
 *
 * This class represents an old-style AMANDA DAQ readout, with a
 * series of LEs and TEs and a single amplitude measurement 
 * that represents the peak from the entire event.  TOTs are generated
 * on the fly and may be wrong if edges are missing.
 */
class I3AMANDAAnalogReadout : public I3AnalogReadout 
{ 
  vector<double> LEs_; 
  vector<double> TEs_; 
  mutable vector<double> TOTs_;
  mutable bool calculateTOTs_;
  vector<int>    HitNumbers_;  
  vector<int>    ParentIDs_;  
  double adc_;         
  bool   overflow_;    
  bool   is_calib_;    
 
public:
  I3AMANDAAnalogReadout() : calculateTOTs_(true) {};
  virtual ~I3AMANDAAnalogReadout(){};

  /**
   * Returns the earliest leading edge recorded by the DAQ
   */
  double GetFirstLE() const;
    
  /** 
   * Returns the series of leading edges
   */
  const vector<double>& GetLEs() const {return LEs_;}
  vector<double>& GetLEs()
  { 
    calculateTOTs_ = true;
    return LEs_;
  }
    
  /**
   * Returns the series of trailing edges
   */
  const vector<double>& GetTEs() const {return TEs_;}
  vector<double>& GetTEs()
  {
    calculateTOTs_ = true;    
    return TEs_;
  }
    
  /**
   * Returns the time differences between leading and trailing edges.
   * If some edges are missing, the series may be shorter than expected.
   */
  const vector<double>& GetTOTs() const;

  const vector<int>& GetHitNumbers() const {return HitNumbers_;}
  vector<int>& GetHitNumbers() {return HitNumbers_;}

  const vector<int>& GetParentIDs() const {return ParentIDs_;}
  vector<int>& GetParentIDs() {return ParentIDs_;}

  /** 
   * Alternate name for the amplitude
   */
  double GetADC() const {return GetAmplitude();}
  void SetADC(double adc) {SetAmplitude(adc);}

  /**
   * Returns the single amplitude recorded for the event
   */
  double GetAmplitude() const {return adc_;}
  void SetAmplitude(double amp) {adc_=amp;}
  
  /** 
   * Indicates whether edge pairs were lost due to buffer overflow.
   * If true, the earliest edges are missing (FIFO buffer).  The
   * buffer is 16 edges (8 pairs) deep.
   */
  bool GetOverflow() const {return overflow_;}
  void SetOverflow(bool overflow) {overflow_=overflow;}
    
  /** 
   * Indicates whether this object stores calibrated or uncalibrated data.
   */
  bool IsCalibrated() const {return is_calib_;}
  void SetCalibrated(bool is_calib) {is_calib_=is_calib;}
    

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
  
  //template <class Archive> void save(Archive& ar, unsigned version) const
  //{
  //  ar & make_nvp("I3AnalogReadout", base_object<I3AnalogReadout>(*this));
  //  ar & make_nvp("LEs", LEs_);
  //  ar & make_nvp("TEs", TEs_);
  //  ar & make_nvp("HitNumbers", HitNumbers_);
  //  ar & make_nvp("ParentIDs", ParentIDs_);
  //  ar & make_nvp("ADC", adc_ );
  //  ar & make_nvp("Overflow", overflow_ );
  //  ar & make_nvp("Calib", is_calib_ );
  //}

  template <class Archive> void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3AnalogReadout", base_object<I3AnalogReadout>(*this));
    ar & make_nvp("LEs", LEs_);
    ar & make_nvp("TEs", TEs_);
    ar & make_nvp("HitNumbers", HitNumbers_);
    ar & make_nvp("ParentIDs", ParentIDs_);
    ar & make_nvp("ADC", adc_ );
    ar & make_nvp("Overflow", overflow_ );
    ar & make_nvp("Calib", is_calib_ );
    
    calculateTOTs_ = true;
  }
  //BOOST_SERIALIZATION_SPLIT_MEMBER()
  //would be much better to split serialize into save and load
  //but rootcint can not deal with above macro ... need to check in detail

  // ROOT macro
  ClassDef(I3AMANDAAnalogReadout,1);
};

BOOST_SHARED_POINTER_EXPORT(I3AMANDAAnalogReadout);

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef shared_ptr<I3AMANDAAnalogReadout> I3AMANDAAnalogReadoutPtr;
#endif

