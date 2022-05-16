#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Dictionary.h"

Dictionary *d = new Dictionary();
Person *p1 = new Person("a", "a", 0);
Person *p2 = new Person("a", "b", 1);
Person *p3 = new Person("a", "c", 2);
Person *p4 = new Person("a", "d", 3);
Person *p5 = new Person("a", "e", 4);
Person *p6 = new Person("John", "Smith", 5);
Person *p7 = new Person("hello", "world", 6);
Person *p8 = new Person("MARIO", "mario", 7);
Person *p9 = new Person("Another", "Name", 8);

TEST_CASE("insert and get_all_keys tests")
{
  // insert nullptr
  try
  {
    d->insert(nullptr);
  }
  catch (int e)
  {
    CHECK(e == 1);
  }

  // regular insert cases
  d->insert(p1);
  CHECK(d->get_all_keys() == "a, a-> |  |  |  |  | ");
  d->insert(p2);
  CHECK(d->get_all_keys() == "a, a-> | b, a-> |  |  |  | ");
  d->insert(p3);
  CHECK(d->get_all_keys() == "a, a-> | b, a-> | c, a-> |  |  | ");
  d->insert(p4);
  CHECK(d->get_all_keys() == "a, a-> | b, a-> | c, a-> | d, a-> |  | ");
  d->insert(p5);
  CHECK(d->get_all_keys() == "a, a-> | b, a-> | c, a-> | d, a-> | e, a-> | ");

  d->insert(p6);
  CHECK(d->get_all_keys() == "a, a-> | b, a-> | Smith, John->c, a-> | d, a-> | e, a-> | ");
  d->insert(p7);
  CHECK(d->get_all_keys() == "world, hello->a, a-> | b, a-> | Smith, John->c, a-> | d, a-> | e, a-> | ");
  d->insert(p8);
  CHECK(d->get_all_keys() == "world, hello->a, a-> | b, a-> | Smith, John->c, a-> | mario, MARIO->d, a-> | e, a-> | ");
  d->insert(p9);
  CHECK(d->get_all_keys() == "world, hello->a, a-> | b, a-> | Name, Another->Smith, John->c, a-> | mario, MARIO->d, a-> | e, a-> | ");
}

TEST_CASE("retrieve tests")
{
  // name does not exist in d
  CHECK(d->retrieve("returns, nullptr") == nullptr);
  CHECK(d->retrieve("non, existent") == nullptr);

  // names that do exist in d
  CHECK(d->retrieve("a, a") == p1);
  CHECK(d->retrieve("b, a") == p2);
  CHECK(d->retrieve("c, a") == p3);
  CHECK(d->retrieve("d, a") == p4);
  CHECK(d->retrieve("e, a") == p5);
  CHECK(d->retrieve("Smith, John") == p6);
  CHECK(d->retrieve("world, hello") == p7);
  CHECK(d->retrieve("mario, MARIO") == p8);
  CHECK(d->retrieve("Name, Another") == p9);
}

TEST_CASE("hash_func tests")
{
  CHECK(d->hash_func(p1->get_name()) == 0);
  CHECK(d->hash_func(p2->get_name()) == 1);
  CHECK(d->hash_func(p3->get_name()) == 2);
  CHECK(d->hash_func(p4->get_name()) == 3);
  CHECK(d->hash_func(p5->get_name()) == 4);

  CHECK(d->hash_func(p6->get_name()) == 2);
  CHECK(d->hash_func(p7->get_name()) == 0);
  CHECK(d->hash_func(p8->get_name()) == 3);
  CHECK(d->hash_func(p9->get_name()) == 2);

  delete d;
}
