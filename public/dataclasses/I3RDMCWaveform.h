/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RDMCWaveform.h,v 1.1 2004/09/14 03:21:38 ehrlich Exp $
 *
 * @file I3RDMCWaveform.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/09/14 03:21:38 $
 * @author ehrlich
 */
#ifndef I3RDMCWAVEFORM_H
#define I3RDMCWAVEFORM_H

#include <TObject.h>
#include <vector>
#include "StoragePolicy.h"

using namespace std;

class I3RDMCWaveform : public TObject
{
  Int_t           id;
  Float_t         start_time;
  Float_t         time_bins;
  Float_t         baseline;
  vector<Float_t> digi;


  public:
  /**
   * constructor
   */
  I3RDMCWaveform() {id=0; start_time=0; time_bins=0; baseline=0;}

  /**
   * destructor
   */
  virtual ~I3RDMCWaveform() {;}

  Int_t            GetId() {return id;}
  void             SetId(Int_t id_) {id=id_;}
  Float_t          GetStartTime() {return start_time;}
  void             SetStartTime(Float_t start_time_) {start_time=start_time_;}
  Float_t          GetTimeBins() {return time_bins;}
  void             SetTimeBins(Float_t time_bins_) {time_bins=time_bins_;}
  Float_t          GetBaseline() {return baseline;}
  void             SetBaseline(Float_t baseline_) {baseline=baseline_;}
  vector<Float_t>& GetDigi() {return digi;}

  private:
  // copy and assignment private
//  I3RDMCWaveform(const I3RDMCWaveform &);
//  const I3RDMCWaveform& operator=(const I3RDMCWaveform&);

  // ROOT macro
  ClassDef(I3RDMCWaveform,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RDMCWaveform>::ThePolicy I3RDMCWaveformPtr;
#endif

