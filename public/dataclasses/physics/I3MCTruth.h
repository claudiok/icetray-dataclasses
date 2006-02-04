/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id: I3MCTruth.h 15115 2006-02-01 02:10:03Z olivas $
 * @file I3MCTruth.h
 * @date $Date: 2006-01-31 21:10:03 -0500 (Tue, 31 Jan 2006) $
 */

#ifndef I3MCTRUTH_H_INCLUDED
#define I3MCTRUTH_H_INCLUDED

#include "TObject.h"
#include "dataclasses/StoragePolicy.h"
#include <string>

class I3MCTruth : public TObject
{
 public:

  virtual ~I3MCTruth();

  enum MCID { PLEASE, BE, CAREFUL, COMMITING, WHEN, ITS, THREE, DAYS, TO, THE, WORKSHOP, Null };

  I3MCTruth():
    mcID_(Null),
    mcLength_(NAN)
    {};


  /**
   * enumerated type of the different paricles.
   * follows the f2k convention for numbering
   */

 const double GetLength() const { return mcLength_;}
 
 void SetLength(double& mcLength){mcLength_ = mcLength;}

 private:

  MCID mcID_;
  double mcLength_;

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

typedef shared_ptr<I3MCTruth>  I3MCTruthPtr;
#endif //I3PARTICLE_H_INCLUDED
