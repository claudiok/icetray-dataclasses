/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: GarnishedVector.cxx,v 1.1 2004/02/15 02:42:03 troy Exp $

    @version $Revision: 1.1 $
    @date $Date: 2004/02/15 02:42:03 $
    @author Troy Straszheim

*/
#include <TObject.h>
#include "dataclasses/GarnishedVector.h"

#include <iostream>

templateClassImp(VectorPlus);

template <class HeaderType, class ElementType, class StoragePolicy>
void GarnishedVector<HeaderType, ElementType, StoragePolicy>::dump()
{
  cout << "[GarnishedVector: " << endl; 
  for (unsigned i=0; i<size(); i++)
    {
      cout << operator[](i) << endl;
    }
  cout << "]" << endl;
}  

