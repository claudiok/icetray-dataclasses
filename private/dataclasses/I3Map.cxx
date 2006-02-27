
#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3Map.h>
#include <string>

typedef I3Map<std::string, double> I3MapStringDouble;
typedef I3Map<std::string, int> I3MapStringInt;



I3_SERIALIZABLE(I3MapStringDouble);

I3_SERIALIZABLE(I3MapStringInt);

