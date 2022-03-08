#pragma once
#include "ONode.h"

class OList
{
private:
  ONode *head;
public:
  OList();
  ~OList();

  void insert(int value);
  std::string toString();
  bool contains(int value);
  int get(int loc);
  void remove(int loc);
  void reverse();
};
