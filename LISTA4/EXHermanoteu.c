#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 1
#define FALHA 0

////////////////
//Teste.h
////////////////

typedef struct node SimpleNode;
typedef struct linkedlist LinkedList;
LinkedList *createLinkedList();
SimpleNode *createSimpleNode(char *name, char *number, int calls);
int addLastArgs(LinkedList *lk, char *name, char *number, int calls);
void printLinkedList(LinkedList *lk);
void removeElementByKey(LinkedList *lk, char *name);

///////////////
//Teste.c
///////////////

typedef struct node{
    char *name;
    char *number;
    int calls;
    struct node *next;
} SimpleNode;

typedef struct linkedlist{
    SimpleNode *begin;
} LinkedList;

LinkedList *createLinkedList(){
    LinkedList *lk = (LinkedList *)calloc(1, sizeof(LinkedList));
    lk->begin = NULL;
    return lk;
}

SimpleNode *createSimpleNode(char *name, char *number, int calls){
    SimpleNode *sn = (SimpleNode *)calloc(1, sizeof(SimpleNode));
    sn->name = strdup(name);
    sn->number = strdup(number);
    sn->calls = calls;
    sn->next = NULL;
    return sn;
}

int addLastArgs(LinkedList *lk, char *name, char *number, int calls){
    SimpleNode *sn = createSimpleNode(name, number, calls);
    if(lk->begin == NULL){
        lk->begin = sn;
    }
    else{
        SimpleNode *p = lk->begin;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = sn;
    }
    return SUCESSO;
}

void printLinkedList(LinkedList *lk){
    SimpleNode *p = lk->begin;
    while(p != NULL){
        printf("%s - %s %d\n", p->name, p->number, p->calls);
        p = p->next;
    }
}

void removeElementByKey(LinkedList *lk, char *name){
    SimpleNode *prev = NULL;
    SimpleNode *pos = lk->begin;

    while(pos != NULL && strcmp(pos->name, name) != 0){
        prev = pos;
        pos = pos->next;
    }

    if(pos != NULL){
        if(prev == NULL){
            // Se o nó a ser removido é o primeiro da lista
            lk->begin = pos->next;
        } 
        else{
            // Se o nó a ser removido tá no meio
            prev->next = pos->next;
        }
        free(pos);
    }
}

void addCall(LinkedList *lk, char *name){
    SimpleNode *p = lk->begin;
    while(p != NULL && strcmp(p->name, name) != 0){
        p = p->next;
    }
    p->calls++;
}

void bubbleSort(LinkedList *lk) {
    int swapped;
    SimpleNode *ptr1;
    SimpleNode *lptr = NULL;

    if (lk->begin == NULL || lk->begin->next == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = lk->begin;

        while (ptr1->next != lptr) {
            if (ptr1->calls < ptr1->next->calls) {

                char *tempName = ptr1->name;
                char *tempNumber = ptr1->number;
                int tempCalls = ptr1->calls;

                ptr1->name = ptr1->next->name;
                ptr1->number = ptr1->next->number;
                ptr1->calls = ptr1->next->calls;

                ptr1->next->name = tempName;
                ptr1->next->number = tempNumber;
                ptr1->next->calls = tempCalls;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main(){

    LinkedList *lk = createLinkedList();
    addLastArgs(lk, "Hermanoteu", "4523-2248", 300);
    addLastArgs(lk, "Ooloneia", "4523-4887", 299);
    char escolha, name[20], number[20];
    int calls;

    while(escolha != 'F'){
        escolha = getchar();
        switch(escolha){
            case 'I':
                scanf("%s", name);
                getchar();
                scanf("%s", number);
                getchar();
                scanf("%d", &calls);
                getchar();
                addLastArgs(lk, name, number, calls);
                break;
            case 'R':
                scanf("%s", name);
                removeElementByKey(lk, name);
                break;
            case 'L':
                scanf("%s", name);
                getchar();
                addCall(lk, name);
                break;
            case 'F':
                bubbleSort(lk);
                printLinkedList(lk);
                break;
        }
    }

    return 0;
}