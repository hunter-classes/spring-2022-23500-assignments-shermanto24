#include <iostream>
#include "BSTree.h"
#include <cstdlib>
#include <ctime>

int main()
{
  srand(time(NULL));

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
  std::cout << "\n----- Inserting random values to trace -----\n" << '\n';
  BSTree *t2 = new BSTree();
  std::cout << "Created a BSTree t2" << '\n';

  for (int i = 0; i < 10; i++)
    t2->rinsert(rand()%100 + 1);

  std::cout << "t2 = " << t2->get_debug_string() << '\n';

  // testing part 2
  std::cout << "\n\n-------------------- Part 2 --------------------\n\n" << '\n';

  BSTree *t3 = new BSTree();
  std::cout << "Created a BSTree t3" << '\n';
  t3->rinsert(10);
  t3->rinsert(5);
  t3->rinsert(20);
  t3->rinsert(7);
  t3->rinsert(6);
  std::cout << "t3 = " << t3->get_debug_string() << '\n';

  std::cout << "\n----- Testing remove -----\n" << '\n';
  t3->remove(6);
  std::cout << "Removing a leaf: after t3->remove(6)" << '\n';
  std::cout << "t3 = " << t3->get_debug_string() << '\n';
  try
  {
    std::cout << t3->rsearch(6) << '\n';
  }
  catch (int e)
  {
    std::cout << "Tried calling t3->rsearch(6), but not found" << '\n';
  }
}
