#pragma once

void initialize_board(int** board);
void print_board(int** board);
void free_memory(int** board);
void solve(int** board, int row, int col, int counter);
bool is_solved(int** board);
