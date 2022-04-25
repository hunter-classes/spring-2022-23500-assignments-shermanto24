#include <iostream>
#include "Stack.h"

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
}
