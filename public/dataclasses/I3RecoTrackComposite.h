#ifndef TI3RECOTRACKCOMPOSITE_H
#define TI3RECOTRACKCOMPOSITE_H

#include <TObject.h>
#include "I3RecoTrack.h"
/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoTrackComposite.h,v 1.7 2004/03/14 15:07:12 pretz Exp $

    @version $Revision: 1.7 $
    @date $Date: 2004/03/14 15:07:12 $
    @author

    @todo isn't this class rendered obsolete by the new Track stuff???

*/
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

