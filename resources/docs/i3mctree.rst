--------
I3MCTree
--------

The I3MCTree is an STL-like n-ary tree of I3Particles. There is also
a mapping of I3ParticleID -> I3Particle for fast lookups.

Users Guide
===========

C++
---

Everything is const-correct, so be sure to follow the rules.
If something isn't compiling, this may be why.

Iterators
^^^^^^^^^

.. _pre_order_iterator:

  **pre_order_iterator (default)**
  
    Iterates through a tree in pre-order.
    
    .. only:: html
      
      .. raw:: html
          
        <a href="http://en.wikipedia.org/wiki/Tree_traversal#Pre-order" title="Pre-order">
          <img src="http://upload.wikimedia.org/wikipedia/commons/d/d4/Sorted_binary_tree_preorder.svg" alt="Pre-order traversal image" />
        </a>

    #. Visit the root
    #. Traverse the left subtree
    #. Traverse the right subtree

.. _post_order_iterator:

  **post_order_iterator**

    Iterates through a tree in post-order.
    
    .. only:: html
      
      .. raw:: html
          
        <a href="http://en.wikipedia.org/wiki/Tree_traversal#Post-order" title="Post-order">
          <img src="http://upload.wikimedia.org/wikipedia/commons/9/9d/Sorted_binary_tree_postorder.svg" alt="Post-order traversal image" />
        </a>

    #. Traverse the left subtree
    #. Visit the root
    #. Traverse the right subtree

.. _sibling_iterator:

  **sibling_iterator**

    Iterates through all siblings to the right of the given node.

.. _fast_iterator:

  **fast_iterator**

    No guarantees on order of node. Uses underlying datastructures to
    give fastest iterator possible.

.. _leaf_iterator:

  **leaf_iterator**

    Uses a fast_iterator, but only stops at leaf nodes.

Functions
^^^^^^^^^

  Functions that are built-in to the tree. Most functions support
  either I3ParticleID / I3Particle or Iterator arguments.

  **Navigating the Tree**

  * get_head()
  * get_heads()
  * at(ID)
  * parent(ID)
  * previous_sibling(ID)
  * next_sibling(ID)
  * number_of_siblings(ID)
  * first_child(ID)
  * children(ID)
  * number_of_children(ID)
  * depth(ID)

  **Adding to the Tree**

  * insert(Particle)
  * insert_after(Particle)
  * insert(ID, Particle)
  * insert_after(ID, Particle)
  * insert_subtree(ID, Tree, ID)
  * insert_subtree_after(ID, Tree, ID)
  * append_child(ID, Particle)
  * append_child(ID, Tree, ID)
  * append_children(ID, Vector)

  **Modifying the Tree**

  * clear()
  * erase(ID)
  * erase_children(ID)
  * flatten(ID)
  * reparent(ID, ID)
  * replace(ID, Particle)
  * replace(ID, Tree, ID)
  * merge(Tree)

  **General Tree Actions**

  * size()
  * empty()
  * is_in_subtree(ID, ID)
  * subtree_in_tree(Tree, ID)


I3MCTreeUtils
^^^^^^^^^^^^^

  Functions that do not need to know about tree internals to work.

  **General Functions**
  
  * AddPrimary(Tree, Particle)
  * GetPrimary(Tree, ID)
  * GetPrimaries(Tree)
  * GetParticle(Tree, ID)
  * GetParent(Tree, ID)
  * HasParent(Tree, ID)
  * GetDaughters(Tree, ID)
  * AppendChild(Tree, ID, Particle)
  * Dump(Tree)
  * Get(Frame, Key)

  **Filtering / Selection Functions**
  
    Use either a function from the Physics Library or your own.
  
  * GetBest(Tree, Function)
    
    Returns the single particle that best matches a comparison function.
    Function is a callable which takes two I3Particles, compares them,
    and returns true/false (true = first is less than second).
    
  * GetFilter(Tree, Function)
    
    Returns all partiles that pass the filtering function.
    Function is a callable which takes an I3Particle and returns true/false.
    
  * GetBestFilter(Tree, FilterFunction, CmpFunction)
    
    Returns the single particle that best matches a comparison function
    and also passes a filtering function.
    FilterFunction is a callable which takes an I3Particle and returns
    true/false.
    CmpFunction is a callable which takes two I3Particles, compares them,
    and returns true/false (true = first is less than second).

For more C++ details, see the 
`doxygen docs <../../doxygen/dataclasses/classTreeBase_1_1Tree.html>`_.


Python
------

All C++ functions (both built-in to the tree and in I3MCTreeUtils)
are available in python.

Iterators are simulated through python generators.

Several special functions are included:

* __str__

  Dump the tree to a string::
  
    print tree

* __nonzero__

  Test for empty tree::
  
    if tree:
      print 'the tree is not empty'
    else:
      print 'empty tree'

* __eq__

  Test for equality::
  
    if tree1 == tree2:
      print 'the trees are equal'

* __len__

  Number of particles in the tree::
  
    print 'tree has',len(tree),'particles'

* __contains__

  Does the tree contain an I3ParticleID? ::
  
    if particle in tree:
      print 'found particle'
    else:
      print 'particle not in tree'

* __getitem__

  Get a particle from the tree::
  
    particle = tree[particleID]

* __delitem__

  Erase a particle (and all children) from the tree. Calls the erase() method::
  
    del tree[particleID]

* __iter__

  Gives you the default iterator (pre_order_iterator)::
  
    for particle in tree:
      print particle

For more details, see :ref:`mctree-python-bindings`.


Tree Internals
==============

N-ary Tree
----------

The n-ary tree is formed by making a binary tree representation.

N-ary Tree:

.. only:: html

  .. raw:: html

    <div style="white-space: pre;font-family: 'Consolas', 'Deja Vu Sans Mono',
                'Bitstream Vera Sans Mono', monospace;margin:-1em 0 2em">
              P
           ---^---
          P       P
         / \      /\
        P   P    P  P
       /\   |   /\   \
      P  P  P  P  P   P
    </div>

.. only:: not html

  |         P
  |      ---^---
  |     P       P
  |    / \      /\
  |   P   P    P  P
  |  /\   |   /\   \
  | P  P  P  P  P   P

Binary Representation:

.. only:: html

  .. raw:: html

    <div style="white-space: pre;font-family: 'Consolas', 'Deja Vu Sans Mono',
                'Bitstream Vera Sans Mono', monospace;margin:-1em 0 2em">
              P
            /
          P-------P
         /       /
        P---P    P--P
       /    |   /    \
      P--P  P  P--P   P
    </div>

.. only:: not html

  |         P
  |       /
  |     P-------P
  |    /       /
  |   P---P    P--P
  |  /    |   /    \
  | P--P  P  P--P   P

Storage of I3Particles
----------------------

Each particle is stored in a node which has the following structure:

* parent node pointer
* next sibling node pointer
* first child node pointer
* I3Particle

This allows a compact storage of the binary tree representation above.

Nodes are themselves stored in a hash_map with the hash being the
I3ParticleID of each I3Particle. This allows constant time access
to each I3Particle in the tree. One major constraint is that the I3ParticleID
must be unique, so inserting a second particle with the same ID does not work
(you'll just write over the first copy).

Iterator Invalidation
^^^^^^^^^^^^^^^^^^^^^

The implementation of hash_map only stores pointers to each node, so changing
the shape of the hash_map does not invalidate those pointers, leaving all
references to nodes as valid (though note that the child/sibling/parent
node pointer is not valid if that node is deleted). Moreover, inserting an
element in the hash_map invalidates no hash_map iterators, and removing an
element invalidates only those iterators which point at the removed element.

Thus, operations which add nodes to the tree structure do not invalidate
any iterators. Operators which modify or remove nodes from the tree structure
invalidate all fast_iterator_ and leaf_iterator_, but only invalidate
pre_order_iterator_, post_order_iterator_ and sibling_iterator_ where
the iterator is a child/sibling/parent of the modified or removed nodes.

Iterator Internals
------------------

Iterators use boost::iterator_facade to generate most of the STL syntax
for the iterators. This makes things simpler, but there is still some
complexity.

There are two general types of iterators, with several implementations
of each:

* Tree Iterators

  * pre_order_iterator (default)
  * post_order_iterator
  * sibling_iterator

* hash_map Iterators

  * fast_iterator
  * leaf_iterator

Additionally, each iterator can be constant as well. To present a unified
iterator class to functions, iterator traits were used.

When modifying the tree, iterators are not invalidated unless that node or
a neighboring node is deleted, or the tree structure changes around the node.

Iterator Traits
^^^^^^^^^^^^^^^

Using partial template specialization we can define two different trait
types: 

Const Traits
""""""""""""

  This controls the const-ness of the iterator.

Storage Traits
""""""""""""""

  This contains the actual storage type underlying the iterator. It is a
  node pointer to the current node, and either the I3ParticleID to the
  current node or the hash_map iterator to the current node.

Static Binding of Derived Methods
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Derived iterators use a static cast to the derived type to call derived
methods. This allows compile-type binding and verification instead of
runtime binding of derived methods, which is mainly of benefit to detect
errors sooner.

The secret code::

  *static_cast<Derived*>(this)

This requires the parent class template to contain the Derived type, but
this was required by boost::iterator_facade anyway.

Compilers
---------

Or, why this doesn't compile with older versions of GCC.

The main reason is `bug 14032 <http://gcc.gnu.org/bugzilla/show_bug.cgi?id=14032>`_.
This has to do with template specialization within a templated class (basing
the inner template off of the outer template). It's important to the Tree
class, and difficult to make everything work without it.

So, GCC 4.3+ is supported. No support for anything lower. Clang is also good.

.. _mctree-python-bindings:

Python Bindings
===============

.. autoclass:: icecube.dataclasses.I3MCTree
    :members:



