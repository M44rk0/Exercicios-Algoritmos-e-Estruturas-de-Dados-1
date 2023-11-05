//==============================================================================
// Arquivo ponto.h
//==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

//Define o tamanho máximo de elementos no conjunto
#define MAX_ELEMENTOS 1000000 

//Define as constantes
#define SUCESSO 1
#define FALHA 0
#define TRUE 1
#define FALSE 0 
#define TOP 1
#define BASE 0

typedef struct stack Stack;

struct stack{
    long int *data;
    long int top;
};

int create(Stack *P){
    if(P != NULL){
        P->data = (long int *)malloc(MAX_ELEMENTOS * sizeof(long int));
        P->top = -1;
        return SUCESSO;
    }return FALHA;
}

int isEmpty(Stack *P){
    return (P != NULL && P->top == -1) ? TRUE : FALSE;
}

int push(Stack *P, long int elemento){
    if(P != NULL && P->top < MAX_ELEMENTOS && elemento < LONG_MAX && elemento > LONG_MIN){
        P->top++;
        P->data[P->top] = elemento;
        return SUCESSO;
    }return FALHA;
};

int pop(Stack *P){
    if(P != NULL && P->top > -1){
        P->top--;
        return SUCESSO;
    }return FALHA;
}

long int size(Stack *P){
    return(P->top == -1) ? 0 : P->top+1;
}

int belongTo(long int x, Stack *P){
    if(P != NULL){
        for(int i = 0; i < P->top; i++){
            if(P->data[i] == x){
                return TRUE;
            }
        }return FALSE;
    }return FALSE;
}

int isEqual(Stack *P1, Stack *P2){
    if(P1 != NULL && P2 != NULL && P1->top == P2->top){
        for(int i = 0; i < P1->top; i++){
            long int elemento = P1->data[i];
            if(!belongTo(elemento, P2)){
                return FALSE;
            }
        }return TRUE;
    }return FALSE;
}

void show(Stack *P, int ordem){
    if(P != NULL){
        if(ordem == BASE){
            for(int i = 0; i < P->top+1; i++){
                printf(" %ld \n", P->data[i]);
            }
        }else if (ordem == TOP){
            for(int i = P->top; i >= 0; i--){
                printf("  %ld \n", P->data[i]);

            }
        }
    }
}


void createP1P2(Stack *P1, Stack *P2){
    create(P1), create(P2);
    printf("Quantos elementos em P1?: ");
    int quantidade;
    while(1){
        scanf("%d", &quantidade);
        if(quantidade <= 0){
            printf("quantidade inválida, tente novamente.\n");
            printf("Quantos elementos em P1?: ");
        }else{break;};
    }
    printf("Digite os elementos a serem inseridos em P1:\n");
    for(int i = 0; i<quantidade; i++){
        long int elemento;
        printf("%d elemento: ", i+1);
        scanf("%ld", &elemento);
        push(P1, elemento);
    }
    printf("Quantos elementos em P2?: ");
    int quantidade2;
    while(1){
        scanf("%d", &quantidade2);
        if(quantidade2 <= 0){
            printf("quantidade inválida, tente novamente\n");
            printf("Quantos elementos em P2?: ");
        }else{break;};
    }
    printf("Digite os elementos a serem inseridos em P2:\n");
    for(int i = 0; i<quantidade2; i++){
        long int elemento2;
        printf("%d° elemento: ", i+1);
        scanf("%ld", &elemento2);
        push(P2, elemento2);
    }
}

int copy(Stack *P1, Stack *P2){
    if (P1 != NULL && P2 != NULL){
        P2->top = P1->top;
        for (int i = 0; i < P1->top; i++){
            P2->data[i] = P1->data[i];
        }return SUCESSO;
    }return FALHA;
}

int destroy(Stack *P){
    if (P != NULL){
        P->top = -1;
        free(P->data);
        return SUCESSO;
    }return FALHA;
}

int main(){
    Stack P, P1, P2;
    return 0;
}



