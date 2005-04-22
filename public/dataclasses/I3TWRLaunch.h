/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3TWRLaunch.h
 * @version $Revision: 1.6 $
 * @date $Date$
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
  int           id_;
  float         startTime_;
  float         binSize_;
  float         baseline_;
  vector<float> digi_;


  public:
  /**
   * constructor
   */
  I3TWRLaunch() {id_=0; startTime_=0; binSize_=0; baseline_=0;}

  /**
   * destructor
 */
  virtual ~I3TWRLaunch() {;}

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

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3DigitalLaunch", base_object<I3DigitalLaunch>(*this) );
    ar & make_nvp("ID", id_ );
    ar & make_nvp("StartTime", startTime_ );
    ar & make_nvp("BinSize", binSize_ );
    ar & make_nvp("Basline", baseline_ );
    ar & make_nvp("Digi", digi_ );
  }

  // ROOT macro
  ClassDef(I3TWRLaunch,1);
};

BOOST_SHARED_POINTER_EXPORT(I3TWRLaunch);

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef shared_ptr<I3TWRLaunch>  I3TWRLaunchPtr;
#endif

