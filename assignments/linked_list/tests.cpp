#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "OList.h"
//#include <iostream>

OList *l1 = new OList();

TEST_CASE("insert(value), get(loc), and toString() tests")
{
  CHECK(l1->toString() == "head --> nullptr");

  //when we have no elements (head == nullptr)
  l1->insert(3);
  CHECK(l1->get(0) == 3);
  CHECK(l1->toString() == "head --> 3 --> nullptr");

  //at the beginning
  l1->insert(1);
  CHECK(l1->get(0) == 1);
  CHECK(l1->get(1) == 3);
  CHECK(l1->toString() == "head --> 1 --> 3 --> nullptr");

  //at the end
  l1->insert(4);
  CHECK(l1->get(0) == 1);
  CHECK(l1->get(1) == 3);
  CHECK(l1->get(2) == 4);
  CHECK(l1->toString() == "head --> 1 --> 3 --> 4 --> nullptr");

  //in between
  l1->insert(2);
  for (int i = 0; i < 4; i++)
    CHECK(l1->get(i) == i + 1);
  CHECK(l1->toString() == "head --> 1 --> 2 --> 3 --> 4 --> nullptr");

  //adding more elements
  l1->insert(-10);
  CHECK(l1->get(0) == -10);
  CHECK(l1->toString() == "head --> -10 --> 1 --> 2 --> 3 --> 4 --> nullptr");

  l1->insert(10);
  CHECK(l1->get(5) == 10);
  CHECK(l1->toString() == "head --> -10 --> 1 --> 2 --> 3 --> 4 --> 10 --> nullptr");

  l1->insert(7);
  CHECK(l1->get(5) == 7);
  CHECK(l1->toString() == "head --> -10 --> 1 --> 2 --> 3 --> 4 --> 7 --> 10 --> nullptr");
}

TEST_CASE("contains(value): true")
{
  CHECK(l1->contains(-10));
  CHECK(l1->contains(1));
  CHECK(l1->contains(2));
  CHECK(l1->contains(3));
  CHECK(l1->contains(4));
  CHECK(l1->contains(7));
  CHECK(l1->contains(10));
}

TEST_CASE("contains(value): false")
{
  CHECK(!l1->contains(0));
  CHECK(!l1->contains(5));
  CHECK(!l1->contains(20));
}

TEST_CASE("get(loc): invalid index")
{
  CHECK(l1->get(-1) == 0);
  CHECK(l1->get(7) == 0);
  CHECK(l1->get(100) == 0);
}

TEST_CASE("remove(loc) tests")
{
  //at the beginning
  l1->remove(0);
  CHECK(l1->toString() == "head --> 1 --> 2 --> 3 --> 4 --> 7 --> 10 --> nullptr");

  //at the end
  l1->remove(5);
  CHECK(l1->toString() == "head --> 1 --> 2 --> 3 --> 4 --> 7 --> nullptr");

  //in between
  l1->remove(2);
  CHECK(l1->toString() == "head --> 1 --> 2 --> 4 --> 7 --> nullptr");

  //out of range
  //l1->remove(-1);
  //l1->remove(4);
}
