
#ifndef _LINKED_LIST_
#define _LINKED_LIST_

typedef struct LinkedList LinkedList;

LinkedList *list_construct();

void list_add_left(LinkedList *lst, int value);
int list_pop_left(LinkedList *lst);
int list_get_left(LinkedList *lst);
void list_print(LinkedList *lst);
void list_delete(LinkedList *lst);
void list_add_sorted(LinkedList *lst, int value);

// TODO: Funcao a ser implementada
void list_sort(LinkedList *lst, int compare(void *, void *));

#endif
