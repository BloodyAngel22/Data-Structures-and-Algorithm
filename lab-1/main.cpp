#include "logic.h"

int main(){
  Student s1[10];
  fillStudent(s1);
  bool isRunning = 1;
  while (isRunning){
    cout << "Enter action number\n1 - print list, 2 - sorting by surname, 3 - sorting by subjects, 4 - search by surname, 5 - exit" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
      printInfo(s1);
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      isRunning = 0;
      break;
    default:
      cout << "You entered an invalid number" << endl;
      break;
    }
  }

  return 0;
}