/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: JAMSFitTrack.h,v 1.2 2005/01/04 16:03:56 dule Exp $

    @file I3JAMSTrack.h
    @version $Revision: 1.2 $
    @date $Date: 2005/01/04 16:03:56 $
    @author dule
*/

#ifndef JAMSFITTRACK_H
#define JAMSFITTRACK_H

#include "dataclasses/I3BasicTrack.h"

/**
 * @brief A track class to store the results of the JAMS fit
 */
class JAMSFitTrack : public I3BasicTrack
{
 private:

  // Additional variables for the JAMS track.  Obtained from InitResult().
  Double_t fNDirect;
  Double_t fSigRho;
  Double_t fSigL;
  Double_t fSigPsi;
  Double_t fQ;
  Double_t fNhitLH;
  Double_t fLLHt;
  Double_t fLLHxy;

 public:

  /**
   * Default constructor - sets all JAMS variables to NAN
   */
  JAMSFitTrack():
    fNDirect(NAN),
    fSigRho(NAN),
    fSigL(NAN),
    fSigPsi(NAN),
    fQ(NAN),
    fNhitLH(NAN),
    fLLHt(NAN),
    fLLHxy(NAN)
    {};

  /**
   * Default destructor
   */
  virtual ~JAMSFitTrack() {};

  /**
   * NDirect
   */
  void SetNDirect(Double_t val) { fNDirect = val; }
  Double_t GetNDirect() { return fNDirect; }

  /**
   * SigRho
   */
  void SetSigRho(Double_t val) { fSigRho = val; }
  Double_t GetSigRho() { return fSigRho; }

  /**
   * SigL
   */
  void SetSigL(Double_t val) { fSigL = val; }
  Double_t GetSigL() { return fSigL; }

  /**
   * SigPsi
   */
  void SetSigPsi(Double_t val) { fSigPsi = val; }
  Double_t GetSigPsi() { return fSigPsi; }

  /**
   * Quality of fit
   */
  void SetQ(Double_t val) { fQ = val; }
  Double_t GetQ() { return fQ; }

  /**
   * NhitLH
   */
  void SetNHitLH(Double_t val) { fNhitLH = val; }
  Double_t GetNHitLH() { return fNhitLH; }

  /**
   * LLHt
   */
  void SetLLHt(Double_t val) { fLLHt = val; }
  Double_t GetLLHt() { return fLLHt; }

  /**
   * LLHxy
   */
  void SetLLHxy(Double_t val) { fLLHxy = val; }
  Double_t GetLLHxy() { return fLLHxy; }


  // Extend the ToStream method
  virtual void ToStream(ostream& o) const
    {
      I3BasicTrack::ToStream(o);
      o<<"NDirect: "<<fNDirect<<"\n"
       <<"SigRho: "<<fSigRho<<"\n"
       <<"SigL: "<<fSigL<<"\n"
       <<"SigPsi: "<<fSigPsi<<"\n"
       <<"Q: "<<fQ<<"\n"
       <<"NhitLH: "<<fNhitLH<<"\n"
       <<"LLHt: "<<fLLHt<<"\n"
       <<"LLHxy: "<<fLLHxy<<"\n";
    }

  //ROOT macro
  ClassDef(JAMSFitTrack,1);
};

typedef PtrPolicy<JAMSFitTrack>::ThePolicy JAMSFitTrackPtr;

#endif
