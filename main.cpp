// This is the main file where the user driven menu will existing!
// Authors: Lane Maimone, Sebastion Wcislo, Yuwei Liu, Willi Vargas
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <vector>
#include "FileReader.cpp"

//if you feel any additional libraries are necessary, please add them!

using namespace std;
FileReader fr;
vector<Person> temp;

//This function filters the list to only include students with a weekly alcohol consumption of 7 or more
void alcFilter(){
  temp.clear();
  for(int i = 0; i < fr.students.size(); i++){
    if(fr.students[i].alc > 7){
      temp.push_back(fr.students[i]);
    }
  }
  fr.students = temp;
}

//This function filters the list to only include students with a weekly alcohol consumption of 6 or less
void nalcFilter(){
  temp.clear();
  for(int i = 0; i < fr.students.size(); i++){
    if(fr.students[i].alc < 7){
      temp.push_back(fr.students[i]);
      }
    }
  fr.students = temp;
  }

//This function filters the list to only include female students
void fFilter(){
  temp.clear();
  for(int i = 0; i < fr.students.size(); i++){
    if(fr.students[i].sex == "F"){
      temp.push_back(fr.students[i]);
    }
  }
  fr.students = temp;
}

//This function filters the list to only include male students
void mFilter(){
  temp.clear();
  for(int i = 0; i < fr.students.size(); i++){
    if(fr.students[i].sex == "M"){
      temp.push_back(fr.students[i]);
    }
  }
  fr.students = temp;
}

//This function filters the list to only include students whose parents both have an education level of 1 or less
void lowEduParentFilter(){
  temp.clear();
  for(int i = 0; i < fr.students.size(); i++){
    if(fr.students[i].mEdu <= 1 && fr.students[i].fEdu <= 1){
      temp.push_back(fr.students[i]);
    }
  }
  fr.students = temp;
}

//This function filters the list to only include students who have at least 1 parent with an education level of 2 or more
void eduParentFilter(){
  temp.clear();
  for(int i = 0; i < fr.students.size(); i++){
    if(fr.students[i].mEdu > 1 || fr.students[i].fEdu > 1){
      temp.push_back(fr.students[i]);
    }
  }
  fr.students = temp;
}

void unfilter(){
  fr.students.clear();
  fr.initVec();
}

//Finds data pertaining to average study time and alcohol consumption.
void algorithm1(){

  float temp1 = 0;
  float temp2 = 0;
  float dStudyAvg;
  float dGradeAvg;
  float ndStudyAvg;
  float ndGradeAvg;
  vector<Person> drinkers;
  vector<Person> ndrinkers;

//This for loop lists all the students.
  for(int i = 0; i < fr.students.size(); i++){
    if(fr.students[i].alc > 7){
      drinkers.push_back(fr.students[i]);
    }
    else{
      ndrinkers.push_back(fr.students[i]);
    }
  }

//This for loop will inhabit temp with every drinkers study and grade data.
  for(int i = 0; i < drinkers.size(); i++){
    temp1 += drinkers[i].study;
    temp2 += drinkers[i].grade;
  }

//We now use temp to find the averages.
  dStudyAvg = temp1/drinkers.size();
  dGradeAvg = temp2/drinkers.size();
  temp1 = 0;
  temp2 = 0;

//This for loop will inhabit temp with every nondrinkers study and grade data.
  for(int i = 0; i < ndrinkers.size(); i++){
    temp1 += ndrinkers[i].study;
    temp2 += ndrinkers[i].grade;
  }

//We now use temp to find the averages.
  ndStudyAvg = temp1/ndrinkers.size();
  ndGradeAvg = temp2/ndrinkers.size();

//Printing results.
  cout <<"\n";
  cout << "The excessive drinking students have an average study time of " << setprecision(3) << dStudyAvg << " and an average grade in their course of " << setprecision(3) << dGradeAvg << endl;
  
  cout << "The nonexcessive drinking students have an average study time of " << setprecision(3) << ndStudyAvg << " and an average grade in their course of " <<setprecision(3) <<  ndGradeAvg << endl;
  cout <<"\n";
}

//Finds data pertaining to alcohol consumption in educated and uneducated households. 
void algorithm2(){
 
  int nonDrinkerParentHighEd = 0,nonDrinkerParentLowEd = 0;
  int DrinkerParentHighEd = 0,DrinkerParentLowEd = 0;
  vector<Person> drinkers;
  vector<Person> ndrinkers;

  //This For loop counts all the students.
  for(int i = 0; i < fr.students.size(); i++){
    if(fr.students[i].alc > 7){
      drinkers.push_back(fr.students[i]);
    }
    else{
      ndrinkers.push_back(fr.students[i]);
    }
  }

  //This for loop will count if the either of the student's parents who are drinkers have low or high education.
  for(int i = 0; i < fr.students.size(); i++){
    if(drinkers[i].mEdu <= 1 || drinkers[i].fEdu<=1){
      DrinkerParentLowEd++;
    }
    else{
      DrinkerParentHighEd++;
    }
  }

  //This for loop will count if the either of the student's parents who are non-drinkers have low or high education.
  for(int i = 0; i < fr.students.size(); i++){
    if(ndrinkers[i].mEdu <= 1 || ndrinkers[i].fEdu<=1){
      nonDrinkerParentLowEd++;
    }
    else{
      nonDrinkerParentHighEd++;
    }
  }

  //Printing results.
  cout <<"\n";
  cout<< "For non-excessive drinker: Educated Parent Number: " <<nonDrinkerParentHighEd<< " & Uneducated Parent Number: " << nonDrinkerParentLowEd << endl;
   cout<< "For excessive drinker: Educated Parent Number: " <<DrinkerParentHighEd<< " & Uneducated Parent Number: " << DrinkerParentLowEd << endl;
  cout <<"\n";
}

//Finds data pertaining alcohol consumption between male and female students. 
void algorithm3(){

float malePop = 0, femalePop = 0;
float maleAlcPop = 0, femaleAlcPop = 0;
float malePerc = 0.0, femalePerc = 0.0;

//This for loop counts every student who is male and drinks in excess, as well as female and drinks in excess.
for(int i = 0; i < fr.students.size(); i++){
     if(fr.students[i].sex == "M" && (fr.students[i].alc > 7)){
      maleAlcPop++;
     }
    else if (fr.students[i].sex == "F" && (fr.students[i].alc > 7)){
       femaleAlcPop++;
     }
   }

//This for loop counts the total population of male and female students.
for(int i = 0; i < fr.students.size(); i++){
  if(fr.students[i].sex == "M"){
    malePop++;
  }
  else{
    femalePop++;
  }
}

//We now find the percentage of male students that drink in excess, and female students that drink in excess.
malePerc = (maleAlcPop/malePop)*100;
femalePerc = (femaleAlcPop/femalePop)*100;

//Printing results.
cout <<"\n";
cout << "Percent of male population that drank in excess is: "<< setprecision(2) << malePerc<< " out of: " << setprecision(4)<<  malePop<< " males."<<  endl;
cout << "Percent of female population that drank in excess is: "<<setprecision(2) << femalePerc<<" out of: " << setprecision(4)<< femalePop<< " females."<<  endl;
cout <<"\n";
}

//Finds data with comparing excessive drinkers and whether or not they are involved in extra curricular activities.
void algorithm4() {

  float DrinkerExtraC = 0, DrinkerNonExtraC = 0;
  float ExtraCPop = 0, NonExtraCPop = 0;
  float DrinkerPerc = 0, DrinkerNoEPerc = 0;

//This for loop counts every student who takes extracurricular activities and drinks in excess, as well every student who doesn't take extracurricular activities and drinks in excess.
  for(int i = 0; i < fr.students.size(); i++){
    if(fr.students[i].activities == "yes" && (fr.students[i].alc > 7)){
      DrinkerExtraC++;
    }
    else if (fr.students[i].activities == "no" && (fr.students[i].alc > 7)) {
      DrinkerNonExtraC++;
    }
  }

//This for loop counts every student who takes extracurricular and every student who isn't.
for(int i = 0; i < fr.students.size(); i++){
  if(fr.students[i].activities == "yes"){
    ExtraCPop++;
  }
  else{
    NonExtraCPop++;
  }
}

//We now find the percentages of students who drink and take extracurricular activities and who don't take extracurricular activites.
DrinkerPerc = (DrinkerExtraC/ExtraCPop)*100;
DrinkerNoEPerc = (DrinkerNonExtraC/NonExtraCPop)*100;

//Printing results.
cout <<"\n";
cout << "Percent of students who are excessive drinkers and take extracurricular activities: " << setprecision(3) << DrinkerPerc << " out of: " << ExtraCPop << " students." << endl;
cout << "Percent of students who are excessive drinkers and don't take extracurricular activities: " << setprecision(3) << DrinkerNoEPerc << " out of: " << NonExtraCPop << " students." << endl;
cout <<"\n";
}
//This function creates our text-based menu
void menu(){
  int input = 0;
  bool cont = true;
    cout << "1. Print Data." << endl;
    cout << "2. Filter Excessive Drinkers." << endl;
    cout << "3. Filter Nonexcessive Drinkers." << endl;
    cout << "4. Filter Students with Educated Parents." << endl;
    cout << "5. Filter Students with Parents that have a low education." << endl;
    cout << "6. Filter Female Students." << endl;
    cout << "7. Filter Male Students." << endl;
    cout << "8. Unfilter Data." << endl;
    cout << "9. Run Algorithm to compare average Study Time and Course Grades between excessive drinking and non-excessive drinking students." << endl;
    cout << "10. Run Algorithm to compare education level of parents for excessive drinkers and non-excessive drinkers." << endl;
    cout << "11. Run Algorithm to compare alcohol consumption between genders." << endl;
    cout << "12. Run Algorithm to compare extracurricular activities and alcohol consumption." << endl;
    cin >> input;

    //We are using a switch for our menu.
    switch(input){
      case 1:
      fr.print();
      break;
      case 2:
        alcFilter();
        cout << "Data has been filtered to inlcude only excessive drinking students and is a size of " << temp.size() << endl;
        break;
      case 3:
        nalcFilter();
        cout << "Data has been filtered to include only nonexcessive drinking students and is a size of " << temp.size() << endl;
        break;
      case 4:
        eduParentFilter();
        cout << "Data has been filtered to include students with at least 1 parent with an education of 2-4 and is a size of " << temp.size() << endl;
        break;
      case 5:
        lowEduParentFilter();
        cout << "Data has been filtered to include students whose parents both have an education level of 0-1 and is a size of " << temp.size() << endl;
        break;
      case 6:
        fFilter();
        cout << "Data has been filtered to include only female students and is a size of " << temp.size() << endl;
        break;
      case 7:
        mFilter();
        cout << "Data has been filtered to include only male students and is a size of " << temp.size() << endl;
        break;
      case 8:
        unfilter();
        cout << "Data has been restored to default and is a size of " << fr.students.size() << endl;
        break;
      case 9:
        algorithm1();
        break;
      case 10:
        algorithm2();
        break;
      case 11:
        algorithm3();
        break;
      case 12:
        algorithm4();
        break;
      default:
        exit;
        break;
    
      }
}

int main(){

  //We use user to loop the menu.
  int user = 0;
  bool cont = true;
  fr.readFile("student-mat.csv");
  fr.readFile("student-por.csv");
  fr.initVec();

//Welcome message.
  cout << "Welcome to our data project! This program reads two csv files and creates a list of students with their respective data. What would you like to do with this data?" << endl;

//The menu loop.
  while(cont){
    menu();
    cout << "To continue enter: 1" <<endl;
    cout << "To exit, enter anything else." <<endl;
    cin >> user;
    if (user!=1){
      cont =false;
    }
  }
  
  //Ending message.
  cout << "Goodbye!";

}