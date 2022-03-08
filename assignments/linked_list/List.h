#pragma once
#include "Node.h"

class List
{
private:
  Node *head; //head of list/data set

//from class
public:
  List();
  ~List();

  void insert(std::string data);
  void insert(int loc, std::string data);

  void remove(int loc);

  std::string get(int loc);

  int length();

  std::string toString(); // for testing and debugging

//my code
/*
public:
  List();
  void insert(std::string data);
  std::string toString();

  Node *locate(int index);
  void insert(int index, std::string data);
  void remove(int index);
  ~List();
*/
};
