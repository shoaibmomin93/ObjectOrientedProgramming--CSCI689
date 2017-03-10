
/****************************************************************
   PROGRAM:   REMOVING COMMENTS IN A FILE
   AUTHOR:    SHOAIB MOMIN
   LOGON ID:  Z1777526
   DUE DATE:  Thursday, September 24, 2015

   FUNCTION:  The program removes the commented lines from the source file.
              

   INPUT:     A source file is the input for this program.
              

   OUTPUT:    A source file wihtout the comments if output of this program
              
              
              

   NOTES:    The statements in Strings , comments and character constants are 
             preserved           
****************************************************************/





#include"prog4.h"      // the header file includes all the prototypes and constants 



int main()
{
ifstream infile;          // ifstream variable is used to open and read the source file that needs to be modified
ofstream outfile;     // ofstream writes the modified source code to a new file
open_files(infile,outfile);  // The call to otpn_files open the source file with comments and another file to store the the output .
//cout<<"success";
cout<<"The files have opened successfully"<<endl;  // Once the files are opened succesfully, this message is displayed.
process_data(infile,outfile); // A call to this function process the file. This where the actual computation is made to remove the comments from the file.
cout<<"The files have been processed succesfully"<<endl;
close_files(infile, outfile); // this function closes the files after they have been read and modified.
cout<<"The files have been closed successfulyy"<<endl;
}

/****************************************************************

   FUNCTION:   This function opens two files . One is the input file and the other is output file.

   ARGUMENTS:  The file streams are passed as arguments. One is for reading the file and the other is for writing 

   RETURNS:    This function doesnt return anything

****************************************************************/


void open_files(ifstream & is, ofstream& os) 
{
is.open("/home/cs689/progs/p4/prog4d.cc");     // ifstream is used to open the source file. It is prog4d.cc
if(is.fail())   // if it fails , an error messsage is displayed
error("coudnt open file 1");
os.open("prog4out.cc");       // ofstream variable is used to open the file where output code is stored
if(os.fail())         // if it fails, an error message is displayed.
error("couldnt open file 2");
}

/****************************************************************

   FUNCTION:   void proces_data(ifstream &, ofstream&);

   ARGUMENTS:  Stream variables are passed as arguments.

   RETURNS:    This function doesnt return anythig

   NOTES:      Comment symbols in strings, character constants and comments are preserved 
****************************************************************/


void process_data(ifstream& is, ofstream& os)
{
int ch1, ch2;      // ch1 stores the first character and ch2 stores the next
 bool commentFlag,singleComment,stringFlag; // commentFlag is used to indicate multiple line comments, singleComment is used for single line comment, stringFlag is used for comment symbols within strings.
stringFlag=false;  // initially all the flags are assigned false
 commentFlag = false;
singleComment=false;
 while ((ch1 = is.get()) != EOF) {  // the file is read till the end

/*if(ch=='"'){
os.put(ch);
while((nch=is.get()) !='"')
os.put(nch);
}*/
//{
//os.put(ch);}
//if(ch=='"' && stringFlag==true) stringFlag=false;

//if(ch=='"' && stringFlag) stringFlag=false;
//if(stringFlag && singleComment) singleComment=false;

if(singleComment){                          // if the single line comment is true, make it false at the end of the line
	if(ch1=='\n') singleComment=false;
	if(commentFlag){ commentFlag=false;   // if a multiple line comment occurs within single line comment, false is as well as it has no significance
	singleComment=true;}    // if the end of line has not been reached, single comemnt is turned true.
} 
if (commentFlag ) {      // if multiple line comment is true, make if false when */ appears
//if(ch=='\n') commentFlag=false;
 if (ch1 == '*' ) { // the character * is looked for
 ch2 = is.get();    // if it appears, the next character is looked for %
 if (ch2 == '/') {
 commentFlag = false;  // if the end of multiple comment characters appear, it is turned false
 } else {             // if not, it is pushed on the stream
 is.unget();
 }
 }
 } 

else {             // if none of the comment flags are true, it looks for both comment characters

if(ch1=='"'){       
os.put(ch1);              // for all characters that appear within double quotes as strings, display them
while((ch2=is.get()) !='"')
os.put(ch2);
}

 if (ch1 == '/') {       // if the character is /, look for next character as * to assign true value to multiple comment flag
 ch2 = is.get();
 if (ch2 == '*') {

 commentFlag = true;


 }
if(ch2=='/') singleComment=true;  // if the first character is /, look for next character as / to assign true to single comment flag
 else {
 is.unget();         // or push on the stream
 }
 }

 if (((!commentFlag && !singleComment))&&!stringFlag) os.put(ch1);  // if none of the flag values are true, write them on the output file
 }
 }
}

/****************************************************************

   FUNCTION:   void close_files(ifstream&,ofstream&);

   ARGUMENTS:  File streams are sent as parameters.

   RETURNS:    This function doesnt return anythig. void

****************************************************************/



 void close_files(ifstream& is, ofstream& os)
{
is.close();              // input file is closed
os.close();               // output file is closed
}
