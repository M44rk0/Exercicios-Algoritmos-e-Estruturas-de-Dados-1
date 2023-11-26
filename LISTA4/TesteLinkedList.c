#include <stdio.h>
#include <stdlib.h>

////////////////
//Teste.h
////////////////

typedef struct node SimpleNode;
typedef struct linkedlist LinkedList;
LinkedList *createLinkedList();
SimpleNode *createSimpleNode(int key, int val);
void addFirst(LinkedList *lk, SimpleNode *sn);
void addFirstArgs(LinkedList *lk, int key, int val);
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

//Definindo o apontador para o primeiro Nó da Linked List
typedef struct linkedlist{
    SimpleNode *begin;
} LinkedList;

//O Calloc já define o bloco alocado com valores 0 para inteiro e 
//Null para ponteiros, mas pra facilitar o entendimento, begin também
//recebe NULL
LinkedList *createLinkedList(){
    LinkedList *lk = (LinkedList *)calloc(1, sizeof(LinkedList));
    lk->begin = NULL; 
    return lk;
}
//Criando um construtor de Nó Simples para a Linked List, com a mesma 
//observação sobre NULL acima
SimpleNode *createSimpleNode(int key, int val){
    SimpleNode *sn = (SimpleNode *)calloc(1, sizeof(SimpleNode));
    sn->key = key, sn->val = val, sn->next = NULL;
    return sn;
}
//Aqui ele adiciona um Nó criado no início da Linked List
void addFirst(LinkedList *lk, SimpleNode *sn){
    //se a LinkedList está vazia, begin é um valor NULL, e next tbm é NULL
    //Ou seja, caso a lista esteja vazia ou com outros elementos, a inserção é válida em ambos os casos
    sn->next = lk->begin, lk->begin = sn;
}
//Aqui é outro construtor pra caso o Nó ainda não esteja criado
void addFirstArgs(LinkedList *lk, int key, int val){
    SimpleNode *sn = createSimpleNode(key, val);
    sn->next = lk->begin, lk->begin = sn;
}
//Funçãozinha pra printar a lista
void printLinkedList(LinkedList *lk){
    SimpleNode *p = lk->begin;
    printf("LK -> ");
    while(p != NULL){
        printf("Chave: %d, Valor: %d -> ", p->key, p->val);
        p = p->next;
    }
    printf("NULL\n");
}
//Função pra adicionar no final
void addLast(LinkedList *lk, SimpleNode *sn){
    if(lk->begin == NULL){
        //Se a lista estiver vazia, o inicio também pode ser o final
        addFirst(lk, sn);
    } 
    else{ 
        SimpleNode *p = lk->begin;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = sn;
    }
}
//Função pra adicionar no final, mas no mesmo esquema da addFirstArgs
void addLastArgs(LinkedList *lk, int key, int val){
    
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

    return 0;
}

