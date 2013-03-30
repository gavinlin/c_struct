/*
 * =====================================================================================
 *
 *       Filename:  linkstack.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年03月30日 12时24分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "linkstack.h"
Status InitStack(LinkStack** s){
	if(*s != NULL)
		return ERROR;
	*s = (LinkStack*)malloc(sizeof(LinkStack));
	if(!s)
		return ERROR;
	(*s)->count=0;
	(*s)->top=NULL;
	return SUCCESSED;
}

Status ClearStack(LinkStack** s){
	LinkStack** nativeS;

	if(*s == NULL)
		return ERROR;

	nativeS = s;
	while((*nativeS)->top){
		LinkStackPtr curr;
		curr = (*nativeS)->top;
		(*nativeS)->top = (*nativeS)->top->next;
		free(curr);
	}
	(*s)->count = 0;
	return SUCCESSED;
}

Status StackEmpty(LinkStack* s){
	if(s == NULL)
		return ERROR;
	if(s->count == 0)
		return TRUE;
	else
		return FALSE;
} 

int StackLength(LinkStack* s){
	if(s == NULL)
		return -1;
	return s->count;
}

Status Push(LinkStack* s, elemType e){
	LinkStackPtr lsp = (LinkStackPtr)malloc(sizeof(StackNode));
	lsp->data = e;
	lsp->next = s->top;
	s->top = lsp;
	s->count++;
	return SUCCESSED;
}

Status Pop(LinkStack* s, elemType* e){
	if(s == NULL || StackEmpty(s) ){
		*e = -1;
		return ERROR;
	}

	LinkStackPtr p;
	if(StackEmpty(s)){
		return ERROR;
	}
	p = s->top;
	*e = s->top->data;
	s->top = s->top->next;
	free(p);
	s->count--;
	return SUCCESSED;
}

Status PrintStack(LinkStack* s){
	LinkStackPtr p;
	p = s->top;
	while(p){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
	return SUCCESSED;
}
