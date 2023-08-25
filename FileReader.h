#include <iostream>
#include "Person.cpp"
using namespace std;
#pragma once

class FileReader{
  public:
  FileReader();
  void readFile(std::string);
  void initVec();
  void print();
  vector<vector<string> > data;
  vector<Person> students;
  vector<string> cells;
  string line, word, hold;
};