
/**********************************************************

   PROGRAM:   A GROCERRY STORE SIMULATION MODEL
   AUTHOR:    SHOAIB MOMIN
   LOGON ID:  Z1777526
   DUE DATE:   Friday, November 6, 2015

   FUNCTION:  To simulate an events of a grocerry store


   INPUT:     None. It takes random values and rns for a constant simulation time


   OUTPUT:    Statistics of the store
****************************************************************/



#include"/home/cs689/common/689.h"


typedef struct { long id, arrTime, pickTime, waitTime; } cust;       // STRUCTURES are declared
typedef struct { long nextArr, nextCheckout, nextDept; } event;
typedef struct { long numDept, totShop, totWait, totServ; } stat;


typedef list < cust > L;         // data types for list, queue and iteratr are declared
typedef L :: iterator LI;
typedef queue< cust > Q;


void init_vars ( event& , stat&  );        //various function prototypes
void Arrival ( event& , const int& , L& );
void Checkout ( event& , L& , Q&  );
void Departure ( event& , Q& , stat&  );
int arr_time ( const int&  );
int pick_time ( const int&  );
int dept_time ( const int&  );
int update_clock ( const event& , const bool& , const bool&  );
void update_fin_stat ( stat& , const cust& , const int& clockt  );
void print_fin_stat ( const stat&  );
int rnd ( const int& , const int&  );
extern const int MIN_INT_ARR;
extern const int MAX_INT_ARR;
extern const int MIN_PICK;
extern const int MAX_PICK;
extern const int MIN_SERV;
extern const int MAX_SERV;



