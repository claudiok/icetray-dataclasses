/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MCPMTResponseTest.cxx,v 1.1 2004/08/12 17:33:32 pretz Exp $

    @version $Revision: 1.1 $
    @date $Date: 2004/08/12 17:33:32 $
    @author pretz

    @todo
*/

#include "TUT/tut.h"

#include "dataclasses/I3MCPMTResponse.h"
#include "TFile.h"
#include "TTree.h"
#include <string>
using std::string;
using std::cout;
using std::endl;

namespace tut
{
  struct I3MCPMTResponseTest
  {
  };

  typedef test_group<I3MCPMTResponseTest> factory;

  typedef factory::object object;
}

namespace
{
  tut::factory t("I3MCPMTResponseTest");
}

namespace tut
{ 
  /**
   * check that constructor and destructor work
   */
  void object::test<1>() 
  {
     I3MCPMTResponsePtr ptr(new I3MCPMTResponse());
  }
  
  /**
   * check writing object to disk
   */
  void object::test<2>()
  {
     I3MCPMTResponsePtr ptr(new I3MCPMTResponse());

     /** @todo should fill some data for I3MCPMTResponse here */

     TFile f_out("test.out.root","RECREATE");
     ptr->Write();
     f_out.Close();

     TFile f_in("test.out.root");
     TObject* object_in =
		f_in.FindObjectAny("I3MCPMTResponse");
     f_in.Close();
     ensure("the read-in pointer is non-zero",object_in);
     
     I3MCPMTResponse* tested_in = dynamic_cast<I3MCPMTResponse*>(object_in);
     ensure("the read-in pointer is of the right type",tested_in);

     I3MCPMTResponsePtr ptr_in(tested_in);
    
    /** @todo should check the read-in data for I3MCPMTResponse here */

  }
   
   /**
    * check branching it to a tree
    */
   void object::test<3>(){
   I3MCPMTResponsePtr ptr(new I3MCPMTResponse());
   /** @todo add some setting of data here */
 
   I3MCPMTResponse* raw_ptr = &(*ptr);
   TTree tree("TestTree","Icecube");
   tree.Branch("branch","I3MCPMTResponse",&raw_ptr);
   
   tree.Fill();

   I3MCPMTResponse* raw_ptr_in = new I3MCPMTResponse();
   I3MCPMTResponsePtr ptr_in (raw_ptr_in);

   tree.SetBranchAddress("branch",&raw_ptr_in);
   tree.GetEvent(0);

   /** @todo add some checking of the data of I3MCPMTResponse here */

   }

   /**
    * check branching object to a tree, writing the tree to disk,
    * and reading the tree back in, and finding the object in the tree.
    */
   void object::test<4>(){
   I3MCPMTResponsePtr ptr(new I3MCPMTResponse());
   /** @todo add some setting of data here */
                                                                                
   I3MCPMTResponse* raw_ptr = &(*ptr);
   TTree tree("TestTree","Icecube");
   tree.Branch("branch","I3MCPMTResponse",&raw_ptr);
                                                                                
   tree.Fill();

   TFile file_out("test.out.root","RECREATE");
   tree.Write();
   file_out.Close();
                    

   TFile file_in("test.out.root");
   TTree* tree_in = (TTree*)file_in.FindObjectAny("TestTree");
   ensure("the test tree exists",tree_in);
                                                            
   I3MCPMTResponse* raw_ptr_in = new I3MCPMTResponse();
   I3MCPMTResponsePtr ptr_in (raw_ptr_in);
                                                                                
   tree_in->SetBranchAddress("branch",&raw_ptr_in);
   tree_in->GetEvent(0);

   /** @todo add some checking of the data of I3MCPMTResponse here */

   delete tree_in;
   }
}
