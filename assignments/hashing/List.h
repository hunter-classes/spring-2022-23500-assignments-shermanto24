#pragma once

#include "Node.h"

class List{
 private: Node *head;

 public:
  List();
  ~List();

  void insert(Person *data); // insert at head
  //void insert(int loc, Person *data);

  void remove(int loc);

  Person* get(int loc);

  int length();

  std::string toString(); // for testing and debugging
  
  Node* get_head();
};
