#include <iostream>
//#include "Node.h"
#include "BSTree.h"
/*
 *
 BST - Binary Search Tree

 ordered tree where it's either empty or given a node N, all the
 values in N's left subtree are less than the value in N and all the
 values in N's right subtree are greater than the value in N.




*/
BSTree::BSTree(){
  root = nullptr;
}




// Traversal - visit every node in the tree
// O(n)
std::string BSTree::traverse(Node *n){
  std::string a,b,c;

  if (n==nullptr){
    return "";
  } else {


    /*
     *  pre-order traversal

     1. process the node
     2. recurse to left subtree
     3. recurse to right subtree

     a = std::to_string(n->getData());
     b =  traverse(n->getLeft());
     c =  traverse(n->getRight());


     * post-order traversal

     1. recurse to left subtree
     2. recurse to right subtree
     3. process the node

     a =  traverse(n->getLeft());
     b =  traverse(n->getRight());
     c = std::to_string(n->getData());

    */

    /*
	in-order traversal

	1. recurse left subtree
	2. process node
	3. recurse right subtree
    */

    a =  traverse(n->getLeft());
    b = std::to_string(n->getData());
    c =  traverse(n->getRight());

    return a + ", " + b+ ", " + c;


  }
};

std::string BSTree::get_debug_string(){
  return traverse(root);
};

void BSTree::setup(){
  Node *n = new Node(10);
  root = n;
  n = new Node(20);
  root->setRight(n);
  Node *n2 = new Node(30);
  n->setRight(n2);
  n2 = new Node(15);
  n->setLeft(n2);
  n2 = new Node(5);
  root->setLeft(n2);
  n = new Node(3);
  n2->setLeft(n);
  n = new Node(8);
  n2->setRight(n);

}


int BSTree::search(int value){
  Node *t = root;

  while (t != nullptr){
    int tval = t->getData();
    if (tval==value){
      // here we'd really return a full object
      // with all the stuff associated with value
      // not just an int
      return value;
    }

    if (tval < value){
      t = t->getRight();
    } else {
      t = t->getLeft();
    }

  }

  // if we get here then the value isn't
  // in the tree

  // normally, if we had a tree of objects
  // we could return null but since we only have
  // an int, we can't return an int to represent
  // not found so we'll throw an exception

  throw 1; // we should define our exceptions.



}

// we will always insert new nodes as leaves
void BSTree::insert(int value){

  // make a new node
  Node *newnode = new Node(value);

  // search for where the node would go as a leaf
  // that is, search until we get to null
  // we can use the piggyback strategy of having
  // a second pointer trail the lead pointer
  Node *p = root;
  Node *trailer;


  while (p != nullptr) {
    // note that trailer is one level behind
    trailer = p;
    if (p->getData() == value){
      // do the stuff when the node is already in the tree
      return;
    }
    else if (p->getData() < value){
      p = p->getRight();
    } else {
      p = p->getLeft();
    }
  }

  // handle the special case of the tree
  // being empty (null)
  if (root==nullptr){
    root=newnode;
  } else {
    // trailer points to the node ABOVE where the new node
    // will go.
    // we have to figure out if newnode goes on the
    // left of trailer or on the right of trailer
    if (trailer->getData() < value){
      trailer->setRight(newnode);
    } else {
      trailer->setLeft(newnode);
    }

  }
}

int BSTree::rsearch(int value)
{
  return rsearch(value, root);
}

int BSTree::rsearch(int value, Node *p)
{
  // base cases
  if (p == nullptr)
    throw TREE_ERR_VALUE_NOT_FOUND;
  else if (p->getData() == value)
    return value;

  int pval = p->getData();
  if (value > pval)
    return rsearch(value, p->getRight());
  else
    return rsearch(value, p->getLeft());
}

void BSTree::rinsert(int value)
{
  rinsert(value, root);
}

void BSTree::rinsert(int value, Node *p)
{
  Node *newnode = new Node(value);

  if (root == nullptr)
  {
    root = newnode;
    return;
  }

  int pval = p->getData();

  if (pval == value)
    return;
  else if (value > pval)
  {
    if (p->getRight() == nullptr)
      p->setRight(newnode);
    else
      rinsert(value, p->getRight());
  }
  else
  {
    if (p->getLeft() == nullptr)
      p->setLeft(newnode);
    else
      rinsert(value, p->getLeft());
  }
}

void BSTree::remove(int value)
{
  Node *p = root;
  Node *trailer = nullptr;
  Node *pleft, *pright;
  int pval;

  while (p != nullptr)
  {
    pval = p->getData();
    pleft = p->getLeft();
    pright = p->getRight();

    // we are at the node we want to delete
    if (pval == value)
    {
      // p is a leaf or p has one child
      if (pleft == nullptr || pright == nullptr)
      {
        delete p;
        p = nullptr;

        Node *newchild;

        if (pleft == nullptr && pright == nullptr) // p is a leaf
          newchild = nullptr;
        else if (pleft != nullptr) // p only has left child
          newchild = pleft;
        else // p only has right child
          newchild = pright;

        if (trailer == nullptr) // removing root
          root = newchild;
        else if (value > trailer->getData()) // p is the right child of parent
          trailer->setRight(newchild);
        else // p is the left child of parent
          trailer->setLeft(newchild);
      }
      else // p has 2 children
      {
        Node *p2 = pleft; // left subtree
        int max = p2->getData(); //p2 will never be nullptr here
        // so it will always go into the while loop

        while (p2 != nullptr)
        {
          // largest element in left subtree
          max = p2->getData();
          p2 = p2->getRight();
        }

        remove(max); // will have 0 or 1 children
        p->setData(max);
      }

      return;
    }
    else if (value > pval)
    {
      trailer = p;
      p = p->getRight();
    }
    else
    {
      trailer = p;
      p = p->getLeft();
    }
  }
  // here, this means that p = nullptr
  // value to remove was never found
  // or tree was empty to begin with
  throw TREE_ERR_VALUE_NOT_FOUND;
}

int BSTree::count_leaves(Node *p)
{
  // base case
  if (p == nullptr)
    return 0;
  else if (p->getLeft() == nullptr && p->getRight() == nullptr)
    return 1;

  // otherwise
  int total = 0;
  total += count_leaves(p->getLeft());
  total += count_leaves(p->getRight());
  return total;
}

int BSTree::count_leaves()
{
  return count_leaves(root);
}

int BSTree::get_height()
{
  
}
