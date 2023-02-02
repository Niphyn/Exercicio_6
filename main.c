
#include <stdio.h>
#include "linkedlist.h"

int main()
{
    LinkedList *lst = list_construct();

    list_add_left(lst, 3);
    list_add_left(lst, 1);
    list_add_left(lst, 5);
    list_add_left(lst, 7);
    list_add_left(lst, -2);

    printf("Primeira lista em ordem reversa de insecao:");
    list_print(lst);
    printf("\n");

    list_delete(lst);

    lst = list_construct();
    
    list_add_sorted(lst, 22);
    list_add_sorted(lst, -1);
    list_add_sorted(lst, 3);
    list_add_sorted(lst, 5);
    list_add_sorted(lst, 0);
    list_add_sorted(lst, 7);
    
    printf("Segunda lista com elementos em ordem:");
    list_print(lst);
    printf("\n");
    
    list_delete(lst);

    return 0;
}