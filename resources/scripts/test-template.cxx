/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: test-template.cxx,v 1.2 2004/08/16 16:22:14 pretz Exp $

    @version $Revision: 1.2 $
    @date $Date: 2004/08/16 16:22:14 $
    @author pretz

    @todo
*/

#include "TUT/tut.h"

#include "dataclasses/__TESTED_CLASS__.h"
#include "TFile.h"
#include "TTree.h"
#include <string>
using std::string;
using std::cout;
using std::endl;

namespace tut
{
  struct __TESTED_CLASS__Test
  {
  };

  typedef test_group<__TESTED_CLASS__Test> factory;

  typedef factory::object object;
}

namespace
{
  tut::factory t("__TESTED_CLASS__Test");
}

namespace tut
{ 
  /**
   * check that constructor and destructor work
   */
  void object::test<1>() 
  {
     __TESTED_CLASS__Ptr ptr(new __TESTED_CLASS__());
  }
  
  /**
   * check writing object to disk
   */
  void object::test<2>()
  {
     __TESTED_CLASS__Ptr ptr(new __TESTED_CLASS__());

     /** @todo should fill some data for __TESTED_CLASS__ here */

     TFile f_out("test.out.root","RECREATE");
     ptr->Write();
     f_out.Close();

     TFile f_in("test.out.root");
     TObject* object_in =
		f_in.FindObjectAny("__TESTED_CLASS__");
     f_in.Close();
     ensure("the read-in pointer is non-zero",object_in);
     
     __TESTED_CLASS__* tested_in = dynamic_cast<__TESTED_CLASS__*>(object_in);
     ensure("the read-in pointer is of the right type",tested_in);

     __TESTED_CLASS__Ptr ptr_in(tested_in);
    
    /** @todo should check the read-in data for __TESTED_CLASS__ here */

  }
   
   /**
    * check branching it to a tree
    */
   void object::test<3>(){
   __TESTED_CLASS__Ptr ptr(new __TESTED_CLASS__());
   /** @todo add some setting of data here */
 
   __TESTED_CLASS__* raw_ptr = &(*ptr);
   TTree tree("TestTree","Icecube");
   tree.Branch("branch","__TESTED_CLASS__",&raw_ptr);
   
   tree.Fill();

   __TESTED_CLASS__* raw_ptr_in = new __TESTED_CLASS__();
   __TESTED_CLASS__Ptr ptr_in (raw_ptr_in);

   tree.SetBranchAddress("branch",&raw_ptr_in);
   tree.GetEvent(0);

   /** @todo add some checking of the data of __TESTED_CLASS__ here */

   }

   /**
    * check branching object to a tree, writing the tree to disk,
    * and reading the tree back in, and finding the object in the tree.
    */
   void object::test<4>(){
   __TESTED_CLASS__Ptr ptr(new __TESTED_CLASS__());
   /** @todo add some setting of data here */
                                                                                
   __TESTED_CLASS__* raw_ptr = &(*ptr);
   TTree tree("TestTree","Icecube");
   tree.Branch("branch","__TESTED_CLASS__",&raw_ptr);
                                                                                
   tree.Fill();

   TFile file_out("test.out.root","RECREATE");
   tree.Write();
   file_out.Close();
                    

   TFile file_in("test.out.root");
   TTree* tree_in = (TTree*)file_in.FindObjectAny("TestTree");
   ensure("the test tree exists",tree_in);
                                                            
   __TESTED_CLASS__* raw_ptr_in = new __TESTED_CLASS__();
   __TESTED_CLASS__Ptr ptr_in (raw_ptr_in);
                                                                                
   tree_in->SetBranchAddress("branch",&raw_ptr_in);
   tree_in->GetEvent(0);

   /** @todo add some checking of the data of __TESTED_CLASS__ here */

   delete tree_in;
   }

   void object::test<5>(){
      __TESTED_CLASS__ the_class;
      cout<<the_class<<"\n";
   }
}
