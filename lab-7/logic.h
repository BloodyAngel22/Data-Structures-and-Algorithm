#include <algorithm>
#include <fstream>
#include <ostream>
#include <string>
#include <iostream>
#include <istream>
#include <vector>

struct Storage{
  std::string data;
  unsigned int key;
};

class IndexFile{
  public:
    std::string dataFileName = "data.txt";
    std::string sortDataFileName = "sort_data.txt";
    std::string indexFileName = "index.txt";
    std::vector<Storage> records;
    std::vector<int> mainIndex;

    void createIndexFile();
    void createMainIndex(int M);
    int findRecordSequential(int key, int M);
    int findRecordBinary(int key);
};

