#include "avl.h"

  // основной код 
int main()  
{  
    AVLNode *root = NULL;  
   
    // построение дерева AVL
    root = insert(root, 47);  
    root = insert(root, 33);  
    root = insert(root, 30);  
    root = insert(root, 10);  
    root = insert(root, 56);  
    root = insert(root, 86);  
    root = insert(root, 89);  
    root = insert(root, 41);  
    root = insert(root, 23);  
    root = insert(root, 50);  
     
    //Обход по порядку для вышеуказанного дерева : 4 5 8 11 12 17 18 
    cout << "Inorder traversal for the AVL tree is: \n";  
    inOrder(root);  
    cout << endl;
    print(root);
    root = deleteNode(root, 5);  
    cout << "\nInorder traversal after deletion of node 5: \n";  
    inOrder(root);  
    cout << endl;
   
    return 0;  
}
