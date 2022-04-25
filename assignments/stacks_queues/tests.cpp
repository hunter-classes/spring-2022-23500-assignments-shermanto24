#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Stack.h"

Stack *s = new Stack();

TEST_CASE("Testing push and top")
{
  s->push("e");
  CHECK(s->top() == "e");
  s->push("d");
  CHECK(s->top() == "d");
  s->push("c");
  CHECK(s->top() == "c");
  s->push("b");
  CHECK(s->top() == "b");
  s->push("a");
  CHECK(s->top() == "a");
}

TEST_CASE("Testing pop: good cases")
{
  s->pop();
  CHECK(s->top() == "b");
  s->pop();
  CHECK(s->top() == "c");
  s->pop();
  CHECK(s->top() == "d");
  s->pop();
  CHECK(s->top() == "e");
  s->pop();
}

TEST_CASE("Testing top and pop exceptions")
{
  bool worked = false;
  try
  {
    s->pop();
    worked = true;
  }
  catch (int e)
  {
    CHECK(worked == false);
  }

  worked = false;
  try
  {
    s->top();
    worked = true;
  }
  catch (int e)
  {
    CHECK(worked == false);
  }

  delete s;
}
