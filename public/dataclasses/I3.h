#ifndef I3_H
#define I3_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <TObject.h>
#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>

#include "dataclasses/I3Order.h"

class I3
{
  TFile    *f;
  TTree    *tree;
  I3Order  *order;
  int      filemode;

  public:
           I3(const char* filename);
  virtual ~I3();
  
  const char* GetEventtype(int sequencenumber);
  int         GetIndex(int sequencenumber);
  int         GetIndexmax(const char* eventtype);
  int         GetSequencenumber(const char* eventtype, int index);
  int         GetSequencemax();
  bool        I3Read(void* data, int index, int numberbranches, ...);
  void        I3Write(void* data, int numberbranches, ...);
  
  ClassDef(I3, 1);
}; 
#endif
