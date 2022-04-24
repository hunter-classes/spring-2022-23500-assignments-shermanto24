#pragma once
#include "Node.h"
#define STACK_ERR_EMPTY 1
//#define STACK_ERR_FULL 2

class Stack
{
private:
  Node *head;

public:
  Stack();
  ~Stack();

  void push(std::string str); // add str onto the top of the stack
  std::string pop(); // remove and return the top item
  std::string top(); // return but do not remove the top item
  bool is_empty(); // return true if empty, false otherwise
};
