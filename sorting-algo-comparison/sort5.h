/****************************************************
REFERENCE

Author: Dr. Hamid Sarbazi-Azad, Dick Grune
Link: https://www.w3resource.com/c-programming-exercises/searching-and-sorting/c-search-and-sorting-exercise-10.php
****************************************************/


/*
	You may declare additional functions here
*/


/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


/*
	Sorts the array A using <fill this> sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/


#include <stdio.h>
#include <stdlib.h>

void sort5(int A[], int n, double *dCounter)

    {

        int i, tmp;
        for(i=1; i<n; )
        {
                if(A[i-1] <= A[i])
                ++i;
                else
            {
                tmp = A[i];
                A[i] = A[i-1];
                A[i-1] = tmp;
                --i;
                if(i == 0)
                i = 1;
            }
        *dCounter+=1;
        }

    }














