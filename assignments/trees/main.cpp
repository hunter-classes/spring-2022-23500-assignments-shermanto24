#include <iostream>
#include "BSTree.h"

int main()
{
  BSTree *t = new BSTree();
  t->setup();
  std::cout << "Created a BSTree t" << '\n';
  std::cout << "t = " << t->get_debug_string() << '\n';
  
  std::cout << "\nTesting rsearch\n" << '\n';
  std::cout << "t->rsearch(8) = " << t->rsearch(8) << '\n';
  try
  {
    std::cout << t->rsearch(1) << '\n';
  }
  catch (int e)
  {
    std::cout << "Tried calling t->rsearch(1). but it's not in the tree" << '\n';
  }
}
