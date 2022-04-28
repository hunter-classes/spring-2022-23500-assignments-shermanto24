#include <iostream>
#include "Stack.h"
#include "Queue.h"

int main()
{
  // testing Stack
  std::cout << "----- Testing Stack -----\n" << '\n';
  Stack *s = new Stack();
  std::cout << "Created Stack s" << '\n';
  std::cout << "s->is_empty() == " << std::boolalpha << s->is_empty() << '\n';
  try
  {
    std::cout << s->top() << '\n';
  }
  catch (int e)
  {
    std::cout << "Tried to print s->top(), but s is empty" << '\n';
  }

  std::cout << "\nTesting push and top\n" << '\n';
  s->push("hello");
  std::cout << "After s->push(\"hello\"), s->top() == " << s->top() << '\n';
  std::cout << "s->is_empty() == " << std::boolalpha << s->is_empty() << '\n';
  s->push("world");
  std::cout << "After s->push(\"world\"), s->top() == " << s->top() << '\n';
  s->push("!");
  std::cout << "After s->push(\"!\"), s->top() == " << s->top() << '\n';

  std::cout << "\nTesting pop\n" << '\n';
  s->pop();
  std::cout << "After s->pop(), s->top() == " << s->top() << '\n';
  s->pop();
  std::cout << "After s->pop(), s->top() == " << s->top() << '\n';
  s->pop();
  std::cout << "Called s->pop()\n" << '\n';

  try
  {
    std::cout << s->top() << '\n';
  }
  catch (int e)
  {
    std::cout << "Tried to print s->top(), but s->empty() == " << std::boolalpha << s->is_empty() << '\n';
  }
  try
  {
    s->pop();
  }
  catch (int e)
  {
    std::cout << "Tried to call s->pop(), but s->empty() == " << std::boolalpha << s->is_empty() << '\n';
  }

  delete s;

  // testing Queue
  std::cout << "\n----- Testing Queue -----\n" << '\n';
  Queue *q = new Queue();
  std::cout << "Created Queue q" << '\n';
  std::cout << "q->is_empty() == " << std::boolalpha << q->is_empty() << '\n';
  try
  {
    std::cout << q->front() << '\n';
  }
  catch (int e)
  {
    std::cout << "Tried to call q->front(), but q is empty" << '\n';
  }

  std::cout << "\nTesting enqueue, front, and is_full\n" << '\n';
  q->enqueue(1);
  std::cout << "After q->enqueue(1), q->front() == " << q->front() << '\n';
  std::cout << "q->is_empty() == " << std::boolalpha << q->is_empty() << '\n';
  q->enqueue(2);
  std::cout << "After q->enqueue(2), q->front() == " << q->front() << '\n';
  q->enqueue(3);
  q->enqueue(4);
  q->enqueue(5);
  std::cout << "Called q->enqueue(3), q->enqueue(4), q->enqueue(5)" << '\n';
  try
  {
    q->enqueue(6);
  }
  catch (int e)
  {
      std::cout << "Tried to call q->enqueue(6), but q->is_full() == " << std::boolalpha << q->is_full() << '\n';
  }

  std::cout << "\nTesting dequeue\n" << '\n';
  std::cout << "q->dequeue() == " << q->dequeue() << '\n';
  std::cout << "q->dequeue() == " << q->dequeue() << '\n';
  std::cout << "q->dequeue() == " << q->dequeue() << '\n';
  q->enqueue(6);
  std::cout << "After q->enqueue(6), q->front() == " << q->front() << '\n';
  std::cout << "q->dequeue() == " << q->dequeue() << '\n';
  std::cout << "q->dequeue() == " << q->dequeue() << '\n';
  std::cout << "q->dequeue() == " << q->dequeue() << '\n';
  try
  {
    std::cout << q->dequeue() << '\n';
  }
  catch (int e)
  {
    std::cout << "Tried to call q->dequeue(), but q->is_empty() == " << std::boolalpha << q->is_empty() << '\n';
  }
}
