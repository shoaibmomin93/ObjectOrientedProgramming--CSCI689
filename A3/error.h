
/*************************************************************
   PROGRAM:   CAESAR CIPHER
   AUTHOR:    SHOAIB MOMIN
   LOGON ID:  Z1777526
   DUE DATE:  Wednesday, September 16, 2015

   FUNCTION:  THE PROGRAM TAKES TEXT FROM A DATA FILE AND ENCRYPTS IT USING
              A SPECIFIED KEY

   INPUT:     THE TEXT TO BE ENCRYPTED IS IN prog3.d2. SHIFT VALUES CAN BE
              GIVEN FROM KEYBOARD OR prog3.d1

   OUTPUT:    THE OUTPUT CAN BE DISPLAYED ON THE SCREEN OR AN OUTPUT FILE
              DEPENDING ON THE WAY IT IS EXECUTED



****************************************************************/

// THIS HEADER FILE IS USED TO PRINT THE ERROR MESSAGE ON THE SCREEN
#ifndef _error_h
#define _error_h
#include"/home/cs689/common/689.h"
void error(std::string msg);  // WRITES THE ERROR MESSAGE TO cerr STREAM AND EXITS
#endif
