#ifndef _STRLL_H_
#define _STRLL_H_

struct _str_node{
    char *str; //the value that will be stored
    struct _str_node *next; //pointer to next quentry struct or tail
    struct _str_node *prev; //pointer to previouse quentry struct or head
};

typedef struct _str_node strll; //typical handle for head of strll
typedef struct _str_node strll_entry;
typedef struct _str_node strll_tail;


strll* strll_new();
void strll_free_entry(strll_entry*);
void strll_free(strll*);
strll_entry* strll_new_entry(char*); //allocates a new strll_entry struct containing char
//strll_tail* strll_get_tail(strll*);
//strll* strll_get_head(strll*);
int strll_has_entry(strll*, char*);
int strll_isempty(strll_entry*);


void strll_insert(strll*, char*); //inserts at the front of the list
int strll_delete(strll*, char*); //delete element containing char* if it exists
int strll_isempty(strll*);

//queue interface
//int strll_enqueue(strll*, char*); //insert at the back of the list
//int strll_dequeue(strll_entry*); //remove from the front of the list

void strll_print(strll_entry *q);

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "strll.h"

strll* strll_new(){
    strll *head = (strll*)malloc(sizeof(strll));

	if (!head)
		return NULL;

    head->str = NULL;
    head->next = NULL;
    head->prev = NULL; //head always points to tail
    return head;
}
void strll_free_entry(strll_entry *entry){
    free(entry->str);
	free(entry);
}
void strll_free(strll *ll){
    if (!ll->next) {
        strll_free_entry(ll);
        return;
    }
    strll_free(ll->next);
    strll_free_entry(ll);
}



	/*int result;*/
	/*strll_entry *current = q;*/
	/*strll_entry *next;*/
	/*while (current->pid != FUTQ_TAIL){*/
		/*next = current->qnext;*/
		/*result = strll_free_entry(current);*/
		/*if (result == SYSERR)*/
			/*return result;*/

		/*current = next;*/
	/*}*/
	/*return strll_free_entry(current);*/
/*}*/

void strll_insert(strll *ll, char *new_string) {
    strll_entry *new_entry = strll_new_entry(new_string);

    if (!ll->next) { // There is nothing after the head
        ll->next = new_entry;
        new_entry->prev = ll;
        new_entry->next = NULL;
    } else { // There is an element after the head
        strll_entry *after = ll->next;

        new_entry->next = after;
        after->prev = new_entry;
        ll->next = new_entry;
        new_entry->prev = ll;
    }
}


// don't need it now
/*int strll_delete(strll *ll, char *str_to_del) {*/
    /*while (ll) {*/
        /*if (strcmp(ll->str, str_to_del) == 0) {*/
            /*strll_entry *ll_prev = ll->prev;*/
            /*if (!ll->next) {*/
                /*ll_prev->next = NULL;*/
                /*strll_free_entry(ll);*/
            /*} else {*/
                /*ll_prev->next = ll->next;*/
                /*ll->next->prev = ll_prev;*/
                /*strll_free_entry(ll);*/
            /*}*/
        /*} else {*/
            /*ll = ll->next;*/
        /*}*/
    /*}*/
/*}*/

strll_entry* strll_new_entry(char *entry_string){
    strll_entry *entry = (strll_entry*) malloc(sizeof(strll_entry));
    entry->str = (char*) malloc(strlen(entry_string) + 1);
    strcpy(entry->str, entry_string);
	return entry;
}
/*strll_entry* strll_get_tail(strll *q){*/
	/*if (q->pid == FUTQ_HEAD)*/
		/*return q->qprev; //should always be a pointer to head*/
	/*if (q->pid == FUTQ_TAIL) //this is just sainity checking*/
		/*return q;*/

	/*return strll_get_tail(q->qnext);	//so is this*/
/*}*/
/*strll_entry* strll_get_head(strll *q){*/
	/*if (q->pid == FUTQ_HEAD)*/
		/*return q; //should always be a pointer to head*/

	/*return strll_get_head(q->qprev);	// sanity check*/
/*}*/

/*void strll_enqueue(strll* q, pid32 pid){*/
	/*strll_tail *tail = strll_get_tail(q);*/
	/*strll_entry *new_entry = strll_newentry(pid);*/
	/*strll_entry *before_new = tail->qprev;*/

	/*tail->qprev = new_entry;*/
	/*new_entry->qnext = tail;*/
	/*new_entry->qprev = before_new;*/
	/*before_new->qnext = new_entry;*/

/*}*/
/*pid32 strll_dequeue(strll *q){*/
	/*strll *head = strll_get_head(q);*/
	/*strll_entry *rmv = head->qnext;*/

	/*head->qnext = rmv->qnext;*/
	/*rmv->qnext->qprev = head;*/

	/*pid32 ret = rmv->pid;*/
	/*strll_free_entry(rmv);*/

	/*return ret;*/
/*}*/
int strll_isempty(strll *ll){
    if (!ll->prev && !ll->next)
        return 1;
    return 0;
}
void strll_print(strll *ll){
    if (!ll) {
        printf("[NULL]\n");
        return;
    } else if (!ll->prev) {
        printf("[HEAD]-->");
    } else {
        printf("[%s]-->", ll->str);
    }
    strll_print(ll->next);
}
#endif //_STRLL_H_
