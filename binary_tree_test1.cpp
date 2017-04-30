// binary_tree_test1.cpp
// Unit Tests for binary_tree, CS 223 Lab 10, Part 1
//
// Initial tests written by: Barb Wahl & Theresa Wilson, 4-5-2017
//
// Additional tests written by...
// Student Name: Kenneth Jarnagin
// Date: 4-11-17

#include <iostream>
#include <cassert>
#include "binary_tree.h"    // provides binary_tree, normal_node, empty_node

using namespace std;

void testTreeConstructor()
{
    cout << "\nTesting tree constructor . . ." << endl;

    cout << "   treeConstructor.test.1: constructor creates empty tree" << endl;
    binary_tree mytree;
    assert(mytree.isEmpty());
    cout << "    . . . tree constructor OK!" << endl;
}

void testInsertAndContains_1()
{
    string test = "  insertAndContains.test.1: insert into empty tree";
    cout << test << endl;

    binary_tree mytree;
    mytree.insert(17);

    assert(mytree.contains(17));
    assert(!mytree.isEmpty());
}

void testInsertAndContains_2()
{	 	  	 	    	 	 	   	       	 	
    string test = "  insertAndContains.test.2: insert into tree depth 0";
    cout << test << endl;

    binary_tree mytree;
    mytree.insert(17); // empty tree has been inserted into (depth now 1)

    assert(mytree.contains(17));
    assert(!mytree.isEmpty());

    mytree.insert(12);

    assert (mytree.contains(12));
    assert (!mytree.isEmpty());
}

void testInsertAndContains_3()
{
    string test = "  insertAndContains.test.3: insert into tree multiple times";
    cout << test << endl;

    binary_tree mytree;
    mytree.insert(17);// empty tree has been inserted into (depth now 1)

    assert(mytree.contains(17));
    assert(!mytree.isEmpty());

    mytree.insert(12);
    mytree.insert(10);
    mytree.insert(9);
    mytree.insert(3);
    mytree.insert(98);
    mytree.insert(76);
    mytree.insert(0);
    mytree.insert(55);
    mytree.insert(99);
    mytree.insert(31);
    mytree.insert(78);
    mytree.insert(84);
    mytree.insert(36);
    mytree.insert(63); //14 inserts


    assert (mytree.contains(12));
    assert (mytree.contains(10));
    assert (mytree.contains(98));
    assert (mytree.contains(9));
    assert (mytree.contains(3));
    assert (mytree.contains(99));
    assert (mytree.contains(31));
    assert (mytree.contains(78));
    assert (mytree.contains(84));
    assert (mytree.contains(36));
    assert (mytree.contains(63));
    assert (mytree.contains(0));
    assert (mytree.contains(76));
    assert (mytree.contains(55)); //14 asserts
    assert (!mytree.isEmpty());
}	 	  	 	    	 	 	   	       	 	

void testInsertAndContains()
{
    cout << "\nTesting tree insert and contains . . ." << endl;

    // Test 1: insert into empty tree
    testInsertAndContains_1();
    // Test 2: insert into a tree of one
    testInsertAndContains_2();
    // Test 3: insert multiple times into a tree
    testInsertAndContains_3();


    cout << "    . . . insert and contains OK!" << endl;
}

void testInorder_0()
{
    string test = "  inorder.test.0: inorder for empty-node tree";
    cout << test << endl;

    binary_tree mytree;

    string result = mytree.inorder();
    string actual = "[empty]";
    assert (result == actual);
}

void testInorder_1()
{
    string test = "  inorder.test.1: inorder for 1-node tree";
    cout << test << endl;

    binary_tree mytree;

    mytree.insert(17);

    string result = mytree.inorder();
    string actual = "17 ";

    assert (result == actual);
}	 	  	 	    	 	 	   	       	 	

void testInorder_2()
{
    //right sided tree
    string test = "  inorder.test.2: inorder for 3-node tree";
    cout << test << endl;

    binary_tree mytree;

    mytree.insert(17);
    mytree.insert(43);
    mytree.insert(99);

    string result = mytree.inorder();
    string actual = "17 43 99 ";

    assert (result == actual);
}

void testInorder_3()
{
    //somewhat balanced tree
    string test = "  inorder.test.3: inorder for 6-node tree";
    cout << test << endl;

    binary_tree mytree;

    mytree.insert(17);
    mytree.insert(3);
    mytree.insert(5);
    mytree.insert(19);
    mytree.insert(18);
    mytree.insert(20);

    string result = mytree.inorder();
    string actual = "3 5 17 18 19 20 ";

    assert (result == actual);
}	 	  	 	    	 	 	   	       	 	

void testInorder_4()
{
    //lopsided tree
    string test = "  inorder.test.4: inorder for 6-node tree";
    cout << test << endl;

    binary_tree mytree;

    mytree.insert(17);
    mytree.insert(35);
    mytree.insert(99);
    mytree.insert(19);
    mytree.insert(18);
    mytree.insert(20);

    string result = mytree.inorder();
    string actual = "17 18 19 20 35 99 ";

    assert (result == actual);
}


void testInorder()
{
    cout << "\nTesting tree traversal inorder . . ." << endl;
    // Test 0: empty tree
    testInorder_0();

    // Test 1: 1-node tree
    testInorder_1();

    // Test 2: 2-node tree
    testInorder_2();

    // Test 3: 3-node tree
    testInorder_3();

    // Test 4: 4-node tree
    testInorder_4();

    cout << "    . . . inorder traversal OK!" << endl;
}	 	  	 	    	 	 	   	       	 	

int main()
{
    testTreeConstructor();
    testInsertAndContains();
    testInorder();

    cout << "\nAll current tests passing!  Need to add more?" << endl;
    return 0;
}
