#include "SudokuSolver.h"

vector<vector<int>> solveSudoku(vector<vector<int>> board) 
{
  solvePartialSudoku(0, 0, board);
  return board;
}

/**
 * @brief The core function which solves the 
 * sudoku puzzle. 
 * 
 * @param row The row position in the board
 * @param col The column position in the board
 * @param board The sudoku board
 * @return true The sudoku puzzle has been solved
 * @return false No valid digit for current position, 
 * reset value and backtrack
 */
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

  // Fill the position with a valid digit
  if(board[currentRow][currentCol] == 0)
  {
    return tryDigitsAtPosition(currentRow, currentCol, board);
  }

  // Move on to the next position
  return solvePartialSudoku(currentRow, currentCol + 1, board);
}

/**
 * @brief Identifies the correct digit for the current
 * cell position in the board. Backtracks when there 
 * is no digit that can be placed in the current
 * position due to an incorrect digit stored in a
 * previous position.
 * 
 * @param row The row position in the board
 * @param col The column position in the board
 * @param board The sudoku board
 * @return true The sudoku puzzle has been solved
 * @return false No valid digit for current position, 
 * reset value and backtrack
 */
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

  // No valid digit for the current position, reset value
  board[row][col] = 0;
  return false;
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