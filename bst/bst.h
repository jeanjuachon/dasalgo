/*******************************************************************
YOU ARE NOT ALLOWED TO MODIFY THE STRUCT AND THE FUNCTION PROTOTYPES
*******************************************************************/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *pLeft;
    struct Node *pRight;
};

typedef struct Node sNode;

typedef struct {
	sNode *pRoot;
} bst;

bst* create() { //the return type of the create function is a bst pointer
	// Your code here
	bst *tree = (bst*)malloc(sizeof(bst));
	tree -> pRoot = NULL;
	return tree;

}

void insert(bst *t, int x) {
	// Your code here
	if(t == NULL){
		t = (bst*)malloc(sizeof(bst));
		t -> pRoot ->data = x;
		t -> pRoot ->pLeft = NULL;
		t -> pRoot ->pRight = NULL;
	}

}
/*
sNode* search(bst *t, int x) {
	// Your code here
}
*/

void inorder(sNode *pPointer) {
	// Your code here
}

void preorder(sNode *pPointer) {
	// Your code here
}

void postorder(sNode *pPointer) {
	// Your code here
}
/*
sNode* maximum(sNode *pPointer) {
	// Your code here
}

sNode* minimum(sNode *pPointer) {
	// Your code here
}

sNode* parent(bst *t, int x) {
	// Your code here
}

sNode* successor(bst *t, int x) {
	// Your code here
}

sNode* predecessor(bst *t, int x) {
	// Your code here
}
*/
