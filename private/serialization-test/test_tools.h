#ifndef TEST_TOOLS_H_INCLUDED
#define TEST_TOOLS_H_INCLUDED

#include <string>

template <typename T>
T randval() { 
   return static_cast<T>(randval()); 
}

template<>
std::string randval() {
   return "RANDOMSTRING";
}

#endif
