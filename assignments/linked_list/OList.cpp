#include <iostream>
#include "OList.h"

OList::OList()
{
  head = nullptr;
}

OList::~OList()
{
  ONode *trailer;
  std::cerr << "Destructing\n";
  while (head != nullptr)
  {
    trailer = head;
    head = head->getNext();
    delete trailer;
  }
}

void OList::insert(int value)
{
  ONode *tmp = new ONode(value);

  ONode *walker = head;
  ONode *trailer = nullptr;

  while (walker != nullptr)
  {
    //value should be inserted:
    //at the beginning
    if (walker == head && value <= walker->getData())
    {
      tmp->setNext(head);
      head = tmp;
      walker = nullptr;
    }
    else if (walker->getNext() == nullptr && value >= walker->getData()) //at the end
    {
      walker->setNext(tmp);
      walker = nullptr;
    }
    else //somewhere in between
    {
      int prev_val = trailer->getData();
      int next_val = walker->getNext()->getData();
      if (prev_val <= value && value <= next_val)
      {
        tmp->setNext(walker);
        trailer = tmp;
        walker = nullptr;
      }
    }
  }
}

std::string OList::toString()
{
  std::string result;
  ONode *walker = head;
  while (walker != nullptr)
  {
    result += walker->getData() + "->";
    walker = walker->getNext();
  }
  return result;
}

bool OList::contains(int value)
{
  ONode *walker = head;
  while (walker != nullptr)
  {
    if (walker->getData() == value)
      return true;
    walker = walker->getNext();
  }
  return false;
}

int OList::get(int loc)
{
  ONode *walker = head;
  int counter = 0;
  while (walker != nullptr)
  {
    if (counter == loc)
      return walker->getData();
    counter++;
    walker = walker->getNext();
  }
  return 0;
}

void OList::remove(int loc)
{

}

void OList::reverse()
{

}
