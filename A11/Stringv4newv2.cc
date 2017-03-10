/**************************************************************

   PROGRAM:   A USER DEFINED STRING CLASS- PHASE 2
   AUTHOR:    SHOAIB MOMIN
   LOGON ID:  Z1777526
   DUE DATE:  Tuesday, November 24, 2015

   FUNCTION:  Various constructors and methods for the class have been defined.


   INPUT:     Data file provided.


   OUTPUT:    Results of operations performed on string

****************************************************************/


#include "String.h"
const size_t String::npos=-1;  //initalize the npos value to max integer value of system

/****************************************************************

   FUNCTION:  String()

   ARGUMENTS:  none

   RETURNS:    nothing

****************************************************************/


String::String(){
sz=1;	               // dynamic allocation of memory
p=new char[sz];	  // initial size is 01 including \0

p[0]='\0';		 //since it is character array
}


/****************************************************************


FUNCTION:  String(const String& s)

   ARGUMENTS:  constant String

   RETURNS:    nothing

****************************************************************/

String::String(const String& s){
unsigned l,count=0;	
for(l=0;s.p[l]!='\0';l++)count++;;	 //copy constructor and so copy the members
p=new char[count+1];	  //initialize the pointer
sz=count+1;		
for(unsigned i=0;i<sz;i++)
p[i]=s.p[i];	 //copy characters 
}

/****************************************************************

   FUNCTION:  String( const String& s, const size_t& pos, const size_t& n  )

   ARGUMENTS:  String s, pos, n values

   RETURNS:    nothing

****************************************************************/

String::String(const String& s, const size_t& pos, const size_t& n){
sz=n+1;		
p=new char[n+1];	
for(unsigned i=pos,j=0; i<pos+n;i++,j++){    // copies n values of string from pos position
p[j]=s.p[i];	
}
p[sz-1]='\0';	
}
/****************************************************************

   FUNCTION:  String(const char* cs, const size_t& n)

   ARGUMENTS:  c-string, n values

   RETURNS:    nothing

****************************************************************/
String::String(const char* cs, const size_t& n){    
sz=n+1;		
p=new char[sz];	                // copy n characters from the c string
for(unsigned i=0;(i<n&&i<sz-1);i++)
p[i]=cs[i];		
p[sz-1]='\0';	
}
/****************************************************************

   FUNCTION:  String(const char* cs)

   ARGUMENTS:  constant c string

   RETURNS:    nothing

****************************************************************/

String::String(const char* cs){
unsigned count=0;;	
for(unsigned len=0;cs[len]!='\0';len++) count++;   // get the length of c string
sz=count+1;		
p=new char[sz];	
for(unsigned i=0;i<sz-1;i++)
p[i]=cs[i];		              // copy the string
p[sz-1]='\0';	
}
/****************************************************************

   FUNCTION:  String(const size_t& n, const char& c)

   ARGUMENTS:  size and c

   RETURNS:    nothing

****************************************************************/

String::String(const size_t& n, const char& c){
sz=n+1;		
p=new char[n+1];	
for(unsigned i=0;i<n;i++)
p[i]=c;		  // have n copies of character c in the String
p[n]='\0';	
}
/****************************************************************

   FUNCTION:  ~String()

   ARGUMENTS:  none

   RETURNS:    nothing

****************************************************************/

String::~String(){
delete [] p;	  //frees the memory of the members
p=NULL;
sz=0;		
}	
		

/**************************************************************
   FUNCTION:  String& String:: operator= ( const String& s )

   ARGUMENTS:  constant String s

   RETURNS:    String value

***************************************************************/

String& String::operator=(const String& s)
{
sz=s.sz;		
delete [] p;   // delete the contents of p
p=new char[s.sz];	//allocate memory to p
for(unsigned i=0;i<s.sz-1;i++)
p[i]=s.p[i];	 // assign data to String
p[sz-1]='\0';	
return *this; // return string
}

/**************************************************************

   FUNCTION:  String& String::operator= ( const char* cs )

   ARGUMENTS:  const c string

   RETURNS:    String object

**************************************************************/
String& String::operator=(const char* cs)
{
unsigned count=0;
for(unsigned len=0;cs[len]!='\0';len++) count++;  // get the length of c string
sz=count+1;		
delete[] p;
p=new char[sz];	//assign values to String	
for(unsigned i=0;i<(sz-1);i++)
p[i]=cs[i];		
p[sz-1]='\0';	
return *this;	// return String
}

/****************************************************************

   FUNCTION:  String& String::operator= ( const char& c )

   ARGUMENTS: constant char

   RETURNS:    String value

****************************************************************/
String& String::operator=(const char& c){
sz=2;		
delete[] p;		 //delete p
p=new char[sz];	 //allocate new memory
p[0]=c;       //assign values
p[sz-1]='\0';
return *this;  //return string
}

/*************************************************************

   FUNCTION:  String& String::operator+= (const String& s)

   ARGUMENTS:  constant String

   RETURNS:    String value

**************************************************************/

String& String::operator+=(const String& s)
{
unsigned  len=s.sz+sz-1;
char *temp=new char[len];   // create the resultant string
for(unsigned i=0;i<sz-1;i++)  temp[i]=p[i];
for(unsigned j=0;j<s.length();j++) temp[j+sz-1]=s.p[j]; //conactenate the strings
delete [] p;
sz=len;
p= new char[sz];
for(unsigned k=0;k<sz;k++) p[k]=temp[k];
return *this;  //return string
}


/*********************************************************

   FUNCTION: String& String:: operator+=(const char*cs)

   ARGUMENTS: constant c style string

   RETURNS:   String value

**************************************************************/


String& String::operator+=(const char* cs)
{
unsigned count=0;
for(unsigned len=0;cs[len]!='\0';len++) count++;
char *temp=new char[sz+count];
for(unsigned i=0;i<sz-1;i++) temp[i]=p[i];
for(unsigned j=0;j<=count;j++) temp[sz-1+j]=cs[j]; //conatenate two strings
delete [] p;
p= new char[sz+count];
for(unsigned k=0;k<(sz+count);k++) p[k]=temp[k];
sz=sz+count;
return *this;//return string
}

/*************************************************************

   FUNCTION:  String& String::operator+=(const char& c)

   ARGUMENTS:  constant char c

   RETURNS:   String value

*************************************************************/
String& String::operator+=(const char& c)
{
unsigned len=sz+1;
char *temp=new char[len];
for(unsigned i=0;i<sz-1;i++)    temp[i]=p[i];
delete [] p;
p= new char[len];
sz=len;
for(unsigned j=0;j<len-2;j++) p[j]=temp[j];
p[len-2]=c;                      //append the character to the string
p[len-1]='\0';
return *this;     //return string
}

/************************************************************

   FUNCTION:  size_t String::length()const

   ARGUMENTS:  none

   RETURNS:   length of string

**********************************************************/
size_t String::length() const
{
return sz-1;          // return sz member
}
/***********************************************************

   FUNCTION: size_t String::size() const

   ARGUMENTS:  none

   RETURNS:   length of strinf

***********************************************************/

size_t String::size() const
{
return sz-1;   //return length
}

/*******************************************************

   FUNCTION:  bool String::empty() const

   ARGUMENTS:  none

   RETURNS:   boolean value , true for empty

***********************************************************/
bool String::empty() const
{
return (sz==1);   //returns true if size is 0
}

/**TION:  void String::expandMem(const size_t& n)

   ARGUMENTS:  size n

   RETURNS:    nothing

****************************************************************/

void String::expandMem(const size_t& n)
{
//      cout<<"enter expand mem"<<endl;
   char *oldp = p;       //save the original p
//cout<<"sz before incrememnt is "<<sz<<endl;
   int count=sz;    //save the size
   sz += n;
//delete []p;              //increase the size
//cout<<"sz after incrememnt is "<<sz<<endl;
//cout<<"before alloc"<<endl;
p=NULL;
 p = new char[sz+1];   //create a new memory with required size
//cout<<"after alloc"<<endl;
   for (int i = 0; i < count; i++) {

      p[i] = oldp[i];               //copy the ontents of original string
   }

  delete[] oldp;         //delete temp string
}
/********************************************************


   FUNCTION:  void String::clear()

   ARGUMENTS:  none

   RETURNS:    nothing

***********************************************************/

void String::clear()
{
delete [] p;       // clears all the memory
p=new char[1];
p[0]='\0';
sz=1;
}

/************************************************************

   FUNCTION:  ostream& operator<<(ostream& os, const String& s)

   ARGUMENTS:  ostream and String

   RETURNS:    ostream

*************************************************************/
ostream& operator<< ( ostream& os, const String& s )
{
os<<s.p;   //display the contents of the string
return os;    //return stream
}

/***********************************************************
FUNCTION : String& String::assign(const String& s )

   ARGUMENTS:  string s

   RETURNS:    Strng object

*************************************************************/



String& String::assign(const String& s)
{
/*
if(this!= &s)           // check for self assignment
{
delete []p;            // delete the contents of p
p=new char[s.sz+1];       //allocate memory to p
unsigned i;
for(i=0;i<s.sz;i++)
{
expandMem(1);       // assign data to String
p[i]=s.p[i];
}
expandMem(1);
p[i]='\0';
sz=s.sz;
}
*/
return *this=s;        //use previously defined =
}

/***********************************************************
FUNCTION : String& String::assign(const String& s, const size_t& pos, const size_t& n)

   ARGUMENTS:  string s, pos, n

   RETURNS:    Strng object

*************************************************************/	
String& String::assign(const String& s, const size_t& pos, const size_t& n)
{
String res(s,pos,n);    // create object with given conditions
delete[] p;
sz=res.sz;
p=new char[sz];           //update the current p and copy contents
for(unsigned i=0;i<sz;i++) p[i]=res.p[i];
return *this;
}


/***********************************************************
FUNCTION : String& String::assign(const char *cs, const size_t& n)

   ARGUMENTS:  char *cs,  n

   RETURNS:    Strng object

*************************************************************/

String& String::assign(const char*cs, const size_t& n)
{
sz=n+1;                // create p with updated length
p=new char[sz];
for(unsigned i=0;i<sz-1;i++) p[i]=cs[i];       //copy contents
p[sz-1]='\0';
return *this;

}

/***********************************************************
FUNCTION : String& String::assign(const char * cs)

   ARGUMENTS:  char *cs

   RETURNS:    Strng object

*************************************************************/

String& String::assign(const char*cs)
{
String res(cs);          // create object for cs
return *this=res;       //use previously defined =
}

/***********************************************************
FUNCTION : String& String::assign( const size_t& n, const char c)

   ARGUMENTS:  n characters, c character

   RETURNS:    Strng object

*************************************************************/
String& String::assign(const size_t& n,const char c)
{
String res(n,c);              //create objcet according to specification
return *this=res;   // use = operator previously defined
}


/***********************************************************
FUNCTION : String& String::append(const String& s)

   ARGUMENTS:  string 

   RETURNS:    Strng object

*************************************************************/

String& String::append(const String& s)
{
return *this+=s;          //use += previously defined
}

/***********************************************************
FUNCTION : String& String::append(const String& s, const size_t& pos, const size_t& n)

   ARGUMENTS:  string s, pos, n

   RETURNS:    Strng object

*************************************************************/

String& String::append(const String& s, const size_t& pos, const size_t& n)
{
/*
size_t m;
if(n==s.length())
{ m= s.sz-pos;}
else m=n;
String s1(s,pos,m);
*this+=(s1);
return *this;
*/
String res(s,pos,n);   // create object according to specification
return *this+=res;        //use previously defined +=
}

/***********************************************************
FUNCTION : String& String::append(const char * cs, const size_t& n)

   ARGUMENTS:  char *cs, n

   RETURNS:    Strng object

*************************************************************/

String& String::append(const char*cs, const size_t& n)
{
String res(cs,n);        //create object with current string
return *this+=res;           //use += previously defined
}

/***********************************************************
FUNCTION : String& String::append(const char * cs)

   ARGUMENTS:  char *cs

   RETURNS:    Strng object

*************************************************************/

String& String::append(const char* cs)
{
return *this+=cs;    //use += previously defined
}

/***********************************************************
FUNCTION : String& String::append( const size_t& n, const char& c)

   ARGUMENTS:  n , c character

   RETURNS:    Strng object

*************************************************************/

String& String::append(const size_t& n, const char& c)
{
String s1(p);         // create object fr current string
String s2(n,c);           //create object according to specification
s1+=s2;
delete[] p;         ///use ++ previously defined
sz=s1.sz;
p= new char[sz];                    //update current object
for(unsigned i=0;i<sz;i++) p[i]=s1.p[i];
return *this;
}


/***********************************************************
FUNCTION : String& String::compare(const String& s)

   ARGUMENTS:  String s

   RETURNS:    integer value 1 or 0 

*************************************************************/

int String::compare(const String& s)const
{

if(sz!=s.sz) return 1;              //if they are not equal return 1

else for(unsigned i=0;i<s.length();i++){
if(p[i]!=s.p[i]) return 1;               // any character is not equal, return1

}

return 0;           //if equal, return 0
}

/***********************************************************
FUNCTION : String& String::compare(const char * cs)

   ARGUMENTS:  char *cs

   RETURNS:    integer value 1 or 0

*************************************************************/

int String::compare(const char* cs)const
{
String res(cs);        //creae string object
return (*this).compare(res);      // call previously defined compare
}

/***********************************************************
FUNCTION : String& String::compare(const size_t& pos, const size_t & n,const String& s)

   ARGUMENTS:  pos, n String

   RETURNS:    integer value 1 or 0

*************************************************************/

int String::compare(const size_t& pos, const size_t& n, const String& s)const
{
String res(p,pos,n);        //create object according to specification
return res.compare(s);     //call previously defined compare
}

/***********************************************************
FUNCTION : String& String::compare(const size_t & pos, const size_t& n, const char* cs)const

   ARGUMENTS:  pos , n , char*cs

   RETURNS:    integer value 1 or 0

*************************************************************/

int String::compare ( const size_t& pos, const size_t& n, const char* cs ) const{
String res1(p,pos,n);           //create objects accordingly
String res2(cs);
return res1.compare(res2);         //call previously defined compare
}

/***********************************************************
FUNCTION : String& String::compare(const size_t& pos1, const size_t& n1,const String& s, const size_t& pos2, const size_t& n2))

   ARGUMENTS:  pos1, pos2, n1, n2, String s

   RETURNS:    integer value 1 or 0

*************************************************************/


int String::compare(const size_t& pos1, const size_t& n1, const String& s, const size_t& pos2, const size_t& n2 )const
{
String res1(p,pos1,n1);        //create objects accordingly
String res2(s,pos2,n2);                 //call previously defined compare
return res1.compare(res2);
}

/***********************************************************
FUNCTION : String& String::compare(const size_t& pos, const size_t&n1, const char*cs, const size_t& n2)

   ARGUMENTS:  pos, n1, n2 , char *cs

   RETURNS:    integer value 1 or 0

*************************************************************/


int String::compare ( const size_t& pos, const size_t& n1, const char* cs, const size_t& n2 )const
{
String res1(p,pos,n1);              //create string objects respectively
String res2(cs,0,n2);
return res1.compare(res2);        //call previously defined compare
}

/***********************************************************
FUNCTION : String& String::insert(const size_t&pos, const String& s)

   ARGUMENTS:  pos, String s

   RETURNS:   String object

*************************************************************/

String& String::insert (const size_t& pos, const String& s)
{
/*
for(unsigned i =pos, j =0;  j <s.sz ; i++,j++)
{
expandMem(1);
for(unsigned k=sz-1;k>=pos+j;k--)
{
 p[k+1]=p[k];
}
}
for(unsigned i=pos,j=0;j<s.sz;i++,j++)
{
p[i]=s.p[j];
}
return *this;

*/
String res1(p);      //create a new object with current contents
delete[] p;              // delete current string
sz=res1.sz+s.sz-1;         
p=new char[sz];      //create new string for current object with updated size
unsigned i,j;
for(i=0;i<pos;i++) p[i]=res1.p[i];
for(i=pos,j=0;j<s.sz-1;i++,j++) p[i]=s.p[j];     //copy the contents accordingly
for(i=pos+s.sz-1,j=pos;i<sz;j++,i++) p[i]=res1.p[j];
return *this;
}

/***********************************************************
FUNCTION : String& String::insert(const size_t& pos1, const String& s, const size_t& pos2, const size_t& n)

   ARGUMENTS:  pos1, s, pos2 ,n

   RETURNS:   String object

*************************************************************/

String& String::insert ( const size_t& pos1, const String& s, const size_t& pos2, const size_t& n )
{
String res1(s,pos2,n);
String res2(p);              //create new objectsand call above defined insert
return *this=res2.insert(pos1,res1);
   
}

/***********************************************************
FUNCTION : String& String::insert(const size_t& pos, const char* cs, const size_t& n)

   ARGUMENTS:  pos, cs, n

   RETURNS:   String object

*************************************************************/

String& String::insert ( const size_t& pos, const char* cs, const size_t& n )
{
String res1(cs,n);        //create a object with cs, n
String res2(p);          //create object of current string
return *this=res2.insert(pos,res1);           // call earlier defined insert
}

/***********************************************************
FUNCTION : String& String::insert(const size_t& pos, const char* cs)

   ARGUMENTS:  pos, cs

   RETURNS:   String object

*************************************************************/

String& String::insert ( const size_t& pos, const char* cs )
{
String res1(cs);        // create object with cs
String res2(p);           //create object of current string
return *this=res2.insert(pos,res1);         // call earlier defined insert
}

/***********************************************************
FUNCTION : String& String::insert(const size_t& pos, const size_t& n, const char& c)

   ARGUMENTS:  pos, n, c

   RETURNS:   String object

*************************************************************/

String& String::insert ( const size_t& pos, const size_t& n, const char& c )
{
String res1(n,c);       // create string object with n, c
String res2(p);         // create object with current string
return *this=res2.insert(pos,res1);         // call insert defined earlier
}


/***********************************************************
FUNCTION : String& String::erase(const size_t& pos, const size_t& n)

   ARGUMENTS:  pos, n

   RETURNS:   String object

*************************************************************/


String& String::erase(const size_t& pos, const size_t& n)
{
String res1(p);       // copy the string to a new object
delete [] p;         //delete the string
sz=res1.sz-n;
p=new char[sz];          // update the size of current pointer string
unsigned i,j;
for(i=0;i<pos;i++) p[i]=res1.p[i];
for(i=pos,j=pos+n;j<res1.sz;j++,i++) p[i]=res1.p[j];    // copy the contents
return *this;
/*
//String s1;
if(pos==0 && n==npos) {
delete [] p;
 p=NULL;
p=new char[1];
p[0]='\0';
sz=0;
 return *this;}

//String s1;
else
{

unsigned l,i;
if(sz-pos <n ) l=sz-pos;
else l=n;
//cout<<"l is "<<l<<endl;
//cout<<"pos is" <<pos<<endl;
for( i=pos;i<pos+l+9;i++)
{
p[i]= p[i+l];
//cout<<"p[i] is "<<p[i]<<endl;
}
p[i]='\0';
sz=sz-l;
//cout<<"p[i] is "<<p[i]<<endl;
//p[i]=s.p[j];

return *this;

}

*/
}

/***********************************************************
FUNCTION : String& String::replace, (const size_t& pos, const size_t& n, const String& s)

   ARGUMENTS:  pos, n, s

   RETURNS:   String object

*************************************************************/

String& String::replace ( const size_t& pos, const size_t& n, const String& s )
{
/*
unsigned i,j;
String s1;
for(i=0;i<pos1;i++)
{
s1.expandMem(1);
s1.p[i]=p[i];
}
for(j=pos2;j<pos2+n2;j++,i++)
{
s1.expandMem(1);
s1.p[i]=s.p[j];
}
for(j=pos1+n1;j<sz;j++,i++)
{
s1.expandMem(1);
s1.p[i]=p[j];
}
s1.expandMem(1);
s1.p[i]='\0';
return s1;
*/
String res1(p);                // get the current string in a new object
res1.erase(pos,n);            // erase the contents that need to be replaced
res1.insert(pos,s);         //insert new data
sz=res1.sz;
delete [] p;
p=new char[sz];                                //update current object
for(unsigned i=0;i<sz;i++) p[i]=res1.p[i];
return *this;
}

/***********************************************************
FUNCTION : String& String::replace(const size_t& pos1, const size_t& n1, const String& s,const size_t& pos2, const size_t& n2 )

   ARGUMENTS:  pos1,pos2 n1, n2, s

   RETURNS:   String object

*************************************************************/


String& String::replace( const size_t& pos1, const size_t& n1, const String& s, const size_t& pos2, const size_t& n2 )
{
String res1(p);                // the current string is copied to a new String object
String res2(s,pos2,n2);     // create a new string with passed arguments
res1.erase(pos1,n1);       // erase the ocntents to be replaced
res1.insert(pos1,res2);         //insert new data
sz=res1.sz;
delete [] p;
p= new char[sz];
for(unsigned i=0;i<sz;i++) p[i]=res1.p[i];             // update current object
return *this; 
}

/***********************************************************
FUNCTION : String& String::replace(const size_t& pos, const size_t& n1, const char* cs, const size_t& n2 )

   ARGUMENTS:  pos n1,cs n2

   RETURNS:   String object

*************************************************************/

String& String::replace ( const size_t& pos, const size_t& n1, const char* cs, const size_t& n2 )
{
String res1(p);                  // copy the current string is String object
String res2(cs,n2);            // have a new String object with cs and n2
res1.erase(pos,n1);             // first erase the ocntents tht need to be replaced
res1.insert(pos,res2);       // next insrt the new data
sz=res1.sz;
delete [] p;
p= new char[sz];
for(unsigned i=0;i<sz;i++) p[i]=res1.p[i]; // copy the contents to the current object
return *this;
}

/***********************************************************
FUNCTION : String& String::replace(const size_t& pos, const size_t& n, const char* cs  )

   ARGUMENTS:  pos, n, cs

   RETURNS:   String object

*************************************************************/

String& String::replace( const size_t& pos, const size_t& n, const char* cs )
{
String res1(p);              //copy the current string to String object
String res2(cs);            // have another string object with string passed
res1.replace(pos,n,res2);      // call the replace function 
sz=res1.sz;
delete [] p;
p= new char[sz];
for(unsigned i=0;i<sz;i++) p[i]=res1.p[i];   // update the current string
return *this;
}

/***********************************************************
FUNCTION : String& String::replace(const size_t& pos, const size_t& n1, const size_t& n2, const char & c )

   ARGUMENTS:  pos, n1, n2, c

   RETURNS:   String object

*************************************************************/

String& String::replace ( const size_t& pos, const size_t& n1, const size_t& n2, const char& c )
{
String res1(p);                // have the current string in new String object
String res2(n2,c);          // create another string object with n2 charcters
res1.replace(pos,n1,res2);      // replace first string content with second
sz=res1.sz;
delete [] p;
p= new char[sz];
for(unsigned i=0;i<sz;i++) p[i]=res1.p[i];   // copy it to the current string
return *this;
}

/***********************************************************
FUNCTION : String& String::copy(char *cs,const size_t& n, const size_t& pos )

   ARGUMENTS:  cs, n, pos

   RETURNS:   number of characters copied

*************************************************************/

size_t String::copy(char* cs,const size_t& n,const size_t& pos)const
{
/*
 size_t i,j;
for(i=pos,j=0;j<n;j++,i++) cs[j]=p[i];
return j;
*/
unsigned i,j;
for(i=pos,j=0;i<pos+n;i++,j++)
{
cs[j]=p[i];                       // copy the current strig into cs
}
return n;          // return n

}

/***********************************************************
FUNCTION : String& String::swap(String & s )

   ARGUMENTS:  s

   RETURNS:   nothing

*************************************************************/

void String::swap(String & s)
{

String res1;
res1.p=new char[sz+1];              // copy and store the contents of first word
res1.sz=sz;
strcpy(res1.p,p);
delete []p;
p=NULL;
sz=0;
sz=s.sz;
p=new char[s.sz+1];
strcpy(p,s.p);                 // copy them with the second word
//delete []s.p;
//s.p=NULL;
//s.sz=s1.sz;
strcpy(s.p,res1.p);

}

