#pragma once
#include "Node.h"

class List
{
private:
  Node *head; //head of list/data set

public:
  List();
  void insert(std::string data);
  std::string toString();

  //my code
  Node *locate(int index);
  void insert(int index, std::string data);
  void remove(int index);
  ~List();
};
