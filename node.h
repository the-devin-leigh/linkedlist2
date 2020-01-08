#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

class Node{
 public:
  Node(Student*);
  ~Node(); //destructor
  void setStudent(Student*); //set the student
  Student* getStudent(); //returns student
  void setNext(Node* newNext); //sets the name
  Node* getNext(); //returns next node in list
 private:
  Student* student; //Student node
  Node* next; //goes to next node
};

#endif
