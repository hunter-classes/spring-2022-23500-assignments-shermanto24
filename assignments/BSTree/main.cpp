#include <iostream>
#include "Node.h"
#include "BSTree.h"

int main()
{
  // video 2
  Node *n = new Node(20);
  //std::cout << n->getData() << '\n';
  Node *n2 = new Node(30);
  n->setLeft(n2);
  n2 = new Node(40);
  n->setRight(n2);

  //std::cout << n->getLeft()->getData() << '\n';
  //std::cout << n->getRight()->getData() << '\n';

  // video 2 task
  Node *x1 = new Node(10);
  Node *x2 = new Node(20);
  Node *x3 = new Node(30);
  Node *x4 = new Node(40);
  Node *x5 = new Node(50);
  Node *x6 = new Node(60);
  Node *x7 = new Node(70);

  x1->setLeft(x2);
  x2->setLeft(x3);
  x3->setLeft(x4);

  x1->setRight(x5);
  x5->setLeft(x6);
  x5->setRight(x7);

  std::cout << "Video 2 Task\n" << '\n';
  std::cout << "   " << x1->getData() << '\n';
  std::cout << x1->getLeft()->getData() << "    " << x1->getRight()->getData() << '\n';
  std::cout << x2->getLeft()->getData() << "   " << x5->getLeft()->getData()
     << " " << x5->getRight()->getData() << '\n';
  std::cout << x3->getLeft()->getData() << '\n';

  // video 5
  std::cout << "\nVideo 5 Task\n" << '\n';
  BSTree *t = new BSTree();
  t->setup();
  std::cout << "Testing get_debug_string" << '\n';
  std::cout << t->get_debug_string() << '\n';
}
