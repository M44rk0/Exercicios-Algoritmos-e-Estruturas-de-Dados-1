#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

//==============================================================================
// Arquivo ponto.h
//==============================================================================

typedef struct conjunto Conjunto;
int criaConjunto(Conjunto *C);
int conjuntoVazio(Conjunto *C);
int insereElementoConjunto(long int x , Conjunto *C);
int excluirElementoConjunto(long int x , Conjunto *C);
int tamanhoConjunto(Conjunto *C);
int maior(long int x, Conjunto *C);
int menor(long int x, Conjunto *C);
int pertenceConjunto(long int x, Conjunto *C);
int conjuntosIdenticos(Conjunto *C1, Conjunto *C2);
int subconjunto(Conjunto *C1, Conjunto *C2);
Conjunto complemento(Conjunto *C1, Conjunto *C2);
Conjunto uniao(Conjunto *C1, Conjunto *C2);
Conjunto interseccao(Conjunto *C1, Conjunto *C2);
Conjunto diferenca(Conjunto *C1, Conjunto *C2);
Conjunto conjuntoPartes(Conjunto *C);
void mostraConjunto(Conjunto *C, char* ordem);
int copiarConjunto(Conjunto *C1, Conjunto *C2);
int destroiConjunto(Conjunto *C);

//==============================================================================
// Arquivo ponto.c
//==============================================================================

struct conjunto{
    int tamanho;
    int conjunto[1000000];
};

int criaConjunto(Conjunto *C) {
    if (C == NULL) {
        return 0; // Falha
    }

    C->tamanho = 0; // Inicializa o tamanho como zero
    return 1; // Sucesso
}

int conjuntoVazio(Conjunto *C){
    if(C == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int insereElementoConjunto(long int x, Conjunto *C){
    if(x >= LONG_MAX || C->tamanho >=1000000){
        return 0; // Elemento é maior que o permitido ou o conjunto já está cheio
    }

    for (int i = 0; i < C->tamanho; i++) {
        if (C->conjunto[i] == x) {
            return 0; // Elemento já tá no conjunto
        }
    }

    C->conjunto[C->tamanho] = x;
    C->tamanho++;

    return 1;

}

int excluirElementoConjunto(long int x, Conjunto *C) {
    if (C == NULL) {
        return 0; // Se o conjunto for nulo
    }

    for (int i = 0; i < C->tamanho; i++) {
        if (C->conjunto[i] == x) {
            // Encontrou o elemento pra remover
            for (int j = i; j < C->tamanho - 1; j++) {
                // Move os elementos para preencher o espaço
                C->conjunto[j] = C->conjunto[j + 1];
            }

            C->tamanho--; // Decrementa o tamanho do conjunto
            return 1; // Elemento removido
        }
    }

    return 0; // Elemento não foi encontrado
}

int tamanhoConjunto(Conjunto *C){
    if(C == NULL){
        return 0; //Conjunto vazio
    }

    return C->tamanho;
}

int maior(long int x, Conjunto *C){
    long int maiores = 0;
    for (int i = 0; i < C->tamanho; i++){
        if(C->conjunto[i] > x){
            maiores++; //Contagem de quantos elementos são maiores que X
        }
    }

    if(C->tamanho == maiores){
        return 0; // Se o tamanho for engual ao número de elementos maiores que X, todos são maiores que X
    }
    else{
        return maiores; 
    }   
}

int menor(long int x, Conjunto *C){
    long int menores = 0;
    for (int i = 0; i < C->tamanho; i++){
        if(C->conjunto[i] < x){
            menores++; //Contagem de quantos elementos são maiores que X
        }
    }

    if(C->tamanho == menores){
        return 0; // Se o tamanho for engual ao número de elementos menores que X, todos são menores
    }
    else{
        return menores; 
    }   
}

pertenceConjunto(long int x, Conjunto *C){
    for (int i = 0; i < C->tamanho; i++){
        if(C->conjunto[i] == x){
            return 0; //Elemento encontrado
        }
        return 1;
    }
}

int conjuntosIdenticos(Conjunto *C1, Conjunto *C2) {
    if (C1 == NULL || C2 == NULL) {
        return 1; // Se algum dos conjuntos for nulo, eles não são idênticos
    }

    if (C1->tamanho != C2->tamanho) {
        return 0; // Se os tamanhos dos conjuntos forem diferentes, eles não são idênticos
    }

    for (int i = 0; i < C1->tamanho; i++) {
        if (C1->conjunto[i] != C2->conjunto[i]) {
            return 0; // Se algum elemento for diferente, os conjuntos não são idênticos
        }
    }

    return 1; // Se nenhum dos casos acima foi satisfeito, os conjuntos são idênticos
}