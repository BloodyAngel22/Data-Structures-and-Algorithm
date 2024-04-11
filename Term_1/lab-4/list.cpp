#include "list.h"
#include <iostream>

List::List() {
  head = nullptr;
  length = 0;
}

List::~List(){
  while (head != nullptr){
    Elem* tmp = head;
    head = head->next;
    delete tmp;
  }
}

void List::push(int key, int index){ //Вставка элемента после n-го элемента списка
  index--;
  if (index < 0){
    cout << "index must be >= 0" << endl;
    return;
  }
  if (index > length){
    cout << "index must be in range list" << endl;
    return;
  }
  Elem* e = new Elem;
  e->key = key;
  e->next = nullptr;
  if (head == nullptr){
    head = e;
    length++; 
  }
  else {
    int counter = 0;
    Elem* iterator = head;
    while (counter != index){
      if (iterator->next == nullptr)
        break;
      iterator = iterator->next;
      counter++;
    }
    e->next = iterator->next;
    iterator->next = e;
    length++; 
  }
}

void List::pop(){ //удаление из списка каждого 2-го элемента
  if (length < 2){
    cout << "size must be >= 2" << endl;
    return;
  }
  int counter = 1;
  Elem* iterator = head;
  Elem* nextel = nullptr;

  while (iterator != nullptr){
    if (counter % 2 == 0){
      nextel->next = iterator->next;
      delete iterator;
      length--;
      iterator = nextel->next;
    }
    else{
      nextel = iterator;
      iterator = iterator->next;
    }
    counter++;
  }
}

void List::print(){
  if (head == nullptr)
    return;
  Elem* iterator = head;
  while (iterator != nullptr){
    cout << iterator->key << " -> ";
    iterator = iterator->next;
  }
  cout << "\b\b\b   " << endl;
}

void List::sort(){ //размещение элементов списка в возрастающем порядке
  if (length < 2)
    return;
  Elem* iterator = head;
  
  for ( ; iterator!= nullptr; iterator = iterator->next){
    Elem* i = iterator;
    Elem* j = iterator->next;
    while(j != nullptr){
      if (i->key > j->key){
        int tmp = i->key;
        i->key = j->key;
        j->key = tmp;
      }
      j = j->next;
    }
  }
}

int List::sum(){ //вычисление суммы элементов
  if (head == nullptr)
    return 0;
  int sum_list = 0;

  Elem* iterator = head;  
  while (iterator != nullptr){
    sum_list += iterator->key;
    iterator = iterator->next;
  }
  return sum_list;
}

void List::shiftElement(int start_index, int end_index){ //перещение элемента на n позиций вперед
  start_index--;
  if (head == nullptr || length < 2 || end_index <= 0 || start_index < 0 || start_index == length || end_index >= length || start_index + end_index > length) {
    return;
  }
  Elem* cur = head;
  int count = 1;

  if (start_index == 0){
    Elem* nodeToMove = head;
    head = head->next;
    cur = head;
    count = 1;
    if (cur == nullptr)
      return;
    
    for ( ; count < end_index; count++)
      cur = cur->next;

    nodeToMove->next = cur->next;
    cur->next = nodeToMove;
  }
  else { 
    while (count < start_index-1 && cur != nullptr) {
      cur = cur->next;
      count++;
    }
    if (cur == nullptr) {
      return; 
    }

    Elem* nodeToMove = cur->next;
    cur->next = cur->next->next;
    count = 0;

    for ( ; count < end_index; count++)
      cur = cur->next;

    nodeToMove->next = cur->next;
    cur->next = nodeToMove;
  }
}

bool List::find(int key){
  if (head == nullptr)
    return 0;
  Elem* cur = head;
  while (cur != nullptr){
    if (cur->key == key)
      return 1;
    cur = cur->next;
  }
  return 0;
}

List List::createList(List& list_2){ //создание списка содержащего элементы общие для двух других списков
  List tmp; 
  
  Elem* cur = head;
  while (cur != nullptr){
    if (list_2.find(cur->key)){
      //push
      Elem* e = new Elem;
      e->next = nullptr;
      e->key = cur->key;
      if (tmp.head == nullptr){
        tmp.head = e;
        tmp.length ++;
      }
      else{
        Elem* tmpCur = tmp.head;
        while (tmpCur->next != nullptr)
          tmpCur = tmpCur->next;
        e->next = tmpCur->next;
        tmpCur->next = e;
        tmp.length++;
      }
    }
    cur = cur->next;
  }
  return tmp;
}
