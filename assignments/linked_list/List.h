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
};
