{
gSystem->Load("libdataclasses.so");
gSystem->Load("libicetray.so");
gSystem->Load("liblog4cpp.so");

I3DataExecution::Instance().GetLogger().Warn("Here is a message of 'Warn' priority");
I3DataExecution::Instance().GetLogger().Notice("Here is a message of 'Notice' priority");
I3DataExecution::Instance().GetLogger().EmergStream()<<"Here is a message logged in the 'cout' style"<<"\n"<<"See, I can put "<<47<<" random numbers into the message"<<I3LogStream::kEndl;
I3DataExecution::Instance().Fatal("Here is a fatal call");

}
