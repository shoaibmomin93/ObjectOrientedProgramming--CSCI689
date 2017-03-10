
/****************************************************************
   PROGRAM:   PROGRAM 5
   AUTHOR:    SHOAIB MOMIN
   LOGON ID:  Z1777526
   DUE DATE:  Friday, October 2, 2015

   FUNCTION:  Checks if a date is valid and prints the appropriate result.
              

   INPUT:     Date values can be given from a file, stdin or in constructors.
              

   OUTPUT:    Output can viewed in a file or on stdout
                         
             
****************************************************************/





#include"Date.h"                  // the header file has the class declarartion and friend function declarartionss
extern const int DAY=1;               // the constants for the default date are set as 1st Jan 1900
extern const int YEAR=1900;
extern const string MONTH="January";
string integerToString(int);        // this function converts an integer value to string.

/****************************************************************

   FUNCTION:   int daysInMonth() const;

   ARGUMENTS:  Doesnt take in any arguments

   RETURNS:   This function returns the number of days in the specified month

   NOTES:     Leap year has 29 days and so it is checked specifically.
****************************************************************/

int Date:: daysInMonth() const
{
if(month=="January")               // if month is january, 31 days is returned
return 31;
 if(month=="February")         // if february , leap year is to be checked
{
if(isLeapYear()) return 29;      // if it is a leap year, return 29 days
else
return 28;                     // if not, 28 days is returned

}
 if(month=="March")         // for march, 31 days are returned
return 31;
 if(month=="April")            // for april, 30 days are rerurned
return 30;
 if(month=="May")            // if its may, return 31 days
return 31;
 if(month=="June")           // if its june, return 30 days
return 30;
 if(month=="July")           // for july return 31 days
return 31;
 if(month=="August")        // august has 31 days
return 31;
 if(month=="September")       // if its september, return 30 days
return 30;
 if(month=="October")         // if its october, return 31 days
return 31;
 if(month=="November")      // for november, return 30 days
return 30;
 if(month=="December")      //  for december return 31 days
return 31;
else return -1;
}

/****************************************************************

   FUNCTION:   bool isLeapyear() const;

   ARGUMENTS:  This function takes no arguments

   RETURNS:    It return true if the year is leap year.

  
****************************************************************/



bool Date:: isLeapYear() const                   // function is declared constant as no values are being changed
{

 if(year%4 == 0)                                 // if year is divisible by 4,100,400, then it is a leap year
      {   if( year%100 == 0) 
     {
        if ( year%400 == 0)
         return true;                      // in which case, true is returned
           else
         return false ;          // if any of the above condition fails, return false
         }
        else
         return true;
    }
      else
        return false;
}
/****************************************************************

   FUNCTION:   bool isValidMonth() const;

   ARGUMENTS:  No arguments are passed

   RETURNS:    It returns a bool value

  
****************************************************************/


bool Date:: isValidMonth() const           // since none of the values are changed inside the function, its declared as constant
{
int n;                         // n stores the number of days in each month
n=daysInMonth();              // the number of days in each month is brought
if(
 (month=="January" && day<=n) ||
(month=="February" && day<=n)||
(month=="March" && day<=n)||(month=="April" && day<=n)||
(month=="May" && day<=n)||
(month=="June" && day<=n)|| (month=="July" && day<=n)||(month=="August" && day<=n)||(month=="September" && day<=n)||(month=="October" && day<=n)||(month=="November" && day<=n)||(month=="December" && day<=n)

)                               // it is checked if the month is valid or not and also if the days returned are in that month
return true;
else return false;
}





/****************************************************************

   FUNCTION:   Date() is a default constructor

   ARGUMENTS:  No arguments are passed

   RETURNS:    It returns nothing


****************************************************************/




Date :: Date()
{
day=DAY;              // the constant value DAY is assigned
month=MONTH;          // constant value MONTH  is  assigned
year=YEAR;           // constant value YEAR is assigned

}

/****************************************************************

   FUNCTION:  Date(const string& m,const int& d, const int& y); is parameterized constructor

   ARGUMENTS:  It takes in month, day and year 

   RETURNS:    It doesnt return anything


****************************************************************/



Date::Date(const string& m,const int& d, const int& y)
{
//m.c_str();
//strcpy(month,m);
month=m;                      // store m in month
day=d;                         // store d in day
year=y;                         // store y in year
Month();          // Month() is called to convert first letter in upper case

}


/*bool printDate(const Date& d)
{
cout<<"in print data";
if(d.isValidDate())
{
cout<<"It is a valid date"<<endl;
return false;
}
else{
cerr<<"not a valid date"<<endl;
return true;
}
}*/


/****************************************************************

   FUNCTION:  void setMonth(const string& m);

   ARGUMENTS:  It takes in month as parameter

   RETURNS:    It doesnt return anything


****************************************************************/

void Date::setMonth(const string& m){
//m.c_str();
//strcpy(month,m);
month=m;                         // set month value to new value
Month();                            // convert the value of first leter to upper case letter
}


/****************************************************************

   FUNCTION:  void setDay(const int &d);

   ARGUMENTS:  It takes in day as parameter

   RETURNS:    It doesnt return anything


****************************************************************/

void Date::setDay(const int& d)
{
day=d;                 // set date to new date
}

/****************************************************************

   FUNCTION:  void setYear(const int y);

   ARGUMENTS:  It takes in year  as parameter

   RETURNS:    It doesnt return anything


****************************************************************/


void Date::setYear(const int& y)
{
year=y;                 // set year to new year
}

/****************************************************************

   FUNCTION:  string getMonth()const ;

   ARGUMENTS:  It takes no arguments

   RETURNS:    It returns the month value


****************************************************************/


string Date::getMonth() const{
return month;              // month value is returned
}

/****************************************************************

   FUNCTION:  int getDay()const ;

   ARGUMENTS:  It takes no arguments

   RETURNS:    It returns the day value


****************************************************************/


int Date::getDay() const {
return day;           // day is returned
}

/****************************************************************

   FUNCTION:  int getYear()const ;

   ARGUMENTS:  It takes no arguments

   RETURNS:    It returns the year value


****************************************************************/



int Date:: getYear() const{
return year;             // year is returned
}

/****************************************************************

   FUNCTION:  void Month() ;

   ARGUMENTS:  It takes no arguments

   RETURNS:    It doesnt return anything


****************************************************************/

void Date::Month()
{
//string month1=month;//cout<<"in month()";
month.c_str();                // convert it to c style string
//cout<<month[0]<<endl;
month[0]=toupper(month[0]);          // convert first letter to upper case letters
//cout<<month[0]<<endl;
for(unsigned i=1;i<month.length();i++)    
{ 
month[i]=tolower(month[i]);          // for the rest of the characters, make it lower case
}
//cout<<month;
}

/****************************************************************

   FUNCTION:  bool isValidDate()const ;

   ARGUMENTS:  It takes no arguments

   RETURNS:    It returs true if the entire date given is valid


****************************************************************/


bool Date::isValidDate() const{
if(year<0) return false;            // year should be greater than 0
return isValidMonth();         // check if the month is valid
}


/*istream & operator>>(istream & is, Date &d)
{char  ch;
is>>d.month;
is>>d.day;
//d.year;

//ch=d.year; 
//cout<<"in while";
is>>ch;
if (isdigit(ch))
{
// cout<<"is number";
is.unget(); 
}
else
{
//cout<<"in comma";
//is.unget();
is>>d.year;
}



//is.unget();
//is>>d.year;}
 
//is.unget();
*/
/*if(isdigit(a))
is>>d.year;
else is.unget();*/
//d.Month();
//return is;
//}

/****************************************************************

   FUNCTION:  istream & operator>>(istream &is, Date &d);

   ARGUMENTS:  It takes stream and date object

   RETURNS:    returns value to stream


****************************************************************/
istream & operator>>(istream &is, Date &d)
{
char ch;
is>>d.month;      //  store first argument in month
is>>d.day;          // second in day
is>>ch;              // for the third, check if its a digit or not
if(isdigit(ch))
is.unget();           // if yes, unget
is>>d.year;           // lastly, store year
d.Month();
return is;           // return stream
}

/****************************************************************

   FUNCTION:  ostream& operator<<(ostream & os,const Date & d);

   ARGUMENTS:  It takes stream and date object

   RETURNS:    returns value to stream


****************************************************************/


ostream& operator<<(ostream & os,const Date & d) {

return os<<d.month<<" "<<d.day<<", "<<d.year;            // returns month, day and year to output stream
//return os<<endl<<d.toString();
}

/****************************************************************

   FUNCTION: string toString()const;

   ARGUMENTS:  It takes stream and date object

   RETURNS:    returns string 


****************************************************************/



string Date::toString()const {

//string month1;
//for(int i=0;i<3;i++)
//{month1[i]=month[i];}
return integerToString(day)+ "-" + month.substr(0,3) + "-" + integerToString(year);   // the date is returned in the string format.
}

/*int main()
{
//cout<<"main prog";
Date d,d2;
cout<<d2;
//cout<<"enter date";
while(cin>>d)
{
d.Month();
cout<<d;
if(!printDate(d))
//cout<<"Its a valid date";
//cout<<d;
cout<<endl<<d.toString();
//cout<<d;
}
Date d1("August",8,1993);
//cout<<d1;
return 0;
}*/
/*int main()
{
 Date defaultDate;                       // default date
    printDate ( defaultDate );

    Date moonLanding ( "jul", 20, 1969 );   // date to moon landing
    printDate ( moonLanding );
    moonLanding.setMonth ( "july" );        // correct the month
    printDate ( moonLanding );

    Date leapDay ( "FEBRUARY", 29, 2001 );  // leap day
    printDate ( leapDay );
    leapDay.setDay ( 28 );                  // correct the leap day
    printDate ( leapDay );

    // Get and print the individual components of the default date
    // by using the getters.

    Date d;
    cout << d.getMonth ( ) << " " << d.getDay ( )
         << ", " << d.getYear ( ) << endl;

    // Set and print the individual components of the independence day
    // by using the setters.

    d.setMonth ( "July"); d.setDay ( 4 ); d.setYear ( 1776 );
    printDate ( d );

    // Get several dates from the stdin until EOF. Print each date in
    // a proper format, and if the date is a valid, also print the
    // date in the form dd-mmm-yyy.

    while ( cin >> d ) {
        d.Month ( ); bool flag = printDate ( d );
        if ( !flag ) cout << d.toString ( ) << endl;
    }
return 0;
*/
//}

/****************************************************************

   FUNCTION:  string integerToString(int n);

   ARGUMENTS:  It takes integer value

   RETURNS:    returns string type of it.


****************************************************************/


string integerToString(int n) {
 ostringstream stream;           // string stream is used
 stream << n;
 return stream.str();        // str function is used to convert it to string
}
