/*
CompareAsInt.cpp - various functions to compare floating point numbers using
integer operations, other functions to test these comparisons, and other
functions to print out floating point numbers and their representation.
This comes from here : http://www.cygnus-software.com/papers/comparingfloats/comparingfloats.htm
We'll see this a lot below so I'll include a snippet from the website.

The IEEE float and double formats were designed so that the numbers are lexicographically orderedâ,
which in the words of IEEE architect William Kahan means "if two floating-point numbers in the same 
format are ordered ( say x < y ), then they are ordered the same way when their bits are reinterpreted 
as Sign-Magnitude integers."
 
This means that if we take two floats in memory, interpret their bit pattern as integers, and compare 
them, we can tell which is larger, without doing a floating point comparison. In the C/C++ language 
this comparison looks like this:

if (*(int*)&f1 < *(int*)&f2)

This charming syntax means take the address of f1, treat it as an integer pointer, and dereference it. 
All those pointer operations look expensive, but they basically all cancel out and just mean "treat f1 
as an integer". Since we apply the same syntax to f2 the whole line means compare f1 and f2, 
using their in-memory representations interpreted as integers instead of floats.

NB:  Another thing you'll see is "Ulps" which stands for "Units in the Last Place."
*/
#ifndef COMPARE_FLOATING_POINT
#define COMPARE_FLOATING_POINT

#include <float.h>
#include <math.h>
#include <stdint.h>

#define INFINITYCHECK
#define NANCHECK
#define SIGNCHECK

namespace CompareFloatingPoint{

  // Function to print a number and its representation, in hex and decimal
  std::string ToString(double f, int64_t offset = 0);
  std::string ToString(float f, int32_t offset = 0);

  bool Compare(float A, float B, int32_t maxUlps = 10);
  bool Compare(double A, double B, int64_t maxUlps = 10);
  
  bool Compare_NanEqual(double A, double B);
  
  bool IsInfinite(float);
  bool IsNan(float);
  int32_t Sign(float);

  bool IsInfinite(double);
  bool IsNan(double);
  int64_t Sign(double);
  
}//end namespace CompareFloatingPoint

// Support functions and conditional compilation directives for the
// master AlmostEqual function.
  
inline bool CompareFloatingPoint::IsInfinite(float A){
  const int32_t INF_AS_INT = 0x7F800000;
  
  // An infinity has an exponent of 255 (shift left 23 positions) and
  // a zero mantissa. There are two infinities - positive and negative.
  int32_t aInt;
  memcpy( &aInt, &A, sizeof(int32_t));
  if ((aInt & 0x7FFFFFFF) == INF_AS_INT)
    return true;
  return false;
}

inline bool CompareFloatingPoint::IsInfinite(double A){
  
  const int64_t INF_AS_LONG = 0x7FF0000000000000LL;
  // An infinity has an exponent of 2047 (shift left 52 positions) and
  // a zero mantissa. There are two infinities - positive and negative.
  int64_t aInt;
  memcpy( &aInt, &A, sizeof(int64_t) );
  if (( aInt & 0x7FFFFFFFFFFFFFFFLL  ) == INF_AS_LONG)
    return true;
  return false;
}

inline bool CompareFloatingPoint::IsNan(float A){
  // A NAN has an exponent of 255 (shifted left 23 positions) and
  // a non-zero mantissa.
  int32_t aInt;
  memcpy( &aInt, &A, sizeof(int32_t) );
  int32_t exp = aInt & 0x7F800000;
  int32_t mantissa = aInt & 0x007FFFFF;
  if (exp == 0x7F800000 && mantissa != 0)
    return true;
  return false;
}

inline bool CompareFloatingPoint::IsNan(double A){
  // A NAN has an exponent of 2047 (shifted left 52 positions) and
  // a non-zero mantissa.
  const int64_t INF_AS_LONG = 0x7FF0000000000000LL;
  int64_t aInt;
  memcpy( &aInt, &A, sizeof(int64_t) );
  int64_t mantissa = aInt & 0xFFFFFFFFFFFFFLL;
  if ( ( ( aInt & 0x7FF0000000000000LL) == INF_AS_LONG)  &&
       mantissa != 0)
    return true;
  return false;
}

inline int32_t CompareFloatingPoint::Sign(float A){
  // The sign bit of a number is the high bit.
  int32_t aInt;
  memcpy( &aInt, &A, sizeof(int32_t) );  
  return aInt & 0x80000000;
}

inline int64_t CompareFloatingPoint::Sign(double A){
  // The sign bit of a number is the high bit.
  int64_t aInt;
  memcpy( &aInt, &A, sizeof(int64_t) );
  return aInt & 0x8000000000000000LL;
}

// This is the 'final' version of the AlmostEqualUlps function.
// The optional checks are included for completeness, but in many
// cases they are not necessary, or even not desirable.
inline bool CompareFloatingPoint::Compare(float A, float B, int32_t maxUlps){
  // There are several optional checks that you can do, depending
  // on what behavior you want from your floating point comparisons.
  // These checks should not be necessary and they are included
  // mainly for completeness.
  
#ifdef  INFINITYCHECK
  // If A or B are infinity (positive or negative) then
  // only return true if they are exactly equal to each other -
  // that is, if they are both infinities of the same sign.
  // This check is only needed if you will be generating
  // infinities and you don't want them 'close' to numbers
  // near FLT_MAX.
  if (IsInfinite(A) || IsInfinite(B))
    return A == B;
#endif
  
#ifdef  NANCHECK
  // If A or B are a NAN, return false. NANs are equal to nothing,
  // not even themselves.
  // This check is only needed if you will be generating NANs
  // and you use a maxUlps greater than 4 million or you want to
  // ensure that a NAN does not equal itself.
  if (IsNan(A) || IsNan(B))
    return false;
#endif
  
#ifdef  SIGNCHECK
  // After adjusting floats so their representations are lexicographically
  // ordered as twos-complement integers a very small positive number
  // will compare as 'close' to a very small negative number. If this is
  // not desireable, and if you are on a platform that supports
  // subnormals (which is the only place the problem can show up) then
  // you need this check.
  // The check for A == B is because zero and negative zero have different
  // signs but are equal to each other.
  if (Sign(A) != Sign(B))
    return A == B;
#endif
  
  int32_t aInt;
  memcpy( &aInt, &A, sizeof(int32_t) );
  // Make aInt lexicographically ordered as a twos-complement int
  if (aInt < 0)
    aInt = 0x80000000 - aInt;
  // Make bInt lexicographically ordered as a twos-complement int
  int32_t bInt;
  memcpy( &bInt, &B, sizeof(int32_t) );
  if (bInt < 0)
    bInt = 0x80000000 - bInt;
  
  // Now we can compare aInt and bInt to find out how far apart A and B
  // are.
  int32_t intDiff = abs(aInt - bInt);
  if (intDiff <= maxUlps)
    return true;
  return false;
}

// This is the 'final' version of the AlmostEqualUlps function.
// The optional checks are included for completeness, but in many
// cases they are not necessary, or even not desirable.
inline bool CompareFloatingPoint::Compare(double A, double B, int64_t maxUlps){
  // There are several optional checks that you can do, depending
  // on what behavior you want from your floating point comparisons.
  // These checks should not be necessary and they are included
  // mainly for completeness.
  
#ifdef  INFINITYCHECK
  // If A or B are infinity (positive or negative) then
  // only return true if they are exactly equal to each other -
  // that is, if they are both infinities of the same sign.
  // This check is only needed if you will be generating
  // infinities and you don't want them 'close' to numbers
  // near FLT_MAX.
  if (IsInfinite(A) || IsInfinite(B))
    return A == B;
#endif
  
#ifdef  NANCHECK
  // If A or B are a NAN, return false. NANs are equal to nothing,
  // not even themselves.
  // This check is only needed if you will be generating NANs
  // and you use a maxUlps greater than 4 million or you want to
  // ensure that a NAN does not equal itself.
  if (IsNan(A) || IsNan(B))
    return false;
#endif
  
#ifdef  SIGNCHECK
  // After adjusting floats so their representations are lexicographically
  // ordered as twos-complement integers a very small positive number
  // will compare as 'close' to a very small negative number. If this is
  // not desireable, and if you are on a platform that supports
  // subnormals (which is the only place the problem can show up) then
  // you need this check.
  // The check for A == B is because zero and negative zero have different
  // signs but are equal to each other.
  if (Sign(A) != Sign(B))
    return A == B;
#endif
  
  int64_t aLong;
  memcpy( &aLong, &A, sizeof(int64_t) );
  // Make aLong lexicographically ordered as a twos-complement long
  if (aLong < 0)
    aLong = 0x8000000000000000LL - aLong;
  // Make bLong lexicographically ordered as a twos-complement long
  int64_t bLong;
  memcpy( &bLong, &B, sizeof(int64_t) );
  if (bLong < 0)
    bLong = 0x8000000000000000LL - bLong;
  
  // Now we can compare aLong and bLong to find out how far apart A and B are.
  int64_t longDiff = llabs(aLong - bLong);
  if (longDiff <= maxUlps)
    return true;
  return false;
}

inline bool CompareFloatingPoint::Compare_NanEqual(double A, double B)
{
  return ((CompareFloatingPoint::IsNan(A) && CompareFloatingPoint::IsNan(B))
        || A == B);
}
  
#endif
