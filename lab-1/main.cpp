#include "logic.h"
#include <iostream>

int main(){
  srand(time(nullptr));
  const int size = 10;
  int arr[size] = {9,7,7,4,1,2,7,3,5,5};
  /* fillArray(arr, size); */
  /* printArray(arr,size); */
  printArray(arr,size);
  
  cout << uniqueElem_2(arr, size) << endl;
  cout << uniqueElem_3(arr, size) << endl;
  cout << uniqueElem_1(arr, size) << endl;

  return 0;
}
