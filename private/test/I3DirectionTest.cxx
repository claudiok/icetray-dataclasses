/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3DirectionTest.cxx,v 1.2 2004/10/11 07:06:10 troy Exp $

    @version $Revision: 1.2 $
    @date $Date: 2004/10/11 07:06:10 $
    @author dule

    @todo
*/

#include "TUT/tut.h"

#include "dataclasses/I3Direction.h"
#include "dataclasses/I3Units.h"
#include "TFile.h"
#include "TTree.h"
#include <string>
using std::string;
using std::cout;
using std::endl;
using namespace I3Units;

namespace tut
{
  struct I3DirectionTest
  {
  };

  typedef test_group<I3DirectionTest> factory;
  typedef factory::object object;
}

namespace
{
  static tut::factory t("I3DirectionTest");
}

namespace tut
{ 
  /**
   * check that constructor and destructor work
   */
  void object::test<1>() 
  {
     I3DirectionPtr ptr(new I3Direction());
  }
  
  /**
   * check writing object to disk
   */
  void object::test<2>()
  {
     I3DirectionPtr ptr(new I3Direction());

     /** @todo should fill some data for I3Direction here */

     TFile f_out("test.out.root","RECREATE");
     ptr->Write();
     f_out.Close();

     TFile f_in("test.out.root");
     TObject* object_in =
       f_in.FindObjectAny("I3Direction");
     f_in.Close();
     ensure("the read-in pointer is non-zero",object_in);
     
     I3Direction* tested_in = dynamic_cast<I3Direction*>(object_in);
     ensure("the read-in pointer is of the right type",tested_in);

     I3DirectionPtr ptr_in(tested_in);
    
    /** @todo should check the read-in data for I3Direction here */

  }
   
   /**
    * check branching it to a tree
    */
   void object::test<3>(){
   I3DirectionPtr ptr(new I3Direction());
   /** @todo add some setting of data here */
 
   I3Direction* raw_ptr = &(*ptr);
   TTree tree("TestTree","Icecube");
   tree.Branch("branch","I3Direction",&raw_ptr);
   
   tree.Fill();

   I3Direction* raw_ptr_in = new I3Direction();
   I3DirectionPtr ptr_in (raw_ptr_in);

   tree.SetBranchAddress("branch",&raw_ptr_in);
   tree.GetEvent(0);

   /** @todo add some checking of the data of I3Direction here */

   }

   /**
    * check branching object to a tree, writing the tree to disk,
    * and reading the tree back in, and finding the object in the tree.
    */
   void object::test<4>(){
   I3DirectionPtr ptr(new I3Direction());
   /** @todo add some setting of data here */

   I3Direction* raw_ptr = &(*ptr);
   TTree tree("TestTree","Icecube");
   tree.Branch("branch","I3Direction",&raw_ptr);
   tree.Fill();

   TFile file_out("test.out.root","RECREATE");
   tree.Write();
   file_out.Close();
                    

   TFile file_in("test.out.root");
   TTree* tree_in = (TTree*)file_in.FindObjectAny("TestTree");
   ensure("the test tree exists",tree_in);
                                                            
   I3Direction* raw_ptr_in = new I3Direction();
   I3DirectionPtr ptr_in (raw_ptr_in);

   tree_in->SetBranchAddress("branch",&raw_ptr_in);
   tree_in->GetEvent(0);

   /** @todo add some checking of the data of I3Direction here */

   delete tree_in;
   }

  /**
   * Make sure that the changing of coordinate systems works well
   */
  void object::test<5>(){
    cout <<"Creating I3Direction..."<<endl;
    I3Direction dir;
    cout <<"Setting dir: zen=(180-54.74)deg, azi=-135deg (i.e.1,1,1)..."<<endl;
    dir.SetDirection((180-54.73561)*deg, -135*deg);
    ensure_distance("dir.GetZenith failed",dir.GetZenith()/deg,125.264,0.001);
    ensure_distance("dir.GetAzimuth failed",dir.GetAzimuth()/deg,-135.0,0.001);
    ensure_distance("dir.GetX failed",dir.GetX(),0.57735,0.0001);
    ensure_distance("dir.GetY failed",dir.GetY(),0.57735,0.0001);
    ensure_distance("dir.GetZ failed",dir.GetZ(),0.57735,0.0001);

    cout <<"Setting dir: x=1,y=1,z=0..."<<endl;
    dir.SetDirection(1,1,0);
    ensure_distance("dir.GetZenith failed",dir.GetZenith()/deg,90.0,0.001);
    ensure_distance("dir.GetAzimuth failed",dir.GetAzimuth()/deg,225.0,0.001);

    cout <<"Setting values for dir in zen=0,azi=0 (i.e. down)..."<<endl;
    dir.SetDirection(0,0);
    ensure_distance("dir.GetX failed",dir.GetX(),0.0,0.0001);
    ensure_distance("dir.GetY failed",dir.GetY(),0.0,0.0001);
    ensure_distance("dir.GetZ failed",dir.GetZ(),-1.0,0.0001);

    cout <<"Rotating dir around x-axis by +90deg... ==> +y-axis"<<endl;
    dir.RotateX(90*deg);
    ensure_distance("dir.GetZenith failed",dir.GetZenith()/deg,90.0,0.001);
    ensure_distance("dir.GetAzimuth failed",dir.GetAzimuth()/deg,270.0,0.001);
    ensure_distance("dir.GetX failed",dir.GetX(),0.0,0.0001);
    ensure_distance("dir.GetY failed",dir.GetY(),1.0,0.0001);
    ensure_distance("dir.GetZ failed",dir.GetZ(),0.0,0.0001);

    cout <<"Rotating dir around z-axis by -45deg...==> x=1,y=1,z=0"<<endl;
    dir.RotateZ(-45*deg);
    ensure_distance("dir.GetZenith failed",dir.GetZenith()/deg,90.0,0.001);
    ensure_distance("dir.GetAzimuth failed",dir.GetAzimuth()/deg,225.0,0.001);
    ensure_distance("dir.GetX failed",dir.GetX(),0.707107,0.0001);
    ensure_distance("dir.GetY failed",dir.GetY(),0.707107,0.0001);
    ensure_distance("dir.GetZ failed",dir.GetZ(),0.0,0.0001);

    cout <<"Rotating dir around y-axis by -90deg... ==> x=0,y=1,z=1"<<endl;
    dir.RotateY(-90*deg);
    ensure_distance("dir.GetZenith failed",dir.GetZenith()/deg,135.0,0.001);
    ensure_distance("dir.GetAzimuth failed",dir.GetAzimuth()/deg,270.0,0.001);
    ensure_distance("dir.GetX failed",dir.GetX(),0.0,0.0001);
    ensure_distance("dir.GetY failed",dir.GetY(),0.707107,0.0001);
    ensure_distance("dir.GetZ failed",dir.GetZ(),0.707107,0.0001);

  }
}
