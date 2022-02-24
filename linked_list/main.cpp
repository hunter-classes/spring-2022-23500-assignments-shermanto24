#include <iostream>
#include "List.h"

int main(int argc, char *argv[])
{
  List *l1 = new List();
  std::cout << l1->toString() << '\n';

  l1->insert("a");
  l1->insert("b");
  l1->insert("c");

  std::cout << l1->toString() << '\n';

  //testing my code
  std::cout << "\n----- Testing my code -----\n" << '\n';

  std::cout << "Testing locate\n" << '\n';
  Node *p0 = l1->locate(0);
  Node *p1 = l1->locate(1);
  Node *p2 = l1->locate(2);

  std::cout << "l1->locate(0)->getData() = " << p0->getData() << '\n';
  std::cout << "l1->locate(1)->getData() = " << p1->getData() << '\n';
  std::cout << "l1->locate(2)->getData() = " << p2->getData() << '\n';

  std::cout << "\nTesting insert(index, data)\n" << '\n';
  l1->insert(2, "d");
  std::cout << "After insert(2, \"d\")" << '\n';
  std::cout << l1->toString() << '\n';
  l1->insert(1, "e");
  std::cout << "After insert(1, \"e\")" << '\n';
  std::cout << l1->toString() << '\n';
  l1->insert(0, "f");
  std::cout << "After insert(0, \"f\")" << '\n';
  std::cout << l1->toString() << '\n';

  std::cout << "\nTesting remove(index)\n" << '\n';
  l1->remove(1);
  std::cout << "After remove(1)" << '\n';
  std::cout << l1->toString() << '\n';
  l1->remove(3);
  std::cout << "After remove(3)" << '\n';
  std::cout << l1->toString() << '\n';

  std::cout << "\nTesting destructor" << '\n';
  delete l1;
  std::cout << "After delete l1, calling toString() results in an error" << '\n';
  //std::cout << l1->toString() << '\n';
}
