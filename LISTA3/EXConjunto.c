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
// Arquivo conjunto.c
//==============================================================================

//Define o struct Conjunto
struct conjunto{
    int tamanho;
    long int *elementos;
};
//Funcao para criar um conjunto vazio
int criaConjunto(Conjunto *C){
    if(C != NULL){
        C->elementos = (long int *)malloc(MAX_ELEMENTOS * sizeof(long int));
        C->tamanho = 0;
        return SUCESSO;
    }return FALHA;
}
//Funcao pra ver se o conjunto esta vazio
int conjuntoVazio(Conjunto *C){
    return (C != NULL && C->tamanho == 0) ? TRUE : FALSE;
}
//Funcao pra iserir um elemento no conjunto
int insereElementoConjunto(long int x, Conjunto *C){
    if(C != NULL && C->tamanho < MAX_ELEMENTOS && x < LONG_MAX && x > LONG_MIN){
        for(int i = 0; i < C->tamanho; i++){
            if(C->elementos[i] == x) return FALHA; //elemento ja existe no conjunto
        }
        C->elementos[C->tamanho] = x, C->tamanho++;
        return SUCESSO;
    }return FALHA;
}
//Funcao pra exlucir um elemento do conjunto
int excluirElementoConjunto(long int x, Conjunto *C){
    if(C != NULL){
        int encontrado = FALSE;
        for(int i = 0; i<C->tamanho; i++){
            if(C->elementos[i] == x){
                encontrado = TRUE;
                //move os elementos a direita do elemento que vai ser excluido
                for(int j = 0; j < C->tamanho - 1; j++){
                    C->elementos[j] = C->elementos[j+1];
                }
                C->tamanho--;
                break;
            }
        }return encontrado ? SUCESSO : FALHA;
    }return FALHA;
}
//Funcao pra calcular a cardinalidade do conjunto
int tamanhoConjunto(Conjunto *C){
    return (C != NULL) ? C->tamanho : 0;
}
//Funcao pra ver a quantidade de elementos maiores que X no conjunto
int maior(long int x, Conjunto *C){
    int maiores = 0;
    if(C != NULL){
        for(int i = 0; i < C->tamanho; i++){
            if(C->elementos[i] > x){
                maiores++;
            }
        }
        if(C->tamanho == maiores) return 0;
    }return maiores;
}
//Funcao pra ver a quantidade de elementos menores que X no conjunto 
int menor(long int x, Conjunto *C){
    int menores = 0;
    if(C != NULL){
        for(int i = 0; i < C->tamanho; i++){
            if(C->elementos[i] < x){
                menores++;
            }
        }
        if(C->tamanho == menores) return 0;
    }return menores;
}
//Funcao pra verificar se o elemento X pertence ao conjunto
int pertenceConjunto(long int x, Conjunto *C){
    if(C != NULL){
        for(int i = 0; i < C->tamanho; i++){
            if(C->elementos[i] == x) return TRUE;
        }return FALSE;
    }return FALSE;
}
//Funcao pra comparar se os conjuntos sao idênticos
int conjuntosIdenticos(Conjunto *C1, Conjunto *C2){
    if(C1 != NULL && C2 != NULL && C1->tamanho == C2->tamanho){
        for(int i = 0; i < C1->tamanho; i++){
            long int elemento = C1->elementos[i];
            if(!pertenceConjunto(elemento, C2)) return FALSE;
        }return TRUE;
    }return FALSE;
}
//Funcao pra verificar se C1 e subconjunto de C2
int subConjunto(Conjunto *C1, Conjunto *C2){
    if(C1 != NULL && C2 != NULL){
        for(int i = 0; i < C1->tamanho; i++){
            long int elemento = C1->elementos[i];
            if(!pertenceConjunto(elemento, C2)) return FALSE;
        }return TRUE;
    }return FALSE;
}
//Funcao pra gerar o complemento de C1 em relacao a C2
Conjunto complemento(Conjunto *C1, Conjunto *C2){
    Conjunto complemento;
    criaConjunto(&complemento);

    if(C1 != NULL && C2 != NULL){
        for(int i = 0; i < C2->tamanho; i++){
            long int elemento = C2->elementos[i];
            if(!pertenceConjunto(elemento, C1)) insereElementoConjunto(elemento, &complemento);
        }
    }return complemento;
}
//Funcao pra gerar a uniao de C1 com C2
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
    }return uniao;
}
//Funcao pra gerar a interseccao de C1 com C2
Conjunto interseccao(Conjunto *C1, Conjunto *C2){
    Conjunto interseccao;
    criaConjunto(&interseccao);

    if(C1 != NULL && C2 != NULL){
        for(int i = 0; i < C1->tamanho; i++){
            long int elemento = C1->elementos[i];
            if(pertenceConjunto(elemento, C2)) insereElementoConjunto(elemento, &interseccao);
            
        }
    }return interseccao;
}
//Funcao pra gerar a diferenca de C1 e C2
Conjunto diferenca(Conjunto *C1, Conjunto *C2){
    Conjunto diferenca;
    criaConjunto(&diferenca);

    if(C1 != NULL && C2 != NULL){
        for(int i = 0; i < C1->tamanho; i++){
            long int elemento = C1->elementos[i];
            if(!pertenceConjunto(elemento, C2)) insereElementoConjunto(elemento, &diferenca);
        }
    }return diferenca;
}
//Sinceramente essa aqui eu nem consegui pensar em como fazer 
// um beijao pro GPT <3
Conjunto conjuntoPartes(Conjunto *C) {
    Conjunto resultado;
    criaConjunto(&resultado);
    
    if (C != NULL) {
        int n = C->tamanho;
        int numSubconjuntos = pow(2, n);
        
        for (int i = 0; i < numSubconjuntos; i++) {
            criaConjunto(&resultado);

            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) insereElementoConjunto(C->elementos[j], &resultado);
            }mostraConjunto(&resultado, CRESCENTE);
        }
    }return resultado;
}
//Funcao pra mostrar os elementos no conjunto
void mostraConjunto(Conjunto *C, int ordem){
    if(C != NULL){
        if(ordem == CRESCENTE){
            printf("{");
            for(int i = 0; i < C->tamanho; i++){
                printf("%ld ", C->elementos[i]);
            }
        }else if (ordem == DECRESCENTE){
            printf("{");
            for(int i = C->tamanho - 1; i >= 0; i--){
                printf("%ld ", C->elementos[i]);
            }
        }printf("}\n");
    }
}
// Funcao para copiar um conjunto para outro
int copiarConjunto(Conjunto *C1, Conjunto *C2){
    if (C1 != NULL && C2 != NULL){
        C2->tamanho = C1->tamanho;
        for (int i = 0; i < C1->tamanho; i++){
            C2->elementos[i] = C1->elementos[i];
        }return SUCESSO;
    }return FALHA;
}
// Funcao para destruir o conjunto
int destroiConjunto(Conjunto *C){
    if (C != NULL){
        C->tamanho = 0;
        free(C->elementos);
        return SUCESSO;
    }return FALHA;
}
//Funcao pra printar linha :O
void printLinha(){
    printf("+-------------------------------------------------------------------------------------------------------+\n");
}
//Funcao pra printar as opcões :O
void opcoes(){
    printLinha();
    printf("| [ 1] -> [Criar um conjunto C]                       | [18] -> [Destruir conjunto]                     |\n");
    printf("| [ 2] -> [Verificar se o conjunto C e vazio]         | [10] -> [Gerar conjunto das partes]             |\n");
    printf("| [ 3] -> [Inserir um elemento no conjunto C]         | [11] -> [Comparar conjuntos identicos]          |\n");
    printf("| [ 4] -> [Excluir um elemento do conjunto C]         | [12] -> [Identificar subconjunto]               |\n");
    printf("| [ 5] -> [Mostrar os elementos do conjunto C]        | [13] -> [Gerar complemento de um conjunto]      |\n");
    printf("| [ 6] -> [Calcular a cardinalidade do conjunto C]    | [14] -> [Gerar uniao de dois conjuntos]         |\n");
    printf("| [ 7] -> [Verificar elementos maiores que um numero] | [15] -> [Gerar intersecao entre dois conjuntos] |\n");
    printf("| [ 8] -> [Verificar elementos menores que um numero] | [16] -> [Gerar diferenca entre dois conjuntos]  |\n");
    printf("| [ 9] -> [Verificar pertinencia de um elemento]      | [17] -> [Copiar conjunto para outro]            |\n");
}
//Funcao pra printar boas vindas :O
void boasVindas(){
    printLinha();
    printf("|            ░█▀█░█▀█░█▀▀░█▀█░█▀█░█▀▀░█▀█░█▀█░░░█▀▀░█▀█░█▄█░░░█▀▀░█▀█░▀▀█░█░█░█▀█░▀█▀░█▀█░█▀▀           |\n");
    printf("|            ░█░█░█▀▀░█▀▀░█▀▄░█▀█░█░░░█▀█░█░█░░░█░░░█░█░█░█░░░█░░░█░█░░░█░█░█░█░█░░█░░█░█░▀▀█           |\n");
    printf("|            ░▀▀▀░▀░░░▀▀▀░▀░▀░▀░▀░▀▀▀░▀░▀░▀▀▀░░░▀▀▀░▀▀▀░▀░▀░░░▀▀▀░▀▀▀░▀▀░░▀▀▀░▀░▀░░▀░░▀▀▀░▀▀▀           |\n");
    printLinha();
    printf("|                                         Escolha uma opcao:                                            |\n");
    opcoes();
}
//Funcao auxiliar pra criar o conjunto C1 e conjunto C2
void AuxiliarCriarC1C2(Conjunto *C1, Conjunto *C2){
    criaConjunto(C1), criaConjunto(C2);
    printf("Quantos elementos em C1?: ");
    int quantidade;
    while(1){
        scanf("%d", &quantidade);
        if(quantidade <= 0){
            printf("Quantidade invalida, tente novamente.\n");
            printf("Quantos elementos em C1?: ");
        }else{break;};
    }
    printf("Digite os elementos a serem inseridos em C1:\n");
    for(int i = 0; i<quantidade; i++){
        long int elemento;
        printf("%d elemento: ", i+1);
        scanf("%ld", &elemento);
        insereElementoConjunto(elemento, C1);
    }
    printf("Quantos elementos em C2?: ");
    int quantidade2;
    while(1){
        scanf("%d", &quantidade2);
        if(quantidade2 <= 0){
            printf("Quantidade invalida, tente novamente\n");
            printf("Quantos elementos em C2?: ");
        }else{break;};
    }
    printf("Digite os elementos a serem inseridos em C2:\n");
    for(int i = 0; i<quantidade2; i++){
        long int elemento2;
        printf("%d° elemento: ", i+1);
        scanf("%ld", &elemento2);
        insereElementoConjunto(elemento2, C2);
    }
}

//==============================================================================
// Corpo Principal
//==============================================================================

int main(){
    boasVindas();
    int escolha, criadoC = 0;
    while(escolha != 0){
        Conjunto C, C1, C2;
        printLinha();
        printf("|                [999] -> [Mostrar opcoes novamente] | [ 0 ] -> [Encerrar programa]                     |\n");
        printLinha();
        scanf("%d", &escolha);
        switch (escolha){
            case 999: {
                opcoes();
                break;
            }
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
                if(criadoC){
                long int elemento;
                printf("Digite o elemento a ser inserido no conjunto: ");
                scanf("%ld", &elemento);
                (insereElementoConjunto(elemento, &C) == 1) ? printf("Elemento inserido com sucesso\n") : printf("Erro na insercao do elemento\n");
                break;
                }printf("Erro, conjunto C ainda nao foi criado\n");
                break;
            }
            case 4: {
                if(criadoC){
                long int elemento;
                printf("Digite o elemento a ser excluido do conjunto: ");
                scanf("%ld", &elemento);
                (excluirElementoConjunto(elemento, &C) == 1) ? printf("Elemento excluido com sucesso\n") : printf("Erro na exclusao do elemento\n");
                break;
                }printf("Erro, conjunto C ainda nao foi criado\n");
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
            case 6: {
                if(criadoC){
                printf("Tamanho do conjunto: %d\n", tamanhoConjunto(&C));
                break;
                }printf("Erro, conjunto C ainda nao foi criado\n");
                break;
            }
            case 7: {
                if(criadoC && conjuntoVazio(&C) == 0){
                long int elemento;
                printf("Digite um elemento: ");
                scanf("%ld", &elemento);
                printf("Elementos maiores que o numero dado: %d\n", maior(elemento, &C));
                printf("(O valor 0 (zero) indica que todos os elementos de C sao maiores que x)\n");
                break;
                }printf("Erro, conjunto C ainda nao foi criado ou e vazio\n");
                break;
            }
            case 8: {
                if(criadoC && conjuntoVazio(&C) == 0){
                long int elemento;
                printf("Digite um elemento: ");
                scanf("%ld", &elemento);
                printf("Elementos menores que o numero dado: %d\n", menor(elemento, &C));
                printf("(O valor 0 (zero) indica que todos os elementos de C sao maiores que x)\n");
                break;
                }printf("Erro, conjunto C ainda nao foi criado ou e vazio\n");
                break;
            }
            case 9: {
                if(criadoC && conjuntoVazio(&C) == 0){
                long int elemento;
                printf("Digite um elemento: ");
                scanf("%ld", &elemento);
                (pertenceConjunto(elemento, &C) == 1) ? printf("O elemento dado pertence ao conjunto\n") : printf("O elemento dado nao pertence ao conjunto\n");
                break;
                }printf("Erro, conjunto C ainda nao foi criado ou e vazio\n");
                break;
            }
            case 10: {
                if(criadoC){
                conjuntoPartes(&C);
                break;
                }printf("Erro, conjunto C ainda nao foi criado\n");
                break;
            }
            case 11: {
                AuxiliarCriarC1C2(&C1, &C2);
                (conjuntosIdenticos(&C1, &C2) == 1) ? printf("Os conjuntos sao identicos\n") : printf("Os conjuntos nao sao identicos\n");
                break;
            }
            case 12: {
                AuxiliarCriarC1C2(&C1, &C2);
                (subConjunto(&C1, &C2) == 1) ? printf("C1 e subconjunto de C2\n") : printf("C1 nao e subconjunto de C2\n");
                break;
            }
            case 13: {
                AuxiliarCriarC1C2(&C1, &C2);
                Conjunto complementoC1;
                complementoC1 = complemento(&C1, &C2);
                mostraConjunto(&complementoC1, CRESCENTE);
                break;
            }
            case 14: {
                AuxiliarCriarC1C2(&C1, &C2);
                Conjunto uniaoC1 = uniao(&C1, &C2);
                mostraConjunto(&uniaoC1, CRESCENTE);
                break;
            }
            case 15: {
                AuxiliarCriarC1C2(&C1, &C2);
                Conjunto interseccaoC1 = interseccao(&C1, &C2);
                mostraConjunto(&interseccaoC1, CRESCENTE);
                break;
            }
            case 16: {
                AuxiliarCriarC1C2(&C1, &C2);
                Conjunto diferencaC1 = diferenca(&C1, &C2);
                mostraConjunto(&diferencaC1, CRESCENTE);
                break;
            }
            case 17: {
                AuxiliarCriarC1C2(&C1, &C2);
                if(copiarConjunto(&C1, &C2) == 1){
                    printf("Copiado com sucesso!\n");
                    mostraConjunto(&C2, CRESCENTE);
                }else{printf("Erro na copia\n");
                }break;
            }
            case 18: {
                printf("Qual conjunto destruir? (C = 0, C1 & C2 = 1): \n");
                int opcao;
                scanf("%d", &opcao);
                switch (opcao){
                case 0: {
                    criadoC = 0;
                    (destroiConjunto(&C) == 1) ? printf("Conjunto C destruido com sucesso\n") : printf("Erro na destruicao do Conjunto C\n");
                    break;
                }
                case 1: {
                    (destroiConjunto(&C1) == 1 && destroiConjunto(&C2) == 1) ? printf("Conjunto C1 e C2 destruidos com sucesso\n") : printf("Erro na destruicao dos Conjuntos\n");
                    break;
                }
                default:
                    printf("Opcao invalida. Tente novamente.\n");
                    break;
                }break;
            }
            case 0: {
                destroiConjunto(&C), destroiConjunto(&C1), destroiConjunto(&C2);
                break;
            }
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    }
    return 0;
}