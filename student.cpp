#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

Student::Student(const char* setName, int setID, float setGpa){
  strcpy(name, setName); //name = input name
  id = setID; //id = input id
  gpa = setGpa; //gpa = input gpa
}

Student::~Student(){ //destructor
  delete name;
}

char* Student::getName(){ //returns name
  return name;
}

int Student::getID(){ //returns id
  return id; 
}

float Student::getGpa(){ //returns gpa float
  return gpa;
}
