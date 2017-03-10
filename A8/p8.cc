

/****************************************************************
   PROGRAM:   N QUEENS PUZZLE
   AUTHOR:    SHOAIB MOMIN
   LOGON ID:  Z1777526
   DUE DATE:  Thursday, October 29, 2015

   FUNCTION:  Display the solution of n queens problem if it exists

   INPUT:     A value for the dimension of the chessboard
              

   OUTPUT:   The positions where a queens can be placed in a n dimension array, if a solution exists.
                       
             
****************************************************************/
#include"p8.h"
bool flag=false;
//#include<iostream>
//#include <cstdio>
//#include <cstdlib>
//void initBoard(vector<vector<bool>> & board, unsigned n  );
//void initBoard(vector<vector<bool>> & board, int n  )
//void printBoard(const vector<vector<bool>> & board,const unsigned  n);


int main()
{
unsigned n;                // n stores the size of the chessboard for which n queens solution is to be computed
cout<<"Enter n value";
while(cin>>n)              // The solution is computed as long as the user enters n values
{

solveNQueens(n);         // This is function call to solve the problem. the size of the chessboard is given as an argument


}

return 0;
}


/****************************************************************

   FUNCTION:   void initBoard(vector<vector<bool>> & board, unsigned n  );

   ARGUMENTS:  A vector board and n, the size of the bosrd

   RETURNS:    Nothing

  ****************************************************************/
void initBoard(vector<vector<bool>> & board, unsigned n  )
{
unsigned i,j;
for( i=0;i<n;i++)
{
for( j=0;j<n;j++)                // initially, all the traps are assigned with balls- hence no trap is sprung
{
board[i][j]=false;
}
}
srand(time(NULL));   // srand is assigned to time(NULL) to get different values
}

/****************************************************************

   FUNCTION:   void printBoard(const vector<vector<bool>> & board,const unsigned n);
   ARGUMENTS:  A vector board and size of the board

   RETURNS:    Nothing

   NOTES:     Displays the solution on screen
****************************************************************/

void printBoard(const vector<vector<bool>> & board,const unsigned n)
{
	unsigned i,j;
	for(i=0;i<n;i++){
		cout<<endl;         // after every n characters, a new line is added 
		for(j=0;j<n;j++){	
			if(board[i][j]) cout<< " Q ";   // if a queen can be placed at a particular place, denote it using Q
			else 
			cout<<" _ ";          // or denote it using a _

		//cout<<board[i][j]<<" ";
		}
	}



}

/****************************************************************

   FUNCTION:   void solveNQueens ( const unsigned& n );

   ARGUMENTS:  The size n is sent as argument

   RETURNS:    Nothing

 ****************************************************************/

void solveNQueens ( const unsigned& n )
{
	vector <vector<bool>> board(n,vector <bool>(n));  // vector for the chess board is first created. it is n*n vector
	initBoard(board,n);           // initial assignments to the vector are made by calling this function
	//int random;
	//random=rand()%(n);
//if(n==2 || n==3) cout<<"Solution does not exist";
	  if (!solveNqueensUtil(board, 0))    // solveNqueensutil starts from the first col. if no solution exists, display the following
    {
       cout<<"Solution does not exist"<<endl;
       return;                     // return here is used to come out of the function
    }
   // if(solveNqueensUtil(board,0))
	printBoard(board,n);        // if  a solution exists, the entire board is displayed
    
}


/****************************************************************

   FUNCTION:   bool solveNqueensUtil(vector<vector<bool>> & board, const unsigned& col);

   ARGUMENTS:  board and column number

   RETURNS:    returns a boolean value

****************************************************************/


bool solveNqueensUtil(vector<vector<bool>> & board, const unsigned& col)
{
int row=rand()%board.size();
if (col >= board.size()) {               // if the col exceeds, size of the board, all columns have been checked, hence return true
        return true;}
else{                                                   
    for (unsigned i = row; i < board.size(); i++)          // Check from random row generated till the end of the board
    {
        if ( isSafe(board, i, col) )                          // if the place is safe to place the queen
        {
            board[i][col] = true;                       // place the queen on the board       
            if (solveNqueensUtil(board, col + 1) ){     // go to the next column   
                return true;}                                
            board[i][col] = false;                      // or remove the queen from the place
        }
    }


  for (int i = 0; i < row; i++)                   // this loop checks from start of the row till the random number generated
    {
        if ( isSafe(board, i, col) )              // if the position is safe, place the queen
        {
            board[i][col] = true;                                
            if (solveNqueensUtil(board, col + 1) ){   // go to the next column
                return true;}
            board[i][col] = false;             // or remove the queen
        }
    }
}
   
	return false;                        // return false if no such positions are found

}


/****************************************************************

   FUNCTION:   bool isSafe(const vector<vector<bool>>& board, const int & row, const int& col)

   ARGUMENTS:  vextor, row and column values

   RETURNS:    boolean result which specifies if a queen can be placed at that position

****************************************************************/
bool isSafe(const vector<vector<bool>>& board, const int & row, const int& col)
{
	//int i,j
	// unsigned i;
int i, j, size=board.size(); 
    for (i = 0; i < col; i++)         // this loop checks if a queen is present in any of the rows 
    {
        if (board[row][i])
            return false;              // if a queen is present, return false
    }
/*	for(i=0,j=0;i<n,j<n;i++,j++)
	{
		if(abs(row-i)==abs(col-j)
		return false;
	}*/
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)     // this loop is used to check the lower diagonal 
    {
        if (board[i][j])             // if a queen is present, return false
            return false;
    }
 
    for (i = row, j = col; j >= 0 && i < size; i++, j--)        // this loop checks the other diagonal
    {
        if (board[i][j])                      // if queen is present, return false
            return false;
    }
 
    return true;                     // or it is safe to place the queen in the position row and columnn

}
	
		
		
	
