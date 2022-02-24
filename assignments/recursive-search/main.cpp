#include <iostream>
#include "funcs.h"

int main()
{
  int** board = new int*[5];
  initialize_board(board);
  //print_board(board);
  solve(board, 4, 0, 1);
  print_board(board);
  free_memory(board);
}
