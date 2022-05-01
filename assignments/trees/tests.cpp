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
