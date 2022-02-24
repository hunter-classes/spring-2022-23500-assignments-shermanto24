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
  std::cout << "\nTesting my code\n" << '\n';

  std::cout << "Testing locate" << '\n';
  Node *p0 = l1->locate(0);
  Node *p1 = l1->locate(1);
  Node *p2 = l1->locate(2);

  std::cout << "l1->locate(0)->getData = " << p0->getData() << '\n';
  std::cout << "l1->locate(1)->getData = " << p1->getData() << '\n';
  std::cout << "l1->locate(2)->getData = " << p2->getData() << '\n';

}
