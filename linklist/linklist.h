#ifndef _LINKLIST_H
#define _LINKLIST_H

#define ERROR -1
#define SUCCESSED 0

typedef int value_t;

typedef struct _tag_Linklist{
	value_t value;
	struct _tag_Linklist * next;
}Linklist,Node;

void linklist_destroy(Linklist ** linklist);
int linklist_length(Linklist * Linklist);
int linklist_insert(Linklist ** linklist,value_t value, int pos);
int linklist_remove(Linklist ** linklist, int pos);
int linklist_clear(Linklist * linklist);
int linklist_print(Linklist * linklist);
#endif
