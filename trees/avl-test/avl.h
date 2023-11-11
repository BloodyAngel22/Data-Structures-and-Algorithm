// Программа на C++ для дерева AVL  
#include<iostream> 
using namespace std; 
   
// Узел дерева AVL 
class AVLNode  
{  
    public: 
    int key;  
    AVLNode *left;  
    AVLNode *right;  
    int depth;  
};  
   
//получить максимум два целых числа 
int max(int a, int b){
    return (a > b) ? a : b;
}  
   
//функция для получения высоты дерева
int depth(AVLNode *n)  
{  
    if (n == NULL)  
        return 0;  
    return n->depth;  
}  
// выделите новый узел с переданным ключом
AVLNode* newNode(int key)  
{  
    AVLNode* node = new AVLNode(); 
    node->key = key;  
    node->left = NULL;  
    node->right = NULL;  
    node->depth = 1; // новый узел добавлен как лист
    return(node);  
}  
// поверните вправо поддерево с корнем y
AVLNode *rightRotate(AVLNode *y)  
{  
    AVLNode *x = y->left;  
    AVLNode *T2 = x->right;  
   
    // Выполнить вращение 
    x->right = y;  
    y->left = T2;  
   
    // Высоты обновления  
    y->depth = max(depth(y->left),  
                    depth(y->right)) + 1;  
    x->depth = max(depth(x->left),  
                    depth(x->right)) + 1;  
   
    // Вернуть новый корень 
    return x;  
}  
   
// поворот влево дочернего дерева с корнем x 
AVLNode *leftRotate(AVLNode *x)  
{   
    AVLNode *y = x->right;  
    AVLNode *T2 = y->left;  
   
    // Выполнить вращение 
    y->left = x;  
    x->right = T2;  
    // Высоты обновления
    x->depth = max(depth(x->left),  
                    depth(x->right)) + 1;  
    y->depth = max(depth(y->left),  
                    depth(y->right)) + 1;  
   
    // Вернуть новый корень  
    return y;  
}  
   
// Получить коэффициент баланса узла N 
int getBalance(AVLNode *N)  
{  
    if (N == NULL)  
        return 0;  
    return depth(N->left) -  
           depth(N->right);  
}    
//операция вставки для узла в дереве AVL
AVLNode* insert(AVLNode* node, int key)  {  
    //вращение по BST
    if (node == NULL)  
        return(newNode(key));  
   
    if (key < node->key)  
        node->left = insert(node->left, key);  
    else if (key > node->key)  
        node->right = insert(node->right, key);  
    else // Одинаковые ключи не допускаются  
        return node;  
   
    //обновить высоту узла-предка
    node->depth = 1 + max(depth(node->left),  depth(node->right));  
   
    int balance = getBalance(node);        //получить коэффициент баланса
   
    // вращать, если несбалансирован
   
    // Лево лево
    if (balance > 1 && key < node->left->key)  
        return rightRotate(node);  
   
    // Право право
    if (balance < -1 && key > node->right->key)  
        return leftRotate(node);  
  // Лево право
    if (balance > 1 && key > node->left->key)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
   
    // Право лево  
    if (balance < -1 && key < node->right->key)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
    return node;  
}  
   
// найти узел с минимальным значением 
AVLNode * minValueNode(AVLNode* node)  
{  
    AVLNode* current = node;  
   
    // найти крайний левый лист */
    while (current->left != NULL)  
        current = current->left;  
   
    return current;  
}  
// удалить узел из дерева AVL с заданным ключом  
AVLNode* deleteNode(AVLNode* root, int key)  
{  
    if (root == NULL)  
        return root;  
   
    //удалить по BST 
    if ( key < root->key )  
        root->left = deleteNode(root->left, key);  
   
    else if( key > root->key )  
        root->right = deleteNode(root->right, key);  
   
else
    {  
        // узел только с одним дочерним элементом или без дочернего элемента  
        if( (root->left == NULL) || 
            (root->right == NULL) )  
        {  
            AVLNode *temp = root->left ?  
                         root->left :  
                         root->right;  
   
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else   
            *root = *temp;   
            free(temp);  
        }  
   else
        {  
            AVLNode* temp = minValueNode(root->right);  
   
            root->key = temp->key;  
   
            // Удалить преемника по порядку 
            root->right = deleteNode(root->right,  
                                     temp->key);  
        }  
    }  
   
    if (root == NULL)  
    return root;  
   
    // глубина обновления  
    root->depth = 1 + max(depth(root->left),  
                           depth(root->right));  
   
    // получить коэффициент баланса 
    int balance = getBalance(root);  
   
    //повернуть дерево, если оно несбалансировано
   
    // Лево лево  
    if (balance > 1 &&  
        getBalance(root->left) >= 0)  
        return rightRotate(root);  
   
    // Лево право  
    if (balance > 1 &&  getBalance(root->left) < 0)  {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
    // Право право  
    if (balance < -1 &&  getBalance(root->right) <= 0)  
        return leftRotate(root);  
   
    // Право лево  
    if (balance < -1 && getBalance(root->right) > 0)   {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
    return root;  
}  
// печатает обход дерева AVL по порядку
void inOrder(AVLNode *root)  
{  
    if(root != NULL)  
    {  
        inOrder(root->left);
        cout << root->key << " ";  
        inOrder(root->right);  
    }  
}  
void printNode(AVLNode* node);
void print(AVLNode* root)
{
  printNode(root);
  cout << endl;
}

void printNode(AVLNode* node)
{
  if (!node) return;

  cout << node->key << ": ";
  if (node->left != nullptr)
    cout << node->left->key << " ";
  if (node->right != nullptr)
    cout << node->right->key;
  cout << ", ";

  printNode(node->left);
  printNode(node->right);
}
