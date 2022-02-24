#include <iostream>
#include <iomanip>
#include <unistd.h>
#include "funcs.h"

const int SIDE_LENGTH = 5;

//initialize the board
void initialize_board(int** board)
{
  for (int row = 0; row < SIDE_LENGTH; row++)
  {
    board[row] = new int[SIDE_LENGTH];
    for (int col = 0; col < SIDE_LENGTH; col++)
      board[row][col] = 0;
  }
}

void print_board(int** board)
{
  for (int i = 0; i < SIDE_LENGTH; i++)
  {
    for (int j = 0; j < SIDE_LENGTH; j++)
      std::cout << std::setw(2) << board[i][j] << ":";
    std::cout << '\n';
  }
  std::cout << '\n';
}

void free_memory(int** board)
{
  for (int i = 0; i < SIDE_LENGTH; i++)
  {
    delete[] board[i];
    board[i] = nullptr;
  }

  delete[] board;
  board = nullptr;
}

void solve(int** board, int row, int col, int counter)
{
  //base case
  if (is_solved(board))
    return;
  else if (row < 0 || row >= SIDE_LENGTH || col < 0 || col >= SIDE_LENGTH)
    return;
  else if (board[row][col] != 0) //already placed horse
    return;

  board[row][col] = counter;
  //usleep(80000);
  //print_board(board);

  //just changed board, don't know if you want to continue
  if (!is_solved(board))
    solve(board, row-2, col-1, counter+1); //2 up, 1 left
  if (!is_solved(board))
    solve(board, row-2, col+1, counter+1); //2 up, 1 right
  if (!is_solved(board))
    solve(board, row+2, col-1, counter+1); //2 down, 1 left
  if (!is_solved(board))
    solve(board, row+2, col+1, counter+1); //2 down, 1 right
  if (!is_solved(board))
    solve(board, row-1, col-2, counter+1); //2 left, 1 up
  if (!is_solved(board))
    solve(board, row+1, col-2, counter+1); //2 left, 1 down
  if (!is_solved(board))
    solve(board, row-1, col+2, counter+1); //2 right, 1 up
  if (!is_solved(board))
    solve(board, row+1, col+2, counter+1); //2 right, 1 down

  //if we reached this point,
  //we tried all possible cases and want to go back
  if (!is_solved(board)) //don't wanna remove when solved
    board[row][col] = 0;
}

bool is_solved(int** board)
{
  for (int i = 0; i < SIDE_LENGTH; i++)
    for (int j = 0; j < SIDE_LENGTH; j++)
      if (board[i][j] == 0)
        return false; //if there is any 0 keep going

  return true;
}
