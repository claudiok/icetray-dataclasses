#include "dataclasses/I3Bag.h"

#include "TMap.h"
#include "TNamed.h"

#include "dataclasses/I3DataExecution.h"
#include <iostream>

using namespace std;

ClassImp(I3Bag);

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
  TPair* pair = (TPair*)fMap->FindObject(key);
  return *(pair->Value());
}

Bool_t I3Bag::HasObject(const Char_t* key,const Char_t* type)
{
  if(!fMap)
    {
      cout<<"the map doesn't exist"<<endl;
      return kFALSE;
    }
  TObject* to_check = fMap->FindObject(key);
  if(!to_check)
    {
      cout<<"Didn't succeed in getting the object"<<endl;
      return kFALSE; 
    }
  TPair *pair = (TPair*)to_check;
  if(!pair->Value()->InheritsFrom(type))
    {
      cout<<"The inheritance isn't right"<<endl;
      return kFALSE;
    }
  return kTRUE;
}
