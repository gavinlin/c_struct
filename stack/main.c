#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"
#include <math.h>

int main(int argc, const char *argv[])
{
	LinkStack *testList = NULL;
	elemType e;
	int i;
	srand(time(0));
	printf("list length is %d\n",StackLength(testList));
	if(InitStack(&testList) == ERROR){
		return -1;
	}
	for(i = 0; i < 10 ; i++){
		Push(testList,i);
	}
	printf("list length is %d\n",StackLength(testList));
	PrintStack(testList);
	Pop(testList,&e);
	printf("pop e is %d ,length is %d \n",e,StackLength(testList));
	ClearStack(&testList);
	printf("list length is %d\n",StackLength(testList));
	return 0;
}
