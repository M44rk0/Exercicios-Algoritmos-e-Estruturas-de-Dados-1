//==============================================================================
// Arquivo texto.h
//==============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Define as constantes
#define SUCESSO 1
#define FALHA 0
#define IGUAL 0
#define MENOR -1
#define MAIOR 1
//Define o cabecalho das funcoes
typedef struct texto Texto;
Texto *criarTexto(char *t);
void liberarTexto(Texto *t);
unsigned int tamanhoTexto(Texto *t);
char *obterTexto(Texto *t);
void mostrarTexto(Texto *t, unsigned int colunas);
Texto *copiarTexto(Texto *t);
void substituirTexto(Texto *t, char *alteracao);
Texto *concatenarTextos(Texto *t1, Texto *t2);
char *obterSubtexto(Texto *t, unsigned int inicio, unsigned int tamanho);
unsigned int encontrarSubtexto(Texto *t, char *subtexto, unsigned int ocorrencia);
int compararTextos(Texto *t1, Texto *t2);
//==============================================================================
// Arquivo pilha.c
//==============================================================================
struct texto{
    char *conteudo;
};
//Funcao que cria um texto a partir de uma string lida
Texto *criarTexto(char *t){
    Texto *novoTexto = (Texto *)malloc(sizeof(Texto));
    novoTexto->conteudo = strdup(t);
    return novoTexto;
}
//Funcao pra limpar a alocação do Texto
void liberarTexto(Texto *t){
    if(t != NULL){
        free(t);
    }
}
//Funcao pra obter o tamanho do texto
unsigned int tamanhoTexto(Texto *t){
    return strlen(t->conteudo);
}
//Funcao pra obter a string do texto
char *obterTexto(Texto *t){
    return t->conteudo;
}
//Funcao pra mostrar o texto
void mostrarTexto(Texto *t, unsigned int colunas){
    unsigned int i;
    for(i = 0; i < strlen(t->conteudo); i++){
        putchar(t->conteudo[i]);
        if((i+1) % colunas == 0){
            putchar('\n');
        }
    }
    putchar('\n');
}
//Funcao pra copiar o texto
Texto *copiarTexto(Texto *t){
    return criarTexto(t->conteudo);
}
//Funcao pra substituir o texto
void substituirTexto(Texto *t, char *alteracao){
    free(t->conteudo);
    t->conteudo = strdup(alteracao);
}
//Funcao pra concatenar dois textos
Texto *concatenarTextos(Texto *t1, Texto *t2){
    char *novo = (char *)malloc(strlen(t1->conteudo) + strlen(t2->conteudo));
    strcpy(novo, t1->conteudo);
    strcat(novo, t2->conteudo);
    Texto *novoTexto = criarTexto(novo);
    free(novo);
    return novoTexto;
}
//Implementacao da strndup pois o compilador nao reconheceu
char *strndup(const char *s, size_t n){
    size_t len = strnlen(s, n);
    char *dup = (char *)malloc(len + 1);
    if (dup != NULL){
        memcpy(dup, s, len);
        dup[len] = '\0';
    }
    return dup;
}
//Funcao pra obter o subtexto
char *obterSubtexto(Texto *t, unsigned int inicio, unsigned int tamanho){
    if(inicio < 1 || inicio > strlen(t->conteudo)){
        return NULL;
    }
    return strndup(t->conteudo + inicio - 1, tamanho);
}
//funcao prra encontrar um subtexto no Texto
unsigned int encontrarSubtexto(Texto *t, char *subtexto, unsigned int ocorrencia){
    char *pos = t->conteudo;
    unsigned int i;
    for (i = 1; i < ocorrencia; ++i){
        pos = strstr(pos + 1, subtexto);
        if (pos == NULL) {
            return FALHA;
        }
    }
    return (unsigned int)(pos - t->conteudo) + 1;
}
//funcao que compara dois Textos
int compararTextos(Texto *t1, Texto *t2){
    int comparacao = strcmp(t1->conteudo, t2->conteudo);
    if (comparacao < 0){
        return MENOR;
    } else if (comparacao > 0){
        return MAIOR;
    } else {
        return IGUAL;
    }
}
void printLinha(){
    printf("+--------------------------------------------------------------------------------------------+\n");
}
//Funcao auxiliar pra printar opcões
void opcoes(){
    printLinha();
    printf("| [ 1] -> [Criar um texto]                | [ 7] -> [Substituir o texto]                     |\n");
    printf("| [ 2] -> [Libera o texto]                | [ 8] -> [Concatenar textos]                      |\n");
    printf("| [ 3] -> [Exibir o tamanho do texto]     | [ 9] -> [Obter um subtexto]                      |\n");
    printf("| [ 4] -> [Obter o texto]                 | [10] -> [Encontrar um subtexto]                  |\n");
    printf("| [ 5] -> [Imprimir o texto por colunas]  | [11] -> [Comparar textos]                        |\n");
    printf("| [ 6] -> [Copiar o texto]                |                                                  |\n");
}
//Funcao pra printar boas vindas :O
void boasVindas(){
    printLinha();
    printf("                                                                    _            _            \n");
    printf("                                                                   | |          | |           \n");
    printf("  ___  _ __   ___ _ __ __ _  ___ __ _  ___     ___ ___  _ __ ___   | |_ _____  __ |_ ___  ___ \n");
    printf(" / _ \\| '_ \\ / _ \\ '__/ _` |/ __/ _` |/ _ \\   / __/ _ \\| '_ ` _ \\  | __/ _ \\ \\/ / __/ _ \\/ __|\n");
    printf("| (_) | |_) |  __/ | | (_| | (__ (_| | (_) | | (__ (_) | | | | | | | |_  __/>  <| |_ (_) \\__ \\\n");
    printf(" \\___/| .__/ \\___|_|  \\__,_|\\___\\__,_|\\___/   \\___\\___/|_| |_| |_| \\__\\___ /_/\\_\\\\__\\___/|___/\n");
    printf("      | |                                                                                     \n");
    printf("      |_|                                                                                     \n");

    printLinha();
    printf("|                                   Escolha uma opcao:                                       |\n");
    opcoes();
}
int main() {
    Texto *texto = NULL;
    int escolha = 1;
    char textoAux[1000];
    boasVindas();
    while (escolha != 0){
        printLinha();
        printf("|             [999] -> [Mostrar opcoes novamente] | [ 0 ] -> [Encerrar programa]             |\n");
        printLinha();
        scanf("%d", &escolha);
        switch (escolha){
            case 999: {
                opcoes();
                break;
            }
            case 1: {
                printf("Digite o texto: ");
                scanf(" %[^\n]s", textoAux);
                if (texto != NULL){
                    liberarTexto(texto);
                }
                texto = criarTexto(textoAux);
                printf("Texto criado com sucesso\n");
                break;
            }
            case 2: {
                if (texto != NULL){
                    liberarTexto(texto);
                    texto = NULL;
                    printf("Texto liberado com sucesso\n");
                } else {
                    printf("Nenhum texto para liberar.\n");
                }
                break;
            }
            case 3: {
                if (texto != NULL){
                    printf("Tamanho do texto: %u\n", tamanhoTexto(texto));
                } else {
                    printf("Nenhum texto disponivel.\n");
                }
                break;
            }
            case 4: {
                if (texto != NULL){
                    printf("Texto: %s\n", obterTexto(texto));
                } else {
                    printf("Nenhum texto disponivel.\n");
                }
                break;
            }
            case 5: {
                if (texto != NULL){
                    unsigned int colunas;
                    printf("Digite o numero de colunas por linha: ");
                    scanf("%u", &colunas);
                    mostrarTexto(texto, colunas);
                } else {
                    printf("Nenhum texto disponivel.\n");
                }
                break;
            }
            case 6: {
                if (texto != NULL){
                    Texto *copia = copiarTexto(texto);
                    printf("Texto copiado.\n");
                    mostrarTexto(copia, 80);
                    liberarTexto(copia);
                } else {
                    printf("Nenhum texto disponível.\n");
                }
                break;
            }
            case 7: {
                if (texto != NULL){
                    printf("Digite o novo texto: ");
                    scanf(" %[^\n]s", textoAux);
                    substituirTexto(texto, textoAux);
                    printf("Texto substituido.\n");
                } else {
                    printf("Nenhum texto disponivel.\n");
                }
                break;
            }
            case 8: {
                if(texto != NULL){
                    printf("Digite o segundo texto: ");
                    scanf(" %[^\n]s", textoAux);
                    Texto *texto2 = criarTexto(textoAux);
                    Texto *concatenado = concatenarTextos(texto, texto2);
                    printf("Textos concatenados.\n");
                    mostrarTexto(concatenado, 80);
                    liberarTexto(texto2);
                    liberarTexto(concatenado);
                } else {
                    printf("Nenhum texto disponivel.\n");
                }
                break;
            }
            case 9: {
                if (texto != NULL){
                    unsigned int inicio, tamanho;
                    printf("Digite a posicao inicial: ");
                    scanf("%u", &inicio);
                    printf("Digite o tamanho do subtexto: ");
                    scanf("%u", &tamanho);
                    char *subtexto = obterSubtexto(texto, inicio, tamanho);
                    if (subtexto != NULL){
                        printf("Subtexto: %s\n", subtexto);
                        free(subtexto);
                    } else {
                        printf("Posicao inicial invalida.\n");
                    }
                } else {
                    printf("Nenhum texto disponivel.\n");
                }
                break;
            }
            case 10: {
                if (texto != NULL){
                    printf("Digite o subtexto: ");
                    scanf(" %[^\n]s", textoAux);
                    printf("Digite a ocorrencia: ");
                    scanf("%u", &escolha);
                    unsigned int posicao = encontrarSubtexto(texto, textoAux, escolha);
                    if (posicao != 0){
                        printf("Ocorrencia encontrada na posicao %u.\n", posicao);
                    } else {
                        printf("Ocorrência não encontrada.\n");
                    }
                } else {
                    printf("Nenhum texto disponível.\n");
                }
                break;
            }
            case 11: {
                if(texto != NULL){
                    printf("Digite o segundo texto: ");
                    scanf(" %[^\n]s", textoAux);
                    Texto *t2 = criarTexto(textoAux);
                    int resultado = compararTextos(texto, t2);
                    if (resultado < 0){
                        printf("Os textos sao diferentes, e o primeiro e menor.\n");
                    } else if (resultado > 0){
                        printf("Os textos sao diferentes, e o primeiro e maior.\n");
                    } else {
                        printf("Os textos sao iguais.\n");
                    }
                    liberarTexto(t2);
                } else {
                    printf("Nenhum texto disponivel. \n");
                }
                break;
            }
            case 0: {
                printf("Encerrando programa.\n");
                if (texto != NULL){
                    liberarTexto(texto);
                }
                break;
            }
            default:
                printf("Opcao invalida.\n");
        }
    }
    return 0;
}