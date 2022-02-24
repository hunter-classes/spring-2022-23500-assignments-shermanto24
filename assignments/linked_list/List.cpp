#include <iostream>
#include "List.h"

List::List()
{
  head = nullptr;
}

void List::insert(std::string data)
{
  //create a new node
  Node *new_node = new Node(data);

  //insert the new node
  new_node->setNext(head);
  head = new_node; //head doesn't have a next? / it's always nullptr
                   //so we can't do head->setNext(new_node)
}

std::string List::toString()
{
  /*
  if (head == nullptr)
    return "";
  */

  Node *walker = head;
  std::string s = "";
  while (walker != nullptr) //replaces prev
  {
    s = s + walker->getData() + "-->";
    walker = walker->getNext(); //i++;
  }

  s = s + "nullptr";
  return s;
}

//----------------- MY CODE -----------------

Node* List::locate(int index)
{
  Node *walker = head;
  int currPos = 0;

  while (walker != nullptr)
  {
    if (currPos == index)
      return walker;
    else
    {
      currPos++;
      walker = walker->getNext();
    }
  }
  return walker;
}

void List::insert(int index, std::string data)
{
  if (index <= 0)
    insert(data);
  else
  {
    Node *p = locate(index-1);
    if (p != nullptr) //p == nullptr means index is too big
    {
      Node *new_node = new Node(data);
      Node *temp = p->getNext();
      p->setNext(new_node);
      new_node->setNext(temp);
    }
  }
}

void List::remove(int index)
{
  Node *p1 = locate(index-1); //before the skipped
  Node *p2 = locate(index+1); //after the skipped
  Node *removed = locate(index);
  p1->setNext(p2);
  delete removed;
  removed = nullptr;
}

List::~List()
{
  Node *walker = head;

  while (walker != nullptr)
  {
    Node *to_delete = walker;
    delete to_delete;
    to_delete = nullptr;
    walker = walker->getNext();
  }
}
