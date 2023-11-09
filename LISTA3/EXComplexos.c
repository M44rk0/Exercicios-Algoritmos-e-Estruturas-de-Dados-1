//==============================================================================
// Arquivo conjunto.h
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
#define CRESCENTE 1
#define DECRESCENTE 0

typedef struct complexo Complexo;
typedef struct conjunto Conjunto;
int criaConjunto(Conjunto *C);
int conjuntoVazio(Conjunto *C);
int insereElementoConjunto(Complexo x, Conjunto *C);
int excluirElementoConjunto(long int x, Conjunto *C);
int tamanhoConjunto(Conjunto *C);
int pertenceConjunto(long int x, Conjunto *C);
int conjuntosIdenticos(Conjunto *C1, Conjunto *C2);
int subConjunto(Conjunto *C1, Conjunto *C2);
Conjunto complemento(Conjunto *C1, Conjunto *C2);
Conjunto uniao(Conjunto *C1, Conjunto *C2);
Conjunto interseccao(Conjunto *C1, Conjunto *C2);
Conjunto diferenca(Conjunto *C1, Conjunto *C2);
void mostraConjunto(Conjunto *C, int ordem);
int copiarConjunto(Conjunto *C1, Conjunto *C2);
int destroiConjunto(Conjunto *C);

//==============================================================================
// Arquivo conjunto.c
//==============================================================================
struct complexo{
    double real;
    double imaginario;
};
//Define o struct Conjunto
struct conjunto{
    int tamanho;
    Complexo *elementos;
};
//Funcao para criar um conjunto vazio
int criaConjunto(Conjunto *C){
    if(C != NULL){
        C->elementos = (Complexo *)malloc(MAX_ELEMENTOS * sizeof(long int));
        C->tamanho = 0;
        return SUCESSO;
    }return FALHA;
}
//Funcao pra ver se o conjunto esta vazio
int conjuntoVazio(Conjunto *C){
    return (C != NULL && C->tamanho == 0) ? TRUE : FALSE;
}
//Funcao pra iserir um elemento no conjunto
int insereElementoConjunto(Complexo x, Conjunto *C){
    if(C != NULL && C->tamanho < MAX_ELEMENTOS){
        for(int i = 0; i < C->tamanho; i++){
            if(C->elementos[i].imaginario == x.imaginario && C->elementos[i].real == x.real) return FALHA; //elemento ja existe no conjunto
        }
        C->elementos[C->tamanho] = x, C->tamanho++;
        return SUCESSO;
    }return FALHA;
}

void mostraConjunto(Conjunto *C, int ordem){
    if(C != NULL){
        if(ordem == CRESCENTE){
            printf("{");
            for(int i = 0; i < C->tamanho; i++){
                if(C->elementos[i].real == 0){
                    printf("%0.lfi, ", C->elementos[i].imaginario);
                }else{
                printf("%.0lf %.0lfi, ", C->elementos[i].real, C->elementos[i].imaginario);
                }
            }
        }else if (ordem == DECRESCENTE){
            printf("{");
            for(int i = C->tamanho - 1; i >= 0; i--){
                if(C->elementos[i].real == 0){
                    printf("%0.lfi, ", C->elementos[i].imaginario);
                }else{
                    printf("%.0lf %.0lfi, ", C->elementos[i].real, C->elementos[i].imaginario);
                }
            }
        }printf("}\n");
    }
}
int main(){
    int escolha, criadoC = 0;
    while(escolha != 0){
        Conjunto C;
        printf("|                [999] -> [Mostrar opcoes novamente] | [ 0 ] -> [Encerrar programa]                     |\n");
        scanf("%d", &escolha);
        switch (escolha){
            case 1: {
                if(criaConjunto(&C) == 1){
                    printf("Conjunto criado com sucesso\n");
                    criadoC = 1; 
                }else{printf("Erro na criacao\n");
                }break;
            }
            case 2: {
                if(criadoC){
                (conjuntoVazio(&C) == 1) ? printf("Conjunto e vazio\n") : printf("Conjunto nao e vazio\n");
                break;
                }printf("Erro, conjunto C ainda nao foi criado\n");
                break;
            }
            case 3: {
                if (criadoC) {
                    char entrada[MAX_ELEMENTOS];
                    Complexo elemento;
                    char c;
                    scanf("%c", &c);
                    printf("Digite a string no formato real + imaginarioi: ");
                    fgets(entrada, sizeof(entrada), stdin);

                    int resultado = sscanf(entrada, " %lf %c %lf", &elemento.real, &entrada[0], &elemento.imaginario);
                    
                    if (entrada[0] == '-') {
                        elemento.imaginario = -elemento.imaginario;
                    }

                    if (resultado == 2) {
                        // Apenas a parte imaginária foi fornecida
                        elemento.imaginario = elemento.real;
                        elemento.real = 0;
                    } else if (resultado != 3) {
                        // Entrada inválida
                        printf("Formato de entrada inválido.\n");
                        break;
                    }

                    (insereElementoConjunto(elemento, &C) == 1) ? printf("Elemento %.0lf %.0lfi inserido com sucesso\n", elemento.real, elemento.imaginario) : printf("Erro na insercao do elemento\n");
                } else {
                    printf("Erro, conjunto C ainda nao foi criado\n");
                }
                break;
            }
            case 5: {
                if(criadoC){
                printf("Mostrar conjunto de forma Crescente[1] ou Descrescente[0]?: ");
                int cres;
                scanf("%d", &cres);
                switch (cres) {
                    case 1:
                        mostraConjunto(&C, CRESCENTE);
                        break;
                    case 0:
                        mostraConjunto(&C, DECRESCENTE);
                        break;
                    default:
                        printf("Forma invalida, tente novamente!\n");
                        break;
                }break;
                }printf("Erro, conjunto C ainda nao foi criado\n");
                break; 
            }

    return 0;
        }
    }
}
