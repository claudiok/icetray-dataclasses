/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3AMANDAAnalogReadout.h,v 1.10 2005/01/24 23:17:44 ehrlich Exp $
 *
 * @file I3AMANDAAnalogReadout.h
 * @version $Revision: 1.10 $
 * @date $Date: 2005/01/24 23:17:44 $
 * @author pretz
 * @author ehrlich
 *
 */
#ifndef I3AMANDAANALOGREADOUT_CALIB_H
#define I3AMANDAANALOGREADOUT_CALIB_H

#include "I3AnalogReadout.h"
#include "I3DataReadout.h"
#include "StoragePolicy.h"

#include <vector>

using namespace std;

/**
 * @brief Old-style AMANDA ADC/TDC readout (calibrated) 
 *
 * This class represents an old-style AMANDA DAQ readout (calibrated), with a
 * series of (calibrated) times and times over threshold, and a single
 * amplitude measurement that represents the peak from the entire
 * event. 
 */
class I3AMANDAAnalogReadout_calib: public I3AnalogReadout 
{ 
  vector<Double_t> T_surf;    //in times
  vector<Double_t> T_z;       //in times
  vector<Double_t> T_1pe;     //in times
  vector<Double_t> T_amp;     //in times
  vector<Double_t> TOTs;      //in times
  vector<Int_t> HitNumbers;
  Double_t Amp;               //in PEs
  Bool_t Overflow;
 
  public:
  I3AMANDAAnalogReadout_calib(){}
  virtual ~I3AMANDAAnalogReadout_calib() {;}
    
  const vector<Double_t>& GetT_surf() const {return T_surf;}
  vector<Double_t>& GetT_surf(){return T_surf;}
    
  const vector<Double_t>& GetT_z() const {return T_z;}
  vector<Double_t>& GetT_z(){return T_z;}
    
  const vector<Double_t>& GetT_1PE() const {return T_1pe;}
  vector<Double_t>& GetT_1PE(){return T_1pe;}
    
  const vector<Double_t>& GetT_amp() const {return T_amp;}
  vector<Double_t>& GetT_amp(){return T_amp;}
    
  const vector<Double_t>& GetTOTs() const {return TOTs;}
  vector<Double_t>& GetTOTs() {return TOTs;}
    
  const vector<Int_t>& GetHitNumbers() const {return HitNumbers;}
  vector<Int_t>& GetHitNumbers() {return HitNumbers;}

  Double_t GetAmplitude() const {return Amp;}
  void SetAmplitude(Double_t amplitude) {Amp=amplitude;}
    
  Bool_t GetOverflow() const {return Overflow;}
  void SetOverflow(Bool_t overflow) {Overflow=overflow;}
    

  virtual void ToStream(ostream& o) const 
  {
    I3AnalogReadout::ToStream(o);
    o << "Amplitude: " << Amp << "\n"
      << "Number of Pulses: " << T_surf.size() << "\n";
    o << "T_surf: ";
    for (unsigned i = 0; i < T_surf.size(); i++) {o << T_surf[i] << " ";}
    o << "T_z: ";
    for (unsigned i = 0; i < T_z.size(); i++) {o << T_z[i] << " ";}
    o << "T_1PE: ";
    for (unsigned i = 0; i < T_1pe.size(); i++) {o << T_1pe[i] << " ";}
    o << "T_amp: ";
    for (unsigned i = 0; i < T_amp.size(); i++) {o << T_amp[i] << " ";}
    o << "\nTOTs: ";
    for (unsigned i = 0; i < TOTs.size(); i++) {o << TOTs[i] << " ";}
    o << "\n";
  }
    
  private:
  friend class boost::serialization::access;
  template <class Archive> void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3AnalogReadout", base_object<I3AnalogReadout>(*this));
    ar & make_nvp("T_surf", T_surf);
    ar & make_nvp("T_z", T_z);
    ar & make_nvp("T_1PE", T_1pe);
    ar & make_nvp("T_amp", T_amp);
    ar & make_nvp("TOTs", TOTs);
    ar & make_nvp("HitNumbers", HitNumbers_);
    ar & make_nvp("Amplitude", Amp);
    ar & make_nvp("Overflow", overflow);
  }

  // ROOT macro
  ClassDef(I3AMANDAAnalogReadout_calib,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef shared_ptr<I3AMANDAAnalogReadout_calib> I3AMANDAAnalogReadout_calibPtr;
#endif

