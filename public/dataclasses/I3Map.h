/**
    copyright  (C) 2004
    the icecube collaboration
    @version $Id: StoragePolicy.h 14347 2006-01-15 15:15:08Z pretz $
    @date    $Date: 2006-01-15 10:15:08 -0500 (Sun, 15 Jan 2006) $
*/

#ifndef I3MAP_H_INCLUDED
#define I3MAP_H_INCLUDED

#include "TObject.h"
#include <map>

template <typename Key, typename Value>
class I3Map : public TObject, public std::map<Key, Value>
{ };

#endif // I3MAP_H_INCLUDED

