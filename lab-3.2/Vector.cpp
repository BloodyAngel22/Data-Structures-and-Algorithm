#include "Vector.h"

Vector::Vector(int SIZE) : size(SIZE), curSize(0){
  ptr = new int[size];
}

Vector::~Vector(){
  delete[] ptr;
}

int Vector::getSize(){ 
  return size; 
}

int& Vector::operator[] (int index){
  return ptr[index]; 
}

void Vector::printVector(){
  int* cur = begin();
  while (cur != end()){
    cout << *cur++ << " ";
  }
  cout << endl;
}

int* Vector::begin() {
  return ptr;
}

int* Vector::end() {
  return ptr + size; 
}

void Vector::pushBack(int data){
  if (curSize == size) return;
  *(ptr + curSize) = data;
  curSize++;
}

void Vector::fill(int data){
  if (curSize == size) return;
  for (int i = 0; i < size; i++){
    *(ptr + curSize) = data;
    curSize++;
  }
}

bool Vector::find(int data){
  for (int i = 0; i < size; i++)
    if (ptr[i] == data)
      return 1;

  return 0;
}

Vector Vector::merge(Vector& merging){
  int new_size = size + merging.getSize();

  Vector new_vector(new_size);
  for (int i = 0; i < size; i++)
      new_vector.pushBack(ptr[i]);
  for (int i = 0; i < merging.getSize(); i++)
    new_vector.pushBack(merging[i]);

  return new_vector;
}

void Vector::randomFilling(int min, int max){
  for (int i = 0; i < size; i++)
    ptr[i] = rand() % (max - min + 1) + min;
}
