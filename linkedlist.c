
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

struct LinkedList
{
    Node *head;
    int size;
};

Node *node_construct(int value, Node *next)
{
    Node *node = (Node *)calloc(1, sizeof(Node));
    node->value = value;
    node->next = next;
    return node;
}

void node_delete(Node *node)
{
    free(node);
}

LinkedList *list_construct()
{
    LinkedList *lst = (LinkedList *)calloc(1, sizeof(LinkedList));
    lst->head = NULL;
    lst->size = 0;
    return lst;
}

void list_add_left(LinkedList *lst, int value)
{
    lst->head = node_construct(value, lst->head);
    lst->size++;
}

int list_pop_left(LinkedList *lst)
{
    if (lst->size < 1)
        exit(printf("Error: Trying to pop elements in an empty linkedlist.\n"));

    int head_value = lst->head->value;
    Node *previous_head = lst->head;

    lst->head = lst->head->next;
    lst->size--;

    node_delete(previous_head);

    return head_value;
}

int list_get_left(LinkedList *lst)
{
    if (lst->size < 1)
        exit(printf("Error: Trying to pop elements in an empty linkedlist.\n"));

    return lst->head->value;
}

void list_print(LinkedList *lst)
{
    Node *it = lst->head;

    while (it != NULL)
    {
        printf("%d ", it->value);
        it = it->next;
    }
}

void list_delete(LinkedList *lst)
{
    // do not use lst->size in the loop below becasue
    // pop_left decrease size.
    int size = lst->size;

    for (int i = 0; i < size; i++)
        list_pop_left(lst);

    free(lst);
}

void list_add_sorted(LinkedList *lst, int value)
{
    // Caso 1: o valor deve ser adicionado no inicio da lista.
    // Isto acontece quando a lista eh vazia ou quando o primeiro
    // elemento eh menor que o elemento sendo inserido.
    int add_first = 0;

    if (lst->size == 0)
        add_first = 1;
    else if (value < lst->head->value)
        add_first = 1;

    if (add_first)
    {
        list_add_left(lst, value);
        return;
    }

    // Caso 2: Percorremos a lista até encontrar o primeiro
    // elemento maior que o valor sendo inserido. Ao encontrar
    // este elemento, adicionamos o novo antes dele. Considere
    // que vamos inserir o valor X entre A -> B. A lista resultante
    // sera' A -> X -> B. Para que seja possivel realizar esta
    // insercao, precisamos manter dois nos, o anterior (A) e
    // o atual (B).
    Node *previous = lst->head;
    Node *current = lst->head->next;

    while (current != NULL)
    {
        if (value < current->value)
            break;

        previous = current;
        current = current->next;
    }

    // observe que funciona tanto no caso em que chegamos ao final
    // da lista, caso em que o novo no sera o ultimo, quando no
    // caso de termos encontrado um elemento maior no meio da lista.
    Node *new = node_construct(value, current);
    previous->next = new;
    lst->size++;
}

void list_sort(LinkedList *lst, int compare(void *, void *))
{
    // TODO: Funcao a ser implementada
}
