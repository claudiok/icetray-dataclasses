#include <dataclasses/external/CompareFloatingPoint.h>
#include <iostream>
#include <sstream>
#include <iomanip>

// Function to print a number and its representation, in hex and decimal
template <typename F, typename I>
std::string ToStringImpl(F f, I offset )
{
  const int PREC(2 *sizeof(I));
  (*((I*)&f)) += offset;
  std::stringstream s;
  s<< std::showpos << std::setw(PREC) << std::setprecision(PREC) << f << " "
   << std::right << "0x" << std::hex << std::uppercase << std::setw(PREC) << *(F*)&f << " "
   << std::dec << std::setw(PREC) << *(F*)&f << " "
   << offset  << " "
   << std::endl;
  return s.str();
}

std::string CompareFloatingPoint::ToString(double f, long offset ){
  return ToStringImpl<double,long>(f,offset);
}

std::string CompareFloatingPoint::ToString(float f, int offset ){
  return ToStringImpl<float,int>(f,offset);
}
