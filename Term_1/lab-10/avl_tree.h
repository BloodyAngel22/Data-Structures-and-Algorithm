#include <iostream>
using namespace std;

struct AVL_Node {
    int key;
    int height;
    AVL_Node* left;
    AVL_Node* right;

    AVL_Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    AVL_Node* root;

    int getHeight(AVL_Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    int getBalance(AVL_Node* node) {
        if (node == nullptr) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    AVL_Node* rightRotate(AVL_Node* y) {
        AVL_Node* x = y->left;
        AVL_Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    AVL_Node* leftRotate(AVL_Node* x) {
        AVL_Node* y = x->right;
        AVL_Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    AVL_Node* insertRec(AVL_Node* root, int key) {
        if (root == nullptr) {
            return new AVL_Node(key);
        }

        if (key < root->key) {
            root->left = insertRec(root->left, key);
        } else if (key > root->key) {
            root->right = insertRec(root->right, key);
        } else {
            return root; // Duplicate keys are not allowed
        }

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int balance = getBalance(root);

        if (balance > 1 && key < root->left->key) {
            return rightRotate(root);
        }

        if (balance < -1 && key > root->right->key) {
            return leftRotate(root);
        }

        if (balance > 1 && key > root->left->key) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && key < root->right->key) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void printRec(AVL_Node* root) {
        if (root != nullptr) {
            printRec(root->left);
            cout << root->key << " ";
            printRec(root->right);
        }
    }

    int counter;
public:
    AVLTree() : root(nullptr) {}

    void insert(int key) {
        root = insertRec(root, key);
    }

    void print() {
        printRec(root);
        cout << endl;
    }
    bool search(int key){
      counter = 0;
      return searchRec(root, key, counter);
    }
    bool searchRec(AVL_Node* root, int key, int counter){
      if (root == nullptr) 
        return false;

      if (root->key == key){
        cout << "Количество шагов: " << counter << endl;
        return true;
      }
      
      if (key < root->key) 
        return searchRec(root->left, key, counter+1);
      else 
        return searchRec(root->right, key, counter+1);
    }
};
