//==============================================================================
// Arquivo datas.h
//==============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <math.h>
//Define constantes
#define IGUAL 0
#define MENOR -1
#define MAIOR 1
//Define o cabecalho das funcoes
typedef struct datas Data;
Data *criaData(unsigned int dia, unsigned int mes, unsigned int ano);
Data *copiaData(Data d);
void liberaData(Data *d);
Data somaDiasData(Data d, unsigned int dias);
Data subtrairDiasData(Data d, unsigned int dias);
void atribuirData (Data * d, unsigned int dia, unsigned int mes, unsigned int ano);
unsigned int obtemDiaData(Data d);
unsigned int obtemMesData(Data d);
unsigned int obtemAnoData(Data d);
unsigned int bissextoData(Data d);
int comparaData (Data d1, Data d2);
unsigned int numeroDiasDatas(Data d1, Data d2);
unsigned int numeroMesesDatas(Data d1, Data d2);
unsigned int numeroAnosDatas(Data d1, Data d2);
unsigned int obtemDiaSemanaData(Data d);
char *imprimeData(Data d, char *formato);
//==============================================================================
// Arquivo ponto.c
//==============================================================================

//Define o struct data
struct datas{
    unsigned int dia;
    unsigned int mes;
    unsigned int ano;
};
//Cria data (lembrar de criar uma verificacao na main para os dias <=31 e meses <=12, e se o mês for 2, os dias devem ser <=28 e 29 se for bissexto)
Data *criaData(unsigned int dia, unsigned int mes, unsigned int ano){
    Data *data = (Data *)calloc(1, sizeof(Data));
    data->dia = dia, data->mes = mes, data->ano = ano;
    return data;
}
//Funcao pra copiar uma data
Data *copiaData(Data d){
    return(criaData(d.dia, d.mes, d.ano));
}
//Funcao pra destruir uma data
void liberaData(Data *d){
    if(d != NULL){
    free(d);
    }
}
//Funcao auxiliar pra verificar se um ano e bissexto
int bissexto(int ano){
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}
// Funcao auxiliar pra calcular o numero de dias em um mês
unsigned int diasNoMes(int mes, int ano) {
    unsigned int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (mes == 2 && bissexto(ano)) ? 29 : diasPorMes[mes];
}
// Funcao pra somar os dias a uma data
Data somaDiasData(Data d, unsigned int dias){
    while (dias > 0){
        unsigned int diasNoMesAtual = diasNoMes(d.mes, d.ano);
        if (d.dia + dias > diasNoMesAtual){
            dias -= (diasNoMesAtual - d.dia + 1);
            d.dia = 1;
            if (d.mes == 12){
                d.mes = 1;
                d.ano++;
            }
            else{
                d.mes++;}
        }
        else{
            d.dia += dias;
            dias = 0;
        }
    } return d;
}
//Funcao pra subtrair uma data
Data subtrairDiasData(Data d, unsigned int dias){
    while (dias > 0){
        if (d.dia > dias){
            d.dia -= dias;
            dias = 0;
        } 
        else{
            if (d.mes == 1) {
                d.mes = 12;
                d.ano--;
            }
            else d.mes--;

            int diasNoMesAnterior = diasNoMes(d.mes, d.ano);
            d.dia = diasNoMesAnterior;
            dias -= d.dia;
        }
    } return d;
}
//Funcao pra atribuir novos valores a data
void atribuirData (Data * d, unsigned int dia, unsigned int mes, unsigned int ano){
    if(d != NULL){
        d->dia = dia, d->mes = mes, d->ano = ano;
    }
}
//Funcao pra retornar o dia de uma data
unsigned int obtemDiaData(Data d){
    return d.dia;
}
//Funcao pra retornar o mes de uma data
unsigned int obtemMesData(Data d){
    return d.mes;
}
//Funcao pra retornar o ano de uma data
unsigned int obtemAnoData(Data d){
    return d.ano;
}
//Funcao pra verificar se uma data pertence a um ano bissexto
unsigned int bissextoData(Data d){
    return (d.ano % 4 == 0 && d.ano % 100 != 0) || (d.ano % 400 == 0);
}
//Funcao que compara duas datas
int comparaData(Data d1, Data d2) {
    if (d1.ano > d2.ano) {
        return MAIOR;
    } else if (d1.ano < d2.ano) {
        return MENOR;
    } else { 
        if (d1.mes > d2.mes) {
            return MAIOR;
        } else if (d1.mes < d2.mes) {
            return MENOR;
        } else { 
            if (d1.dia > d2.dia) {
                return MAIOR;
            } else if (d1.dia < d2.dia) {
                return MENOR;
            } else {
                return IGUAL;
            }
        }
    }
}
//Funcao que calcula os dias entre duas datas
unsigned int numeroDiasDatas(Data d1, Data d2){
    unsigned int dias = 0;
    if (d1.ano > d2.ano || (d1.ano == d2.ano && (d1.mes > d2.mes || (d1.mes == d2.mes && d1.dia > d2.dia)))){
        Data temp = d1;
        d1 = d2;
        d2 = temp;
    } 
    while (d1.ano < d2.ano || (d1.ano == d2.ano && (d1.mes < d2.mes || (d1.mes == d2.mes && d1.dia < d2.dia)))){
        dias++;
        d1.dia++;
        if (d1.dia > diasNoMes(d1.mes, d1.ano)){
            d1.dia = 1;
            d1.mes++;
            if (d1.mes > 12) {
                d1.mes = 1;
                d1.ano++;
            }
        }
    } return dias;
}
//Funcao que calcula o numero de meses entre duas datas
unsigned int numeroMesesDatas(Data d1, Data d2){
    unsigned int meses = 0;
    if (d1.ano > d2.ano || (d1.ano == d2.ano && d1.mes > d2.mes)){
        Data temp = d1;
        d1 = d2;
        d2 = temp;
    } 
    while (d1.ano < d2.ano || (d1.ano == d2.ano && d1.mes < d2.mes)){
        meses++;
        d1.mes++;
        if (d1.mes > 12){
            d1.mes = 1;
            d1.ano++;
        }
    } return meses;
}
//Funcao que calcula o numero de anos entre duas datas
unsigned int numeroAnosDatas(Data d1, Data d2) {
    unsigned int anos = 0;
    anos = abs(d2.ano - d1.ano);
    return anos;
}
//Funcao que calcula o dia da semana usando Congruencia de Zeller
unsigned int obtemDiaSemanaData(Data d){
    int mes, ano, dia, h, k, j;
    if (d.mes < 3){
        mes = d.mes + 12;
        ano = d.ano - 1;
    } else {
        mes = d.mes;
        ano = d.ano;
    }
    dia = d.dia;
    j = ano / 100;
    k = ano % 100;
    h = (dia + 13 * (mes + 1) / 5 + k + k / 4 + j / 4 - 2 * j) % 7;
    if (h < 0){
        h += 7;
    }
    return (h == 0) ? 7 : h;
}
//Funcao para imprimir uma data
char *imprimeData(Data d, char *formato){
    char *dataFormatada = (char *)malloc(11);
    dataFormatada[0] = '\0';
    if (strcmp(formato, "ddmmaaaa") == 0){
        snprintf(dataFormatada, 11, "%02u/%02u/%04u", d.dia, d.mes, d.ano);
    } else if (strcmp(formato, "aaaammdd") == 0){
        snprintf(dataFormatada, 11, "%04u/%02u/%02u", d.ano, d.mes, d.dia);
    } else if (strcmp(formato, "aaaa") == 0){
        snprintf(dataFormatada, 11, "%04u", d.ano);
    } else if (strcmp(formato, "mm") == 0){
        snprintf(dataFormatada, 11, "%02u", d.mes);
    } else if (strcmp(formato, "dd") == 0){
        snprintf(dataFormatada, 11, "%02u", d.dia);
    } else if (strcmp(formato, "ddmm") == 0){
        snprintf(dataFormatada, 11, "%02u%02u", d.dia, d.mes);
    }return dataFormatada;
}
//Funcao auxiliar pra criar duas datas
void criaDataAux(Data **d1, Data **d2){
    printf("Digite as informacoes da primeira data:\n");
    
    printf("Dia: ");
    unsigned int dia;
    while (1){
        scanf("%u", &dia);
        if (dia > 31){
            printf("Erro, tente novamente.\n");
            printf("Dia: ");
        } else break;
    }
    printf("Mes: ");
    unsigned int mes;
    while (1){
        scanf("%u", &mes);
        if (mes > 12 || (mes == 2 && dia > 29) || (mes > 2 && dia == 29)){
            printf("Erro, tente novamente.\n");
            printf("Mes: ");
        } else break;
    }
    printf("Ano: ");
    unsigned int ano;
    while (1){
        scanf("%u", &ano);
        if (ano > 2200 || ano < 1900 || (mes == 2 && dia == 29 && !bissexto(ano))){
            printf("Erro, tente novamente.\n");
            printf("Ano: ");
        } else break;
    }
    *d1 = criaData(dia, mes, ano);
    printf("Data %s criada com sucesso!\n", imprimeData(**d1, "ddmmaaaa"));

    printf("Digite as informacoes da segunda data:\n");
    printf("Dia: ");
    while (1){
        scanf("%u", &dia);
        if (dia > 31){
            printf("Erro, tente novamente.\n");
            printf("Dia: ");
        } else break;
    }
    printf("Mes: ");
    while (1){
        scanf("%u", &mes);
        if (mes > 12 || (mes == 2 && dia > 29) || (mes > 2 && dia == 29)){
            printf("Erro, tente novamente.\n");
            printf("Mes: ");
        } else break;
    }
    printf("Ano: ");
    while (1) {
        scanf("%u", &ano);
        if (ano > 2200 || ano < 1900 || (mes == 2 && dia == 29 && !bissexto(ano))){
            printf("Erro, tente novamente.\n");
            printf("Ano: ");
        } else break;
    }
    *d2 = criaData(dia, mes, ano);
    printf("Data %s criada com sucesso!\n", imprimeData(**d2, "ddmmaaaa"));
}

//Funcao auxiliar pra printar linha
void printLinha(){
    printf("+-----------------------------------------------------------------------------------------------------------+\n");
}
//Funcao auxiliar pra printar opcões
void opcoes(){
    printLinha();
    printf("| [ 1] -> [Criar uma data]                       | [ 9] -> [Exibir o mes da data]                           |\n");
    printf("| [ 2] -> [Alterar o dia/mes/ano de uma data]    | [10] -> [Exibir o ano da data]                           |\n");
    printf("| [ 3] -> [Criar uma copia de uma data]          | [11] -> [Verificar se a data pertence a um ano bissexto] |\n");
    printf("| [ 4] -> [Imprimir uma data na tela]            | [12] -> [Verificar qual o dia da semana de uma data]     |\n");
    printf("| [ 5] -> [Destruir uma data]                    | [13] -> [Verificar quantos dias entre duas datas]        |\n");
    printf("| [ 6] -> [Retornar dias posteriores a uma data] | [14] -> [Verificar quantos meses entre duas datas]       |\n");
    printf("| [ 7] -> [Retornar dias anteriores a uma data]  | [15] -> [Verificar quantos anos entre duas datas]        |\n");
    printf("| [ 8] -> [Exibir o dia da data]                 | [16] -> [Comparar duas datas]                            |\n");
}
//Funcao pra printar boas vindas :O
void boasVindas(){
    printLinha();
    printf("|                                                                               _       _                   |\n");
    printf("|                                                                              | |     | |                  |\n");
    printf("|         ___  _ __   ___ _ __ __ _  ___ __ _  ___     ___ ___  _ __ ___     __| | __ _| |_ __ _ ___        |\n");
    printf("|        / _ \\| '_ \\ / _ \\ '__/ _` |/ __/ _` |/ _ \\   / __/ _ \\| '_ ` _ \\   / _` |/ _` | __/ _` / __|       |\n");
    printf("|       | (_) | |_) |  __/ | | (_| | (__ (_| | (_) | | (__ (_) | | | | | | | (_| | (_| | |_ (_| \\__ \\       |\n");
    printf("|        \\___/| .__/ \\___|_|  \\__,_|\\___\\__,_|\\___/   \\___\\___/|_| |_| |_|  \\__,_|\\__,_|\\__\\__,_|___/       |\n");
    printf("|             | |                                                                                           |\n");
    printf("|             |_|                                                                                           |\n");
    printLinha();
    printf("|                                          Escolha uma opcao:                                               |\n");
    opcoes();
}
//==============================================================================
// Arquivo ponto.c
//==============================================================================
int main(){
   boasVindas();
    int escolha;
    Data *d = NULL, *d1 = NULL, *d2 = NULL, *copia = NULL;
    while(escolha != 0){
        printLinha();
        printf("|                  [999] -> [Mostrar opcoes novamente] | [ 0 ] -> [Encerrar programa]                       |\n");
        printLinha();
        scanf("%d", &escolha);
        switch (escolha){
            case 999: {
                opcoes();
                break;
            }
            case 0: {
                printf("Encerrando programa.\n");
                liberaData(d);
                break;
            }
            case 1: {
                printf("Dia: ");
                unsigned int dia;
                while(1){
                    scanf("%u", &dia);
                    if(dia > 31){
                        printf("Erro, tente novamente.\n");
                        printf("Dia: ");
                        } else break;
                }
                printf("Mes: ");
                unsigned int mes;
                while(1){
                    scanf("%u", &mes);
                    if(mes > 12 || (mes == 2 && dia > 29)){
                        printf("Erro, tente novamente.\n");
                        printf("Mes: ");
                    } else break;
                } 
                printf("Ano: ");
                unsigned int ano;
                while(1){
                    scanf("%u", &ano);
                    if(ano > 2200 || ano < 1900 || (mes == 2 && dia == 29 && !bissexto(ano))){
                        printf("Erro, tente novamente.\n");
                        printf("Ano: ");
                    } else break;
                } 
                d = criaData(dia, mes, ano);               
                printf("Data %s criada com sucesso!\n", imprimeData(*d, "ddmmaaaa"));
                break;
            }
            case 2: {
                if(d != NULL){
                    printf("Dia: ");
                    unsigned int dia;
                    while(1){
                        scanf("%u", &dia);
                        if(dia > 31){
                            printf("Erro, tente novamente\n");
                            printf("Dia: ");
                            } else break;
                    }
                    printf("Mes: ");
                    unsigned int mes;
                    while(1){
                        scanf("%u", &mes);
                        if(mes > 12 || (mes == 2 && dia > 29) || (mes > 2 && dia == 29)){
                            printf("Erro, tente novamente\n");
                            printf("Mes: ");
                        } else break;
                    } 
                    printf("Ano: ");
                    unsigned int ano;
                    while(1){
                        scanf("%u", &ano);
                        if(ano > 2200 || (mes == 2 && dia == 29 && !bissexto(ano))){
                            printf("Erro, tente novamente\n");
                            printf("Mes: ");
                        } else break;
                    } 
                    atribuirData(d, dia, mes, ano);
                    printf("Data alterada com sucesso.\n");
                } else {
                    printf("Data ainda nao criada.\n");
                    break;
                } break;
            }
            case 3: {
                if(d != NULL){
                    copia = copiaData(*d); 
                    printf("Copia de [%s] realizada com sucesso.\n", imprimeData(*copia, "ddmmaaaa"));
                }
                else printf("Data ainda nao criada.\n");
                break;
            }
            case 4: {
                if(d != NULL){
                    printf("Data: %s\n", imprimeData(*d, "ddmmaaaa"));
                }
                else printf("Data ainda nao criada.\n");
                break;
            }
            case 5: {
                liberaData(d);
                printf("Data destruida com sucesso.\n");
                break;
            }
            case 6: {
                if(d != NULL){
                    unsigned int dias;
                    printf("Quantos dias?: ");
                    scanf("%u", &dias);
                    copia = copiaData(*d);
                    printf("Data: %s\n", imprimeData(somaDiasData(*copia, dias), "ddmmaaaa"));
                    liberaData(copia);
                }
                else printf("Data ainda nao criada.\n");
                break;
            }
            case 7: {
                if(d != NULL){
                    unsigned int dias;
                    printf("Quantos dias?: ");
                    scanf("%u", &dias);
                    copia = copiaData(*d);
                    printf("Data: %s\n", imprimeData(subtrairDiasData(*copia, dias), "ddmmaaaa"));
                    liberaData(copia);
                }
                else printf("Data ainda nao criada.\n");
                break;
            }
            case 8: {
                if(d != NULL){
                    printf("Dia: %u\n", obtemDiaData(*d));
                }
                else printf("Data ainda nao criada.\n");
                break;
            }
            case 9: {
                if(d != NULL){
                    printf("Mes: %u\n", obtemMesData(*d));
                }
                else printf("Data ainda nao criada.\n");
                break;
            }
            case 10: {
                if(d != NULL){
                    printf("Ano: %u\n", obtemAnoData(*d));
                }
                else printf("Data ainda nao criada.\n");
                break;
            }
            case 11: {
                if(d != NULL){
                    (bissextoData(*d) == 1) ? printf("Ano bissexto.\n") : printf("Nao e bissexto.\n");
                }
                else printf("Data ainda nao criada.\n");
                break;
            }
            case 12: {
                if(d != NULL){
                    switch(obtemDiaSemanaData(*d)){
                        case 1: printf("Domingo\n"); break;
                        case 2: printf("Segunda\n"); break;
                        case 3: printf("Terca\n"); break;
                        case 4: printf("Quarta\n"); break;
                        case 5: printf("Quinta\n"); break;
                        case 6: printf("Sexta\n"); break;
                        case 7: printf("Sabado\n"); break;
                    }
                }
                else printf("Data ainda nao criada.\n");
                break;
            }
            case 13: {
                criaDataAux(&d1, &d2);
                unsigned int dias = numeroDiasDatas(*d1, *d2);
                printf("Diferenca de %u dia(s)\n", dias);
                free(d1), free(d2);
                break;
            }
            case 14: {
                criaDataAux(&d1, &d2);
                unsigned int meses = numeroMesesDatas(*d1, *d2);
                printf("Diferenca de %u mes(es)\n", meses);
                free(d1), free(d2);
                break;
            }
            case 15: {
                criaDataAux(&d1, &d2);
                unsigned int anos = numeroAnosDatas(*d1, *d2);
                printf("Diferenca de %u ano(s)\n", anos);
                free(d1), free(d2);
                break;
            }
            case 16: {
                criaDataAux(&d1, &d2);
                int comparar = comparaData(*d1, *d2);
                switch(comparar){
                    case 1:
                        printf("D1 é maior que D2\n");
                        break;
                    case -1:
                        printf("D1 é menor que D2\n");
                        break;
                    case 0:
                        printf("D1 é igual a D2\n");
                        break;
                }
                break;
            }
            default:
                printf("Opcao invalida.\n");
                break;
        }
    }   
}