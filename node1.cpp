//  node1.cpp
//  Function implementations for CS 223, Lab 10 Part 1 -- node classes
//
//  Student Name: Kenny Jarnagin
//  Date: 4-10-17
//
// This file contains the implementations for all the member functions of
// normal_node and empty_node that are not already implemented in node.h.
//
// CLASS INVARIANT
//    The instance variables `left` and `right` (for a normal node) are never
//    set to NULL. To indicate the lack of a left child or right child, make
//    the pointer point to an empty_node.
//
// Implementation note:
//    The motivation for creating an "empty" node class is to allow for elegant
//    recursive implementations for many of the tree functions (size, height,
//    insert, contains, etc.).  In general, the recursive node functions will
//    *not* use expressions such as "if (this is a leaf node)" or "if (the left
//    subtree is empty)" -- the recursion will automatically hit its base level
//    when it encounters an instance of the empty_node class.
//
//    To summarize the above:  The function implementations for empty_node
//    provide the base cases for the recursion.  DO NOT attempt to short-circuit
//    the recursion and prevent the function from being called on an empty node.
//    This would undermine the entire design.

#include <iostream>
#include <cassert>
#include <sstream>  // for accumulating strings
#include <string>
#include "node.h"   // provides node, empty_node, normal_node

using namespace std;


// ########### empty_node implementations ###########

// Part One:

    // insert
    //   When called on an empty_node, insert puts the given value into
    //   a new normal_node and returns a pointer to the new node.
    node * empty_node::insert(int k)
    {	 	  	 	    	 	 	   	       	 	
    	return new normal_node(k);
    }

    // contains
    //   In an empty tree, contains will always return false.
    bool empty_node::contains(int k) const
    {
    	return false;
    }

    // isLeaf
    //   In an empty tree, isLeaf will always return false.
    bool empty_node::isLeaf() const
    {
    	return false;
    }

    // isEmpty
    //   In an empty tree, isEmpty will always return true.
    bool empty_node::isEmpty() const
    {
    	return true;
    }


// Part Two:
    // size
    //   What is the size of an empty tree?
    int empty_node::size() const
    {
        return 0;
    }

    // height
    //   What is the height of an empty tree? Hint: it's not zero...
    int empty_node::height() const
    {	 	  	 	    	 	 	   	       	 	
        return -1;
    }

    // clear
    //   There is nothing to change in order to `clear` this empty node.
    void empty_node::clear()
    {
        return;
    }


// ########### normal_node implementations ###########

// Part One:
    // normal_node node constructor
    //   Makes a leaf node.
    //   Postcondition: The new node is a normal node with data equal to `k`
    //    and two empty child nodes.
    normal_node::normal_node(int k)
    {
    	data = k;
    	left = new empty_node;
    	right = new empty_node;
    }

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
    node * normal_node::insert(int k)
    {	 	  	 	    	 	 	   	       	 	
    	if (k < data)
    	{
    		//recursive call to insert on the left (if alphabetically less than)
            node * tempL = left;
    		left = left -> insert(k);
            if (getLeft() -> isEmpty())
            {
                delete tempL;
            }
    	}
    	if (k > data)
    	{
    		//recurisve call to insert on the right (if alphabetically less than)
            node * tempR = right;
    		right = right -> insert(k);
            if (getRight() -> isEmpty())
            {
                delete tempR;
            }
    	}
    	return this;

    }

    // contains in a normal node
    //   Postcondition: returns true iff this node, or one of its subtrees,
    //     contains the value `k`.
    //
    //   Implementation note:  Similar logic to `insert(k)`.
    bool normal_node::contains(int k) const
    {
    	if (data == k)
    	{
    		return true;
    	}
    	if (k < data)
    	{
    		return left -> contains(k);
    	}	 	  	 	    	 	 	   	       	 	
    	if (k > data)
    	{

    		return right -> contains(k);
    	}
    }

    // isLeaf
    //   Return value is true iff both subtrees of this node are empty.
    bool normal_node::isLeaf() const
    {
    	if (getLeft() -> isEmpty() && getRight() -> isEmpty())
    	{
    		return true;
    	}
    	return false;
    }

    // isEmpty
    //   Hint: Is a normal node empty?
    bool normal_node::isEmpty() const
    {
    	return false; //a normal node is never empty
    }

    // accessor methods
    int normal_node::getData() const
    {
    	return data;
    }

    node * normal_node::getLeft() const
    {
    	return left;
    }

    node * normal_node::getRight() const
    {	 	  	 	    	 	 	   	       	 	
    	return right;
    }


// inorder for normal node
// prints the values in the tree whose root is the current node, using an
// inorder traversal (left, root, right) and separating the values by a
// single space
//
// implementation provided
string normal_node::inorder() const
{
    stringstream acc;

    acc << (left -> inorder());
    acc << (this -> data) << " ";
    acc << (right -> inorder());

    return acc.str();
}

// Part Two:

    // destructor
    normal_node::~normal_node()
    {
        if (!isLeaf())
        {
            this -> clear();
        }
        delete left;
        delete right;
        left = NULL;
        right = NULL;
    }

    // preorder for normal node
    //   Prints the values in the tree whose root is the current node, using a
    //     preorder traversal (root, left, right) and separating the values by
    //     a single space.
    std::string normal_node::preorder() const
    {
        stringstream acc;

        acc << (this -> data) << " ";
        acc << (left -> preorder());
        acc << (right -> preorder());

        return acc.str();
    }	 	  	 	    	 	 	   	       	 	

    // size
    //   Return value is the number of values stored in the tree whose root is
    //     the current node.
    //   Implementation note:  Use recursive divide-and-conquer.
    int normal_node::size() const
    {
        return left -> size() + right -> size() + 1; //counts left, right and the node
    }

    // height
    //   Return value is the height of the tree whose root is the current node.
    //   Implementation note:  Use recursive divide-and-conquer.
    int normal_node::height() const
    {
        //max is a standard library function used to compare two given parameters
        return max(left -> height(), right -> height()) + 1;
    }

    // clear
    //   Deletes all the descendants of this node.
    //   Postcondition: This node is a leaf.
    //   Implementation note:  Use recursive divide-and-conquer.
    void normal_node::clear()
    {
        if (!left -> isEmpty())
        {
           left -> clear();
           delete left;
           left = new empty_node;          
        }
        if (!right -> isEmpty())
        {
           right -> clear();
           delete right;
           right = new empty_node;  
        }
    }
	 	  	 	    	 	 	   	       	 	
