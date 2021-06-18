/****************************************************
REFERENCE

Author: Chaitanya Singh
Link: https://beginnersbook.com/2015/02/selection-sort-program-in-c/
****************************************************/


/*
	You may declare additional functions here
*/


/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


/*
	Sorts the array A using selection sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/
void selectionSort(int A[], int n, double *dCounter) {
	//	your code here

	/* Here i & j for loop counters, temp for swapping,
    * count for total number of elements, number[] to
    * store the input numbers in array. You can increase
    * or decrease the size of number array as per requirement
    */
   int i, j, temp;

   // Logic of selection sort algorithm
   for(i=0;i<n;i++)
    {
      
      for(j=i+1;j<n;j++)
      {
         if(A[i]>A[j])
         {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
         }
      }
      *dCounter += 1;
    }
  
}
