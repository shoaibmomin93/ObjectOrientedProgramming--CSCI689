
/****************************************************************
   PROGRAM:   program 5
   AUTHOR:    SHOAIB MOMIN
   LOGON ID:  Z1777526
   DUE DATE:  Friday, October 2, 2015

   FUNCTION:  Evaluate if the given date is valid or not
              

   INPUT:     Different date values are given as input
              

   OUTPUT:    The date is displayed and if its not valid, it is mentioned      
              
              
              
****************************************************************/


#ifndef _date_h
#define _date_h
#include"/home/cs689/common/689.h"
extern const int DAY;         // constant for default day
extern const int YEAR;       // constant for default year
extern const string MONTH;   // constant for default month
class Date                // class declaration starts here
{
private:                 // private section has variables declared
//#include"MyDate.cc"
string month;
int day;
int year;
friend istream& operator>>(istream& , Date& );            // >> operator is overloaded as friend function
friend  bool printDate(const Date&);                 // it is used to print valid date
friend ostream& operator<<(ostream&, const  Date&);       // << operator is overloaded
int daysInMonth ()const;                              //get the value of days in month
bool isLeapYear ()const;                      // check if its a leap year
bool isValidMonth()const;             // check if its a valid month
/*int daysInMonth const ()
{
if(month=="January")
return 31;
if(month=="February")
{
if(isLeapYear) return 29;
return 28;
}
if(month=="March")
return 31;
if(month=="April")
return 30;
if(month=="May")
return 31;
if(month=="June")
return 30;
if(month=="July")
return 31;
if(month=="August")
return 31;
if(month=="September")
return 30;
if(month=="October")
return 31;
if(month=="November")
return 30;
if(month=="December")
return 31;
}
bool isLeapYear const()
{

 if(year%4 == 0)
      {
          if( year%100 == 0) 
          {
              if ( year%400 == 0)
                 return true;
              else
                 return false ;
          }
          else
             return true;
      }
      else
        return false;
}


bool isValidMonth const()
{
int n=daysInMonth();
if(
 (month=="January" && day<=n) ||
(month=="February" && day<=n)||
(month=="March" && day<=n)||(month=="April" && day<=n)||
(month!="May" && day<=n)||
(month=="June" && day<=n)|| (month=="July" && day<=n)||(month=="August" && day<=n)||(month=="September" && day<=n)||(month=="October" && day<=n)||(month=="November" && day<=n)||(month=="December" && day<=n)

)
return true;
} */
public:                      // this is the public section
Date();                          // default constructor
Date(const string&,const int&,const int&);   // parameterized constructor
void setMonth(const string&);               // used to modify the value of month
void setDay(const int&);                // used to modify the value of day
void setYear(const int&);               // used to modify the value of year
string getMonth()const;                // used to get the value of month
int getYear()const;               // used to get the value of year

int getDay()const;                   // used ti get the value of day
void Month();                      // change the case of month
bool isValidDate()const;                 // check if a given date is valid
std::string toString() const ;             // comvert to string
//private:
//#include"MyDate.cc"
};
std::istream& operator>>(std::istream&,Date&); // overload >> operator
std::ostream& operator<<(std::ostream&,const Date&); // overload << operator
bool printDate(const Date&);               // used to print date
//private:
//#include"MyDate.cc"
#endif 
