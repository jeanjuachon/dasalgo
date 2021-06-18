/****************************************************
REFERENCE

Author:Chaitanya Singh
Link: https://beginnersbook.com/2015/02/insertion-sort-program-in-c/
****************************************************/


/*
	You may declare additional functions here
*/


/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


/*
	Sorts the array A using insertion sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/

#include <stdio.h>
#include <time.h>

void insertionSort(int A[], int n, double *dCounter)
    {
           for (int i = 1;i < n;i++)
    {
        int x = A[i];
        int j = i;
        while (j > 0 && A[j-1] > A[j])
        {
            int temporaryVariable=A[j];
            A[j] = A[j-1];
            A[j-1]=temporaryVariable;
            j--;
            *dCounter +=1;
        }
        A[j] = x;
    }
}


