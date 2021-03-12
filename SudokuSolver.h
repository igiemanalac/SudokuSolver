#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> solveSudoku(vector<vector<int>> board);
bool solvePartialSudoku(int row, int col, vector<vector<int>> &board);
bool isValidAtPosition(int value, int row, int col, vector<vector<int>> &board);
bool tryDigitsAtPosition(int row, int col, vector<vector<int>> &board);