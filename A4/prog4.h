
/****************************************************************
   PROGRAM:   REMOVING COMMENTS IN A SOURCE FILE
   AUTHOR:    SHOAIB MOMIN
   LOGON ID:  Z1777526
   DUE DATE:  Thursday, September 24, 2015

   FUNCTION:  The program takes the file with comments, processes it and removes the comments
              

   INPUT:     Source file with comments
              

   OUTPUT:    The source file wihtout comments.
              
              
              
****************************************************************/


//This header file has all the prototypes of functions that re required for the program

//#include“/home/cs689/common/689.h”
#include"/home/cs689/common/689.h"  
#include"error.h"   // this file is used to include errro message in the program

#ifndef _remcom_h
#define _remcom_h 
void open_files(ifstream& is,ofstream& os); // this function is used to open the files
void process_data(ifstream& is, ofstream&os); // this function is used to process the files
void close_files(ifstream& is, ofstream& os);  // this function closes the files
#endif
