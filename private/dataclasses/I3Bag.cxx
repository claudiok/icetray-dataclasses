#include "dataclasses/I3Bag.h"

#include "TMap.h"
#include "TNamed.h"

#include "dataclasses/I3DataExecution.h"

I3Bag::I3Bag() :
  fMap(0)
{
}

I3Bag::~I3Bag()
{
  if(fMap){
    fMap->DeleteAll();
    delete fMap;
  }
}

Bool_t I3Bag::AddObject(TObject* obj,const Char_t* key)
{
  if(0==fMap)
    fMap = new TMap();

  if(fMap->FindObject(key))
    return kFALSE;
  
  fMap->Add(new TNamed(key,""),obj);
  return kTRUE;
}

const TObject& I3Bag::GetObject(const Char_t* key, const Char_t* type)
{
  if(!HasObject(key,type)){
    I3DataExecution::Instance().Fatal("I3Bag::GetObject() the named object isn't present");
    return *(TObject*)0;
  }
  TObject* to_return = fMap->FindObject(key);
  return *to_return;
}

Bool_t I3Bag::HasObject(const Char_t* key,const Char_t* type)
{
  if(!fMap)
    return kFALSE;
  TObject* to_check = fMap->FindObject(key);
  if(!to_check)
    return kFALSE;
  if(!to_check->InheritsFrom(type))
    return kFALSE;
  return kTRUE;
}
