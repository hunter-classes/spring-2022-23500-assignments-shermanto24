#include <iostream>
#include "BSTree.h"

BSTree::BSTree()
{
  root = nullptr;
}

void BSTree::insert(int d)
{

}

// for reference
/*
std::string List::getDebugRHelper(Node *l)
{
  if (l == nullptr)
    return "";
  else
  {
    return l->getData() + "-->" + getDebugRHelper(l->getNext());
  }
}

std::string List::getDebugR()
{
  return getDebugRHelper(head);
}
*/

// code as recursive routine to print out all nodes in BSTree
// don't care abt order
// recurse to both left and right child
std::string BSTree::get_debug_string_helper(Node *n)
{
  if (n != nullptr && n->getLeft() == nullptr && n->getRight() == nullptr)
    return std::to_string(n->getData());
  else if (n == nullptr)
    return "";
  else
  {
    std::string result = std::to_string(n->getData()) + "\n";
    if (n->getLeft() != nullptr)
      result += get_debug_string_helper(n->getLeft()) + " ";
    if (n->getRight() != nullptr)
      result += get_debug_string_helper(n->getRight());
    return result;
  }
}

std::string BSTree::get_debug_string()
{
  return get_debug_string_helper(root);
}

void BSTree::setup()
{
  Node *n = new Node(10);
  root = n;
  n = new Node(20);
  root->setLeft(n);
  n = new Node(30);
  root->setRight(n);
  n = new Node(40);
  root->getLeft()->setLeft(n);
}
