/**
 * @file I3MCTree.h
 * @brief
 * 
 * copyright (C) 2013 the icecube collaboration
 * 
 * $Id$
 * @version $Revision$
 * @date $Date$
 */

#ifndef DATACLASSES_I3MCTREE_H_INCLUDED
#define DATACLASSES_I3MCTREE_H_INCLUDED

#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include <stdint.h>

#include <boost/none.hpp>
#include <boost/optional.hpp>
#include <boost/iterator/iterator_facade.hpp>

#include <icetray/I3DefaultName.h>
#include <icetray/I3FrameObject.h>
#include <icetray/serialization.h>
#include <icetray/I3Logging.h>

#include <I3/hash_map.h>
#include "dataclasses/physics/I3Particle.h"
#include "dataclasses/physics/I3ParticleID.h"


/* Define basic tree structures here instead of in I3Tree so 
   we don't break other tree operations with the I3MCTree upgrade
*/
namespace TreeBase {
  static const unsigned tree_version_ = 1;
  
  typedef boost::optional<uint64_t> TreeHashKey;
  
  /**
   * A generic tree node
   */
  template<typename T>
  class TreeNode {
    public:
      TreeHashKey parent;
      TreeHashKey firstChild;
      TreeHashKey nextSibling;
      T data;
      
      TreeNode() { };
      TreeNode(const T& d) : data(d) { };
      T operator*() { return data; }
      T operator=(const TreeNode<T>& other) { return data = other.data; }
      T operator=(const T& otherData) { return data = otherData; }
      bool operator==(const TreeNode<T>& other) const
      { 
        return (data == other.data &&
                parent == other.parent &&
                firstChild == other.firstChild &&
                nextSibling == other.nextSibling);
      }
      bool operator==(const T& otherData) const { return data == otherData; }
      bool operator!=(const TreeNode<T>& other) const { return !(*this == other); }
      bool operator!=(const T& otherData) const { return !(*this == otherData); }
    private:
      friend class boost::serialization::access;
      template <class Archive> void load(Archive & ar, unsigned version);
      template <class Archive> void save(Archive & ar, unsigned version) const;
      BOOST_SERIALIZATION_SPLIT_MEMBER();
  };
  
  /**
   * A generic tree class for hashable, unique data types
   * T is the data type
   * Key is the lookup type (T must be able to be implicitly converted to Key)
   * Hash is the hash function to convert from Key to uint64_t
   */
  template<typename T, typename Key=T, typename Hash=hash<Key> >
  class Tree : public I3FrameObject {
    public:
      typedef T      value_type;
      typedef T*     pointer;
      typedef T&     reference;
      typedef size_t size_type;
      
      /**
       * The nonPtrType is used when returning by value
       * when there might not be anything to return.
      */
      typedef boost::optional<T>  nonPtrType;
    protected:
      typedef TreeNode<value_type > treeNode;
      typedef hash_map<uint64_t,treeNode > tree_hash_map;
      
      tree_hash_map internalMap;
      TreeHashKey head_;
      TreeHashKey end_; // a special end node that doesn't really exist
      
      Hash hash_functor_;
      inline uint64_t valueToHash_(const Key& value) const
      { return (uint64_t)hash_functor_(value); }
      
      void headInitialize_();
      void erase_(const uint64_t&);
      void eraseRightSiblings_(const uint64_t&);
      void eraseChildren_(const uint64_t&);
      typename tree_hash_map::const_iterator getLeftSibling_(const uint64_t&) const;
      typename tree_hash_map::iterator getLeftSibling_(const uint64_t&);
      bool subtree_in_tree_(const Tree<T,Key,Hash>& other, const uint64_t&) const;
      void append_child_(const uint64_t& node, const T&);
      
    public:
      // note: required to use underscores on std methods
      //       to match tree_indexing_suite
      
      /**
       * Iterator base (for tree-based iterators)
       */
      template<class Derived, class Value>
      class iterator_base
        : public boost::iterator_facade<
            iterator_base<Derived,Value>,
            Value,
            boost::forward_traversal_tag
          >
      {
        public:
          iterator_base() : node_(derived_().first_()) { }
          explicit iterator_base(Tree<T,Key,Hash>& ext) :
            ext_(&ext), node_(derived_().first_()) { }
          explicit iterator_base(Tree<T,Key,Hash>& ext, const Value* v) :
            ext_(&ext)
          {
            uint64_t h = ext_.valueToHash_((Key)(*v));
            typename tree_hash_map::iterator iter = internalMap.find(h);
            if (iter == internalMap.end())
              node_ = ext.end_;
            else
              node_ = h;
          }
          explicit iterator_base(Tree<T,Key,Hash>& ext, const Key& k) :
            ext_(&ext)
          {
            uint64_t h = ext.valueToHash_(k);
            typename tree_hash_map::iterator iter = ext.internalMap.find(h);
            if (iter == ext.internalMap.end())
              node_ = ext.end_;
            else
              node_ = h;
          }
        protected:
          TreeHashKey first_() { return ext_->head_; };
          void next_() { };
          mutable Tree<T,Key,Hash>* ext_;
          mutable TreeHashKey node_;
        private:
          friend class Tree<T,Key,Hash>;
          explicit iterator_base(Tree<T,Key,Hash>& ext, const TreeHashKey& h) :
            ext_(&ext), node_(h) { }
          Derived& derived_()
          {
            return *static_cast<Derived*>(this);
          }
          friend class boost::iterator_core_access;
          Value& dereference() const
          {
            assert( node_ != ext_->end_ );
            assert( node_ );
            typename tree_hash_map::iterator iter = ext_->internalMap.find(*node_);
            assert( iter != ext_->internalMap.end() );
            return iter->second.data;
          }
          bool equal(iterator_base<Derived,Value> const & other) const
          {
            return (node_ == other.node_);
          }
          void increment()
          {
            derived_().next_();
          }
      };
      
      /**
       * Pre order iterator: O(n)
       */
      template <class Value>
      class pre_order : public iterator_base<pre_order<Value>,Value>
      {
        public:
          pre_order(Tree<T,Key,Hash>& ext) :
            iterator_base<pre_order<Value>,Value>(ext) { }
          explicit pre_order(Tree<T,Key,Hash>& ext, const Value* value) :
            iterator_base<pre_order<Value>,Value>(ext,value) { }
          explicit pre_order(Tree<T,Key,Hash>& ext, const Key& k) :
            iterator_base<pre_order<Value>,Value>(ext,k) { }
          explicit pre_order(Tree<T,Key,Hash>& ext, const TreeHashKey& k) :
            iterator_base<pre_order<Value>,Value>(ext,k) { }
        private:
          friend class iterator_base<pre_order<Value>,Value>;
        protected:
          void next_()
          {
            typename tree_hash_map::iterator iter = this->ext_->internalMap.find(*(this->node_));
            if (iter == this->ext_->internalMap.end()) {
              this->node_ = this->ext_->end_;
              return;
            }
            if (iter->second.firstChild)
              iter = this->ext_->internalMap.find(*(iter->second.firstChild));
            else if (iter->second.nextSibling)
              iter = this->ext_->internalMap.find(*(iter->second.nextSibling));
            else if (iter->second.parent) {
              // go to a parent's next sibling
              do {
                iter = this->ext_->internalMap.find(*(iter->second.parent));
                assert( iter != this->ext_->internalMap.end() );
                if (iter->second.nextSibling)
                  break;
              } while (iter->second.parent);
              if (iter->second.nextSibling)
                iter = this->ext_->internalMap.find(*(iter->second.nextSibling));
              else {
                this->node_ = this->ext_->end_;
                return;
              }
            } else {
              this->node_ = this->ext_->end_;
              return;
            }
            assert( iter != this->ext_->internalMap.end() );
            this->node_ = iter->first;
          }
      };
      typedef pre_order<T> pre_order_iterator;
      typedef pre_order<T const> pre_order_const_iterator;
      
      /**
       * Post order iterator: O(n log n)
       */
      template <class Value>
      class post_order : public iterator_base<post_order<Value>,Value>
      {
        public:
          post_order(Tree<T,Key,Hash>& ext) :
            iterator_base<post_order<Value>,Value>(ext) { }
          explicit post_order(Tree<T,Key,Hash>& ext, const Value* value) :
            iterator_base<post_order<Value>,Value>(ext,value) { }
          explicit post_order(Tree<T,Key,Hash>& ext, const Key& k) :
            iterator_base<post_order<Value>,Value>(ext,k) { }
          explicit post_order(Tree<T,Key,Hash>& ext, const TreeHashKey& k) :
            iterator_base<post_order<Value>,Value>(ext,k) { }
        private:
          friend class iterator_base<post_order<Value>,Value>;
        protected:
          TreeHashKey first_()
          {
            if (this->ext_->head_) {
              // go to leftmost child
              typename tree_hash_map::iterator iter = this->ext_->internalMap.find(*(this->ext_->head_));
              while (iter->second.firstChild) {
                iter = this->ext_->internalMap.find(*(iter->second.firstChild));
                assert( iter != this->ext_->internalMap.end() );
              }
              return iter->first;
            } else
              return this->ext_->end_;
          }
          void next_()
          {
            typename tree_hash_map::iterator iter = this->ext_->internalMap.find(*(this->node_));
            if (iter == this->ext_->internalMap.end()) {
              this->node_ = this->ext_->end_;
              return;
            }
            if (iter->second.nextSibling) {
              // go to leftmost child of next sibling
              iter = this->ext_->internalMap.find(*(iter->second.nextSibling));
              assert( iter != this->ext_->internalMap.end() );
              while (iter->second.firstChild) {
                iter = this->ext_->internalMap.find(*(iter->second.firstChild));
                assert( iter != this->ext_->internalMap.end() );
              }
            } else if (iter->second.parent) {
              // go to parent
              iter = this->ext_->internalMap.find(*(iter->second.parent));
              assert( iter != this->ext_->internalMap.end() );
            } else {
              this->node_ = this->ext_->end_;
              return;
            }
            this->node_ = iter->first;
          }
      };
      typedef post_order<T> post_order_iterator;
      typedef post_order<T const> post_order_const_iterator;
      
      /**
       * Sibling iterator: O(n)
       */
      template<class Value>
      class sibling_iter : public iterator_base<sibling_iter<Value>,Value>
      {
        public:
          sibling_iter(Tree<T,Key,Hash>& ext) :
            iterator_base<sibling_iter<Value>,Value>(ext) { }
          explicit sibling_iter(Tree<T,Key,Hash>& ext, const Value* value) :
            iterator_base<sibling_iter<Value>,Value>(ext,value) { }
          explicit sibling_iter(Tree<T,Key,Hash>& ext, const Key& k) :
            iterator_base<sibling_iter<Value>,Value>(ext,k) { }
          explicit sibling_iter(Tree<T,Key,Hash>& ext, const TreeHashKey& k) :
            iterator_base<sibling_iter<Value>,Value>(ext,k) { }
        private:
          friend class iterator_base<sibling_iter<Value>,Value>;
        protected:
          void next_()
          {
            typename tree_hash_map::iterator iter = this->ext_->internalMap.find(*(this->node_));
            if (iter == this->ext_->internalMap.end() || !(iter->second.nextSibling)) {
              this->node_ = this->ext_->end_;
            } else {
              iter = this->ext_->internalMap.find(*(iter->second.nextSibling));
              assert( iter != this->ext_->internalMap.end() );
              this->node_ = iter->first;
            }
          }
      };
      typedef sibling_iter<T> sibling_iterator;
      typedef sibling_iter<T const> sibling_const_iterator;
      
      /**
       * Iterator map base (for unordered iterators)
       * Gives greater speed by using the hash_map's iterators
       */
      template<class Derived,class Value>
      class iterator_map_base
        : public boost::iterator_facade<
            iterator_map_base<Derived,Value>,
            Value,
            boost::forward_traversal_tag
          >
      {
        public:
          iterator_map_base(Tree<T,Key,Hash>& ext) :
            ext_(&ext), internalIter_(derived_().first_()) { }
          explicit iterator_map_base(Tree<T,Key,Hash>& ext, Value* v) :
            ext_(&ext),
            internalIter_(ext.internalMap.find(valueToHash_(*v))) { }
          explicit iterator_map_base(Tree<T,Key,Hash>& ext, Key& k) :
            ext_(&ext), 
            internalIter_(ext.internalMap.valueToHash_(k)) { }
        protected:
          typename tree_hash_map::iterator first_()
          { return this->ext_->internalMap.begin(); }
          void next_() { this->internalIter_++; };
          mutable Tree<T,Key,Hash>* ext_;
          mutable typename tree_hash_map::iterator internalIter_;
        private:
          friend class Tree<T,Key,Hash>;
          explicit iterator_map_base(Tree<T,Key,Hash>& ext, const TreeHashKey& k) :
            ext_(&ext), internalIter_(ext.internalMap.end())
          { if (k) this->internalIter_ = ext.internalMap.find(*k); }
          Derived& derived_()
          {
            return *static_cast<Derived*>(this);
          }
          friend class boost::iterator_core_access;
          T& dereference() const
          {
            assert( internalIter_ != ext_->internalMap.end() );
            return internalIter_->second.data;
          }
          bool equal(iterator_map_base<Derived,Value> const & other) const
          {
            return ( internalIter_ == other.internalIter_ );
            //typename tree_hash_map::iterator i1 = internalIter_;
            //typename tree_hash_map::iterator i2 = other.internalIter_;
            //return (i1 == i2);
          }
          void increment()
          {
            derived_().next_();
          }
      };
      
      /**
       * Fast iterator: O(n)
       * Note that there is no ordering, but this gives the fastest results
       */
      template <class Value>
      class fast_iter : public iterator_map_base<fast_iter<Value>,Value>
      {
        public:
          fast_iter(Tree<T,Key,Hash>& ext) :
            iterator_map_base<fast_iter<Value>,Value>(ext) { }
          explicit fast_iter(Tree<T,Key,Hash>& ext, Value* v) :
            iterator_map_base<fast_iter<Value>,Value>(ext,v) { }
          explicit fast_iter(Tree<T,Key,Hash>& ext, Key& k) :
            iterator_map_base<fast_iter<Value>,Value>(ext,k) { }
          explicit fast_iter(Tree<T,Key,Hash>& ext, const TreeHashKey& k) :
            iterator_map_base<fast_iter<Value>,Value>(ext,k) { }
        private:
          friend class iterator_map_base<fast_iter<Value>,Value>;
      };
      typedef fast_iter<T> fast_iterator;
      typedef fast_iter<T const> fast_const_iterator;
      
      /**
       * Leaf iterator: O(n)
       * Note that there is no ordering of leaves
       */
      template <class Value>
      class leaf_iter : public iterator_map_base<leaf_iter<Value>,Value>
      {
        public:
          leaf_iter(Tree<T,Key,Hash>& ext) :
            iterator_map_base<leaf_iter<Value>,Value>(ext) { }
          explicit leaf_iter(Tree<T,Key,Hash>& ext, Value* v) :
            iterator_map_base<leaf_iter<Value>,Value>(ext,v) { }
          explicit leaf_iter(Tree<T,Key,Hash>& ext, Key& k) :
            iterator_map_base<leaf_iter<Value>,Value>(ext,k) { }
          explicit leaf_iter(Tree<T,Key,Hash>& ext, const TreeHashKey& k) :
            iterator_map_base<leaf_iter<Value>,Value>(ext,k) { }
        private:
          friend class iterator_map_base<leaf_iter<Value>,Value>;
        protected:
          typename tree_hash_map::iterator first_()
          {
            typename tree_hash_map::iterator iter = this->ext_->internalMap.begin(),
                                    iterEnd = this->ext_->internalMap.end();
            for(;iter != iterEnd; iter++) {
              if (iter->second.firstChild)
                continue;
              else
                break;
            }
            return iter;
          }
          void next_()
          {
            this->internalIter_++;
            typename tree_hash_map::iterator iterEnd = this->ext_->internalMap.end();
            for(;this->internalIter_ != iterEnd; this->internalIter_++) {
              if (this->internalIter_->second.firstChild)
                continue;
              else
                break;
            }
          }
      };
      typedef leaf_iter<T> leaf_iterator;
      typedef leaf_iter<T const> leaf_const_iterator;
      
      /**
       * Define the default iterator
       */
      typedef pre_order_iterator iterator;
      
      /**
       * Constructors and destructor
       */
      Tree();
      Tree(const T& value);
      template<class D,class V> Tree(const iterator_base<D,V>& other);
      Tree(const Tree<T,Key,Hash>&);
      ~Tree();
      
      /**
       * Assignment operator
       */
      const Tree<T,Key,Hash> operator=(const Tree<T,Key,Hash>&);
      
      /**
       * Equality operator to compare two trees
       */
      bool operator==(const Tree<T,Key,Hash>& other) const;
      bool operator!=(const Tree<T,Key,Hash>& other) const;
      
      
      inline pre_order_iterator begin()
      { return pre_order_iterator(*this); }
      inline pre_order_iterator end()
      { return pre_order_iterator(*this,end_); };
      inline post_order_iterator begin_post()
      { return post_order_iterator(*this); }
      inline post_order_iterator end_post()
      { return post_order_iterator(*this,end_); }
//      fixed_depth_iterator begin_fixed(const iterator_base&, unsigned int) const;
//      fixed_depth_iterator end_fixed(const iterator_base&, unsigned int) const;
      template<class D,class V>
      inline sibling_iterator begin(const iterator_base<D,V>& i)
      { return sibling_iterator(*this,i); }
      inline sibling_iterator begin_sibling(const Key& k)
      { return sibling_iterator(*this,k); }
      template<class D,class V>
      inline sibling_iterator end(const iterator_base<D,V>& i)
      { return sibling_iterator(*this,end_); }
      inline sibling_iterator end_sibling()
      { return sibling_iterator(*this,end_); }
      inline fast_iterator begin_fast()
      { return fast_iterator(*this); }
      inline fast_iterator end_fast()
      { return fast_iterator(*this,end_); };
      inline leaf_iterator begin_leaf()
      { return leaf_iterator(*this); }
      inline leaf_iterator end_leaf()
      { return leaf_iterator(*this,end_); };
      
      /**
       * Get head value
       */
      const nonPtrType get_head() const;
      
      /**
       * Get value at key
       */
      const nonPtrType at(const Key&) const;
      
      /**
       * Get parent
       */
      const nonPtrType parent(const Key&) const;
      //template<typename iter> iter parent(iter) const;
      
      /**
       * Get previous sibling
       */
      const nonPtrType previous_sibling(const Key&) const;
      //template<typename iter> iter previous_sibling(iter) const;
      
      /**
       * Get next sibling
       */
      const nonPtrType next_sibling(const Key&) const;
      //template<typename iter> iter next_sibling(iter) const;
      //template<typename iter> iter next_at_same_depth(iter) const;
      
      /**
       * Get immediate children
       */
      std::vector<T> children(const Key&) const;
      
      /**
       * Clear all nodes from tree
       */
      void clear();
      
      /**
       * Erase node and children
       */
      void erase(const Key&);
//      template<typename iter> iter erase(iter);
      
      /**
       * Erase children of node
       */
      void erase_children(const Key&);
//      void erase_children(const iterator_base&);
      
      /**
       * Short-hand to insert topmost node in otherwise empty tree
       */
      pre_order_iterator set_head(const T&);
      
      /**
       * Add a child to a node
       */
      void append_child(const Key& node, const T&);
//      template<typename iter> iter appendChild(iter);
//      template<typename iter> iter appendChild(iter, const T&);
//      template<typename iter> iter appendChild(iter,iter);
//      template<typename iter> iter appendChild(const T& node, const T&);
//      template<typename iter> iter appendChild(const T&, iter);
      
      /**
       * Add subtree as a child to a node
       */
      void append_child(const Key& node, const Tree<T,Key,Hash>&, const Key&);
      
      /**
       * Insert as sibling before node
       */
      void insert(const Key& node, const T&);
//      template<typename iter> iter insert(iter, const T&);
      
      /**
        * Insert as sibling after node
        */
      void insert_after(const Key& node, const T&);
//      template<typename iter> iter insertAfter(iter, const T&);

      /**
       * Insert subtree as sibling before node
       */
      void insert_subtree(const Key& node, const Tree<T,Key,Hash>&, const Key&);
//      template<typename iter> iter insertSubtree(iter, const iterator_base&);
      
      /**
       * Insert subtree as sibling after node
       */
      void insert_subtree_after(const Key& node, const Tree<T,Key,Hash>&, const Key&);
//      template<typename iter> iter insertSubtreeAfter(iter, const iterator_base&);
      
      /**
       * Replace node (keeping children)
       */
      void replace(const Key& node, const T&);
//      template<typename iter> iter replace(iter, const T&);

      /**
       * Replace node (and children) with subtree
       */
      void replace(const Key&, const Tree<T,Key,Hash>&, const Key&);
      
      /**
       * Move all children of node to be siblings
       */
      void flatten(const Key&);
//      template<typename iter> iter flatten(iter);
      
      /**
       * Move all child nodes of 'from' to be children of 'node'
       */
      void reparent(const Key& node, const Key& from);
//      template<typename iter> iter reparent(iter, iter from);
      
      /**
       * Merge with other tree
       */
//      void merge(const Tree<T,Hash>&);
//      void merge(const T&, const Tree<T,Hash>&);
      
//      void sort_siblings(const T&);
//      void sort_siblings(sibling_iterator from, sibling_iterator to);
      
      // Compare two subtrees
//      bool equal_subtree(const T&, const T&);
//      template<typename iter> bool equal_subtree(const iter&, const iter&);
      
      // Extract subtree formed by node and children
//      Tree<T,Hash> subtree(const T& node);
      
      // swap subtrees (node+children)
//      void swap(const T&,const T&)
//      void swap(sibling_iterator);
      
      size_type size() const;
      bool empty() const;
      
      /**
       * Compute depth to the root
       */
      size_type depth(const Key&) const;
      
      /**
       * Get the number of children a node has
       */
      size_type number_of_children(const Key&) const;
      
      /**
       * Get the number of siblings a node has
       */
      size_type number_of_siblings(const Key&) const;
      
      /**
       * Search for a key in the subtree
       */
      bool is_in_subtree(const Key& haystack, const Key& needle) const;
      
      /**
       * Finds if any key in the subtree is in the tree
       */
      bool subtree_in_tree(const Tree<T,Key,Hash>& other, const Key& node) const;
      
    protected:
      Tree(const uint64_t& value);
      
      friend class boost::serialization::access;
      template <class Archive> void load(Archive & ar, unsigned version);
      template <class Archive> void save(Archive & ar, unsigned version) const;
      
      BOOST_SERIALIZATION_SPLIT_MEMBER();
      
      SET_LOGGER("Tree");
  };
  
  //BOOST_CLASS_VERSION(Tree<>,tree_version_);
  //I3_POINTER_TYPEDEFS(Tree<>);
};



/**
 *I3MCTree - This goes into the frame and everyone can see it
 */
class I3MCTree : public TreeBase::Tree<I3Particle,I3ParticleID>
{
  private:
    // really hope that no I3ParticleID ever hashes to this
    static const uint64_t HIDDEN_ROOT_;
    
    friend class boost::serialization::access;
    BOOST_SERIALIZATION_SPLIT_MEMBER();
    
  public:
    // constructors
    I3MCTree();
    I3MCTree(const I3Particle&);
    template<class D,class V> I3MCTree(const iterator_base<D,V>& other);
    I3MCTree(const I3MCTree& m);
    
    // disable set_head so we don't overwrite the root
    void set_head(const I3Particle&);
    
    // modify empty to always keey HIDDEN_ROOT
    
    
    /**
     * Add a primary particle
     */
    void AddPrimary(const I3Particle&);
};

BOOST_CLASS_VERSION(I3MCTree,TreeBase::tree_version_);
I3_POINTER_TYPEDEFS(I3MCTree);
I3_DEFAULT_NAME(I3MCTree);

#include "dataclasses/physics/I3MCTree.hh"

#endif // DATACLASSES_I3MCTREE_H_INCLUDED

