#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int positiveElem(int* arr, const int size){
  int index = 0;
  for (int i = 0; i < size; i++)
    if (arr[i] >= 0){
      index = i;
      break;
    }
  return index;
}

int main(){
  srand(time(nullptr));

  const int size = 10;
  int arr[size]; 

  for (int i = 0; i < size; i++)
    arr[i] = rand() % (10 - -10 + 1) + -10;

  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;

  int positivePos = -1;
  for (int i = 0; i < size; i++){
    positivePos = positiveElem(arr, size);

    if (arr[i] < 0){
      int tmp = arr[positivePos];
      arr[positivePos] = arr[i];
      arr[i] = tmp;
      positivePos = i;
    }
  }

  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;

  return 0;
}
