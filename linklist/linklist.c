#include <stdio.h>
#include "linklist.h"
#include <stdlib.h>

/**
 * 生成链表
 * return 链表头地址
 */
int linklist_create(Linklist** linklist,value_t value){
	*linklist = (Linklist *)malloc(sizeof(Linklist));
	if(*linklist != NULL){
		(*linklist)->value=value;
		(*linklist)->next = NULL;
	}
	return 0;
}

/**
 * 销毁链表
 * */
void linklist_destroy(Linklist ** linklist){
	Node ** curr;
	if(*linklist == NULL){
		return;
	}
	for(curr = linklist;*curr;){
		Node* entry = *curr;
		if(entry){
			*curr = entry->next;
			free(entry);
		}else{
			curr = &entry->next;
		}
	}
}

/**
 * 计算链表长度
 * return 链表长度
 * */
int linklist_length(Linklist * linklist){
	int len = 0;
	Linklist *point;
	if(linklist == NULL){
		return ERROR;
	}
	point = linklist;
	while(point != NULL){
		point = point->next;
		len++;
	}
	return len;
}

int linklist_insert_native(Linklist ** linklist, value_t value, int pos){
	Node* prev = NULL;
	Node* curr;
	int i;
	Node* node;

	node = (Node*)malloc(sizeof(Node));
	if(node == NULL)
		return -1;

	node->value = value;
	curr = *linklist;
	for(i = 0; i < pos && curr ;i++)
	{
		prev = curr;
		curr = curr->next;
	}

	if(prev != NULL){
		prev->next = node;
		node->next=prev->next;
	}else{
		node->next=curr;
		*linklist = node;
	}

	return 0;
}

/**
 * 插入数据
 *
 */
int linklist_insert(Linklist ** linklist,value_t value , int pos){
	if(pos < 0){
		return ERROR;
	}

	if(*linklist == NULL){
		printf("linklist is null \n");
		linklist_create(linklist,value);
		return 0;
	}

	return linklist_insert_native(linklist,value,pos);
}

int linklist_remove(Linklist ** linklist, int pos){
	Linklist* curr;
	Linklist* prev = NULL;
	int i = 0;
	if(!(*linklist) || pos <0){
		return ERROR;
	}
	if(pos > linklist_length(*linklist)){
		return ERROR;
	}
	
	curr = *linklist;
	while(curr && pos > i){
		prev = curr;
		curr = curr->next;
		i++;
	}

	if(prev != NULL){
		prev->next = curr->next;
	}else{
		*linklist = curr->next;
	}
	free(curr);
	return SUCCESSED;
}

/**
 * 打印链表元素
 */
int linklist_print(Linklist * linklist){
	Linklist * point ;
	if(linklist == NULL){
		printf("it is null\n");
		return ERROR;
	}

	point = linklist;
	if(point)
		printf("value is ");
	else{
		printf("linklist is null \n");
		goto exit;
	} 
	while(point != NULL){
		printf("%d ",point->value);
		point = point->next;
	}
	printf("\n");
exit:	
	return SUCCESSED;
}

value_t linklist_get(Linklist** linklist,int pos){
	Node* curr;
	int position;

	if(pos < 0 || *linklist == NULL){
		return ERROR;
	}

	if(pos > linklist_length(*linklist)){
		return ERROR;
	}
	
	curr = *linklist;
	for(position = 0; position < pos; position++){
		curr = curr->next;
	}
	return curr->value;

}

