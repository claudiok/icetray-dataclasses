/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: AugVec.h,v 1.1 2004/02/20 21:42:08 troy Exp $

    @version $Revision: 1.1 $
    @date $Date: 2004/02/20 21:42:08 $
    @author Troy Straszheim

    @todo
*/
#ifndef I3AUGVEC_H
#define I3AUGVEC_H

#include <TObject.h>

using namespace std;

template 
<
  class HeaderType, 
  class ElementType, 
  class StoragePolicy
>
class AugVec : public TObject, public HeaderType, public StoragePolicy
{
 public:

  void dump();

  AugVec() {};
  ~AugVec() {};
  
  ClassDef(AugVec, 1);
};

#endif
