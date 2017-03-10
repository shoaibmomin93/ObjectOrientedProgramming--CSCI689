/**************************************************************


   PROGRAM : N QUEENS PUZZLE

   AUTHOR:    SHOAIB MOMIN

   LOGON ID:  Z1777526

   DUE DATE:  Thursday, October 29, 2015

   FUNCTION:  Display the solution of n queens problem if it exists

   INPUT:     A value for the dimension of the chessboard


   OUTPUT:   The positions where a queens can be placed in a n dimension array, if a solution exists.


****************************************************************/


#include"/home/cs689/common/689.h"  
        
void solveNQueens ( const unsigned& n );         // This function prototype takes n value and computes for result
bool solveNqueensUtil ( vector < vector < bool > >& board, const unsigned& col );   // This is a recursive function where every row value is checked for every column
bool isSafe ( const vector < vector < bool > >& board, const int& row, const int& col );  // this function is used to see if a queen can be placed at the position or not

void initBoard(vector<vector<bool>> & board, unsigned n  );   // this is used to 
//void initBoard(vector<vector<bool>> & board, int n  )
void printBoard(const vector<vector<bool>> & board,const unsigned  n);

