/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoResultSingleTrack.cxx,v 1.6 2004/02/26 18:53:11 pretz Exp $

    @version $Revision: 1.6 $
    @date $Date: 2004/02/26 18:53:11 $
    @author

    @todo

*/
#include "dataclasses/I3DataExecution.h"
#include "dataclasses/I3RecoResultSingleTrack.h"

ClassImp(I3RecoResultSingleTrack);

const I3RecoTrack& 
I3RecoResultSingleTrack::operator[](UShort_t tracklistindex) const 
{
  if(size()>tracklistindex) 
    return I3RecoResult::operator[](tracklistindex)[0];
  else
    I3DataExecution::Instance().Fatal("I3RecoResultSingleTrack::GetSingleRecoTrack() asked for an index out of bounds or a track which doesn't exist");
  return(*(I3RecoTrack*)NULL);
}


