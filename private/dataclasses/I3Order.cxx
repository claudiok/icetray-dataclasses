#include "dataclasses/I3Order.h"

ClassImp(I3Order);
  
I3Order::I3Order() {;}
    
int         I3Order::GetIndex()                  {return index;}
const char* I3Order::GetEventtype()              {return eventtype;}
void        I3Order::SetIndex(int i)             {index=i;}
void        I3Order::SetEventtype(const char* c) {strcpy(eventtype,c);}
