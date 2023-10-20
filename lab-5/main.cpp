#include "stack.h"
#include <fstream>

string readFile(string file_name){
  ifstream file;
  file.open(file_name);
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

void changeFile(string text, string file_name = "output.txt"){
  ofstream file;
  file.open(file_name);
  string modifiedStr;
  for (int i = 0; i < text.size(); i++){
    if (text[i] == '(' || text[i] == ')' || text[i] == '[' || text[i] == ']')
      continue;
    else
    {
      modifiedStr += text[i];
    }
  }
  file << modifiedStr;
}

int main()
{
  srand(time(0));
  Stack stack;
  
  string text  = readFile("input.txt");
  /* cout << text << endl; */
  bool res = stack.task_1(text);

  stack.print();
  cout << "res = " << res << endl;
  if (res == 1){
    cout << "Правильная вложенность\n";
    changeFile(text);
  }

  return 0;
}
