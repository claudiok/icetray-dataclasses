/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TWRLaunch.h,v 1.2 2005/02/21 06:47:54 ehrlich Exp $
 *
 * @file I3TWRLaunch.h
 * @version $Revision: 1.2 $
 * @date $Date: 2005/02/21 06:47:54 $
 * @author ehrlich
 */
#ifndef I3TWRLAUNCH_H
#define I3TWRLAUNCH_H

#include <TObject.h>
#include <vector>
#include "dataclasses/I3DigitalLaunch.h"

using namespace std;

class I3TWRLaunch : public I3DigitalLaunch
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
  I3TWRLaunch() {id=0; start_time=0; bin_size=0; baseline=0;}

  /**
   * destructor
   */
  virtual ~I3TWRLaunch() {;}

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
  ClassDef(I3TWRLaunch,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3TWRLaunch>::ThePolicy I3TWRLaunchPtr;
#endif

