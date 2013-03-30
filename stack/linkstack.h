/*
 * =====================================================================================
 *
 *       Filename:  linkstack.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年03月30日 12时24分24秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef _LINKSTACK_H
#define _LINKSTACK_H

#define SUCCESSED 0
#define ERROR -1

#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int elemType;

typedef struct StackNode{
	elemType data;
	struct StackNode* next;
}StackNode,*LinkStackPtr;

typedef struct{
	LinkStackPtr top;
	int count;
}LinkStack;

Status InitStack(LinkStack** s);
Status ClearStack(LinkStack** s);
Status StackEmpty(LinkStack* s);
int StackLength(LinkStack* s);
Status Pop(LinkStack* s, elemType* e);
Status PrintStack(LinkStack* s);

#endif //_LINKSTACK_H
