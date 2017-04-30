// node_test1.cpp
// CS 223 Lab 10, Part 1: Unit Tests for the node classes
//
// Initial tests written by: Barb Wahl & Theresa Wilson, 4-5-2017
//
// Additional tests written by...
// Student Name:
// Date:

#include <iostream>
#include <cassert>
#include "node.h"

using namespace std;


void testNodeBasics_1()
{
    string test = "  NodeBasics.test.1: empty_node constructor, isEmpty == true";  // NOLINT
    cout << test << endl;

    empty_node em;
    assert(em.isEmpty());
}

void testNodeBasics_2()
{
    string test = "  NodeBasics.test.2: normal_node constructor, getters, empty subtrees";  // NOLINT
    cout << test << endl;

    normal_node normal1(17);
    assert(normal1.getData() == 17);
    assert(normal1.getLeft() -> isEmpty());
    assert(normal1.getRight() -> isEmpty());
}

void testNodeBasics_3()
{
    string test = "  NodeBasics.test.3: normal_node is not empty";  // NOLINT
    cout << test << endl;

    normal_node normal1(17);
    assert(!(normal1.isEmpty()));
}

void testNodeBasics()
{
    cout << "\nTesting node basics . . ." << endl;

    // Test 1: empty_node constructor, isEmpty
    testNodeBasics_1();

    // Test 2: normal_node constructor, getters, left and right are empty
    testNodeBasics_2();

    // Test 3: normal_node is not empty
    testNodeBasics_3();

    cout << "    . . . node basics OK!" << endl;
}

void testIsEmpty_1()
{
    string test = "  isEmpty.test.1: normal_node is not empty";  // NOLINT
    cout << test << endl;

    normal_node normal1(17);
    assert(!(normal1.isEmpty()));
}

void testIsEmpty_2()
{
    string test = "  isEmpty.test.2: normal_node has empty subtrees";
    cout << test << endl;

    normal_node normal1(17);
    assert(normal1.getLeft() -> isEmpty());
    assert(normal1.getRight() -> isEmpty());
}

void testIsEmpty_3()
{
    string test = "  isEmpty.test.3: empty_node is empty";
    cout << test << endl;

    empty_node em1;
    assert(em1.isEmpty());
}

void testIsEmpty()
{
    cout << "\nTesting isEmpty . . ." << endl;

    // Test 1: normal_node is not empty
    testIsEmpty_1();

    // Test 2: normal_node has empty subtrees
    testIsEmpty_2();

    // Test 3: empty node is empty
    testIsEmpty_3();

    cout << "    . . . isEmpty OK!" << endl;
}

void testIsLeaf_1()
{
    string test = "  isLeaf.test.1: empty_node is not a leaf";
    cout << test << endl;

    empty_node em1;
    assert(!(em1.isLeaf()));
}

void testIsLeaf_2()
{
    string test = "  isLeaf.test.2: normal_node with two empty subtrees is a leaf";  // NOLINT
    cout << test << endl;

    normal_node normal1(17);
    assert(normal1.isLeaf());
}

void testIsLeaf()
{
    cout << "\nTesting isLeaf . . ." << endl;

    // Test 1: empty_node is not a leaf
    testIsLeaf_1();

    // Test 2: normal_node with two empty subtrees is a leaf
    testIsLeaf_2();

    cout << "    . . . isLeaf OK!" << endl;
}

void testInsertAndContains_1()
{
    string test = "  insertAndContains.test.1: insert into empty node/tree";
    cout << test << endl;

    empty_node em1;
    node * newNode = em1.insert(17);
    assert(newNode -> getData() == 17);
    assert(newNode -> contains(17));

    assert(newNode -> isLeaf());
    assert(!(newNode -> isEmpty()));
    delete newNode;
}

void testInsertAndContains_2()
{
    string test = "  insertAndContains.test.2: insert into 1-node tree";
    cout << test << endl;

    normal_node normal1(5);
    normal1.insert(17);
    assert(normal1.getLeft() -> isEmpty());
    assert((normal1.getRight() -> getData()) == 17);
    assert(normal1.contains(17));

    assert(!normal1.isEmpty());
    assert(!normal1.isLeaf());
}

void testInsertAndContains_3()
{
    string test = "  insertAndContains.test.3: insert into 2-node tree";
    cout << test << endl;

    normal_node normal1(5);
    normal1.insert(17);
    normal1.insert(10);
    node * rt_tree = normal1.getRight();
    assert(rt_tree -> getData() == 17);
    assert(rt_tree -> getLeft() -> getData() == 10);
    assert(rt_tree -> getLeft() -> isLeaf());
    assert(normal1.contains(10));
}

void testInsertAndContains_4()
{
    string test = "  insertAndContains.test.4: insert into 3-node unbalanced tree";  // NOLINT
    cout << test << endl;

    normal_node normal1(5);
    normal1.insert(17);
    normal1.insert(10);
    normal1.insert(20);
    node * rt_tree = normal1.getRight();
    assert(rt_tree -> getRight() -> getData() == 20);
    assert(rt_tree -> getLeft() -> getData() == 10);
    assert(rt_tree -> getRight() -> isLeaf());
    assert(rt_tree -> getLeft() -> isLeaf());
    assert(normal1.contains(20));
}

void testInsertAndContains_5()
{
    string test = "  insertAndContains.test.5: insert into 4-node tree";
    cout << test << endl;

    normal_node normal1(5);
    normal1.insert(17);
    normal1.insert(10);
    normal1.insert(20);
    normal1.insert(12);
    node * rl_tree = normal1.getRight() -> getLeft();
    assert(rl_tree -> getRight() -> getData() == 12);
    assert(rl_tree -> getRight() -> isLeaf());
    assert(normal1.contains(12));
}

void testInsertAndContains_6()
{
    string test = "  insertAndContains.test.6: make sure we cannot insert a duplicate value"; // NOLINT
    cout << test << endl;

    normal_node normal1(5);
    normal1.insert(5);
    assert(normal1.getLeft() -> isEmpty());
    assert(normal1.getRight() -> isEmpty());
    assert(normal1.getData() == 5);
    normal1.insert(10);
    normal1.insert(10);
    assert(normal1.getRight() -> isLeaf());
    assert(normal1.getLeft() -> isEmpty());
}

void testInsertAndContains_7()
{
    string test = "  insertAndContains.test.7: contains should be false, 5-node tree";  // NOLINT
    cout << test << endl;

    normal_node normal1(5);
    normal1.insert(17);
    normal1.insert(10);
    normal1.insert(20);
    normal1.insert(12);
    assert(!normal1.contains(6));
    assert(!normal1.contains(1));
    assert(!normal1.contains(21));
}

void testInsertAndContains_8()
{
    string test = "  insertAndContains.test.8: contains should be false, empty node";  // NOLINT
    cout << test << endl;

    empty_node em1;
    assert(!em1.contains(17));
}

void testInsertAndContains_9()
{
    string test = "  insertAndContains.test.9: insert duplicate value into normal node, check return value";  // NOLINT
    cout << test << endl;

    empty_node em1;
    node* node_ptr1 = em1.insert(17);
    node* node_ptr2 = node_ptr1 -> insert(17);

    assert(node_ptr1 == node_ptr2);
    delete node_ptr1;
}

void testInsertAndContains_10()
{
    string test = "  insertAndContains.test.10: insert new value into normal node, check return value";  // NOLINT
    cout << test << endl;

    empty_node em1;
    node* node_ptr1 = em1.insert(17);

    node* node_ptr2 = node_ptr1 -> insert(19);
    assert(node_ptr1 == node_ptr2);

    node* node_ptr3 = node_ptr1 -> insert(15);
    assert(node_ptr1 == node_ptr3);
    delete node_ptr1;
}

void testInsertAndContains()
{
    cout << "\nTesting node insert and contains. . ." << endl;

    // Test 1: insert into empty node/tree
    testInsertAndContains_1();

    // Test 2: insert into 1-node tree
    testInsertAndContains_2();

    // Test 3: insert into 2-node tree
    testInsertAndContains_3();

    // Test 4: insert into 3-node unbalanced tree
    testInsertAndContains_4();

    // Test 5: insert into 4-node tree
    testInsertAndContains_5();

    // Test 6: try to insert a duplicate value
    testInsertAndContains_6();

    // Test 7: contains should be false, 5-node tree
    testInsertAndContains_7();

    // Test 8: contains should be false, empty node
    testInsertAndContains_8();

    // Test 9: insert duplicate value into node, check return value
    testInsertAndContains_9();

    // Test 10: insert value will go into right subtree, check return value
    testInsertAndContains_10();

    cout << "    . . . node insert and contains OK!" << endl;
}

void testInorder_0()
{
    string test = "  inorder.test.0: inorder for empty tree";
    cout << test << endl;

    empty_node em1;
    string result = em1.inorder();
    string correct = "";
    assert(result == correct);
}

void testInorder_1()
{
    string test = "  inorder.test.1: inorder for 1-node tree";
    cout << test << endl;

    normal_node normal1(52);
    string result = normal1.inorder();
    string correct = "52 ";
    assert(result == correct);
}

void testInorder_2()
{
    string test = "  inorder.test.2: inorder for 2-node tree";
    cout << test << endl;

    normal_node normal1(52);
    normal1.insert(1000);
    string result = normal1.inorder();
    string correct = "52 1000 ";
    assert(result == correct);
}

void testInorder_3()
{
    string test = "  inorder.test.3: inorder for 3-node tree";
    cout << test << endl;

    normal_node normal1(52);
    normal1.insert(1000);
    normal1.insert(12);
    string result = normal1.inorder();
    string correct = "12 52 1000 ";
    assert(result == correct);
}

void testInorder_4()
{
    string test = "  inorder.test.4: inorder for 4-node tree";
    cout << test << endl;

    normal_node normal1(52);
    normal1.insert(1000);
    normal1.insert(12);
    normal1.insert(73);
    string result = normal1.inorder();
    string correct = "12 52 73 1000 ";
    assert(result == correct);
}

void testInorder_5()
{
    string test = "  inorder.test.5: inorder for 5-node tree";
    cout << test << endl;

    normal_node normal1(52);
    normal1.insert(1000);
    normal1.insert(12);
    normal1.insert(73);
    normal1.insert(217);
    string result = normal1.inorder();
    string correct = "12 52 73 217 1000 ";
    assert(result == correct);
}

void testInorder()
{
    cout << "\nTesting inorder . . ." << endl;

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

    // Test 5: 5-node tree
    testInorder_5();

    cout << "    . . . inorder OK!" << endl;
}

void testPreorder_0()
{
    string test = "  inorder.test.0: inorder for empty tree";
    cout << test << endl;

    empty_node em1;
    string result = em1.preorder();
    string correct = "";
    assert(result == correct);
}

void testPreorder_1()
{
    string test = "  inorder.test.1: inorder for 1-node tree";
    cout << test << endl;

    normal_node normal1(52);
    string result = normal1.preorder();
    string correct = "52 ";
    assert(result == correct);
}

void testPreorder_2()
{
    string test = "  inorder.test.2: inorder for 2-node tree";
    cout << test << endl;

    normal_node normal1(52);
    normal1.insert(1000);
    string result = normal1.preorder();
    string correct = "52 1000 ";
    assert(result == correct);
}

void testPreorder_3()
{
    string test = "  inorder.test.3: inorder for 3-node tree";
    cout << test << endl;

    normal_node normal1(52);
    normal1.insert(1000);
    normal1.insert(12);
    string result = normal1.preorder();
    string correct = "52 12 1000 ";
    assert(result == correct);
}

void testPreorder_4()
{
    string test = "  inorder.test.4: inorder for 4-node tree";
    cout << test << endl;

    normal_node normal1(52);
    normal1.insert(1000);
    normal1.insert(12);
    normal1.insert(73);
    string result = normal1.preorder();
    string correct = "52 12 1000 73 ";
    assert(result == correct);
}

void testPreorder_5()
{
    string test = "  inorder.test.5: inorder for 5-node tree";
    cout << test << endl;

    normal_node normal1(52);
    normal1.insert(1000);
    normal1.insert(12);
    normal1.insert(73);
    normal1.insert(217);
    string result = normal1.preorder();
    string correct = "52 12 1000 73 217 ";
    assert(result == correct);
}

void testPreorder()
{
    cout << "\nTesting preorder . . ." <<endl;

    // Literal copy-paste of Inorder with some edits
    // Test 0: empty tree
    testPreorder_0();

    // Test 1: 1-node tree
    testPreorder_1();

    // Test 2: 2-node tree
    testPreorder_2();

    // Test 3: 3-node tree
    testPreorder_3();

    // Test 4: 4-node tree
    testPreorder_4();

    // Test 5: 5-node tree
    testPreorder_5();

    cout << "    . . . preorder OK!" << endl;
}

void testSizeandHeight1()
{
    string test = "  Size.and.height.test.1: Size and Height for an empty tree";
    cout << test << endl;

    empty_node em1;

    assert (em1.size() == 0);
    assert (em1.height() == -1);

}

void testSizeandHeight2()
{
    string test = "  Size.and.height.test.2: Size and Height for a 1-node tree";
    cout << test << endl;
    
    normal_node nn1(12);

    assert (nn1.size() == 1);
    assert (nn1.height() == 0);

}

void testSizeandHeight3()
{
    string test =  "  Size.and.height.test.3: Size and Height for a 3-node tree";
    cout << test << endl;
    
    normal_node nn1(12);

    nn1.insert(11); // left
    nn1.insert(13); // right

    assert (nn1.size() == 3);
    assert (nn1.height() == 1);
}

void testSizeandHeight4()
{
    string test = "  Size.and.height.test.4: Size and Height for a 7-node tree";
    cout << test << endl;

    normal_node nn1(12);

    //now insert 6 more nodes for a total of 7
    nn1.insert(10); // left of 12 
    nn1.insert(11); // right of 10
    nn1.insert(9); // left of 10
    nn1.insert(14); // right of 12 
    nn1.insert(13); // left of 14
    nn1.insert(15); // right of 14

    // Total nodes in the tree: 7

    assert (nn1.size() == 7);
    assert (nn1.height() == 2);
    
}

void testSizeandHeight5()
{
    string test = "  Size.and.height.test.5: Size and Height for a right-skewed tree";
    cout << test << endl;
    
    normal_node nn1(100);

    // insert 5 nodes, ALL to the RIGHT of root 
    nn1.insert(150);
    nn1.insert(200);
    nn1.insert(250);
    nn1.insert(300);
    nn1.insert(350);

    assert (nn1.size() == 6);
    assert (nn1.height() == 5);
}

void testSizeandHeight6()
{
    string test = "  Size.and.height.test.6: Size and Height for a left-skewed tree";
    cout << test << endl;
    
    normal_node nn1(100);

    // insert 5 nodes, ALL to the LEFT of root 
    nn1.insert(75);
    nn1.insert(50);
    nn1.insert(25);
    nn1.insert(20);
    nn1.insert(10);

    assert (nn1.size() == 6);
    assert (nn1.height() == 5);
}

void testSizeandHeight()
{
    cout << "\nTesting Size and Height . . . " <<endl;

    // Test 1: empty-node tree
    testSizeandHeight1();

    // Test 2: 1-node tree
    testSizeandHeight2();

    // Test 3: 3-node tree
    testSizeandHeight3();

    // Test 4: 7-node tree
    testSizeandHeight4();

    // Test 5: skewed right tree
    testSizeandHeight5();

    // Test 6: skewed left tree
    testSizeandHeight6();

    cout << "    . . . Size and Height OK! " << endl;

}

void testclear1()
{
    string test = "  Clear.1: clear an empty tree";
    cout << test << endl;

    empty_node em1;

    assert (em1.size() == 0);
    em1.clear();
    assert (em1.size() == 0); 
}

void testclear2()
{
    string test = "  Clear.2: clear a 1-node tree";
    cout << test << endl;  

    normal_node nn1(12);

    assert (nn1.size() == 1);
    assert (nn1.contains(12));
    assert (nn1.height() == 0); // ensures 12 is the root 

    nn1.clear();

    assert (nn1.size() == 1);
    assert (nn1.contains(12));  // gets down to the root node
    assert (nn1.height() == 0); // ensures the tree is now empty (it's been cleared)
}

void testclear3()
{
    string test = "  Clear.3: clear a 3-node tree";
    cout << test << endl;  

    normal_node nn1(12);

    assert (nn1.size() == 1);
    assert (nn1.contains(12));
    assert (nn1.height() == 0); // ensures 12 is the root

    //create a complete tree
    nn1.insert(13); // right of 12
    nn1.insert(11); // left of 12

    assert (nn1.size() == 3);
    assert (nn1.contains(11));
    assert (nn1.contains(13));
    assert (nn1.height() == 1);

    nn1.clear();

    assert (nn1.size() == 1);
    assert (nn1.contains(12));  // gets down to the root node
    assert (nn1.height() == 0); // ensures the tree is now empty (it's been cleared)
}

void testclear4()
{
    string test = "  Clear.4: clear a skewed-right tree, 5 nodes";
    cout << test << endl;  

    normal_node nn1(12);

    assert (nn1.size() == 1);
    assert (nn1.contains(12));
    assert (nn1.height() == 0); // ensures 12 is the root

    //create a complete tree
    nn1.insert(13); // right of 12
    nn1.insert(14); // right of 13
    nn1.insert(15); // right of 14
    nn1.insert(16); // right of 15

    assert (nn1.size() == 5);
    assert (nn1.contains(13));
    assert (nn1.contains(14));
    assert (nn1.contains(15));
    assert (nn1.contains(16));
    assert (nn1.height() == 4);

    nn1.clear();

    assert (nn1.size() == 1);
    assert (nn1.contains(12));  // gets down to the root node
    assert (nn1.height() == 0); // ensures the tree is now empty (it's been cleared)
}

void testclear5()
{
    string test = "  Clear.5: clear a skewed-left tree";
    cout << test << endl; 

    normal_node nn1(12);

    assert (nn1.size() == 1);
    assert (nn1.contains(12));
    assert (nn1.height() == 0); // ensures 12 is the root

    //create a complete tree
    nn1.insert(11); // right of 12
    nn1.insert(10); // right of 13
    nn1.insert(9); // right of 14
    nn1.insert(8); // right of 15

    assert (nn1.size() == 5);
    assert (nn1.contains(11));
    assert (nn1.contains(10));
    assert (nn1.contains(9));
    assert (nn1.contains(8));
    assert (nn1.height() == 4);

    nn1.clear();

    assert (nn1.size() == 1);
    assert (nn1.contains(12));  // gets down to the root node
    assert (nn1.height() == 0); // ensures the tree is now empty (it's been cleared) 
}

void testclear()
{
    cout << "\nTesting clear . . . " <<endl;

    // Test 1: clear an empty tree
    testclear1();

    // Test 2: clear a tree with 1 node
    testclear2();

    // Test 3: clear a tree with 3 nodes
    testclear3();

    // Test 4: clear a tree skewed right
    testclear4();

    // Test 5: clear a tree skewed left
    testclear5();
}

int main()
{
    testNodeBasics();         // node constructors, getters, isEmpty
    testIsLeaf();
    testInsertAndContains();  // also test isLeaf, isEmpty on larger structures
    testInorder();
    testPreorder();
    testSizeandHeight();
    testclear();

    cout << "\nAll current tests for node classes are passing!" << endl;

    return 0;
}
