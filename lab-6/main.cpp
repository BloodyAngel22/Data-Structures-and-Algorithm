#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void printArr(const int *arr, const int size);
void sort(int *arr, const int size);

int main() {
  srand(time(0));
  int size;
  cout << "Enter size ";
  cin >> size;
  int *arr = new int[size];

  cout << "Enter element array\n";
  for (int i = 0; i < size; i++)
    cin >> arr[i];

  printArr(arr, size);
  sort(arr, size);
  printArr(arr, size);

  delete[] arr;
  return 0;
}

void printArr(const int *arr, const int size) {
  if (size < 1)
    return;
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void sort(int *arr, const int size) {
  for (int i = 0; i < size - 1; i++) {
    int min_elem_index = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[min_elem_index] > arr[j])
        min_elem_index = j;
    }
    if (min_elem_index != i) {
      int temp = arr[i];
      arr[i] = arr[min_elem_index];
      arr[min_elem_index] = temp;
    }
  }
}