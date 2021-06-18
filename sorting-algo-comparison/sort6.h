/****************************************************
REFERENCE

Author: Rahul Agrawal
Link: https://www.geeksforgeeks.org/comb-sort/?fbclid=IwAR3k-xFEY6mcVdDMeutzpvuJAL-hC72Zj6WvGU3BzkYpLi7FgOFASzqEJb8
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

/**void swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}**/
#include <stdbool.h>
#include <stdio.h>

int getNextGap(int gap) 
{ 
    // Shrink gap by Shrink factor 
    gap = (gap*10)/13; 
  
    if (gap < 1) 
        return 1; 
    return gap; 
} 

void sort6(int a[], int n, double *dCounter) 
{ 
    // Initialize gap 
    int gap = n; 
  
    // Initialize swapped as true to make sure that 
    // loop runs 
    bool swapped = true; 
  
    // Keep running while gap is more than 1 and last 
    // iteration caused a swap 
    while (gap != 1 || swapped == true) 
    {
        // Find next gap 
        gap = getNextGap(gap); 
  
        // Initialize swapped as false so that we can 
        // check if swap happened or not 
        swapped = false; 
  
        // Compare all elements with current gap 
        for (int i=0; i<n-gap; i++) 
        { 
            if (a[i] > a[i+gap]) 
            { 
                swap(&a[i], &a[i+gap]); 
                *dCounter += 1;
                swapped = true; 
            } 

        } 
         
    } 
} 
