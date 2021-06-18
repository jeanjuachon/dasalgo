/*******************************************************************
YOU ARE NOT ALLOWED TO MODIFY THE STRUCT AND THE FUNCTION PROTOTYPES
*******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

typedef struct {
	int n;
	stack *stack1;
	stack *stack2;
} queue2stacks;

queue2stacks* createQueue(int n) //Queue2stack pointer declaration
    {
        // Your code here
        //Create 2 stacks with pointers to head and tail each
        queue2stacks* q; //Queue2stack Pointer q declaration

        if((q=(queue2stacks*)malloc(sizeof(queue2stacks)))==NULL)  //initialize pointer q
        {
            printf("ERROR! Memory full\n");
        }
        else
        {
            q->n=n;
            q->stack1=create(n-1); //Create stack1 function Pointer top to enqueue PTAIL
            q->stack2=create(n-1); //Create stack2 function Pointer top to dequeue PHEAD
            //both stack1 and stack2 pTop = NULL
        }
        return q;
    }


int queueEmpty(queue2stacks *q)
    {
	// Your code here
	/*Queue code */
    //return q->pHead == NULL && q->pTail == NULL;
        return((stackEmpty(q->stack1)==1) && (stackEmpty(q->stack2)==1));
    }

int queueFull(queue2stacks *q)
    {
	// Your code here
	//number of elements inside 1 stack is equal to n
	//Queue Code
	//return q->n == q->nCount + 1;

	//check if queue / tail stack 1 is full or dequeue / head stack 2 is full
        return ((stackfull(q->stack1)==1) || (stackfull(q->stack2)==1));
    }

void enqueue(queue2stacks **q, int data)
    {
        sNode *pTemp; //New node


        if((pTemp = (sNode*)malloc(sizeof(sNode))) == NULL) {
		printf("ERROR! Memory full\n");
        } else {

            if(!queueFull(*q)) { //if tail stack1 or queue is not full

                    //queue code for initializing new node and passing arguments
                    pTemp->data = data;
                    pTemp->pLink = NULL;

                    //(*q)->stack1->nCount = (*q)->stack->nCount + 1;

                    //Add data to new node
                    //N size increments
                    //Tail pointer or pTop moves to next node
                    //Apply push data to stack

                    stack** sTemp = (*q)->stack1;

                    if ((*q)->stack1->pTop==NULL) //If queue is empty,  then new node is front and rear both

                            //*q->front = q->rear = temp; //Udemy
                            //(q*)->pTail = pTemp; //head and tail pointers is temp
                            //(q*)->pHead = pTemp;


                            //Push data to new node in stack
                            //New node is head and tail
                            //Apply push to stack1 (enqueue stack) and add data to new node
                            push(sTemp, int data);

            } else {
                printf("Queue overflow!\n");
		}
	}

	// Your code here
	//if stack2 is not full
	//add element to tail (stack2)
	//if stack1 is not full
	//move oldest element in tail (s2) to head (s1)

    }

int dequeue(queue2stacks **q) {

    sNode *pTemp; //new node
    int val = 0; // new data for node
    int temp =0;
    //if queue is not empty
    //move contents of stack 1 to stack 2 to produce FIFO sequence
    //Head stack now contains FIFO sequence

    if (!queueEmpty(*q))

    {

            //Loop to transfer N elements to stack 2
            for(int i=0; i<(*q)->stack1->nCount; i++)
            {
            temp = pop((*q)->stack1);
            enqueue((*q)->stack2, temp);
            };
            //stack 2 now follows FIFO sequence
            //Pop pTop of stack2 / Tail stack
            val = pop((q*)->stack2);
            //Loop to transfer N elements back to stack1
            //The stack1 will now follow LIGO sequence again
            for(int i=0; i<(*q)->stack2->nCount; i++)
            {
            temp = pop((*q)->stack2);
            enqueue((*q)->stack1, temp);
            };

    }else{
            printf("Queue Underflow!");
    }

        //POP stack 2
        //value of current head
        //ptemp is now the current head

        //head is now the previous node in stack
        //stack size decrements

    //else queue is empty return null
    //Check if stack 1 and stack 2 is empty
    //Queue empty function
    //if empty print queue underflow

    // Your code here
    return val;

}

void displayQueue(queue2stacks *q) {
    sNode *pTemp = NULL;
    int temp =0;
	// Your code here
	//while node pointer is not null
	//move all contents of enqueue stack to dequeue stack (stack 1 to stack 2)
	//print loop all conents of stacks from first-in first out (FIFO)
	//dequeue stack to be displayed (FIFO Sequence)
	//then return all contents to enqueue stack (LIFO order) stack1

		if(!queueEmpty(*q))
        {
            //Loop to transfer N elements to stack 2
            for(int i=0; i<(*q)->stack1->nCount; i++)
            {
            temp = pop((*q)->stack1);
            enqueue((*q)->stack2, temp);
            };
            //stack 2 now follows FIFO sequence
            display((q*)->stack2); //Display pTop of Stack 2 (Stack2 is FIFO sequence)

            //Loop to transfer N elements back to stack1
            //The stack1 will now follow LIGO sequence again
            for(int i=0; i<(*q)->stack2->nCount; i++)
            {
            temp = pop((*q)->stack2);
            enqueue((*q)->stack1, temp);
            };

        }
}

int head(queue2stacks *q) {

    int head=0;
	// Your code here
	//move contents of stack 1 to stack 2 (dequeue stack)
	//contents of stack 2 will follow FIFO order
	//Ptop becomes pHead (first to be dequeued which will follow LIFO as a whole)
	//Head stack / Stack2

	//int n = 0; value to n to be modified by pTop
	//if ptop of stack2 is not null
	//n = ptop = data of stack 2
	//return n

	//move stack 2 back to stack 1 / tail stack
	// stack 1 follows Lifo order as a whole once again


	//Loop to transfer N elements to stack 2
            for(int i=0; i<(*q)->stack1->nCount; i++)
            {
            temp = pop((*q)->stack1);
            enqueue((*q)->stack2, temp);
            };
            //stack 2 now follows FIFO sequence

            head = top((*q)->stack2);

            //Loop to transfer N elements back to stack1
            //The stack1 will now follow LIGO sequence again
            for(int i=0; i<(*q)->stack2->nCount; i++)
            {
            temp = pop((*q)->stack2);
            enqueue((*q)->stack1, temp);
            };


            return head;
}

int tail(queue2stacks *q) {
    int tail = 0;
	// Your code here
	//int n = 0; value to n to be modified by pTop
    top((*q)->stack1);

	//if ptop of stack1 is not null
	//n = ptop = data of stack 1
	return tail;
}

