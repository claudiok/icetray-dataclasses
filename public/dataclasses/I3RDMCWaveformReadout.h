/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RDMCWaveformReadout.h,v 1.1 2004/09/14 03:21:38 ehrlich Exp $
 *
 * @file I3RDMCWaveformReadout.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/09/14 03:21:38 $
 * @author ehrlich
 */
#ifndef I3RDMCWAVEFORMREADOUT_H
#define I3RDMCWAVEFORMREADOUT_H

#include "dataclasses/I3DataReadout.h"
#include "dataclasses/I3RDMCWaveform.h"
#include "StoragePolicy.h"

class I3RDMCWaveformReadout : public I3DataReadout, public VectorPolicy<I3RDMCWaveform>::ThePolicy
{
  public:
  /**
   * constructor
   */
  I3RDMCWaveformReadout(){}

  /**
   * destructor
   */
  virtual ~I3RDMCWaveformReadout() {;}


  private:
  // copy and assignment private
  I3RDMCWaveformReadout(const I3RDMCWaveformReadout &);
  const I3RDMCWaveformReadout& operator=(const I3RDMCWaveformReadout&);

  // ROOT macro
  ClassDef(I3RDMCWaveformReadout,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RDMCWaveformReadout>::ThePolicy I3RDMCWaveformReadoutPtr;
#endif

