/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: GarnishedVector.h,v 1.1 2004/02/15 02:42:03 troy Exp $

    @version $Revision: 1.1 $
    @date $Date: 2004/02/15 02:42:03 $
    @author Troy Straszheim

    @todo
*/
#ifndef I3HITSERIES_H
#define I3HITSERIES_H

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
