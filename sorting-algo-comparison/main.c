/****************************************************
Group: Group 1	
Section: 
Members: Juachon, Jean Philip L.
****************************************************/

#include <stdio.h>
#include <time.h>
#include "bubbleSort.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "mergeSort.h"
#include "sort5.h"
#include "sort6.h"
#include "generateData.h"
#include "timer.h"
#define M 10
#include <stdbool.h>
#include <string.h>

void printer(int A[], int n){
  for (int i = 0; i < n; ++i)
  {
    printf("%d ", A[i]);
  }
    printf("\n");
}

int main(){
	int n[] = {5}; //Setup Array size
//1024,2048,4096,8192,16384
	for(int i = 0; i < 1; i++){
		int A[n[i]]; //Initialize an array with size based on the index of n
		generateData(A, n[i]);
		printf("-----N: %d-----\n", n[i]); //show the array size
		//printer(A, n[i]); //show the array to be sorted
		struct timespec t1,t2; //initialize timer

		double totalElapsedBubble = 0;
		double totalElapsedMerge = 0;
		double totalElapsedInsertion = 0;
		double totalElapsedSelection = 0;
		double totalElapsedSort5 = 0;
		double totalElapsedSort6 = 0;
		
		double elapsedBubble = 0;
		double elapsedInsertion = 0;
		double elapsedSelection = 0;
		double elapsedMerge = 0;
		double elapsedSort5 = 0;
		double elapsedSort6 = 0;

		double dCounterBubble = 0;
		double dCounterInsertion = 0;
		double dCounterSelection = 0;
		double dCounterMerge = 0;
		double dCounterSort5 = 0;
		double dCounterSort6 = 0;

		double totalCounterBubble = 0;
		double totalCounterInsertion = 0;
		double totalCounterSelection = 0;
		double totalCounterMerge = 0;
		double totalCounterSort5 = 0;
		double totalCounterSort6 = 0;

		for(int j = 0; j < M; j++){
			//BUBBLE SORT
			int A_copy[n[i]];
			memcpy(A_copy, A, sizeof(A));
			//printer(A_copy, n[i]);
			t1 = getTime();
			bubbleSort(A_copy, n[i], &dCounterBubble);
			t2 = getTime();
			//printer(A_copy, n[i]);
			elapsedBubble = getElapsed(t1, t2);
			totalElapsedBubble += elapsedBubble;
			dCounterBubble = dCounterBubble;
			totalCounterBubble += dCounterBubble;
			printf("Bubble iter: %d, Elapsed: %f\t\t Sum elapsed: %f\n", j, elapsedBubble, totalElapsedBubble);
			//printf("Bubble iter: %d, Critical Count: %f\t\t Total Critical: %f\n", j+1, dCounterBubble, totalCounterBubble);
			
			//INSERTION SORT
			memcpy(A_copy, A, sizeof(A));
			//printer(A_copy, n[i]);
			t1 = getTime();
			insertionSort(A_copy, n[i], &dCounterInsertion);
			//printer(A_copy, n[i]);
			t2 = getTime();
			elapsedInsertion = getElapsed(t1, t2);
			totalElapsedInsertion += elapsedInsertion;
			dCounterInsertion = dCounterInsertion;
			totalCounterInsertion += dCounterInsertion;
			//printf("Insertion iter: %d, Elapsed: %f\t\t Sum elapsed: %f\n", j, elapsedInsertion, totalElapsedInsertion);
			//printf("Insertion iter: %d, Critical Count: %f\t\t Total Critical: %f\n", j+1, dCounterInsertion, totalCounterInsertion);
			
			//SELECTION SORT
			memcpy(A_copy, A, sizeof(A));
			t1 = getTime();
			selectionSort(A_copy, n[i], &dCounterSelection);
			t2 = getTime();
			elapsedSelection = getElapsed(t1, t2);
			totalElapsedSelection += elapsedSelection;
			dCounterSelection = dCounterSelection;
			totalCounterSelection += dCounterSelection;
			//printf("Insertion iter: %d, Elapsed: %f\t\t Sum elapsed: %f\n", j, elapsedSelection, totalElapsedSelection);

			//MERGE SORT
			memcpy(A_copy, A, sizeof(A));
			t1 = getTime();
			mergeSort(A_copy, n[i], &dCounterMerge);
			t2 = getTime();
			elapsedMerge = getElapsed(t1, t2);
			totalElapsedMerge += elapsedMerge;
			dCounterMerge = dCounterMerge;
			totalCounterMerge += dCounterMerge;
			//printf("Merge iter: %d, Elapsed: %f\t\t Sum elapsed: %f\n", j, elapsedMerge, totalElapsedMerge);	

			//SORT5: GNOME SORT
			memcpy(A_copy, A, sizeof(A));
			t1 = getTime();
			sort5(A_copy, n[i], &dCounterSort5);
			t2 = getTime();
			elapsedSort5 = getElapsed(t1, t2);
			totalElapsedSort5 += elapsedSort5;	
			dCounterSort5= dCounterSort5;
			totalCounterSort5 += dCounterSort5;	
			//printf("Sort5 iter: %d, Elapsed: %f\t\t Sum elapsed: %f\n", j, elapsedSort5, totalElapsedSort5);	
			
			//SORT6: COMB SORT
			memcpy(A_copy, A, sizeof(A));
			//printer(A_copy, n[i]);
			t1 = getTime();
			sort6(A_copy, n[i], &dCounterSort6);
			//printer(A_copy, n[i]);
			t2 = getTime();
			elapsedSort6 = getElapsed(t1, t2);
			totalElapsedSort6 += elapsedSort6;
			dCounterSort6 = dCounterSort6;
			totalCounterSort6 += dCounterSort6;	
			//printf("Sort6 iter: %d, Elapsed: %f\t\t Sum elapsed: %f\n", j, elapsedSort6, totalElapsedSort6);	
			//printf("Sort 6 iter: %d, Critical Count: %f\t\t Total Critical: %f\n", j+1, dCounterSort6, totalCounterSort6);
		}
		printf("Bubble Sort\n");
		printf("Average MET Bubble: %f milliseconds\n", (totalElapsedBubble/M) * 1000);
		printf("Average Critical Count: %f\n\n", dCounterBubble/M);

		printf("Insertion Sort\n");
		printf("Average MET Insertion: %f milliseconds\n", (totalElapsedInsertion/M) * 1000);
		printf("Average Critical Count: %f\n\n", dCounterInsertion/M);
		
		printf("Selection Sort\n");
		printf("Average MET Selection: %f milliseconds\n", (totalElapsedSelection/M) * 1000);
		printf("Average Critical Count: %f\n\n", dCounterSelection/M);
		
		printf("Merge Sort\n");
		printf("Average MET Merge: %f milliseconds\n", (totalElapsedMerge/M) * 1000);
		printf("Average Critical Count: %f\n\n", dCounterMerge/M);
		
		printf("Sort 5\n");
		printf("Average MET Sort5: %f milliseconds\n", (totalElapsedSort5/M) * 1000);
		printf("Average Critical Count: %f\n\n", dCounterSort5/M);

		printf("Sort 6\n");
		printf("Average MET Sort6: %f milliseconds\n", (totalElapsedSort6/M) * 1000);
		printf("Average Critical Count: %f\n\n", dCounterSort6/M);
	}
return 0;
}