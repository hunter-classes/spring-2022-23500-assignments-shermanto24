#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>
#include <ctime>

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

//returns the largest value in vector v
int largest(std::vector<int> v)
{
  if (v.empty())
    return 0;

  int max = v[0];
  for (int i = 1; i < v.size(); i++)
    if (v[i] > max)
      max = v[i];
  return max;
}

//returns the mode of vector v, which is
//the item that appears most frequently
//if there are multiple modes, this function
//will return the mode whose first occurrence
//in the list is earlier
int mode1(std::vector<int> v)
{
  if (v.empty())
    return 0;

  int mode = v[0];
  int max_freq = 0;
  for (int i = 0; i < v.size(); i++)
  {
    int curr_freq = count(v, v[i]);
    if (curr_freq > max_freq)
    {
      mode = v[i];
      max_freq = curr_freq;
    }
  }
  return mode;
}

//if there are multiple modes, this function
//will return the mode that is smaller in value
int mode2(std::vector<int> v)
{
  int size = largest(v);
  std::vector<int> freqs(size);
  for (int i = 0; i < v.size(); i++)
    freqs[v[i]]++;

  int mode = 0;
  for (int i = 0; i < size; i++)
    if (freqs[i] > freqs[mode])
      mode = i;

  return mode;
}

int main()
{
  //count tests
  std::cout << "Testing count\n" << '\n';
  std::vector<int> v1 = {2, 4, 1, 2, 0, 20, 2};
  std::cout << "v1 = ";
  print_vector(v1);
  std::cout << "count(v1, 2) = " << count(v1, 2) << '\n';
  std::cout << "count(v1, 0) = " << count(v1, 0) << '\n';
  std::cout << "count(v1, 100) = " << count(v1, 100) << '\n';

  //largest tests
  std::cout << "\nTesting largest\n" << '\n';
  std::cout << "largest(v1) = " << largest(v1) << '\n';
  std::vector<int> v2;
  std::cout << "v2 is an empty vector" << '\n';
  std::cout << "largest(v2) = " << largest(v2) << '\n';
  v2.push_back(1);
  std::cout << "After adding the element 1 to v2, v2 = {1}" << '\n';
  std::cout << "largest(v2) = " << largest(v2) << '\n';

  //mode1 tests
  std::cout << "\nTesting mode1\n" << '\n';

  std::cout << "On a vector with one mode:" << '\n';
  std::cout << "mode(v1) = " << mode1(v1) << '\n';

  std::cout << "\nOn a vector with more than one mode:" << '\n';
  std::vector<int> v3 = {1, 2, 1, 2, 1, 2, 0};
  std::cout << "v3 = ";
  print_vector(v3);
  std::cout << "mode(v3) = " << mode1(v3) << '\n';

  std::cout << "\nOn a vector with no mode" << '\n';
  std::vector<int> v4 = {5, 6, 7, 2, 1, 3};
  std::cout << "v4 = ";
  print_vector(v4);
  std::cout << "mode(v4) = " << mode1(v4) << '\n';

  std::cout << "\nOn an empty vector" << '\n';
  v2.clear();
  std::cout << "After clearing v2, v2 is an empty vector" << '\n';
  std::cout << "mode(v2) = " << mode1(v2) << '\n';

  //mode2 tests
  std::cout << "\nTesting mode2\n" << '\n';

  srand(time(nullptr));
  int size = 100000;
  std::vector<int> v5(size);
  int max = 100;
  for (int i = 0; i < size; i++)
    v5[i] = rand() % (max + 1);
  std::cout << "size of v5 = 100000" << '\n';
  std::cout << "mode2(v5) = " << mode2(v5) << '\n';

  std::vector<int> v6 = {1, 1, 1, 3, 3, 5, 3, 4};
  std::cout << "\nv6 = ";
  print_vector(v6);
  std::cout << "mode1(v6) = " << mode1(v6) << '\n';
  std::cout << "mode2(v6) = " << mode2(v6) << '\n';
}
