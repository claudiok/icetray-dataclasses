#include "dataclasses/UniqueID.h"

ClassImp(UniqueID);

void ParticleID(I3ParticlePtr particle, UniqueID::IDOption option, Int_t &highestID)
{
  if(option==UniqueID::SET_ALL_NULL) particle->SetParticleID(0);
  Int_t id=particle->GetParticleID();
  if(id>highestID) highestID=id;
  if(option==UniqueID::SET_ALL_UNIQUE_ID && id==0) particle->SetParticleID(++highestID);
}

Int_t UniqueID::ID(TObjectPtr obj, IDOption option)
{
  return(0);
}

Int_t UniqueID::ID(I3MCEventPtr obj, IDOption option)
{
  Int_t highestID=0;
  
  I3MCParticleMultiMap::iterator iter1;
  I3MCParticleMultiMap &map1 = obj->GetMCParticleData().GetPrimary();
  for(iter1 = map1.begin(); iter1!= map1.end(); iter1++) ParticleID(iter1->second, option, highestID);
  I3MCParticleMultiMap &map2 = obj->GetMCParticleData().GetIceTopParticles();
  for(iter1 = map2.begin(); iter1!= map2.end(); iter1++) ParticleID(iter1->second, option, highestID);
  I3MCParticleMultiMap &map3 = obj->GetMCParticleData().GetInIceParticles();
  for(iter1 = map3.begin(); iter1!= map3.end(); iter1++) ParticleID(iter1->second, option, highestID);
      
    
  I3RecoResultDict &map4 = obj->GetRecoResultDict();
  I3RecoResultDict::iterator iter2;
  for(iter2 = map4.begin(); iter2!= map4.end(); iter2++)
  {
    I3RecoResult& recoresult=*iter2->second;
    if(recoresult.InheritsFrom("I3RecoResultMultiTracks"))
    {
      Int_t nparticle=((I3RecoResultMultiTracks&)recoresult).size();
      for(Int_t j=0; j<nparticle; j++) 
        ParticleID( ((I3RecoResultMultiTracks&)recoresult)[j], option, highestID);
    }
    if(recoresult.InheritsFrom("I3RecoResultSingleTrack"))
      ParticleID( ((I3RecoResultSingleTrack&)recoresult).GetTrack(), option, highestID);
  }
  
  return(highestID+1);
}

Int_t UniqueID::ID(I3MCParticleDataPtr obj, IDOption option)
{
  Int_t highestID=0;
  
  I3MCParticleMultiMap::iterator iter;
  I3MCParticleMultiMap &map1 = obj->GetPrimary();
  for(iter = map1.begin(); iter!= map1.end(); iter++) ParticleID(iter->second, option, highestID);
  I3MCParticleMultiMap &map2 = obj->GetIceTopParticles();
  for(iter = map2.begin(); iter!= map2.end(); iter++) ParticleID(iter->second, option, highestID);
  I3MCParticleMultiMap &map3 = obj->GetInIceParticles();
  for(iter = map3.begin(); iter!= map3.end(); iter++) ParticleID(iter->second, option, highestID);
  
  return(highestID+1);
}

Int_t UniqueID::ID(I3MCParticleMultiMapPtr obj, IDOption option)
{
  Int_t highestID=0;
  
  I3MCParticleMultiMap::iterator iter;
  for(iter = obj->begin(); iter!= obj->end(); iter++) ParticleID(iter->second, option, highestID);
  
  return(highestID+1);
}

Int_t UniqueID::ID(I3EventPtr obj, IDOption option)
{
  Int_t highestID=0;
  
  I3RecoResultDict &map = obj->GetRecoResultDict();
  I3RecoResultDict::iterator iter;
  for(iter = map.begin(); iter!= map.end(); iter++)
  {
    I3RecoResult& recoresult=*iter->second;
    if(recoresult.InheritsFrom("I3RecoResultMultiTracks"))
    {
      Int_t nparticle=((I3RecoResultMultiTracks&)recoresult).size();
      for(Int_t j=0; j<nparticle; j++) 
        ParticleID( ((I3RecoResultMultiTracks&)recoresult)[j], option, highestID);
    }
    if(recoresult.InheritsFrom("I3RecoResultSingleTrack"))
      ParticleID( ((I3RecoResultSingleTrack&)recoresult).GetTrack(), option, highestID);
  }
  
  return(highestID+1);
}

Int_t UniqueID::ID(I3RecoResultDictPtr obj, IDOption option)
{
  Int_t highestID=0;
  
  I3RecoResultDict::iterator iter;
  for(iter = obj->begin(); iter!= obj->end(); iter++)
  {
    I3RecoResult& recoresult=*iter->second;
    if(recoresult.InheritsFrom("I3RecoResultMultiTracks"))
    {
      Int_t nparticle=((I3RecoResultMultiTracks&)recoresult).size();
      for(Int_t j=0; j<nparticle; j++) 
        ParticleID( ((I3RecoResultMultiTracks&)recoresult)[j], option, highestID);
    }
    if(recoresult.InheritsFrom("I3RecoResultSingleTrack"))
      ParticleID( ((I3RecoResultSingleTrack&)recoresult).GetTrack(), option, highestID);
  }
  
  return(highestID+1);
}

Int_t UniqueID::ID(I3RecoResultPtr obj, IDOption option)
{
  Int_t highestID=0;
  
  if(obj->InheritsFrom("I3RecoResultMultiTracks"))
  {
    Int_t nparticle=roost::dynamic_pointer_cast<I3RecoResultMultiTracks>(obj)->size();
    for(Int_t j=0; j<nparticle; j++)
      ParticleID( (*roost::dynamic_pointer_cast<I3RecoResultMultiTracks>(obj))[j], option, highestID);
  }
  if(obj->InheritsFrom("I3RecoResultSingleTrack"))
    ParticleID( roost::dynamic_pointer_cast<I3RecoResultSingleTrack>(obj)->GetTrack(), option, highestID);
  
  return(highestID+1);
}

Int_t UniqueID::ID(I3ParticlePtr obj, IDOption option)
{
  Int_t highestID=0;
  ParticleID(obj, option, highestID);
  return(highestID+1);
}

