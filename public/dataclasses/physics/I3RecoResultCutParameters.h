/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id: I3RecoResultCutParameters.h 12685 2005-11-17 15:04:25Z blaufuss $
 * @file I3RecoResultCutParameters.h
 * @date $Date: 2005-11-17 10:04:25 -0500 (Thu, 17 Nov 2005) $
 */

#ifndef I3RECORESULTCUTPARAMETERS_H_INCLUDED
#define I3RECORESULTCUTPARAMETERS_H_INCLUDED

#include "I3RecoResultSingleParticle.h"

/**
 * @brief This is a reco result container class which stores both InIce 
 * and IceTop reconstruction result objects plus the cut varios parameters
 * calculated from the reconstruction and the relevant hits.
 * 
 * The cut parameters are calculated using either all hits (after hit cleaning)
 * or only direct hits.  This is indicated by the suffix "all" or "dir".
 *
 * Direct hits are defined as hits inside a defined time window 
 * (something like -15ns,+25ns by default) around the expected arrival time
 * of the photon.
 *
 * @todo Add other cut parameters to the container......
 */
class I3RecoResultCutParameters : public I3RecoResultSingleParticle
{
 private:
  int Ndir_;
  double Ldir_;
  double Sdir_;
  double Sall_;
  
  // TDS FIXME most of this has/get/set stuff can go away.  You just
  // get the pointer out, it either points to something valid or it
  // points to nothing.

 public:
  I3RecoResultCutParameters() { }
  virtual ~I3RecoResultCutParameters();

  /**
   * The number of direct hits. 
   */
  void SetNdir(int val) { Ndir_ = val; }
  const int GetNdir() const { return Ndir_; }

  /**
   * The "length of muon" based on direct hits.  This is obtained by 
   * projecting all direct hits onto the given muon reco track and 
   * calculating the distance between the two farthest hit projections 
   * on the track.  
   */
  void SetLdir(double val) { Ldir_ = val; }
  const double GetLdir() const { return Ldir_; }

  /**
   * The "smoothness" of the muon track (as defined in the AMANDA muon 
   * reconstruction paper) calculated using direct hits only.
   */
  void SetSdir(double val) { Sdir_ = val; }
  const double GetSdir() const { return Sdir_; }

  /**
   * The "smoothness" of the muon track (as defined in the AMANDA muon 
   * reconstruction paper) calculated using all hits.
   */
  void SetSall(double val) { Sall_ = val; }
  const double GetSall() const { return Sall_; }

  /**
   * Puts the contents of the container (a reco result) into the stream
   */
  virtual void ToStream(ostream& o) const;
  
 private:

  friend class boost::serialization::access;
  template <class Archive> void serialize(Archive & ar, unsigned version);

};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3RecoResultCutParameters> I3RecoResultCutParametersPtr;

#endif //I3RECORESULTCUTPARAMETERS_H_INCLUDED

