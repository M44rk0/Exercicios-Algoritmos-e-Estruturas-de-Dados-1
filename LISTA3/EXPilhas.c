//==============================================================================
// Arquivo ponto.h
//==============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
//Define o tamanho maximo de elementos no conjunto
#define MAX_ELEMENTOS 1000000 
//Define as constantes
#define SUCESSO 1
#define FALHA 0
#define TRUE 1
#define FALSE 0 
#define TOP 1
#define BASE 0
//Define o cabecalho das funcões
typedef struct stack Stack;
int create(Stack *P);
int isEmpty(Stack *P);
int push(Stack *P, long int elemento);
int pop(Stack *P);
long int size(Stack *P);
int belongTo(long int x, Stack *P);
int isEqual(Stack *P1, Stack *P2);
void show(Stack *P, int ordem);
int copy(Stack *P1, Stack *P2);
//==============================================================================
// Arquivo ponto.c
//==============================================================================

//Definindo o struct stack(Pilha)
struct stack{
    long int *data;
    long int top;
};
//Funcao pra criar pilha
int create(Stack *P){
    if(P != NULL){
        P->data = (long int *)malloc(MAX_ELEMENTOS * sizeof(long int));
        P->top = -1;
        return SUCESSO;
    }return FALHA;
}
//Funcao pra verificar se a pilha e vazia ou nao
int isEmpty(Stack *P){
    return (P != NULL && P->top == -1) ? TRUE : FALSE;
}
//Funcao pra inserir um elemento no topo da pilha
int push(Stack *P, long int elemento){
    if(P != NULL && P->top < MAX_ELEMENTOS && elemento < LONG_MAX && elemento > LONG_MIN){
        P->top++;
        P->data[P->top] = elemento;
        return SUCESSO;
    }return FALHA;
};
//Funcao pra remover um elemento do topo da pilha
int pop(Stack *P){
    if(P != NULL && P->top > -1){
        P->top--;
        return SUCESSO;
    }return FALHA;
}
//Funcao para mostrar o tamanho da pilha
long int size(Stack *P){
    return(P->top == -1) ? 0 : P->top+1;
}
//Funcao auxiliar para verificar se um elemento pertence a pilha
int belongTo(long int x, Stack *P){
    if(P != NULL){
        for(int i = 0; i < P->top; i++){
            if(P->data[i] == x){
                return TRUE;
            }
        }return FALSE;
    }return FALSE;
}
//Funcao pra verificar se duas pilhas sao iguais
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
//Funcao para printar a pilha
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
        }printf("\n");
    }
}
//Funcao pra copiar uma pilha pra outra
int copy(Stack *P1, Stack *P2){
    if (P1 != NULL && P2 != NULL){
        P2->top = P1->top;
        for (int i = 0; i < P1->top; i++){
            P2->data[i] = P1->data[i];
        }return SUCESSO;
    }return FALHA;
}
//Funcao auxiliar pra criar duas Pilhas, P1 & P2
void createP1P2(Stack *P1, Stack *P2){
    create(P1), create(P2);
    printf("Quantos elementos em P1?: ");
    int quantidade;
    while(1){
        scanf("%d", &quantidade);
        if(quantidade <= 0){
            printf("quantidade invalida, tente novamente.\n");
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
            printf("quantidade invalida, tente novamente\n");
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
//Funcao extra pra destruir uma pilha
int destroy(Stack *P){
    if (P != NULL){
        P->top = -1;
        free(P->data);
        return SUCESSO;
    }return FALHA;
}
//Funcao auxiliar pra printar linha
void printLinha(){
    printf("+------------------------------------------------------------------------+\n");
}
//Funcao auxiliar pra printar opcões
void opcoes(){
    printLinha();
    printf("| [1] -> [Criar uma Pilha P]                                             |\n");
    printf("| [2] -> [Verificar se a Pilha P e vazia]                                |\n");
    printf("| [3] -> [Inserir um elemento na Pilha P]                                |\n");
    printf("| [4] -> [Excluir um elemento da Pilha P]                                |\n");
    printf("| [5] -> [Mostrar os elementos da Pilha P]                               |\n");
    printf("| [6] -> [Calcular a cardinalidade da Pilha P]                           |\n");
    printf("| [7] -> [Comparar duas Pilhas]                                          |\n");
    printf("| [8] -> [Copiar uma Pilha para outra]                                   |\n");
    printf("| [9] -> [Destruir Pilha]                                                |\n");
}
//Funcao pra printar boas vindas :O
void boasVindas(){
    printLinha();
    printf("|                    Bem-vindo ao menu de operacoes                      |\n");
    printf("|                             com Pilhas                                 |\n");
    printLinha();
    printf("|                          Escolha uma opcao:                            |\n");
    opcoes();
}

int main(){
   boasVindas();
    int escolha, criadoP = 0;
    while(escolha != 0){
        Stack P, P1, P2;
        printLinha();
        printf("| [999] -> [Mostrar opcoes novamente]                                    |\n");
        printf("| [ 0 ] -> [Encerrar programa]                                           |\n");
        printLinha();
        scanf("%d", &escolha);
        switch (escolha){
            case 999: {
                opcoes();
                break;
            }
            case 1: {
                if(create(&P) == 1){
                    printf("Pilha criada\n");
                    criadoP = 1; 
                }else{printf("Erro na criacao\n");
                }break;
            }
            case 2: {
                if(criadoP){
                (isEmpty(&P) == 1) ? printf("Pilha vazia\n") : printf("Pilha nao e vazia\n");
                break;
                }printf("Erro, Pilha P ainda nao foi criada\n");
                break;
            }
            case 3: {
                if(criadoP){
                long int elemento;
                printf("Digite o elemento a ser inserido na Pilha: ");
                scanf("%ld", &elemento);
                (push(&P, elemento) == 1) ? printf("Elemento inserido com sucesso\n") : printf("Erro na insercao do elemento\n");
                break;
                }printf("Erro, Pilha P ainda nao foi criada\n");
                break;
            }
            case 4: {
                if(criadoP){
                long int elemento;
                printf("Digite o elemento a ser excluido do conjunto: ");
                scanf("%ld", &elemento);
                (pop(&P) == 1) ? printf("Elemento excluido com sucesso\n") : printf("Erro na exclusao do elemento\n");
                break;
                }printf("Erro, Pilha P ainda nao foi criado\n");
                break;
            }
            case 5: {
                if(criadoP){
                printf("Mostrar pilha desde o Topo[1] ou desde a Base[2]?: ");
                int cres;
                scanf("%d", &cres);
                switch(cres){
                    case 0:
                        show(&P, BASE);
                        break;
                    case 1:
                        show(&P, TOP);
                        break;
                    default:
                        printf("Opcao invalida\n");
                        break;
                }break;
                }printf("Erro, Pilha P ainda nao foi criada\n");
                break; 
            }
            case 6: {
                if(criadoP){
                printf("Tamanho do Pilha P: %ld\n", size(&P));
                break;
                }printf("Erro, Pilha P ainda nao foi criada\n");
                break;
            }
            case 7: {
                createP1P2(&P1, &P2);
                (isEqual(&P1, &P2) == 1) ? printf("As pilhas sao identicas\n") : printf("As pilhas nao sao identicas\n");
                break;
            }
            case 8: {
                createP1P2(&P1, &P2);
                if(copy(&P1, &P2) == 1){
                    printf("Copiado com sucesso\n");
                    show(&P2, TOP);
                }else{printf("Erro na copia\n");
                }break;
            }
            case 9: {
                printf("Qual pilha destruir? (P = 0, P1 & P2 = 1): \n");
                int opcao;
                scanf("%d", &opcao);
                switch (opcao){
                case 0: {
                    criadoP = 0;
                    (destroy(&P) == 1) ? printf("Pilha P destruida com sucesso!\n") : printf("Erro na destruicao da Pilha P\n");
                    break;
                }
                case 1: {
                    (destroy(&P1) == 1 && destroy(&P2) == 1) ? printf("Pilha P1 e P2 destruidas com sucesso\n") : printf("Erro na destruicao das Pilhas\n");
                    break;
                }
                default:
                    printf("Opcao invalida. Tente novamente.\n");
                    break;
                }break;
            }
            case 0: {
                destroy(&P), destroy(&P1), destroy(&P2);
                break;
            }
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    }return 0;
}