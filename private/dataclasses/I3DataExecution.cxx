#include "dataclasses/I3DataExecution.h"

#include "services/I3Logger.h"
#include "impl-icetray/I3TrayLogging.h"

#include <cstdlib>
#include <iostream>

using namespace std;

ClassImp(I3DataExecution);

I3DataExecution* I3DataExecution::fInstance = 0;

I3DataExecution& I3DataExecution::Instance(){
  if(!fInstance)
    fInstance = new I3DataExecution();
  return *fInstance;
}

void I3DataExecution::Fatal(const Char_t* message){
  cout<<"This message came from the data and caused a fatal error:\n '"
      <<message
      <<"'"
      <<endl;
  // to be fancied up later and linked into icetray's 'Fatal' call
  exit(1);
}

I3DataExecution::I3DataExecution(){

}

I3Logger& I3DataExecution::GetLogger(){
// to be re-implemented later with the data having its own logger
// rather than just stealing icetray's
  return I3TrayLogging::GetLogger();
}

I3DataExecution::~I3DataExecution(){

}
