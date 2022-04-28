#pragma once
#define QUEUE_ERR_EMPTY 1
#define QUEUE_ERR_FULL 2

class Queue
{
private:
  int arr[5];
  int head, tail;
  int num_elems;

public:
  Queue();
  void enqueue(int num); // add an item to the back of the queue
  int dequeue(); // remove and return the item from the front of the queue
  int front(); // return but do not remove the item from the front of the queue
  bool is_empty();
  bool is_full();
};
