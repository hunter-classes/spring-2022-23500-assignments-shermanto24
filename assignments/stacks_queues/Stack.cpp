#include "Stack.h"

Stack::Stack()
{
  head = nullptr;
}

Stack::~Stack()
{
  Node *trailer;
  std::cerr << "Destructing\n";

  while (head != nullptr)
  {
    trailer = head;
    head = head->getNext();
    delete trailer;
  }
}

void Stack::push(std::string str)
{
  /*
  if () //full?
  {
    throw STACK_ERR_FULL;
  }
  */
  Node *new_node = new Node(str);
  new_node->setNext(head); //head-->...-->nullptr
                           //new_node-^
  head = new_node; //head-->new_node-->...-->nullptr
}

// remove and return the top item
std::string Stack::pop()
{
  if (is_empty())
    throw STACK_ERR_EMPTY;

  Node *node_to_remove = head;
  std::string removed_data = node_to_remove->getData();
  head = head->getNext();
  delete node_to_remove;
  return removed_data;
}

// return but do not remove the top item
std::string Stack::top()
{
  if (is_empty())
    throw STACK_ERR_EMPTY;

  return head->getData();
}

bool Stack::is_empty()
{
  if (head == nullptr)
    return true;
  else
    return false;
}
