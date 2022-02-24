#include <iostream>
#include "funcs.h"

int main()
{
  int** board = new int*[5];
  initialize_board(board);
  //print_board(board);
  std::cout << "Solution with bottom left corner as start\n" << '\n';
  solve(board, 4, 0, 1);
  print_board(board);
  free_memory(board);
}
