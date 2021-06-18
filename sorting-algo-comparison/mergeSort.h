/****************************************************
REFERENCE

Author: N/A
Link: http://www.firmcodes.com/sorting-algorithms-in-c/?fbclid=IwAR2X_ol-0aT1wFsj3jzorbqukX315Uuj38lguai-xN3QJUqS1zfxNmJEAiE
****************************************************/


/* 
	You may declare additional functions here
*/


/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


/*
	Sorts the array A using merge sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/

#include<stdio.h>
#include<stdlib.h>


void merge(int A[], int leftArray[], int rightArray[], int leftLength, int rightLength){
	int leftIndex = 0;
	int rightIndex = 0;
	int arrayIndex = 0;

	while(leftIndex < leftLength && rightIndex < rightLength){
		if(leftArray[leftIndex] <= rightArray[rightIndex]){
			A[arrayIndex] = leftArray[leftIndex];
			leftIndex++;
		}
		else{
			A[arrayIndex] = rightArray[rightIndex];
			rightIndex++;
			//*dCounter+=1;
		}
		arrayIndex++;
	}
	while(leftIndex < leftLength){
		A[arrayIndex] = leftArray[leftIndex];
		leftIndex++;
		arrayIndex++;
	}
	while(rightIndex < rightLength){
		A[arrayIndex] = rightArray[rightIndex];
		rightIndex++;
		arrayIndex++;
	}
	//printf("Counter: %f\n", *dCounter);
}

void mergeSort(int A[], int n, double *dCounter){
	if(n < 2) return;

	int leftLength = n/2;
	int rightLength = n - leftLength;
	int leftArray[leftLength];
	int rightArray[rightLength];

	int i;
	for(i = 0; i < leftLength; i++){
		leftArray[i] = A[i];
	}
	for(i = 0; i < rightLength; i++){
		rightArray[i] = A[i + leftLength];
	}
	mergeSort(leftArray, leftLength, dCounter);
	mergeSort(rightArray, rightLength, dCounter);
	merge(A, leftArray, rightArray, leftLength, rightLength);
	*dCounter += 1;
	//printf("Counter: %f\n", *dCounter);
}



