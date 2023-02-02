#include <stdlib.h>
#include<string.h>
#include <stdio.h>
#include "linkedlist.h"

void desalocando(const void *value){
    char * string = (char*)value;
    free(string);
}

int comparacao_1(void *value1, void *value2){
    char *string1 = (char*)value1;
    char *string2 = (char*)value2;
    return strcmp(string1,string2);
}

void print(void *value){
    printf("%s\n",(char*)value);
}

int main()
{
    LinkedList *lst = list_construct(desalocando);

    char string[100];

    while(1){
        scanf("%s",string);
        if((strcmp(".",string)) != 0){
            list_add_left(lst,strdup(string));
        }else{
            break;
        }
    }

    list_sort(lst,comparacao_1);

    list_print(lst,print);

    list_delete(lst);

    return 0;
}