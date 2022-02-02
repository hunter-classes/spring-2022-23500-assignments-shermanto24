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

int main()
{
  std::cout << "stepPerms(5) = " << stepPerms(5) << '\n';
  std::cout << "stepPerms(3) = " << stepPerms(3) << '\n';
  std::cout << "stepPerms(1) = " << stepPerms(1) << '\n';
  std::cout << "stepPerms(10) = " << stepPerms(10) << '\n';
  std::cout << "stepPerms(12) = " << stepPerms(12) << '\n';
}
