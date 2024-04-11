#include <iostream>
using namespace std;

struct Bin_Node {
    int key;
    Bin_Node* left;
    Bin_Node* right;
    
    Bin_Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Bin_Node* root;

    Bin_Node* insertRec(Bin_Node* root, int key) {
        if (root == nullptr) {
            return new Bin_Node(key);
        }

        if (key < root->key) {
            root->left = insertRec(root->left, key);
        } else if (key > root->key) {
            root->right = insertRec(root->right, key);
        }

        return root;
    }

    void printRec(Bin_Node* root) {
        if (root != nullptr) {
            printRec(root->left);
            cout << root->key << " ";
            printRec(root->right);
        }
    }

    int counter;
public:
    BinaryTree() : root(nullptr) {}

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
    bool searchRec(Bin_Node* root, int key, int counter){
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
