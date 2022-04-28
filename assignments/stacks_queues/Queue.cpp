#include "Queue.h"

Queue::Queue()
{
  head = 0;
  tail = 0; //where we will enqueue the next item
  num_elems = 0;
}

// add an item to the back of the queue
void Queue::enqueue(int num)
{
  // check if full
  if (is_full())
    throw QUEUE_ERR_FULL;

  // add num to the end
  arr[tail%5] = num;
  /*
  if (tail == 4) //last elem
  {
    tail = 0; //wrap around
    head++; //??
  }
    //do smth with head?
  else*/
  tail++;
  num_elems++;
}

// remove and return the item from the front of the queue
int Queue::dequeue()
{
  if (is_empty())
    throw QUEUE_ERR_EMPTY;

  //int front = arr[head];
  int front = arr[head%5];
  head++;
  /*
  if (head != 1) // if head == 1, it'll be empty
    head++;
  if (!is_empty()) // if empty, head should still be at index 0
    head++;
    */
  num_elems--;
  return front;
}

// return but do not remove the item from the front of the queue
int Queue::front()
{
  if (is_empty())
    throw QUEUE_ERR_EMPTY;

  return arr[head];
}

bool Queue::is_empty()
{
  if (num_elems == 0)
    return true;
  else
    return false;
}

bool Queue::is_full()
{
  if (num_elems == 5)
    return true;
  else
    return false;
}
