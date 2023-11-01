#include <stdio.h>

void lerRotulos(int[], int);
int encontrarMinimo(int[], int);

int main(){
    
    int quantidade, tipos, i;
    
    scanf("%d", &quantidade);
    scanf("%d", &tipos);
    
    int contagem[tipos];
    
    for (i = 0; i < tipos; i++) {
        contagem[i] = 0;
    }
    
    lerRotulos(contagem, quantidade);
    
    int min_cont = encontrarMinimo(contagem, tipos);
    
    printf("%d\n", min_cont);
    
    return 0;
}

void lerRotulos(int contagem[], int quantidade){
    int i;
    for (i = 0; i < quantidade; i++) {
        int embalagem;
        scanf("%d", &embalagem);
        contagem[embalagem - 1]++;
    }
}

int encontrarMinimo(int contagem[], int tipos){
    int i;
    int min_cont = contagem[0];
    for (i = 1; i < tipos; i++){
        if (contagem[i] < min_cont){
            min_cont = contagem[i];
        }
    }
    return min_cont;
}
