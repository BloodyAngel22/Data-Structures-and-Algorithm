#include "logic.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main(){
  IndexFile file;
  int M = 1;
  /* cout << "Enter M - shift index: "; */
  /* cin >> M; */
  file.createIndexFile();
  
  file.createMainIndex(M);
  int position;
  for (int i = 0; i < 3; i++){
    cout << "Enter index: ";
    cin >> position; 
    cout << file.findRecordSequential(position, M) << endl;
  }

  cout << "-----------------" << endl;

  for (int i = 0; i < 3; i++){
    cout << "Enter index: ";
    cin >> position; 
    cout << file.findRecordBinary(position) << endl;
  }

  return 0;
}
