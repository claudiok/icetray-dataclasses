#include "dataclasses/I3GeometryDataHeader.h"

ClassImp(I3GeometryDataHeader);

I3GeometryDataHeader::I3GeometryDataHeader()
  : fNumOms(-1),
    fNumStrings(-1){
}

I3GeometryDataHeader::~I3GeometryDataHeader(){
}

Int_t I3GeometryDataHeader::GetNumOms(){
  return fNumOms;
}

Int_t I3GeometryDataHeader::GetNumStrings(){
  return fNumStrings;
}

const Char_t* I3GeometryDataHeader::GetArrayName(){
  return fArrayName.Data();
}

const Char_t* I3GeometryDataHeader::GetDataStream(){
  return "Geometry";
}

void I3GeometryDataHeader::SetNumOms(Int_t oms){
  fNumOms = oms;
}

void I3GeometryDataHeader::SetNumStrings(Int_t strings){
  fNumStrings = strings;
}


void I3GeometryDataHeader::SetArrayName(const Char_t* name){
  fArrayName.Resize(0);
  fArrayName.Append(name);
}
