#ifndef I3BAG_H
#define I3BAG_H

/**
 * Class: I3Bag
 *
 * Version: $Id: I3Bag.h,v 1.5 2004/02/16 19:20:22 troy Exp $
 *
 * Date: 30 Jan 2004
 *
 * (c) 2004 IceCube collaboration
 *
 */

#include "TObject.h"
#include "TMap.h"


/**
 * I3Bag is a generic keyed TObject container, akin to the
 * Sieglinde bag. Each Event (and geometry etc) gets one so that it can hold 
 * stuff that  doesn't really fit into the Data structure.  Just for 
 * 'temporary' or 'personal' use.
 */
class I3Bag : public TObject {
 public:
  I3Bag();
  virtual ~I3Bag();

  /**
   * adds an object to the bag.  'Fails' if the name is already used.
   */
  Bool_t AddObject(TObject* obj,const Char_t* key);

  /**
   * Retrieves the indicated object, if it exists.  
   * A fatal error occurs if the name isn't used, so check first
   * with 'HasObject()'
   * @param key the name of the object you're getting out
   * @param type the name of the type that you expect the object to be
   */
  const TObject& GetObject(const Char_t* key,const Char_t* type);

  /**
   * Tells if the keyed object exists in the bag.
   */
  Bool_t HasObject(const Char_t* key,const Char_t* type);
 private:
  TMap* fMap;
  ClassDef(I3Bag,1);
};

#endif //I3BAG_H
