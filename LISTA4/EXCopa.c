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
SimpleNode *createSimpleNode(int val);
int addLastArgs(LinkedList *lk, int val);
void printLinkedList(LinkedList *lk);

///////////////
//Teste.c
///////////////

//Definindo o Nó da Linked List
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

SimpleNode *createSimpleNode(int val){
    SimpleNode *sn = (SimpleNode *)calloc(1, sizeof(SimpleNode));
    sn->val = val, sn->next = NULL;
    return sn;
}

int addLastArgs(LinkedList *lk, int val){
    
    SimpleNode *sn = createSimpleNode(val);
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
        printf("%d ", p->val);
        p = p->next;
    }
}

void removeElementByValue(LinkedList *lk, int val){
    SimpleNode *prev = NULL;
    SimpleNode *pos = lk->begin;

    while(pos != NULL && pos->val != val){
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

    int i, entradas, remover;
    LinkedList *lk = createLinkedList();

    scanf("%d", &entradas);
    for(i = 0; i < entradas; i++){
        int elemento;
        scanf("%d", &elemento);
        addLastArgs(lk, elemento);
    }

    scanf("%d", &remover);
    for(i = 0; i < remover; i++){
        int elemento;
        scanf("%d", &elemento);
        removeElementByValue(lk, elemento);
    }

    printLinkedList(lk);
    return 0;
}

