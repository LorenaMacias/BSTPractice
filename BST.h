// Minimum implementation of a binary search tree.
// Author: Ryan Shim
// Date: 11-1-2018
#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T value;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
};

template <typename T>
class BinarySearchTree {
    public:
        BinarySearchTree();
        Node<T>* root();
        int size();
        T getMinimum();
        T getMaximum();
        bool insertVal(const T& val);
        void preorderPrint(Node<T>* nodeptr);
        void inorderPrint(Node<T>* nodeptr);
        void postorderPrint(Node<T>* nodeptr);
        T sum();
        T sumRec(Node<T>* nodptr);
        T siize();
        T rsize(Node<T>* p);
    private:
        int size_;
        Node<T>* root_;
};
template <typename T>
T BinarySearchTree<T>::siize(){
  return rsize(root_);
}
template <typename T>
T BinarySearchTree<T>::rsize(Node<T>* p){

   if (p == nullptr) { return 0; }
   return rsize(p->left) + rsize(p->right) + (p->left == nullptr && p->right == nullptr ? 1 : 0);

   /*
  T size;
  if(p == nullptr) return 0;
  size = size + rsize(p->left);
  size = size + rsize(p->right);
  return size;
  */
}

template <typename T>
T BinarySearchTree<T>::sum(){
    return sumRec(root_);
}
template <typename T>
T BinarySearchTree<T>::sumRec(Node<T>* nodeptr){
    if(nodeptr == nullptr)
      return 0;
    return nodeptr->value + sumRec(nodeptr->left) + sumRec(nodeptr->right);
}


// Default constructor
template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
    size_= 0;
    root_ = nullptr;
}

// Returns the maximum in the BST
template <typename T>
T BinarySearchTree<T>::getMinimum() {
    if(root_ == nullptr)
      return 0;
    Node<T>* tmp = root_;
    while(tmp->left != nullptr){
      tmp = tmp->left;
    }
    return tmp->value;
}

// Returns the minimum in the BST
template <typename T>
T BinarySearchTree<T>::getMaximum() {
    if(root_ == nullptr){
      return 0;}
    Node<T>* tmp = root_;
    while(tmp->right != nullptr){
        tmp = tmp->right;
    }
    return tmp->value;
}

// Prints the BST using an preorder traversal.
template <typename T>
void BinarySearchTree<T>::preorderPrint(Node<T>* nodeptr) {
    if(nodeptr == nullptr){
      return;
    }
    cout << nodeptr->value;
    preorderPrint(nodeptr->left);
    preorderPrint(nodeptr->right);
}

// Prints the BST using an inorder traversal.
template <typename T>
void BinarySearchTree<T>::inorderPrint(Node<T>* nodeptr) {
    if(nodeptr == nullptr)
      return;
    inorderPrint(nodeptr->left);
    cout << nodeptr->value;
    inorderPrint(nodeptr->right);
}

// Prints the BST using an postorder traversal.
template <typename T>
void BinarySearchTree<T>::postorderPrint(Node<T>* nodeptr) {
    if(nodeptr == nullptr)
      return;
    postorderPrint(nodeptr->left);
    postorderPrint(nodeptr->right);
    cout << nodeptr->value;
}


/****************************
 * DO NOT CHANGE CODE BELOW *
 ****************************/
// Returns a node pointer to the root_ node
// DO NOT CHANGE
template <typename T>
Node<T>* BinarySearchTree<T>::root() {
    return root_;
}

// Returns the number of elements in the BST
// DO NOT CHANGE
template <typename T>
int BinarySearchTree<T>::size() {
    return size_;
}

// Insert a value in the BST.
// DO NOT CHANGE
template <typename T>
bool BinarySearchTree<T>::insertVal(const T& val) {
    Node<T>* newNode = new Node<T>;
    newNode->value = val;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if (size_ == 0) {
        root_ = newNode;
        size_++;
        return true;
    }

    Node<T>* tmp = root_;

    while (tmp) {
        if (val > tmp->value) {
            if (tmp->right) {
                tmp = tmp->right;
            }
            else {
                tmp->right = newNode;
                size_++;
                return true;
            }
        }
        else if (val < tmp->value) {
            if (tmp->left) {
                tmp = tmp->left;
            }
            else {
                tmp->left = newNode;
                size_++;
                return true;
            }
        }
    }
    return false;
}

#endif
