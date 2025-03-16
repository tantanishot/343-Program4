#ifndef BINTREE_H
#define BINTREE_H

#include <string>
#include <vector>
#include "hash_table.h"
#include "customer.h"
#include "movie.h"
#include "classics.h"
#include "iomanip"

using std::right;

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
    bool insert(T* objectPtr); // insert node with the node data

    bool hasObject(const T* objectPtr) const;

    // so far only for classics
    int findNumSimilarTitles(T* objectPtr) const;

    void displaySideways() const; // displays the tree sidways

    void displayInorder(HashTable<T>* table);

  private:
    Node<T>* root; // Points to the root of the BST

    // You can add private methods here
    void clearTree(Node<T>* deletePtr); // removes all nodes except for root using post order traversal
    Node<T>* findParentNode(const T* objectPtr, Node<T>*& nodePtr) const; // finds the parent node to the given value by traversing in preorder
    int iterateAllSimilar(T* objectPtr, Node<T>*& nodePtr, int*& count) const; // inorder traverses and counts all similar objects
    void printSidewaysTree(Node<T>*& nodePtr, int indentTracker) const; // recursively goes through right, root, left and prints
    void inorderPrint(Node<T>*& nodePtr, vector<Movie*>*& seenMovies, HashTable<T>* table);
};

// ------------------------------------ constructor -------------------------------------------
// Description: Default constructor for BinTree class
// preconditions: no inputs
// postconditions: BinTree with an empty node as root
// --------------------------------------------------------------------------------------------
template <typename T>
BinTree<T>::BinTree()
{
  root = new Node<T>();
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
    //kinda reverted backk to the old version since yours got a littel confusing
    if (objectPtr == nullptr)
    {
      return false;
    }

    Node<T>* newNode = new Node<T>();
    newNode->data = objectPtr;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if (isEmpty())
    {
      root = newNode;
      return true;
    }

    Node<T>* current = root;
    Node<T>* parent = nullptr;


    //tried dereferencing approach which is better
    //since its bad practice to compare with pointers
    while (current != nullptr)
    {
        parent = current;
        if (*objectPtr < *(current->data))
        {
          current = current->left;
        }
        else if (*objectPtr > *(current->data))
        {
          current = current->right;
        }
        else
        {
          delete newNode;
          return false; // Duplicate found
        }
    }
      if (*objectPtr < *(parent->data))
      {
        parent->left = newNode;
      }
      else
      {
        parent->right = newNode;
      }
    return true;
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
int BinTree<T>::findNumSimilarTitles(T* objectPtr) const
{
  if (objectPtr == nullptr)
  {
    return -1;
  }

  Node<T>* nodePtr = root;
  //  //Was getting a segmentation fault here using the gdb debugger
  //it rooted it here 
  //the problem here is how is set to a nullptr
  //"In C and C++, an integer constant expression with the value 0, when used as a pointer, is also a null pointer"
  //int* i = 0;
  int i = 0; 
  int* countPtr = &i;
  int count = iterateAllSimilar(objectPtr, nodePtr, countPtr);
  countPtr = nullptr;
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
void BinTree<T>::displayInorder(HashTable<T>* table)
{
  if (isEmpty())
  {
    cout << "Tree is empty." << endl;
  }
  cout << "----------------------------------------------------------------------------------------------" << endl;
  Node<T>* nodePtr = root;
  if (nodePtr->data->getCode().compare("C") == 0)
  {
    cout << "Classics:" << endl;
    cout << setw(8) << left << "Genre" << setw(8) << left << "Media" << setw(35) << left << "Title" << setw(22) << left <<
            "Director" << setw(10) << left << "Month" << setw(8) << left << "Year" << "Stock" << endl;
  }
  else if (nodePtr->data->getCode().compare("D") == 0)
  {
    cout << "Dramas:" << endl;
    cout << setw(8) << left << "Genre" << setw(8) << left << "Media" << setw(35) << left << "Title" << setw(22) << left <<
            "Director" << setw(18) << left << "Year" << "Stock" << endl;
  }
  else if (nodePtr->data->getCode().compare("F") == 0)
  {
    cout << "Comedy:" << endl;
    cout << setw(8) << left << "Genre" << setw(8) << left << "Media" << setw(35) << left << "Title" << setw(22) << left <<
            "Director" << setw(18) << left << "Year" << "Stock" << endl;
  }
  vector<Movie*>* seenMovies = new vector<Movie*>();
  inorderPrint(nodePtr, seenMovies, table);
  cout << "----------------------------------------------------------------------------------------------" << endl;
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
int BinTree<T>::iterateAllSimilar(T* objectPtr, Node<T>*& nodePtr, int*& count) const
{
  // base case
  //stop when the node pointer is null
  if (nodePtr == nullptr || nodePtr->data == nullptr) // Add this check
  {
      return 0;
  }

  Classics* classicPtr = dynamic_cast<Classics*>(objectPtr);
  Classics* nodeClassicPtr = dynamic_cast<Classics*>(nodePtr->data);

  if (classicPtr != nullptr && nodeClassicPtr != nullptr) {
      if (classicPtr->isSimilar(nodeClassicPtr)) { // check current node
          (*count)++;
      }
  }
  
  /*
    if (objectPtr->isSimilar(nodePtr->data)) // check current node
  {
    //correctly updates the count
    count++;
  }
  */
 //did you mean iterateAllSimilar?
  //updateAllSimilar(objectPtr, nodePtr->left, count);
  //updateAllSimilar(objectPtr, nodePtr->right, count);

  iterateAllSimilar(objectPtr, nodePtr->left, count);
  iterateAllSimilar(objectPtr, nodePtr->right, count);


  return *count; //Returns the final count
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
    //data is a a void so its not a string
    nodePtr->data->print();
  }
  if (nodePtr->left != nullptr)
  {
    printSidewaysTree(nodePtr->left, indentTracker + 1);
  }
}

template <typename T>
void BinTree<T>::inorderPrint(Node<T>*& nodePtr, vector<Movie*>*& seenMovies, HashTable<T>* table)
{
  if (nodePtr == nullptr)
  {
    return;
  }
  if (nodePtr->left != nullptr)
  {
    inorderPrint(nodePtr->left, seenMovies, table);
  }

  if (nodePtr->data->getCode().compare("C") == 0)
  {
    int numSimilar = findNumSimilarTitles(nodePtr->data);
    if (numSimilar > 0)
    {
      // if not in seenMovies:
        // iterate through hash until all similar titles found
          // print all of their stocks and main actor names
        // add any to vector seenMovies
      bool seen = false;
      Classics* newNodePtr = dynamic_cast <Classics*>(nodePtr->data);
      cout << "test 1" << endl;////////////////////////////////////////////////////////////////////
      if (!seenMovies->empty())
      {
        for (int i = 0; i < seenMovies->size(); i++)
        {
          Classics* cPtr = dynamic_cast <Classics*>(seenMovies->at(i));
          if (cPtr->isSimilar(newNodePtr))
          {
            seen = true;
            i = seenMovies->size() + 1;
          }
        }
      }
      cout << "test 2" << endl;
      if (!seen)
      {
        newNodePtr->print();
        cout << setw(75) << newNodePtr->getMA() << "---------------" << setw(3) << to_string(newNodePtr->getStock()) << endl;
        int count = 0;
        while (count < numSimilar)
        {
          Classics* classicsPtr = dynamic_cast<Classics*>(table->atIndex(table->getStringIndex(newNodePtr->formatSortCriteria(), count)));
          if (classicsPtr != nullptr && classicsPtr->isSimilar(newNodePtr))
          {
            cout << setw(75) << classicsPtr->getMA() << "---------------" << setw(3) << right << to_string(classicsPtr->getStock()) << endl;
            count++;
          }
        }
        seenMovies->push_back(newNodePtr);
      }
      else
      {
        newNodePtr->print();
      }
    }
    else
    {
      nodePtr->data->print();
    }
  }
  else
  {
    nodePtr->data->print();
  }

  if (nodePtr->right != nullptr)
  {
    inorderPrint(nodePtr->right, seenMovies, table);
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