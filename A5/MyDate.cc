#include"/home/cs689/common/689.h"

int daysInMonth() const
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

bool isLeapYear() const
{

 if(year%4 == 0)
      {
          if( year%100 == 0) /* Checking for a century year */
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

bool isValidMonth() const
{
int n;
n=daysInMonth();
if(
 (month=="January" && day<=n) ||
(month=="February" && day<=n)||
(month=="March" && day<=n)||(month=="April" && day<=n)||
(month=="May" && day<=n)||
(month=="June" && day<=n)|| (month=="July" && day<=n)||(month=="August" && day<=n)||(month=="September" && day<=n)||(month=="October" && day<=n)||(month=="November" && day<=n)||(month=="December" && day<=n)

)
return true;
}

