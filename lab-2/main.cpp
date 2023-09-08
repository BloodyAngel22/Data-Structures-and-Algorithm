#include "logic.h" 

int main(){
	string text = readFile();

	cout << text << endl;
	cout << searchNumbers(text) << endl;

	newModifiedFile();

	return 0;
}
