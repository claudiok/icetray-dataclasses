/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RDMCLaunch.h,v 1.6 2005/04/12 18:55:28 dule Exp $
 *
 * @file I3RDMCLaunch.h
 * @version $Revision: 1.6 $
 * @date $Date: 2005/04/12 18:55:28 $
 * @author ehrlich
 */
#ifndef I3RDMCLAUNCH_H
#define I3RDMCLAUNCH_H

#include <TObject.h>
#include <vector>
#include "dataclasses/I3DigitalLaunch.h"

using namespace std;

class I3RDMCLaunch : public I3DigitalLaunch
{
  int           id_;
  float         startTime_;
  float         binSize_;
  float         baseline_;
  vector<float> digi_;


  public:
  /**
   * constructor
   */
  I3RDMCLaunch() {id_=0; startTime_=0; binSize_=0; baseline_=0;}

  /**
   * destructor
   */
  virtual ~I3RDMCLaunch() {;}

  int            GetId() {return id_;}
  void             SetId(int id) {id_=id;}
  float          GetStartTime() {return startTime_;}
  void             SetStartTime(float start_time) {startTime_=start_time;}
  float          GetBinSize() {return binSize_;}
  void             SetBinSize(float bin_size) {binSize_=bin_size;}
  float          GetBaseline() {return baseline_;}
  void             SetBaseline(float baseline) {baseline_=baseline;}
  vector<float>& GetDigi() {return digi_;}

  private:

  // ROOT macro
  ClassDef(I3RDMCLaunch,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef shared_ptr<I3RDMCLaunch>  I3RDMCLaunchPtr;
#endif

