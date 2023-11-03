//==============================================================================
// Arquivo ponto.h
//==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

//Define o tamanho máximo de elementos no conjunto
#define MAX_ELEMENTOS 1000000 

//Define as constantes
#define SUCESSO 1
#define FALHA 0
#define TRUE 1
#define FALSE 0 
#define CRESCENTE 1
#define DECRESCENTE 2

typedef struct conjunto Conjunto;
int criaConjunto(Conjunto *C);
int conjuntoVazio(Conjunto *C);
int insereElementoConjunto(long int x, Conjunto *C);
int excluirElementoConjunto(long int x, Conjunto *C);
int tamanhoConjunto(Conjunto *C);
int maior(long int x, Conjunto *C);
int menor(long int x, Conjunto *C);
int pertenceConjunto(long int x, Conjunto *C);
int conjuntosIdenticos(Conjunto *C1, Conjunto *C2);
int subConjunto(Conjunto *C1, Conjunto *C2);
Conjunto complemento(Conjunto *C1, Conjunto *C2);
Conjunto uniao(Conjunto *C1, Conjunto *C2);
Conjunto interseccao(Conjunto *C1, Conjunto *C2);
Conjunto diferenca(Conjunto *C1, Conjunto *C2);
Conjunto conjuntoPartes(Conjunto *C);
void mostraConjunto(Conjunto *C, int ordem);
int copiarConjunto(Conjunto *C1, Conjunto *C2);
int destroiConjunto(Conjunto *C);

//==============================================================================
// Arquivo ponto.c
//==============================================================================

//Define o struct Conjunto
struct conjunto{
    long int elementos[MAX_ELEMENTOS];
    int tamanho;
};

//Função para criar um conjunto vazio
int criaConjunto(Conjunto *C){
    if(C != NULL){
        C->tamanho = 0;
        return SUCESSO;
    }
    return FALHA;
}

//Função pra ver se o conjunto está vazio
int conjuntoVazio(Conjunto *C){
    return (C != NULL && C->tamanho == 0) ? TRUE : FALSE;
}

//Função pra iserir um elemento no conjunto
int insereElementoConjunto(long int x, Conjunto *C){
    if(C != NULL && C->tamanho < MAX_ELEMENTOS && x < LONG_MAX){
        for(int i = 0; i < C->tamanho; i++){
            if(C->elementos[i] == x){
                return FALHA; //elemento já existe no conjunto
            }
        }

        C->elementos[C->tamanho] = x;
        C->tamanho++;
        return SUCESSO;
    }
    return FALHA;
}

//Função pra exlucir um elemento do conjunto
int excluirElementoConjunto(long int x, Conjunto *C){
    if(C != NULL){
        int encontrado = FALSE;
        for(int i = 0; i<C->tamanho; i++){
            if(C->elementos[i] == x){
                encontrado = TRUE;
                //move os elementos á direita do elemento que vai ser excluido
                for(int j = 0; j < C->tamanho - 1; i++){
                    C->elementos[j] = C->elementos[j+1];
                }
                C->tamanho--;
                break;
            }
        }
        return encontrado ? SUCESSO : FALHA;
    }
    return FALHA;
}

//Função pra calcular a cardinalidade do conjunto
int tamanhoConjunto(Conjunto *C){
    return (C != NULL) ? C->tamanho : 0;
}

//Função pra ver a quantidade de elementos maiores que X no conjunto
int maior(long int x, Conjunto *C){
    int maiores = 0;
    if(C != NULL){
        for(int i = 0; i < C->tamanho; i++){
            if(C->elementos[i] > x){
                maiores++;
            }
        }

        if(C->tamanho == maiores){
            return 0;
        }
    }
    return maiores;
}

//Função pra ver a quantidade de elementos menores que X no conjunto 
int menor(long int x, Conjunto *C){
    int menores = 0;
    if(C != NULL){
        for(int i = 0; i < C->tamanho; i++){
            if(C->elementos[i] < x){
                menores++;
            }
        }

        if(C->tamanho == menores){
            return 0;
        }
    }
    return menores;
}

//Função pra verificar se o elemento X pertence ao conjunto
int pertenceConjunto(long int x, Conjunto *C){
    if(C != NULL){
        for(int i = 0; i < C->tamanho; i++){
            if(C->elementos[i] == x){
                return TRUE;
            }
        }
        return FALSE;
    }
    return FALSE;
}

//Função pra comparar se os conjuntos são idênticos
int conjuntosIdenticos(Conjunto *C1, Conjunto *C2){
    if(C1 != NULL && C2 != NULL && C1->tamanho == C2->tamanho){
        for(int i = 0; i < C1->tamanho; i++){
            long int elemento = C1->elementos[i];
            if(!pertenceConjunto(elemento, C2)){
                return FALSE;
            }
        }
        return TRUE;
    }
    return FALSE;
}

//Funççao pra verificar se C1 é subconjunto de C2
int subConjunto(Conjunto *C1, Conjunto *C2){
    if(C1 != NULL && C2 != NULL){
        for(int i = 0; i < C1->tamanho; i++){
            long int elemento = C1->elementos[i];
            if(!pertenceConjunto(elemento, C2)){
                return FALSE;
            }
        }
        return TRUE;
    }
    return FALSE;
}

//Função pra gerar o complemento de C1 em relação a C2
Conjunto complemento(Conjunto *C1, Conjunto *C2){
    Conjunto complemento;
    criaConjunto(&complemento);

    if(C1 != NULL && C2 != NULL){
        for(int i = 0; i < C2->tamanho; i++){
            long int elemento = C2->elementos[i];
            if(!pertenceConjunto(elemento, C1)){
                insereElementoConjunto(elemento, &complemento);
            }
        }
    }

    return complemento;
}

//Função pra gerar a união de C1 com C2
Conjunto uniao(Conjunto *C1, Conjunto *C2){
    Conjunto uniao;
    criaConjunto(&uniao);

    if(C1 != NULL && C2 != NULL){
        for(int i = 0; i < C1->tamanho; i++){
            insereElementoConjunto(C1->elementos[i], &uniao);
        }
        for(int i = 0; i < C2->tamanho; i++){
            insereElementoConjunto(C2->elementos[i], &uniao);
        }
    }
    return uniao;
}

//Função pra gerar a intersecção de C1 com C2
Conjunto interseccao(Conjunto *C1, Conjunto *C2){
    Conjunto interseccao;
    criaConjunto(&interseccao);

    if(C1 != NULL && C2 != NULL){
        for(int i = 0; i < C1->tamanho; i++){
            long int elemento = C1->elementos[i];
            if(pertenceConjunto(elemento, C2)){
                insereElementoConjunto(elemento, &interseccao);
            }
        }
    }
    return interseccao;
}

//Função pra gerar a diferença de C1 e C2
Conjunto diferenca(Conjunto *C1, Conjunto *C2){
    Conjunto diferenca;
    criaConjunto(&diferenca);

    if(C1 != NULL && C2 != NULL){
        for(int i = 0; i < C1->tamanho; i++){
            long int elemento = C1->elementos[i];
            if(!pertenceConjunto(elemento, C2)){
                insereElementoConjunto(elemento, &diferenca);
            }
        }
    }
    return diferenca;
}

// Função auxiliar pra adicionar um subconjunto ao resultado
void adicionaSubconjunto(Conjunto *resultado, int *subconjunto, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        insereElementoConjunto(subconjunto[i], resultado);
    }
}

// Função auxiliar recursiva pra gerar o conjunto das partes
void geraConjuntoPartesRecursivo(Conjunto *C, Conjunto *resultado, int *subconjunto, int posicao, int inicio) {
    // Adicione o subconjunto atual ao resultado
    adicionaSubconjunto(resultado, subconjunto, posicao);
    
    for (int i = inicio; i < C->tamanho; i++) {
        subconjunto[posicao] = C->elementos[i];
        geraConjuntoPartesRecursivo(C, resultado, subconjunto, posicao + 1, i + 1);
    }
}

// Função pra gerar o conjunto das partes do conjunto C
Conjunto conjuntoPartes(Conjunto *C) {
    Conjunto resultado;
    criaConjunto(&resultado);
    
    if (C != NULL) {
        // Gere o conjunto das partes usando recursão
        int subconjunto[MAX_ELEMENTOS];
        geraConjuntoPartesRecursivo(C, &resultado, subconjunto, 0, 0);
    }
    
    return resultado;
}

//Função pra mostrar os elementos no conjunto
void mostraConjunto(Conjunto *C, int ordem){
    if(C != NULL){
        if(ordem == CRESCENTE){
            printf("{");
            for(int i = 0; i < C->tamanho; i++){
                printf("%ld ", C->elementos[i]);
            }
        }
        else if (ordem == DECRESCENTE){
            printf("{");
            for(int i = C->tamanho - 1; i >= 0; i--){
                printf("%ld ", C->elementos[i]);
            }
        }
        printf("}\n");
    }
}

// Função para copiar um conjunto para outro
int copiarConjunto(Conjunto *C1, Conjunto *C2){
    if (C1 != NULL && C2 != NULL){
        C2->tamanho = C1->tamanho;
        for (int i = 0; i < C1->tamanho; i++){
            C2->elementos[i] = C1->elementos[i];
        }
        return SUCESSO;
    }
    return FALHA;
}

// Função para destruir o conjunto
int destroiConjunto(Conjunto *C){
    if (C != NULL){
        C->tamanho = 0;
        return SUCESSO;
    }
    return FALHA;
}

//==============================================================================
// Corpo Principal
//==============================================================================

#include <stdio.h>

int main(){

    

    return 0;
}