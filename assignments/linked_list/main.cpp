#include <iostream>
#include "Node.h"

int main(int argc, char *argv[])
{
  Node *p1 = new Node();
  //*p1                    data     next
  //                       100
  //[100]  ---------->  ["hello"]  nullptr
  //basically *p1 makes a pointer (box)
  //and new allocates memory (box) elsewhere
  //sets next to be nullptr
  p1->setData("hello"); //same as *(p1).setData

  Node *p2 = new Node("World");
  p1->setNext(p2);

  std::cout << p1->getData() << '\n';
  std::cout << p2->getData() << '\n';
  std::cout << p1->getNext()->getData() << '\n';

  p2 = new Node("!");
  //at this point, p1's next is still "world"
  //bc we haven't changed where p1's next points to
  //this just allocates more memory elsewhere

  p1->getNext()->setNext(p2);
  //sets p1's next's next to be p2
  //getNext() returns a pointer, so this is the same as
  //*(*(p1).getNext()).setNext(p2);

  std::cout << p1->getData() << '\n';
  std::cout << p1->getNext()->getData() << '\n';
  std::cout << p1->getNext()->getNext()->getData() << '\n';

  Node *walker = p1;
  std::cout << walker->getData() << '\n';

  //next line is i=i+1 of pointers
  walker = walker->getNext(); //walker = p1->getNext()
  std::cout << walker->getData() << '\n';

  walker = walker->getNext(); //walker = p1->getNext()
  std::cout << walker->getData() << '\n';

  walker = p1;
  while (walker != nullptr)
  {
    std::cout << walker->getData() << '\n';
    walker = walker->getNext();
  }

  //at this point, walker points to (refers to) nullptr
  //if we try to dereference it, we get a segfault
  //std::cout << walker->getData() << '\n';

  //---------------- MY CODE ----------------

  //adding more items to the list
  Node *p4 = new Node("last");
  Node *p3 = new Node("?", p4);

  p2->setNext(p3);
  p2->getNext()->setNext(p4);

  std::cout << "-----------" << '\n';
  std::cout << p2->getNext()->getData() << '\n';
  std::cout << p3->getData() << '\n';

  std::cout << p3->getNext()->getData() << '\n';
  std::cout << p4->getData() << '\n';
}
