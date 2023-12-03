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
SimpleNode *createSimpleNode(int key, int val);
int addFirst(LinkedList *lk, SimpleNode *sn);
int addFirstArgs(LinkedList *lk, int key, int val);
void printLinkedList(LinkedList *lk);

///////////////
//Teste.c
///////////////

typedef struct node{
    int key;
    int val;
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

SimpleNode *createSimpleNode(int key, int val){
    SimpleNode *sn = (SimpleNode *)calloc(1, sizeof(SimpleNode));
    sn->key = key, sn->val = val, sn->next = NULL;
    return sn;
}

int addFirst(LinkedList *lk, SimpleNode *sn){
    sn->next = lk->begin, lk->begin = sn;
    return SUCESSO;
}

int addFirstArgs(LinkedList *lk, int key, int val){
    SimpleNode *sn = createSimpleNode(key, val);
    sn->next = lk->begin, lk->begin = sn;
    return SUCESSO;
}

int addLast(LinkedList *lk, SimpleNode *sn){
    if(lk->begin == NULL){

        addFirst(lk, sn);
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

int addLastArgs(LinkedList *lk, int key, int val){
    
    SimpleNode *sn = createSimpleNode(key, val);
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
    printf("LK -> ");
    while(p != NULL){
        printf("Chave: %d, Valor: %d -> ", p->key, p->val);
        p = p->next;
    }
    printf("NULL\n");
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
            lk->begin = pos->next;
        } 
        else{
            prev->next = pos->next;
        }
        free(pos);
    }
}

/////////////////
//main.c
/////////////////

int main(){

    LinkedList *lk = createLinkedList();
    addLastArgs(lk, 1, 29);
    addFirstArgs(lk, 2, 15);
    addLastArgs(lk, 6, 34);
    addLastArgs(lk, 7, 37);
    addFirstArgs(lk, 8, 45);
    printLinkedList(lk);
    removeElementByKey(lk, 2);
    printLinkedList(lk);
    removeElementByKey(lk, 9);
    printLinkedList(lk);
    removeElementByKey(lk, 7);
    removeElementByKey(lk, 8);
    printLinkedList(lk);
    removeElementByKey(lk, 6);
    printLinkedList(lk);

    return 0;
}

