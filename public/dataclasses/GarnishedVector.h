/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: GarnishedVector.h,v 1.2 2004/02/20 04:04:18 troy Exp $

    @version $Revision: 1.2 $
    @date $Date: 2004/02/20 04:04:18 $
    @author Troy Straszheim

    @todo
*/
#ifndef I3GARNISHEDVECTOR_H
#define I3GARNISHEDVECTOR_H

#include <TObject.h>

using namespace std;

template 
<
  class HeaderType, 
  class ElementType, 
  class StoragePolicy
>
class GarnishedVector : public TObject, public HeaderType, public StoragePolicy
{
 public:

  void dump();

  GarnishedVector() {};
  ~GarnishedVector() {};
  
  ClassDef(GarnishedVector, 1);
};

#endif
