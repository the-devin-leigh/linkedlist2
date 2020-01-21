/*Author: Devin Leigh
 *Date:1/20/2019
 *Project: Linked list, students held in nodes pointing to next node
 */
#include <iostream>
#include <iomanip>
#include "node.h"
#include "student.h"

using namespace std;

Node* head = NULL; //first node

void add(Node* current, char* name, int id, float gpa){//adds the student to the end of the list
  Student* newStudent = new Student(name, id, gpa);
  
  if(head == NULL){ //first node
    head = new Node(newStudent); //make new node for head
  }else if(newStudent->getID() < head->getStudent()->getID()){ //new node ID less than head 
    Node* temp = new Node(head->getStudent());
    temp->setNext(head->getNext());
    head->setStudent(newStudent);
    head->setNext(temp);
  }else if(current->getNext() == NULL){ //at end of list already
    Node* newNode = new Node(newStudent);
    current->setNext(newNode);
  }else if(newStudent->getID() > current->getStudent()->getID()){ //new nodeID more than head
    Node* newNode = new Node(newStudent);
    newNode->setNext(current->getNext());
    current->setNext(newNode);
  }else{ //recursion
    add(current->getNext(), name, id, gpa);
  }
}

void print(Node* next){ //print function
  if(next == head){ //if next is equal to head
    cout << "List: " << endl; //print list
  }if(next != NULL){ //if not
    cout << "(Name: " << next->getStudent()->getName() << ", ID: " << next->getStudent()->getID() << " , GPA: "  << fixed << setprecision(2) << next->getStudent()->getGpa() << ") "<< endl;
    print(next->getNext()); //same thing to next node
  }
}

float average(Node* n){ //average
  float total = 0;
  int counter = 0;
  if (n == head){ //totaling
    total += n->getStudent()->getGpa();
    counter++;
  }
  while (n->getNext() != NULL){ //if list is at the last node
    total += n->getNext()->getStudent()->getGpa();
    counter++;
    n = n->getNext();
  }
  return(total/counter); //calculate average
}

void del(Node* next, Node* previous, int id) {
char choice;
 if(next == head && (next->getStudent()->getID() == id)){ //head is student for deleting  
    cout << next->getStudent()->getName() << " " << endl;
    cout << next->getStudent()->getID() << endl;
    cout << next->getStudent()->getGpa() << endl;
    cout << "Would you would like to delete this student?" << endl;
    cin >> choice;
    cin.clear();
    cin.ignore(1000000, '\n');
    if(choice == 'y'){ //confirm
      cout << "Student deleted" << endl;
      if (next->getNext() == NULL){ //delete student
	next->~Node();
	head = NULL;
      }else{ //moving it to the end
	head = next -> getNext();
	next->~Node();
	del(head, NULL, id);
      }
    }else if(choice == 'n'){
      cout << "Student not deleted" << endl;
      if(next->getNext() != NULL) {
	del(next->getNext(), next, id);
      }
    }else{
      cout << "Invalid input" << endl << endl;
    }
  }else if(next -> getStudent() -> getID() == id){ //for middle of list
    cout << next->getStudent()->getName();
    cout << next->getStudent()->getID() << endl;
    cout << next->getStudent()->getGpa() << endl;
    cout << "Would you would like to delete this student?" << endl;
    cin >> choice;
    cin.clear();
    cin.ignore(1000000, '\n');
    if(choice == 'y'){//deleting student
      cout << "Student deleted" << endl;
      previous->setNext(next->getNext());
      next->~Node();
    }else if(choice == 'n'){//not deleted
      cout << "Student not deleted" << endl;
    }else{
      cout << "Invalid input" << endl;
    }
  }
 if(next->getNext() != NULL){ //recursion
    del(next->getNext(), next, id);
  }
}

int main(){ //main 
  int active = 0;

  while(active == 0){
    char* input = new char[50];
    char* studentName = new char[50];
    int id = 0;
    float gpa = 0;
    int deleteid = 0;
    cout << "Student linked list" << endl;
    cout << "Do you want to add, print, delete, average, or exit?" << endl;
    cin.getline(input, 25, '\n');

    if(strcmp(input, "add") == 0){
      cout << "Enter name of student:" << endl;
      cin.getline(studentName, 25, '\n');
      
      cout << "Enter ID of student:" << endl;
      cin >> id;
      cin.clear();
      cin.ignore(1000000, '\n');
      
      cout << "Enter GPA of student: " << endl;
      cin >> gpa;
      cin.clear();
      cin.ignore(1000000, '\n');

      add(head, studentName, id, gpa);
    }else if(strcmp(input, "print") == 0){
      print(head);
    }else if(strcmp(input, "exit") == 0){
      active = 1;
    }else if(strcmp(input, "delete") == 0){
      if(head == NULL){
	cout << "There are no students to delete" << endl;
      }else{
	cout << "What is the ID of the student you want to delete?" << endl;
	cin >> deleteid;
	cin.clear();
	cin.ignore(100000, '\n');
	del(head, NULL, deleteid);
      }
    }else if(strcmp(input, "average") == 0){
      if(head == NULL){
	cout << "No students in list" << endl;
      }else{
	cout << "Average GPA: " << average(head) << endl;
      }
    }else{
      cout << "Not a valid input" << endl;
    }
  }
}
