#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

Node::Node(Student*){
  student = NULL;
  next = NULL;
}

Node::~Node(){ //destructor
  delete &student; //deletes the actual Student value
  next = NULL;
}

void Node::setStudent(Student* newStudent){ //set the student to input
  student = newStudent;
}

Student* Node::getStudent(){ //returns Student
  return student;
}

void Node::setNext(Node* newNext){ //gets next node
  next = newNext;
}

Node* Node::getNext(){ //returns next node
  return next; 
}
