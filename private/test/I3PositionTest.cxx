/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3PositionTest.cxx,v 1.4 2004/09/13 14:45:34 dule Exp $

    @version $Revision: 1.4 $
    @date $Date: 2004/09/13 14:45:34 $
    @author pretz

    @todo
*/

#include "TUT/tut.h"

#include "dataclasses/I3Position.h"
#include "TFile.h"
#include "TTree.h"
#include <string>
using std::string;
using std::cout;
using std::endl;

namespace tut
{
  struct I3PositionTest
  {
  };

  typedef test_group<I3PositionTest> factory;
  typedef factory::object object;
}

namespace
{
  tut::factory t("I3PositionTest");
}

namespace tut
{ 
  /**
   * check that constructor and destructor work
   */
  void object::test<1>() 
  {
     I3PositionPtr ptr(new I3Position());
  }
  
  /**
   * check writing object to disk
   */
  void object::test<2>()
  {
     I3PositionPtr ptr(new I3Position());

     /** @todo should fill some data for I3Position here */

     TFile f_out("test.out.root","RECREATE");
     ptr->Write();
     f_out.Close();

     TFile f_in("test.out.root");
     TObject* object_in =
		f_in.FindObjectAny("I3Position");
     f_in.Close();
     ensure("the read-in pointer is non-zero",object_in);
     
     I3Position* tested_in = dynamic_cast<I3Position*>(object_in);
     ensure("the read-in pointer is of the right type",tested_in);

     I3PositionPtr ptr_in(tested_in);
    
    /** @todo should check the read-in data for I3Position here */

  }
   
   /**
    * check branching it to a tree
    */
   void object::test<3>(){
   I3PositionPtr ptr(new I3Position());
   /** @todo add some setting of data here */
 
   I3Position* raw_ptr = &(*ptr);
   TTree tree("TestTree","Icecube");
   tree.Branch("branch","I3Position",&raw_ptr);
   
   tree.Fill();

   I3Position* raw_ptr_in = new I3Position();
   I3PositionPtr ptr_in (raw_ptr_in);

   tree.SetBranchAddress("branch",&raw_ptr_in);
   tree.GetEvent(0);

   /** @todo add some checking of the data of I3Position here */

   }

   /**
    * check branching object to a tree, writing the tree to disk,
    * and reading the tree back in, and finding the object in the tree.
    */
   void object::test<4>(){
   I3PositionPtr ptr(new I3Position());
   /** @todo add some setting of data here */

   I3Position* raw_ptr = &(*ptr);
   TTree tree("TestTree","Icecube");
   tree.Branch("branch","I3Position",&raw_ptr);
   tree.Fill();

   TFile file_out("test.out.root","RECREATE");
   tree.Write();
   file_out.Close();
                    

   TFile file_in("test.out.root");
   TTree* tree_in = (TTree*)file_in.FindObjectAny("TestTree");
   ensure("the test tree exists",tree_in);
                                                            
   I3Position* raw_ptr_in = new I3Position();
   I3PositionPtr ptr_in (raw_ptr_in);

   tree_in->SetBranchAddress("branch",&raw_ptr_in);
   tree_in->GetEvent(0);

   /** @todo add some checking of the data of I3Position here */

   delete tree_in;
   }

  /**
   * Make sure that the changing of coordinate systems works well
   */
  void object::test<5>(){
    cout <<"Creating positions p(4,3,0) and q(0,0,0)..."<<endl;
    I3Position p(4,3,0);
    //I3PositionPtr q_ptr(new I3Position(1,2,3));
    I3Position q(1,2,3);
    cout <<"Setting position q to: 2,2,2 in car..."<<endl;
    q.SetPosition(2,2,2,I3Position::car);

    ensure_distance("p.GetX failed",p.GetX(),4.0,0.0001);
    ensure_distance("p.GetY failed",p.GetY(),3.0,0.0001);
    ensure_distance("p.GetZ failed",p.GetZ(),0.0,0.0001);
    ensure_distance("p.GetR failed",p.GetR(),5.0,0.0001);
    ensure_distance("p.GetTheta failed",p.GetTheta(),1.5708,0.0001);
    ensure_distance("p.GetPhi failed",p.GetPhi(),0.6435,0.0001);
    ensure_distance("p.GetRho failed",p.GetRho(),5.0,0.0001);

    ensure_distance("q.GetX failed",q.GetX(),2.0,0.0001);
    ensure_distance("q.GetY failed",q.GetY(),2.0,0.0001);
    ensure_distance("q.GetZ failed",q.GetZ(),2.0,0.0001);

    ensure_distance("p.CalcDistance(q) failed",p.CalcDistance(q),3.0,0.0001);
    ensure_distance("q.CalcDistance(p) failed",q.CalcDistance(p),3.0,0.0001);

    cout <<"Rotating p by Pi/4 around z-axis..."<<endl;
    p.RotateZ(3.141592/4);
    ensure_distance("p.GetX failed",p.GetX(),0.707108,0.0001);
    ensure_distance("p.GetY failed",p.GetY(),4.94975,0.0001);
    ensure_distance("p.GetZ failed",p.GetZ(),0.0,0.0001);

    cout <<"Rotating p by Pi/2 around y-axis..."<<endl;
    p.RotateY(3.141592/2);
    ensure_distance("p.GetX failed",p.GetX(),0.0,0.0001);
    ensure_distance("p.GetY failed",p.GetY(),4.94975,0.0001);
    ensure_distance("p.GetZ failed",p.GetZ(),-0.707108,0.0001);

    cout <<"Rotating p by Pi/2 around x-axis..."<<endl;
    p.RotateX(3.141592/2);
    ensure_distance("p.GetX failed",p.GetX(),0.0,0.0001);
    ensure_distance("p.GetY failed",p.GetY(),0.707108,0.0001);
    ensure_distance("p.GetZ failed",p.GetZ(),4.94975,0.0001);

    cout <<"Creating position s and setting coordinates in sph..."<<endl;
    I3Position s;
    s.SetPosition(1.732050808,0.955316618,3.141592/4,I3Position::sph);
    ensure_distance("s.GetX failed",s.GetX(),1.0,0.0001);
    ensure_distance("s.GetY failed",s.GetY(),1.0,0.0001);
    ensure_distance("s.GetZ failed",s.GetZ(),1.0,0.0001);

    cout <<"Creating position d and setting coordinates in car..."<<endl;
    I3Position d(1,1,1);
    ensure_distance("d.GetR failed",d.GetR(),1.73205,0.0001);
    ensure_distance("d.GetTheta failed",d.GetTheta(),0.955317,0.0001);
    ensure_distance("d.GetPhi failed",d.GetPhi(),0.785398,0.0001);

    cout <<"Using the = operator on I3Position e=d..."<<endl;
    I3Position e = d;
    ensure_distance("e.GetR failed",e.GetR(),1.73205,0.0001);
    ensure_distance("e.GetTheta failed",e.GetTheta(),0.955317,0.0001);
    ensure_distance("e.GetPhi failed",e.GetPhi(),0.785398,0.0001);

    cout <<"Creating position f from position d..."<<endl;
    I3Position f(d);
    ensure_distance("f.GetX failed",f.GetX(),1.0,0.0001);
    ensure_distance("f.GetY failed",f.GetY(),1.0,0.0001);
    ensure_distance("f.GetZ failed",f.GetZ(),1.0,0.0001);

    cout <<"Shifting coordinate system of f by s..."<<endl;
    f.ShiftCoordSystem(s);
    ensure_distance("shifted f.GetX failed",f.GetX(),0.0,0.0001);
    ensure_distance("shifted f.GetY failed",f.GetY(),0.0,0.0001);
    ensure_distance("shifted f.GetZ failed",f.GetZ(),0.0,0.0001);

    cout <<"Shifting coordinate system of f by p..."<<endl;
    f.ShiftCoordSystem(p);
    ensure_distance("shifted f.GetX failed",f.GetX(),0.0,0.0001);
    ensure_distance("shifted f.GetY failed",f.GetY(),-0.707108,0.0001);
    ensure_distance("shifted f.GetZ failed",f.GetZ(),-4.94975,0.0001);
    ensure_distance("shifted f.GetR failed",f.GetR(),5.0,0.0001);
    ensure_distance("shifted f.GetTheta failed",f.GetTheta(),2.9997,0.0001);
    ensure_distance("shifted f.GetPhi failed",f.GetPhi(),4.71239,0.0001);
    ensure_distance("shifted f.GetRho failed",f.GetRho(),0.707108,0.0001);

  }
}
