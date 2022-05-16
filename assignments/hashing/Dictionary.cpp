#include "Dictionary.h"

Dictionary::Dictionary()
{
  for (int i = 0; i < 5; i++)
    arr[i] = new List();
}

Dictionary::~Dictionary()
{
  for (int i = 0; i < 5; i++)
    delete arr[i];
}

int Dictionary::hash_func(std::string key)
{
  int result = 0;
  for (int i = 0; i < key.length(); i++)
    result += key[i];
  return result % 5;
}

void Dictionary::insert(Person *p)
{
  if (p == nullptr)
    throw DICT_ERR_INSERT_NULLPTR;

  int pos = hash_func(p->get_name());
  arr[pos]->insert(p);
}

Person* Dictionary::retrieve(std::string name)
{
  int pos = hash_func(name);
  List *list = arr[pos];

  Node *walker = list->get_head();
  while (walker != nullptr)
  {
    if (walker->getData()->get_name() == name)
      return walker->getData();
    walker = walker->getNext();
  }

  return nullptr;
}

std::string Dictionary::get_all_keys()
{
  std::string result = "";
  for (int i = 0; i < 5; i++)
  {
    result += arr[i]->toString();
    result += " | ";
  }
  return result;
}
