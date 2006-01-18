#ifndef TTREE_PROXY_INCLUDED
#define TTREE_PROXY_INCLUDED

#include <boost/scoped_ptr.hpp>

namespace boost {  namespace archive { namespace detail {
  class ttree_proxy_impl;
} } }

class TTree;

/**
   This is a "compiler firewall" class (the "pimpl" idiom)
   that forwards all operations to the unseen ttree_proxy_impl, which does
   all the work.
*/
class ttree_proxy
{
  
  boost::scoped_ptr<boost::archive::detail::ttree_proxy_impl> impl_;

public:

  void push(const std::string&);
  void pop();
  void branch(char typechar, void* address);
  void fill();

  ttree_proxy(TTree&);
  ~ttree_proxy();

};

#endif //TTREE_PROXY_H_INCLUDED
