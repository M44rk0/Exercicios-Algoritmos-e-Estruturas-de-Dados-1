//==============================================================================
// Arquivo complexos.h
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
//Define o cabecalho das funcoes
typedef struct complexo Complexo;
typedef struct conjunto Conjunto;
int criaConjunto(Conjunto *C);
int conjuntoVazio(Conjunto *C);
int insereElementoConjunto(Complexo x, Conjunto *C);
int excluirElementoConjunto(Complexo x, Conjunto *C);
int tamanhoConjunto(Conjunto *C);
int pertenceConjunto(Complexo x, Conjunto *C);
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
// Arquivo complexos.c
//==============================================================================

//Define o struct para um numero complexo
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
        C->elementos = (Complexo *)malloc(MAX_ELEMENTOS * sizeof(Complexo));
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
//Funcao para excluir um elemento
int excluirElementoConjunto(Complexo x, Conjunto *C){
    if(C != NULL){
        int encontrado = FALSE;
        for(int i = 0; i<C->tamanho; i++){
            if(C->elementos[i].real == x.real && C->elementos[i].imaginario == x.imaginario){
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
//Funcao para retornar o tamanho
int tamanhoConjunto(Conjunto *C){
    return (C != NULL) ? C->tamanho : 0;
}
//Funcao pra verificar se o elemento X pertence ao conjunto
int pertenceConjunto(Complexo x, Conjunto *C){
    if(C != NULL){
        for(int i = 0; i < C->tamanho; i++){
            if(C->elementos[i].real == x.real && C->elementos[i].imaginario == x.imaginario) return TRUE;
        }return FALSE;
    }return FALSE;
}
//Funcao pra comparar se os conjuntos sao idênticos
int conjuntosIdenticos(Conjunto *C1, Conjunto *C2){
    if(C1 != NULL && C2 != NULL && C1->tamanho == C2->tamanho){
        for(int i = 0; i < C1->tamanho; i++){
            Complexo elemento = C1->elementos[i];
            if(!pertenceConjunto(elemento, C2)) return FALSE;
        }return TRUE;
    }return FALSE;
}
//Funcao pra verificar se C1 e subconjunto de C2
int subConjunto(Conjunto *C1, Conjunto *C2){
    if(C1 != NULL && C2 != NULL){
        for(int i = 0; i < C1->tamanho; i++){
            Complexo elemento = C1->elementos[i];
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
            Complexo elemento = C2->elementos[i];
            
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
            Complexo elemento = C1->elementos[i];
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
            Complexo elemento = C1->elementos[i];
            if(!pertenceConjunto(elemento, C2)) insereElementoConjunto(elemento, &diferenca);
        }
    }return diferenca;
}
//Funcao pra copiar um conjunto para o outro
int copiarConjunto(Conjunto *C1, Conjunto *C2){
    if (C1 != NULL && C2 != NULL){
        C2->tamanho = C1->tamanho;
        for (int i = 0; i < C1->tamanho; i++){
            C2->elementos[i] = C1->elementos[i];
        }return SUCESSO;
    }return FALHA;
}
// Funcao para destruir um conjunto
int destroiConjunto(Conjunto *C){
    if (C != NULL){
        C->tamanho = 0;
        free(C->elementos);
        return SUCESSO;
    }return FALHA;
}
//Funcao para mostrar o conjunto
void mostraConjunto(Conjunto *C, int ordem){
    if(C != NULL){
        if(ordem == CRESCENTE){
            printf("{");
            for(int i = 0; i < C->tamanho; i++){
                if(C->elementos[i].real == 0){
                    printf("%0.lfi, ", C->elementos[i].imaginario);
                }else if(C->elementos[i].imaginario < 0){
                    printf("%.0lf%.0lfi, ", C->elementos[i].real, C->elementos[i].imaginario);
                }else{
                    printf("%.0lf+%.0lfi, ", C->elementos[i].real, C->elementos[i].imaginario);
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
//Funcao auxiliar para remover os espacos de uma String
void removerEspacos(char *entrada, char *saida) {
    int i, j = 0;

    for (i = 0; entrada[i] != '\0'; i++) {
        if (entrada[i] != ' ') {
            saida[j++] = entrada[i];
        }
    }
    saida[j] = '\0';
}
//Funcao auxiliar para ler um complexo
Complexo lerComplexo(){
    char entrada[MAX_ELEMENTOS], saida[MAX_ELEMENTOS];
    Complexo elemento;
    elemento.real = 0.0, elemento.imaginario = 0.0;

    printf("Digite o numero complexo (EX: 4+2i / 5 - 7i / 5i): ");
    fgets(entrada, sizeof(entrada), stdin);
    removerEspacos(entrada, saida);

    int resultado = sscanf(saida, " %lf %c %lf", &elemento.real, &saida[0], &elemento.imaginario);

    if (saida[0] == '-'){
        elemento.imaginario = -elemento.imaginario;
    }

    if (resultado == 2){
        elemento.imaginario = elemento.real, elemento.real = 0;
    } 
    
    else if (resultado != 3){
        printf("Formato de entrada invalido, tente novamente.\n");
        elemento.real = 0.0, elemento.imaginario = 0.0;
    }
    return elemento;
}
//Funcao auxiliar para criar dois conjuntos
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
    char c;
    scanf("%c", &c);
    for(int i = 0; i<quantidade; i++){
        Complexo elemento = lerComplexo();
        (elemento.real == 0.0 && elemento.imaginario == 0.0) ? i-- : insereElementoConjunto(elemento, C1);
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
    scanf("%c", &c);
    for(int i = 0; i<quantidade2; i++){
        Complexo elemento = lerComplexo();
        (elemento.real == 0.0 && elemento.imaginario == 0.0) ? i-- : insereElementoConjunto(elemento, C2);
    }
}
//Funcao pra printar uma linha
void printLinha(){
    printf("+----------------------------------------------------------------------------------------------------+\n");
}
//Funcao pra printar as opcões
void opcoes(){
    printLinha();
    printf("| [ 1] -> [Criar um conjunto C]                    | [ 9] -> [Identificar subconjunto]               |\n");
    printf("| [ 2] -> [Verificar se o conjunto C e vazio]      | [10] -> [Gerar complemento de um conjunto]      |\n");
    printf("| [ 3] -> [Inserir um elemento no conjunto C]      | [11] -> [Gerar uniao de dois conjuntos]         |\n");
    printf("| [ 4] -> [Excluir um elemento do conjunto C]      | [12] -> [Gerar intersecao entre dois conjuntos] |\n");
    printf("| [ 5] -> [Mostrar os elementos do conjunto C]     | [13] -> [Gerar diferenca entre dois conjuntos]  |\n");
    printf("| [ 6] -> [Calcular a cardinalidade do conjunto C] | [14] -> [Copiar um conjunto para outro]         |\n");
    printf("| [ 7] -> [Verificar pertinencia de um elemento]   | [15] -> [Destruir conjunto]                     |\n");
    printf("| [ 8] -> [Comparar conjuntos identicos]           |                                                 |\n");
}
//Funcao pra printar boas vindas
void boasVindas(){
    printLinha();
    printf("                 _             _              _                                  _                    \n");
    printf("                (_)           | |            | |                                | |                   \n");
    printf("  ___ ___  _ __  _ _   _ _ __ | |_ ___     __| | ___    ___ ___  _ __ ___  _ __ | | _____  _____  ___ \n");
    printf(" / __/ _ \\| '_ \\| | | | | '_ \\| __/ _ \\   / _` |/ _ \\  / __/ _ \\| '_ ` _ \\| '_ \\| |/ _ \\ \\/ / _ \\/ __|\n");
    printf("| (__ (_) | | | | | |_| | | | | |_ (_) | | (_| |  __/ | (__ (_) | | | | | | |_) | |  __/>  < (_) \\__ \\\n");
    printf(" \\___\\___/|_| |_|_|\\__,_|_| |_|\\__\\___/   \\__,_|\\___|  \\___\\___/|_| |_| |_| .__/|_|\\___/_/\\_\\___/|___/\n");
    printf("               _/ |                                                       | |                         \n");
    printf("              |__/                                                        |_|                         \n");
    printLinha();
    printf("|                                          Escolha uma opcao:                                        |\n");
    opcoes();
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
        printf("|                 [999] -> [Mostrar opcoes novamente] | [ 0 ] -> [Encerrar programa]                 |\n");
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
                if (criadoC){
                    char c;
                    scanf("%c", &c); // scan pra ler o 'enter' dado apos o case pra ele nao ser lido pelo o fgets do lerComplexo()
                    Complexo elemento = lerComplexo();
                    if (elemento.real == 0.0 && elemento.imaginario == 0.0) {
                        break;
                    } 
                    else{
                    (insereElementoConjunto(elemento, &C) == 1) ? printf("Elemento inserido com sucesso\n") : printf("Erro na insercao do elemento\n");
                    break;
                    }
                }else{printf("Erro, conjunto C ainda nao foi criado\n");
                }break;
            }
            case 4: {
                if(criadoC){
                    char c;
                    scanf("%c", &c); // scan pra ler o 'enter' dado apos o case pra ele nao ser lido pelo o fgets do lerComplexo()
                    Complexo elemento = lerComplexo();
                    if (elemento.real == 0.0 && elemento.imaginario == 0.0) {
                        break;
                    } 
                    else{
                    (excluirElementoConjunto(elemento, &C) == 1) ? printf("Elemento excluido com sucesso\n") : printf("Erro na exclusao do elemento\n");
                    break;
                    }
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
                }
                printf("Erro, conjunto C ainda nao foi criado\n");
                break;
            }
            case 7: {
                if(criadoC && conjuntoVazio(&C) == 0){
                    char c;
                    scanf("%c", &c); // scan pra ler o enter dado apos o case pra ele nao ser lido pelo o fgets do lerComplexo()
                    Complexo elemento = lerComplexo();
                    if (elemento.real == 0.0 && elemento.imaginario == 0.0) {
                        break;
                    } 
                    else{
                (pertenceConjunto(elemento, &C) == 1) ? printf("O elemento dado pertence ao conjunto\n") : printf("O elemento dado nao pertence ao conjunto\n");
                break;
                }
                }printf("Erro, conjunto C ainda nao foi criado ou e vazio\n");
                break;
            }
            case 8: {
                AuxiliarCriarC1C2(&C1, &C2);
                (conjuntosIdenticos(&C1, &C2) == 1) ? printf("Os conjuntos sao identicos\n") : printf("Os conjuntos nao sao identicos\n");
                break;
            }
            case 9: {
                AuxiliarCriarC1C2(&C1, &C2);
                (subConjunto(&C1, &C2) == 1) ? printf("C1 e subconjunto de C2\n") : printf("C1 nao e subconjunto de C2\n");
                break;
            }
            case 10: {
                AuxiliarCriarC1C2(&C1, &C2);
                Conjunto complementoC1;
                complementoC1 = complemento(&C1, &C2);
                mostraConjunto(&complementoC1, CRESCENTE);
                break;
            }
            case 11: {
                AuxiliarCriarC1C2(&C1, &C2);
                Conjunto uniaoC1 = uniao(&C1, &C2);
                mostraConjunto(&uniaoC1, CRESCENTE);
                break;
            }
            case 12: {
                AuxiliarCriarC1C2(&C1, &C2);
                Conjunto interseccaoC1 = interseccao(&C1, &C2);
                mostraConjunto(&interseccaoC1, CRESCENTE);
                break;
            }
            case 13: {
                AuxiliarCriarC1C2(&C1, &C2);
                Conjunto diferencaC1 = diferenca(&C1, &C2);
                mostraConjunto(&diferencaC1, CRESCENTE);
                break;
            }
            case 14: {
                AuxiliarCriarC1C2(&C1, &C2);
                if(copiarConjunto(&C1, &C2) == 1){
                    printf("Copiado com sucesso!\n");
                    mostraConjunto(&C2, CRESCENTE);
                }else{printf("Erro na copia\n");
                }break;
            }
            case 15: {
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
                printf("Opcao invalida\n");
                break;
        }
    }
    return 0;
}