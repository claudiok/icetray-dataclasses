#include <cassert>

#include <icetray/serialization.h>


namespace TreeBase {
  /*
   * A note about the tree_hash_map::iterator
   * The iterator is a *pair<uint64_t,treeNode>
   * So to get the hash_map key, use iter->first
   * and to get the treeNode, use iter->second
   */
  
  template <typename T>
  template <class Archive>
  void
  TreeNode<T>::load(Archive & ar, unsigned version)
  {
    ar & make_nvp("data",data);
    uint8_t packed;
    ar & make_nvp("active",packed);
    if (packed&0x4)
      ar & make_nvp("parent",*parent);
    if (packed&0x2)
      ar & make_nvp("firstChild",*firstChild);
    if (packed&0x1)
      ar & make_nvp("nextSibling",*nextSibling);
  }
  
  template <typename T>
  template <class Archive>
  void
  TreeNode<T>::save(Archive & ar, unsigned version) const
  {
    ar & make_nvp("data",data);
    uint8_t packed = 0;
    if (parent)
      packed |= (uint32_t)0x4;
    if (firstChild)
      packed |= (uint32_t)0x2;
    if (nextSibling)
      packed |= (uint32_t)0x1;
    ar & make_nvp("active",packed);
    if (parent)
      ar & make_nvp("parent",*parent);
    if (firstChild)
      ar & make_nvp("firstChild",*firstChild);
    if (nextSibling)
      ar & make_nvp("nextSibling",*nextSibling);
  }
  
  template<typename T, typename Key, typename Hash>
  Tree<T,Key,Hash>::Tree()
  {
    headInitialize_();
  }
  
  template<typename T, typename Key, typename Hash>
  Tree<T,Key,Hash>::Tree(const T& value)
  {
    headInitialize_();
    set_head(value);
  }
  
  template<typename T, typename Key, typename Hash>
  template<typename IterD,typename IterType>
  Tree<T,Key,Hash>::Tree(const iterator_base<IterD,IterType>& other)
  {
    headInitialize_();
    set_head(other->second);
  }
  
  template<typename T, typename Key, typename Hash>
  Tree<T,Key,Hash>::Tree(const Tree<T,Key,Hash>& copy)
  {
    internalMap = tree_hash_map(copy.internalMap);
    head_ = copy.head_;
  }
  
  template<typename T, typename Key, typename Hash>
  Tree<T,Key,Hash>::Tree(const uint64_t& value)
  {
    headInitialize_();
    head_ = value;
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
    internalMap = tree_hash_map(other.internalMap);
    head_ = other.head_;
    return other;
  }
  
  template<typename T, typename Key, typename Hash>
  bool
  Tree<T,Key,Hash>::operator==(const Tree<T,Key,Hash>& other) const
  {
    return internalMap == other.internalMap;
  }
  
  template<typename T, typename Key, typename Hash>
  bool
  Tree<T,Key,Hash>::operator!=(const Tree<T,Key,Hash>& other) const
  {
    return internalMap != other.internalMap;
  }
  
  template<typename T, typename Key, typename Hash>
  const typename Tree<T,Key,Hash>::nonPtrType
  Tree<T,Key,Hash>::at(const Key& key) const
  {
    typename tree_hash_map::const_iterator iter = internalMap.find(valueToHash_(key));
    if (iter == internalMap.end())
      return nonPtrType();
    else
      return nonPtrType(iter->second.data);
  }
  
  template<typename T, typename Key, typename Hash>
  const typename Tree<T,Key,Hash>::nonPtrType
  Tree<T,Key,Hash>::parent(const Key& key) const
  {
    typename tree_hash_map::const_iterator iter = internalMap.find(valueToHash_(key));
    if (iter == internalMap.end() || !iter->second.parent)
      return nonPtrType();
    else {
      iter = internalMap.find(*(iter->second.parent));
      assert( iter != internalMap.end() );
      return nonPtrType(iter->second.data);
    }
  }
  
  template<typename T, typename Key, typename Hash>
  const typename Tree<T,Key,Hash>::nonPtrType
  Tree<T,Key,Hash>::previous_sibling(const Key& key) const
  {
    uint64_t h = valueToHash_(key);
    typename tree_hash_map::const_iterator iter = internalMap.find(h);
    if (iter == internalMap.end() || !iter->second.parent)
      return nonPtrType();
    else {
      iter = getLeftSibling_(h);
      if ( iter == internalMap.end() )
        return nonPtrType();
      else
        return nonPtrType(iter->second.data);
    }
  }
  
  template<typename T, typename Key, typename Hash>
  const typename Tree<T,Key,Hash>::nonPtrType
  Tree<T,Key,Hash>::next_sibling(const Key& key) const
  {
    typename tree_hash_map::const_iterator iter = internalMap.find(valueToHash_(key));
    if (iter == internalMap.end() || !iter->second.nextSibling)
      return nonPtrType();
    else {
      iter = internalMap.find(*(iter->second.nextSibling));
      assert( iter != internalMap.end() );
      return nonPtrType(iter->second.data);
    }
  }
  
  template<typename T, typename Key, typename Hash>
  std::vector<T>
  Tree<T,Key,Hash>::children(const Key& key) const
  {
    std::vector<T> result;
    typename tree_hash_map::const_iterator iter = internalMap.find(valueToHash_(key));
    if (iter != internalMap.end() && iter->second.firstChild) {
      iter = internalMap.find(*(iter->second.firstChild));
      assert( iter != internalMap.end() );
      result.push_back(iter->second.data);
      while (iter->second.nextSibling) {
        iter = internalMap.find(*(iter->second.nextSibling));
        assert( iter != internalMap.end() );
        result.push_back(iter->second.data);
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
  typename Tree<T,Key,Hash>::tree_hash_map::const_iterator 
  Tree<T,Key,Hash>::getLeftSibling_(const uint64_t& h) const
  {
    typename tree_hash_map::const_iterator iter = internalMap.find(h);
    assert( iter != internalMap.end() );
    if (!iter->second.parent)
      return internalMap.end();
    iter = internalMap.find(*(iter->second.parent));
    assert( iter != internalMap.end() );
    assert( iter->second.firstChild );
    if (*(iter->second.firstChild) == h)
      return internalMap.end();
    iter = internalMap.find(*(iter->second.firstChild));
    assert( iter != internalMap.end() );
    while (iter->second.nextSibling && *(iter->second.nextSibling) != h) {
      iter = internalMap.find(*(iter->second.nextSibling));
      assert( iter != internalMap.end() );
    }
    if (iter != internalMap.end())
      assert( iter->first != h );
    return iter;
  }
  
  template<typename T, typename Key, typename Hash>
  typename Tree<T,Key,Hash>::tree_hash_map::iterator 
  Tree<T,Key,Hash>::getLeftSibling_(const uint64_t& h)
  {
    typename tree_hash_map::iterator iter = internalMap.find(h);
    assert( iter != internalMap.end() );
    if (!iter->second.parent)
      return internalMap.end();
    iter = internalMap.find(*(iter->second.parent));
    assert( iter != internalMap.end() );
    assert( iter->second.firstChild );
    if (*(iter->second.firstChild) == h)
      return internalMap.end();
    iter = internalMap.find(*(iter->second.firstChild));
    assert( iter != internalMap.end() );
    while (iter->second.nextSibling && *(iter->second.nextSibling) != h) {
      iter = internalMap.find(*(iter->second.nextSibling));
      assert( iter != internalMap.end() );
    }
    if (iter != internalMap.end())
      assert( iter->first != h );
    return iter;
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::eraseRightSiblings_(const uint64_t& h)
  {
    // erase this node and all right siblings and children
    typename tree_hash_map::iterator iter = internalMap.find(h);
    if (iter == internalMap.end())
      return;
    if (iter->second.nextSibling)
      eraseRightSiblings_(*(iter->second.nextSibling));
    if (iter->second.firstChild)
      eraseChildren_(h);
    internalMap.erase(iter);
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::eraseChildren_(const uint64_t& h)
  {
    typename tree_hash_map::iterator iter = internalMap.find(h);
    if (iter == internalMap.end())
      return;
    if (iter->second.firstChild) {
      eraseRightSiblings_(*(iter->second.firstChild));
      iter->second.firstChild = boost::none;
    }
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::erase_(const uint64_t& h) {
    /*if (h == head_) {
      clear();
      return
    }*/
    typename tree_hash_map::iterator iter = internalMap.find(h);
    if (iter == internalMap.end())
      return;
    if (iter->second.firstChild)
      eraseChildren_(h);
    if (iter->second.parent) {
      typename tree_hash_map::iterator prev = getLeftSibling_(h);
      if (prev == internalMap.end()) {
        // attach next sibling as first child of parent
        prev = internalMap.find(*(iter->second.parent));
        assert( prev != internalMap.end() );
        prev->second.firstChild = iter->second.nextSibling;
      } else {
        // attach next sibling to previous sibling
        prev->second.nextSibling = iter->second.nextSibling;
      }
    }
    // erase node from map
    internalMap.erase(iter);
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::erase(const Key& key)
  {
    erase_(valueToHash_(key));
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::erase_children(const Key& key) {
    eraseChildren_(valueToHash_(key));
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
  typename Tree<T,Key,Hash>::pre_order_iterator
  Tree<T,Key,Hash>::set_head(const T& value)
  {
    clear();
    uint64_t key = valueToHash_(value);
    internalMap.insert(std::make_pair(key,treeNode(value)));
    head_ = key;
    return pre_order_iterator(*this);
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::headInitialize_()
  {
    head_ = boost::none;
    // attempt to find the head
    typename tree_hash_map::iterator iter;
    for (iter = internalMap.begin();iter != internalMap.end();iter++) {
      if (!iter->second.parent) {
        head_ = iter->first;
        break;
      }
    }
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::append_child_(const uint64_t& node, const T& child)
  {
    uint64_t childHash = valueToHash_(child);
    typename tree_hash_map::iterator iter = internalMap.find(childHash);
    assert( iter == internalMap.end() );
    iter = internalMap.find(node);
    assert( iter != internalMap.end() );
    treeNode newNode = treeNode(child);
    newNode.parent = node;
    internalMap.insert(std::make_pair(childHash,newNode));
    if (iter->second.firstChild) {
      // add as last child
      iter = internalMap.find(*(iter->second.firstChild));
      assert( iter != internalMap.end() );
      while ( iter->second.nextSibling ) {
        iter = internalMap.find(*(iter->second.nextSibling));
        assert( iter != internalMap.end() );
      }
      iter->second.nextSibling = childHash;
    } else {
      // add as only child
      iter->second.firstChild = childHash;
    }
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::append_child(const Key& node, const T& child)
  {
    append_child_(valueToHash_(node),child);
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::append_child(const Key& node, const Tree<T,Key,Hash>& otherTree, const Key& node2)
  {
    uint64_t h2 = valueToHash_(node2);
    assert( !subtree_in_tree_(otherTree,h2) );
    typename tree_hash_map::const_iterator iter = otherTree.internalMap.find(h2);
    assert( iter != otherTree.internalMap.end() );
    append_child(node,iter->second.data);
    if (iter->second.firstChild) {
      // append all children of node2
      iter = otherTree.internalMap.find(*(iter->second.firstChild));
      append_child(node2,otherTree,iter->second.data);
      assert( iter != otherTree.internalMap.end() );
      while (iter->second.nextSibling) {
        iter = otherTree.internalMap.find(*(iter->second.nextSibling));
        append_child(node2,otherTree,iter->second.data);
        assert( iter != otherTree.internalMap.end() );
      }
    }
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::insert(const Key& node, const T& node2)
  {
    uint64_t h = valueToHash_(node);
    uint64_t newHash = valueToHash_(node2);
    typename tree_hash_map::iterator iter = internalMap.find(newHash);
    assert( iter == internalMap.end() );
    iter = internalMap.find(h);
    assert( iter != internalMap.end() );
    treeNode newNode = treeNode(node2);
    newNode.parent = iter->second.parent;
    newNode.nextSibling = h;
    typename tree_hash_map::iterator prev = getLeftSibling_(h);
    if (prev == internalMap.end()) {
      // there is no left sibling, so node2 is the new left-most sibling
      iter = internalMap.find(*(iter->second.parent));
      assert( iter != internalMap.end() );
      iter->second.firstChild = newHash;
    } else {
      prev->second.nextSibling = newHash;
    }
    internalMap.insert(std::make_pair(newHash,newNode));
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::insert_after(const Key& node, const T& node2)
  {
    uint64_t h = valueToHash_(node);
    uint64_t newHash = valueToHash_(node2);
    typename tree_hash_map::iterator iter = internalMap.find(newHash);
    assert( iter == internalMap.end() );
    iter = internalMap.find(h);
    assert( iter != internalMap.end() );
    treeNode newNode = treeNode(node2);
    newNode.parent = iter->second.parent;
    newNode.nextSibling = iter->second.nextSibling;
    internalMap.insert(std::make_pair(newHash,newNode));
    iter->second.nextSibling = newHash;
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::insert_subtree(const Key& node, const Tree<T,Key,Hash>& otherTree, const Key& node2)
  {
    uint64_t h2 = valueToHash_(node2);
    assert( !subtree_in_tree_(otherTree,h2) );
    typename tree_hash_map::const_iterator iter2 = otherTree.internalMap.find(h2);
    assert( iter2 != otherTree.internalMap.end() );
    insert(node,iter2->second.data);
    if (iter2->second.firstChild) {
      // append all children of node2
      iter2 = otherTree.internalMap.find(*(iter2->second.firstChild));
      assert( iter2 != otherTree.internalMap.end() );
      append_child(node2,otherTree,iter2->second.data);
      while (iter2->second.nextSibling) {
        iter2 = otherTree.internalMap.find(*(iter2->second.nextSibling));
        assert( iter2 != otherTree.internalMap.end() );
        append_child(node2,otherTree,iter2->second.data);
      }
    }
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::insert_subtree_after(const Key& node, const Tree<T,Key,Hash>& otherTree, const Key& node2)
  {
    uint64_t h2 = valueToHash_(node2);
    assert( !subtree_in_tree_(otherTree,h2) );
    typename tree_hash_map::const_iterator iter2 = otherTree.internalMap.find(h2);
    assert( iter2 != otherTree.internalMap.end() );
    insert_after(node,iter2->second.data);
    if (iter2->second.firstChild) {
      // append all children of node2
      iter2 = otherTree.internalMap.find(*(iter2->second.firstChild));
      assert( iter2 != otherTree.internalMap.end() );
      append_child(node2,otherTree,iter2->second.data);
      while (iter2->second.nextSibling) {
        iter2 = otherTree.internalMap.find(*(iter2->second.nextSibling));
        assert( iter2 != otherTree.internalMap.end() );
        append_child(node2,otherTree,iter2->second.data);
      }
    }
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::replace(const Key& node, const T& node2)
  {
    uint64_t h = valueToHash_(node);
    uint64_t newHash = valueToHash_(node2);
    typename tree_hash_map::iterator iter = internalMap.find(newHash);
    assert( iter == internalMap.end() );
    iter = internalMap.find(h);
    assert( iter != internalMap.end() );
    treeNode newNode = treeNode(node2);
    newNode.parent = iter->second.parent;
    newNode.nextSibling = iter->second.nextSibling;
    newNode.firstChild = iter->second.firstChild;
    typename tree_hash_map::iterator prev = getLeftSibling_(h);
    if (prev == internalMap.end()) {
      // there is no left sibling, so node2 is the new left-most sibling
      iter = internalMap.find(*(iter->second.parent));
      assert( iter != internalMap.end() );
      iter->second.firstChild = newHash;
    } else {
      prev->second.nextSibling = newHash;
    }
    internalMap.erase(iter);
    internalMap.insert(std::make_pair(newHash,newNode));
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::replace(const Key& node, const Tree<T,Key,Hash>& otherTree, const Key& node2)
  {
    uint64_t h2 = valueToHash_(node2);
    assert( !subtree_in_tree_(otherTree,h2) );
    typename tree_hash_map::const_iterator iter2 = otherTree.internalMap.find(h2);
    assert( iter2 != otherTree.internalMap.end() );
    erase_children(node);
    replace(node,iter2->second.data);
    if (iter2->second.firstChild) {
      // append all children of node2
      iter2 = otherTree.internalMap.find(*(iter2->second.firstChild));
      assert( iter2 != otherTree.internalMap.end() );
      append_child(node2,otherTree,iter2->second.data);
      while (iter2->second.nextSibling) {
        iter2 = otherTree.internalMap.find(*(iter2->second.nextSibling));
        assert( iter2 != otherTree.internalMap.end() );
        append_child(node2,otherTree,iter2->second.data);
      }
    }
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::flatten(const Key& node)
  {
    uint64_t h = valueToHash_(node);
    typename tree_hash_map::iterator iter = internalMap.find(h);
    assert( iter != internalMap.end() );
    if (iter->second.firstChild) {
      // move children to siblings
      typename tree_hash_map::iterator iter2 = internalMap.find(*(iter->second.firstChild));
      assert( iter2 != internalMap.end() );
      iter2->second.parent = iter->second.parent;
      while (iter2->second.nextSibling) {
        iter2 = internalMap.find(*(iter2->second.nextSibling));
        assert( iter2 != internalMap.end() );
        iter2->second.parent = iter->second.parent;
      }
      iter2->second.nextSibling = iter->second.nextSibling;
      iter->second.nextSibling = iter->second.firstChild;
      iter->second.firstChild = boost::none;
    }
  }
  
  template<typename T, typename Key, typename Hash>
  void
  Tree<T,Key,Hash>::reparent(const Key& node, const Key& from)
  {
    uint64_t h = valueToHash_(node);
    typename tree_hash_map::iterator iter = internalMap.find(h);
    assert( iter != internalMap.end() );
    uint64_t h2 = valueToHash_(from);
    typename tree_hash_map::iterator iter2 = internalMap.find(h2);
    assert( iter2 != internalMap.end() );
    if (iter2->second.firstChild) {
      // move firstChild
      if (iter->second.firstChild) {
        iter = internalMap.find(*(iter->second.firstChild));
        assert( iter != internalMap.end() );
        while (iter->second.nextSibling) {
          iter = internalMap.find(*(iter->second.nextSibling));
          assert( iter != internalMap.end() );
        }
        iter->second.nextSibling = iter2->second.firstChild;
        
      } else {
        iter->second.firstChild = iter2->second.firstChild;
      }
      // set parents of all children
      typename tree_hash_map::iterator iter3 = internalMap.find(*(iter2->second.firstChild));
      assert( iter3 != internalMap.end() );
      iter3->second.parent = h;
      while (iter3->second.nextSibling) {
        iter3 = internalMap.find(*(iter3->second.nextSibling));
        assert( iter3 != internalMap.end() );
        iter3->second.parent = h;
      }
      iter2->second.firstChild = boost::none;
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
    uint64_t h = valueToHash_(node);
    typename tree_hash_map::const_iterator iter = internalMap.find(h);
    assert( iter != internalMap.end() );
    size_type d(0);
    while (iter->second.parent) {
      d++;
      iter = internalMap.find(*(iter->second.parent));
      assert( iter != internalMap.end() );
    }
    return d;
  }
  
  template<typename T, typename Key, typename Hash>
  typename Tree<T,Key,Hash>::size_type
  Tree<T,Key,Hash>::number_of_children(const Key& node) const
  {
    uint64_t h = valueToHash_(node);
    typename tree_hash_map::const_iterator iter = internalMap.find(h);
    assert( iter != internalMap.end() );
    size_type d(0);
    if (!iter->second.firstChild)
      return d;
    d++;
    iter = internalMap.find(*(iter->second.firstChild));
    assert( iter != internalMap.end() );
    while (iter->second.nextSibling) {
      d++;
      iter = internalMap.find(*(iter->second.nextSibling));
      assert( iter != internalMap.end() );
    }
    return d;
  }
  
  template<typename T, typename Key, typename Hash>
  typename Tree<T,Key,Hash>::size_type
  Tree<T,Key,Hash>::number_of_siblings(const Key& node) const
  {
    typename tree_hash_map::const_iterator iter = internalMap.find(valueToHash_(node));
    assert( iter != internalMap.end() );
    if (!iter->second.parent) {
      return 0;
    } else {
      iter = internalMap.find(*(iter->second.parent));
      assert( iter != internalMap.end() );
      return number_of_children(iter->second.data)-1;
    }
  }
  
  template<typename T, typename Key, typename Hash>
  bool
  Tree<T,Key,Hash>::is_in_subtree(const Key& haystack, const Key& needle) const
  {
    if (needle == haystack) {
      return true;
    }
    typename tree_hash_map::const_iterator iter = internalMap.find(valueToHash_(haystack));
    assert( iter != internalMap.end() );
    if (iter->second.firstChild) {
      iter = internalMap.find(*(iter->second.firstChild));
      assert( iter != internalMap.end() );
      if (is_in_subtree(iter->second.data,needle))
        return true;
      while (iter->second.nextSibling) {
        iter = internalMap.find(*(iter->second.nextSibling));
        assert( iter != internalMap.end() );
        if (is_in_subtree(iter->second.data,needle))
          return true;
      }
    }
    return false;
  }
  
  template<typename T, typename Key, typename Hash>
  bool
  Tree<T,Key,Hash>::subtree_in_tree_(const Tree<T,Key,Hash>& other, const uint64_t& node) const
  {
    typename tree_hash_map::const_iterator iter = internalMap.find(node);
    if (iter != internalMap.end())
      return true;
    iter = other.internalMap.find(node);
    if (iter == other.internalMap.end())
      return false;
    bool ret = false;
    if (iter->second.firstChild) {
      ret |= subtree_in_tree_(other,*(iter->second.firstChild));
      iter = other.internalMap.find(*(iter->second.firstChild));
      while (!ret and iter->second.nextSibling) {
        ret |= subtree_in_tree_(other,*(iter->second.nextSibling));
        iter = other.internalMap.find(*(iter->second.nextSibling));
      }
    }
    return ret;
  }
  
  template<typename T, typename Key, typename Hash>
  bool
  Tree<T,Key,Hash>::subtree_in_tree(const Tree<T,Key,Hash>& other, const Key& node) const
  {
    return subtree_in_tree_(other,valueToHash_(node));
  }
  
  
  
  
  template<typename T, typename Key, typename Hash>
  template<class Archive>
  void
  Tree<T,Key,Hash>::load(Archive & ar, unsigned version)
  {
    if (version == 0) {
      // load old-style Tree
      // TODO: implement this
      assert( false );
    } else {
      // load new Tree
      ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
      ar & make_nvp("map", internalMap);
      headInitialize_();
    }
  }
  
  template<typename T, typename Key, typename Hash>
  template<class Archive>
  void
  Tree<T,Key,Hash>::save(Archive & ar, unsigned version) const
  {
    ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
    ar & make_nvp("map", internalMap);
  }

};


