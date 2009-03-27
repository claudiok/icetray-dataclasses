//  (C) Copyright Joel de Guzman 2003.
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//  Modified by Troy D. Straszheim and Jakob van Santen, 2009-03-26

#ifndef STD_MAP_INDEXING_SUITE_JDG20038_HPP
# define STD_MAP_INDEXING_SUITE_JDG20038_HPP

# include <boost/python/suite/indexing/indexing_suite.hpp>
# include <boost/python/iterator.hpp>
# include <boost/python/call_method.hpp>
# include <boost/python/tuple.hpp>
# include <boost/iterator/transform_iterator.hpp>

namespace bp = boost::python;

namespace boost { namespace python {

    // Forward declaration
    template <class Container, bool NoProxy, class DerivedPolicies>
    class std_map_indexing_suite;

    namespace detail
    {
        template <class Container, bool NoProxy>
        class final_std_map_derived_policies
            : public std_map_indexing_suite<Container,
                NoProxy, final_std_map_derived_policies<Container, NoProxy> > {};
    }

    // The map_indexing_suite class is a predefined indexing_suite derived
    // class for wrapping std::vector (and std::vector like) classes. It provides
    // all the policies required by the indexing_suite (see indexing_suite).
    // Example usage:
    //
    //  class X {...};
    //
    //  ...
    //
    //      class_<std::map<std::string, X> >("XMap")
    //          .def(map_indexing_suite<std::map<std::string, X> >())
    //      ;
    //
    // By default indexed elements are returned by proxy. This can be
    // disabled by supplying *true* in the NoProxy template parameter.
    //
    template <
        class Container,
        bool NoProxy = false,
        class DerivedPolicies
            = detail::final_std_map_derived_policies<Container, NoProxy> >
    class std_map_indexing_suite
        : public indexing_suite<
            Container
          , DerivedPolicies
          , NoProxy
          , true
          , typename Container::value_type::second_type
          , typename Container::key_type
          , typename Container::key_type
        >
    {
    public:

        typedef typename Container::value_type value_type;
        typedef typename Container::value_type::second_type data_type;
        typedef typename Container::key_type key_type;
        typedef typename Container::key_type index_type;
        typedef typename Container::size_type size_type;
        typedef typename Container::difference_type difference_type;
        typedef typename Container::const_iterator const_iterator;
        
 // TODO: implement the following methods: (which are actually useful?)
 // popitem()
 // clear()
 // copy()
 // update()
 // setdefault() 

		
        // __getitem__ for std::pair
        static object pair_getitem(value_type const& x, int i) {
            if (i==0 || i==-2) return object(x.first);
            else if (i==1 || i==-1) return object(x.second); 
            else {
                PyErr_SetString(PyExc_IndexError,"Index out of range.");
                throw_error_already_set();
                return object(); // None
            }
        }
        // __len__ std::pair = 2
        static int pair_len(value_type const& x) { return 2; }

        // return a list of keys
        static bp::list keys(Container const&  x)
        {
          bp::list t;
          for(typename Container::const_iterator it = x.begin(); it != x.end(); it++)
            t.append(it->first);
          return t;
        }
        // return a list of values
        static bp::list values(Container const&  x)
        {
          bp::list t;
          for(typename Container::const_iterator it = x.begin(); it != x.end(); it++)
            t.append(it->second);
          return t;
        }
        // return a list of (key,value) tuples
        static bp::list items(Container const&  x)
        {
          bp::list t;
          for(typename Container::const_iterator it = x.begin(); it != x.end(); it++)
            t.append(make_tuple(it->first, it->second));
          return t;
        }

        // set up operators to extract the key, value, or a tuple from a std::pair 
        struct iterkeys
        {
          typedef key_type result_type;

          result_type operator()(value_type const& x) const 
          { 
            return x.first; 
          }
        };

        struct itervalues 
        {
          typedef data_type result_type;

          result_type operator()(value_type const& x) const 
          { 
            return x.second; 
          }
        };

        struct iteritems {
          typedef tuple result_type;

          result_type operator()(value_type const& x) const 
          { 
            return make_tuple(x.first,x.second); 
          }
        };

        template <typename Transform>
        struct make_transform_impl 
        {
          typedef boost::transform_iterator<Transform, const_iterator> iterator;

          static iterator begin(const Container& m)
          { 
            return boost::make_transform_iterator(m.begin(), Transform()); 
          }
          static iterator end(const Container& m)
          { 
            return boost::make_transform_iterator(m.end(), Transform()); 
          }

          static bp::object range()
          {
            return bp::range(&begin, &end);
          }
        };

        template <typename Transform>
        static bp::object 
        make_transform()
        {
          return make_transform_impl<Transform>::range();
        }

        static object
        print_elem(typename Container::value_type const& e)
        {
            return "(%s, %s)" % python::make_tuple(e.first, e.second);
        }

        static
        typename mpl::if_<
            is_class<data_type>
          , data_type&
          , data_type
        >::type
        get_data(typename Container::value_type& e)
        {
            return e.second;
        }

        static typename Container::key_type
        get_key(typename Container::value_type& e)
        {
            return e.first;
        }

        static data_type&
        get_item(Container& container, index_type i_)
        {
            typename Container::iterator i = container.find(i_);
            if (i == container.end())
            {
                PyErr_SetString(PyExc_KeyError, "Invalid key");
                throw_error_already_set();
            }
            return i->second;
        }

        static void
        set_item(Container& container, index_type i, data_type const& v)
        {
            container[i] = v;
        }

        static void
        delete_item(Container& container, index_type i)
        {
            container.erase(i);
        }

        static size_t
        size(Container& container)
        {
            return container.size();
        }

        static bool
        contains(Container& container, key_type const& key)
        {
            return container.find(key) != container.end();
        }

        static bool
        compare_index(Container& container, index_type a, index_type b)
        {
            return container.key_comp()(a, b);
        }

        static index_type
        convert_index(Container& container, PyObject* i_)
        {
            extract<key_type const&> i(i_);
            if (i.check())
            {
                return i();
            }
            else
            {
                extract<key_type> i(i_);
                if (i.check())
                    return i();
            }

            PyErr_SetString(PyExc_TypeError, "Invalid index type");
            throw_error_already_set();
            return index_type();
        }

        template <class Class>
        static void
        extension_def(Class& cl)
        {
            //  Wrap the map's element (value_type)
            std::string elem_name = "std_map_indexing_suite_";
            object class_name(cl.attr("__name__"));
            extract<std::string> class_name_extractor(class_name);
            elem_name += class_name_extractor();
            elem_name += "_entry";

            typedef typename mpl::if_<
                is_class<data_type>
              , return_internal_reference<>
              , default_call_policies
            >::type get_data_return_policy;

            class_<value_type>(elem_name.c_str())
                .def("__repr__", &DerivedPolicies::print_elem)
                .def("data", &DerivedPolicies::get_data, get_data_return_policy(),
                   "K.data() -> the value associated with this pair.\n")
                .def("key", &DerivedPolicies::get_key,
                   "K.key() -> the key associated with this pair.\n")
                .def("__getitem__",&pair_getitem)
                .def("__len__",&pair_len)
                .def("first",&DerivedPolicies::get_key,
                   "K.first() -> the first item in this pair.\n")
                .def("second",&DerivedPolicies::get_data, get_data_return_policy(),
                   "K.second() -> the second item in this pair.\n")
            ;
            // add convenience methods to the map
            cl
                .def("keys", &keys, "D.keys() -> list of D's keys\n")
                .def("has_key", &contains, "D.has_key(k) -> True if D has a key k, else False\n") // don't re-invent the wheel
                .def("values", &values, "D.values() -> list of D's values\n")
                .def("items", &items, "D.items() -> list of D's (key, value) pairs, as 2-tuples\n")
                .def("iteritems", 
                 make_transform<iteritems>(),
                 "D.iteritems() -> an iterator over the (key, value) items of D\n")
                .def("iterkeys", 
                 make_transform<iterkeys>(),
                 "D.iterkeys() -> an iterator over the keys of D\n")
                .def("itervalues", 
                 make_transform<itervalues>(),
                 "D.itervalues() -> an iterator over the values of D\n")
              ;
		      
        }

    };

}} // namespace boost::python

#endif // STD_MAP_INDEXING_SUITE_JDG20038_HPP
