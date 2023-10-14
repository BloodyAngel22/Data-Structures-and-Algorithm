#include "list.h"

int main(){
  List list, list_2;
  list_2.push(7, 1);
  list_2.push(5, 2);
  list_2.push(12, 1);
  list_2.push(15, 2);
  
  int switcher;
  int key;
  int index;
  int start_index, end_index;
  bool isRunning = 1;
  while (isRunning){
    cout << "\tMenu:\n1 - push\n2 - pop\n3 - sort\n4 - summary list\n5 - get size\n6 - shift element\n7 - create original list\n8 - exit\n";
    cin >> switcher;
      if (switcher == 1){
        cout << "Enter key and index "; cin >> key >> index;
        list.push(key, index);
      }
      else if (switcher == 2){
        list.pop();
        break;
      }
      else if (switcher == 3){
        list.sort();
      }
      else if (switcher == 4){ 
        cout << "Summary = " << list.sum() << endl;
      }
      else if (switcher == 5){
        cout << "size = " << list.getSize() << endl;
      }
      else if (switcher == 6){
        cout << "Enter start index and end index "; cin >> start_index >> end_index;
        list.shiftElement(start_index, end_index);
      }
      else if (switcher == 7){
        List original = list.createList(list_2);
        cout << "original list\n";
        original.print();
      }
      else if (switcher == 8){
        isRunning = 0;
      }
    
    list.print();
  }

  return 0;
}
