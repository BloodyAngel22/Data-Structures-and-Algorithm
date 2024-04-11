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
  cout << vector[4] << endl;
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

  Vector* vector_2 = new Vector(3);
  vector_2->randomFilling(-10, 15);
  cout << (*vector_2)[4] << endl;

  return 0;
}
