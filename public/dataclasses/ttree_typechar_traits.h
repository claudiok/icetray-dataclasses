#ifndef ROOT_TYPECHAR_TRAITS_H_INCLUDED
#define ROOT_TYPECHAR_TRAITS_H_INCLUDED

namespace boost {
  namespace archive {
    namespace root {
      
      // macro expands to a specialization of the traits template
      // which maps a type to a character that one uses in TTree::Branch.
      // used both in ttree_oarchive and tuple_oarchive

#define TRAIT(TYPE,CHAR) \
template <> struct typechar_traits<TYPE> { static char const value = CHAR; }

    // C : a character string terminated by the 0 character
    // O : a boolean (Bool_t)  but bool isnt here, we just convert to unsigned.
    // B : an 8 bit signed integer (Char_t)
    // b : an 8 bit unsigned integer (UChar_t)
    // S : a 16 bit signed integer (Short_t)
    // s : a 16 bit unsigned integer (UShort_t)
    // I : a 32 bit signed integer (Int_t)
    // i : a 32 bit unsigned integer (UInt_t)            	
    // F : a 32 bit floating point (Float_t)            	
    // D : a 64 bit floating point (Double_t)            	
    // L : a 64 bit signed integer (Long64_t)            	
    // l : a 64 bit unsigned integer (ULong64_t)            	

      template <typename T>
      struct typechar_traits {
	static char const value = '?';
      };

      TRAIT(const char*,'C');
      TRAIT(char,'B');
      TRAIT(unsigned char,'b');
      TRAIT(short,'S');
      TRAIT(unsigned short,'s');
      TRAIT(int,'I');
      TRAIT(unsigned int, 'i');
      TRAIT(float, 'F');
      TRAIT(double, 'D');
      TRAIT(long, 'L');
      TRAIT(unsigned long, 'l');
	    
    }
  }
}
#endif
