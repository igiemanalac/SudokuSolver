#include "SudokuSolver.h"

vector<vector<int>> solveSudoku(vector<vector<int>> board) 
{
  solvePartialSudoku(0, 0, board);
  return board;
}

bool tryDigitsAtPosition(int row, int col, vector<vector<int>> &board)
{
  for(int digit = 1; digit <= 9; digit++)
  {
    if(isValidAtPosition(digit, row, col, board))
    {
      board[row][col] = digit;
      if(solvePartialSudoku(row, col + 1, board))
        return true;
    }
  }
  board[row][col] = 0;
  return false;
}

bool solvePartialSudoku(int row, int col, vector<vector<int>> &board)
{
  int currentRow = row;
  int currentCol = col;

  if(currentCol == board[row].size())
  {
    currentCol = 0;
    currentRow++;
    if(currentRow == board.size())
      return true;
  }

  if(board[currentRow][currentCol] == 0)
  {
    return tryDigitsAtPosition(currentRow, currentCol, board);
  }

  return solvePartialSudoku(currentRow, currentCol + 1, board);
}

/**
 * @brief Identifies if the input value can be stored in 
 * the position board[row][col]
 * 
 * @param value The value to be checked
 * @param row The row position in the board
 * @param col The column position in the board
 * @param board The sudoku board
 * @return true Valid sudoku board position for the value
 * @return false Invalid sudoku board position for the value
 */
bool isValidAtPosition(int value, int row, 
int col, vector<vector<int>> &board)
{
	bool rowIsValid = find(board[row].begin(), 
  board[row].end(), value) == board[row].end();
  bool colIsValid = true;
  for(auto arr : board)
  {
    if(arr[col] == value)
    {
      colIsValid = false;
      break;
    }
  }

  if(!rowIsValid || !colIsValid)
    return false;

  /*
    Check the position subgrid if the value already 
    exists in it
  */
  int subgridRowStart = row / 3 * 3;
  int subgridColStart = col / 3 * 3;
  for(int rowIdx = 0; rowIdx < 3; rowIdx++)
  {
    for(int colIdx = 0; colIdx < 3; colIdx++)
    {
      int rowToCheck = subgridRowStart + rowIdx;
      int colToCheck = subgridColStart + colIdx;
      int existingValue = board[rowToCheck][colToCheck];
      
      if(existingValue == value)
        return false;
    }
  }

  return true;
}