/****************************************************************
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

// THIS FUNCTION WRITES THE ERROR MESSAGE TO CERR STREAM AND EXITS THE PROGRAM


#include"error.h"

void error(string msg)   // The message written in cerr is stored in msg
{
cerr<<msg<<endl;
exit(EXIT_FAILURE);
}
