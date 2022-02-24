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
      new_node->setNext(p);
      p = new_node;
    }
 }
}
