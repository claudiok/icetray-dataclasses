/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: OMKeyTest.cxx,v 1.2 2004/08/09 12:13:10 troy Exp $

    @version $Revision: 1.2 $
    @date $Date: 2004/08/09 12:13:10 $
    @author pretz

    @todo
*/

#include "TUT/tut.h"

#include "dataclasses/OMKey.h"
#include "TFile.h"
#include <string>
using std::string;
using std::cout;
using std::endl;

namespace tut
{
  struct OMKeyTest
  {
  };

  typedef test_group<OMKeyTest> factory;

  typedef factory::object object;
}

namespace
{
  tut::factory t("OMKeyTest");
}

namespace tut
{
  void object::test<1>() 
  {
    OMKey k(15,45);
    TFile file_out("test.out.root","RECREATE");
    k.Write();
    file_out.Close();
    
    TFile file_in("test.out.root");
    OMKey* key_in = (OMKey*) file_in.FindObjectAny("OMKey");

    ensure("pointer is non-zero",key_in!=0);
    
    ensure("OM Number is right",key_in->GetOM() == 45);
    ensure("String number is right",key_in->GetString() == 15);
  }

  void object::test<2>()
  {
    ensure("different keys are different",OMKey(1,1) != OMKey(1,2));
    ensure("different keys are different",OMKey(1,3) != OMKey(2,3));
    ensure("operator< works as expected",OMKey(1,0) < OMKey(1,1));
    ensure("operator< works as expected",OMKey(1,0) < OMKey(2,0));
    ensure("operator< works as expected",OMKey(1,1) < OMKey(2,2));
      
  }

}
