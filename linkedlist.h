
#ifndef _LINKED_LIST_
#define _LINKED_LIST_

typedef struct LinkedList LinkedList;

typedef void (*desaloca)(const void *value);

LinkedList *list_construct(desaloca funcao_desalocando);

int list_size(LinkedList *lst);
void list_add_left(LinkedList *lst, void *value);
void list_pop_left(LinkedList *lst);
void *list_get_left(LinkedList *lst);
void list_print(LinkedList *lst,void printar(void *));
void list_delete(LinkedList *lst);

// TODO: Funcao a ser implementada
void list_sort(LinkedList *lst, int compare(void *, void *));

#endif
