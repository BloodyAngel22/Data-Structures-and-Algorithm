#include "logic.h"

int maxLengthSurname = 0;
int maxLengthName = 0;
int maxLengthPatronymic = 0;

const int listSize = 10;

void fillStudent(Student* list){
  string fileName = "students.txt";
  ifstream file;
  file.open(fileName);
  if (!file.is_open()){
    cout << "Error! File not found." << endl;
    exit (-1);
  }

  for (int i = 0; i < listSize; i++){
  file >> list[i].id;
  file >> list[i].surname;
  file >> list[i].name;
  file >> list[i].patronymic;
  file >> list[i].recNumber;
  file >> list[i].marks[0];
  file >> list[i].marks[1];
  file >> list[i].marks[2];
  file >> list[i].marks[3];
  file >> list[i].marks[4];
  }
  maxLength(list);
  file.close();
}

void printInfo(const Student* list){
  cout << "-------List------" << endl;
  cout << "ID  " << "Surname"; shiftBySpaces(1, 6);
  cout << "Name"; shiftBySpaces(2,3);
  cout << "Patronymic"; shiftBySpaces(3, 9);
  cout << "Record number  ";
  cout << "A B C D E" << endl;
  
  for (int i = 0; i < listSize; i++){
  cout << list[i].id;
  if (list[i].id < 10)
  cout << "   " ;
  else
    cout << "  ";
  cout << list[i].surname; shiftBySpaces(1, list[i].surname.length() / 2); cout << " ";
  cout << list[i].name; shiftBySpaces(2, list[i].name.length() / 2); cout << " ";
  cout << list[i].patronymic; shiftBySpaces(3, list[i].patronymic.length() / 2); cout << " "; 
  cout << list[i].recNumber << " ";
  cout << "          ";
  for (int j = 0; j < 5; j++)
  cout << list[i].marks[j] << " ";
  cout << endl;
  }
  cout << "A - Programming, B - History, C - OS, D - Unix system, E - Philosophy" << endl;
}

void maxLength(const Student* list){
  maxLengthSurname = list[0].surname.length() / 2;
  maxLengthName = list[0].name.length() / 2;
  maxLengthPatronymic = list[0].patronymic.length() / 2;
  //cout << maxLengthSurname << " " << maxLengthName << " " << maxLengthPatronymic << endl;
  for (int i = 1; i < listSize; i++){
    if (list[i].surname.length()/2 > maxLengthSurname)
      maxLengthSurname = list[i].surname.length() / 2;  
    if (list[i].name.length()/2 > maxLengthName)
      maxLengthName = list[i].name.length() / 2;  
    if (list[i].patronymic.length()/2 > maxLengthPatronymic)
      maxLengthPatronymic = list[i].patronymic.length() / 2;  
  }
  //cout << maxLengthSurname << " " << maxLengthName << " " << maxLengthPatronymic << endl;
}

void shiftBySpaces(int choice, int length){
  int subLength;
  switch (choice)
  {
    case 1:
    subLength = maxLengthSurname - length;
    break;

    case 2: 
    subLength = maxLengthName - length;    
    break;

    case 3:
    subLength = maxLengthPatronymic - length;    
    break;  

    case 4:
    subLength = length + 1;
    break;
  }
  int counter = 0;
  while (counter < subLength + 1){
    counter++;
    cout << " ";
  }
}