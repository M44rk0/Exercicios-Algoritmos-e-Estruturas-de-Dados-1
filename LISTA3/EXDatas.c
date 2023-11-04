//==============================================================================
// Arquivo ponto.h
//==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

//Definindo algumas constantes
/*
#define JANEIRO 1
#define FEVEREIRO 2
#define MARCO 3
#define ABRIL 4
#define MAIO 5
#define JUNHO 6
#define JULHO 7
#define AGOSTO 8
#define SETEMBRO 9
#define OUTUBRO 10
#define NOVEMBRO 11
#define DEZEMBRO 12
*/

#define IGUAL 0
#define MENOR -1
#define MAIOR 1

typedef struct datas Data;
//Define o struct data
struct datas{
    unsigned int dia;
    unsigned int mes;
    unsigned int ano;
};
//Cria data (lembrar de criar uma verificação na main para os dias <=31 e meses <=12, e se o mês for 2, os dias devem ser <=28 e 29 se for bissexto)
Data *criaData(unsigned int dia, unsigned int mes, unsigned int ano){
    Data *data = (Data *)calloc(1, sizeof(Data));
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
    return data;
}
//Função pra copiar uma data
Data *copiaData(Data d){
    return(criaData(d.dia, d.mes, d.ano));
}
//Função pra destruir uma data
void liberaData(Data *d){
    if(d != NULL){
    free(d);
    }
};
//Função auxiliar pra verificar se um ano é bissexto
int Bissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}
// Função auxiliar pra calcular o número de dias em um mês
int diasNoMes(int mes, int ano) {
    int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mes == 2 && Bissexto(ano)) {
        return 29;
    }else{return diasPorMes[mes];}
}
// Função pra somar os dias a uma data
Data somaDiasData(Data d, unsigned int dias){
    while (dias > 0){
        unsigned int diasNoMesAtual = diasNoMes(d.mes, d.ano);
        if (d.dia + dias > diasNoMesAtual){
            dias -= (diasNoMesAtual - d.dia + 1);
            d.dia = 1;
            if (d.mes == 12){
                d.mes = 1;
                d.ano++;
            }else{d.mes++;}
        }else{
            d.dia += dias;
            dias = 0;
        }
    }return d;
}
//Função pra subtrair uma data
Data subtrairDiasData(Data d, unsigned int dias) {
    while (dias > 0) {
        if (d.dia > dias) {
            d.dia -= dias;
            dias = 0;
        } else {
            if (d.mes == 1) {
                d.mes = 12;
                d.ano--;
            } else {d.mes--;}
            int diasNoMesAnterior = diasNoMes(d.mes, d.ano);
            d.dia = diasNoMesAnterior;
            dias -= d.dia;
        }
    }return d;
}
//Função pra atribuir novos valores a data
void atribuirData (Data * d, unsigned int dia, unsigned int mes, unsigned int ano){
    if(d != NULL){
        d->dia = dia;
        d->mes = mes;
        d->ano = ano;
    };
}
unsigned int obtemDiaData(Data d){
    return d.dia;
};

unsigned int obtemMesData(Data d){
    return d.mes;
};

unsigned int obtemAnoData(Data d){
    return d.ano;
};

unsigned int bissextoData(Data d) {
    return (d.ano % 4 == 0 && d.ano % 100 != 0) || (d.ano % 400 == 0);
}

int comparaData (Data d1, Data d2){
    if(d1.ano > d2.ano){
        return MAIOR;
    }
    else if(d1.ano < d2.ano){
        return MENOR;
    }
    else if(d1.ano == d2.ano){
        if(d1.mes > d2.mes){
            return MAIOR;
        }
        else if(d1.mes < d2.mes){
            return MENOR;
        }
        else if(d1.mes == d2.mes){
            if(d1.dia > d2.dia){
                return MAIOR;
            }
            else{
                return MENOR;
            }
        }
    }return IGUAL;
};
//Retorna MENOR se d1 < d2, retorna IGUAL se d1 = d2 ou retorna MAIOR, se d1 > d2

//teste

int main(){
    Data *d = criaData(11, 12, 2023);
    Data *d1 = criaData(9, 7, 2023);
    Data *d2 = criaData(2, 5, 2023);

    printf("dia de D: %d", obtemDiaData(*d));
    printf("dia de D2: %d", obtemDiaData(*d1));
    printf("dia de D3: %d", obtemDiaData(*d2));

    liberaData(d);
    liberaData(d1);
    liberaData(d2);

}