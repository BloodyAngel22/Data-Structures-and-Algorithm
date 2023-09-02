#include <iostream>
#include <fstream>

using namespace std;

struct Student
{
  int id;
  string surname;
  string name;
  string patronymic;
  int recNumber; //Record number

  int marks[5];

  enum subjects{
    programming,
    history,
    oc,
    unixSys,
    philosophy
  };
};
extern const int listSize;

void fillStudent(Student* list);
void printInfo(const Student* list);
void maxLength(const Student* list);
void shiftBySpaces(int choice, int length);
void sortBySurname(Student* list);
void sortBySubject(Student* list, const string subject);
void searchBySurname(const Student* list, const string surname);