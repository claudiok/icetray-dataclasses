#include "dataclasses/I3DataExecution.h"

#include "services/I3Logging.h"

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
  log_info("This message came from the data and caused a fatal error:\"%s\"\n",
	message);
  // to be fancied up later and linked into icetray's 'Fatal' call
  exit(1);
}

I3DataExecution::I3DataExecution(){

}

I3DataExecution::~I3DataExecution(){

}
