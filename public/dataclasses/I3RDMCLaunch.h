/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RDMCLaunch.h,v 1.5 2005/04/09 03:02:10 olivas Exp $
 *
 * @file I3RDMCLaunch.h
 * @version $Revision: 1.5 $
 * @date $Date: 2005/04/09 03:02:10 $
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
  int           id;
  float         start_time;
  float         bin_size;
  float         baseline;
  vector<float> digi;


  public:
  /**
   * constructor
   */
  I3RDMCLaunch() {id=0; start_time=0; bin_size=0; baseline=0;}

  /**
   * destructor
   */
  virtual ~I3RDMCLaunch() {;}

  int            GetId() {return id;}
  void             SetId(int id_) {id=id_;}
  float          GetStartTime() {return start_time;}
  void             SetStartTime(float start_time_) {start_time=start_time_;}
  float          GetBinSize() {return bin_size;}
  void             SetBinSize(float bin_size_) {bin_size=bin_size_;}
  float          GetBaseline() {return baseline;}
  void             SetBaseline(float baseline_) {baseline=baseline_;}
  vector<float>& GetDigi() {return digi;}

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

