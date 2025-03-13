// ------------------------------------------------- bintree.h -------------------------------------------------------- 
// Ethan Phonsouk
// CSS 343 - Program 2
// Created: 1/28/2025
// Last Modified: 2/1/2025
// --------------------------------------------------------------------------------------------------------------------
// Purpose:
// Header file to bintree.cpp. Uses nodes to form binary searchable trees. Added private helper methods to original
// file
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions:
// No remove method.
// --------------------------------------------------------------------------------------------------------------------
#ifndef BINTREE_H
#define BINTREE_H

#include <iostream> //input and output
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int ARRAYSIZE = 100;

// BST Node contains pointer for left, right, and data
struct Node
{
  string data;
  Node *left;
  Node *right;
};

class BinTree
{
  // Overloaded << : prints BinTree in correct structure
  friend ostream &operator<<(ostream &stream, const BinTree &aBinTree);

public:
  // Constructors
  BinTree();
  BinTree(const BinTree &otherBinTree);

  // Desctructor
  ~BinTree();

  // required public methods
  bool isEmpty() const; // check if tree is empty

  // retrieve the pointer of the node of given data
  bool retrieve(const string &value, Node *&nodePtr) const;

  bool insert(const string &value); // insert node with the node data

  // displays the tree in pre-order, provide prefix (Root, L--, R--)
  void displayTree() const;

  void displaySideways() const; // displays the tree sidways

  // get height of a node starting from leaf (= 1)
  int getHeight(const string &value) const;

  // Overload operators
  // -- Assignment Operator
  BinTree &operator=(const BinTree &otherBinTree); // this = rhs
  // -- Comparison Operators
  bool operator==(const BinTree &otherBinTree) const; // this == rhs
  bool operator!=(const BinTree &otherBinTree) const; // this != rhs

  // Miscellaneous Functions
  void bstreeToArray(string arr[]);
  void arrayToBSTree(string arr[]);

private:
  Node *root; // Points to the root of the BST

  // You can add private methods here
  void ostreamPrint(ostream &stream, Node *&nodePtr) const; // gives ostream an inorder print of the tree
  void clearTree(Node *deletePtr); // removes all nodes except for root using post order traversal
  void preorderCopy(Node *&otherPtr); // deep copies another binary tree using preorder
  Node *findParentNode(const string &value, Node *&nodePtr) const; // finds the parent node to the given value by traversing in preorder
  bool isNumTree() const; // determines whether the tree is made up of numbers or strings (for comparison)
  void printTree(Node *&nodePtr, int indentTracker) const; // iterates through tree recursively using preorder and prints
  void printSidewaysTree(Node *&nodePtr, int indentTracker) const; // recursively goes through right, root, left and prints
  int depthOfNode(Node *&nodePtr) const; // finds the height of the node given a value using 
  void findDifference(Node *&thisPtr, Node *&otherPtr, bool *&equalPtr) const; // traverses inorder to find where tree is different
  void buildArray(string arr[], Node *&nodePtr); // builds array inorder
  void buildBalancedTree(vector<string> arr, int low, int high); // builds a balanced tree given array using inorder traversal in array
};

#endif