#pragma once
#include <iostream>
#include <stdio.h>
#include "Node.h"
#define TREE_ERR_VALUE_NOT_FOUND 1

class BSTree{
 private:
  Node *root;
  std::string traverse(Node *n);

public:
  BSTree();

  void setup();

  std::string get_debug_string();


  // std::string traverse(Node *n);

  int search(int value);
  void insert(int value);

  int rsearch(int value);
  int rsearch(int value, Node *p);

  // int treesum();
  // int treesum(Node *n);
  // int searchr(int value);
  // int searchr(int value, Node *n);

};
