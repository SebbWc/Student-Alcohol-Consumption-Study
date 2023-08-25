#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "FileReader.h"
using namespace std;


FileReader::FileReader(){
}

//This function reads a file and creates a 2d vector of all the data
void FileReader::readFile(std::string file){
  ifstream fs;
  fs.open(file);

  if(!fs.is_open()){
    cout << "Could not open files" << endl;  
  }

  while(fs.good()){
    getline(fs, line);
    stringstream ss(line);
    while(getline(ss, word, ',')){
      cells.push_back(word);
    }
    data.push_back(cells);
    cells.clear();
  }
}

//This funciton creates a vector of type Person, essentially creating a list of students
void FileReader::initVec(){
  for(int i = 1; i < data.size() - 1; i++){
    if(data[i][0] != "school"){
    Person person(data[i][1], data[i][16], stoi(data[i][2]), stoi(data[i][6]), stoi(data[i][7]), stoi(data[i][26]),stoi(data[i][27]), stoi(data[i][32]), stoi(data[i][13]));
    students.push_back(person);
    }
  }
}

//This funciton prints out the list of students
void FileReader::print(){
  for(int i = 0; i < students.size(); i++){
    cout << "Student " << i + 1 << ": " << "Sex: " << students[i].sex << ", Inolved in extra-curriculars: " << students[i].activities << ", Age: " << students[i].age << ", Mother Education: " << students[i].mEdu << ", Father Education: " << students[i].fEdu << ", Weekly Alcohol Consumption: " << students[i].alc << ", Study Time: " << students[i].study << ", Course Grade: " << students[i].grade << endl;
  }
}

