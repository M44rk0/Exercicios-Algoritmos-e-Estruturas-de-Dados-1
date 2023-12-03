#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 1
#define FALHA 0

////////////////
//Teste.h
////////////////

typedef struct node SimpleNode;
typedef struct linkedlist LinkedList;
LinkedList *createLinkedList();
SimpleNode *createSimpleNode(int key);
int addLastArgs(LinkedList *lk, int key);
void printLinkedList(LinkedList *lk);
void removeElementByKey(LinkedList *lk, int key);
void insertElementByKey(LinkedList *lk, int insertKey, int key);
void searchElements(LinkedList *lk, int initKey, int endKey);

///////////////
//Teste.c
///////////////

typedef struct node{
    int key;
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

SimpleNode *createSimpleNode(int key){
    SimpleNode *sn = (SimpleNode *)calloc(1, sizeof(SimpleNode));
    sn->key = key, sn->next = NULL;
    return sn;
}

int addLastArgs(LinkedList *lk, int key){
    SimpleNode *sn = createSimpleNode(key);
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
    printf("lista ");
    while(p != NULL){
        printf("%d ", p->key);
        p = p->next;
    }
    printf("\n");
}

void removeElementByKey(LinkedList *lk, int key){
    SimpleNode *prev = NULL;
    SimpleNode *pos = lk->begin;

    while(pos != NULL && pos->key != key){
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
        printf("removido %d\n", key);
    }
}

void insertElementByKey(LinkedList *lk, int insertKey, int key){
    SimpleNode *prev = NULL;
    SimpleNode *pos = lk->begin;
    SimpleNode *sn = createSimpleNode(insertKey);

    while(pos != NULL && pos->key != key){
        prev = pos;
        pos = pos->next;
    }

    if(pos != NULL){
        if(prev == NULL){
            // Se o nó a ser inserido é o primeiro da lista
            sn->next = pos->next;
            pos->next = sn;
        } 
        else{
            // Se o nó a ser inserido tá no meio
            sn->next = pos->next;
            pos->next = sn;
        }
        printf("inserido %d\n", insertKey);
    }
}

void searchElements(LinkedList *lk, int initKey, int endKey){
    SimpleNode *init = lk->begin;
    SimpleNode *end = NULL;
    int count = 0;
    while(init != NULL && init->key != initKey && init->key != endKey){
        init = init->next;
    }

    if(init != NULL){
        end = init->next;

        // Se endKey foi encontrado antes de initKey, troca um pelo outro
        if (end != NULL && end->key == initKey) {
            SimpleNode *temp = init;
            init = end;
            end = temp;
        }

        while(end != NULL && end->key != initKey && end->key != endKey){
                end = end->next;
                count++;
        }
    }

    printf("quantidade %d\n", count);
}


int main(){
    LinkedList *lk = createLinkedList();
    int i, entradas, elemento, insertKey, key, initKey, endKey;
    char escolha;

    scanf("%d", &entradas);
    for(i = 0; i < entradas; i++){
        scanf("%d", &elemento);
        addLastArgs(lk, elemento);
    }

    while(escolha != 'F'){
        escolha = getchar();
        switch(escolha){
            case 'I':
                scanf("%d", &insertKey);
                scanf("%d", &key);
                insertElementByKey(lk, insertKey, key);
                break;
            case 'R':
                scanf("%d", &key);
                removeElementByKey(lk, key);
                break;
            case 'C':
                scanf("%d", &initKey);
                scanf("%d", &endKey);
                searchElements(lk, initKey, endKey);
                break;
            case 'M':
                printLinkedList(lk);
            case 'F':
                printf("fim");
                break;

        }
    }

    return 0;
}