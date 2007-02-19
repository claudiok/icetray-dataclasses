
#include <icetray/serialization.h>
#include <dataclasses/I3Vector.h>
#include <string>

I3_SERIALIZABLE(I3VectorBool);
I3_SERIALIZABLE(I3Vector<char>);

I3_SERIALIZABLE(I3VectorShort);
I3_SERIALIZABLE(I3VectorUShort);
I3_SERIALIZABLE(I3VectorInt);
I3_SERIALIZABLE(I3Vector<unsigned int>);
I3_SERIALIZABLE(I3Vector<long>);
I3_SERIALIZABLE(I3Vector<unsigned long>);
I3_SERIALIZABLE(I3Vector<long long>);
I3_SERIALIZABLE(I3Vector<unsigned long long>);

I3_SERIALIZABLE(I3VectorFloat);
I3_SERIALIZABLE(I3VectorDouble);

I3_SERIALIZABLE(I3VectorString);
I3_SERIALIZABLE(I3VectorOMKey);

