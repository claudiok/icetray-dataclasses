/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3ArrayHitTest.cxx,v 1.5 2004/10/14 15:18:30 troy Exp $

    @version $Revision: 1.5 $
    @date $Date: 2004/10/14 15:18:30 $
    @author pretz

    @todo
*/

#include "TUT/tut.h"

#include "dataclasses/I3ArrayHit.h"
#include "TFile.h"
#include "TTree.h"
#include "services/I3Logging.h"
#include <string>
using std::string;
using std::cout;
using std::endl;

namespace tut
{
  struct I3ArrayHitTest
  {
  };

  typedef test_group<I3ArrayHitTest> factory;

  typedef factory::object object;
}

namespace
{
  static tut::factory t("I3ArrayHitTest");
}

namespace tut
{ 
  /**
   * check that constructor and destructor work
   */
  void object::test<1>() 
  {
     I3ArrayHitPtr ptr(new I3ArrayHit());
  }
  
  /**
   * check writing object to disk
   */
  void object::test<2>()
  {
     I3ArrayHitPtr ptr(new I3ArrayHit());

     /** @todo should fill some data for I3ArrayHit here */

     TFile f_out("test.out.root","RECREATE");
     ptr->Write();
     f_out.Close();

     TFile f_in("test.out.root");
     TObject* object_in =
		f_in.FindObjectAny("I3ArrayHit");
     f_in.Close();
     ensure("the read-in pointer is non-zero",object_in);
     
     I3ArrayHit* tested_in = dynamic_cast<I3ArrayHit*>(object_in);
     ensure("the read-in pointer is of the right type",tested_in);

     I3ArrayHitPtr ptr_in(tested_in);
    
    /** @todo should check the read-in data for I3ArrayHit here */

  }
   
   /**
    * check branching it to a tree
    */
   void object::test<3>(){
   I3ArrayHitPtr ptr(new I3ArrayHit());
   /** @todo add some setting of data here */
 
   I3ArrayHit* raw_ptr = &(*ptr);
   TTree tree("TestTree","Icecube");
   tree.Branch("branch","I3ArrayHit",&raw_ptr);
   
   tree.Fill();

   I3ArrayHit* raw_ptr_in = new I3ArrayHit();
   I3ArrayHitPtr ptr_in (raw_ptr_in);

   tree.SetBranchAddress("branch",&raw_ptr_in);
   tree.GetEvent(0);

   /** @todo add some checking of the data of I3ArrayHit here */

   }

   /**
    * check branching object to a tree, writing the tree to disk,
    * and reading the tree back in, and finding the object in the tree.
    */
   void object::test<4>(){
   I3ArrayHitPtr ptr(new I3ArrayHit());
   /** @todo add some setting of data here */
                                                                                
   I3ArrayHit* raw_ptr = &(*ptr);
   TTree tree("TestTree","Icecube");
   tree.Branch("branch","I3ArrayHit",&raw_ptr);
                                                                                
   tree.Fill();

   TFile file_out("test.out.root","RECREATE");
   tree.Write();
   file_out.Close();
                    

   TFile file_in("test.out.root");
   TTree* tree_in = (TTree*)file_in.FindObjectAny("TestTree");
   ensure("the test tree exists",tree_in);
                                                            
   I3ArrayHit* raw_ptr_in = new I3ArrayHit();
   I3ArrayHitPtr ptr_in (raw_ptr_in);
                                                                                
   tree_in->SetBranchAddress("branch",&raw_ptr_in);
   tree_in->GetEvent(0);

   /** @todo add some checking of the data of I3ArrayHit here */

   delete tree_in;
   }

   void object::test<5>()
   {
     I3ArrayHit the_class;
#warning FIXME:  this below breaks things on the mac.  Some funky stuff going on there.
     //     cout<<the_class<<"\n";
     cout<<the_class.ToString()<<"\n";
     //      log_debug("object written to debug %s\n",the_class.ToString().c_str());
   }
}