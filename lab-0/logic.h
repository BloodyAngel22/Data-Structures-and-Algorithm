#include <iostream>
#include <fstream>

using namespace std;

struct Student
{
  int id;
  string surname;
  string name;
  int recNumber; //Record number

  int marks[5];
  string subjects[5] = {
    "Programing",
    "History",
    "OS",
    "Unix",
    "Philosophy"
  };
	float averageMark = 0;
};
extern const int listSize;

void fillStudent(Student* list);
void printInfo(const Student* list);
void maxLength(const Student* list);
void shiftBySpaces(int choice, int length);
void sortBySurname(Student* list);
void sortBySubject(Student* list, const string subject);
void searchBySurname(const Student* list, const string surname);
void averageMarkStudents(Student* list);
void printAvarage(const Student* list);
