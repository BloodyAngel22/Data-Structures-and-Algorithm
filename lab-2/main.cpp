#include "logic.h" 

int main(){
  string fileName = getFileName();
	string text = readFile(fileName);

	cout << text << endl;
	cout << searchNumbers(text) << endl;

	newModifiedFile(fileName);

	return 0;
}
