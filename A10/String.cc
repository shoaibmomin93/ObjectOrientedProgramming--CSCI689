/****************************************************************
   PROGRAM:   A USER DEFINED STRING CLASS
   AUTHOR:    SHOAIB MOMIN
   LOGON ID:  Z1777526
   DUE DATE:  Monday, November 16, 2015

   FUNCTION:  Various constructors and methods for the class have been defined.
              

   INPUT:     Data file provided.
              

   OUTPUT:    Results of operations performed on string

****************************************************************/




#include"String.h"
const size_t String:: npos=-1;         //initalize the npos value to max integer value of system
/****************************************************************

   FUNCTION:  String()

   ARGUMENTS:  none

   RETURNS:    nothing

****************************************************************/
String::String()
{
p=new char[1];    // dynamic allocation of memory
sz=0;          // initial size is 0
p[0]='\0';        //since it is character array
}


/****************************************************************

   FUNCTION:  String(const String& s)

   ARGUMENTS:  constant String

   RETURNS:    nothing

****************************************************************/

String :: String(const String& s)
{
//p=s.p;
sz= s.length();              //copy constructor and so copy the members
p=new char[sz+1];          //initialize the pointer
for(unsigned i=0; i<sz;i++)          //copy characters
p[i]=s.p[i];
p[sz]='\0';         

}


/****************************************************************

   FUNCTION:  String( const String& s, const size_t& pos, const size_t& n  )

   ARGUMENTS:  String s, pos, n values

   RETURNS:    nothing

****************************************************************/

String::String ( const String& s, const size_t& pos, const size_t& n  )
{
unsigned i,j;
sz=n;
p=new char[n+1];
for(i=pos,j=0;j<n;i++,j++)       // copies n values of string from pos position
{
p[j]=s.p[i];
}
p[j]='\0';

}

/****************************************************************

   FUNCTION:  String(const char* cs, const size_t& n)

   ARGUMENTS:  c-string, n values

   RETURNS:    nothing

****************************************************************/


String::String(const char* cs, const size_t& n)
{
unsigned i;
p=new char[n+1];
for(i=0;i<n;i++)     // copy n characters from the c string
p[i]=cs[i];
sz=n;
p[n]='\0';
}

/****************************************************************

   FUNCTION:  String(const char* cs)

   ARGUMENTS:  constant c string

   RETURNS:    nothing

****************************************************************/


String::String(const char* cs)
{
unsigned i;
unsigned count=0;
 for( i=0; cs[i]!='\0'; i++)  // get the length of c string
    count++;
sz=count;
p=new char[count+1];
for( i=0;i<count;i++)  // copy the string 
p[i]=cs[i];
p[i]='\0';
}

/****************************************************************

   FUNCTION:  String(const size_t& n, const char& c)

   ARGUMENTS:  size and c

   RETURNS:    nothing

****************************************************************/


String::String(const size_t& n, const char& c)
{
unsigned i;
sz=n;
p=new char[n+1];
for( i=0; i<n;i++)
{
p[i]=c;                       // have n copies of character c in the String
}
p[i]='\0';
}

/****************************************************************

   FUNCTION:  ~String()

   ARGUMENTS:  none

   RETURNS:    nothing

****************************************************************/


String::~String()
{
delete[] p;         //frees the memory of the members
sz=0;
p=NULL;
}

/****************************************************************

   FUNCTION:  String& String:: operator= ( const String& s )

   ARGUMENTS:  constant String s

   RETURNS:    String value

****************************************************************/

String& String:: operator= ( const String& s )
{
/*if(s.sz>0)
{
unsigned i;
sz=s.sz;
char *temp=new char[sz+1];
for(i=0; i<sz;i++)
temp[i]=s.p[i];
temp[i]='\0';
if(p) delete [] p;
p=temp;
}
else
{
sz=0;
if(p) delete [] p;
p=NULL;
}
*/
if(this!= &s)           // check for self assignment
{
delete []p;            // delete the contents of p
p=new char[s.sz+1];       //allocate memory to p
unsigned i;
for(i=0;i<s.sz;i++)       // assign data to String
p[i]=s.p[i];
p[i]='\0';
sz=s.sz;
}
return *this;  // return string
}


/****************************************************************

   FUNCTION:  String& String::operator= ( const char* cs )

   ARGUMENTS:  const c string

   RETURNS:    String object

****************************************************************/

String& String::operator= ( const char* cs )
{
/*
if(cs[0]!='\0')
{
unsigned j;
int count=0;
for(unsigned i=0; cs[i]!='\0';i++)
count++;
sz=count;
char *temp=new char[sz+1];
for(j=0; j<sz;j++)
temp[j]=cs[j];
temp[j]='\0';
if(cs) delete []cs;
p=temp;
}
else
{
sz=0;
if(p) delete [] p;
p=NULL;
}
*/
//if(this->p != cs)

unsigned count=0;
unsigned i;
for( i=0; cs[i]!='\0';i++)     // get the length of c string
count++;
delete []p;
p=new char[count+1 ];            //assign values to String
for(i=0;i<count;i++)
p[i]=cs[i];
p[i] = '\0';
//am Young University[i]='\0';
sz=count;

return *this;           // return String
}

/****************************************************************

   FUNCTION:  String& String::operator= ( const char& c )

   ARGUMENTS: constant char

   RETURNS:    String value

****************************************************************/

String& String::operator= ( const char& c )
{
/*
if(c!='\0')
{
sz=1;
char *temp= new char[sz+1];
temp[0]=c;
temp[1]='\0';
if(p) delete []p;
p=temp;
}
else
{
sz=0;
if(p) delete []p;
p=NULL;
}
*/
//if(this->p!=&c)

unsigned i;
delete []p;           //delete p
p=new char[1+1];   //allocate new memory
for(i=0;i<1;i++)
p[i]=c;             //assign values
p[i]='\0';
sz=1;

return *this;         //return string
}




//operator +=

/****************************************************************

   FUNCTION:  String& String::operator+= (const String& s)

   ARGUMENTS:  constant String

   RETURNS:    String value

****************************************************************/

String& String::operator+= (const String& s)
{
//String s1;           // create the resultant String

int i,j;
int l=s.length();
for(i=sz,j=0;j<l;i++,j++){    // conactenate the strings
expandMem(1);          //expand memory as you build it
p[i]=s.p[j];
//sz++;
//expandMem(1);
}
expandMem(1);
p[sz]='\0';
return *this;                  //return string
}

/****************************************************************

   FUNCTION: String& String:: operator+=(const char*cs)

   ARGUMENTS: constant c style string

   RETURNS:   String value

****************************************************************/


String& String:: operator+=(const char*cs)
{
//String a;
int i,j;
for(i=0,j=sz;cs[i]!='\0';i++,j++)            //conatenate two strings
{
expandMem(1);          //expand memory for resultant string
p[j]=cs[i];
//expandMem(1);
//sz++;
}
expandMem(1);
p[sz]='\0';
return *this;                      //return string
}

/****************************************************************

   FUNCTION:  String& String::operator+=(const char& c)

   ARGUMENTS:  constant char c

   RETURNS:   String value

****************************************************************/

String& String::operator+=(const char& c)
{
//String s;
p[sz]=c;            //append the character to the string
expandMem(1);
p[sz]='\0';      
return *this;            //return string
}

//length

/****************************************************************

   FUNCTION:  size_t String::length()const

   ARGUMENTS:  none

   RETURNS:   length of string

****************************************************************/

size_t String::length()const
{
return sz;           // return sz member
}

/****************************************************************

   FUNCTION: size_t String::size() const

   ARGUMENTS:  none

   RETURNS:   length of strinf

****************************************************************/

size_t String::size() const
{
return sz;            //return length
}

// empty

/****************************************************************

   FUNCTION:  bool String::empty() const

   ARGUMENTS:  none

   RETURNS:   boolean value , true for empty

****************************************************************/

bool String::empty() const
{
return sz==0;          //returns true if size is 0
}

/****************************************************************

   FUNCTION:  void String::clear()

   ARGUMENTS:  none

   RETURNS:    nothing

****************************************************************/

void String::clear()
{
delete[]p;         // clears all the memory
p=NULL;
sz=0;
}

// sunscription

/****************************************************************

   FUNCTION:  char& String::operator[](const size_t& pos)

   ARGUMENTS:  position

   RETURNS:    character at that position

****************************************************************/

char& String::operator[](const size_t& pos)
{
return p[pos];         //returns the character at that position
}

/****************************************************************

   FUNCTION:  const char& String::operator[](const size_t& pos)const

   ARGUMENTS: position

   RETURNS:    character at that position

****************************************************************/

const char& String::operator[](const size_t& pos)const
{
return p[pos];        //returns character at that position
}

/****************************************************************

   FUNCTION:  char& String::at(const size_t& pos)

   ARGUMENTS:  position

   RETURNS:    character at that position

****************************************************************/

char& String::at(const size_t& pos)
{
char *a;
a=new char[1];
a[0]='\0';
if(pos>sz ){ cerr<<"Invalid position"<<endl; return a[0];}       //performs error checking and returns empty with error message
else
{
 return p[pos];     //or return position
}
}

/****************************************************************

   FUNCTION:  const char& String::at(const size_t& pos) const

   ARGUMENTS:  position

   RETURNS:    character at that position

****************************************************************/

const char& String::at(const size_t& pos) const
{

char *a;
a=new char[1];
a[0]='\0';
if( pos>sz){ cerr<<"Invalid position"<<endl; return a[0]; } //performs error checking and returns empty string and error message
else
{
return p[pos];      //or return position
}
}

//substr function

/****************************************************************

   FUNCTION:  String String::substr(const size_t& pos,const size_t& n)

   ARGUMENTS:  position and n value

   RETURNS:    String value

****************************************************************/

String String::substr(const size_t& pos,const size_t& n)
{
String a;
//a.p[0]='\0';
unsigned i,j;
if( pos>sz) {cerr<<"Invalid position"<<endl; return a;}        //perform error checking and return error message 
if(pos==sz) return a;      //return empty string
//if( n>sz){cerr<<"Invalid number of characters"<<endl; return a; }
else
{
for( i=pos,j=0;(j<n&&i< sz);i++,j++)
{ a.expandMem(1);
a.p[j]=p[i];        //or build the new string of n values from pos
}
a.expandMem(1);
a.p[j]='\0';
return a;               //return string
}
}

//c_str

/****************************************************************

   FUNCTION:  const char* String::c_str() const

   ARGUMENTS:  none

   RETURNS:   c-string

****************************************************************/

const char* String::c_str() const
{
return p;            //returns the c string
}

/****************************************************************

   FUNCTION:  const char* String::data() const

   ARGUMENTS:  none

   RETURNS:   c string

****************************************************************/

const char* String::data() const
{
return p;        //returns c string
}

//push_back

/****************************************************************

   FUNCTION:  void String::push_back(const char& c )

   ARGUMENTS:  character c

   RETURNS:    nothing

****************************************************************/

void String::push_back(const char& c )
{
expandMem(1);      //increase capacity
p[sz-1]=c;        //add the character
p[sz]='\0';


}

/****************************************************************

   FUNCTION:  void String::expandMem(const size_t& n)

   ARGUMENTS:  size n

   RETURNS:    nothing

****************************************************************/

void String::expandMem(const size_t& n)
{
   char *oldp = p;       //save the original p
   int count=sz;    //save the size
   sz += n;              //increase the size
   p = new char[sz+1];   //create a new memory with required size
   for (int i = 0; i < count; i++) {
      p[i] = oldp[i];               //copy the ontents of original string
   }
   delete[] oldp;         //delete temp string
}

//stream insertion

/****************************************************************

   FUNCTION:  ostream& operator<<(ostream& os, const String& s)

   ARGUMENTS:  ostream and String

   RETURNS:    ostream

****************************************************************/

 ostream& operator<<(ostream& os, const String& s)
{
for(unsigned i=0; i<s.sz;i++)
os<<s.p[i];               //display the contents of the string

return os;                //return stream
}

/****************************************************************

   FUNCTION:  istream& operator>>(istream& is, String& s)

   ARGUMENTS:  istream, String

   RETURNS:    istream

****************************************************************/

istream& operator>>(istream& is, String& s)
{

getline(is,s,'\n');        //using getline
return is;           //return stream
}

/****************************************************************

   FUNCTION:  istream& getline(istream& is, String& s, const char& del)

   ARGUMENTS:  isstrem, String and del

   RETURNS:    istream object

****************************************************************/

istream& getline(istream& is, String& s, const char& del)
{
//int i=0;
/*
while(true)
{
is>> s.p[i];
if(s.p[i]== del) break;
i++;
}
*/

/*
char ch;
while(true)
{                   // take in values as long as delimiter is not reached
ch=is.get();
if(ch==del) break;
s.p[i]=ch;             //store it in buffer
is>>s.p[i];
}
*/
s.clear();
char c;
while(is.get(c) && c != del){s.push_back(c);}



//is>>s;
return is;    //return stream
}

//operator +

/****************************************************************

   FUNCTION:  String operator+(const String& s1, const String& s2)

   ARGUMENTS:  String objects viz s1, s2

   RETURNS:    String object

****************************************************************/

String operator+(const String& s1, const String& s2)
{
unsigned i,j;
String s3;       //create a new string 
for( i=0;i<s1.size();i++)
{                               //fill it with contents of first string
s3.expandMem(1);
s3.p[i]=s1.p[i];
//s3.sz++;
}
for( i=s1.size(),j=0;j<s2.size();i++,j++)         //add contents of second string
{
s3.expandMem(1);
s3.p[i]=s2.p[j];
//s3.sz++;
}
s3.expandMem(1);
s3.p[i]='\0';
return s3;                   //return string
} 

/****************************************************************

   FUNCTION:  String operator+(const String& s, const char* cs)

   ARGUMENTS:  String s, cstring cs

   RETURNS:    String object

****************************************************************/

String operator+(const String& s, const char* cs)
{
unsigned i,j; 
String s3;             //create new string
for( i=0; i<s.size();i++)
{
s3.expandMem(1);                    //fill it with 1st string content
s3.p[i]=s.p[i];
}
for( i=0,j=s.size(); cs[i]!='\0';i++,j++)
{
s3.expandMem(1);                        //add second string
s3.p[j]=cs[i];
}
s3.expandMem(1);
s3.p[j]='\0';
return s3;               //return string
}

/****************************************************************

   FUNCTION:  String operator+ (const char*cs, const String& s)

   ARGUMENTS:  c string cs, String s

   RETURNS:    String object

****************************************************************/

String operator+ (const char*cs, const String& s)
{
String s3; //create new string
int j,n=0;
unsigned i;
for( i=0;cs[i]!='\0';i++){     //fill contents of first string
s3.expandMem(1);
s3.p[i]=cs[i];
n++;
}
for( i=0,j=n;i<s.size();i++,j++)
{                          //add second string
s3.expandMem(1);
s3.p[j]=s.p[i];
}
s3.expandMem(1);
s3.p[j]='\0';
return s3;                   //return string
}

/****************************************************************

   FUNCTION:  String operator+(const String&s, const char& c)

   ARGUMENTS:  String s and character c

   RETURNS:   String object

****************************************************************/

String operator+(const String&s, const char& c)
{
String s3;         //create new string
unsigned i;
for( i=0; i<s.size();i++)
{                              //fill contents of first string
s3.expandMem(1);
s3.p[i]=s.p[i];
}

s3.expandMem(1);
s3.p[i]=c;                     //add charcater
i++;
s3.expandMem(1);
s3.p[i]='\0';
return s3;                       //return string
}

/****************************************************************

   FUNCTION:  String operator+(const char& c, const String& s)

   ARGUMENTS:  char c, String s

   RETURNS:   String object

****************************************************************/

String operator+(const char& c, const String& s)
{
 String s3;       //create new string
int i=0;
unsigned j;
s3.expandMem(1);
s3.p[i]=c;        //fill it with charcater
for(i=1,j=0;j<s.size();j++,i++)
{
s3.expandMem(1);           //add the String
s3.p[i]=s.p[j];
}
s3.expandMem(1);
s3.p[i]='\0';
return s3;            //return final string
}

/****************************************************************

   FUNCTION:  bool operator==(const String& s1, const String& s2)

   ARGUMENTS:  Strings s1, s2

   RETURNS:    bool value, true if equal

****************************************************************/

bool operator==(const String& s1, const String& s2)
{
unsigned i;
if(s1.size()!=s2.size()) return false;
for(i=0;i<s1.size();i++)
{
if(s1.p[i]!=s2.p[i]) return false;         // returns false if the strings are not equal
}
return true; // or return true
}

/****************************************************************

   FUNCTION:  bool operator!=(const String& s1, const String& s2)

   ARGUMENTS:  String s1, s2

   RETURNS:    boolean value

****************************************************************/

bool operator!=(const String& s1, const String& s2)
{
unsigned i;

if(s1.size()!=s2.size()) return true;           //return true if not equal
for(i=0;i<s1.size();i++)
{
if(s1.p[i]!=s2.p[i]) return true;
}
return false;        //or return true
}

/****************************************************************

   FUNCTION:  bool operator<(const String& s1, const String& s2)

   ARGUMENTS:  String s1, s2

   RETURNS:    bool value

****************************************************************/

bool operator<(const String& s1, const String& s2)
{
int i;

for(i=0; s1.p[i]!='\0' && s2.p[i]!='\0' ; i++)
{
//cout<<"s1.p[i]"<<s1.p[i]<<endl<<"s2.p[i]"<<s2.p[i]<<endl;
if(s1.p[i]<s2.p[i]) return true;           //if less than then true
}
return false;             //or false
}

/****************************************************************

   FUNCTION:  bool operator<=(const String& s1, const String& s2)

   ARGUMENTS:  none

   RETURNS:    nothing

****************************************************************/


bool operator<=(const String& s1, const String& s2)
{
int i;
for(i=0; s1.p[i]!='\0' && s2.p[i]!='\0' ; i++)
{

if(s1.p[i]<s2.p[i] || s1.p[i]==s2.p[i]) return true; //if less than or equal then truw
}

return false;  //or false
}

/****************************************************************

   FUNCTION:  bool operator>(const String& s1, const String& s2)

   ARGUMENTS:  Strings s1, s2

   RETURNS:    bool value

****************************************************************/

bool operator>(const String& s1, const String& s2)
{
int i;
for(i=0; s1.p[i]!='\0' && s2.p[i]!='\0' ; i++)
{
if(s1.p[i]<s2.p[i]) return false;      //if less than then false 
}
return true;       //or true
}

/****************************************************************

   FUNCTION:  bool operator>=(const String& s1, const String& s2)

   ARGUMENTS:  Strings s1, s2

   RETURNS:    bool value

****************************************************************/

bool operator>=(const String& s1, const String& s2)
{
int i;
for(i=0; s1.p[i]!='\0' && s2.p[i]!='\0' ; i++)
{

if(s1.p[i]<s2.p[i] ||s1.p[i]==s2.p[i]) return false;   //if less than or equal false

}
return true; //or true
}

