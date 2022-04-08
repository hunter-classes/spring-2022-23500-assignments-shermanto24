#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>

void print_vector(std::vector<int> a)
{
  for (auto i : a)
    std::cout << i << ", ";

  std::cout << "\n";
}

int find_min_index(std::vector<int> a, int start_index, int stop_index)
{
  int min_index = start_index;
  int i;
  for (i = start_index ; i < stop_index; i++)
    if (a[i] < a[min_index])
      min_index = i;

  return min_index;
}

std::vector<int> ssort(std::vector<int> a)
{
  int i, min_index, j, tmp;
  int len = a.size();
  // loop through the vector from 0 to end
  for (i = 0; i < len; i++)
  {
    // find the smallest value from i to the end
    min_index = find_min_index(a, i, len);

    // swap it into position i
    tmp = a[i];
    a[i] = a[min_index];
    a[min_index] = tmp;
  }
  return a;
}

/*
  left and right are already sorted

  merged should be a new vector with all the
  elements in left and right, and result
  should be sorted
*/
std::vector<int> merge(std::vector<int> left, std::vector<int> right)
{
  std::vector<int> merged;

  // your code here
  int l = 0;
  int r = 0;

  while (l < left.size() && r < right.size())
  {
    if (left[l] < right[r])
    {
      merged.push_back(left[l]);
      l++;
    }
    else
    {
      merged.push_back(right[r]);
      r++;
    }
  }

  // add any extra elements in left
  while (l < left.size())
  {
    merged.push_back(left[l]);
    l++;
  }

  // add any extra elements in right
  while (r < right.size())
  {
    merged.push_back(right[r]);
    r++;
  }

  return merged;
}

//---------------- my code ----------------
std::vector<int> msort(std::vector<int> v)
{
  std::vector<int> result;

  if (v.size() < 2)
    return v;
  else
  {
    std::vector<int> left;
    std::vector<int> right;

    for (int i = 0; i < v.size(); i++)
    {
      if (i < v.size()/2)
        left.push_back(v[i]);
      else
        right.push_back(v[i]);
    }

    left = msort(left);
    right = msort(right);

    result = merge(left, right);
    return result;
  }
}

// from classcode (+ added pivot option)
std::vector<int> bad_qsort(std::vector<int> &list, bool good_pivot){

  int i,j;
  int size = list.size();

  // base case
  if (size <= 1){
    return list;
  }

  int pivot;
  int piv_index = 0;
  if (!good_pivot)
    pivot = list[0];
  else
  {
    int first = list[0];
    int last = list[size - 1];
    int mid = list[size / 2];

    if ((first >= mid && mid >= last) || (last >= mid && mid >= first))
    {
      pivot = mid;
      piv_index = size / 2;
    }
    else if ((mid >= first && first >= last) || (last >= first && first >= mid))
      pivot = first;
    else
    {
      pivot = last;
      piv_index = size - 1;
    }
  }

  // make 2 new vectors
  std::vector<int> lower,higher;

  // copy all the values < pivot value to lower
  // copy all the values >= pivot value to higher;
  if (good_pivot)
    i = 0; // we don't want to skip the first element
  else
    i = 1;

  for (i=i; i < size; i++){
    if (good_pivot && i == piv_index)
    {
      i++;
      if (i >= size)
        break;
    }
    if (list[i] < pivot){
      lower.push_back(list[i]);
    } else {
      higher.push_back(list[i]);
    }
  }

  lower = bad_qsort(lower, good_pivot);
  higher = bad_qsort(higher, good_pivot);

  // copy everything back into list

  for (i=0 ; i < lower.size(); i++){
    list[i]=lower[i];
  }

  list[i] = pivot;
  i++;

  for (j=0;j<higher.size();j++){
    list[i] = higher[j];
    i++;
  }

  // return the sorted list
  return list;
}

// in-place quick sort
// Ivan Rao helped me with the code for this function.
void in_place_qsort(std::vector<int> &list, int l, int h, bool good_pivot)
{
  // base case
  // there is a chance that l > h
  if (l >= h)
    return;

  //print_vector(list);

  int pivot;
  if (!good_pivot)
    pivot = list[l];
  else
  {
    int first = list[l];
    int last = list[h];
    int mid = list[(h - l) / 2 + l];

    if ((first >= mid && mid >= last) || (last >= mid && mid >= first))
      pivot = mid;
    else if ((mid >= first && first >= last) || (last >= first && first >= mid))
      pivot = first;
    else
      pivot = last;
  }

  // we want to keep the parameters as the initial bounds
  int i = l; // like walkers
  int j = h;

  // while j is still on the high side
  // and i is still on the low side
  // or they're equal -> we want to change them
  while (j >= i)
  {
    // changing i and j so that
    // list[i] and list[j] are ready to swap
    while (list[i] < pivot)
      i++;

    while (list[j] > pivot)
      j--;

    // we only want to swap when the values of i and j
    // still belong to the low and high sides respectively
    // this also handles whether or not i and j go out of bounds
    // if i = j, we still want to enter this if statement
    // so that their values get changed
    // and we exit the big while loop
    if (j >= i)
    {
      int temp = list[i];
      list[i] = list[j];
      list[j] = temp;
      i++;
      j--;
    }
  }

  // we don't touch the pivot anymore
  // bc it's in its correct location
  in_place_qsort(list, l, j, good_pivot);
  in_place_qsort(list, i, h, good_pivot);
}

void test(char type, bool print, std::vector<int> list, bool good_pivot)
{
  std::vector<int> result(list.size());

  struct timeval tp;
  gettimeofday(&tp,NULL);
  long start_time = tp.tv_sec *1000 + tp.tv_usec / 1000;

  if (type == 'm') //msort
    list = msort(list);
  else if (type == 'b') //bad_qsort
    list = bad_qsort(list, good_pivot);
  else if (type == 'i') //in_place_qsort
    in_place_qsort(list, 0, list.size() - 1, good_pivot);

  if (print)
    print_vector(list);

  gettimeofday(&tp,NULL);
  long current_time = tp.tv_sec *1000 + tp.tv_usec / 1000;

  long elapsed = current_time - start_time;
  std::cout << "type = " << type << ", time: " << elapsed << '\n';
}

int main()
{
  /*
  std::cout << "\nTesting msort\n" << '\n';

  //testing with an even size
  std::cout << "With an even size:" << '\n';
  std::vector<int> v1 = {24, 5, 2, 31};
  std::cout << "Before msort, v1 = ";
  print_vector(v1);
  v1 = msort(v1);
  std::cout << "After msort, v1 = ";
  print_vector(v1);

  //testing with an odd size
  std::cout << "\nWith an odd size:" << '\n';
  std::vector<int> v2 = {10, 5, 2, 4, 3};
  std::cout << "Before msort, v2 = ";
  print_vector(v2);
  v2 = msort(v2);
  std::cout << "After msort, v2 = ";
  print_vector(v2);

  //testing with a size less than 2
  std::cout << "\nWith a size less than 2:" << '\n';
  std::vector<int> v3 = {1};
  std::cout << "Before msort, v3 = ";
  print_vector(v3);
  v3 = msort(v3);
  std::cout << "After msort, v3 = ";
  print_vector(v3);
  */

  int max_val = 100;
  int size = 10;
  int i;

  // testing on randomized data
  std::cout << "----- TESTING ON RANDOMIZED DATA -----" << '\n';
  srand(time(nullptr));

  // tiny data set
  std::cout << "\n-- Tiny data set (size = 10) --\n" << '\n';

  std::vector<int> a(size);
  for (i = 0; i < size; i++)
    a[i] = rand() % max_val;

  std::cout << "a = ";
  print_vector(a);

  std::cout << "\nmsort(a): a = ";
  test('m', 1, a, 0);

  std::cout << "\nWith bad pivot:" << '\n';
  std::cout << "bad_qsort(a): a = ";
  test('b', 1, a, 0);
  std::cout << "in_place_qsort: a = ";
  test('i', 1, a, 0);

  std::cout << "\nWith good pivot:" << '\n';
  std::cout << "bad_qsort(a): a = ";
  test('b', 1, a, 1);
  std::cout << "in_place_qsort: a = ";
  test('i', 1, a, 1);

  // small data
  std::cout << "\n-- Small data set (size = 10,000) --\n" << '\n';

  size = 10000;
  std::vector<int> b(size);
  for (i = 0; i < size; i++)
    b[i] = rand() % max_val;

  test('m', 0, b, 0);
  std::cout << "\nWith bad pivot:" << '\n';
  test('b', 0, b, 0);
  test('i', 0, b, 0);
  std::cout << "\nWith good pivot:" << '\n';
  test('b', 0, b, 1);
  test('i', 0, b, 1);

  // big data
  std::cout << "\n-- Big data set (size = 100,000) --\n" << '\n';

  size = 100000;
  std::vector<int> c(size);
  for (i = 0; i < size; i++)
    c[i] = rand() % max_val;

  //test('m', 0, c, 0);
  // std::cout << "\nWith bad pivot:" << '\n';
  // test('b', 0, c, 0);
  // test('i', 0, c, 0);
  std::cout << "\nWith good pivot:" << '\n';
  //test('b', 0, c, 1);
  test('i', 0, c, 1);

  // bigger data
  std::cout << "\n-- Bigger data set (size = 1,000,000) --\n" << '\n';

  size = 1000000;
  std::vector<int> d(size);
  for (i = 0; i < size; i++)
    d[i] = rand() % max_val;

  //test('m', 0, d, 0);
  // std::cout << "\nWith bad pivot:" << '\n';
  // test('b', 0, d, 0);
  // test('i', 0, d, 0);
  std::cout << "With good pivot:" << '\n';
  //test('b', 0, d, 1);
  test('i', 0, d, 1);

  // testing on sorted data
  std::cout << "\n----- TESTING ON SORTED DATA -----" << '\n';

  // small data
  std::cout << "\n-- Small data set (size = 10,000) --\n" << '\n';

  size = 10000;
  std::vector<int> e(size);
  for (int i = 0; i < size; i++)
    e[i] = i;

  test('m', 0, e, 0);
  // std::cout << "\nWith bad pivot:" << '\n';
  // test('b', 0, e, 0);
  // test('i', 0, e, 0);
  std::cout << "\nWith good pivot:" << '\n';
  test('b', 0, e, 1);
  test('i', 0, e, 1);

  // big data
  std::cout << "\n-- Big data set (size = 100,000) --\n" << '\n';

  size = 100000;
  std::vector<int> f(size);
  for (i = 0; i < size; i++)
    f[i] = i;

  //test('m', 0, f, 0);
  // std::cout << "\nWith bad pivot:" << '\n';
  // test('b', 0, c, 0);
  // test('i', 0, c, 0);
  std::cout << "\nWith good pivot:" << '\n';
  test('b', 0, f, 1);
  test('i', 0, f, 1);

  // bigger data
  std::cout << "\n-- Bigger data set (size = 1,000,000) --\n" << '\n';

  size = 1000000;
  std::vector<int> g(size);
  for (i = 0; i < size; i++)
    g[i] = i;

  //test('m', 0, g, 0);
  // std::cout << "\nWith bad pivot:" << '\n';
  // test('b', 0, d, 0);
  // test('i', 0, d, 0);
  std::cout << "With good pivot:" << '\n';
  //test('b', 0, g, 1);
  test('i', 0, g, 1);
}
