#include <iostream>

using namespace std;


class Stack{
  public:
    class Element{
      public:
        char key;
        Element* next;
    };
    Stack();
    ~Stack();
    void push(char key);
    char pop();
    void print();
    int getSize();
    bool task_1(string text);
    void task_2();
  private:
    Element* head;
    int size;
};
