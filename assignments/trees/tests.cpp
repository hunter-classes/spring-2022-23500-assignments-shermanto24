#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "BSTree.h"

// -------------------- PART 1 --------------------

BSTree *t = new BSTree();

TEST_CASE("rsearch: value exists")
{
  t->setup();
  t->insert(6);
  t->insert(24);

  CHECK(t->rsearch(10) == 10);
  CHECK(t->rsearch(5) == 5);
  CHECK(t->rsearch(3) == 3);
  CHECK(t->rsearch(8) == 8);
  CHECK(t->rsearch(6) == 6);
  CHECK(t->rsearch(20) == 20);
  CHECK(t->rsearch(15) == 15);
  CHECK(t->rsearch(24) == 24);
  CHECK(t->rsearch(30) == 30);
}

TEST_CASE("rsearch: value does not exist")
{
  try
  {
    t->rsearch(1);
  }
  catch (int e)
  {
    CHECK(e == 1);
  }

  try
  {
    t->rsearch(4);
  }
  catch (int e)
  {
    CHECK(e == 1);
  }

  try
  {
    t->rsearch(100);
  }
  catch (int e)
  {
    CHECK(e == 1);
  }

  try
  {
    t->rsearch(50);
  }
  catch (int e)
  {
    CHECK(e == 1);
  }
}

TEST_CASE("rinsert: into t, which already has values")
{
  // inserting on the left side of a leaf
  t->rinsert(1);
  CHECK(t->rsearch(1) == 1);
  t->rinsert(-10);
  CHECK(t->rsearch(-10) == -10);

  // inserting on the right side of a leaf
  t->rinsert(9);
  CHECK(t->rsearch(9) == 9);
  t->rinsert(40);
  CHECK(t->rsearch(40) == 40);
}

BSTree *t2 = new BSTree();

TEST_CASE("rinsert: into t2, which starts off empty")
{
  // testing when root == nullptr
  t2->rinsert(20);
  CHECK(t2->rsearch(20) == 20);

  // testing left and right
  t2->rinsert(10);
  CHECK(t2->rsearch(10) == 10);
  t2->rinsert(5);
  CHECK(t2->rsearch(5) == 5);

  t2->rinsert(30);
  CHECK(t2->rsearch(30) == 30);
  t2->rinsert(35);
  CHECK(t2->rsearch(35) == 35);
}

TEST_CASE("rinsert: value already exists in the tree")
{
  t->rinsert(1);
  CHECK(t->rsearch(1) == 1);
  t->rinsert(40);
  CHECK(t->rsearch(40) == 40);

  t2->rinsert(5);
  CHECK(t2->rsearch(5) == 5);
  t2->rinsert(30);
  CHECK(t2->rsearch(30) == 30);
}

// -------------------- PART 2 --------------------

BSTree *t3 = new BSTree();

TEST_CASE("remove: leaf")
{
  t3->rinsert(10);

  // left
  t3->rinsert(5);
  CHECK(t3->get_debug_string() == ", 5, , 10, ");

  t3->remove(5);
  CHECK(t3->get_debug_string() == ", 10, ");

  // right
  t3->rinsert(15);
  CHECK(t3->get_debug_string() == ", 10, , 15, ");

  t3->remove(15);
  CHECK(t3->get_debug_string() == ", 10, ");
}

TEST_CASE("remove: leaf (root)")
{
  t3->remove(10);
  CHECK(t3->get_debug_string() == "");
}

TEST_CASE("remove: node with one child")
{
  t3->rinsert(10);

  // left child
  t3->rinsert(5);
  t3->rinsert(2);
  t3->rinsert(3);
  t3->rinsert(1);
  CHECK(t3->get_debug_string() == ", 1, , 2, , 3, , 5, , 10, ");

  t3->remove(5);
  CHECK(t3->get_debug_string() == ", 1, , 2, , 3, , 10, ");

  // right child
  t3->rinsert(7);
  t3->rinsert(4);
  t3->rinsert(9);
  CHECK(t3->get_debug_string() == ", 1, , 2, , 3, , 4, , 7, , 9, , 10, ");

  t3->remove(3);
  CHECK(t3->get_debug_string() == ", 1, , 2, , 4, , 7, , 9, , 10, ");
}

TEST_CASE("remove: node with one child (root)")
{
  t3->remove(10);
  CHECK(t3->get_debug_string() == ", 1, , 2, , 4, , 7, , 9, ");
}

TEST_CASE("remove: node with two children")
{
  t3->rinsert(8);
  t3->rinsert(15);
  CHECK(t3->get_debug_string() == ", 1, , 2, , 4, , 7, , 8, , 9, , 15, ");

  t3->remove(7);
  CHECK(t3->get_debug_string() == ", 1, , 2, , 4, , 8, , 9, , 15, ");

  t3->remove(9);
  CHECK(t3->get_debug_string() == ", 1, , 2, , 4, , 8, , 15, ");
}

TEST_CASE("remove: node with two children (root)")
{
  t3->remove(2);
  CHECK(t3->get_debug_string() == ", 1, , 4, , 8, , 15, ");
}

TEST_CASE("remove: value does not exist")
{
  try
  {
    t3->remove(10);
  }
  catch (int e)
  {
    CHECK(e == 1);
  }

  try
  {
    t3->remove(2);
  }
  catch (int e)
  {
    CHECK(e == 1);
  }

  try
  {
    t3->remove(100);
  }
  catch (int e)
  {
    CHECK(e == 1);
  }
}

// -------------------- PART 3 --------------------

BSTree *t4 = new BSTree();

TEST_CASE("count_leaves")
{
  // empty tree
  CHECK(t4->count_leaves() == 0);

  // one node
  t4->rinsert(10);
  CHECK(t4->count_leaves() == 1);

  // left leaf
  t4->rinsert(5);
  CHECK(t4->count_leaves() == 1);

  // left + right leaf
  t4->rinsert(20);
  CHECK(t4->count_leaves() == 2);

  // adding more nodes
  t4->rinsert(2);
  CHECK(t4->count_leaves() == 2);
  t4->rinsert(7);
  CHECK(t4->count_leaves() == 3);
  t4->rinsert(1);
  CHECK(t4->count_leaves() == 3);
  t4->rinsert(3);
  CHECK(t4->count_leaves() == 4);
  t4->rinsert(25);
  CHECK(t4->count_leaves() == 4);
  t4->rinsert(30);
  CHECK(t4->count_leaves() == 4);
  t4->rinsert(22);
  CHECK(t4->count_leaves() == 5);
  t4->rinsert(15);
  CHECK(t4->count_leaves() == 6);
}

BSTree *t5 = new BSTree();

TEST_CASE("get_height")
{
  // empty tree
  CHECK(t5->get_height() == 0);

  // one node
  t5->rinsert(20);
  CHECK(t5->get_height() == 1);

  // adding other nodes
  t5->rinsert(10);
  CHECK(t5->get_height() == 2);
  t5->rinsert(30);
  CHECK(t5->get_height() == 2);

  // nodes at level 3 (1st level being the root)
  t5->rinsert(25);
  CHECK(t5->get_height() == 3);
  t5->rinsert(15);
  CHECK(t5->get_height() == 3);
  t5->rinsert(5);
  CHECK(t5->get_height() == 3);
  t5->rinsert(35);
  CHECK(t5->get_height() == 3);

  t5->rinsert(40);
  CHECK(t5->get_height() == 4);
  t5->rinsert(37);
  CHECK(t5->get_height() == 5);
  t5->rinsert(12);
  CHECK(t5->get_height() == 5);
  t5->rinsert(38);
  CHECK(t5->get_height() == 6);
}
