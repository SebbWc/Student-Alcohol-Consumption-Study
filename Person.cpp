#include <iostream>
#include "Person.h"

using namespace std;

Person::Person(string s, string act, int a, int me, int fe, int da, int wa, int gr, int st){
  sex = s; 
  activities = act;
  age = a;
  mEdu = me;
  fEdu = fe;
  grade = gr;
  study = st;
  dAlc = da;
  wAlc = wa;
  alc = dAlc + wAlc;
}