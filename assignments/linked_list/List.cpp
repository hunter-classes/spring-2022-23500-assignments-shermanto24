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
  head = new_node; //head doesn't have a next?
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
