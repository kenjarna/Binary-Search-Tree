//  binary_tree.h
//  Header file for CS 223, Lab 10: Binary Search Tree Class
//
//  Barb Wahl & Theresa Wilson, 4-5-2017
//
//  In Lab 10, node objects are linked together to create a binary search tree.
//
//  The class binary_tree encapsulates the workings of the tree into a single
//  object, instead of just providing "toolkit" functions as in Main & Savitch
//  Ch. 10.
//
//  The only instance variable for binary_tree is a pointer to the root
//  node, `root_ptr`.
//
//    - An empty tree is represented by making root_ptr point to a node of
//      type empty_node.
//
//    - A non-empty tree is represented by making root_ptr point to a node
//      of type normal_node, the root of the desired tree.
//
//  The tree is maintained as a binary search tree, which imposes a logic on
//  the `insert` and `contains` operations.  For a node storing data value K,
//  all the data for nodes in the left subtree are _less_ than K, and all
//  the data for nodes in its right subtree are _greater_ than K.
//
//  Because of the recursive structure of the tree, the tree functions are
//  implemented recursively.  A public "wrapper" simply sends the request 
//  on to the root node, and conveys the result (if any) back to the caller.
//  So, all of these methods (except for the constructors and destructor, 
//  of course) are implemented in three forms:
//    - as tree functions (simple wrapper)
//    - as functions on normal nodes
//    - as functions on empty nodes
//
//  Note:  This is an example of the concept of "polymorphism" (literally,
//   "many forms") in object-oriented design.
//
//  For Part 1 -- Basic Functionality for a Binary Search Tree Storing Integer
//  Data:
//
//     binary_tree()
//        Postcondition: The tree is initialized as an empty tree (root points
//          to an empty node).
//
//     void insert(int k)
//        Postcondition: Data value `k` has been inserted into the tree and the
//          size (number of data values in the tree) has increased by 1; but,
//          if an equivalent value was already in the tree, then the tree is
//          unchanged.
//
//        Implementation note: pass the request to the root node and assign the
//          return value to the root pointer
//
//     bool contains(int k)
//        Postcondition: Return value is true iff the value `k` is in the tree.
//        Implementation note: return the result of passing the request to the
//          root node
//
//     bool isEmpty()
//        Postcondition: Return value is true iff the tree has no stored values
//        Implementation note: return the result of passing the request to the
//          root node
//
//     string inorder()
//        Postcondition: Return value is a string for printing the values of the
//          tree according to an in-order traversal, with a single space, " ",
//          inserted after each value.  If the tree is empty, the return value
//          will be the string, "[empty]".
//
//  For Part 2 -- Additional Functionality for a Binary Search Tree Storing
//  Integer Data:
//
//     binary_tree(std::vector<int> the_vector)
//        Postcondition: The tree holds the data values provided by the_vector
//        Implementation note: The data values are inserted one at a time,
//          iterating through the_vector in the usual order:  0, 1, 2, ...
//
//     ~binary_tree()
//        destructor
//
//     string preorder()
//        Postcondition: Return value is a string for printing the values of the
//          tree according to a pre-order traversal, with a single space, " ",
//          inserted after each value.  If the binary_tree is empty, the return
//          value will be the string, "[empty]".
//
//     int size()
//        Postcondition: Return value is the number of data values stored in
//          the tree.
//        Implementation note: Return the result of passing the request to the
//          root node.
//
//     int height()
//        Postcondition: Return value is the height (aka depth) of the tree.
//        Implementation note: Return the result of passing the request to the
//          root node.
//
//     void clear()
//        Postcondition: The tree is empty.
//
//  Value Semantics for binary_tree Class:
//     The copy constructor and assignment operator are disabled.
//

/* DO NOT CHANGE THIS FILE! */

#ifndef binary_tree_H
#define binary_tree_H

#include <vector>
#include "node.h"    // provides node, empty_node, normal_node

class binary_tree
{
 public:
    // MEMBER FUNCTIONS

    // Functionality for Part 1
    binary_tree();
    void insert(int k);
    bool contains(int k) const;
    bool isEmpty() const;
    std::string inorder() const;

    // Functionality for Part 2
    explicit binary_tree(std::vector<int> the_vector);
    ~binary_tree();
    std::string preorder() const;
    int size() const;
    int height() const;
    void clear();

 private:
    // INSTANCE VARIABLES
    node * root_ptr;

    // Disable the copy constructor and assignment operator by declaring them
    // private.

    // Note the repercussions:  This means a binary_tree cannot be sent as a
    // value parameter and cannot be returned as a value.  Both of these
    // operations would trigger the copy constructor or assignment operator.

    // *** Do not implement! ***
    binary_tree(const binary_tree &other);
    binary_tree operator=(const binary_tree &other);
};

#endif /* binary_tree_H */
