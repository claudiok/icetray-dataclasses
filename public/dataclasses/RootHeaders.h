#ifndef RootHeaders_H_Included
#define RootHeaders_H_Included

#ifdef __CINT__
#warning YES __CINT__
#include <TObject.h>
#include <TClass.h>
#include <RTypes.h>


#else // __CINT__

#warning NOT __CINT__
typedef int Int_t;
typedef unsigned int UInt_t;
typedef long Long_t;
typedef unsigned long ULong_t;
typedef double Double_t;
typedef short Short_t;
typedef unsigned short UShort_t;
typedef float Float_t;
typedef bool Bool_t;
typedef char Char_t;
const bool kFALSE = false;
const bool kTRUE = true;

// dummy base class
struct TObject { }; 

struct IsA_Proxy {
      const char *GetName() { 
	 const static char* fixme = "FIXME!";
	 return fixme; 
      }
};

IsA_Proxy* IsA() { 
   static IsA_Proxy p;
   return &p;
}

// dummy macros
#define ClassDef(X,Y)
#define ClassImp(X)

#endif __CINT__

#endif
