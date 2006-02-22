#include "dataclasses/BoostHeaders.h"
#include "dataclasses/Utility.h"

string ToString(shared_ptr<const TObject> obj)
{
  ostringstream outstring;
  boost::archive::xml_oarchive ar(outstring);
  ar << make_nvp("", obj);
  return outstring.str();
}

string ToString(const TObject& obj)
{
  TObject* ob = obj.Clone();
  shared_ptr<TObject> newobj(new TObject(*ob));
  return ToString(newobj);
}

ostream& operator<<(ostream& o, shared_ptr<const TObject> obj)
{
  o<<ToString(obj);
  return o;
}

ostream& operator<<(ostream& o, const TObject& obj)
{
  o<<ToString(obj);
  return o;
}
