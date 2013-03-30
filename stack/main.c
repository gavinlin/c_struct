#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"
#include <math.h>

int isLeft(char c){
	int ret = FALSE;
	switch(c){
	case '<':
	case '{':
	case '[':
	case '(':
		ret = TRUE;
		break;
	default:
		ret = FALSE;
		break;
	}
	return ret;
}

int isRight(char c){
	int ret = FALSE;
	switch(c){
	case '>':
	case '}':
	case ']':
	case ')':
		ret = TRUE;
		break;
	default:
		ret = FALSE;
		break;
	}
	return ret;
}

Status isMatch(char left, char right){
	int ret = FALSE;
	switch(left){
	case '<':
		if( right == '>'){
			ret = TRUE;
		}
		break;
	case '{':
		if( right == '}'){
			ret = TRUE;
		}
		break;
	case '[':
		if( right == ']'){
			ret = TRUE;
		}
		break;
	case '(':
		if( right == ')'){
			ret = TRUE;
		}
		break;
	default:
		ret = FALSE;
		break;
	}
	return ret;

}

Status scanner(char* c){
	LinkStack* stack = NULL;
	InitStack(&stack);
	Status ret = FALSE;
	int i = 0;
	while(c[i] != '\0'){
		elemType e;
		if( isLeft(c[i]) ){
			Push(stack,(elemType)c[i]);
		}
		if(isRight(c[i])){
			char codeOut;
			Pop(stack,&e);
			codeOut = (char)e;
			if(!isMatch(codeOut,c[i])){
				printf("not matching %c %c\n",codeOut,c[i]);
				ret = FALSE;
				goto EXIT;
			}
		}
		i++;
	}

	if(StackEmpty(stack)){
		ret = TRUE;
	}else{
		ret = FALSE;
	}

EXIT:
	ClearStack(&stack);
	return ret;
}

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

	printf("scanner: is it matching? ");
	scanner("hello(){}") ? printf("true \n"):printf("false \n");
	return 0;
}
