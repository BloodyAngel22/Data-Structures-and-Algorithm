#include "logic.h"
#include <algorithm>
#include <iostream>

void fillArray(int* arr, const int size){
  for (int i = 0; i < size; i++)
    arr[i] = rand() % 50;
}

void printArray(int* arr, const int size){
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void sortArray(int* arr, const int size){
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size - 1; j++)
      if (arr[j] > arr[j+1]){
        int tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
}

int uniqueElem_1(int* arr, const int size){
  cout << "uniqueElem_1" << endl;
  sortArray(arr, size);
  int counter = 0;
  int steps = 0;
  for (int i = 0; i < size; i++){
    if (arr[i] != arr[i-1] && arr[i] != arr[i+1]){
      counter++;
    }
    steps++;
  }
  cout << "Count steps = " << steps << endl;
  return counter;
}

int uniqueElem_2(int* arr, const int size){
  cout << "uniqueElem_2" << endl;
  int counter = 0;
  int steps = 0;
  for (int i = 0; i < size; i++){
    bool isUnique = 1;
    for (int j = 0; j < size; j++){
      steps ++;
      if (i != j && arr[i] == arr[j]){
        isUnique = 0;
        break;
      }
    }
    if (isUnique)
      counter++;
  }
  cout << "Count steps = " << steps << endl;
  return counter;
}

int uniqueElem_3(int* arr, const int size){
  cout << "uniqueElem_3" << endl;
  int counter = 0;
  int steps = 0;
  for(int i = 0; i < size; i++){
    if (count(arr, arr+size, arr[i]) == 1){
      counter++;
    }
    steps++;
  }
  cout << "Count steps = " << steps << endl;
  return counter;
}
