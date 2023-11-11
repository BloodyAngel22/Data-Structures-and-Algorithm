#include "logic.h"
#include <algorithm>
#include <cstddef>
#include <string>
#include <variant>
#include <vector>

void IndexFile::createIndexFile() {
  std::ifstream dataFile(dataFileName);
  if (!dataFile.is_open()) {
    std::cout << "Error opening data file." << std::endl;
    return;
  }
  while(!dataFile.eof()){
    Storage tmp;
    std::getline(dataFile, tmp.data);
    if (!dataFile.eof())
      records.push_back(tmp);
  }
  std::sort(records.begin(), records.end(), [](const Storage& a, const Storage& b) {
            return a.data < b.data;
            });

  /* for (auto x : records) */
  /*   std::cout << x.data << "\n"; */

  for (size_t i = 0; i < records.size(); i++)
    records[i].key = i;

  std::ofstream sortFile(sortDataFileName);
  if (!sortFile.is_open()) {
    std::cout << "Error opening sort data file." << std::endl;
    return;
  }
  for (size_t i = 0; i < records.size(); i++) {
    sortFile << records[i].data;
    sortFile << "\n";
  }
  sortFile.close();

  std::ofstream indexFile(indexFileName);
  if (!indexFile.is_open()) {
    std::cout << "Error creating index file." << std::endl;
    return;
  }

  for (size_t i = 0; i < records.size(); i++) {
    indexFile << records[i].key ;
    indexFile << "\n";
  }

  dataFile.close();
  indexFile.close();
}

void IndexFile::createMainIndex(int M) {
  mainIndex.clear();
  std::ifstream inFile(indexFileName);
  if (!inFile.is_open()) {
    std::cout << "Error creating index file." << std::endl;
    return;
  }

  int count = 0;
  while (!inFile.eof()) {
    int tmp;
    inFile >> tmp;
    if (!inFile.eof()) {
      if (count % M == 0) {
        mainIndex.push_back(tmp);
      }
      count++;
    }
  }
  inFile.close();
}

int IndexFile::findRecordSequential(int key, int M) {
  for (size_t i = 0; i < mainIndex.size(); i++){
    if (key == mainIndex[i]){
      std::cout << records[i*M].data << " ";
      return i;
    }
  }

  return -1; // Запись не найдена
}

int IndexFile::findRecordBinary(int key)
{
  std::ifstream indexFile(indexFileName);
  std::vector<int> indexes;
  while (!indexFile.eof()){
    int index;
    indexFile >> index;
    if (!indexFile.eof())
      indexes.push_back(index);
  }
  indexFile.close();

  int low = 0;
  int high = indexes.size() - 1;

  while (low <= high) {
    int mid = (low + high) / 2;
    int midKey = indexes[mid];

    if (midKey == key) {
      std::cout << records[midKey].data << " ";
      return mid;
    } else if (midKey < key) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1; // Запись не найдена
}
