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

// The header file includes all the libraries, function prototypes and constant declarations that will be used in the source file.
#ifndef _prog3_h
#define _prog3_h

#include"/home/cs689/common/689.h"
#include"error.h"  // The error message display  uses error.h
extern const string PATH;   // the path stores the path of the data file that needs to be encrypted
extern const int ALPHABET; // aplhabet has the number of letters in aplhabet 
//extern const int alphabet;
void process_infile(int shift); // takes the shift value and passes to encodecaesar
string encodeCaesarCipher(string str,int shift); // data file is opened and the string is encrypted
int new_position(char c, int shift); // the new position of the character is computed in this function
#endif
