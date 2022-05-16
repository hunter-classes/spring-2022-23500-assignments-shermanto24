#pragma once
#include "List.h"

class Dictionary
{
private:
  List* arr[5];
public:
  Dictionary();
  ~Dictionary();

  int hash(std::string key);
  void insert(Person *p);
  Person* retrieve(std::string name);
  std::string get_all_keys(); //returns all first+last names
};
