/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RDMCLaunch.h,v 1.2.2.3 2005/02/04 21:49:05 troy Exp $
 *
 * @file I3RDMCLaunch.h
 * @version $Revision: 1.2.2.3 $
 * @date $Date: 2005/02/04 21:49:05 $
 * @author ehrlich
 */
#ifndef I3RDMCLAUNCH_H
#define I3RDMCLAUNCH_H

#include <vector>
#include "dataclasses/I3DigitalLaunch.h"

using namespace std;

class I3RDMCLaunch : public I3DigitalLaunch
{
  Int_t           id;
  Float_t         start_time;
  Float_t         bin_size;
  Float_t         baseline;
  vector<Float_t> digi;


  public:
  /**
   * constructor
   */
  I3RDMCLaunch() {id=0; start_time=0; bin_size=0; baseline=0;}

  /**
   * destructor
   */
  virtual ~I3RDMCLaunch() {;}

  Int_t            GetId() {return id;}
  void             SetId(Int_t id_) {id=id_;}
  Float_t          GetStartTime() {return start_time;}
  void             SetStartTime(Float_t start_time_) {start_time=start_time_;}
  Float_t          GetBinSize() {return bin_size;}
  void             SetBinSize(Float_t bin_size_) {bin_size=bin_size_;}
  Float_t          GetBaseline() {return baseline;}
  void             SetBaseline(Float_t baseline_) {baseline=baseline_;}
  vector<Float_t>& GetDigi() {return digi;}

  private:

  // ROOT macro

};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RDMCLaunch>::ThePolicy I3RDMCLaunchPtr;
#endif

