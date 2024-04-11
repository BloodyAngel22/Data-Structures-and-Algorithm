#include "logic.h"

string getFileName(){
	string defFileName = "text.txt";
  string fileName;
  cout << "Enter file name (enter d for text.txt)" << endl;
  cin >> fileName;
  if (fileName == "d")
    fileName = defFileName;
  return fileName;
}

string readFile(string fileName){

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

void newModifiedFile(string fileName){
	string text;
	text = readFile(fileName);
	for (int i = 0; i < text.size(); i++){
	  if (text[i] >= 48 && text[i] <= 57)
			text[i] = '#';
	}
  string modifiedStr;
  for(int i = 0; i < text.size(); i++){
      if ((text[i] == ' ' && text[i+1] != ' ') || text[i] != ' ')
        if ((text[i] == '\n' && text[i+1] != '\n') || text[i] != '\n')
          modifiedStr += text[i];
  }

	string fileNameOut = setFileName();
	ofstream file;
	file.open(fileNameOut);
	file << modifiedStr;
}

string setFileName(){
	string defFileNameOut = "chagedFile.txt";
	string fileNameOut;
  cout << "Enter a file name to save (enter d to chagedFile.txt)" << endl;
  cin >> fileNameOut;
  if (fileNameOut == "d")
    fileNameOut = defFileNameOut;
  return fileNameOut;
}
