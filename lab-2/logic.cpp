#include "logic.h"
#include <fstream>
#include <string>

string readFile(){
	string fileName = "text.txt";
	ifstream file;
	file.open(fileName);
	if (!file.is_open()){
		cout << "Error! File not found" << endl;
		exit(-1);
	}

	string text;
	char c;
	while (!file.eof()){
		file.get(c);
		text += c;
	}
	return text;
}

int searchNumbers(string text){
	int sum = 0;
	int number = 0;
	int counter = 0;

	for (int i = 0; i < text.size(); i++){
		if (text[i] >= 48 && text[i] <= 57){
			if (number == 0)
				number = text[i] - 48;
			else
				number = (number * 10 + text[i]) - 48;
			// cout << number << endl;
		}
		else {
			sum += number;
			number = 0;
		}
	}
	return sum;
}

void newModifiedFile(){
	string text;
	text = readFile();
	for (int i = 0; i < text.size(); i++){
	  if (text[i] >= 48 && text[i] <= 57)
			text[i] = '#';
	}
	string fileName = "chagedFile.txt";
	ofstream file;
	file.open(fileName);
	file << text;
}
