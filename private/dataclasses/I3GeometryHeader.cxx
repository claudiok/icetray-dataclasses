#include "dataclasses/I3GeometryHeader.h"

ClassImp(I3GeometryHeader);

I3GeometryHeader::I3GeometryHeader()
  : fNumOms(-1),
    fNumStrings(-1){
}

I3GeometryHeader::~I3GeometryHeader(){
}

Int_t I3GeometryHeader::GetNumOms(){
  return fNumOms;
}

Int_t I3GeometryHeader::GetNumStrings(){
  return fNumStrings;
}

const Char_t* I3GeometryHeader::GetArrayName(){
  return fArrayName.Data();
}

const Char_t* I3GeometryHeader::GetDataStream(){
  return "Geometry";
}

void I3GeometryHeader::SetNumOms(Int_t oms){
  fNumOms = oms;
}

void I3GeometryHeader::SetNumStrings(Int_t strings){
  fNumStrings = strings;
}

void I3GeometryHeader::SetArrayName(const Char_t* name){
  fArrayName.Resize(0);
  fArrayName.Append(name);
}
