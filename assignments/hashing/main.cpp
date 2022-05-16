#include <iostream>
#include "Dictionary.h"

int main()
{
  Dictionary *d = new Dictionary();
  std::cout << "Created Dictionary d" << '\n';
  std::cout << "d->get_all_keys() = " << d->get_all_keys() << '\n';
  std::cout << "d->retrieve(\"nonexistent, name\") = " << d->retrieve("nonexistent, name") << " (nullptr)" << '\n';

  Person *p1 = new Person("a", "a", 0);
  std::cout << "\nCreated Person p1 named " << p1->get_name() << '\n';
  d->insert(p1);
  std::cout << "Inserted p1 into d" << '\n';
  std::cout << "d->hash_func(\"a, a\") = " << d->hash_func("a, a") << '\n';
  std::cout << "d->retrieve(\"a, a\")->get_name() = " << d->retrieve("a, a")->get_name() << '\n';
  std::cout << "d->get_all_keys() = " << d->get_all_keys() << '\n';

  Person *p2 = new Person("a", "b", 1);
  d->insert(p2);
  Person *p3 = new Person("a", "c", 2);
  d->insert(p3);
  Person *p4 = new Person("a", "d", 3);
  d->insert(p4);
  Person *p5 = new Person("a", "e", 4);
  d->insert(p5);

  std::cout << "\nInserted p2, p3, p4, and p5 into d" << '\n';
  std::cout << "d->get_all_keys() = " << d->get_all_keys() << '\n';

  Person *p6 = new Person("John", "Smith", 5);
  d->insert(p6);
  std::cout << "\nInserted p6 named " << p6->get_name() << " into d" << '\n';
  std::cout << "d->hash_func(\"Smith, John\") = " << d->hash_func("Smith, John") << '\n';
  std::cout << "d->retrieve(\"Smith, John\")->get_name() = " << d->retrieve("Smith, John")->get_name() << '\n';
  std::cout << "d->get_all_keys() = " << d->get_all_keys() << '\n';
}
