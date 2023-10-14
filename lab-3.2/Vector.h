#include <iostream>

using namespace std;

class Vector{
  public:
    Vector(int SIZE);
    ~Vector();

    int& operator[] (int index);

    int getSize();   
    void printVector();
    int* begin(); 
    int* end(); 
    void pushBack(int data);
    void fill(int data);
    bool find(int data);
    Vector merge(Vector& merging);

    void randomFilling(int min, int max);

  private:
    int* ptr;
    int size;
    int curSize;
};
