/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: AugVec.h,v 1.2 2004/02/21 13:35:10 pretz Exp $

    @version $Revision: 1.2 $
    @date $Date: 2004/02/21 13:35:10 $
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

  void dump(){};

  AugVec() {};
  ~AugVec() {};
  
  ClassDef(AugVec, 1);
};

#endif
