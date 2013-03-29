#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"
#include <math.h>

int main(int argc, const char *argv[])
{
	Linklist *testList = NULL;
	int i;
	srand(time(0));
	printf("list length is %d\n",linklist_length(testList));
	for(i = 0; i < 10 ; i++){
		/* node->value = rand()%100+1; */
		linklist_insert(&testList, i,0);
	}
	printf("list length is %d\n",linklist_length(testList));
	linklist_print(testList);
	linklist_remove(&testList, 9);
	printf("list length is %d\n",linklist_length(testList));
	linklist_print(testList);
	linklist_destroy(&testList);
	linklist_print(testList);
	return 0;
}
