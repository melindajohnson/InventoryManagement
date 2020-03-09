
/*
 BinarySearchTree.h
 Created by Melinda Stannah Stanley Jothiraj on 11/27/19.
 Student number- 1978413
 BinarySearchTree class: is a Binary Search Tree class that has
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
 -- size of the tree is part of the class i.e the total number of Nodes in the BinarySearchTree
 Assumptions:
 -- RootPtr is initialized to nullPtr and count is initialized to zero
 -- The file from which input is inserted into the tree must be valid ASCII characters
 The character and the frequency of its occurence are displayed as output
 ---------------------------------------------------------------------------
 */


#include "BinarySearchTree.h"


/*
 //-------------------------- Default constructor for class BinarySearchTree ------------------------------------//
 Preconditions: None
 Postconditions: The rootPtr of the BinarySearchTree is initialized to a nullptr and the totalCharacters is set to 0
 */
BinarySearchTree::BinarySearchTree() {
   rootPtr = nullptr;
   totalCharacters = 0;
}

/*
 //-------------------------- Copy constructor for class BinarySearchTree ------------------------------------//
 Preconditions: The rootPtr points to an empty BinarySearchTree  or one containing a number of nodes in each of its left and right Subtree
 Postconditions: The rootPtr point to a copy of the BinarySearchTree tree containing new copies of its left and right subtree in a different memory location
 */
BinarySearchTree::BinarySearchTree(const BinarySearchTree& tree) {
   
   rootPtr = deepCopy(tree.rootPtr); //helper method that makes a deep copy of the SearchTree tree
   totalCharacters = tree.totalCharacters;
}

/*
 //-------------------------- Destructor  for class BinarySearchTree ------------------------------------//
 Preconditions:  The rootPtr points to an empty BinarySearchTree or one containing a number of nodes in each of its left and right Subtree
 Postconditions: The rootptr and all subtree pointers in the tree are deallocated
 */
BinarySearchTree::~BinarySearchTree() {
   clear(rootPtr);
   totalCharacters = 0;
}

/*
 //-------------------------- Overloaded assignment operator =  ------------------------------------//
 Preconditions: The right.rootPtr points to  an empty BinarySearchTree  or one containing a number of nodes in each of its left and right Subtree
 Postconditions: *this point to a copy of the BinarySearchTree right containing copies of its left and right subtree in a different memory location
 @return BinarySearchTree which is a deep copy of the object right
 */
BinarySearchTree BinarySearchTree::operator= (const BinarySearchTree& right) {
   if (this != &right) {
      makeEmpty(); // Deallocate left-hand side
      rootPtr = deepCopy(right.rootPtr); //copy Tree Nodes from right;
      totalCharacters = right.totalCharacters;
   }
   return *this;
}

/*
 //-------------------------- Overloaded equal to operator ==  ------------------------------------//
 Preconditions: The rootPtr and right.rootPtr point to a two BinarySearchTree containing a number of nodes
 Postconditions: boolean true if the left and right object have the same number of nodes having the same structure and value or false if not
 @return boolean true or false depending on if they both have the same data, the same structure, and the same number of occurrences for each comparable
 */
bool BinarySearchTree::operator==(const BinarySearchTree& right) const {
   return (identicalTrees(rootPtr, right.rootPtr));
}

/*
 //-------------------------- Overloaded not equal to operator !=  ------------------------------------//
 Preconditions:The rootPtr and right.rootPtr point to a two BinarySearchTree containing a number of nodes
 Postconditions:boolean false if the left and right object have the same number of nodes having the same structure and value or true if not
 @return boolean true or false depending on if they both have the different data, the different structure, and the different number of occurrences for each comparable
 */
bool BinarySearchTree::operator!=(const BinarySearchTree& right) const {
   return !(identicalTrees(rootPtr, right.rootPtr));
}

/*
 //--------------------------Overloaded output operator <<  ------------------------------------//
 Outputs the frequency table in sorted order using inorder traversal of the  tree.
 Preconditions: tree.rootPtr must point to a BinarySearchTree with child nodes
 Postconditions: Outputs the frequency table of the BinarySearchTree in sorted order using inorder traversal method.
 */
std::ostream& operator<<(std::ostream& out, const BinarySearchTree& tree) {
   tree.inorderTraversal(out, tree.rootPtr);
   return out;
   
}

/*
 //--------------------------Insert method  ------------------------------------//
 Preconditions: The rootPtr points to a BinarySearchTree containing a number of nodes in each of its left and right Subtree
 Postconditions: Inserts a Comparable obj into the tree and transfers ownership of its memory to the tree
 or increments the count if it is already exists in the tree in which case the Comparable pointer is deallocated
 @return false if the Comparable is found and not inserted, true if inserted succesfully
 */
bool BinarySearchTree::insert(Comparable* obj) {
   if (insertHelper(rootPtr, obj)) {
      totalCharacters++;
      return true;
   }
   else return false;
}

/*
 //--------------------------Remove method  ------------------------------------//
 Preconditions: The rootPtr points to a BinarySearchTree containing a number of nodes in each of its left and right Subtree
 Postconditions:  Removes one occurrence of a Comparable obj from the tree. If it is the last occurrence the node is removed.
 @return false if the Comparable is not found and true is removal is successful
 */
bool BinarySearchTree::remove(const Comparable& obj) {
   
   
   if (rootPtr == nullptr) return false;
   return deleteNode(rootPtr, obj);
   
}

/*
 //--------------------------MakeEmpty method  ------------------------------------//
 Preconditions: The rootPtr points to a BinarySearchTree containing a number of nodes in each of its left and right Subtree
 Postconditions: Removes and deallocates all of the data from the tree but does not delete the BinarySearchTree object
 */
void BinarySearchTree::makeEmpty() {
   clear(rootPtr);
   totalCharacters = 0;
   rootPtr = nullptr;
}
/*
 //--------------------------retrieve method  ------------------------------------//
 Preconditions:  The rootPtr points to a BinarySearchTree containing a number of nodes in each of its left and right Subtree
 Postconditions: Finds a Comparable 'key' in the tree
 @return nullptr if not found or a comparable pointer if located in the tree
 */
const Comparable* BinarySearchTree::retrieve(const Comparable& key) const {
   if (rootPtr == nullptr) return nullptr;
   return (retrieveHelper(rootPtr, key));
}
/*
 //--------------------------Height method  ------------------------------------//
 Preconditions: The rootPtr points to a BinarySearchTree containing a number of nodes in each of its left and right Subtree
 Postconditions: The height of the node storing the Comparable key in the tree is found out
 @return -1 if the Comparable is not found or if found the height of the tree is returned with leaf nodes having 0 as height
 */
int BinarySearchTree::height(const Comparable& key) const {
   if (rootPtr == nullptr) return -1;
   BSTNode* keyNode = searchForNode(rootPtr, key); //searches for the node containing the comparable key
   if (keyNode == nullptr)  return -1; //returns -1 if no such key exists
   return heightHelper(keyNode); //returns height of the node containing the comparable key
   
}
//---------------------------- Private Helper methods  -----------------------------//

/*
 //-------------------------- Deep Copy Helper method ------------------------------------//
 Preconditions: The subTreePtr points to a nullPtr  or a Node with left and right subtrees
 Postconditions: The newTreePtr point to a copy of the parametric new Object containing new copies of its left and right subtree along with a deep copy of item*
 @return Node pointing to a new copy of the subTreePtr and its child nodes
 */
BinarySearchTree::BSTNode* BinarySearchTree::deepCopy(BSTNode* subTreePtr) {
   
   
   BSTNode* newTreePtr = nullptr;
      // Copy tree nodes during a preorder traversal
   if (subTreePtr != nullptr) {
      newTreePtr = new BSTNode; //Create a new Node
      Comparable *newItem; //Create a new Comparable
      //dereference the Comparable pointer of the subTreePtr and setting it to a new Comparable
      newItem = subTreePtr->item;
      newTreePtr->item =newItem; //-------------------- //change made here
     // newTreePtr->count = subTreePtr->count;
      newTreePtr->left = deepCopy(subTreePtr->left);
      newTreePtr->right = deepCopy(subTreePtr->right);
   }
   return newTreePtr;
}


/*
 //--------------------------Clear method ------------------------------------//
 Preconditions: The subTreePtr points to a nullPtr  or a Node with left and right subtrees
 Postconditions: The subtree pointers and its left and right subtrees are deallocated and frees the memory
 */
void BinarySearchTree::clear(BSTNode* subTreePtr) {
   if (subTreePtr != nullptr)
   {
      clear(subTreePtr->left); //recusively call left subtree
      clear(subTreePtr->right); //recusrively calls the right subtree
      delete subTreePtr->item;
      delete subTreePtr;
   }
}

/*
 //--------------------------Insert helper method  ------------------------------------//
 Preconditions: The root points to a subTree in the BinarySearchTree containing a number of nodes in each of its left and right Subtree
 Postconditions: Inserts a Comparable into the tree and transfers ownership of its memory to the tree
 or increments the count if it is already exists in the tree in which case the Comparable pointer is deallocated
 @return false if the Comparable is found and not inserted, true if inserted succesfully
 */
bool BinarySearchTree::insertHelper(BSTNode*& root, Comparable* item) {
      //Creates a new node if teh Comparable item does not exist
   if (root == nullptr) {
      root = new BSTNode;
      root->item = item;
      root->left = nullptr;
      root->right = nullptr;
      //root->count++;
      return true;
   }
   else if (*item < *root->item)
      insertHelper(root->left, item); //Recursively calls the roots left if the comparable item is lesser than the calling comparable item
   else if (*item > * root->item)
      insertHelper(root->right, item); //Recursively calls the roots right if the comparable item is greater than the calling comparable item
   else if (*item == *root->item) {
     // root->count++;  //increments count if the item already exists in the BinarySearchTree
      delete item;   //The comparable pointer to be inserted is deallocated since it is not inserted in the tree
      return false;
   }
   return true;
}

/*
 //--------------------------DeleteNode method  ------------------------------------//
 Preconditions: The root points to a subtree containing a number of nodes in each of its left and right Subtree
 Postconditions:  Removes one occurrence of a Comparable key from the tree. If it is the last occurrence the node is removed.
 @return false if the Comparable is not found and true is removal is successful
 */
bool BinarySearchTree::deleteNode(BSTNode*& root, const Comparable& key)
{
   if (root == nullptr)
      return false;
   else if (key == *root->item) {
         deleteRoot(root); //The Node is deleted if its count is 1
         totalCharacters--;
         return true;
         
      }
//      else {
//        // root->count--;   //The node is not deleted if count is more than 1 and then count is decremented
//         return false;
//   }
   else if (key < *root->item)
      return deleteNode(root->left, key); //Recursive call to root left if Comparable object key is less than roots Comparable object
   else
      return deleteNode(root->right, key); //Recursive call to root right if Comparable object key is greater than roots Comparable object
}

/*
 //--------------------------DeleteRoot method  ------------------------------------//
 Preconditions: The root points to a subtree containing a number of nodes in each of its left and right Subtree
 Postconditions: If the root has zero children, the node is deleted
 If the root has one child, the node is deleted and replaced with a child that exists).
 If the node root has two children, a replacement item to placed in the node.
 This replacement item used is the smallest descendant of the right child which is done in the findAndDeleteMostLeft() method
 */
void BinarySearchTree::deleteRoot(BSTNode*& root)
{
   delete root->item;
   
   if (root->left == nullptr && root->right == nullptr) {      //root is deleted since it has no children
      delete root;
      root = nullptr;
   }
   else if (root->left == nullptr || root->right == nullptr) {   //root is deleted and replaced with a child that exists
      BSTNode* tmp = root;
      root = root->left == nullptr ? root->right : root->left;
      delete tmp;
   }
   else {
      root->item = findAndDeleteMostLeft(root->right); //roots item is set to the smallest item in its right child
   }
}

/*
 //--------------------------findAndDeleteMostLeft method  ------------------------------------//
 Preconditions: The root points to a subtree containing two child Nodes and is not a nullPtr
 Postconditions: A replacement item is found at the left most of the root
 @return A pointer to a Comparable object
 */
Comparable* BinarySearchTree::findAndDeleteMostLeft(BSTNode*& root)
{
   if (root->left == nullptr) {
      Comparable* item = root->item;
      BSTNode* junk = root;
      root = root->right;
      delete junk;
      return item;
   }
   else
      return findAndDeleteMostLeft(root->left);
}
/*
 //--------------------------retrieveHelper method  ------------------------------------//
 Preconditions:  The subTreePtr points to a Node containing a number of nodes in each of its left and right Subtree
 Postconditions: Finds a Comparable in the tree using the Comparable object key .
 @return nullptr if not found or a comparable pointer if located in the tree
 */
const Comparable* BinarySearchTree::retrieveHelper(BSTNode* subTreePtr, const Comparable& key) const {
   if (subTreePtr == nullptr)
      return nullptr; //nullPtr is returned if there is no Node in the tree that contains the key or the subtree Pointer is itself a nullptr
   else if (key == *subTreePtr->item)
      return subTreePtr->item;
   else if (key < *subTreePtr->item)
      return retrieveHelper(subTreePtr->left, key);  //Recursive call to root left if Comparable object key is less than subTreePtr Comparable object
   else
      return retrieveHelper(subTreePtr->right, key); //Recursive call to root right if Comparable object key is greater than subTreePtr Comparable object
}

/*
 //--------------------------searchForNode method  ------------------------------------//
 Preconditions:  The subTreePtr points to a Node containing a number of nodes in each of its left and right Subtree
 Postconditions: Finds a Node containing the pointer to the Comparable object key .
 @return nullptr if not found or a Node pointer if located in the tree
 */
BinarySearchTree::BSTNode* BinarySearchTree::searchForNode(BSTNode* subTreePtr, const Comparable& key) const {
   
   if (subTreePtr == NULL || key == *subTreePtr->item)
      return subTreePtr;
   
      // Key is greater than root's key
   if (key < *subTreePtr->item)
      return searchForNode(subTreePtr->left, key);
   
      // Key is smaller than root's key
   return searchForNode(subTreePtr->right, key);
}

/*
 //--------------------------HeightHelper method  ------------------------------------//
 Preconditions: The subTreePtr points to a Node containing a number of nodes in each of its left and right Subtree
 Postconditions: The height of the node storing the Comparable in the tree is found out
 @return -1 if the Comparable is not found or if found the height of the tree is returned with leaf nodes having 0 as height
 */
int BinarySearchTree::heightHelper(BSTNode* subTreePtr) const {
   if (subTreePtr == nullptr) return -1;
   return std::max(heightHelper(subTreePtr->left), heightHelper(subTreePtr->right)) + 1;
}

/*
 //--------------------------Inorder traversal method  ------------------------------------//
 Preconditions: The subTreePtr points to a BinarySearchTree containing a number of nodes in each of its left and right Subtree.
 Postconditions: Stores the contents of the BinarySearchTree in two vector using inorder traversal
 */
void BinarySearchTree::inorderTraversal(std::ostream& output, const BSTNode* subTreePtr) const {
   
   if (subTreePtr == nullptr) return;
   
   if (subTreePtr->left != nullptr)
   {
      inorderTraversal(output,subTreePtr->left);
   }
   //output << *subTreePtr->item;
   output << " ";
   //output << subTreePtr->count;
   output << std::endl;
   
   if (subTreePtr->right != nullptr)
   {
      inorderTraversal(output, subTreePtr->right);
   }
   
   
}

/*
 //--------------------------identicalTrees method  ------------------------------------//
 Preconditions: The Node a and Node b points to two BinarySearchTree containing a number of nodes in each of its left and right Subtree
 Postconditions: Checks if both the trees have same item, same count and if its left and right subtrees are also the same structuraly
 @return true if identical or false if not
 */
bool BinarySearchTree::identicalTrees(BSTNode* a, BSTNode* b) const
{
   if (a == nullptr && b == nullptr) return true; //if both are empty then return 1 which corresponds to it being the same
                                                  //if one points to a nullptr then return 0 which corresponds to it not being the same
   else if (a != nullptr && b == nullptr) return false;
   else if (a == nullptr && b != nullptr) return false;
   else //check if they both have same data and if its subtrees are also the same
      if (*a->item == *b->item && identicalTrees(a->left, b->left)
          && identicalTrees(a->right, b->right))  return true;
   return 0;
   
    //if (*a->item == *b->item && a->count == b->count && identicalTrees(a->left, b->left)
}
