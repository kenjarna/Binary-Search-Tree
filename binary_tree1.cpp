//  binary_tree1.cpp
//  Function implementations for CS 223, Lab 10 Part 1: Binary Tree Class
//
//  Student Name: Kenneth Jarnagin
//  Date: 4-10-17
//
//  In Lab 10, node objects are linked together to create a binary search tree.
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
//  CLASS INVARIANTS:
//     1. The tree is maintained as a binary search tree.  At all times, the
//        tree nodes will satisfy the BST order property.
//     2. When a new value is inserted into the tree, it always goes into a
//        new leaf node.
//     3. The tree does not store duplicate values; at all times, there are
//        no two nodes in the tree holding equivalent data.
//     4. The root pointer is held in static memory and the nodes themselves
//        are kept in dynamic memory.
//     5. When a node is no longer in use, the memory for that node is
//        deallocated to avoid memory leaks.

#include <cassert>
#include <iostream>
#include <string>
#include "binary_tree.h"

using namespace std;

//		PART 1 IMPLEMENTATION

//     binary_tree()
//        Postcondition: The tree is initialized as an empty tree (root points
//          to an empty node).

	binary_tree::binary_tree()
	{	 	  	 	    	 	 	   	       	 	
		root_ptr = new empty_node;
	}

//     void insert(int k)
//        Postcondition: Data value `k` has been inserted into the tree and the
//          size (number of data values in the tree) has increased by 1; but,
//          if an equivalent value was already in the tree, then the tree is
//          unchanged.
	void binary_tree::insert(int k)
	{
		if (isEmpty())
		{
			root_ptr = root_ptr -> insert(k);
			return;
		}
		root_ptr -> insert(k);
	}

//        Implementation note: pass the request to the root node and assign the
//          return value to the root pointer
//
//     bool contains(int k)
//        Postcondition: Return value is true iff the value `k` is in the tree.
//        Implementation note: return the result of passing the request to the
//          root node
	bool binary_tree::contains(int k) const
	{
		return root_ptr -> contains(k);
	}

//     bool isEmpty()
//        Postcondition: Return value is true iff the tree has no stored values
//        Implementation note: return the result of passing the request to the
//          root node
	bool binary_tree::isEmpty() const
	{	 	  	 	    	 	 	   	       	 	
		return root_ptr -> isEmpty();
	}

//     string inorder()
//        Postcondition: Return value is a string for printing the values of the
//          tree according to an in-order traversal, with a single space, " ",
//          inserted after each value.  If the tree is empty, the return value
//          will be the string, "[empty]".
	std::string binary_tree::inorder() const
	{
		string str;
		if (this -> isEmpty())
		{
			str = "[empty]";
			return str;
		}
		str += root_ptr -> inorder();
		return str;
	}


//######################  PART 2 ######################
//  For Part 2 -- Additional Functionality for a Binary Search Tree Storing
//  Integer Data:
//
//     binary_tree(std::vector<int> the_vector)
//        Postcondition: The tree holds the data values provided by the_vector
//        Implementation note: The data values are inserted one at a time,
//          iterating through the_vector in the usual order:  0, 1, 2, ...

	binary_tree::binary_tree(std::vector<int> the_vector)
    {
    	root_ptr = new empty_node;
    	for (int i = 0; i < the_vector.size(); i++)
    	{
    		// insert vector items into a tree
    		this -> insert(vector.at(i)); 
    	}
    }
//
//     ~binary_tree()
//        destructor
    binary_tree::~binary_tree()
    {	 	  	 	    	 	 	   	       	 	
    	root_ptr -> clear();
    	node * tempL = left;
    	delete tempL;
    	node * tempR = right;
    	delete tempR;

    	left = NULL;
    	right = NULL;

    	tempL = NULL;
    	tempR = NULL;
    	root_ptr = NULL;
    }
//
//     string preorder()
//        Postcondition: Return value is a string for printing the values of the
//          tree according to a pre-order traversal, with a single space, " ",
//          inserted after each value.  If the binary_tree is empty, the return
//          value will be the string, "[empty]".

    std::string binary_tree::preorder() const
    {
		string str;
		if (this -> isEmpty())
		{
			str = "[empty]";
			return str;
		}
		str += root_ptr -> preorder();
		return str;
    }
//
//     int size()
//        Postcondition: Return value is the number of data values stored in
//          the tree.
//        Implementation note: Return the result of passing the request to the
//          root node.

    int binary_tree::size() const
    {
    	return root_ptr -> size();
    }
//
//     int height()
//        Postcondition: Return value is the height (aka depth) of the tree.
//        Implementation note: Return the result of passing the request to the
//          root node.
    int binary_tree::height() const
    {
    	return root_ptr -> height();
    }

//
//     void clear()
//        Postcondition: The tree is empty.
    void binary_tree::clear()
    {	 	  	 	    	 	 	   	       	 	
    	root_ptr -> clear();
    }
    


  


