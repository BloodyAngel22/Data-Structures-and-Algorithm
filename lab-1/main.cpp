#include "logic.h"
#include <iostream>

int main(){
  srand(time(nullptr));
  const int size = 30;
  /* int arr[size] = {5,1,5,1,8,3,4,4,3,1}; */
  int arr[size];
  fillArray(arr, size);
  /* printArray(arr,size); */
  
  cout << uniqueElem_2(arr, size) << endl;
  cout << uniqueElem_3(arr, size) << endl;
  cout << uniqueElem_1(arr, size) << endl;

  return 0;
}
