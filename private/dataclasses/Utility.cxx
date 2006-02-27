#include "dataclasses/BoostHeaders.h"
#include "dataclasses/Utility.h"
#include "TClass.h"

string ToString(shared_ptr<const TObject> obj)
{
  ostringstream outstring;
  boost::archive::xml_oarchive ar(outstring);
  ar << make_nvp(obj->IsA()->GetName(), obj);
  return outstring.str();
}

string ToString(const TObject& obj)
{
  TObject* ob = obj.Clone();
  ostringstream outstring;
  boost::archive::xml_oarchive ar(outstring);
  ar << make_nvp(ob->IsA()->GetName(), ob);
  return outstring.str();
}
