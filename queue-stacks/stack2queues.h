/*******************************************************************
YOU ARE NOT ALLOWED TO MODIFY THE STRUCT AND THE FUNCTION PROTOTYPES
*******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

typedef struct {
	int n;
	queue *queue1;
	queue *queue2;
} stack2queues;

stack2queues* createStack(int n) {
	// Your code here

	stack2queues* s

	if((s = (stack2queues*)malloc(sizeof(stack2queues))) == NULL)
        {
		printf("ERROR! Memory full\n");
        }
	else
        {

        s->n = n;
		s->queue1=create(n+1);
		s->queue2=create(n+1);

        }

	return s;


}

int stackEmpty(stack2queues *s) {
	// Your code here
	return((queueEmpty(s->queue1)==1) && (queueEmpty(s->queue2)==1));
}

int stackFull(stack2queues *s) {
	// Your code here
	return ((queuefull(s->queue1)==1) || (queuefull(s->queue2)==1));
}



void push(stack2queues **s, int data) {
	// Your code here
	sNode p*Temp;

    if((pTemp = (sNode*)malloc(sizeof(sNode))) == NULL) {
    printf("ERROR! Memory full\n");
	} else {
	    if(!stackFull(*s))
            {
            pTemp->data = data;
			pTemp->pLink =NULL;

            queue** qTemp = (*s)->queue1; //Enqueue queue is the main stack for pushing

            if ((*s)->queue1->pTail==NULL); // If Enqueue Queue is empty

            enqueue(qTemp, int data); //Push values inside queue1

            }
        else
            {
                printf("Stack overflow!\n");
            }
	}
}

int pop(stack2queues **s) {
	// Your code here
	sNode *pTemp; // New node
	int val = 0; //Data to be placed to node
	int temp = 0;

	if(!stackEmpty(*s)){
        sNode *pTemp;
        int value = 0;
        int temp =0;


        for(int i=0; i<(*s)->queue1->nCount-1; i++) //Loop Dequeue items in q1 except last item
        {
            temp = dequeue((*s)->queue1); //dequeue elements in queue1
            enqueue((s*)->queue2, temp);//enqueue elements dequeued from queue1 to queue2
        };

        value = dequeue((*s)->queue1); //Last value in queue 1 to be popped following LIFO sequence

        for(int i=0; i<(*s)->queue2->nCount\; i++) //Loop Dequeue items in q2
        {
            temp = dequeue((*s)->queue2); //dequeue elements in queue2
            enqueue((s*)->queue1, temp);//enqueue elements dequeued from queue2 to queue1
        };
    }
    else
    {
        printf("Stack Underflow!");
    }
        return value;
        //dequeue all until last element to queue 2
        //Last in first out sequence for popping
        //pop the queue1
        //queue 2 is becomes temp
        //after popping queue1
        //queue1 becomes queue2
        //queue2 becomes queue1
	}



void displayStack(stack2queues *s) {
	// Your code here
    //LIFO sequence -
    sNode *pTemp = NULL;
	int temp=0;

	if(!stackEmpty(*s))
    {
        for(int i=0; i<(*s)->queue1->nCount; i++) //Loop Dequeue items in q1 except last item
        {
            temp = dequeue((*s)->queue1); //dequeue elements in queue1
            enqueue((s*)->queue2, temp);//enqueue elements dequeued from queue1 to queue2
        };

        display((s*)->queue2);

        for(int i=0; i<(*s)->queue2->nCount\; i++) //Loop Dequeue items in q2
        {
            temp = dequeue((*s)->queue2); //dequeue elements in queue2
            enqueue((s*)->queue1, temp);//enqueue elements dequeued from queue2 to queue1
        };
	}

}

int top(stack2queues *s) {
	// Your code here

	int top = 0;

	int tail((*s)->queue1);

	return top;

}

