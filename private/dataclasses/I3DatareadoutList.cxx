#include "dataclasses/I3DatareadoutList.h"

ClassImp(I3DatareadoutList);

I3DatareadoutList::I3DatareadoutList()  {datareadout=NULL; }
I3DatareadoutList::~I3DatareadoutList() {if (datareadout)  {datareadout->Delete();  delete datareadout;}  }

int                  I3DatareadoutList::GetNumberDatareadouts() const               {return((datareadout==NULL) ? 0 : datareadout->GetEntriesFast());}
const I3Datareadout* I3DatareadoutList::GetDatareadout(unsigned short number) const {return((GetNumberDatareadouts()<=number) ? NULL : (I3Datareadout*)datareadout->At(number));}
void                 I3DatareadoutList::AddDatareadout(I3Datareadout* datareadout_) {if(datareadout==NULL) datareadout = new TObjArray(1); datareadout->Add(datareadout_);}

