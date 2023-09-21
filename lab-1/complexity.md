# Algorithm Complexity

## Algorithm 1
```cpp
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
```

<h4>
The algorithm requires sorting. Without it it will not work correctly.
Algorithm complexity (excluding sorting) O(n).
</h4>

## Algorithm 2
```cpp
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
```
<h4>
Algorithm complexity O(n*n).
At best, the complexity of the algorithm is O(n*n / 2).
In the worst case, the complexity of the algorithm is O(n*n).
</h4>

## Algorithm 3
```cpp
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
```
<h4>
Algorithm complexity O(n).
</h4>
