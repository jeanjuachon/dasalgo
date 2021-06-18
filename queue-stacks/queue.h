/***************************************************
YOU ARE NOT ALLOWED TO MODIFY ANY PART OF THIS CODE
****************************************************/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *pLink;
};

typedef struct Node sNode;

typedef struct {
	int n;
	int nCount;
	sNode *pHead;
	sNode *pTail;
} queue;

queue* create(int n) {
	
	queue* q;
	
	if((q = (queue*)malloc(sizeof(queue))) == NULL) {
		printf("ERROR! Memory full\n");
	} else {
		q->n = n;
		q->nCount = 0;
		q->pHead = NULL;
		q->pTail = NULL;
	}
	
	return q;
}

int queueEmpty(queue *q) {
	return q->pHead == NULL && q->pTail == NULL;
}

int queueFull(queue *q) {
	return q->n == q->nCount + 1;
}

void enqueue(queue **q, int data) {
	sNode *pTemp;

	if((pTemp = (sNode*)malloc(sizeof(sNode))) == NULL) {
		printf("ERROR! Memory full\n");
	} else {
		if(!queueFull(*q)) {
			pTemp->data = data;
			pTemp->pLink = NULL;
			(*q)->nCount = (*q)->nCount + 1;
			if(!queueEmpty(*q)) {
				(*q)->pTail->pLink = pTemp;
				(*q)->pTail = pTemp;
			} else {
				(*q)->pHead = pTemp;
				(*q)->pTail = pTemp;
			}
		} else {
			printf("Queue overflow!\n");
		}
	}
}

int dequeue(queue **q) {
    sNode *pTemp;
    int val = 0;

	if(!queueEmpty(*q)) {
        val = (*q)->pHead->data;
        pTemp = (*q)->pHead;
        (*q)->pHead = (*q)->pHead->pLink;
        (*q)->nCount = (*q)->nCount - 1;
        if((*q)->pHead == NULL)
            (*q)->pTail = NULL;
        free(pTemp);
	} else {
		printf("Queue underflow\n");
	}

    return val;
}

void display(queue *q) {
	sNode *pTemp = NULL;
	
	if(!queueEmpty(q)) {
		pTemp = q->pHead;
		while(pTemp != NULL) {
			printf("%d, ", pTemp->data);
			pTemp = pTemp->pLink;
		}
	}
}

int head(queue *q) {
	int n = 0;
	
	if(q->pHead != NULL)
		n = q->pHead->data;
	
	return n;
}

int tail(queue *q) {
	int n = 0;
	
	if(q->pTail != NULL)
		n = q->pTail->data;
	
	return n;
}
