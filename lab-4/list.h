#include <iostream>

using namespace std;

class Elem{
  public:
    int key;
    Elem* next;
};

class List{
  public:
    List();
    ~List();
    void push(int key, int index);
    void pop();
    void print();
    void sort();
    int sum();
    int getSize() { return length; }
    void shiftElement(int start_index, int end_index);
    bool find(int key);
    List createList(List& list_2);
  private:
    Elem* head;
    int length = 0;
};
