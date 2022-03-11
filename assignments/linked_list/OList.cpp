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

  //if we have no elements
  if (walker == nullptr)
  {
    tmp->setNext(head);
    head = tmp;
    walker = nullptr;
  }

  //the OList has at least 1 element
  while (walker != nullptr)
  {
    //value should be inserted:
    //at the beginning
    if (trailer == nullptr && value <= walker->getData())
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
    else if (trailer == nullptr) //to avoid trying to get trailer's data
    {
      trailer = walker; //if we are on our first iteration
      walker = walker->getNext();
    }
    else //somewhere in between
    {
      int prev_val = trailer->getData();
      int next_val = walker->getData();
      if (prev_val <= value && value <= next_val)
      {
        tmp->setNext(walker);
        trailer->setNext(tmp);
        walker = nullptr;
      }
      else
      {
        trailer = walker;
        walker = walker->getNext();
      }
    }
  }
}

std::string OList::toString()
{
  std::string result = "head --> ";
  ONode *walker = head;
  while (walker != nullptr)
  {
    result += std::to_string(walker->getData()) + " --> ";
    walker = walker->getNext();
  }
  result += "nullptr";
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
  ONode *walker = head;
  ONode *trailer = nullptr;

  while (loc > 0 && walker != nullptr)
  {
    trailer = walker;
    walker = walker->getNext();
    loc--;
  }

  //trying to remove past the last element
  if (walker == nullptr || loc < 0)
    throw std::out_of_range("out of range");

  //removing the 0th element
  if (trailer == nullptr)
  {
    head = walker->getNext();
    delete walker;
  }
  else
  {
    trailer->setNext(walker->getNext());
    delete walker;
  }
}

void OList::reverse()
{

}
