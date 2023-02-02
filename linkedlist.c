
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

typedef struct Node
{
    void *value;
    struct Node *next;
} Node;

struct LinkedList
{
    Node *head;
    desaloca ptr_funcao_desaloca;
    int size;
};

typedef int (*comparacao)(const void *value1, const void *value2);

int list_size(LinkedList *lst){
    return lst->size;
}

Node *node_construct(void *value, Node *next)
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

LinkedList *list_construct(desaloca funcao_desalocando)
{
    LinkedList *lst = (LinkedList *)calloc(1, sizeof(LinkedList));
    lst->head = NULL;
    lst->size = 0;
    lst->ptr_funcao_desaloca = funcao_desalocando;
    return lst;
}

void list_add_left(LinkedList *lst, void *value)
{
    lst->head = node_construct(value, lst->head);
    lst->size++;
}

void list_pop_left(LinkedList *lst)
{
    if (lst->size < 1)
        exit(printf("Error: Trying to pop elements in an empty linkedlist.\n"));

    void *head_value = lst->head->value;
    Node *previous_head = lst->head;

    lst->head = lst->head->next;
    lst->size--;

    desaloca funcao_desaloca = lst->ptr_funcao_desaloca;
    funcao_desaloca(head_value);
    node_delete(previous_head);
}

void *list_get_left(LinkedList *lst)
{
    if (lst->size < 1)
        exit(printf("Error: Trying to pop elements in an empty linkedlist.\n"));

    return lst->head->value;
}

void list_print(LinkedList *lst,void printar(void *))
{
    Node *it = lst->head;

    while (it != NULL)
    {
        printar(it->value);
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

/*void list_add_sorted(LinkedList *lst, int value)
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
}*/

void list_sort(LinkedList *lst, int compare(void *, void *))
{
    if((lst->size) > 1){
        void *aux;
        Node *aux_ptr_node,*right_node,*left_node;
        int qtd_fora_ordem = 0, verifica = -1;
        while(verifica != 0){
            for(int i= 0; i < lst->size; i++){
                if(i==0){
                    left_node = lst->head;
                    right_node = left_node->next;
                }else{
                    left_node = right_node;
                    right_node = left_node->next;
                }
                if((right_node != NULL) && (compare(right_node->value,left_node->value) < 0)){
                    qtd_fora_ordem++;
                    aux = left_node->value;
                    left_node->value = right_node->value;
                    right_node->value = aux;
                    aux_ptr_node = right_node->next;
                    right_node->next = left_node;
                    left_node->next = aux_ptr_node;
                }
                if(qtd_fora_ordem != 0 ){
                    break;
                }
            }
            if(qtd_fora_ordem == 0){
                verifica = 0;
                qtd_fora_ordem = 0;
            }
            qtd_fora_ordem = 0;
        }
    }
}
