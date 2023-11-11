#include "avl.h"
#include <iostream>
#include <variant>

using namespace std;

avl::AVL_tree::AVL_tree(){
  root = nullptr;
}

avl::AVL_tree::~AVL_tree()
{
  cout << "Destruction\n";
  nodeClear(root);
}

void avl::AVL_tree::nodeClear(Node* node){
  if (!node) return;

  nodeClear(node->left);
  delete node;
  nodeClear(node->right);
}

avl::Node* avl::AVL_tree::newNode(int key)
{
  Node* new_node = new Node;
  new_node->key = key;
  new_node->left = new_node->right = nullptr;
  new_node->weight = 1;
  return new_node;
}

void avl::AVL_tree::insert(int key)
{
  root = nodeInsert(root, key);
}

avl::Node* avl::AVL_tree::nodeInsert(Node* node, int key){
  if (!node){
    return newNode(key);
  }
  if (key < node->key)
    node->left = nodeInsert(node->left, key);
  else if (key > node->key)
    node->right = nodeInsert(node->right, key);
  else {
    /* delete new_node; */
    return node;
  }

  node->weight = 1 + max(getWeight(node->left), getWeight(node->right));
  int balance = getBalance(node);
  
  if (balance > 1 && key < node->left->key)
    return rightRotate(node);
  
  if (balance < -1 && key > node->right->key)
    return leftRotate(node);
  
  if (balance > 1 && key > node->left->key){
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }
  if (balance < -1 && key < node->right->key){
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }
  return node;
}

void avl::AVL_tree::printSort()
{
  printSortNode(root);
  cout << endl;
}

void avl::AVL_tree::printSortNode(Node* node){
  if (!node){
    return;
  } 

  printSortNode(node->left);
  cout << node->key << " ";
  printSortNode(node->right);
}

bool avl::AVL_tree::find(int key)
{
  return nodeFind(root, key); 
}

bool avl::AVL_tree::nodeFind(Node* node, int key)
{
  if (!node) return 0;

  if (node->key == key) return true;
  
  if (key < node->key)
    return nodeFind(node->left, key);
  else
    return nodeFind(node->right, key);
}

void avl::AVL_tree::print()
{
  printNode(root);
  cout << endl;
}

void avl::AVL_tree::printNode(Node* node)
{
  if (!node) return;

  cout << node->key << " | " << node->weight << ": ";
  if (node->left != nullptr)
    cout << node->left->key << " ";
  if (node->right != nullptr)
    cout << node->right->key;
  cout << ", ";

  printNode(node->left);
  printNode(node->right);
}

int avl::AVL_tree::max(int a, int b)
{
  if (a > b) return a;
  return b;
}

int avl::AVL_tree::getWeight(Node* node)
{
  if (!node) return 0;
  return node->weight;
}

int avl::AVL_tree::getBalance(Node* node)
{
  if (!node) return 0;
  return getWeight(node->left) - getWeight(node->right);
}

avl::Node* avl::AVL_tree::rightRotate(Node* y)
{
  Node* x = y->left;
  Node* z = x->right;

  x->right = y;
  y->left = z;

  y->weight = max(getWeight(y->left), getWeight(y->right)) + 1;
  x->weight = max(getWeight(x->left), getWeight(x->right)) + 1;

  return x;
}

avl::Node* avl::AVL_tree::leftRotate(Node* x)
{
  Node* new_root = x->right;
  Node* temp = new_root->left;

  new_root->left = x;
  x->right = temp;
  
  x->weight = max(getWeight(x->left), getWeight(x->right)) + 1;
  new_root->weight = max(getWeight(new_root->left), getWeight(new_root->right)) + 1;

  return new_root;
}

int avl::AVL_tree::getHeight(Node* node)
{
  if (!node) return 0;
  return max(getHeight(node->left), getHeight(node->right)) + 1;
}

//TODO : fix
avl::Node* avl::AVL_tree::deleteNode(int key)
{
  root = subDeleteNode(root, key);
  return root;
}

avl::Node* avl::AVL_tree::subDeleteNode(Node* root, int key)
{
  if (root == NULL)  
    return root;  
  if ( key < root->key )  
    root->left = subDeleteNode(root->left,key);  

  else if( key > root->key )  
    root->right = subDeleteNode(root->right, key);  

  else
  {  
    if( (root->left == NULL) || (root->right == NULL) )  {  
      Node *temp = root->left ? root->left : root->right;  

      if (temp == NULL) {  
        temp = root;  
        root = NULL;  
      }  
      else   
        *root = *temp;   
      delete temp;  
    }  
    else
    {  
      Node* temp = minNode(root->right);  

      root->key = temp->key;  

      root->right = subDeleteNode(root->right, temp->key);  
    }  
  }  

  if (root == NULL)  
    return root;  

  root->weight = 1 + max(getWeight(root->left),  
      getWeight(root->right));  

  // получить коэффициент баланса 
  int balance = getBalance(root);  

  //повернуть дерево, если оно несбалансировано

  // Лево лево  
  if (balance > 1 && getBalance(root->left) >= 0)  
    return rightRotate(root);  

  // Лево право  
  if (balance > 1 && getBalance(root->left) < 0)  {  
    root->left = leftRotate(root->left);  
    return rightRotate(root);  
  }  
  // Право право  
  if (balance < -1 && getBalance(root->right) <= 0)  
    return leftRotate(root);  

  // Право лево  
  if (balance < -1 && getBalance(root->right) > 0)   {  
    root->right = rightRotate(root->right);  
    return leftRotate(root);  
  }  
  return root;  
}

avl::Node* avl::AVL_tree::minNode(Node* node)
{
  Node* cur = node;
  
  while (cur->left != nullptr){
    cur = cur->left;
  }
  return cur;
}
