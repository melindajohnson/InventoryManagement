
/*
BinarySearchTree.h
 Created by Melinda Stannah Stanley Jothiraj on 02/25/2020.
 Student number- 1978413
 SearchTree class: is a Binary Search Tree class that has
 A Node rootPtr that points to the root of the tree
 A int totalCharacters that holds the number of unique characters in the tree
 Struct Node: The Node holds a
 pointer item to the comparable object
 int count which holds the number of times a particular character is found in the input file
 Node left points to the left child and
 Node right points to the right child
 Includes additional features:
 -- allows output of the whole tree using operator << overloading method
 -- allows for comparison of 2 trees, Node by Node, structural similarity as well as what each Nodes item pointer points to in the Comparable Class
 -- allows for assignment of trees which involves a deep copy of the tree
 -- size of the tree is part of the class i.e the total number of Nodes in the SearchTree
 Assumptions:
 -- RootPtr is initialized to nullPtr and count is initialized to zero
 -- The file from which input is inserted into the tree must be valid ASCII characters
 The character and the frequency of its occurence are displayed as output
 ---------------------------------------------------------------------------
 */
#pragma once
#include <stdio.h>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include "Comparable.h"

class BinarySearchTree
{
private:
   
   struct BSTNode
   {
      Comparable* item;  //pointer to a Comparable object
      struct BSTNode* left = nullptr; //pointer to a left child Node
      struct BSTNode* right = nullptr; //pointer to a right child Node
   };
   
   BSTNode* rootPtr; //pointer to the root Node of the SearchTree
   int totalCharacters;  //total numbers of Nodes in the SearchTree
   
public:
   
   /*
    //-------------------------- Default constructor for class Search Tree ------------------------------------//
    Preconditions: None
    Postconditions: The rootPtr of the Searchtree is initialized to a nullptr
    */
   BinarySearchTree();
   
   /*
    //-------------------------- Copy constructor for class Search Tree ------------------------------------//
    Preconditions: The rootPtr points to a SearchTree containing a number of nodes in each of its left and right Subtree
    Postconditions: The rootPtr point to a new node, but the node contains the given data item and pointers to copies of the given subtrees.
    */
   BinarySearchTree(const BinarySearchTree& tree);
   
   /*
    //-------------------------- Destructor  for class Search Tree ------------------------------------//
    Preconditions:  The rootPtr points to a SearchTree containing a number of nodes in each of its left and right Subtree to a memory on the heap
    Postconditions: The rootptr and all subsequent pointers in the tree are deallocated
    */
   virtual ~BinarySearchTree();
   
   /*
    //-------------------------- Overloaded assignment operator =  ------------------------------------//
    Preconditions: The right.rootPtr points to a SearchTree containing a number of nodes
    Postconditions: *this is assigned the same values in the tree as right in a different memory location
    @return SearchTree which is a deep copy of the object right
    */
   BinarySearchTree operator= (const BinarySearchTree& right);
   
   /*
    //-------------------------- Overloaded equal to operator ==  ------------------------------------//
    Preconditions: The rootPtr and right.rootPtr point to a two SearchTree containing a number of nodes
    Postconditions: boolean true if the left and right object have the same number of nodes having the same structure and value or false if not
    @return boolean true or false depending on if they both have the same data, the same structure, and the same number of occurrences for each comparable
    */
   bool operator==(const BinarySearchTree& right) const;
   
   /*
    //-------------------------- Overloaded not equal to operator !=  ------------------------------------//
    Preconditions:The rootPtr and right.rootPtr point to a two SearchTree containing a number of nodes
    Postconditions:boolean false if the left and right object have the same number of nodes having the same structure and value or true if not
    @return boolean true or false depending on if they both have the different data, the different structure, and the different number of occurrences for each comparable
    */
   bool operator!=(const BinarySearchTree& right) const;
   
   /*
    //--------------------------Overloaded output operator <<  ------------------------------------//
    Outputs the contents of the tree in sorted order using inorder traversal of the  tree.
    Preconditions: tree.rootPtr must point to a SearchTree with child nodes
    Postconditions: Outputs the frequency table of the Search tree using inorder traversal method
    */
   friend std::ostream& operator<<(std::ostream& out, const BinarySearchTree& tree);
   
   /*
    //--------------------------Insert method  ------------------------------------//
    Preconditions: The rootPtr points to a SearchTree containing a number of nodes in each of its left and right Subtree
    Postconditions: Inserts a Comparable obj into the tree and transfers ownership of its memory to the tree
    or increments the count if it is already exists in the tree in which case the Comparable pointer is deallocated
    @return false if the Comparable is found and not inserted, true if inserted succesfully
    */
   bool insert(Comparable* obj);
   
   /*
    //--------------------------Remove method  ------------------------------------//
    Preconditions: The rootPtr points to a SearchTree containing a number of nodes in each of its left and right Subtree
    Postconditions:  Removes one occurrence of the Comparable obj from the tree. If it is the last occurrence the node is removed.
    @return false if the Comparable is not found and true is removal is successful
    */
   bool remove(const Comparable& obj);
   
   /*
    //--------------------------MakeEmpty method  ------------------------------------//
    Preconditions: The rootPtr points to a SearchTree containing a number of nodes in each of its left and right Subtree
    Postconditions: Removes and deallocates all of the data from the tree but does not delete the SearchTree object
    */
   void makeEmpty();
   
   /*
    //--------------------------retrieve method  ------------------------------------//
    Preconditions:  The rootPtr points to a SearchTree containing a number of nodes in each of its left and right Subtree
    Postconditions: Finds a Comparable 'key' in the tree
    @return nullptr if not found or a comparable pointer if located in the tree
    */
   const Comparable* retrieve(const Comparable& key) const;
   
   /*
    //--------------------------Height method  ------------------------------------//
    Preconditions: The rootPtr points to a SearchTree containing a number of nodes in each of its left and right Subtree
    Postconditions: The height of the node storing the Comparable key in the tree is found out
    @return -1 if the Comparable is not found or if found the height of the tree is returned with leaf nodes having 0 as height
    */
   int height(const Comparable& key) const;
   
      //-------------------------- Private Helper methods  -------------------------------------------
   
   
   /*
    //-------------------------- Deep Copy Helper method ------------------------------------//
    Preconditions: The subTreePtr points to a nullPtr  or a Node with left and right subtrees
    Postconditions: The newTreePtr point to a copy of the parametric new Object containing new copies of its left and right subtree along with a deep copy of item*
    @return Node pointing to a new copy of the subTreePtr and its child nodes
    */
   BSTNode* deepCopy(BSTNode* subTreePtr);
   
   /*
    //--------------------------Clear method ------------------------------------//
    Preconditions: The subTreePtr points to a nullPtr  or a Node with left and right subtrees
    Postconditions: The subtree pointers and its left and right subtrees are deallocated and frees the memory
    */
   void clear(BSTNode* subTreePtr);
   
   /*
    //--------------------------Insert helper method  ------------------------------------//
    Preconditions: The root points to a subTree in the SearchTree containing a number of nodes in each of its left and right Subtree
    Postconditions: Inserts a Comparable into the tree and transfers ownership of its memory to the tree
    or increments the count if it is already exists in the tree in which case the Comparable pointer is deallocated
    @return false if the Comparable is found and not inserted, true if inserted succesfully
    */
   bool insertHelper(BSTNode*& root, Comparable* item);
   
   /*
    //--------------------------DeleteNode method  ------------------------------------//
    Preconditions: The root points to a subtree containing a number of nodes in each of its left and right Subtree
    Postconditions:  Removes one occurrence of a Comparable from the tree. If it is the last occurrence the node is removed.
    @return false if the Comparable is not found and true is removal is successful
    */
   bool deleteNode(BSTNode*& root, const Comparable& key);
   
   /*
    //--------------------------DeleteRoot method  ------------------------------------//
    Preconditions: The root points to a subtree containing a number of nodes in each of its left and right Subtree
    Postconditions: If the root has zero children, the node is deleted
    If the root has one child, the node is deleted and replaced with a child that exists).
    If the node root has two children, a replacement item to placed in the node.
    This replacement item used is the smallest descendant of the right child which is done in the findAndDeleteMostLeft() method
    */
   void deleteRoot(BSTNode*& root);
   
   /*
    //--------------------------findAndDeleteMostLeft method  ------------------------------------//
    Preconditions: The root points to a subtree containing two child Nodes and is not a nullPtr
    Postconditions: A replacement item is found at the left most of the root
    @return A pointer to a Comparable object
    */
   Comparable* findAndDeleteMostLeft(BSTNode*& root);
   
   /*
    //--------------------------retrieveHelper method  ------------------------------------//
    Preconditions:  The subTreePtr points to a Node containing a number of nodes in each of its left and right Subtree
    Postconditions: Finds a Comparable in the tree using the Comparable object key .
    @return nullptr if not found or a comparable pointer if located in the tree
    */
   const Comparable* retrieveHelper(BSTNode* subTreePtr, const Comparable& key) const;
   
   /*
    //--------------------------searchForNode method  ------------------------------------//
    Preconditions:  The subTreePtr points to a Node containing a number of nodes in each of its left and right Subtree
    Postconditions: Finds a Node containing the pointer to the Comparable object key .
    @return nullptr if not found or a Node pointer if located in the tree
    */
   BSTNode* searchForNode(BSTNode* subTreePtr, const Comparable& key) const;
   
   /*
    //--------------------------HeightHelper method  ------------------------------------//
    Preconditions: The subTreePtr points to a Node containing a number of nodes in each of its left and right Subtree
    Postconditions: The height of the node storing the Comparable in the tree is found out
    @return -1 if the Comparable is not found or if found the height of the tree is returned with leaf nodes having 0 as height
    */
   int heightHelper(BSTNode* subTreePtr) const;
   
   /**
    //--------------------------Inorder traversal method  ------------------------------------//
    Preconditions: The subTreePtr points to a SearchTree containing a number of nodes in each of its left and right Subtree
    Postconditions: Prints the contents of the Search Tree in two vector using inorder traversal
    */
   void inorderTraversal(std::ostream& output, const BSTNode* subTreePtr) const;
   
   /*
    //--------------------------identicalTrees method  ------------------------------------//
    Preconditions: The Node a and Node b points to two SearchTree containing a number of nodes in each of its left and right Subtree
    Postconditions: Checks if both the trees have same item, same count and if its left and right subtrees are also the same structuraly
    @return true if identical or false if not
    */
   bool identicalTrees(BSTNode* a, BSTNode* b) const;
   
};
