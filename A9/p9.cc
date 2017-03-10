/****************************************************************
   PROGRAM:   A GROCERRY STORE SIMULATION MODEL
   AUTHOR:    SHOAIB MOMIN
   LOGON ID:  Z1777526
   DUE DATE:   Friday, November 6, 2015

   FUNCTION:  To simulate an events of a grocerry store
             

   INPUT:     None. It takes random values and rns for a constant simulation time
              

   OUTPUT:    Statistics of the store
****************************************************************/



#include"p9.h"

extern const int MIN_INT_ARR=1;            // ASSIGN THE VALUES TO EXTERNAL CONSTANT VARAIABLES
extern const int MAX_INT_ARR=5;
extern const int MIN_PICK=1;
extern const int MAX_PICK=20;
extern const int MIN_SERV=1;
extern const int MAX_SERV=4;
int clockt;
const int SAMPLE_INT=2000;
const long SIM_TIME= 6*30*24*60;
const int SEED=1;

/*
typedef struct { long id, arrTime, pickTime, waitTime; } cust;
typedef struct { long nextArr, nextCheckout, nextDept; } event;
typedef struct { long numDept, totShop, totWait, totServ; } stat;


typedef list < cust > L;
typedef L :: iterator LI;
typedef queue< cust > Q;

*/
/****************************************************************

   FUNCTION:   bool cmp(const cust& c1, const cust & c2)

   ARGUMENTS:  two customers 

   RETURNS:    boolean value stating true if thr 1st customers pick time is lower than the 2nd customer pck time

  
****************************************************************/


 bool cmp ( const cust& c1, const cust& c2 )
	{ return c1.pickTime <c2.pickTime; }


int main()
{

L l;           // create  a lisr
Q q;           // create a queue
clockt=0;
//cust c;
int idd=1;     // assign the initial id as 1
srand(SEED);      // seed value is set to 1
event e;          // create structure variable e
stat s;	          // structure variable s
init_vars(e,s);    // call the initialization function
//int minpick;
bool f1,f2;         // these two boolean variables are used to check if list and queue are empty 
Arrival(e,idd,l);    // call this for rhe first customer
idd++;              // increment id number
 while(clockt<SIM_TIME)    // t<SIM_TIME
{


//Arrival(e,idd,l);


 f1 = !l.empty ( );

f2 = !q.empty ( );




//LI i = min_element ( l.begin ( ), l.end ( ), cmp );
 //minpick=(i->pickTime);

//if(e.nextArr < minpick && e.nextArr < e.nextDept)
if(clockt==e.nextArr)
{
Arrival(e,idd,l);
idd++;
}

//if(minpick<e.nextArr && minpick< e.nextDept)
if(clockt==e.nextCheckout && f1)
Checkout(e,l,q);

//if(e.nextDept<e.nextArr && e.nextDept<minpick)
if(clockt==e.nextDept && f2)
Departure(e,q,s);
// f1 = !l.empty ( );
//f2 = !q.empty ( );

clockt=update_clock(e,f1,f2);
clockt++;

}
cout<<"Statistical Data: ";
print_fin_stat(s);
return 0;
}



void init_vars ( event& e, stat& s )
{ 
cout<<"init"<<endl;
        e.nextArr=0;
        e.nextCheckout= e.nextDept=SIM_TIME + 1;
        s.numDept=0;
        s.totShop=0;
        s.totWait=0;
        s.totServ=0;
}

void Arrival ( event& e, const int& id, L& l )
{
cout<<"arrival"<<endl;
        cust c;
        c.id=id;
        c.pickTime=pick_time(clockt);
	c.arrTime=clockt;
//	c.waitTime= dept_time(clock); 
	l.push_back(c);
        e.nextArr=arr_time(clockt);
//	e.nextCheckout=c.arrTime + c.pickTime;
LI i=min_element(l.begin() , l.end(), cmp);
	
	e.nextCheckout=(*i).pickTime;
//	l.push_back(c);
	
}

void Checkout ( event& e, L& l, Q& q )
{	
	
cout<<"checkout"<<endl;
	//for(LI i=l.begin();i!=l.end();i++)
       // {
       
	LI i = min_element ( l.begin ( ), l.end ( ), cmp );
	// if(q.empty())
	//	{
		cust a = *i;
//		if(((*i).pickTime) == clock )
//		{			
		 if(q.empty())
		{
			(*i).waitTime=0;
		
			q.push(*i);	
		
			l.erase(i);
	
			if(!l.empty()) 	
			{
				LI j = min_element ( l.begin ( ), l.end ( ), cmp );
				e.nextCheckout=(*j).pickTime;
	

			}	
			e.nextDept=dept_time(clockt);    // not sure
		
		}

		else
		{	cust cl = *i;
			i--;
			cust cb = *i;
			i++;
			cl.waitTime=cb.waitTime+e.nextDept-clockt;
	//	(*i).waitTime= *
                	q.push((*i));
               		 l.erase(i);
		
                	if(!l.empty())
                	{
		        	LI j = min_element ( l.begin ( ), l.end ( ), cmp );
                        	e.nextCheckout=(*j).pickTime;


                	}	

                	e.nextDept=dept_time(clockt);
		}		  
	
}

void Departure ( event& e, Q& q, stat& s )
{

cout<<"departure"<<endl;
q.pop();
cust cc=q.front();
if(!q.empty())
{
//Cust cc=q.front();
cc.waitTime=0;
// LI j = min_element ( l.begin ( ), l.end ( ), cmp );
 //e.nextCheckout=(*j).pickTime;
e.nextDept=dept_time(clockt);
}
update_fin_stat(s,cc,clockt);

}	


int arr_time ( const int& clockt )
{  int t1;
	t1= clockt+(rand()%(MAX_INT_ARR - MIN_INT_ARR +1) + MIN_INT_ARR);
	return t1;
}

int pick_time ( const int& clockt )
{  int t2;
	t2= (clockt+ (rand()%(MAX_PICK-MIN_PICK+1) + MIN_PICK));
	return t2;
}

int dept_time ( const int& clockt )
{  int t3;
	t3= (clockt+ (rand()% (MAX_SERV-MIN_SERV +1)+MIN_SERV));
	return t3;
}

int update_clock ( const event& e, const bool& f1, const bool& f2 )
{
if(f1 && f2)
{
	if(e.nextArr < e.nextCheckout && e.nextArr < e.nextDept) return e.nextArr;
 if(e.nextCheckout<e.nextArr && e.nextCheckout<e.nextDept ) return e.nextCheckout;

if(e.nextDept<e.nextArr && e.nextDept<e.nextCheckout ) 
return e.nextDept;
}
return clockt;
  
}


void update_fin_stat ( stat& s, const cust& c, const int& clockt )
{

int shop=0;
int wait=0;
int serv=0;
shop=c.pickTime-c.arrTime;
wait=c.waitTime;
serv=dept_time(clockt)-c.waitTime;
s.numDept++;
s.totShop+=shop;
s.totWait+=wait;
if(s.numDept % SAMPLE_INT ==0)
{
cout<<"Departing customer number" << s.numDept<<" ";
cout<<"id "<<c.id<<" ";
cout<<"shop "<< shop<<" ";
cout<<"wait "<< wait<<" ";
cout<<"serv "<<serv << " ";
cout<<endl;
}

}

void print_fin_stat ( const stat& s )
{
cout<<"Total number of customers visited "<<s.numDept<<endl;
cout<<"Total Simultion time "<<SIM_TIME<<endl;

double avg_shop = s.totShop / s.numDept;
double avg_wait = s.totWait / s.numDept;
double avg_serv = s.totServ / s.numDept;

cout << "Average Shop Time" << avg_shop << endl;
cout << "Average Wait Time" << avg_wait << endl; 
cout << "Average Serv Time" << avg_serv << endl;

}	
