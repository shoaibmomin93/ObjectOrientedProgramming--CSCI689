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


#include"prog3.h"              // The header file consists of function prototypes, libraries and constant declaration

extern const string PATH="/home/cs689/progs/p3/prog3.d2";   // the PATH variable stores the path of the string whose data is to be encrypted.
extern const int ALPHABET=26;
//extern const int alphabet=26;
int main()                               //The main program takes in shift values and calls the processinfile method where encrypting takes place.
{
string str;
//ifstream infile;
//infile.open("/home/cs689/progs/p3/prog3.d1");
//if(infile.fail()) cerr<<"file couldnt open"<<endl;
//while(!infile.fail()){ 
//getline(infile,str);
//int shift=atoi(str.c_str());
int shift;                 // shift variable stores the shift value entered from keyboard
while ( cin >> shift ) {   // The loop is executed as long as values are entered from keyboard. If ctrl+D is is given, cin returns false and the loop terminates.
process_infile(shift);      //This function opens the data file, calls the cipher function .
cout<<"\t"<<shift;     // the shift value is displayed.
}
//infile.close();
return 0;
}

/****************************************************************

   FUNCTION:   void process_infile(int);

   ARGUMENTS:  integer shift value is passed which is obtained from keyboard or prog3.d1 file

   RETURNS:    It does not return anything- void

   NOTES:      This function takes the text from data file, calls the cipher function and displays the encrypted text.
****************************************************************/




void process_infile(int shift)     
{
ifstream infile1;   //stream variable is used for reading the file
string s1,s2;       //string s1 is used for getline ; s2 stores the encrypted text that is returned.
infile1.open(PATH); // stream variable is used to open the file. PATH has the the path of the file that needs to be opened.
if(infile1.fail()) cerr<<"file 2 coundt open";  // If the opening of the file fails, an error message is displayed. cerr has been implemented in error.cc that has been specified in error.h and included in prog3.h 
cout<<endl<<shift<<endl; //shift value is displayed.
while(!infile1.fail())  // As long as the file is not read completely, the loop is executed.
{
getline(infile1,s1); // getline gets the string value and stores it in s1
s2=encodeCaesarCipher(s1,shift); // the string along with shift value is used in the call to the cipher function where encryption takes place. s2 stores the encrypted text that is returned.
cout<<" "<<s2;   
}

infile1.close();  // the file that was opened is now closed as no more operations are being performed on it.
}



/****************************************************************

   FUNCTION:   string encodeCaesarCipher(string , int);

   ARGUMENTS:  str string contains the text that is to be encrypted
	       shift contains the value by which the characters are to be moved

   RETURNS:    The encrypted string is returned back to the calling function

   NOTES:      This function performs computations on shift and string to get the required output
****************************************************************/

string encodeCaesarCipher(string str, int shift)
{
if((shift>ALPHABET) || (shift<-ALPHABET))   //If the shift value is greater than 26 or less than -26, modulo26 operation is performed as the series is repeated after every 26 letters.
shift%=ALPHABET;
//shift+=ALPHABET;
unsigned i=0;               
while(i<str.length())   //Each character of the string is taken and the new position of its letter is obtained.                  
{
int pos=new_position(str[i],shift);  // the new position obtained after using caesar cipher is stored in pos
str[i]=(char)pos;   // the ascii value is converted back to character and stored in the string.
i++;              // The loop runs till the end of the string
}
return str;           // the encrypted string is returned back to the calling function
}


/****************************************************************

   FUNCTION:   int new_position(char , int )

   ARGUMENTS:  c character receives the letter to be encoded
	      shift stores the value with which the positions are to be shifted 

   RETURNS:    returns the asci value of the new position

   NOTES:      Various conditions are checked and the new position of the character is returned.
****************************************************************/





int new_position(char c, int shift)
{
int num;
if(c==' ') return 32;            // stores the new position of the character
if(c>='a' && c<='z')    // for values between lower case a and z, perform
{
if((c+shift)>'z')       // if the new value is greater than z, then subtract 26 from it .
num=c-ALPHABET+shift;
//else 
//num=c+shift;
else if(c+shift<'a')  // in the contrary if the value is less than a, add 26 to it
num=c+shift+ALPHABET;
else 
num=c+shift;   // or use the new value as it is.
}
if(c>='A' && c<='Z')   // the same logic is used for upper case letters
{
if((c+shift)>'Z')
num=c-ALPHABET+shift;
else if(c+shift<'A')
num=c+shift+ALPHABET;
else
num=c+shift;
}
return num;     // the new position is returned to the caesar function
}
