#ifndef DATACLASSES_TEST_RANDOM_IARCHIVE_H
#define DATACLASSES_TEST_RANDOM_IARCHIVE_H

#include <vector>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include "boost/archive/detail/common_iarchive.hpp"

const unsigned CONTAINER_SIZE_MODULUS = 25;

class random_iarchive : 
  public boost::archive::detail::common_iarchive<random_iarchive>
{
public:
  
  template <typename T>
  void load(T &t, unsigned i = 0)
  {
  }

  template <typename T>
  void load_override(T &t, unsigned i=0)
  {
    boost::archive::load(* this->This(), t);
  }
  
  template <typename T>
  void load_override(std::vector<T> &t, unsigned i=0)
  {
    unsigned size = random();
    t.resize(size % CONTAINER_SIZE_MODULUS);
    for (typename std::vector<T>::iterator iter = t.begin();
	 iter != t.end();
	 iter++)
      boost::archive::load(* this->This(), *iter);
  }

  template <typename T>
  void load_override(std::vector<boost::shared_ptr<T> > &t, unsigned i=0)
  {
    unsigned size = random();
    t.resize(size % CONTAINER_SIZE_MODULUS);
    for (typename std::vector<boost::shared_ptr<T> >::iterator iter = t.begin();
	 iter != t.end();
	 iter++)
      {
	*iter = boost::shared_ptr<T>(new T);
	boost::archive::load(* this->This(), **iter);
      }
  }

  template <typename T>
  void load_override(boost::shared_ptr<T> &pt, unsigned i=0)
  {
    
    pt = boost::shared_ptr<T>(new T);
    //    (* this->This()) >> make_nvp("pointee", *pt);
    boost::archive::load(* this->This(), *pt);
  }

  template <typename T>
  void load (boost::shared_ptr<T> &pt, unsigned v = 0)
  {
    pt = boost::shared_ptr<T>(new T);
    boost::archive::load(* this->This(), *pt);
  }

  void load (int &i, unsigned v = 0)
  {
    i = random();
  }

  void load (double &d, unsigned v = 0)
  {
    d = random() * 1.001;
  }

  void load (float &f, unsigned i = 0)
  {
    f = random() * 1.001;
  }

  void load (std::string &s, unsigned i = 0)
  {
    s = tmpnam(NULL);
  }

};

#endif
