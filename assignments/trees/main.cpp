#include <iostream>
#include "BSTree.h"

int main()
{
  BSTree *t = new BSTree();
  t->setup();
  std::cout << "Created a BSTree t" << '\n';
  std::cout << "t = " << t->get_debug_string() << '\n';

  // testing rsearch
  std::cout << "\n----- Testing rsearch -----\n" << '\n';
  std::cout << "t->rsearch(8) = " << t->rsearch(8) << '\n';
  try
  {
    std::cout << t->rsearch(1) << '\n';
  }
  catch (int e)
  {
    std::cout << "Tried calling t->rsearch(1). but it's not in the tree" << '\n';
  }

  // testing rinsert
  std::cout << "\n----- Testing rinsert -----\n" << '\n';
  t->rinsert(1);
  std::cout << "After t->rinsert(1), t = ";
  std::cout << t->get_debug_string() << '\n';
  std::cout << "t->rsearch(1) = " << t->rsearch(1) << '\n';
  t->rinsert(17);
  std::cout << "After t->rinsert(17), t = ";
  std::cout << t->get_debug_string() << '\n';
  std::cout << "t->rsearch(17) = " << t->rsearch(17) << '\n';

  // generating random numbers and inserting them
  // into a new BSTree t2
  BSTree
}
