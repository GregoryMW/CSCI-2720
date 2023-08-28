#ifndef BINARYTREE_H
#define BINARYTREE_H

template<class T>
struct Node
{
  T key;
  Node<T> *left;
  Node<T> *right;
};

template<class T>
class BinaryTree
{
 public:
  BinaryTree();
  ~BinaryTree();
  void insert(T &key);
  void deleteItem(T &key);
  void retrieve(T &item, bool &found) const;
  void preOrder() const;
  void inOrder() const;
  void postOrder() const;
  int getLength() const;
  int getNumSingleParent();
  int getNumLeafNodes();
  void getSumOfSubtrees(T &item);

  //These are the recursive helper methods that each correspond to one of the methods above
  void destructorRec(Node<T> *node);
  void insertRec(T &key, Node<T>*& temp);
  void deleteRec(Node<T> *node, Node<T> *parent, T &key);
  void deleteNode(Node<T> *& node, Node<T> *parent);
  void getPredecessor(Node<T> *node, Node<T>*& predNode);
  void retrieveRec(T &item, bool &found, Node<T> *node) const;
  void preOrderRec(Node<T> *temp) const;
  void inOrderRec(Node<T> *temp) const;
  void postOrderRec(Node<T> *temp) const;
  int getLengthRec(Node<T> *temp) const;
  void parentRec(Node<T> *node, int &num);
  void leafRec(Node<T> *node, int &num);
  void subtreeFindNode(Node<T> *node, T &item, Node<T>*& nodePtr, bool &found);
  void subtreeSum(Node<T> *node, Node<T> *parent, T &sum);

private:
  Node<T> *root;
};

#endif
