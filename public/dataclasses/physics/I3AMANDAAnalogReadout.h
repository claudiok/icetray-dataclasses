/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3AMANDAAnalogReadout.h
 * @date $Date$
 */

#ifndef I3AMANDAANALOGREADOUT_H_INCLUDED
#define I3AMANDAANALOGREADOUT_H_INCLUDED

#include <iostream>
#include <vector>

#include "TObject.h"
#include "dataclasses/Utility.h"

/**
 * @brief Old-style AMANDA ADC/TDC readout
 *
 * This class represents an old-style AMANDA DAQ readout, with a
 * series of LEs and TEs and a single amplitude measurement 
 * that represents the peak from the entire event.  TOTs are generated
 * on the fly and may be wrong if edges are missing.
 */
class I3AMANDAAnalogReadout : public TObject 
{ 
  std::vector<double> LEs_; 
  std::vector<double> TEs_; 
  mutable double firstLE_;
  mutable bool processFirstLE_;
  mutable std::vector<double> TOTs_;
  mutable bool processTOTs_;
  std::vector<int> HitNumbers_;  
  std::vector<int> ParentIDs_;  
  double adc_;         
  bool overflow_;    
  bool is_calib_;    
 
public:

  I3AMANDAAnalogReadout() : processFirstLE_(true), processTOTs_(true) {}
  
  virtual ~I3AMANDAAnalogReadout();

  /**
   * Returns the earliest leading edge recorded by the DAQ
   */
  double GetFirstLE() const;
    
  /** 
   * Returns the series of leading edges
   */
  const std::vector<double>& GetLEs() const {return LEs_;}
  std::vector<double>& GetLEs()
  { 
    processFirstLE_ = true;
    processTOTs_ = true;
    return LEs_;
  }
    
  /**
   * Returns the series of trailing edges
   */
  const std::vector<double>& GetTEs() const {return TEs_;}
  std::vector<double>& GetTEs()
  {
    processTOTs_ = true;    
    return TEs_;
  }
    
  /**
   * Returns the time differences between leading and trailing edges.
   * If some edges are missing, the series may be shorter than expected.
   */
  const std::vector<double>& GetTOTs() const;

  const std::vector<int>& GetHitNumbers() const {return HitNumbers_;}
  std::vector<int>& GetHitNumbers() {return HitNumbers_;}

  const std::vector<int>& GetParentIDs() const {return ParentIDs_;}
  std::vector<int>& GetParentIDs() {return ParentIDs_;}

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
    

  virtual void ToStream(std::ostream& o) const 
  {
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

  template <class Archive> void save(Archive& ar, unsigned version) const;
  template <class Archive> void load(Archive& ar, unsigned version);
  BOOST_SERIALIZATION_SPLIT_MEMBER();

  // private copy constructors and assignment
  I3AMANDAAnalogReadout(const I3AMANDAAnalogReadout& other);
  I3AMANDAAnalogReadout& operator=(const I3AMANDAAnalogReadout& other);

  // ROOT macro
  //ClassDef(I3AMANDAAnalogReadout,2);
};

I3_POINTER_TYPEDEFS(I3AMANDAAnalogReadout);

#endif //I3AMANDAANALOGREADOUT_H_INCLUDED
