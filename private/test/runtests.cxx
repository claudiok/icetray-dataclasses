#include "test/tut.h"
#include "test/tut_reporter.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace tut
{
  test_runner_singleton runner;
}

void usage (const string &progname) 
{
  cout << "dataclasses test application." << endl;
  cout << "Usage: " << progname << " list|all|testgroup [testnumber]" << endl;
  cout << "       list: List all groups" << endl;
  cout << "       all: Run all tests" << endl;
  cout << "       testgroup [testnumber]: Run entire test group," << endl;
  cout << "       or just testnumber within that group" << endl;;
  exit(1);
}

int main(int c_argc,const char* c_argv[])
{
  tut::reporter visi;

  vector<string> argv(c_argc);
  for (int i=0; i<c_argc; i++)
    argv[i] = c_argv[i];

  if (argv.size() == 1 || argv.size() >= 4)
    usage(argv[0]);

  tut::runner.get().set_callback(&visi);

  if (argv[1] == "help" || argv[1] == "-help" || argv[1] == "--help")
    usage(argv[0]);

  try
  {
    if (argv[1] == "list")
    {
      cout << "registered test groups:" << endl;
      tut::groupnames gl = tut::runner.get().list_groups();
      tut::groupnames::const_iterator i = gl.begin();
      tut::groupnames::const_iterator e = gl.end();
      while( i != e )
      {
        cout << "  " << *i << endl;
        ++i;
      }
    }
    else if (argv[1] == "all") 
    {
      tut::runner.get().run_tests();
    }
    else if (argv.size() == 3)
    {
      tut::runner.get().run_test(argv[1],::atoi(argv[2].c_str()));
    }
    else
    {
      tut::runner.get().run_tests(argv[1]);
    }
  }
  catch (const exception& ex)
  {
    cerr << "tut raised ex: " << ex.what() << endl;
  }

  return 0;
}
