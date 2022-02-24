#include <iostream>
#include <iomanip>
#include "funcs.h"

//add buffer somehow?
const int SIDE_LENGTH = 5;
int** board = new int*[SIDE_LENGTH];

//create a 2d array of ints to represent the board
void initialize_board(int start)
{
  for (int i = 0; i < SIDE_LENGTH; i++)
  {
    board[i] = new int[SIDE_LENGTH];
    for (int j = 0; j < SIDE_LENGTH; j++)
      board[i][j] = 0;
      //add code for start
  }
}

void print_board()
{
  for (int i = 0; i < SIDE_LENGTH; i++)
  {
    for (int j = 0; j < SIDE_LENGTH; j++)
      std::cout << std::setw(2) << board[i][j] << ":";
    std::cout << '\n';
  }
}

void free_memory()
{
  for (int i = 0; i < SIDE_LENGTH; i++)
  {
    delete[] board[i];
    board[i] = nullptr;
  }

  delete[] board;
  board = nullptr;
}

void solve()
{
  //how can we represent start?
  //index: row*SIDE_LENGTH + col


}
