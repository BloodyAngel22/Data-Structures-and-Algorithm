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
  //file >> list[i].patronymic;
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
  //cout << "Patronymic"; shiftBySpaces(3, 9);
  cout << "Record number  ";
  cout << "A B C D E" << endl;
  
  for (int i = 0; i < listSize; i++){
  cout << list[i].id;
  if (list[i].id < 10)
  cout << "   " ;
  else
    cout << "  ";
  cout << list[i].surname; shiftBySpaces(1, list[i].surname.length()); cout << " ";
  cout << list[i].name; shiftBySpaces(2, list[i].name.length()); cout << " ";
  //cout << list[i].patronymic; shiftBySpaces(3, list[i].patronymic.length() / 2); cout << " "; 
  cout << list[i].recNumber << " ";
  cout << "          ";
  for (int j = 0; j < 5; j++)
  cout << list[i].marks[j] << " ";
  cout << endl;
  }
  cout << "A - Programming, B - History, C - OS, D - Unix, E - Philosophy" << endl;
}

void maxLength(const Student* list){
  maxLengthSurname = list[0].surname.length();
  maxLengthName = list[0].name.length();
  //maxLengthPatronymic = list[0].patronymic.length() / 2;
  //cout << maxLengthSurname << " " << maxLengthName << " " << maxLengthPatronymic << endl;
  for (int i = 1; i < listSize; i++){
    if (list[i].surname.length() > maxLengthSurname)
      maxLengthSurname = list[i].surname.length();  
    if (list[i].name.length() > maxLengthName)
      maxLengthName = list[i].name.length();  
    //if (list[i].patronymic.length()/2 > maxLengthPatronymic)
     // maxLengthPatronymic = list[i].patronymic.length() / 2;  
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

void sortBySurname(Student* list){
  for (int i = 0; i < listSize; i++){
    for (int j = 0; j < listSize - 1; j++){
      if (list[j].surname[0] > list[j+1].surname[0]){
        Student tmp = list[j+1];
        list[j+1] = list[j];
        list[j] = tmp;
      }
      if (list[j].surname[0] == list[j+1].surname[0]){
        int minLength = list[j].surname.length();
        if (minLength > list[j+1].surname.length())
          minLength = list[j+1].surname.length();
        bool swaped = 0;
        
        for (int k = 1; k < minLength; k++){
           if (list[j].surname[k] > list[j+1].surname[k]){
//            cout << list[j].surname << " " << list[j+1].surname << endl;
//            cout << list[j].surname[k] << " " << list[j+1].surname[k] << endl;
            Student tmp = list[j+1];
            list[j+1] = list[j];
            list[j] = tmp;
            swaped = 1;
           }
           if (swaped)
            break;
        }
      }
    }
  }
}

void sortBySubject(Student* list, const string subject){
  bool isSubject = 1;
  for (int i = 0; i < listSize; i++){
  for (int j = 0; j < listSize - 1; j++){
    if (subject == "A" || subject == "Programming"){
      if (list[j].marks[0] < list[j+1].marks[0]){
        Student tmp = list[j+1];
        list[j+1] = list[j];
        list[j] = tmp;
      }
    }
    else if (subject == "B" || subject == "History") {
      if (list[j].marks[1] < list[j+1].marks[1]){
        Student tmp = list[j+1];
        list[j+1] = list[j];
        list[j] = tmp;
      }       
    }
    else if (subject == "C" || subject == "OS") {
      if (list[j].marks[2] < list[j+1].marks[2]){
        Student tmp = list[j+1];
        list[j+1] = list[j];
        list[j] = tmp;
      }      
    }
    else if (subject == "D" || subject == "Unix") {
      if (list[j].marks[3] < list[j+1].marks[3]){
        Student tmp = list[j+1];
        list[j+1] = list[j];
        list[j] = tmp;
      }      
    }
    else if (subject == "E" || subject == "Philosophy") {
      if (list[j].marks[4] < list[j+1].marks[4]){
        Student tmp = list[j+1];
        list[j+1] = list[j];
        list[j] = tmp;
      }      
    }
    else{ 
      isSubject = 0;
      break;
    }
  }
    if (!isSubject){
      cout << "This subject isn't in the list" << endl;
      break;
    }
  }
}

void searchBySurname(const Student* list, const string surname){
  cout << "ID  " << "Surname"; shiftBySpaces(1, 6);
  cout << "Name"; shiftBySpaces(2,3);
  cout << "Record number  ";
  cout << "A B C D E" << endl;
  for (int i = 0; i < listSize; i++){
    if (list[i].surname == surname){
     cout << list[i].id;
     if (list[i].id < 10)
        cout << "   " ;
     else
       cout << "  ";
     cout << list[i].surname; shiftBySpaces(1, list[i].surname.length()); cout << " ";
     cout << list[i].name; shiftBySpaces(2, list[i].name.length()); cout << " ";
     cout << list[i].recNumber << " ";
     cout << "          ";
     for (int j = 0; j < 5; j++)
     cout << list[i].marks[j] << " ";
     cout << endl;
    }
  }
}