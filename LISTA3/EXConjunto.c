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
Conjunto* complemento(Conjunto *C1, Conjunto *C2);
Conjunto* uniao(Conjunto *C1, Conjunto *C2);
Conjunto* interseccao(Conjunto *C1, Conjunto *C2);
Conjunto* diferenca(Conjunto *C1, Conjunto *C2);
Conjunto* conjuntoPartes(Conjunto *C);
void mostraConjunto(Conjunto *C, Ordem ordem);
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
    return (C == NULL) ? 1 : 0; 
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
                // Move os conjunto para preencher o espaço
                C->conjunto[j] = C->conjunto[j + 1];
            }
            C->tamanho--; // Decrementa o tamanho do conjunto
            return 1; // Elemento removido
        }
    }
    return 0; // Elemento não foi encontrado
}

int tamanhoConjunto(Conjunto *C){
   return (C == NULL) ? 0 : C->tamanho;
}

int maior(long int x, Conjunto *C){
    long int maiores = 0;
    for (int i = 0; i < C->tamanho; i++){
        if(C->conjunto[i] > x){
            maiores++; //Contagem de quantos conjunto são maiores que X
        }
    }
    return(C->tamanho == maiores) ? 0 : maiores;// Se o tamanho for engual ao número de conjunto maiores que X, todos são maiores que X
}

int menor(long int x, Conjunto *C){
    long int menores = 0;
    for (int i = 0; i < C->tamanho; i++){
        if(C->conjunto[i] < x){
            menores++; //Contagem de quantos conjunto são maiores que X
        }
    }
    return(C->tamanho == menores) ? 0 : menores;
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

int subconjunto(Conjunto *C1, Conjunto *C2) {
    if (C1 == NULL) {
        return 0; // Um conjunto nulo é subconjunto de qualquer conjunto
    }

    if (C2 == NULL || C1->tamanho > C2->tamanho) {
        return 0; // Se C2 é nulo ou tem tamanho menor que C1, C1 não pode ser subconjunto de C2
    }

    for (int i = 0; i < C1->tamanho; i++) {
        int elementoC1 = C1->conjunto[i];
        int encontrado = 0; // Variável para rastrear se o elemento foi encontrado em C2

        for (int j = 0; j < C2->tamanho; j++) {
            if (elementoC1 == C2->conjunto[j]) {
                encontrado = 1; // Elemento encontrado em C2
                break; // Não é necessário continuar procurando
            }
        }

        if (!encontrado) {
            return 0; // Elemento de C1 não encontrado em C2, C1 não é subconjunto de C2
        }
    }
    return 1; // Se nenhum dos casos anteriores ocorrer, C1 é um subconjunto de C2
}

Conjunto* complemento(Conjunto *C1, Conjunto *C2) {
    if (C1 == NULL || C2 == NULL) {
        return NULL; // Não é possível calcular o complemento se algum dos conjuntos for nulo
    }

    Conjunto *resultado = criaConjunto(resultado); // Crie um conjunto vazio para armazenar o complemento

    for (int i = 0; i < C2->tamanho; i++) {
        int elementoC2 = C2->conjunto[i];
        int encontrado = 1; // Variável para rastrear se o elemento foi encontrado em C1

        for (int j = 0; j < C1->tamanho; j++) {
            if (elementoC2 == C1->conjunto[j]) {
                encontrado = 1; // Elemento encontrado em C1
                break; // Não é necessário continuar procurando
            }
        }

        if (!encontrado) {
            insereElementoConjunto(elementoC2, resultado); // Adicione o elemento ao conjunto resultado
        }
    }
    return resultado;
}

Conjunto* uniao(Conjunto *C1, Conjunto *C2) {
    if (C1 == NULL || C2 == NULL) {
        return NULL; // Não é possível calcular a união se algum dos conjuntos for nulo
    }

    Conjunto *resultado = criaConjunto(resultado); // Crie um conjunto vazio para armazenar a união

    // Inserir conjunto de C1 no conjunto resultado
    for (int i = 0; i < C1->tamanho; i++) {
        insereElementoConjunto(C1->conjunto[i], resultado);
    }

    // Inserir conjunto de C2 no conjunto resultado (se não estiverem presentes em C1)
    for (int i = 0; i < C2->tamanho; i++) {
        int elementoC2 = C2->conjunto[i];
        int encontrado = 0;

        for (int j = 0; j < C1->tamanho; j++) {
            if (elementoC2 == C1->conjunto[j]) {
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            insereElementoConjunto(elementoC2, resultado);
        }
    }
    return resultado;
}

Conjunto* interseccao(Conjunto *C1, Conjunto *C2) {
    if (C1 == NULL || C2 == NULL) {
        return NULL; // Não é possível calcular a interseção se algum dos conjuntos for nulo
    }

    Conjunto *resultado = criaConjunto(resultado); // Crie um conjunto vazio para armazenar a interseção

    // Iterar pelos conjunto de C1
    for (int i = 0; i < C1->tamanho; i++) {
        int elementoC1 = C1->conjunto[i];

        // Verificar se o elemento está presente em C2
        for (int j = 0; j < C2->tamanho; j++) {
            if (elementoC1 == C2->conjunto[j]) {
                insereElementoConjunto(elementoC1, resultado);
                break; // Elemento encontrado, não é necessário continuar procurando em C2
            }
        }
    }
    return resultado;
}

Conjunto* diferenca(Conjunto *C1, Conjunto *C2) {
    if (C1 == NULL) {
        return 0; // Não é possível calcular a diferença se C1 for nulo
    }

    Conjunto *resultado = criaConjunto(resultado); // Crie um conjunto vazio para armazenar a diferença

    // Iterar pelos conjunto de C1
    for (int i = 0; i < C1->tamanho; i++) {
        int elementoC1 = C1->conjunto[i];
        int pertenceC2 = 0; // Variável para verificar se o elemento pertence a C2

        if (C2 != NULL) {
            // Verificar se o elemento está presente em C2
            for (int j = 0; j < C2->tamanho; j++) {
                if (elementoC1 == C2->conjunto[j]) {
                    pertenceC2 = 1; // Elemento encontrado em C2
                    break;
                }
            }
        }

        if (!pertenceC2) {
            insereElementoConjunto(elementoC1, resultado);
        }
    }
    return resultado;
}

Conjunto* conjuntoPartes(Conjunto *C) {
    if (C == NULL) {
        return 0; // Conjunto nulo
    }

    int numSubconjuntos = 1 << C->tamanho; // 2 elevado à potência do tamanho do conjunto
    Conjunto *partes = criaConjunto(partes);

    for (int i = 0; i < numSubconjuntos; i++) {
        Conjunto *subconjunto = criaConjunto(subconjunto);
        for (int j = 0; j < C->tamanho; j++) {
            if (i & (1 << j)) {
                insereElementoConjunto(C->conjunto[j], subconjunto);
            }
        }
        insereElementoConjunto((int)subconjunto, partes); // Adiciona o subconjunto ao conjunto das partes
        free(subconjunto);
    }
    return partes;
}

typedef enum {
    CRESCENTE,
    DECRESCENTE
} Ordem;

int compararconjunto(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void mostraConjunto(Conjunto *C, Ordem ordem) {
    if (C == NULL || C->tamanho == 0) {
        printf("Conjunto vazio\n");
        return 0;
    }

    if (ordem == CRESCENTE) {
        qsort(C->conjunto, C->tamanho, sizeof(int), compararconjunto);
    } else if (ordem == DECRESCENTE) {
        qsort(C->conjunto, C->tamanho, sizeof(int), compararconjunto);
        for (int i = 0; i < C->tamanho / 2; i++) {
            int temp = C->conjunto[i];
            C->conjunto[i] = C->conjunto[C->tamanho - 1 - i];
            C->conjunto[C->tamanho - 1 - i] = temp;
        }
    }

    printf("{ ");
    for (int i = 0; i < C->tamanho; i++) {
        printf("%d ", C->conjunto[i]);
    }
    printf("}\n");
}

int copiarConjunto(Conjunto *C1, Conjunto *C2) {
    if (C1 == NULL || C2 == NULL) {
        return 0; // Verifica se os conjuntos são válidos
    }

    if (C1->tamanho == 0) {
        return 0; // Nada a copiar se C1 está vazio
    }

    C2->tamanho = C1->tamanho;
    C2->conjunto = (int *)malloc(C1->tamanho * sizeof(int));

    if (C2->conjunto == NULL) {
        return 0; // Falha na alocação de memória
    }

    for (int i = 0; i < C1->tamanho; i++) {
        C2->conjunto[i] = C1->conjunto[i];
    }
    return 1;
}

int destroiConjunto(Conjunto *C) {
    if (C != NULL) {
        free(C->conjunto); // Libera a memória dos conjunto
        free(C); // Libera a memória do conjunto
        return 1;
    }
    return 0;
}

