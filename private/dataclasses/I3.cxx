#include "dataclasses/I3.h"

I3::I3(const char* filename)
{
  order = new I3Order;
  filemode=0;

  if(access(filename, 0) == 0)
  {
    if ( (f = new TFile(filename, "READ")) == NULL) printf("Cannot open file %s\n", filename);
    else
    {
      filemode=1;
      tree = (TTree*)f->Get("T");
    }
  }
  else
  {
    if ( (f = new TFile(filename, "NEW")) == NULL) printf("Could not create file %s\n", filename);
    else
    {
      filemode=2;
      tree = new TTree("T","ICECUBE");
      printf("creating new tree\n");
      tree->Branch("TI3Order", "TI3Order", &order, 32000, 0);
    }
  }
}

I3::~I3()
{
  if(filemode==2) f->Write();
  if(filemode!=0) f->Close();
  delete order;
}

const char* I3::GetEventtype(int sequencenumber)
{
  char *c=new char[50];  strcpy(c,"");
  if(filemode==0) {printf("File error\n"); return(c);}

  TBranch *branch = tree->GetBranch("TI3Order");
  branch->SetAddress(&order);

  int i_max=(int)branch->GetEntries();
  if(i_max>sequencenumber)
  {
    branch->GetEntry(sequencenumber);
    strcpy(c,order->GetEventtype());
  }
  else printf("no more entries\n");
  return(c);
}

int I3::GetIndex(int sequencenumber)
{
  int n=-1;
  if(filemode==0) {printf("File error\n"); return(n);}

  TBranch  *branch = tree->GetBranch("TI3Order");
  branch->SetAddress(&order);

  int i_max=(int)branch->GetEntries();
  if(i_max>sequencenumber)
  {
    branch->GetEntry(sequencenumber);
    n=order->GetIndex();
  }
  else printf("no more entries\n");
  return(n);
}

int I3::GetIndexmax(const char* eventtype)
{
  if(filemode==0) {printf("File error\n"); return(-1);}
  TBranch *branch = NULL;
  if( (branch=tree->GetBranch(eventtype)) == NULL) {printf("no such branch\n"); return(false);}
  return((int)branch->GetEntries());
}

int I3::GetSequencenumber(const char* eventtype, int index)
{
  if(filemode==0) {printf("File error\n"); return(-1);}
  int n=-1;

  TBranch  *branch = tree->GetBranch("TI3Order");

  branch->SetAddress(&order);
  int i_max=(int)branch->GetEntries();
  for(int i=0; i<i_max; i++)
  {
    branch->GetEntry(i);
    if(strcmp(eventtype,order->GetEventtype())==0 && index==order->GetIndex()) n=i;
  }
  return(n);
}

int I3::GetSequencemax()
{
  if(filemode==0) {printf("File error\n"); return(-1);}
  TBranch  *branch = tree->GetBranch("TI3Order");
  int i_max=(int)branch->GetEntries();
  return(i_max);
}

bool I3::I3Read(void* data, int index, int numberbranches=0, ...)
{
  if(filemode==0) {printf("File error\n"); return(false);}
  TBranch *branch = NULL;
  if( (branch=tree->GetBranch(((TObject*)data)->GetName())) == NULL) {printf("no such branch\n"); return(false);}
  branch->SetAddress(&data);
  int i_max=(int)branch->GetEntries();
  if(i_max<=index) {printf("no more entries\n"); return(false);}

  if(numberbranches!=0)
  {
    tree->SetBranchStatus("*",0);
    tree->SetBranchStatus(((TObject*)data)->GetName(),1);
    va_list argument;
    va_start(argument, numberbranches);
    for(int i=0; i<numberbranches; i++) tree->SetBranchStatus(va_arg(argument, char*),1);
    va_end(argument);
  }

  branch->GetEntry(index);
  tree->SetBranchStatus("*",1);
  return(true);
}

void I3::I3Write(void* data, int numberbranches=0, ...)
{
  if(filemode!=2) {printf("File already exists!\n"); return;}
  TBranch *branch = NULL;
  if( (branch=tree->GetBranch(((TObject*)data)->GetName())) == NULL)
  {
    printf("creating new branch\n");
    branch=tree->Branch( ((TObject*)data)->GetName(), ((TObject*)data)->GetName(), &data, 32000, 99);
  }
  else branch->SetAddress(&data);
  int i_max=(int)branch->GetEntries();

  if(numberbranches!=0)
  {
    tree->SetBranchStatus("*",0);
    tree->SetBranchStatus(((TObject*)data)->GetName(),1);
    va_list argument;
    va_start(argument, numberbranches);
    for(int i=0; i<numberbranches; i++) tree->SetBranchStatus(va_arg(argument, char*),1);
    va_end(argument);
  }

  branch->Fill();
  tree->SetBranchStatus("*",1);

  order->SetEventtype(((TObject*)data)->GetName());
  order->SetIndex(i_max);
  TBranch *branch_order = tree->GetBranch("TI3Order");
  branch_order->SetAddress(&order);
  branch_order->Fill();
}
ClassImp(I3);

