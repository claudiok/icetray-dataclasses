/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3TWRLaunchTest.cxx,v 1.1 2004/08/12 17:33:32 pretz Exp $

    @version $Revision: 1.1 $
    @date $Date: 2004/08/12 17:33:32 $
    @author pretz

    @todo
*/

#include "TUT/tut.h"

#include "dataclasses/I3TWRLaunch.h"
#include "TFile.h"
#include "TTree.h"
#include <string>
using std::string;
using std::cout;
using std::endl;

namespace tut
{
  struct I3TWRLaunchTest
  {
  };

  typedef test_group<I3TWRLaunchTest> factory;

  typedef factory::object object;
}

namespace
{
  tut::factory t("I3TWRLaunchTest");
}

namespace tut
{ 
  /**
   * check that constructor and destructor work
   */
  void object::test<1>() 
  {
     I3TWRLaunchPtr ptr(new I3TWRLaunch());
  }
  
  /**
   * check writing object to disk
   */
  void object::test<2>()
  {
     I3TWRLaunchPtr ptr(new I3TWRLaunch());

     /** @todo should fill some data for I3TWRLaunch here */

     TFile f_out("test.out.root","RECREATE");
     ptr->Write();
     f_out.Close();

     TFile f_in("test.out.root");
     TObject* object_in =
		f_in.FindObjectAny("I3TWRLaunch");
     f_in.Close();
     ensure("the read-in pointer is non-zero",object_in);
     
     I3TWRLaunch* tested_in = dynamic_cast<I3TWRLaunch*>(object_in);
     ensure("the read-in pointer is of the right type",tested_in);

     I3TWRLaunchPtr ptr_in(tested_in);
    
    /** @todo should check the read-in data for I3TWRLaunch here */

  }
   
   /**
    * check branching it to a tree
    */
   void object::test<3>(){
   I3TWRLaunchPtr ptr(new I3TWRLaunch());
   /** @todo add some setting of data here */
 
   I3TWRLaunch* raw_ptr = &(*ptr);
   TTree tree("TestTree","Icecube");
   tree.Branch("branch","I3TWRLaunch",&raw_ptr);
   
   tree.Fill();

   I3TWRLaunch* raw_ptr_in = new I3TWRLaunch();
   I3TWRLaunchPtr ptr_in (raw_ptr_in);

   tree.SetBranchAddress("branch",&raw_ptr_in);
   tree.GetEvent(0);

   /** @todo add some checking of the data of I3TWRLaunch here */

   }

   /**
    * check branching object to a tree, writing the tree to disk,
    * and reading the tree back in, and finding the object in the tree.
    */
   void object::test<4>(){
   I3TWRLaunchPtr ptr(new I3TWRLaunch());
   /** @todo add some setting of data here */
                                                                                
   I3TWRLaunch* raw_ptr = &(*ptr);
   TTree tree("TestTree","Icecube");
   tree.Branch("branch","I3TWRLaunch",&raw_ptr);
                                                                                
   tree.Fill();

   TFile file_out("test.out.root","RECREATE");
   tree.Write();
   file_out.Close();
                    

   TFile file_in("test.out.root");
   TTree* tree_in = (TTree*)file_in.FindObjectAny("TestTree");
   ensure("the test tree exists",tree_in);
                                                            
   I3TWRLaunch* raw_ptr_in = new I3TWRLaunch();
   I3TWRLaunchPtr ptr_in (raw_ptr_in);
                                                                                
   tree_in->SetBranchAddress("branch",&raw_ptr_in);
   tree_in->GetEvent(0);

   /** @todo add some checking of the data of I3TWRLaunch here */

   delete tree_in;
   }
}
