#include <iostream>
#include <vector>

//copied from sorts.cpp
void print_vector(std::vector<int> a)
{
  for (auto i : a)
    std::cout << i << ", ";

  std::cout << "\n";
}

//returns the number of times value appears
//in the unsorted vector v
int count(std::vector<int> v, int value)
{
  int total = 0;
  for (int i = 0; i < v.size(); i++)
    if (v[i] == value)
      total++;
  return total;
}

int main()
{
  std::cout << "Testing count\n" << '\n';
  std::vector<int> v1 = {2, 4, 1, 2, 0, 20, 2};
  std::cout << "v1 = ";
  print_vector(v1);
  std::cout << "count(v1, 2) = " << count(v1, 2) << '\n';
  std::cout << "count(v1, 0) = " << count(v1, 0) << '\n';
  std::cout << "count(v1, 100) = " << count(v1, 100) << '\n';
}
