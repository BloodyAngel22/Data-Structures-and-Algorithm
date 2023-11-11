#include "avl.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>

using namespace std;

int main(){
  srand(time(0));
  avl::AVL_tree tree; 
  
  /* for (int i = 0; i < 10; i++){ */
  /*   int tmp = rand() % 100 + 1; */
  /*   cout << tmp << " "; */
  /*   tree.insert(tmp); */
  /* } */
  /* cout << endl; */
  tree.insert(47);
  tree.insert(33);
  tree.insert(30);
  tree.insert(10);
  tree.insert(56);
  tree.insert(86);
  tree.insert(89);
  tree.insert(41);
  tree.insert(23);
  tree.insert(50);

  cout << "Sort\n";
  tree.printSort();
  cout << "Std\n";
  tree.print();

  tree.deleteNode(10);
  tree.deleteNode(23);
  tree.printSort();

  return 0;
}
