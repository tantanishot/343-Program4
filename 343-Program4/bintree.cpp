// ------------------------------------------------ bintree.cpp ------------------------------------------------------- 
// Ethan Phonsouk
// CSS 343 - Program 2
// Created: 1/28/2025
// Last Modified: 2/1/2025
// --------------------------------------------------------------------------------------------------------------------
// Purpose:
// Implementation file for bintree.h. Implements binary tree methods, constructors, and deconstructors. Uses private
// helper methods for recursive traversal needed to implement public methods.
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions:
// Overloaded operators: =, ==, !=, and <<
// --------------------------------------------------------------------------------------------------------------------

#include "bintree.h"

// ------------------------------------ operator<< --------------------------------------------
// Description: Overloads << operator for bintree class implementation
// preconditions: ostream and BinTree variables as input
// postconditions: outputs the modification to the ostream variable (tree in inorder format)
// --------------------------------------------------------------------------------------------
ostream &operator<<(ostream &stream, const BinTree &aBinTree)
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
BinTree::BinTree()
{
    root = new Node();
    root->data = "";
    root->left = nullptr;
    root->right = nullptr;
}

// --------------------------------- copy constructor -----------------------------------------
// Description: deep copies another bintree object
// preconditions: existing bintree object
// postconditions: equivalent copy of the given tree
// --------------------------------------------------------------------------------------------
BinTree::BinTree(const BinTree &otherBinTree)
{
    if (root == nullptr) // if object doesnt exisit
    {
        root = new Node();
        root->data = "";
        root->left = nullptr;
        root->right = nullptr;

        if (otherBinTree.isEmpty())
        {
            return;
        }
    }
    else // if tree is populated, clear all and rewrite
    {
        Node *deletePtr = root;
        clearTree(deletePtr);
        root->data = "";
        root->left = nullptr;
        root->right = nullptr;
        deletePtr = nullptr;
        if (otherBinTree.isEmpty())
        {
            return;
        }
    }

    Node *otherPtr = otherBinTree.root;
    preorderCopy(otherPtr);
    otherPtr = nullptr;
}

// -------------------------------------- isEmpty ---------------------------------------------
// Description: checks if the tree is currently empty
// preconditions: no inputs
// postconditions: boolean evaluation of whether of not the tree is empty
// --------------------------------------------------------------------------------------------
bool BinTree::isEmpty() const
{
    return (root->data == "");
}

// ------------------------------------- retrieve ---------------------------------------------
// Description: true when assigns the given node to the location of the found value, otherwise
//              returns false
// preconditions: string value and empty node as input
// postconditions: boolean evaluation of whether or not the node as been found
// --------------------------------------------------------------------------------------------
bool BinTree::retrieve(const string &value, Node *&nodePtr) const
{
    if (isEmpty() || value == "")
    {
        return false;
    }

    nodePtr = root;
    Node *parentNode = findParentNode(value, nodePtr);
    if (parentNode == nullptr)
    {
        return false;
    }

    if (isNumTree()) // comparing number
    {
        if (stod(parentNode->data) == stod(value))
        {
            parentNode = nullptr;
            return true;
        }
        parentNode = nullptr;
        return false;
    }

    if (value == parentNode->data) // comparing string
    {
        parentNode = nullptr;
        return true;
    }
    parentNode = nullptr;
    return false;
}

// -------------------------------------- insert ----------------------------------------------
// Description: inserts the proper location of the value into the binary tree
// preconditions: string value as input
// postconditions: boolean evaluation of whether or not the value as been inserted into the
//                 tree
// --------------------------------------------------------------------------------------------
bool BinTree::insert(const string &value)
{
    bool insertSuccess = false;
    if (value == "")
    {
        return false;
    }

    if (isEmpty()) // insert when tree is empty;
    {
        root->data = value;
        insertSuccess = true;
    }

    Node *nodePtr = root;
    Node *parentNode = findParentNode(value, nodePtr);
    if (parentNode == nullptr)
    {
        nodePtr = nullptr;
        parentNode = nullptr;
        return false;
    }
    if (isNumTree() && !insertSuccess) // comparing as numbers
    {
        if (stod(value) < stod(parentNode->data)) // add in to left branch
        {
            Node *addNode = new Node();
            addNode->data = value;
            addNode->left = nullptr;
            addNode->right = nullptr;

            parentNode->left = addNode;
            insertSuccess = true;
        }
        else if (stod(value) > stod(parentNode->data)) // add in to right branch
        {
            Node *addNode = new Node();
            addNode->data = value;
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
    else if (!insertSuccess) // not number, so compare as strings
    {
        if (value < parentNode->data) // add in to left branch
        {
            Node *addNode = new Node();
            addNode->data = value;
            addNode->left = nullptr;
            addNode->right = nullptr;

            parentNode->left = addNode;
            insertSuccess = true;
        }
        else if (value > parentNode->data) // add in to right branch
        {
            Node *addNode = new Node();
            addNode->data = value;
            addNode->left = nullptr;
            addNode->right = nullptr;

            parentNode->right = addNode;
            insertSuccess = true;
        }
        else // value already exists in tree
        {
            insertSuccess = false;
        }
    }

    nodePtr = nullptr;
    parentNode = nullptr;
    return insertSuccess;
}

// ----------------------------------- displayTree --------------------------------------------
// Description: prints tree in specific format
// preconditions: no inputs
// postconditions: visual representation of bintree
// --------------------------------------------------------------------------------------------
void BinTree::displayTree() const
{
    if (isEmpty())
    {
        cout << "    Root: nullptr";
    }
    else
    {
        cout << "    Root: " << root->data << endl;
        Node *nodePtr = root;
        int indentTracker = 2;

        printTree(nodePtr, indentTracker);

        nodePtr = nullptr;
    }
    cout << endl;
}

// --------------------------------- displaySideways ------------------------------------------
// Description: prints tree in specific format
// preconditions: no inputs
// postconditions: visual representation of bintree
// --------------------------------------------------------------------------------------------
void BinTree::displaySideways() const
{
    if (isEmpty())
    {
        cout << "        " << "nullptr";
    }
    else
    {
        Node *nodePtr = root;
        int indentTracker = 2;

        printSidewaysTree(nodePtr, indentTracker);

        nodePtr = nullptr;
    }
    cout << endl;
}

// ------------------------------------ getHeight --------------------------------------------
// Description: gets the height of the node of a given value in the tree
// preconditions: string value as input
// postconditions: int value of the found node's height, if not found then returns 0
// --------------------------------------------------------------------------------------------
int BinTree::getHeight(const string &value) const
{
    int height;
    if (isEmpty() || value == "")
    {
        height = 0;
    }
    else
    {
        Node *nodePtr = root;
        Node *parentNode = findParentNode(value, nodePtr);
        height = depthOfNode(parentNode);

        nodePtr = nullptr;
        parentNode = nullptr;
    }
    return height;
}

// ------------------------------------ operator= ---------------------------------------------
// Description: Overloads = operator for bintree class implementation
// preconditions: another bintree object as input
// postconditions: sets the binary trees equal to each other
// --------------------------------------------------------------------------------------------
BinTree& BinTree::operator=(const BinTree &otherBinTree)
{
    if (root != nullptr) // if tree is populated, then clear
    {
        Node *deletePtr = root;
        clearTree(deletePtr);

        root->data = "";
        root->left = nullptr;
        root->right = nullptr;
        deletePtr = nullptr;
    }

    Node *otherPtr = otherBinTree.root;
    preorderCopy(otherPtr);

    return *this;
}

// ------------------------------------ operator== --------------------------------------------
// Description: Overloads == operator for bintree class implementation
// preconditions: another bintree object as input
// postconditions: boolean evaluation of whether or not the trees are equal
// --------------------------------------------------------------------------------------------
bool BinTree::operator==(const BinTree &otherBinTree) const
{
    Node *thisPtr = root;
    Node *otherPtr = otherBinTree.root;
    bool isEqual = true;
    bool *equalPtr = &isEqual;
    findDifference(thisPtr, otherPtr, equalPtr);

    thisPtr = nullptr;
    otherPtr = nullptr;
    equalPtr = nullptr;

    return isEqual;
}

// ------------------------------------ operator!= --------------------------------------------
// Description: Overloads != operator for bintree class implementation
// preconditions: another bintree object as input
// postconditions: boolean expression of whether or not the trees are not equal
// --------------------------------------------------------------------------------------------
bool BinTree::operator!=(const BinTree &otherBinTree) const
{
    return !(*this == otherBinTree);
}

// ---------------------------------- bstreeToArray -------------------------------------------
// Description: converts the binary tree to an array and clears the tree
// preconditions: empty array as input
// postconditions: populates the array with trees values inorder
// --------------------------------------------------------------------------------------------
void BinTree::bstreeToArray(string arr[])
{
    if (arr[0].compare("") != 0 || isEmpty()) // array should be empty and and tree populated, exit if not
    {
        return;
    }

    Node *nodePtr = root;
    buildArray(arr, nodePtr);

    nodePtr = root;
    clearTree(nodePtr);

    root->data = "";
    root->left = nullptr;
    root->right = nullptr;
    nodePtr = nullptr;
}

// ---------------------------------- arrayToBSTree -------------------------------------------
// Description: converts array into a balanced binary search tree
// preconditions: sorted array going low to high
// postconditions: repopulates the binary tree to balanced version and empties array
// --------------------------------------------------------------------------------------------
void BinTree::arrayToBSTree(string arr[])
{
    if (!isEmpty() || arr->empty())
    {
        return;
    }

    int nodes = 0;
    for (int i = 0; i < arr[0].size(); i++) // counts values in array
    {
        if (arr[0].at(i) == ' ')
        {
            nodes++;
        }
    }

    vector<string> strings(nodes, "");
    int index = 0;
    for (char c : arr[0]) // create vector to access indexes
    {
        if (c != ' ')
        {
            strings[index].push_back(c);
        }
        else
        {
            index++;
        }
    }

    Node *nodePtr = root;
    int low = 0;
    int high = strings.size() - 1;
    buildBalancedTree(strings, low, high);
    nodePtr = nullptr;

    for (int i = 0; i < arr->size(); i++) // clear array
    {
        arr->insert(i, "");
    }
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

// ------------------------------------ isNumTree ---------------------------------------------
// Description: determines if the tree is a number tree or composed of string values
// preconditions: no inputs
// postconditions: boolean expression of whether or not the tree is a number tree or not
// --------------------------------------------------------------------------------------------
bool BinTree::isNumTree() const
{
    return isdigit(root->data.at(0));
}

// ------------------------------------ printTree ---------------------------------------------
// Description: helper function to displayTree. prints the tree in the given format by
//              traversing inorder
// preconditions: node pointing to root and int to track number of indents needed
// postconditions: visual representation of tree
// --------------------------------------------------------------------------------------------
void BinTree::printTree(Node *&nodePtr, int indentTracker) const
{
    if (nodePtr->left != nullptr)
    {
        for (int i = 0; i < indentTracker; i++)
        {
            cout << "    ";
        }
        cout << "L---" << nodePtr->left->data << endl;
        printTree(nodePtr->left, indentTracker + 1);
    }
    if (nodePtr->right != nullptr)
    {
        for (int i = 0; i < indentTracker; i++)
        {
            cout << "    ";
        }
        cout << "R---" << nodePtr->right->data << endl;
        printTree(nodePtr->right, indentTracker + 1);
    }
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

// ----------------------------------- depthOfNode --------------------------------------------
// Description: helper function to getHeight. gets the height of the node by traversing
//              inorder
// preconditions: node pointing to the node at which the height is desired for
// postconditions: number indicating the height of the node in the tree
// --------------------------------------------------------------------------------------------
int BinTree::depthOfNode(Node *&nodePtr) const
{
    if (nodePtr == nullptr)
    {
        return 0;
    }
    return 1 + max(depthOfNode(nodePtr->left), depthOfNode(nodePtr->right));
}

// ---------------------------------- findDifference-------------------------------------------
// Description: helper function to operator== and !=. finds whether two trees are different
//              using preorder traversal
// preconditions: pointer pointing to both tree's roots and boolean pointer
// postconditions: changes boolean pointer depending on if a difference is found
// --------------------------------------------------------------------------------------------
void BinTree::findDifference(Node *&thisPtr, Node *&otherPtr, bool *&equalPtr) const
{
    if (thisPtr->data.compare(otherPtr->data) == 0 && equalPtr) // compare current nodes
    {
        if ((thisPtr->left == nullptr && otherPtr->left != nullptr)
            || (thisPtr->left != nullptr && otherPtr->left == nullptr)
            || (thisPtr->right == nullptr && otherPtr->right != nullptr)
            || (thisPtr->right != nullptr && otherPtr->right == nullptr)) // when branch divergence isnt the same
        {
            *equalPtr = false;
            return;
        }
        if (thisPtr->left != nullptr && otherPtr->left != nullptr)
        {
            findDifference(thisPtr->left, otherPtr->left, equalPtr);
        }
        if (thisPtr->right != nullptr && otherPtr->right != nullptr)
        {
            findDifference(thisPtr->right, otherPtr->right, equalPtr);
        }
    }
    else
    {
        *equalPtr = false;
    }
}

// ------------------------------------ buildArray --------------------------------------------
// Description: helper function to bstreeToArray. builds array with inorder values from tree
//              by traversing inorder
// preconditions: empty array and node pointing to root
// postconditions: outputs the modification to the ostream variable (tree in inorder format)
// --------------------------------------------------------------------------------------------
void BinTree::buildArray(string arr[], Node *&nodePtr)
{
    if (nodePtr->left != nullptr)
    {
        buildArray(arr, nodePtr->left);
    }

    arr->append(nodePtr->data + " ");

    if (nodePtr->right != nullptr)
    {
        buildArray(arr, nodePtr->right);
    }
}

// -------------------------------- buildBalancedtree -----------------------------------------
// Description: helper function to arrayToBSTree. rebuilds a balanced binary search tree based
//              on sorted vector in order from low to high
// preconditions: sorted vector and starting and end index of vector elements
// postconditions: emptied vector and balanced binary tree
// --------------------------------------------------------------------------------------------
void BinTree::buildBalancedTree(vector<string> arr, int low, int high)
{
    if (low > high || low < 0 || high > arr.size() - 1)
    {
        return;
    }
    
    insert(arr[(low + high) / 2]); // middle array
    buildBalancedTree(arr, low, ((low + high) / 2) - 1); // left side array
    buildBalancedTree(arr, ((low + high) / 2) + 1, high); // right side array
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