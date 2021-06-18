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
	sNode *pTop;
} stack;

stack* create(int n) {
	
	stack *s;
	
	if((s = (stack*)malloc(sizeof(stack))) == NULL) {
		printf("ERROR! Memory full\n");
	} else {
		s->n = n;
		s->nCount = 0;
		s->pTop = NULL;
	}
	
	return s;
}

int stackEmpty(stack *s) {
	return s->pTop == NULL;
}

int stackFull(stack *s) {
	return s->n == s->nCount;
}

void push(stack **s, int data) {
	sNode *pTemp;
	
	if((pTemp = (sNode*)malloc(sizeof(sNode))) == NULL) {
		printf("ERROR! Memory full\n");
	} else {
		if(!stackFull(*s)) {
			pTemp->data = data;
			pTemp->pLink = (*s)->pTop;
			(*s)->pTop = pTemp;
			(*s)->nCount = (*s)->nCount + 1;
		} else {
			printf("Stack overflow!\n");
		}
	}
}

int pop(stack **s) {
	sNode *pTemp;
	int val = 0;
	
	if(!stackEmpty(*s)) {
		val = (*s)->pTop->data;
		pTemp = (*s)->pTop;
		(*s)->pTop = (*s)->pTop->pLink;
		pTemp->pLink = NULL;
		(*s)->nCount = (*s)->nCount - 1;
		free(pTemp);
	} else {
		printf("Stack underflow\n");
	}
	
	return val;

}

void display(stack *s) {
	sNode *pTemp = NULL;
	
	if(!stackEmpty(s)) {
		pTemp = s->pTop;
		while(pTemp != NULL) {
			printf("%d, ", pTemp->data);
			pTemp = pTemp->pLink;
		}
	}
}

int top(stack *s) {
	int n = 0;
	
	if(s->pTop != NULL)
		n = s->pTop->data;
		
	return n;
}
