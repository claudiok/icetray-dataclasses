/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RDMCLaunch.h,v 1.2.2.1 2005/01/26 03:59:37 troy Exp $
 *
 * @file I3RDMCLaunch.h
 * @version $Revision: 1.2.2.1 $
 * @date $Date: 2005/01/26 03:59:37 $
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
  // copy and assignment private
  I3RDMCLaunch(const I3RDMCLaunch&);
  const I3RDMCLaunch& operator=(const I3RDMCLaunch&);

  // ROOT macro
  ClassDef(I3RDMCLaunch,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RDMCLaunch>::ThePolicy I3RDMCLaunchPtr;
#endif

