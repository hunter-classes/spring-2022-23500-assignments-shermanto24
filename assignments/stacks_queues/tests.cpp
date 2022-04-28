#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Stack.h"
#include "Queue.h"

// ------------ testing stack ------------

Stack *s = new Stack();

TEST_CASE("push, top, and is_empty")
{
  CHECK(s->is_empty());
  s->push("e");
  CHECK(s->top() == "e");
  CHECK(!s->is_empty());
  s->push("d");
  CHECK(s->top() == "d");
  s->push("c");
  CHECK(s->top() == "c");
  s->push("b");
  CHECK(s->top() == "b");
  s->push("a");
  CHECK(s->top() == "a");
}

TEST_CASE("pop: good cases")
{
  CHECK(s->pop() == "a");
  CHECK(s->pop() == "b");
  CHECK(s->pop() == "c");
  CHECK(s->pop() == "d");
  CHECK(s->pop() == "e");
}

TEST_CASE("top and pop exceptions")
{
  try
  {
    s->pop();
  }
  catch (int e)
  {
    CHECK(e == 1); //STACK_ERR_EMPTY = 1
  }

  try
  {
    s->top();
  }
  catch (int e)
  {
    CHECK(e == 1); //STACK_ERR_EMPTY = 1
  }

  delete s;
}

// ------------ testing queue ------------

Queue *q = new Queue();

TEST_CASE("enqueue (adding elements until full, uninterrupted), front, and is_empty")
{
  CHECK(q->is_empty());
  q->enqueue(1);
  CHECK(q->front() == 1);
  CHECK(!q->is_empty());

  q->enqueue(2);
  CHECK(q->front() == 1);
  q->enqueue(3);
  q->enqueue(4);
  q->enqueue(5);
  CHECK(q->front() == 1);
}

TEST_CASE("enqueue: exception (full)")
{
  try
  {
    q->enqueue(6);
  }
  catch (int e)
  {
    CHECK(e == 2); //QUEUE_ERR_FULL = 2
  }
}

TEST_CASE("dequeue: good cases, front, and enqueue (after dequeueing)")
{
  CHECK(q->dequeue() == 1);
  q->enqueue(6);
  CHECK(q->front() == 2);
  CHECK(q->dequeue() == 2);
  CHECK(q->dequeue() == 3);
  q->enqueue(7);
  CHECK(q->front() == 4);
  CHECK(q->dequeue() == 4);
  CHECK(q->dequeue() == 5);
  CHECK(q->dequeue() == 6);
  q->enqueue(8);
  CHECK(q->dequeue() == 7);
  CHECK(q->dequeue() == 8);
}

TEST_CASE("dequeue and front: exceptions (empty)")
{
  try
  {
    q->dequeue();
  }
  catch (int e)
  {
    CHECK(e == 1); //QUEUE_ERR_EMPTY = 1
  }

  try
  {
    q->front();
  }
  catch (int e)
  {
    CHECK(e == 1); //QUEUE_ERR_EMPTY = 1
  }

  delete q;
}
