#include <TObject.h>
#include <iostream>

using namespace std;
void test1()
{
  gSystem->Load("libicetray.so");
  gSystem->Load("libdataclasses.so");

  cout << "Running test" << endl;

  TestVecType tv;
  Derived d;

  tv.resize(4);
  cout << tv.size() << endl;
  tv[0] = new Base;
  tv[1] = new Derived;
  tv[2] = new Base;
  tv[3] = new Derived;

  tv[0]->print();
  tv[1]->print();
  tv[2]->print();
  tv[3]->print();

  //  TestVecType::type_iterator<Derived*> diter;
  tv.begin();
  tv.end();

  cout << "simpler iterators done" << endl;
  policy::type_iterator<Derived*> diter;
  tv.begin<Derived*>();
  cout << "tests passed" << endl;
}



