#include "stack.h"
#include <iostream>

Stack::Stack()
{
  head = nullptr;
  size = 0;
}

Stack::~Stack()
{
  while (head != nullptr)
  {
    Element* tmp = head;
    head = head->next;
    delete tmp;
  }
}

void Stack::push(char key)
{
  Element* new_elem = new Element;
  new_elem->key = key;
  new_elem->next = head;
  head = new_elem;
  size++;
}

char Stack::pop()
{
  if (head == nullptr)
    return 0;
  char tmp = head->key;
  Element* elem = head;
  head = head->next;
  delete elem;
  size--;

  return tmp;
}

void Stack::print()
{
  Element* iterator = head;
  while (iterator != nullptr){
    cout << iterator->key << " ";
    iterator = iterator->next;
  }
  cout << "\n";
}

bool Stack::task_1(string text)
{
  for (int i = 0; i < text.size(); i++)
  {
    if (text[i] == '{' || text[i] == '(' || text[i] == '[')
    {
      push(text[i]);
    }
    if (head != nullptr)
    {
      if ((head->key == '{' && text[i] == '}') || (head->key == '(' && text[i] == ')') || (head->key == '[' && text[i] == ']'))
      {
        pop();
      }
    }
  }
  if (size != 0)
    return false;
  return true;
}
