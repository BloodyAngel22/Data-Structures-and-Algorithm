#include "logic.h"

int main(){
  Student list[10];
  fillStudent(list);
  bool isRunning = 1;
  while (isRunning){
    cout << "Enter action number\n1 - print list, 2 - sorting by surname, 3 - sorting by subject, 4 - search by surname, 5 - exit" << endl;
    int choice;
    string subject;
    string surname;
    cin >> choice;
    switch (choice)
    {
    case 1:
      printInfo(list);
      break;
    case 2:
      sortBySurname(list);
      break;
    case 3:
      sortBySurname(list);
      cout << "Enter the subject by which grades are to be sorted" << endl;
      cin >> subject;
      sortBySubject(list, subject);
      break;
    case 4:
      cout << "Enter the surname by which you want to find a student" << endl;
      cin >> surname;
      searchBySurname(list, surname);
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