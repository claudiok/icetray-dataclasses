/**
 * @file I3MCTree.h
 * @brief Tree of I3Particles
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
  
  
  /**
   * A generic tree node
   */
  template<typename T>
  class TreeNode {
    public:
      TreeNode<T>* parent;
      TreeNode<T>* firstChild;
      TreeNode<T>* nextSibling;
      T data;
      
      TreeNode() : parent(NULL),firstChild(NULL),nextSibling(NULL) { }
      TreeNode(const T& d) : parent(NULL),firstChild(NULL),nextSibling(NULL),data(d) { }
      T operator*() { return data; }
      T operator=(const TreeNode<T>& other) { return data = other.data; }
      T operator=(const T& otherData) { return data = otherData; }
      bool operator==(const TreeNode<T>& other) const
      {
        if (data != other.data)
          return false;
        if (parent == NULL) {
          if (other.parent != NULL)
            return false;
        } else {
          if (other.parent == NULL)
            return false;
          else if (parent->data != other.parent->data)
            return false;
        }
        if (firstChild == NULL) {
          if (other.firstChild != NULL)
            return false;
        } else {
          if (other.firstChild == NULL)
            return false;
          else if (firstChild->data != other.firstChild->data)
            return false;
        }
        if (nextSibling == NULL) {
          if (other.nextSibling != NULL)
            return false;
        } else {
          if (other.nextSibling == NULL)
            return false;
          else if (nextSibling->data != other.nextSibling->data)
            return false;
        }
        return true;
      }
      bool operator==(const T& otherData) const { return data == otherData; }
      bool operator!=(const TreeNode<T>& other) const { return !(*this == other); }
      bool operator!=(const T& otherData) const { return !(*this == otherData); }
  };
  
  /**
   * A generic tree class for hashable, unique data types
   * T is the data type
   * Key is the lookup type (T must be able to be implicitly converted to Key)
   * Hash is the hash function to convert from Key to size_t
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
      typedef boost::optional<Key> TreeHashKey;
      typedef TreeNode<value_type> treeNode;
      typedef hash_map<Key,treeNode > tree_hash_map;
      
      tree_hash_map internalMap;
      TreeHashKey head_;
      TreeHashKey end_; // a special end node that doesn't really exist
      
      void eraseRightSiblings_(const Key&);
      
    public:
      // note: required to use underscores on std methods
      //       to match tree_indexing_suite
      
      /**
       * Iterator base (for tree-based iterators)
       */
      template<class Derived, class Value, class TreeValue,
               class TreeHashMapIter>
      class iterator_base
        : public boost::iterator_facade<
            iterator_base<Derived,Value,TreeValue,TreeHashMapIter>,
            Value,
            boost::forward_traversal_tag
          >
      {
        public:
          iterator_base() : node_(derived_().first_()) { }
          explicit iterator_base(TreeValue& ext) :
            ext_(&ext), node_(derived_().first_()) { }
          explicit iterator_base(TreeValue& ext, const Value* v) :
            ext_(&ext)
          {
            TreeHashMapIter iter = internalMap.find(*v);
            if (iter == internalMap.end())
              node_ = ext.end_;
            else
              node_ = *v;
          }
          explicit iterator_base(TreeValue& ext, const Key& k) :
            ext_(&ext)
          {
            TreeHashMapIter iter = ext.internalMap.find(k);
            if (iter == ext.internalMap.end())
              node_ = ext.end_;
            else
              node_ = k;
          }
        protected:
          TreeHashKey first_() { return ext_->head_; };
          void next_() { };
          TreeValue* ext_;
          TreeHashKey node_;
        private:
          friend class Tree<T,Key,Hash>;
          explicit iterator_base(TreeValue& ext, const TreeHashKey& h) :
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
            TreeHashMapIter iter = ext_->internalMap.find(*node_);
            assert( iter != ext_->internalMap.end() );
            return iter->second.data;
          }
          bool equal(iterator_base<Derived,Value,TreeValue,TreeHashMapIter> const & other) const
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
      template <class Value, class TreeValue=Tree<T,Key,Hash>,
               class TreeHashMapIter=typename tree_hash_map::iterator>
      class pre_order : public iterator_base<pre_order<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>
      {
        public:
          pre_order(TreeValue& ext) :
            iterator_base<pre_order<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>(ext) { }
          explicit pre_order(TreeValue& ext, const Value* value) :
            iterator_base<pre_order<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>(ext,value) { }
          explicit pre_order(TreeValue& ext, const Key& k) :
            iterator_base<pre_order<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>(ext,k) { }
          explicit pre_order(TreeValue& ext, const TreeHashKey& k) :
            iterator_base<pre_order<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>(ext,k) { }
        private:
          friend class iterator_base<pre_order<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>;
        protected:
          void next_()
          {
            TreeHashMapIter iter = this->ext_->internalMap.find(*(this->node_));
            if (iter == this->ext_->internalMap.end()) {
              this->node_ = this->ext_->end_;
              return;
            }
            const treeNode* n = &(iter->second); // TODO: templatize const TreeNode
            if (n->firstChild != NULL)
              n = n->firstChild;
            else if (n->nextSibling != NULL)
              n = n->nextSibling;
            else if (n->parent != NULL) {
              // go to a parent's next sibling
              do {
                n = n->parent;
                if (n->nextSibling != NULL)
                  break;
              } while (n->parent != NULL);
              if (n->nextSibling != NULL)
                n = n->nextSibling;
              else {
                this->node_ = this->ext_->end_;
                return;
              }
            } else {
              this->node_ = this->ext_->end_;
              return;
            }
            assert( n != NULL );
            this->node_ = n->data;
          }
      };
      typedef pre_order<T> pre_order_iterator;
      typedef pre_order<const T, const Tree<T,Key,Hash>,
              typename tree_hash_map::const_iterator> pre_order_const_iterator;
      
      /**
       * Post order iterator: O(n log n)
       */
      template <class Value, class TreeValue=Tree<T,Key,Hash>,
               class TreeHashMapIter=typename tree_hash_map::iterator>
      class post_order : public iterator_base<post_order<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>
      {
        public:
          post_order(TreeValue& ext) :
            iterator_base<post_order<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>(ext) { }
          explicit post_order(TreeValue& ext, const Value* value) :
            iterator_base<post_order<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>(ext,value) { }
          explicit post_order(TreeValue& ext, const Key& k) :
            iterator_base<post_order<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>(ext,k) { }
          explicit post_order(TreeValue& ext, const TreeHashKey& k) :
            iterator_base<post_order<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>(ext,k) { }
        private:
          friend class iterator_base<post_order<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>;
        protected:
          TreeHashKey first_()
          {
            if (this->ext_->head_) {
              // go to leftmost child
              TreeHashMapIter iter = this->ext_->internalMap.find(*(this->ext_->head_));
              if (iter == this->ext_->internalMap.end())
                return this->ext_->end_;
              treeNode* n = &(iter->second);
              while (n->firstChild != NULL) {
                n = n->firstChild;
              }
              return TreeHashKey(n->data);
            } else
              return this->ext_->end_;
          }
          void next_()
          {
            TreeHashMapIter iter = this->ext_->internalMap.find(*(this->node_));
            if (iter == this->ext_->internalMap.end()) {
              this->node_ = this->ext_->end_;
              return;
            }
            treeNode* n = &(iter->second);
            if (n->nextSibling != NULL) {
              // go to leftmost child of next sibling
              n = n->nextSibling;
              while (n->firstChild != NULL) {
                n = n->firstChild;
              }
            } else if (n->parent != NULL) {
              // go to parent
              n = n->parent;
            } else {
              this->node_ = this->ext_->end_;
              return;
            }
            this->node_ = n->data;
          }
      };
      typedef post_order<T> post_order_iterator;
      typedef post_order<const T, const Tree<T,Key,Hash>,
              typename tree_hash_map::const_iterator> post_order_const_iterator;
      
      /**
       * Sibling iterator: O(n)
       */
      template<class Value, class TreeValue=Tree<T,Key,Hash>,
               class TreeHashMapIter=typename tree_hash_map::iterator>
      class sibling_iter : public iterator_base<sibling_iter<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>
      {
        public:
          sibling_iter(TreeValue& ext) :
            iterator_base<sibling_iter<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>(ext) { }
          explicit sibling_iter(TreeValue& ext, const Value* value) :
            iterator_base<sibling_iter<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>(ext,value) { }
          explicit sibling_iter(TreeValue& ext, const Key& k) :
            iterator_base<sibling_iter<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>(ext,k) { }
          explicit sibling_iter(TreeValue& ext, const TreeHashKey& k) :
            iterator_base<sibling_iter<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>(ext,k) { }
        private:
          friend class iterator_base<sibling_iter<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>;
        protected:
          void next_()
          {
            TreeHashMapIter iter = this->ext_->internalMap.find(*(this->node_));
            if (iter == this->ext_->internalMap.end() || iter->second.nextSibling == NULL) {
              this->node_ = this->ext_->end_;
            } else {
              this->node_ = iter->second.nextSibling->data;
            }
          }
      };
      typedef sibling_iter<T> sibling_iterator;
      typedef sibling_iter<const T, const Tree<T,Key,Hash>,
              typename tree_hash_map::const_iterator> sibling_const_iterator;
      
      /**
       * Iterator map base (for unordered iterators)
       * Gives greater speed by using the hash_map's iterators
       */
      template<class Derived,class Value, class TreeValue=Tree<T,Key,Hash>,
               class TreeHashMapIter=typename tree_hash_map::iterator>
      class iterator_map_base
        : public boost::iterator_facade<
            iterator_map_base<Derived,Value,TreeValue,TreeHashMapIter>,
            Value,
            boost::forward_traversal_tag
          >
      {
        public:
          iterator_map_base(TreeValue& ext) :
            ext_(&ext), internalIter_(derived_().first_()) { }
          explicit iterator_map_base(TreeValue& ext, Value* v) :
            ext_(&ext),
            internalIter_(ext.internalMap.find(valueToHash_(*v))) { }
          explicit iterator_map_base(TreeValue& ext, const Key& k) :
            ext_(&ext), 
            internalIter_(ext.internalMap.find(k)) { }
        protected:
          TreeHashMapIter first_()
          { return this->ext_->internalMap.begin(); }
          void next_() { this->internalIter_++; };
          TreeValue* ext_;
          TreeHashMapIter internalIter_;
        private:
          friend class Tree<T,Key,Hash>;
          explicit iterator_map_base(TreeValue& ext, const TreeHashKey& k) :
            ext_(&ext), internalIter_(ext.internalMap.end())
          { if (k) this->internalIter_ = ext.internalMap.find(*k); }
          Derived& derived_()
          {
            return *static_cast<Derived*>(this);
          }
          friend class boost::iterator_core_access;
          Value& dereference() const
          {
            assert( internalIter_ != ext_->internalMap.end() );
            return internalIter_->second.data;
          }
          bool equal(iterator_map_base<Derived,Value,TreeValue,TreeHashMapIter> const & other) const
          {
            return ( internalIter_ == other.internalIter_ );
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
      template <class Value, class TreeValue=Tree<T,Key,Hash>,
               class TreeHashMapIter=typename tree_hash_map::iterator>
      class fast_iter : public iterator_map_base<fast_iter<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>
      {
        public:
          fast_iter(TreeValue& ext) :
            iterator_map_base<fast_iter<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>(ext) { }
          explicit fast_iter(TreeValue& ext, Value* v) :
            iterator_map_base<fast_iter<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>(ext,v) { }
          explicit fast_iter(TreeValue& ext, const Key& k) :
            iterator_map_base<fast_iter<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>(ext,k) { }
          explicit fast_iter(TreeValue& ext, const TreeHashKey& k) :
            iterator_map_base<fast_iter<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>(ext,k) { }
        private:
          friend class iterator_map_base<fast_iter<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>;
      };
      typedef fast_iter<T> fast_iterator;
      typedef fast_iter<const T, const Tree<T,Key,Hash>,
              typename tree_hash_map::const_iterator > fast_const_iterator;
      
      /**
       * Leaf iterator: O(n)
       * Note that there is no ordering of leaves
       */
      template <class Value, class TreeValue=Tree<T,Key,Hash>,
               class TreeHashMapIter=typename tree_hash_map::iterator>
      class leaf_iter : public iterator_map_base<leaf_iter<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>
      {
        public:
          leaf_iter(TreeValue& ext) :
            iterator_map_base<leaf_iter<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>(ext) { }
          explicit leaf_iter(TreeValue& ext, Value* v) :
            iterator_map_base<leaf_iter<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>(ext,v) { }
          explicit leaf_iter(TreeValue& ext, const Key& k) :
            iterator_map_base<leaf_iter<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>(ext,k) { }
          explicit leaf_iter(TreeValue& ext, const TreeHashKey& k) :
            iterator_map_base<leaf_iter<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>(ext,k) { }
        private:
          friend class iterator_map_base<leaf_iter<Value,TreeValue,TreeHashMapIter>,Value,TreeValue,TreeHashMapIter>;
        protected:
          TreeHashMapIter first_()
          {
            TreeHashMapIter iter = this->ext_->internalMap.begin(),
                            iterEnd = this->ext_->internalMap.end();
            for(;iter != iterEnd; iter++) {
              if (iter->second.firstChild != NULL)
                continue;
              else
                break;
            }
            return iter;
          }
          void next_()
          {
            this->internalIter_++;
            TreeHashMapIter iterEnd = this->ext_->internalMap.end();
            for(;this->internalIter_ != iterEnd; this->internalIter_++) {
              if (this->internalIter_->second.firstChild != NULL)
                continue;
              else
                break;
            }
          }
      };
      typedef leaf_iter<T> leaf_iterator;
      typedef leaf_iter<const T, const Tree<T,Key,Hash>,
              typename tree_hash_map::const_iterator> leaf_const_iterator;
      
      /**
       * Define the default iterator
       */
      typedef pre_order_iterator iterator;
      typedef pre_order_const_iterator const_iterator;
      
      /**
       * Constructors and destructor
       */
      Tree();
      Tree(const T& value);
      template<class D,class V,class TreeValue,class TreeHashMapIter>
      Tree(const iterator_base<D,V,TreeValue,TreeHashMapIter>& other);
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
      
      // pre_order iterator helpers
      inline pre_order_iterator begin()
      { return pre_order_iterator(*this); }
      inline pre_order_const_iterator cbegin() const
      { return pre_order_const_iterator(*this); }
      inline pre_order_iterator end()
      { return pre_order_iterator(*this,end_); };
      inline pre_order_const_iterator cend() const
      { return pre_order_const_iterator(*this,end_); };
      
      // post_order iterator helpers
      inline post_order_iterator begin_post()
      { return post_order_iterator(*this); }
      inline post_order_const_iterator cbegin_post() const
      { return post_order_const_iterator(*this); }
      inline post_order_iterator end_post()
      { return post_order_iterator(*this,end_); }
      inline post_order_const_iterator cend_post() const
      { return post_order_const_iterator(*this,end_); }
      
      // sibling iterator helpers
      template<class D,class V,class TreeValue,class TreeHashMapIter>
      sibling_iterator begin(const iterator_base<D,V,TreeValue,TreeHashMapIter>& i)
      {
        if (i != iterator_base<D,V,TreeValue,TreeHashMapIter>(end_))
          return sibling_iterator(*this,*i);
        else
          return sibling_iterator(*this,end_);
      }
      template<class D,class V,class TreeValue,class TreeHashMapIter>
      sibling_const_iterator cbegin(const iterator_base<D,V,TreeValue,TreeHashMapIter>& i) const
      {
        if (i != iterator_base<D,V,TreeValue,TreeHashMapIter>(end_))
          return sibling_const_iterator(*this,*i);
        else
          return sibling_const_iterator(*this,end_);
      }
      inline sibling_iterator begin_sibling(const Key& k)
      { return sibling_iterator(*this,k); }
      inline sibling_const_iterator cbegin_sibling(const Key& k) const
      { return sibling_const_iterator(*this,k); }
      template<class D,class V,class TreeValue,class TreeHashMapIter>
      inline sibling_iterator end(const iterator_base<D,V,TreeValue,TreeHashMapIter>& i)
      { return sibling_iterator(*this,end_); }
      template<class D,class V,class TreeValue,class TreeHashMapIter>
      inline sibling_const_iterator cend(const iterator_base<D,V,TreeValue,TreeHashMapIter>& i) const
      { return sibling_const_iterator(*this,end_); }
      inline sibling_iterator end_sibling()
      { return sibling_iterator(*this,end_); }
      inline sibling_const_iterator cend_sibling() const
      { return sibling_const_iterator(*this,end_); }
      
      // fast iterator helpers
      inline fast_iterator begin_fast()
      { return fast_iterator(*this); }
      inline fast_const_iterator cbegin_fast() const
      { return fast_const_iterator(*this); }
      inline fast_iterator end_fast()
      { return fast_iterator(*this,end_); };
      inline fast_const_iterator cend_fast() const
      { return fast_const_iterator(*this,end_); };
      
      // leaf iterator helpers
      inline leaf_iterator begin_leaf()
      { return leaf_iterator(*this); }
      inline leaf_const_iterator cbegin_leaf() const
      { return leaf_const_iterator(*this); }
      inline leaf_iterator end_leaf()
      { return leaf_iterator(*this,end_); };
      inline leaf_const_iterator cend_leaf() const
      { return leaf_const_iterator(*this,end_); };
      
      /**
       * Get head value
       */
      const nonPtrType get_head() const;
      const std::vector<T> get_heads() const;
      
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
      const std::vector<T> children(const Key&) const;
      
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
       * Add several children to a node
       */
      void append_children(const Key& node, const std::vector<T>&);
      
      /**
       * Insert at root level before other nodes
       */
      void insert(const T&);
      
      /**
       * Insert at root level after other nodes
       */
      void insert_after(const T&);
      
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
      friend class boost::serialization::access;
      template <class Archive> void load(Archive & ar, unsigned version);
      template <class Archive> void save(Archive & ar, unsigned version) const;
      
      BOOST_SERIALIZATION_SPLIT_MEMBER();
      
      SET_LOGGER("Tree");
  };
  
};



/**
 * I3MCTree - This goes into the frame and everyone can see it
 */
/*class I3MCTree : public TreeBase::Tree<I3Particle,I3ParticleID>
{
  public:
    // constructors
    I3MCTree();
    I3MCTree(const I3Particle&);
    template<class D,class V> I3MCTree(const iterator_base<D,V>& other);
    I3MCTree(const I3MCTree& m);
    
  private:
    friend class boost::serialization::access;
    BOOST_SERIALIZATION_SPLIT_MEMBER();
};*/
typedef TreeBase::Tree<I3Particle,I3ParticleID> I3MCTree;

BOOST_CLASS_VERSION(I3MCTree,TreeBase::tree_version_);
I3_POINTER_TYPEDEFS(I3MCTree);
I3_DEFAULT_NAME(I3MCTree);

#include "dataclasses/physics/I3MCTree.hh"

#endif // DATACLASSES_I3MCTREE_H_INCLUDED

