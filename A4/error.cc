/****************************************************************
   PROGRAM:   REMOVING COMMENTS IN A SOURCE FILE
   AUTHOR:    SHOAIB MOMIN
   LOGON ID:  Z1777526
   DUE DATE: Thursday, September 24, 2015 

   FUNCTION:  The program takes the file with comments, processes it and removes
 the comments
              

   INPUT:     Source file with comments
              

   OUTPUT:   The source file wihtout comments
             



****************************************************************/

// THIS FUNCTION WRITES THE ERROR MESSAGE TO CERR STREAM AND EXITS THE PROGRAM


#include"error.h"

void error(string msg)   // The message written in cerr is stored in msg
{
cerr<<msg<<endl;
exit(EXIT_FAILURE);
}
