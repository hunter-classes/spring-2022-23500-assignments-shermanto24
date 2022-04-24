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

  if (head == nullptr) // empty
  {
    new_node->setNext(head); //new_node-->nullptr
    head = new_node; //head-->new_node-->nullptr
  }
  else //fix this
  {
    Node *next = head->getNext();
    head->setNext(new_node);
    new_node->setNext(next);
  }
  //
}

// remove and return the top item
std::string Stack::pop()
{
  if (is_empty())
    throw STACK_ERR_EMPTY;

  Node *top = head->getNext();
  Node *next = top->getNext();
  std::string top_str = top->getData();
  head->setNext(next);
  delete top;
  return top_str;
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
