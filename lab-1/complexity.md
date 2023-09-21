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

<div>
The algorithm requires sorting. Without it it will not work correctly.
<br>
Algorithm complexity (excluding sorting) O(n).
</div>

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

<div>
Algorithm complexity O(n*n).
<br>
At best, the complexity of the algorithm is O(n*n / 2).
<br>
In the worst case, the complexity of the algorithm is O(n*n).
</div>

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

<div>
Algorithm complexity O(n).
</div>
