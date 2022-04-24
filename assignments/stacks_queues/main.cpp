#include <iostream>
#include "Stack.h"

int main()
{
  Stack *s = new Stack();
  std::cout << "Created Stack s" << '\n';
  std::cout << "s->is_empty() == " << s->is_empty() << '\n';

  s->push("hello");
  std::cout << "After s->push(\"hello\"), s->top() == " << s->top() << '\n';
  s->push("world");
  std::cout << "After s->push(\"world\"), s->top() == " << s->top() << '\n';

}
