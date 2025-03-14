#ifndef BINTREE_H
#define BINTREE_H

#include <iostream> //input and output
#include <sstream>
#include <string>
#include <vector>
#include "customer.h"
#include "movie.h"

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
  // Overloaded << : prints BinTree in correct structure
  friend ostream &operator<<(ostream &stream, const BinTree<T> &aBinTree);

public:
  // Constructor
  BinTree();

  // Desctructor
  ~BinTree();

  // required public methods
  bool isEmpty() const; // check if tree is empty

  // assumes user isn't inserting different object types into tree
  bool insert(T* objectPtr); // insert node with the node data

  // so far only for classics
  int findSimilarTitles(T* objectPtr) const;

  void displaySideways() const; // displays the tree sidways

private:
  Node* root; // Points to the root of the BST

  // You can add private methods here
  void ostreamPrint(ostream &stream, Node *&nodePtr) const; // gives ostream an inorder print of the tree
  void clearTree(Node *deletePtr); // removes all nodes except for root using post order traversal
  Node* findParentNode(const string &value, Node *&nodePtr) const; // finds the parent node to the given value by traversing in preorder
  void identifySimilar(Node* objectPtr);
  void printSidewaysTree(Node *&nodePtr, int indentTracker) const; // recursively goes through right, root, left and prints
};

// ------------------------------------ operator<< --------------------------------------------
// Description: Overloads << operator for bintree class implementation
// preconditions: ostream and BinTree variables as input
// postconditions: outputs the modification to the ostream variable (tree in inorder format)
// --------------------------------------------------------------------------------------------
template <typename T>
ostream &operator<<(ostream &stream, const BinTree<T>& aBinTree)
{
  Node *nodePtr = aBinTree.root;
  if (nodePtr == nullptr)
  {
    stream << "nullptr";
  }
  else
  {
    aBinTree.ostreamPrint(stream, nodePtr);
  }

  stream << endl;
  nodePtr = nullptr;

  return stream;
}

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
bool BinTree<T>::insert(T* objectPtr)
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

  Node *nodePtr = root;
  Node *parentNode = findParentNode(objectPtr, nodePtr);
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
      Node *addNode = new Node();
      addNode->data = objectPtr;
      addNode->left = nullptr;
      addNode->right = nullptr;

      parentNode->left = addNode;
      insertSuccess = true;
    }
    else if (objectPtr > parentNode->data) // add in to right branch
    {
      Node *addNode = new Node();
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

// so far only needed for classics
template <typename T>
int BinTree<T>::findSimilarTitles(T* objectPtr) const
{
  // if similar increment by 1
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



/////////////////////////////////// Private / Helper Methods //////////////////////////////////

// ----------------------------------- ostreamPrint -------------------------------------------
// Description: helper method to << operator. recursively traverses the bintree inorder and
//              fills the ostream
// preconditions: ostream and nodePtr starting at the root
// postconditions: filled ostream with tree values in order
// --------------------------------------------------------------------------------------------
void BinTree::ostreamPrint(ostream& stream, Node *&nodePtr) const
{
    if (nodePtr->left == nullptr && nodePtr->right == nullptr)
    {
        stream << nodePtr->data << " ";
        return;
    }

    if (nodePtr->left != nullptr)
    {
        ostreamPrint(stream, nodePtr->left);
    }
    
    stream << nodePtr->data << " ";

    if (nodePtr->right != nullptr)
    {
        ostreamPrint(stream, nodePtr->right);
    }
}

// ------------------------------------ clearTree ---------------------------------------------
// Description: clears all nodes in the tree except for the root traversing in postorder
// preconditions: node pointer pointing to the root
// postconditions: cleared tree with remaining root node
// --------------------------------------------------------------------------------------------
void BinTree::clearTree(Node *deletePtr)
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

// ----------------------------------- preorderCopy -------------------------------------------
// Description: helper function to copy constructor and operator=. traverses in preorder to
//              copy each node in the tree given node pointing to another tree
// preconditions: node pointing to another tree's root
// postconditions: deep copied tree
// --------------------------------------------------------------------------------------------
void BinTree::preorderCopy(Node *&otherPtr)
{
    if (otherPtr != nullptr)
    {
        insert(otherPtr->data);
    }
    
    if (otherPtr->left != nullptr)
    {
        preorderCopy(otherPtr->left);
    }
    
    if (otherPtr->right != nullptr)
    {
        preorderCopy(otherPtr->right);
    }
}

// ---------------------------------- findParentNode ------------------------------------------
// Description: helper function to finds the parent node to getHeight, insert, and retreieve.
//              traverses in preorder to find parent node to the given value and sets the
//              nodePtr in arguments to the found node
// preconditions: value to be found and node pointing to root
// postconditions: node pointing to the parent node of the value
// --------------------------------------------------------------------------------------------
Node *BinTree::findParentNode(const string &value, Node *&nodePtr) const
{
    if (isdigit(value.at(0)) != isNumTree()) // checks if value is same variable data type as tree
    {
        return nullptr;
    }

    if (isNumTree()) // is a number tree and value is a number
    {
        if (stod(value) < stod(nodePtr->data) && nodePtr->left != nullptr) // if left branch should be traversed
        {
            return findParentNode(value, nodePtr->left); // traverse left branch
        }
        if (stod(value) > stod(nodePtr->data) && nodePtr->right != nullptr) // if right branch should be traversed
        {
            return findParentNode(value, nodePtr->right); // traverse right branch
        }
        return nodePtr; // either the branch is nullptr (can be inserted) or current node already exists
    }
    // for non number values
    if (value < nodePtr->data && nodePtr->left != nullptr) // if left branch should be traversed
    {
        return findParentNode(value, nodePtr->left); // traverse left branch
    }
    if (value > nodePtr->data && nodePtr->right != nullptr) // if right branch should be traversed
    {
        return findParentNode(value, nodePtr->right); // traverse right branch
    }
    return nodePtr; // left/right branch is nullptr (can be inserted) or current node already exists
}

// -------------------------------- printSidewaysTree -----------------------------------------
// Description: helper function to displaySideways. prints the tree in sideways format by
//              traversing right, root, then left.
// preconditions: node pointing to root, int to track number of indents needed
// postconditions: visual representation of sideways tree
// --------------------------------------------------------------------------------------------
void BinTree::printSidewaysTree(Node *&nodePtr, int indentTracker) const
{
    if (nodePtr->right != nullptr)
    {
        printSidewaysTree(nodePtr->right, indentTracker + 1);
    }
    if (nodePtr->data.compare("") != 0)
    {
        for (int i = 0; i < indentTracker; i++)
        {
            cout << "    ";
        }
        cout << nodePtr->data << endl;
    }
    if (nodePtr->left != nullptr)
    {
        printSidewaysTree(nodePtr->left, indentTracker + 1);
    }
}

// ---------------------------------- deconstructor -------------------------------------------
// Description: prevents memory loss by deallocating nodes by traversing in postorder
// preconditions: no inputs
// postconditions: cleared binary tree object
// --------------------------------------------------------------------------------------------
BinTree::~BinTree()
{
    Node *deletePtr = root;
    clearTree(deletePtr);

    delete root;
    root = nullptr;
    deletePtr = nullptr;
}

#endif