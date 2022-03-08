#include <iostream>
#include "ONode.h"

ONode::ONode() : next(nullptr)
{

}

ONode::ONode(int data)
{
  this->data = data;
  this->next = nullptr;
}

ONode::ONode(int data, ONode *next)
{
  this->data = data;
  this->next = next;
}

//setters
void ONode::setData(int data)
{
  this->data = data;
}

void ONode::setNext(ONode *next)
{
  this->next = next;
}

//getters
int ONode::getData()
{
  return this->data;
}

ONode *ONode::getNext()
{
  return this->next;
}
