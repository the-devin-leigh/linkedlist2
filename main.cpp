/*Author: Devin Leigh
 *Date:12/20/2019
 *Project: Linked list, students held in nodes pointing to next node
 */
#include <iostream>
#include <iomanip>
#include "node.h"
#include "student.h"

using namespace std;

Node* head = NULL; //first node

void add(char* name, int id, float gpa){//adds the student to the end of the linked list
  Student* newStudent = new Student(name, id, gpa);
  Node* current = head; //new current node equal to the value at head
  if(current == NULL){ //if head is null
    head = new Node(newStudent); //make new node for head
    head->setStudent(newStudent); //set the new student to head
  }else{
    while(current->getNext() != NULL){ //while the current pointer not at the end of the array
      current = current->getNext();
    }
    current->setNext(new Node(newStudent)); //new node at next location of the current node
    current->getNext()->setStudent(newStudent); //set the nodes student to the input
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

int main(){ //main 
  int active = 0;

  while(active == 0){
    char* input = new char[50];
    char* studentName = new char[50];
    int id = 0;
    float gpa = 0;
    cout << "Student linked list" << endl;
    cout << "Do you want to add, print, or exit?" << endl;
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

      add(studentName, id, gpa);
      print(head);
    }else if(strcmp(input, "print") == 0){
      print(head);
    }else if(strcmp(input, "exit") == 0){
      active = 1;
    }else{
      cout << "not a valid answer" << endl;
    }
  }
}
