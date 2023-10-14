#include "Vector.h"
#include <algorithm>

//4.7

int main(){
  srand(time(NULL));  

  int size;
  cout << "Enter size vector "; cin >> size;
  Vector vector(size);
  vector.randomFilling(-10, 10);
  cout << vector[3] << endl;
  vector[1] = 30;
  vector.printVector();
  cout << vector.find(3) << " " << vector.find(-7) << endl;
  sort(vector.begin(), vector.end());
  vector.printVector();

  cout << "Enter size vector "; cin >> size;
  Vector tmp(size);
  tmp.randomFilling(50, 150);
  tmp.printVector();

  Vector v = vector.merge(tmp);
  v.printVector();

  return 0;
}
