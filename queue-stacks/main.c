#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
	stack *stack1 = create(5);
	printf("%d\n",stackEmpty(stack1));
	push(&stack1, 5);
	push(&stack1, 6);
	push(&stack1, 7);
	push(&stack1, 8);
	push(&stack1, 9);
	printf("%d\n",stackFull(stack1));
	display(stack1);
}