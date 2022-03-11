#include <iostream>
#include "OList.h"

int main(int argc, char *argv[])
{
  OList *l1 = new OList();
  std::cout << "Created a new OList l1" << '\n';

  l1->insert(3); //when there are no elements
  l1->insert(1); //at the beginning
  l1->insert(4); //at the end
  l1->insert(2); //in between

  std::cout << "\nAfter inserting 3, 1, 4, and 2" << '\n';
  std::cout << "l1 = " << l1->toString() << '\n';

  std::cout << "\nl1->contains(1) = " << l1->contains(1) << '\n';
  std::cout << "l1->contains(20) = " << l1->contains(20) << '\n';

  std::cout << "\nl1->get(0) = " << l1->get(0) << '\n';
  std::cout << "l1->get(3) = " << l1->get(3) << '\n';

  l1->remove(0);
  std::cout << "\nAfter l1->remove(0)" << '\n';
  std::cout << "l1 = " << l1->toString() << '\n';

  l1->remove(2);
  std::cout << "After l1->remove(2)" << '\n';
  std::cout << "l1 = " << l1->toString() << '\n';
}
