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
  file >> list[i].recNumber;
  for (int j = 0; j < 5; j++)
    file >> list[i].marks[j];
  }
  maxLength(list);
  file.close();
}

void printInfo(const Student* list){
  cout << "-------List------" << endl;
  cout << "ID  " << "Surname"; shiftBySpaces(1, 6);
  cout << "Name"; shiftBySpaces(2,3);
  cout << "Record number  ";
  cout << "A B C D E ";
	cout << "Average mark" << endl;
  
  for (int i = 0; i < listSize; i++){
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
	cout << list[i].averageMark;
  cout << endl;
  }
  cout << "A - " << list->subjects[0] <<", B - " << list->subjects[1]\
   << ", C - " << list->subjects[2] << ", D - " << list->subjects[3]\
   <<", E - " << list->subjects[4] << endl;
}

void maxLength(const Student* list){
  maxLengthSurname = list[0].surname.length();
  maxLengthName = list[0].name.length();
  for (int i = 1; i < listSize; i++){
    if (list[i].surname.length() > maxLengthSurname)
      maxLengthSurname = list[i].surname.length();  
    if (list[i].name.length() > maxLengthName)
      maxLengthName = list[i].name.length();  
  }
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
        
        for (int k = 1; k < minLength; k++){
           if (list[j].surname[k] > list[j+1].surname[k]){
            Student tmp = list[j+1];
            list[j+1] = list[j];
            list[j] = tmp;
            break;
           }
           if (list[j].surname[k] < list[j+1].surname[k]){
            break;
           }
        }
      }
    }
  }
}

void sortBySubject(Student* list, const string subject){
  bool isSubject = 1;
  for (int i = 0; i < listSize; i++){
  for (int j = 0; j < listSize - 1; j++){
    if (subject == "A" || subject == list->subjects[0]){
      if (list[j].marks[0] < list[j+1].marks[0]){
        Student tmp = list[j+1];
        list[j+1] = list[j];
        list[j] = tmp;
      }
    }
    else if (subject == "B" || subject == list->subjects[1]) {
      if (list[j].marks[1] < list[j+1].marks[1]){
        Student tmp = list[j+1];
        list[j+1] = list[j];
        list[j] = tmp;
      }       
    }
    else if (subject == "C" || subject == list->subjects[2]) {
      if (list[j].marks[2] < list[j+1].marks[2]){
        Student tmp = list[j+1];
        list[j+1] = list[j];
        list[j] = tmp;
      }      
    }
    else if (subject == "D" || subject == list->subjects[3]) {
      if (list[j].marks[3] < list[j+1].marks[3]){
        Student tmp = list[j+1];
        list[j+1] = list[j];
        list[j] = tmp;
      }      
    }
    else if (subject == "E" || subject == list->subjects[4]) {
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
  int counter = 0;
  for (int i = 0; i < listSize; i++)
    if (list[i].surname != surname)
      counter++;
  if (counter == listSize)
    return;

  cout << "ID  " << "Surname"; shiftBySpaces(1, 6);
  cout << "Name"; shiftBySpaces(2,3);
  cout << "Record number  ";
  cout << "A B C D E";
	cout << "Average mark" << endl;
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

void averageMarkStudents(Student* list){
	for (int i = 0; i < listSize; i++){
		for (int j = 0; j < 5; j++){
			list[i].averageMark += list[i].marks[j];
		}
		list[i].averageMark /= 5;
	}
}

void printAvarage(const Student* list){
  cout << "ID  " << "Surname"; shiftBySpaces(1, 6);
  cout << "Name"; shiftBySpaces(2,3);
  cout << "Record number  ";
  cout << "A B C D E ";
	cout << "Average mark " << endl;
	for (int i = 0; i < listSize; i++){
		if (list[i].averageMark <= 4 && list[i].averageMark >= 3){
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
	cout << list[i].averageMark;
  cout << endl;
		}
	}	
}
