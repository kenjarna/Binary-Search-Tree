//  node.h
//  Header file for a binary search tree node class for storing integer values
//  CS 223 Lab 10
//
//  Barb Wahl & Theresa Wilson, 4-5-2017
//
//  In Lab 10, node objects are linked together to create a binary search tree.
//
//  Implementation Note:
//
//     There are two kinds of node, a "normal" node that holds an int value
//     and has pointers to left and right subtrees, and an "empty" node that
//     can be pointed to by a normal node's left or right pointers to indicate
//     an empty subtree.  (An empty node is also useful for implementing an
//     empty tree -- use an empty root node.)
//
//     The node classes are implemented in C++ by creating an abstract
//     superclass `node` and concrete subclasses `normal_node` and `empty_node`.
//
//     A virtual function in the superclass that provides an implementation is
//     *allowed* (not required) to be re-implemented in subclasses.  A virtual
//     function in the superclass that is declared as "= 0" in the superclass
//     is a purely virtual function and is *required* to be implemented in each
//     subclass.

/* DO NOT CHANGE THIS FILE! */

//  ############################ node (superclass) ############################

#ifndef LAB10_NODE_H
#define LAB10_NODE_H

class node
{
 public:
    // Default constructor with empty implementation -- must be provided
    // since the copy constructor has been declared private.
    node(){ /* empty implementation */ }

    // ******** PART 1 ********

    // These must be implemented in both subclasses (normal_node, empty_node).
    virtual node * insert(int k) = 0;
    virtual bool contains(int k) const = 0;
    virtual bool isLeaf() const = 0;
    virtual bool isEmpty() const = 0;
    virtual std::string inorder() const = 0;

    // Implement these for normal_node ONLY, not for empty_node.
    virtual int getData() const { return -99999; }
    virtual node * getLeft() const { return NULL; }
    virtual node * getRight() const { return NULL; }

    // ******** PART 2 ********

    // These must be implemented in both subclasses (normal_node, empty_node).
    virtual std::string preorder() const = 0;
    virtual int size() const = 0;
    virtual int height() const = 0;
    virtual void clear() = 0;

    // Implement the destructor for normal_node ONLY.
    virtual ~node(){ /* empty implementation */ }

 private:
    // Disable the superclass copy constructor by making it private.

    // *** Do not implement! ***
    node(const node& other);
};

//  #################### empty_node (subclass of node) ####################
//
//  An empty_node stores no item and has no child nodes.
//
//  empty_node inherits the public members of node and needs to provide
//  appropriate implementations for virtual functions in node.cpp.

class empty_node : public node
{
 public:
    // Default empty_node constructor with empty implementation provided.
    // (Nothing for students to implement.)
    empty_node() { }

    // ***** For Part 1 *****

    // insert
    //   When called on an empty_node, insert puts the given value into
    //   a new normal_node and returns a pointer to the new node.
    virtual node * insert(int k);

    // contains
    //   In an empty tree, contains will always return false.
    virtual bool contains(int k) const;

    // isLeaf
    //   In an empty tree, isLeaf will always return false.
    virtual bool isLeaf() const;

    // isEmpty
    //   In an empty tree, isEmpty will always return true.
    virtual bool isEmpty() const;

    // inorder
    //   When making a traversal of the tree, empty nodes should not
    //   be reported. (Nothing for students to implement.)
    virtual std::string inorder() const { return ""; }

    //***** For Part 2 *****

    // preorder
    //   When making a traversal of the tree, empty nodes should not
    //   be reported. (Nothing for students to implement.)
    virtual std::string preorder() const { return ""; }

    // size
    //   What is the size of an empty tree?
    virtual int size() const;

    // height
    //   What is the height of an empty tree? Hint: it's not zero...
    virtual int height() const;

    // clear
    //   There is nothing to change in order to `clear` this empty node.
    virtual void clear();
};

//  #################### normal_node (subclass of node) ####################
//
//  A normal_node stores an int value and has pointers to its left and right
//  child nodes.  normal_node inherits the public members of node and needs to
//  provide appropriate implementations for virtual node functions in node.cpp.

class normal_node : public node
{
 public:
    // ***** For Part 1 *****

    // normal_node node constructor
    //   Makes a leaf node.
    //   Postcondition: The new node is a normal node with data equal to `k`
    //    and two empty child nodes.
    explicit normal_node(int k);

    // insert in a normal_node
    //   Postcondition: Returns a pointer to this node.
    //
    //   Implementation note:
    //     - If this node is holding the value `k`, insert does nothing but
    //       return the `this` pointer.
    //     - Otherwise, depending on how the value `k` compares with the data
    //       in this node, insert makes a recursive call to insert `k` on either
    //       the left- or right-subtree of this node (and returns the `this`
    //       pointer).
    virtual node * insert(int k);

    // contains in a normal node
    //   Postcondition: returns true iff this node, or one of its subtrees,
    //     contains the value `k`.
    //
    //   Implementation note:  Similar logic to `insert(k)`.
    virtual bool contains(int k) const;

    // isLeaf
    //   Return value is true iff both subtrees of this node are empty.
    virtual bool isLeaf() const;

    // isEmpty
    //   Hint: Is a normal node empty?
    virtual bool isEmpty() const;

    // accessor methods
    virtual int getData() const;
    virtual node * getLeft() const;
    virtual node * getRight() const;

    // inorder for normal node
    //   Prints the values in the tree whose root is the current node, using an
    //     inorder traversal (left, root, right) and separating the values by a
    //     single space.
    virtual std::string inorder() const;

    //***** For Part 2 *****

    // destructor
    virtual ~normal_node();

    // preorder for normal node
    //   Prints the values in the tree whose root is the current node, using a
    //     preorder traversal (root, left, right) and separating the values by
    //     a single space.
    virtual std::string preorder() const;

    // size
    //   Return value is the number of values stored in the tree whose root is
    //     the current node.
    //   Implementation note:  Use recursive divide-and-conquer.
    virtual int size() const;

    // height
    //   Return value is the height of the tree whose root is the current node.
    //   Implementation note:  Use recursive divide-and-conquer.
    virtual int height() const;

    // clear
    //   Deletes all the descendants of this node.
    //   Postcondition: This node is a leaf.
    //   Implementation note:  Use recursive divide-and-conquer.
    virtual void clear();

 private:
    // INSTANCE VARIABLES
    int data;
    node * left;
    node * right;
};

#endif  /* LAB10_NODE_H */
