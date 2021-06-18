#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(){
	bst *tree1 = create();
	insert(tree1, 5);
	printf("%d\n", tree1);
}