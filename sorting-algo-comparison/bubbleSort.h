/****************************************************
REFERENCE

Author: Rath Bhupendra
Link: https://www.geeksforgeeks.org/bubble-sort/?fbclid=IwAR1TQfsVteq6f4x6aRVjBxqmGApk7MhcWKT2Y-I94n0J60TFviLYJMzgyhw
****************************************************/


/* 
	You may declare additional functions here
*/


/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


/*
	Sorts the array A using bubble sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
	, double *dCounter
*/
#include <stdio.h> 

void swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

void bubbleSort(int A[], int n, double *dCounter) {
	//	your code here
  int i,j;
  for (i = 0; i < n-1; i++ ){
    //*dCounter+=1;
    for(j = 0; j < n-i-1; j++){
      //*dCounter+=1;
      if(A[j] > A[j+1]){
        //*dCounter+=1;
        //critical section
        swap(&A[j], &A[j+1]);
        *dCounter+= 1;
      }

    }
  }
}
