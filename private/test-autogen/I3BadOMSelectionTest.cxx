/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3BadOMSelectionTest.cxx,v 1.1 2005/02/08 20:53:52 pretz Exp $

    @version $Revision: 1.1 $
    @date $Date: 2005/02/08 20:53:52 $
    @author pretz

    @todo
*/

#include "TUT/tut.h"

#include "dataclasses/I3BadOMSelection.h"
#include "TFile.h"
#include "TTree.h"
#include "services/I3Logging.h"
#include <string>
using std::string;
using std::cout;
using std::endl;

namespace tut
{
  struct I3BadOMSelectionTest
  {
  };

  typedef test_group<I3BadOMSelectionTest> factory;

  typedef factory::object object;
}

namespace
{
  tut::factory t("I3BadOMSelectionTest");
}

namespace tut
{ 
  /**
   * check that constructor and destructor work
   */
  void object::test<1>() 
  {
     I3BadOMSelectionPtr ptr(new I3BadOMSelection());
  }
  
  /**
   * check writing object to disk
   */
  void object::test<2>()
  {
     I3BadOMSelectionPtr ptr(new I3BadOMSelection());

     /** @todo should fill some data for I3BadOMSelection here */

     TFile f_out("test.out.root","RECREATE");
     ptr->Write();
     f_out.Close();

     TFile f_in("test.out.root");
     TObject* object_in =
		f_in.FindObjectAny("I3BadOMSelection");
     f_in.Close();
     ensure("the read-in pointer is non-zero",object_in);
     
     I3BadOMSelection* tested_in = dynamic_cast<I3BadOMSelection*>(object_in);
     ensure("the read-in pointer is of the right type",tested_in);

     I3BadOMSelectionPtr ptr_in(tested_in);
    
    /** @todo should check the read-in data for I3BadOMSelection here */

  }
   
   /**
    * check branching it to a tree
    */
   void object::test<3>(){
   I3BadOMSelectionPtr ptr(new I3BadOMSelection());
   /** @todo add some setting of data here */
 
   I3BadOMSelection* raw_ptr = &(*ptr);
   TTree tree("TestTree","Icecube");
   tree.Branch("branch","I3BadOMSelection",&raw_ptr);
   
   tree.Fill();

   I3BadOMSelection* raw_ptr_in = new I3BadOMSelection();
   I3BadOMSelectionPtr ptr_in (raw_ptr_in);

   tree.SetBranchAddress("branch",&raw_ptr_in);
   tree.GetEvent(0);

   /** @todo add some checking of the data of I3BadOMSelection here */

   }

   /**
    * check branching object to a tree, writing the tree to disk,
    * and reading the tree back in, and finding the object in the tree.
    */
   void object::test<4>(){
   I3BadOMSelectionPtr ptr(new I3BadOMSelection());
   /** @todo add some setting of data here */
                                                                                
   I3BadOMSelection* raw_ptr = &(*ptr);
   TTree tree("TestTree","Icecube");
   tree.Branch("branch","I3BadOMSelection",&raw_ptr);
                                                                                
   tree.Fill();

   TFile file_out("test.out.root","RECREATE");
   tree.Write();
   file_out.Close();
                    

   TFile file_in("test.out.root");
   TTree* tree_in = (TTree*)file_in.FindObjectAny("TestTree");
   ensure("the test tree exists",tree_in);
                                                            
   I3BadOMSelection* raw_ptr_in = new I3BadOMSelection();
   I3BadOMSelectionPtr ptr_in (raw_ptr_in);
                                                                                
   tree_in->SetBranchAddress("branch",&raw_ptr_in);
   tree_in->GetEvent(0);

   /** @todo add some checking of the data of I3BadOMSelection here */

   delete tree_in;
   }

   void object::test<5>(){
      I3BadOMSelection the_class;
      cout<<the_class<<"\n";
      cout<<the_class.ToString()<<"\n";
      log_debug("object written to debug %s\n",the_class.ToString().c_str());
   }
}
