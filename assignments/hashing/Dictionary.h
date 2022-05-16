#pragma once
#include "List.h"
#define DICT_ERR_INSERT_NULLPTR 1

class Dictionary
{
private:
  List* arr[5];
public:
  Dictionary();
  ~Dictionary();

  int hash_func(std::string key);
  void insert(Person *p);
  Person* retrieve(std::string name);
  std::string get_all_keys(); //returns all first+last names
};
