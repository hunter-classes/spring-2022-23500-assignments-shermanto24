#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "BSTree.h"

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
