namespace avl{

struct Node{
  int key;
  Node* left, *right;
  int weight = 1;
};

class AVL_tree{
  private:
  Node* root;
  avl::Node* nodeInsert(Node* node, int key);
  void printSortNode(Node* node);
  void printNode(Node* node);
  void nodeClear(Node* node);
  bool nodeFind(Node* node, int key);
  int max(int a, int b);
  int getWeight(Node* node);
  int getHeight(Node* node);
  int getBalance(Node* node);
  Node* rightRotate(Node* y);
  Node* leftRotate(Node* x);
  Node* newNode(int key);
  Node* minNode(Node* node);
  Node* subDeleteNode(Node* root, int key);
  public:
  AVL_tree();
  ~AVL_tree();
  void insert(int key);
  void printSort();
  void print();
  bool find(int key);
  Node* deleteNode(int key);
};

}
