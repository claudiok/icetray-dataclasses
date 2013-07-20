#include <cassert>
#include <boost/dynamic_bitset.hpp>

#include <icetray/serialization.h>
#include <I3/dynamic_bitset.hpp>

namespace TreeBase {
  /*
   * A note about the tree_hash_map::iterator
   * The iterator is a *pair<uint64_t,treeNode>
   * So to get the hash_map key, use iter->first
   * and to get the treeNode, use iter->second
   */
  
  template<typename T, typename Key, typename Hash>
  Tree<T,Key,Hash>::Tree()
  { }
  
  template<typename T, typename Key, typename Hash>
  Tree<T,Key,Hash>::Tree(const T& value)
  {
    insert(value);
  }
  
  template<typename T, typename Key, typename Hash>
  template<typename IterD,typename IterType>
  Tree<T,Key,Hash>::Tree(const iterator_base<IterD,IterType>& other)
  { 
    // TODO: do something
  }
  
  template<typename T, typename Key, typename Hash>
  Tree<T,Key,Hash>::Tree(const Tree<T,Key,Hash>& copy)
  {
    if (copy.head_) {
      uint32_t newsize = copy.size(),elements=1;
      typename tree_hash_map::const_iterator iter = copy.internalMap.find(*(copy.head_));
      assert( iter != copy.internalMap.end() );
      treeNode* newNodes = new treeNode[newsize];
      std::pair<typename tree_hash_map::iterator,bool> insertResult;
      treeNode* n = NULL;
      const treeNode* nOther = &(iter->second);
      const T* data = NULL;
      newNodes[0].data = nOther->data;
      insertResult = internalMap.insert(std::make_pair<Key,treeNode>(nOther->data,newNodes[0]));
      i3_assert( insertResult.second );
      n = &(insertResult.first->second);
      head_ = nOther->data;
      while(elements<newsize) {
        if (nOther->firstChild != NULL) {
          n->firstChild = &(newNodes[elements]);
          data = &(nOther->data);
          nOther = nOther->firstChild;
        } else if (nOther->nextSibling != NULL) {
          n->nextSibling = &(newNodes[elements]);
          data = &(nOther->data);
          nOther = nOther->nextSibling;
        } else if (n->parent != NULL && nOther->parent != NULL) {
          n = n->parent;
          nOther = nOther->parent;
          continue;
        } else
          break;
        newNodes[elements].parent = n;
        newNodes[elements].data = *data;
        insertResult = internalMap.insert(std::make_pair<Key,treeNode>(*data,newNodes[elements]));
        i3_assert( insertResult.second );
        n = &(insertResult.first->second);
        elements++;
      }
    }
  }
  
  template<typename T, typename Key, typename Hash>
  Tree<T,Key,Hash>::~Tree()
  {
    clear();
  }
  
  template<typename T, typename Key, typename Hash>
  const Tree<T,Key,Hash>
  Tree<T,Key,Hash>::operator=(const Tree<T,Key,Hash>& other)
  {
    Tree<T,Key,Hash> tmp(other);
    internalMap = tmp.internalMap;
    head_ = tmp.head_;
    return *this;
  }
  
  template<typename T, typename Key, typename Hash>
  bool
  Tree<T,Key,Hash>::operator==(const Tree<T,Key,Hash>& other) const
  {
    if (head_)
      return (head_ == other.head_ && *head_ == *other.head_
              && internalMap == other.internalMap);
    else
      return (head_ == other.head_);
  }
  
  template<typename T, typename Key, typename Hash>
  bool
  Tree<T,Key,Hash>::operator!=(const Tree<T,Key,Hash>& other) const
  {
    if (head_)
      return (head_ != other.head_ || *head_ != *other.head_
              || internalMap != other.internalMap);
    else
      return (head_ != other.head_);
  }
  
  template<typename T, typename Key, typename Hash>
  const typename Tree<T,Key,Hash>::nonPtrType
  Tree<T,Key,Hash>::at(const Key& key) const
  {
    typename tree_hash_map::const_iterator iter = internalMap.find(key);
    if (iter == internalMap.end())
      return nonPtrType();
    else
      return nonPtrType(iter->second.data);
  }
  
  template<typename T, typename Key, typename Hash>
  const typename Tree<T,Key,Hash>::nonPtrType
  Tree<T,Key,Hash>::parent(const Key& key) const
  {
    typename tree_hash_map::const_iterator iter = internalMap.find(key);
    if (iter == internalMap.end() || iter->second.parent == NULL)
      return nonPtrType();
    else {
      return nonPtrType(iter->second.parent->data);
    }
  }
  
  template<typename T, typename Key, typename Hash>
  const typename Tree<T,Key,Hash>::nonPtrType
  Tree<T,Key,Hash>::previous_sibling(const Key& key) const
  {
    typename tree_hash_map::const_iterator iter = internalMap.find(key);
    if (iter == internalMap.end())
      return nonPtrType();
    const treeNode* n = &(iter->second);
    const treeNode* keynode = &(iter->second);
    if (n->parent == NULL) {
      if (head_) {
        // try iterating over head_ siblings
        iter = internalMap.find(*head_);
        if (iter != internalMap.end()) {
          n = &(iter->second);
          while (n->nextSibling != NULL) {
            if (n->nextSibling == keynode)
              return nonPtrType(n->data);
            n = n->nextSibling;
          }
        }
      }
      return nonPtrType();
    }
    n = n->parent;
    assert( n->firstChild != NULL );
    n = n->firstChild;
    while (n->nextSibling != NULL) {
      if (n->nextSibling == keynode)
        return nonPtrType(n->data);
      n = n->nextSibling;
    }
    return nonPtrType();
  }
  
  template<typename T, typename Key, typename Hash>
  const typename Tree<T,Key,Hash>::nonPtrType
  Tree<T,Key,Hash>::next_sibling(const Key& key) const
  {
    typename tree_hash_map::const_iterator iter = internalMap.find(key);
    if (iter == internalMap.end() || iter->second.nextSibling == NULL)
      return nonPtrType();
    else
      return nonPtrType(iter->second.nextSibling->data);
  }
  
  template<typename T, typename Key, typename Hash>
  std::vector<T>
  Tree<T,Key,Hash>::children(const Key& key) const
  {
    std::vector<T> result;
    typename tree_hash_map::const_iterator iter = internalMap.find(key);
    if (iter != internalMap.end() && iter->second.firstChild != NULL) {
      const treeNode* n = &(iter->second);
      n = n->firstChild;
      result.push_back(n->data);
      while (n->nextSibling != NULL) {
        n = n->nextSibling;
        result.push_back(n->data);
      }
    }
    return result;
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::clear()
  {
    if (head_) {
      internalMap.clear();
      head_ = boost::none;
    }
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::eraseRightSiblings_(const Key& key)
  {
    // erase this node and all right siblings and children
    typename tree_hash_map::iterator iter = internalMap.find(key);
    if (iter == internalMap.end())
      return;
    if (iter->second.nextSibling != NULL)
      eraseRightSiblings_(iter->second.nextSibling->data);
    if (iter->second.firstChild != NULL)
      erase_children(key);
    internalMap.erase(iter);
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::erase(const Key& key)
  {
    typename tree_hash_map::iterator iter = internalMap.find(key);
    if (iter == internalMap.end())
      return;
    if (iter->second.firstChild != NULL)
      erase_children(key);
    const nonPtrType prev = previous_sibling(key);
    if (prev) {
      // attach next sibling to previous sibling
      typename tree_hash_map::iterator iter2 = internalMap.find(*prev);
      assert( iter2 != internalMap.end() );
      iter2->second.nextSibling = iter->second.nextSibling;
    } else if (iter->second.parent != NULL) {
      // attach next sibling as first child of parent
      iter->second.parent->firstChild = iter->second.nextSibling;
    }
    // erase node from map
    internalMap.erase(iter);
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::erase_children(const Key& key) {
    typename tree_hash_map::iterator iter = internalMap.find(key);
    if (iter == internalMap.end())
      return;
    if (iter->second.firstChild != NULL) {
      eraseRightSiblings_(iter->second.firstChild->data);
      iter->second.firstChild = NULL;
    }
  }
  
  template<typename T, typename Key, typename Hash>
  const typename Tree<T,Key,Hash>::nonPtrType
  Tree<T,Key,Hash>::get_head() const
  {
    nonPtrType ret;
    if (head_) {
      typename tree_hash_map::const_iterator iter = internalMap.find(*head_);
      if (iter != internalMap.end())
        ret = iter->second.data;
    }
    return ret;
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::append_child(const Key& node, const T& child)
  {
    typename tree_hash_map::iterator iter = internalMap.find(child);
    assert( iter == internalMap.end() );
    iter = internalMap.find(node);
    assert( iter != internalMap.end() );
    treeNode newNode = treeNode(child);
    newNode.parent = &(iter->second);
    std::pair<typename tree_hash_map::iterator,bool> insertResult;
    insertResult = internalMap.insert(std::make_pair<Key,treeNode>(child,newNode));
    i3_assert( insertResult.second );
    treeNode* n = &(iter->second);
    if (n->firstChild != NULL) {
      // add as last child
      n = n->firstChild;
      while ( n->nextSibling != NULL ) {
        n = n->nextSibling;
      }
      n->nextSibling = &(insertResult.first->second);
    } else {
      // add as only child
      n->firstChild = &(insertResult.first->second);
    }
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::append_child(const Key& node, const Tree<T,Key,Hash>& otherTree, const Key& node2)
  {
    assert( !subtree_in_tree(otherTree,node2) );
    typename tree_hash_map::const_iterator iter = otherTree.internalMap.find(node2);
    assert( iter != otherTree.internalMap.end() );
    append_child(node,iter->second.data);
    if (iter->second.firstChild != NULL) {
      // append all children of node2
      const treeNode* n = &(iter->second);
      n = n->firstChild;
      append_child(node2,otherTree,n->data);
      while (n->nextSibling != NULL) {
        n = n->nextSibling;
        append_child(node2,otherTree,n->data);
      }
    }
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::append_children(const Key& node, const std::vector<T>& children)
  {
    if (!children.empty()) {
      typename std::vector<T>::const_iterator iter = children.begin();
      append_child(node,*iter);
      const T* lastChild = &(*iter);
      for(iter++;iter!=children.end();iter++) {
        insert_after(*lastChild,*iter);
        lastChild = &(*iter);
      }
    }
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::insert(const T& node2)
  {
    treeNode newNode = treeNode(node2);
    if (head_) {
      typename tree_hash_map::iterator iter = internalMap.find(*head_);
      assert( iter != internalMap.end() );
      newNode.nextSibling = &(iter->second);
    }
    std::pair<typename tree_hash_map::iterator,bool> insertResult;
    insertResult = internalMap.insert(std::make_pair<Key,treeNode>(node2,newNode));
    i3_assert( insertResult.second );
    head_ = node2;
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::insert_after(const T& node2)
  {
    treeNode newNode = treeNode(node2);
    std::pair<typename tree_hash_map::iterator,bool> insertResult;
    insertResult = internalMap.insert(std::make_pair<Key,treeNode>(node2,newNode));
    i3_assert( insertResult.second );
    if (head_) {
      typename tree_hash_map::iterator iter = internalMap.find(*head_);
      assert( iter != internalMap.end() );
      treeNode* n = &(iter->second);
      while (n->nextSibling != NULL) {
        n = n->nextSibling;
      }
      n->nextSibling = &(insertResult.first->second);
    } else
      head_ = node2;
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::insert(const Key& node, const T& node2)
  {
    typename tree_hash_map::iterator iter = internalMap.find(node2);
    assert( iter == internalMap.end() );
    iter = internalMap.find(node);
    assert( iter != internalMap.end() );
    treeNode newNode = treeNode(node2);
    newNode.parent = iter->second.parent;
    newNode.nextSibling = &(iter->second);
    std::pair<typename tree_hash_map::iterator,bool> insertResult;
    insertResult = internalMap.insert(std::make_pair<Key,treeNode>(node2,newNode));
    i3_assert( insertResult.second );
    const nonPtrType prev = previous_sibling(node);
    if (prev) {
      iter = internalMap.find(*prev);
      assert( iter != internalMap.end() );
      iter->second.nextSibling = &(insertResult.first->second);
    } else if (iter->second.parent != NULL) {
      // there is no left sibling, so node2 is the new left-most sibling
      treeNode* n = &(iter->second);
      n = n->parent;
      n->firstChild = &(insertResult.first->second);
    }
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::insert_after(const Key& node, const T& node2)
  {
    typename tree_hash_map::iterator iter = internalMap.find(node2);
    assert( iter == internalMap.end() );
    iter = internalMap.find(node);
    assert( iter != internalMap.end() );
    treeNode newNode = treeNode(node2);
    newNode.parent = iter->second.parent;
    newNode.nextSibling = iter->second.nextSibling;
    std::pair<typename tree_hash_map::iterator,bool> insertResult;
    insertResult = internalMap.insert(std::make_pair<Key,treeNode>(node2,newNode));
    i3_assert( insertResult.second );
    iter->second.nextSibling = &(insertResult.first->second);
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::insert_subtree(const Key& node, const Tree<T,Key,Hash>& otherTree, const Key& node2)
  {
    assert( !subtree_in_tree(otherTree,node2) );
    typename tree_hash_map::const_iterator iter = otherTree.internalMap.find(node2);
    assert( iter != otherTree.internalMap.end() );
    insert(node,iter->second.data);
    if (iter->second.firstChild != NULL) {
      // append all children of node2
      const treeNode* n = &(iter->second);
      n = n->firstChild;
      append_child(node2,otherTree,n->data);
      while (n->nextSibling != NULL) {
        n = n->nextSibling;
        append_child(node2,otherTree,n->data);
      }
    }
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::insert_subtree_after(const Key& node, const Tree<T,Key,Hash>& otherTree, const Key& node2)
  {
    assert( !subtree_in_tree(otherTree,node2) );
    typename tree_hash_map::const_iterator iter = otherTree.internalMap.find(node2);
    assert( iter != otherTree.internalMap.end() );
    insert_after(node,iter->second.data);
    if (iter->second.firstChild != NULL) {
      // append all children of node2
      const treeNode* n = &(iter->second);
      n = n->firstChild;
      append_child(node2,otherTree,n->data);
      while (n->nextSibling != NULL) {
        n = n->nextSibling;
        append_child(node2,otherTree,n->data);
      }
    }
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::replace(const Key& node, const T& node2)
  {
    typename tree_hash_map::iterator iter = internalMap.find(node2);
    assert( iter == internalMap.end() );
    iter = internalMap.find(node);
    assert( iter != internalMap.end() );
    treeNode newNode = treeNode(node2);
    newNode.parent = iter->second.parent;
    newNode.nextSibling = iter->second.nextSibling;
    newNode.firstChild = iter->second.firstChild;
    std::pair<typename tree_hash_map::iterator,bool> insertResult;
    insertResult = internalMap.insert(std::make_pair<Key,treeNode>(node2,newNode));
    i3_assert( insertResult.second );
    const nonPtrType prev = previous_sibling(node);
    if (prev) {
      typename tree_hash_map::iterator iter2 = internalMap.find(*prev);
      assert( iter2 != internalMap.end() );
      iter2->second.nextSibling = &(insertResult.first->second);
    } else if (iter->second.parent != NULL) {
      // there is no left sibling, so node2 is the new left-most sibling
      iter->second.parent->firstChild = &(insertResult.first->second);
    }
    internalMap.erase(iter);
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::replace(const Key& node, const Tree<T,Key,Hash>& otherTree, const Key& node2)
  {
    assert( !subtree_in_tree(otherTree,node2) );
    typename tree_hash_map::const_iterator iter = otherTree.internalMap.find(node2);
    assert( iter != otherTree.internalMap.end() );
    erase_children(node);
    replace(node,iter->second.data);
    if (iter->second.firstChild != NULL) {
      // append all children of node2
      const treeNode* n = &(iter->second);
      n = n->firstChild;
      append_child(node2,otherTree,n->data);
      while (n->nextSibling) {
        n = n->nextSibling;
        append_child(node2,otherTree,n->data);
      }
    }
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::flatten(const Key& node)
  {
    typename tree_hash_map::iterator iter = internalMap.find(node);
    assert( iter != internalMap.end() );
    if (iter->second.firstChild != NULL) {
      // move children to siblings
      treeNode* n = &(iter->second);
      n = n->firstChild;
      n->parent = iter->second.parent;
      while (n->nextSibling != NULL) {
        n = n->nextSibling;
        n->parent = iter->second.parent;
      }
      n->nextSibling = iter->second.nextSibling;
      iter->second.nextSibling = iter->second.firstChild;
      iter->second.firstChild = NULL;
    }
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::reparent(const Key& node, const Key& from)
  {
    typename tree_hash_map::iterator iter = internalMap.find(node);
    assert( iter != internalMap.end() );
    typename tree_hash_map::iterator iter2 = internalMap.find(from);
    assert( iter2 != internalMap.end() );
    if (iter2->second.firstChild != NULL) {
      // move firstChild
      treeNode* n = &(iter->second);
      if (n->firstChild != NULL) {
        n = n->firstChild;
        while (n->nextSibling != NULL) {
          n = n->nextSibling;
        }
        n->nextSibling = iter2->second.firstChild;
      } else {
        n->firstChild = iter2->second.firstChild;
      }
      // set parents of all children
      treeNode* n2 = &(iter2->second);
      n2 = n2->firstChild;
      n2->parent = &(iter->second);
      while (n2->nextSibling != NULL) {
        n2 = n2->nextSibling;
        n2->parent = &(iter->second);
      }
      iter2->second.firstChild = NULL;
    }
  }
  
  template<typename T, typename Key, typename Hash>
  typename Tree<T,Key,Hash>::size_type
  Tree<T,Key,Hash>::size() const
  {
    return internalMap.size();
  }
  
  template<typename T, typename Key, typename Hash>
  bool
  Tree<T,Key,Hash>::empty() const
  {
    return internalMap.empty();
  }
  
  template<typename T, typename Key, typename Hash>
  typename Tree<T,Key,Hash>::size_type
  Tree<T,Key,Hash>::depth(const Key& node) const
  {
    typename tree_hash_map::const_iterator iter = internalMap.find(node);
    if (iter == internalMap.end())
      return 0;
    const treeNode* n = &(iter->second);
    size_type d(0);
    while (n->parent != NULL) {
      d++;
      n = n->parent;
    }
    return d;
  }
  
  template<typename T, typename Key, typename Hash>
  typename Tree<T,Key,Hash>::size_type
  Tree<T,Key,Hash>::number_of_children(const Key& node) const
  {
    typename tree_hash_map::const_iterator iter = internalMap.find(node);
    assert( iter != internalMap.end() );
    const treeNode* n = &(iter->second);
    size_type d(0);
    if (n->firstChild == NULL)
      return d;
    d++;
    n = n->firstChild;
    while (n->nextSibling != NULL) {
      d++;
      n = n->nextSibling;
    }
    return d;
  }
  
  template<typename T, typename Key, typename Hash>
  typename Tree<T,Key,Hash>::size_type
  Tree<T,Key,Hash>::number_of_siblings(const Key& node) const
  {
    typename tree_hash_map::const_iterator iter = internalMap.find(node);
    assert( iter != internalMap.end() );
    if (iter->second.parent == NULL) {
      if (!head_)
        return 0;
      iter = internalMap.find(*head_);
      assert( iter != internalMap.end() );
      const treeNode* n = &(iter->second);
      size_type d(0);
      do {
        if (node != n->data)
          d++;
        n = n->nextSibling;
      } while (n != NULL);
      return d;
    } else {
      return number_of_children(iter->second.parent->data)-1;
    }
  }
  
  template<typename T, typename Key, typename Hash>
  bool
  Tree<T,Key,Hash>::is_in_subtree(const Key& haystack, const Key& needle) const
  {
    if (needle == haystack) {
      return true;
    }
    typename tree_hash_map::const_iterator iter = internalMap.find(haystack);
    assert( iter != internalMap.end() );
    const treeNode* n = &(iter->second);
    if (n->firstChild != NULL) {
      n = n->firstChild;
      if (is_in_subtree(n->data,needle))
        return true;
      while (n->nextSibling != NULL) {
        n = n->nextSibling;
        if (is_in_subtree(n->data,needle))
          return true;
      }
    }
    return false;
  }
  
  template<typename T, typename Key, typename Hash>
  bool
  Tree<T,Key,Hash>::subtree_in_tree(const Tree<T,Key,Hash>& other, const Key& node) const
  {
    typename tree_hash_map::const_iterator iter = internalMap.find(node);
    if (iter != internalMap.end())
      return true;
    iter = other.internalMap.find(node);
    if (iter == other.internalMap.end())
      return false;
    const treeNode* n = &(iter->second);
    bool ret = false;
    if (n->firstChild != NULL) {
      n = n->firstChild;
      ret |= subtree_in_tree(other,n->data);
      while (!ret && n->nextSibling != NULL) {
        n = n->nextSibling;
        ret |= subtree_in_tree(other,n->data);
      }
    }
    return ret;
  }
  
  
  static const uint32_t CHUNK_SIZE_ = 40;//65535;
  
  template<typename T, typename Key, typename Hash>
  template<class Archive>
  void
  Tree<T,Key,Hash>::load(Archive & ar, unsigned version)
  {
    clear();
    if (version == 0) {
      // load old-style Tree
      // TODO: implement this
      assert( false );
    } else {
      // load new Tree
      ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
      boost::dynamic_bitset<> nullMask(CHUNK_SIZE_);
      std::vector<I3Particle> dataChunk;
      // TODO: think about implementing our own hash_map<allocator>
      // and swapping hash_maps to make L2 caching better
      std::pair<Key,treeNode > * newNodes;
      std::pair<typename tree_hash_map::iterator,bool> insertResult;
      uint32_t chunkSize(0), i(0), elements(0);
      bool firstChild(true);
      treeNode* n = NULL;
      do {
        nullMask.reset();
        dataChunk.clear();
        //std::vector<T>().swap(dataChunk);
        i=0;
        elements=0;
        ar & make_nvp("numBits",chunkSize);
        if (chunkSize <= 0)
          break;
        nullMask.resize(chunkSize);
        ar & make_nvp("chunkMask",nullMask);
        ar & make_nvp("chunkData",dataChunk);
        newNodes = new std::pair<Key,treeNode >[dataChunk.size()];
        if (!head_ && chunkSize > 0) {
          // take first element as root
          newNodes[0].first = dataChunk[0];
          newNodes[0].second.data = dataChunk[0];
          insertResult = internalMap.insert(newNodes[0]);
          i3_assert( insertResult.second );
          head_ = dataChunk[0];
          n = &(insertResult.first->second);
          i++;
          elements++;
        }
        for(;i<chunkSize;i++) {
          if (nullMask[i]) {
            newNodes[elements].second.data = dataChunk[elements];
            newNodes[elements].first = dataChunk[elements];
            insertResult = internalMap.insert(newNodes[elements]);
            i3_assert( insertResult.second );
            if (firstChild) {
              n->firstChild = &(insertResult.first->second);
              insertResult.first->second.parent = n;
            } else {
              n->nextSibling = &(insertResult.first->second);
              insertResult.first->second.parent = n->parent;
            }
            n = &(insertResult.first->second);
            firstChild = true;
            elements++;
          } else {
            if (firstChild)
              firstChild = false;
            else if (n->parent != NULL)
              n = n->parent;
            else {
              chunkSize = 0; // hit root, so break both loops
              break;
            }
          }
        }
      } while (chunkSize == CHUNK_SIZE_);
    }
  }
  
  
  template<typename T, typename Key, typename Hash>
  template<class Archive>
  void
  Tree<T,Key,Hash>::save(Archive & ar, unsigned version) const
  {
    ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
    
    // do pre_order_iteration and find child and sibling pointers that are null
    uint32_t nelements(0);
    if (!head_) {
      ar & make_nvp("numBits",nelements);
      return;
    }
    boost::dynamic_bitset<> nullMask(CHUNK_SIZE_);
    typename tree_hash_map::const_iterator iter = internalMap.find(*head_);
    const treeNode* n = &(iter->second);
    const treeNode* nprev = NULL;
    bool firstChild(true);
    std::vector<I3Particle> dataChunk;
    do {
      for(nelements=0;nelements<CHUNK_SIZE_;nelements++) {
        if (n != NULL) {
          nullMask.set(nelements,1);
          dataChunk.push_back(n->data);
          nprev = n;
          n = n->firstChild;
          firstChild = true;
        } else {
          if (firstChild) {
            firstChild = false;
            n = nprev->nextSibling;
          } else {
            if (nprev == NULL)
              break; // found root
            n = nprev->parent;
            if (n != NULL)
              n = n->nextSibling;
            nprev = nprev->parent;
          }
          nullMask.set(nelements,0);
        }
      }
      ar & make_nvp("numBits",nelements);
      nullMask.resize(nelements);
      ar & make_nvp("chunkMask",nullMask);
      ar & make_nvp("chunkData",dataChunk);
      nullMask.reset();
      dataChunk.clear();
      //std::vector<T>().swap(dataChunk);
    } while (nelements >= CHUNK_SIZE_);
  }

};


