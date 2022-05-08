#include <iostream>
#include "BSTree.h"
#include <cstdlib>
#include <ctime>

int main()
{
  std::cout << "-------------------- PART 1 --------------------\n\n" << '\n';

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
    std::cout << "Tried calling t->rsearch(1). but not found" << '\n';
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
  std::cout << "\n\n-------------------- PART 2 --------------------\n\n" << '\n';

  std::cout << "----- Testing remove -----\n" << '\n';

  BSTree *t3 = new BSTree();
  std::cout << "Created a BSTree t3" << '\n';
  t3->rinsert(10);
  t3->rinsert(5);
  t3->rinsert(20);
  t3->rinsert(7);
  t3->rinsert(6);
  std::cout << "t3 = " << t3->get_debug_string() << '\n';

  std::cout << "\n-- Removing a leaf --\n" << '\n';
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

  std::cout << "\n-- Removing a node with one child --" << '\n';
  t3->rinsert(6);
  std::cout << "\nInserted 6 back into t3" << '\n';
  std::cout << "t3 = " << t3->get_debug_string() << '\n';
  t3->remove(5);
  std::cout << "Removing a node with one (right) child: after t3->remove(5)" << '\n';
  std::cout << "t3 = " << t3->get_debug_string() << '\n';
  t3->rinsert(15);
  t3->rinsert(12);
  t3->rinsert(18);
  std::cout << "\nInserted 15, 12, and 18 into t3" << '\n';
  std::cout << "t3 = " << t3->get_debug_string() << '\n';
  t3->remove(20);
  std::cout << "Removing a node with one (left) child: after t3->remove(20)" << '\n';
  std::cout << "t3 = " << t3->get_debug_string() << '\n';

  std::cout << "\n-- Removing at root (is leaf or has one child) --" << '\n';
  BSTree *t4 = new BSTree();
  std::cout << "\nCreated a BSTree t4" << '\n';
  t4->rinsert(100);
  std::cout << "t4 = " << t4->get_debug_string() << '\n';
  t4->remove(100);
  std::cout << "Removing a leaf (root): after t4->remove(100)" << '\n';
  std::cout << "t4 = " << t4->get_debug_string() << '\n';

  t4->rinsert(100);
  t4->rinsert(150);
  std::cout << "\nInserted 100 and 150 into t4" << '\n';
  std::cout << "t4 = " << t4->get_debug_string() << '\n';
  t4->remove(100);
  std::cout << "Removing root when it has one (right) child: after t4->remove(100)" << '\n';
  std::cout << "t4 = " << t4->get_debug_string() << '\n';

  t4->rinsert(50);
  t4->rinsert(75);
  std::cout << "\nInserted 50 and 75 into t4" << '\n';
  std::cout << "t4 = " << t4->get_debug_string() << '\n';
  t4->remove(150);
  std::cout << "Removing root when it has one (left) child: after t4->remove(150)" << '\n';
  std::cout << "t4 = " << t4->get_debug_string() << '\n';

  std::cout << "\n-- Removing a node with two children --" << '\n';

  t3->rinsert(11);
  t3->rinsert(13);
  t3->rinsert(14);
  std::cout << "\nInserted 11, 13, and 14 into t3" << '\n';
  std::cout << "t3 = " << t3->get_debug_string() << '\n';
  t3->remove(15);
  std::cout << "Removing a node with two children: after t3->remove(15)" << '\n';
  std::cout << "t3 = " << t3->get_debug_string() << '\n';
  t3->remove(10);
  std::cout << "\nRemoving root (has two children): after t3->remove(10)" << '\n';
  std::cout << "t3 = " << t3->get_debug_string() << '\n';

  try
  {
    t3->remove(10);
  }
  catch (int e)
  {
    std::cout << "Tried calling t3->remove(10), but not found" << '\n';
  }
}
