/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoTrackComposite.h,v 1.6 2004/03/10 20:21:45 pretz Exp $

    @version $Revision: 1.6 $
    @date $Date: 2004/03/10 20:21:45 $
    @author

    @todo

*/
#ifndef TI3RECOTRACKCOMPOSITE_H
#define TI3RECOTRACKCOMPOSITE_H

#include <TObject.h>
#include "I3RecoTrack.h"

class I3RecoTrackComposite : public I3RecoTrack
{
  TObjArray *constituent;

  public: 
           I3RecoTrackComposite();
  virtual ~I3RecoTrackComposite();

  UShort_t GetNumberConstituents() const;
  const I3RecoTrack& GetConstituent(UShort_t number) const;
  void AddConstituent(I3RecoTrack* constituent_);

  ClassDef(I3RecoTrackComposite, 1);
};
#endif

