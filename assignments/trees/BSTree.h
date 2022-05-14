#pragma once
#include <iostream>
#include <stdio.h>
#include "Node.h"
#define TREE_ERR_VALUE_NOT_FOUND 1
#define TREE_ERR_INVALID_LEVEL 2

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

 // part 1
  int rsearch(int value);
  int rsearch(int value, Node *p);

  void rinsert(int value);
  void rinsert(int value, Node *p);

  // part 2
  void remove(int value);

  // int treesum();
  // int treesum(Node *n);
  // int searchr(int value);
  // int searchr(int value, Node *n);

  // part 3
  int count_leaves(Node *p);
  int count_leaves();

  int get_height(Node *p);
  int get_height();

  int get_sum_at(int level, int curr_level, Node *p);
  int get_sum_at(int level);
};
