#ifndef BINTREE_H
#define BINTREE_H

#include <string>
#include <vector>
#include "customer.h"
#include "movie.h"
#include "classics.h"

using namespace std;

const int ARRAYSIZE = 100;

// BST Node contains pointer for left, right, and data
template <typename T>
struct Node
{
  T* data;
  Node<T>* left;
  Node<T>* right;
};

template <typename T>
class BinTree
{
  public:
    // Constructor
    BinTree();

    // Desctructor
    ~BinTree();

    // required public methods
    bool isEmpty() const; // check if tree is empty

    // assumes user isn't inserting different object types into tree
    bool insert(const T* objectPtr); // insert node with the node data

    bool hasObject(const T* objectPtr) const;

    // so far only for classics
    int findNumSimilarTitles(const T* objectPtr) const;

    void displaySideways() const; // displays the tree sidways

    void displayPreorder() const;

  private:
    Node<T>* root; // Points to the root of the BST

    // You can add private methods here
    void clearTree(Node<T>* deletePtr); // removes all nodes except for root using post order traversal
    Node<T>* findParentNode(const T* objectPtr, Node<T>*& nodePtr) const; // finds the parent node to the given value by traversing in preorder
    int iterateAllSimilar(const T* objectPtr, Node<T>*& nodePtr, int*& count) const; // inorder traverses and counts all similar objects
    void printSidewaysTree(Node<T>*& nodePtr, int indentTracker) const; // recursively goes through right, root, left and prints
    void preorderPrint(Node<T>*& nodePtr) const;
};

// ------------------------------------ constructor -------------------------------------------
// Description: Default constructor for BinTree class
// preconditions: no inputs
// postconditions: BinTree with an empty node as root
// --------------------------------------------------------------------------------------------
template <typename T>
BinTree<T>::BinTree()
{
  root = new Node();
  root->data = nullptr;
  root->left = nullptr;
  root->right = nullptr;
}

// -------------------------------------- isEmpty ---------------------------------------------
// Description: checks if the tree is currently empty
// preconditions: no inputs
// postconditions: boolean evaluation of whether of not the tree is empty
// --------------------------------------------------------------------------------------------
template <typename T>
bool BinTree<T>::isEmpty() const
{
  return (root->data == nullptr);
}

// -------------------------------------- insert ----------------------------------------------
// Description: inserts the proper location of the value into the binary tree
// preconditions: string value as input
// postconditions: boolean evaluation of whether or not the value as been inserted into the
//                 tree
// --------------------------------------------------------------------------------------------
template <typename T>
bool BinTree<T>::insert(const T* objectPtr)
{
  bool insertSuccess = false;
  if (objectPtr == nullptr)
  {
    return false;
  }

  if (isEmpty()) // insert when tree is empty;
  {
    root->data = objectPtr;
    insertSuccess = true;
  }

  Node<T>* nodePtr = root;
  Node<T>* parentNode = findParentNode(objectPtr, nodePtr);
  if (parentNode == nullptr)
  {
    nodePtr = nullptr;
    parentNode = nullptr;
    return false;
  }
  if (!insertSuccess)
  {
    if (objectPtr < parentNode->data) // add in to left branch
    {
      Node<T>* addNode = new Node();
      addNode->data = objectPtr;
      addNode->left = nullptr;
      addNode->right = nullptr;

      parentNode->left = addNode;
      insertSuccess = true;
    }
    else if (objectPtr > parentNode->data) // add in to right branch
    {
      Node<T>* addNode = new Node();
      addNode->data = objectPtr;
      addNode->left = nullptr;
      addNode->right = nullptr;

      parentNode->right = addNode;
      insertSuccess = true;
    }
    else // value already exsists in tree
    {
      insertSuccess = false;
    }
  }

  nodePtr = nullptr;
  parentNode = nullptr;
  return insertSuccess;
}

template <typename T>
bool BinTree<T>::hasObject(const T* objectPtr) const
{
  if (objectPtr == nullptr)
  {
    return false;
  }

  Node<T>* nodePtr = root;
  Node<T>* parentNode = findParentNode(objectPtr, nodePtr);
  
  if (parentNode == nullptr)
  {
    return false;
  }
  return (objectPtr == parentNode->data);
}

// so far only needed for classics
template <typename T>
int BinTree<T>::findNumSimilarTitles(const T* objectPtr) const
{
  if (objectPtr == nullptr)
  {
    return -1;
  }
  Node<T>* nodePtr = root;
  int* i = 0;
  int count = iterateAllSimilar(objectPtr, nodePtr, i);
  i = nullptr;
  nodePtr = nullptr;
  return count;
}

// --------------------------------- displaySideways ------------------------------------------
// Description: prints tree in specific format
// preconditions: no inputs
// postconditions: visual representation of bintree
// --------------------------------------------------------------------------------------------
template <typename T>
void BinTree<T>::displaySideways() const
{
  if (isEmpty())
  {
    cout << "        " << "nullptr";
  }
  else
  {
    Node<T>* nodePtr = root;
    int indentTracker = 2;

    printSidewaysTree(nodePtr, indentTracker);

    nodePtr = nullptr;
  }
  cout << endl;
}

template <typename T>
void BinTree<T>::displayPreorder() const
{
  if (isEmpty())
  {
    cout << "Tree is empty." << endl;
  }
  cout << "BinTree in preorder:" << endl;
  Node<T>* nodePtr = root;
  preorderPrint(nodePtr);
}



/////////////////////////////////// Private / Helper Methods //////////////////////////////////

// ------------------------------------ clearTree ---------------------------------------------
// Description: clears all nodes in the tree except for the root traversing in postorder
// preconditions: node pointer pointing to the root
// postconditions: cleared tree with remaining root node
// --------------------------------------------------------------------------------------------
template <typename T>
void BinTree<T>::clearTree(Node<T>* deletePtr)
{
  if (deletePtr->left != nullptr) // has left
  {
    clearTree(deletePtr->left); // traverse left
  }
  if (deletePtr->right != nullptr) // has right
  {
    clearTree(deletePtr->right); // traverse right
  }
  if (deletePtr != root)
  {
    delete deletePtr;
  }
}

// ---------------------------------- findParentNode ------------------------------------------
// Description: helper function to finds the parent node to getHeight, insert, and retreieve.
//              traverses in preorder to find parent node to the given value and sets the
//              nodePtr in arguments to the found node
// preconditions: value to be found and node pointing to root
// postconditions: node pointing to the parent node of the value
// --------------------------------------------------------------------------------------------
template <typename T>
Node<T>* BinTree<T>::findParentNode(const T* objectPtr, Node<T>*& nodePtr) const
{
  if (objectPtr < nodePtr->data && nodePtr->left != nullptr) // if left branch should be traversed
  {
    return findParentNode(objectPtr, nodePtr->left); // traverse left branch
  }
  if (objectPtr > nodePtr->data && nodePtr->right != nullptr) // if right branch should be traversed
  {
    return findParentNode(objectPtr, nodePtr->right); // traverse right branch
  }
  return nodePtr; // either the branch is nullptr (can be inserted) or current node already exists
}

template <typename T>
int BinTree<T>::iterateAllSimilar(const T* objectPtr, Node<T>*& nodePtr, int*& count) const
{
  // base case
  if (nodePtr->data == nullptr)
  {
    return 0;
  }
  if (objectPtr->isSimilar(nodePtr->data)) // check current node
  {
    count++;
  }
  updateAllSimilar(objectPtr, nodePtr->left, count);
  updateAllSimilar(objectPtr, nodePtr->right, count);
}

// -------------------------------- printSidewaysTree -----------------------------------------
// Description: helper function to displaySideways. prints the tree in sideways format by
//              traversing right, root, then left.
// preconditions: node pointing to root, int to track number of indents needed
// postconditions: visual representation of sideways tree
// --------------------------------------------------------------------------------------------
template <typename T>
void BinTree<T>::printSidewaysTree(Node<T>*& nodePtr, int indentTracker) const
{
  if (nodePtr->right != nullptr)
  {
    printSidewaysTree(nodePtr->right, indentTracker + 1);
  }
  if (nodePtr->data != nullptr)
  {
    for (int i = 0; i < indentTracker; i++)
    {
      cout << "    ";
    }
    cout << nodePtr->data->print();
  }
  if (nodePtr->left != nullptr)
  {
    printSidewaysTree(nodePtr->left, indentTracker + 1);
  }
}

template <typename T>
void BinTree<T>::preorderPrint(Node<T>*& nodePtr) const
{
  if (nodePtr == nullptr)
  {
    return;
  }
  if (nodePtr->left != nullptr)
  {
    preorderPrint(nodePtr->left);
  }
  nodePtr->data->print();
  if (nodePtr->right != nullptr)
  {
    preorderPrint(nodePtr->right);
  }
}

// ---------------------------------- deconstructor -------------------------------------------
// Description: prevents memory loss by deallocating nodes by traversing in postorder
// preconditions: no inputs
// postconditions: cleared binary tree object
// --------------------------------------------------------------------------------------------
template <typename T>
BinTree<T>::~BinTree()
{
  Node<T>* deletePtr = root;
  clearTree(deletePtr);

  delete root;
  root = nullptr;
  deletePtr = nullptr;
}

#endif