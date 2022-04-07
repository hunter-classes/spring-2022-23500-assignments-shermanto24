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

// from classcode
std::vector<int> qsort(std::vector<int> &list){

  int i,j;

  // base case
  if (list.size() <= 1){
    return list;
  }

  // select a pivot value.
  // for now, just pick list[0]
  int pivot = list[0];

  // make 2 new vectors
  std::vector<int> lower,higher;

  // copy all the values < pivot value to lower
  // copy all the values >= pivot value to higher;
  for (i=1; i < list.size(); i++){
    if (list[i] < pivot){
      lower.push_back(list[i]);
    } else {
      higher.push_back(list[i]);
    }
  }

  lower = qsort(lower);
  higher = qsort(higher);

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
void in_place_qsort(std::vector<int> &list, int l, int h)
{
  // base case
  // there is a chance that l > h
  if (l >= h)
    return;

  int pivot = list[l]; // will change later
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
  in_place_qsort(list, l, j);
  in_place_qsort(list, i, h);
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

  // testing in-place qsort
  std::vector<int> a = {6, 5, 7, 4, 1, 6};
  in_place_qsort(a, 0, a.size());
  print_vector(a);
}
