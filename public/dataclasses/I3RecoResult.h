#ifndef I3RECORESULT_H
#define I3RECORESULT_H

/**
 * Class: I3RecoResult
 *
 * Version: $Id: I3RecoResult.h,v 1.7 2004/01/30 22:31:23 ehrlich Exp $
 *
 * Date: 30 Jan 2004
 *
 * (c) 2004 IceCube Collaboration
 */

#include <TObject.h>
#include <TObjArray.h>
#include "I3RecoTrackList.h"
#include "dataclasses/I3Iterator.h"

/**
 * I3RecoResult 
 * Each reconstruction method may have more than one solution. 
 * These solutions are stored into different track lists 
 * (every solution may have more than one reconstructed track 
 * which are grouped into track lists). These track lists can be
 * accessed here.
 * Since there are reconstruction methods which give simpler results,
 * (e.g. single likelihood gives only single tracks or double muon 
 * reconstruction gives only one solution with two tracks) there are
 * "convenience" classes which are inherited from this class.
 * These "convenience" classes are there to provide an interface 
 * for simpler access to the reconstructed tracks. The data itself is
 * still stored as provided in this class, so that the tracks can also
 * be accessed by this class without the need of recasting.
 * @version $Id: I3RecoResult.h,v 1.7 2004/01/30 22:31:23 ehrlich Exp $
 * @author Ralf Ehrlich
 */
class I3RecoResult : public TObject
{
  protected:
  TObjArray     *recotracklist;
  TRef          bestrecotracklist;

  public:
           I3RecoResult();
  virtual ~I3RecoResult();

  const char* GetRecomethod() const;

  int GetNumberRecoTrackLists() const;
  const I3RecoTrackList& GetRecoTrackList(unsigned short index) const;
  void AddRecoTrackList(I3RecoTrackList* recotracklist_);
  I3Iterator<const I3RecoTrackList>* MakeRecoTrackListIterator();

  bool HasBestRecoTrackList() const;
  const I3RecoTrackList& GetBestRecoTrackList() const;
  void SetBestRecoTrackList(I3RecoTrackList& bestrecotracklist_);

  ClassDef(I3RecoResult, 1);
};
#endif
