#include "avl_tree.h"
#include "binary_tree.h"
#include <chrono>
#include <iostream>

int main() {
  auto size = 10000;
  BinaryTree bin_tree;
  for (auto i = 0; i < size; i++) {
    bin_tree.insert(i + 1);
  }

  auto start = std::chrono::high_resolution_clock::now();
  bin_tree.search(size);
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "Время выполнения функции search для бинарного дерева: " << duration.count() << " микросекунд" << std::endl;

  AVLTree avl_tree;
  for (auto i = 0; i < size; i++) {
    avl_tree.insert(i + 1);
  }

  start = std::chrono::high_resolution_clock::now();
  avl_tree.search(size);
  end = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "Время выполнения функции search для AVL-дерева: " << duration.count() << " микросекунд" << std::endl;

  return 0;
}

