//==============================================================================
// Arquivo ponto.h
//==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

//Define o tamanho máximo de elementos no conjunto
#define MAX_ELEMENTOS 100000 

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
    if(C != NULL && C->tamanho < MAX_ELEMENTOS && x < LONG_MAX && x > LONG_MIN){
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
                for(int j = 0; j < C->tamanho - 1; j++){
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

void printLinha(){
    printf("+------------------------------------------------------------------------+\n");
}

void opcoes(){
    printLinha();
    printf("| [1 ] -> [Criar um conjunto C]                                          |\n");
    printf("| [2 ] -> [Verificar se um conjunto é vazio]                             |\n");
    printf("| [3 ] -> [Inserir um elemento no conjunto]                              |\n");
    printf("| [4 ] -> [Excluir um elemento do conjunto]                              |\n");
    printf("| [5 ] -> [Mostrar os elementos de um conjunto]                          |\n");
    printf("| [6 ] -> [Calcular a cardinalidade de um conjunto]                      |\n");
    printf("| [7 ] -> [Verificar elementos maiores que um número]                    |\n");
    printf("| [8 ] -> [Verificar elementos menores que um número]                    |\n");
    printf("| [9 ] -> [Verificar pertinência de um elemento]                         |\n");
    printf("| [10] -> [Comparar conjuntos idênticos]                                 |\n");
    printf("| [11] -> [Identificar subconjunto]                                      |\n");
    printf("| [12] -> [Gerar complemento de um conjunto]                             |\n");
    printf("| [13] -> [Gerar união de dois conjuntos]                                |\n");
    printf("| [14] -> [Gerar intersecção entre dois conjuntos]                       |\n");
    printf("| [15] -> [Gerar diferença entre dois conjuntos]                         |\n");
    printf("| [16] -> [Gerar conjunto das partes]                                    |\n");
    printf("| [17] -> [Copiar conjunto para outro]                                   |\n");
    printf("| [18] -> [Destruir conjunto]                                            |\n");
}

void boasVindas(){
    printLinha();
    printf("|                    Bem-vindo ao menu de operações                      |\n");
    printf("|                            com Conjuntos!                              |\n");
    printLinha();
    printf("|                          Escolha uma opção:                            |\n");
    opcoes();
}

//==============================================================================
// Corpo Principal
//==============================================================================

int main(){
    boasVindas();
    int escolha;
    while(escolha != 0){
        Conjunto C;
        printLinha();
        printf("| [999] -> [Mostrar opções novamente]                                    |\n");
        printf("| [ 0 ] -> [Encerrar programa]                                           |\n");
        printLinha();

        scanf("%d", &escolha);
        switch (escolha) {
            case 0:
                break;
            case 999:
                opcoes();
                break;
            case 1: {
                int criar = criaConjunto(&C);
                (criar == 1) ? printf("Conjunto criado com sucesso\n") : printf("Erro na criação\n");
                break;
            }
            case 2: {
                int vazio = conjuntoVazio(&C);
                (vazio == 1) ? printf("Conjunto é vazio\n") : printf("Conjunto não é vazio\n");
                break;
            }
            case 3: {
                long int elemento;
                printf("Digite o elemento a ser inserido no conjunto: ");
                scanf("%ld", &elemento);
                int inserido = insereElementoConjunto(elemento, &C);
                (inserido == 1) ? printf("Elemento inserido com sucesso\n") : printf("Erro na inserção do elemento\n");
                break;
            }
            
            case 4: {
                long int elemento;
                printf("Digite o elemento a ser excluido do conjunto: ");
                scanf("%ld", &elemento);
                int excluido = excluirElementoConjunto(elemento, &C);
                (excluido == 1) ? printf("Elemento excluido com sucesso\n") : printf("Erro na exclusão do elemento\n");
                break;
            }

            case 5: {
                printf("Mostrar conjunto de forma Crescente[1] ou Descrescente[2]?: ");
                int cres;
                scanf("%d", &cres);
                switch (cres) {
                    case 1:
                        mostraConjunto(&C, CRESCENTE);
                        break;
                    case 2:
                        mostraConjunto(&C, DECRESCENTE);
                        break;
                    default:
                        printf("Forma inválida, tente novamente!\n");
                        break;
                }
                break;
            }
            case 6: {
                int tamanho = tamanhoConjunto(&C);
                printf("Tamanho do conjunto: %d\n", tamanho);
                break;
            }

            case 7: {
                long int elemento;
                printf("Digite um elemento: ");
                scanf("%ld", &elemento);
                int maiores = maior(elemento, &C);
                printf("Elementos maiores que o número dado: %d\n", maiores);
                printf("(O valor 0 (zero) indica que todos os elementos de C são maiores que x)\n");
                break;
            }
            case 8: {
                long int elemento;
                printf("Digite um elemento: ");
                scanf("%ld", &elemento);
                int menores = menor(elemento, &C);
                printf("Elementos menores que o número dado: %d\n", menores);
                printf("(O valor 0 (zero) indica que todos os elementos de C são maiores que x)\n");
                break;
            }
            case 9: {
                long int elemento;
                printf("Digite um elemento: ");
                scanf("%ld", &elemento);
                int pertence = pertenceConjunto(elemento, &C);
                (pertence == 1) ? printf("O elemento dado pertence ao conjunto\n") : printf("O elemento dado não pertence ao conjunto\n");
                break;
            }

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    }


    return 0;
}