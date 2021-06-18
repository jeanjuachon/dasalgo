/****************************************************
REFERENCE

Author:N/A
Link:N/A
****************************************************/


/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


#include <stdlib.h> 
#include <time.h> 


void generateData (int A[], int n) {   
    //	your code here
    int i;
    for(i = 0; i < n+1; i++){
      A[i] = rand();
    }
    //return;
}



