/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: AugHashMap.h,v 1.1 2004/02/20 04:08:35 troy Exp $

    @version $Revision: 1.1 $
    @date $Date: 2004/02/20 04:08:35 $
    @author Troy Straszheim

    @todo
*/
#ifndef I3AUGHASHMAP_H
#define I3AUGHASHMAP_H

#include <TObject.h>

using namespace std;

template 
<
  class HeaderType, 
  class ElementType, 
  class StoragePolicy
>
class AugHashMap : public TObject, public HeaderType, public StoragePolicy
{
 public:

  void dump();

  AugHashMap() {};
  ~AugHashMap() {};
  
  ClassDef(AugHashMap, 1);
};

#endif
