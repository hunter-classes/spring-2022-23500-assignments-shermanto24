#include <iostream>

//returns the number of possibilities
int stepPerms(int n) //n = the number of steps
{
  if (n == 0)
    return 1;
  else if (n < 0)
    return 0;
  else
    return stepPerms(n - 1) + stepPerms(n - 2) + stepPerms(n - 3);
}

int steptable[10000];

int stepPerms_dyn(int steps)
{
  if (steps == 0)
    return 1;
  else if (steptable[steps] != 0)
    return steptable[steps];
  else
  {
    int w = 0; //w = # of ways we can do steps-1, steps-2, steps-3 
    for (int i = 3; i >= 1; i--)
    {
      int r = steps - i; //r = steps remaining
      if (r >= 0)
      {
        int temp = w + stepPerms_dyn(r);
        w = temp;
        steptable[steps] = temp;
      }
    }
    return w;
  }
}

int main()
{
  for (int i = 0; i <= 10; i++)
    std::cout << i << ": " << stepPerms(i) << '\n';

  std::cout << '\n';

  for (int i = 0; i <= 10; i++)
    std::cout << i << ": " << stepPerms_dyn(i) << '\n';
}
