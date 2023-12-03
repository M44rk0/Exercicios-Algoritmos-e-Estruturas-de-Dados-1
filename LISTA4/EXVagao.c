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
int isPossible(LinkedList *lk, int vagoes);

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

int isPossible(LinkedList *lk, int vagoes){
    SimpleNode *p = lk->begin;
    int expected = vagoes;
    int expectedCres = 1;

    while (p != NULL){
        if (p->key == expected){ //Decrescente
            p = p->next;
            expected--;
        } 
        else if(p->key == expectedCres){ //Crescente
            p = p->next;
            expectedCres++;
        }
        else{
            break;
        }

    }

    return (expected == 0 || expectedCres == vagoes) ? SUCESSO : FALHA;
}

///////////////
//main.c
///////////////

int main(){
    LinkedList *lk = createLinkedList();
    int vagoes, i, vg;
    scanf("%d", &vagoes);
    for(i = 0; i < vagoes; i++){
        scanf("%d", &vg);
        addLastArgs(lk, vg);
    }
    (isPossible(lk, vagoes) == 1) ? printf("sim") : printf("nao");
    return 0;
}