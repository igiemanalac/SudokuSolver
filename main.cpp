#include "SudokuSolver.h"
#include <iostream>
using namespace std;

void printSudoku(vector<vector<int>> board)
{
  for(auto row : board)
  {
    for(auto val : row)
      cout << val;
    cout << endl;
  }
}

int main()
{
  // vector<vector<int>> testInput = {
  //   {7, 8, 0, 4, 0, 0, 1, 2, 0}, {6, 0, 0, 0, 7, 5, 0, 0, 9},
  //   {0, 0, 0, 6, 0, 1, 0, 7, 8}, {0, 0, 7, 0, 4, 0, 2, 6, 0},
  //   {0, 0, 1, 0, 5, 0, 9, 3, 0}, {9, 0, 4, 0, 6, 0, 0, 0, 5},
  //   {0, 7, 0, 3, 0, 0, 0, 1, 2}, {1, 2, 0, 0, 0, 7, 4, 0, 0},
  //   {0, 4, 9, 2, 0, 6, 0, 0, 7},
  // };
      
  // vector<vector<int>> expected = {
  //   {7, 8, 5, 4, 3, 9, 1, 2, 6}, {6, 1, 2, 8, 7, 5, 3, 4, 9},
  //   {4, 9, 3, 6, 2, 1, 5, 7, 8}, {8, 5, 7, 9, 4, 3, 2, 6, 1},
  //   {2, 6, 1, 7, 5, 8, 9, 3, 4}, {9, 3, 4, 1, 6, 2, 7, 8, 5},
  //   {5, 7, 8, 3, 9, 4, 6, 1, 2}, {1, 2, 6, 5, 8, 7, 4, 9, 3},
  //   {3, 4, 9, 2, 1, 6, 8, 5, 7},
  // };
  
  vector<vector<int>> sudokuPuzzle = {
    {0, 0, 0, 2, 6, 0, 7, 0, 1}, {6, 8, 0, 0, 7, 0, 0, 9, 0},
    {1, 9, 0, 0, 0, 4, 5, 0, 0}, {8, 2, 0, 1, 0, 0, 0, 4, 0},
    {0, 0, 4, 6, 0, 2, 9, 0, 0}, {0, 5, 0, 0, 0, 3, 0, 2, 8},
    {0, 0, 9, 3, 0, 0, 0, 7, 4}, {0, 4, 0, 0, 5, 0, 0, 3, 6},
    {7, 0, 3, 0, 1, 8, 0, 0, 0},
  };

  vector<vector<int>> result = solveSudoku(sudokuPuzzle);
  printSudoku(result);

  // if(expected == result)
  //   cout << "Solution matched the expected output." << endl;

  return 0;
}