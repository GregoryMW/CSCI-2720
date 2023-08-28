#include <cstddef>
#include <iostream>
#include "BinaryTree.h"

//Constructor
template <class T>
BinaryTree<T>::BinaryTree()
{
  root = NULL;
}

//Destructor
template <class T>
BinaryTree<T>::~BinaryTree()
{
  destructorRec(root);
}

//Recursive destructor helper
template <class T>
void BinaryTree<T>::destructorRec(Node<T> *node)
{
    if (node != NULL)
    {
      destructorRec(node->left);
      destructorRec(node->right);
      delete node;
    }
}

//Insert item
template <class T>
void BinaryTree<T>::insert(T &key)
{
  insertRec(key, root);
}

//Recursive insert helper
template <class T>
void BinaryTree<T>::insertRec(T &key, Node<T>*& node)
{
  if (node == NULL)
    {
      node = new Node<T>;
      node->right = NULL;
      node->left = NULL;
      node->key = key;
    }
  else if (key > node->key)
    {
      insertRec(key, node->right);
    }
  else if (key < node->key)
    {
      insertRec(key, node->left);
    }
  else
    {
      std::cout << "\nItem already in the tree.\n";
    }
}

//Checks to see if the item is in the tree, then deletes appropriately
template <class T>
void BinaryTree<T>::deleteItem(T &key)
{
  bool present = false;
  retrieve(key, present);
  Node<T> *parent = NULL;
  if (present)
    {
      deleteRec(root, parent, key);
    }
  else
    {
      std::cout << "\nItem not in tree." << std::endl;
    }
}

//Recursively goes through the tree until it reaches the desired item to delete
template <class T>
void BinaryTree<T>::deleteRec(Node<T> *node, Node<T> *parent, T &key)
{
  if (key < node->key)
    {
      parent = node;
      deleteRec(node->left, parent, key);
    }
  else if (key > node->key)
    {
      parent = node;
      deleteRec(node->right, parent, key);
    }
  else
    {
      if (parent == NULL)
	parent = node;
      deleteNode(node, parent);
    }
}

//Deletes the desired node and updates the parent node as well
template <class T>
void BinaryTree<T>::deleteNode(Node<T>*& node, Node<T> *parent)
{
  Node<T> *temp = node;
  Node<T> *predNode;
  if (node->left == NULL)
    {
      if (parent->right == node)
	parent->right = node->right;
      else
	parent->left = node->right;
      node = node->right;
      delete temp;
    }
  else if (node->right == NULL)
    {
      if (parent->right == node)
	parent->right = node->left;
      else
	parent->left = node->left;
      node = node->left;
      delete temp;
    }
  else
    {
      getPredecessor(node->left, predNode);
      if (parent->left == node)
	{
	  parent = parent->left;
	}
      else if (parent->right == node)
	{
	  parent = parent->right;
	}
      node->key = predNode->key;
      deleteRec(node->left, parent, predNode->key);
    }
}

//If a node selected for deletion has two child nodes, the predecessor is found to replace the deleted node
template <class T>
void BinaryTree<T>::getPredecessor(Node<T> *node, Node<T>*& predNode)
{
  while (node->right != NULL)
    {
      node = node->right;
    }
  predNode = node;
}

//Retrieveal method
template <class T>
void BinaryTree<T>::retrieve(T &item, bool &found) const
{
  retrieveRec(item, found, root);
}

//If a node with the same key as the given item, sets a boolean in main to true
template <class T>
void BinaryTree<T>::retrieveRec(T &item, bool &found, Node<T> *node) const
{
  if (node != NULL)
    {
      if (node->key == item)
	{
	  found = true;
	}
      retrieveRec(item, found, node->left);
      retrieveRec(item, found, node->right);

    }
}

//Pre-order print method
template <class T>
void BinaryTree<T>::preOrder() const
{
  std::cout << "\nPre-Order: ";
  preOrderRec(root);
  std::cout << std::endl;
}

//Prints based on leading heirarchy
template <class T>
void BinaryTree<T>::preOrderRec(Node<T> *node) const
{
  if (node != NULL)
    {
      std::cout << node->key << " ";
      preOrderRec(node->left);
      preOrderRec(node->right);
    }
}

//In-order print method
template <class T>
void BinaryTree<T>::inOrder() const
{
  std::cout << "\nIn-Order: ";
  inOrderRec(root);
  std::cout << std::endl;
}

//Prints from smallest to largest value
template <class T>
void BinaryTree<T>::inOrderRec(Node<T> *node) const
{
  if (node != NULL)
    {
      inOrderRec(node->left);
      std::cout << node->key << " ";
      inOrderRec(node->right);
    }
}

//Post-order print method
template <class T>
void BinaryTree<T>::postOrder() const
{
  std::cout << "\nPost-Order: ";
  postOrderRec(root);
  std::cout << std::endl;
}

//Prints the backwards heirarchy of the tree
template <class T>
void BinaryTree<T>::postOrderRec(Node<T> *node) const
{
  if (node != NULL)
    {
      postOrderRec(node->left);
      postOrderRec(node->right);
      std::cout << node->key << " ";
    }
}

//Returns the length of the tree
template <class T>
int BinaryTree<T>::getLength() const
{
  return getLengthRec(root);
}

//Recursive helper method
template <class T>
int  BinaryTree<T>::getLengthRec(Node<T> *node) const
{
  if (node == NULL)
    {
      return 0;
    }
  else
    {
      return (getLengthRec(node->left) + 1 + getLengthRec(node->right));
    }
}

//Will return the number of nodes that have only one child
template <class T>
int BinaryTree<T>::getNumSingleParent()
{
  int num = 0;
  parentRec(root, num);
  return num;
}

//Recursive helper, counts every time a node has only one child
template <class T>
void BinaryTree<T>::parentRec(Node<T> *node, int &num)
{
  if (node != NULL)
    {
      if ((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL))
	{
	  num ++;
	}
      parentRec(node->left, num);
      parentRec(node->right, num);
    }
}

//Returns the amount of leaf nodes in the tree
template <class T>
int BinaryTree<T>::getNumLeafNodes()
{
  int num = 0;
  leafRec(root, num);
  return num;
}

//Counts every time a node has no left or right nodes attached to it
template <class T>
void BinaryTree<T>::leafRec(Node<T> *node, int &num)
{
  if (node != NULL)
    {
      if (node->left == NULL && node->right == NULL)
	{
	  num ++;
	}
      leafRec(node->left, num);
      leafRec(node->right, num);
    }
}

//Calculates the sum of all the subtress of a given node
template <class T>
void BinaryTree<T>::getSumOfSubtrees(T &item)
{
  T sum;
  bool found = false;
  Node<T> *nodePtr = new Node<T>;
  subtreeFindNode(root, item, nodePtr, found);
  if (found == false)
    {
      std::cout << "\nItem not in tree." << std::endl;
    }
  else
    {
      Node<T> *parentNode = nodePtr;
      subtreeSum(nodePtr, parentNode, sum);
      std::cout << "\nSum of Subtrees: " << sum << std::endl;
    }
}

//Iteratively searches through the tree to find the given node
template <class T>
void BinaryTree<T>::subtreeFindNode(Node<T> *node, T &item, Node<T>*& nodePtr, bool &found)
{
  nodePtr = node;
  found = false;
  while (nodePtr != NULL && !found)
    {
      if (item < nodePtr->key)
	{
	  nodePtr = nodePtr->left;
	}
      else if (item > nodePtr->key)
	{
	  nodePtr = nodePtr->right;
	}
      else
	{
	  found = true;
	}
    }
}

//Recursively goes through the tree, adding up the values of all the subtrees of the given node
template <class T>
void BinaryTree<T>::subtreeSum(Node<T> *node, Node<T> *parent, T &sum)
{
  if (node != NULL)
    {
      if (node->key == parent->key)
	{
	  subtreeSum(node->left, parent, sum);
	  subtreeSum(node->right, parent, sum);
	}
      else
	{
	  sum += node->key;
	  subtreeSum(node->left, parent, sum);
	  subtreeSum(node->right, parent, sum);
	}
    }
}

template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<std::string>;
