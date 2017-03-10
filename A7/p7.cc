/****************************************************************
   PROGRAM:   A SIMPLE CALCULATOR
   AUTHOR:    SHOAIB MOMIN
   LOGON ID:  Z1777526
   DUE DATE:  Wednesday, October 21, 2015

   FUNCTION:  Performs arithmetic operations on real numbers
              

   INPUT:     An expression to be evaluated in postfix notation             

   OUTPUT:    Computed result after postfix evaluation
              
              
****************************************************************/



#include"p7.h"
/*
#include"/home/cs689/common/689.h"
void process_token ( const string& token, stack < double >& S );
bool unarySign ( const char& c, const string& token, const unsigned& i );
bool floatPoint ( const char& c, const string& token, const unsigned& i );
double getNumber ( const char& c, const string& token, unsigned& i, const bool& floatPointFlag );
bool isValidOperator ( const char& c );
double operation ( const char& c, const double& x, const double& y );
double popStack ( stack < double >& S );
void printResult ( const stack < double >& S );
void emptyStack ( stack < double >& S );

*/
int main()
{
	stack <double> S;                   //empty  stack is declared
	string token;                     // input is taken token by token
	while ( cin >> token ) {
		process_token(token,S);     // call the process_token to process it
	}
}
/****************************************************************

   FUNCTION:  void process_token(const string& token, stack<double> &S);  

   ARGUMENTS:  string token and stack S

   RETURNS:    nothing

  ****************************************************************/


void process_token( const string& token, stack<double> &S)  
{
bool floatPointFlag=true;                              // it checks if its a floating point or not
for(unsigned i=0;i<token.length();i++)              // token is traversed and individual characters are checked
{
char c=token[i];                                      //the first character is stored in c
//cout<<"Inside for with c value "<<c<<endl;
bool b1 = unarySign(c,token,i);                     // function calls are made to check if it has a unary sign or a decimal point
//cout<<"b1 is what "<<b1<<endl;
//if(b1){i++; c= c-48; }
bool b2 = floatPoint(c,token,i);
//cout << "b1 = " << b1 << endl;
//cout << "b2 = " << b2 << endl;
/*if(c=='!')                                                 // Look for exclamation points
{ 
cerr<<"error: invalid '!'"<<;
return;
}*/
if(isdigit(c)||b1||b2 && !isValidOperator(c) && c!='=' && c!='!')            // for digit value with unary or decimal points, do the following steps
{
bool flag1=false, flag2=false;                              // first flag is used to look for unary - and second flag for unary +
if(b1 && c=='-')
{
 i++;
c=token[i];                                                     // this is used to convert the number into negative value
 flag1= true;
b1=false;
}
if(b1 && c=='+')
{
i++;
c=token[i];
flag2=true;                                                       // this is used to convert it to positive value
b1=false;
}

/*
if(b2)
{
if(!isdigit(token[i-1]))
{
int n=token.length();
string s1=token.substr(0,i-1);
string s2=token.substr(i,n-1);
token=s1+'0'+s2;
}
}
*/


	

//cout<<"Inside if"<<endl;
	string s;
	while(isdigit(c) || b2 && !isValidOperator(c)) {
        	s+=c;
		i++;                                                     // this loop is used to build the string of number
        	c = token [ i ];
              /* if(!isdigit(c) && !isValidOperator(c)){
		 b2=false;
		s+=c;
		i++;
		c=token[i];
		}*/
             if(c=='.' && !isValidOperator(c)) {                           // the condition for floating points is considered to add them to the string
		b2=false;
		s+=c;
		i++;
		c=token[i];
		}
		
	}
	i--; c = token [ i ];
//cout<<"string is "<<s<<endl;

	double num=getNumber(c,s,i,floatPointFlag);                             // get the number in double form from string
	//double num = stringToDouble ( s );
	if(flag1) num=num*(-1);                                                 // for unary - value convert it to a negative number
	else num=num*1;
	//cout<<"num generated is "<<num<<endl;
	S.push(num);                                                             // push the umber onto the stack
}
else if(isValidOperator(c))                                              // look if the character is a valid operator. If yes, get the values and perform the computation
{
//cout << "A1: c = " << c << endl;
	double n1=popStack(S);
	double n2= popStack(S);
        if(n1!=0.00 && n2!=0.00)
{ 
	double res=operation(c, n1,n2);
	S.push(res);
//cout << "n1 = " << n1 << endl;
//cout << "n2 = " << n2 << endl;
//cout << "res = " << res << endl;
}
}
else if(c=='=')                                                   // for =, print the result from the stack
{
	printResult(S);
}
else if(c=='c')
{                                                // if c is encountered, empty the stack
	emptyStack(S);
}
else 
{
	cerr<<"Error message in process_token. Invalid character "<<c<<endl;              // if none of these is encountered, display error mssg
}
}
}

/*
void process_token(const string& token, stack<double> &S)
{
 	string s;
	for ( unsigned i = 0; i < token.length ( ); i++ ) {
		char c = token [ i ];
cout << "C3: c = " << c << " i = " << i << endl;
		if ( isdigit ( c ) ) {
			while ( isdigit ( c ) ) {
				s += c; i++;
				c = token [ i ];
			} 
cout << "C4: s = " << s << endl;
			double d = stringToDouble ( s );
cout << "C5: d = " << d << endl;
			S.push ( d );
		}
		else if ( c == '+' || c == '-' || c == '*' || c == '/' ) {
			double x = S.top ( ); S.pop ( );
			double y = S.top ( ); S.pop ( );
			double z;
			switch ( c ) {
				case '+': z = x + y; break;
				case '-': z = y - x; break;
				case '*': z = x * y; break;
				case '/': z = y / x; break;
			}
			S.push ( z );
		}
		else if ( c == '=' ) {
			double d = S.top ( ); S.pop ( );
			cout << d << endl;
		}
		else { }
	}
}
*/
/****************************************************************

   FUNCTION: bool unarySign ( const char& c, const string& token, const unsigned& i );

   ARGUMENTS: currect character c, string token and position i

   RETURNS:   boolean value

  ****************************************************************/

bool unarySign ( const char& c, const string& token, const unsigned& i )
{
unsigned pos=token.length()-1;                                        // this is used to check if the number is a unary number or not
if(c=='-' || c=='+')
{
if(i!=pos && (isdigit(token[i+1]) || token[i+1]=='.'))                   // if the sign apprears before a digit or after decimal point, it is valid
return true;
else return false;
}
else return false;
}
/****************************************************************

   FUNCTION:  bool floatPoint ( const char& c, const string& token, const unsigned& i );

   ARGUMENTS: currect character c, string token and position i

   RETURNS:   boolean value

  ****************************************************************/



 bool floatPoint ( const char& c, const string& token, const unsigned& i )
{
unsigned pos=token.length()-1;                                         // it is used to check if the loop has decimal values.
bool flag=false;
for(unsigned i=0;i<token.length();i++)
{
if(token[i]=='.')
{
if(i!=pos && isdigit(token[i+1]))                                  // decimal should be succeeded by a digit
flag= true;
}

}
return flag;
}
/****************************************************************

   FUNCTION: double getNumber ( const char& c, const string& token, unsigned& i, const bool& floatPointFlag)
;
   ARGUMENTS: currect character c, string token,  position i and floatPointFlag

   RETURNS:  double number

  ****************************************************************/


double getNumber ( const char& c, const string& token, unsigned& i, const bool& floatPointFlag)
{


int count=0;
//cout<<"In getNumber token is "<<token<<endl;              // the number of decimal points are checked.
for(unsigned j=0;j<token.length();j++)
{
if(token[j]=='.') count++;                                  // if there are more, displa y error
}
if(count>1) {
cerr<<" ERROR- Invalid token "<<token<<endl;
exit(1);
}

/*else if(count==1){
int pos=token.find('.');
token.substr(0,pos+2);
}*/
//cout<<"count is "<<count<<endl;
double num=stringToDouble(token);                                 // or convert it to double number and return it
return num;
}

/****************************************************************

   FUNCTION:bool isValidOperator ( const char& c );

   ARGUMENTS: currect character c

   RETURNS:  boolean value

  ****************************************************************/


bool isValidOperator ( const char& c )                   // check if it s a valid operator
{
if(c=='+'||c=='-'||c=='*'||c=='/')
return true;
else return false;
}

/****************************************************************

   FUNCTION: double operation ( const char& c, const double& x, const double& y );
   ARGUMENTS: currect character c, double x, y

   RETURNS:  result of operation, a double value

  ****************************************************************/



double operation ( const char& c, const double& x, const double& y )
{
switch(c)
{
case '+': return x+y; break;
case '-': return y-x; break;                              // perform the operations as per the required operation
case '*': return x*y; break;
case '/': return y/x; break;
default:
//cerr<"Invalid operation in operation";
return 0;
}
}

/****************************************************************

   FUNCTION:double popStack ( stack < double >& S );
   ARGUMENTS: Stack S

   RETURNS: top element of the stack

  ****************************************************************/


double popStack ( stack < double >& S )
{
if( S.empty()) {
cerr<<"ERROR: Stack is empty"<<endl;
return 0;
}                                                            // if the stack is empty, display error
else
{
 double n= S.top();                                      // or display the top element of the stack
S.pop();
return n;
}
}

/****************************************************************

   FUNCTION:void printResult ( const stack < double >& S );
 
   ARGUMENTS: Stack S

   RETURNS: top element of the stack that has the result of computation

  ****************************************************************/

void printResult ( const stack < double >& S )
{
double res;
if(S.empty()) cerr<<"Stack is empty ";                              // this displays the result that is stored in stack
else
{
res= S.top();
//S.pop();
cout<<fixed<<setprecision(2)<<showpoint<<"Result is "<<res<<endl;
//S.pop();
}
}


/****************************************************************

   FUNCTION:void emptyStack ( stack < double >& S );

   ARGUMENTS: Stack S

   RETURNS: top element is popped until the stack is empty

  ****************************************************************/

void emptyStack ( stack < double >& S )
{
while(!S.empty())                                        // this function empties the stack
{
double num=popStack(S);
}
}

/****************************************************************

   FUNCTION:voidtringToDouble(string s);

   ARGUMENTS: string that needs to be converted to a double

   RETURNS: double value of string

  ****************************************************************/


double stringToDouble(string s) {
    double d;
    stringstream ss(s); //turn the string into a stream                     // this function takes string stream and converts string into double
    ss >> d; //convert
    return d;
}


