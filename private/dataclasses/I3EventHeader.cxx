#include "dataclasses/I3EventHeader.h"

ClassImp(I3EventHeader);

I3EventHeader::I3EventHeader()
{
}

I3EventHeader::~I3EventHeader()
{
}

const Char_t* I3EventHeader::GetDataStream()
{
  return "Physics";
}

