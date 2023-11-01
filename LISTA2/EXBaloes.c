#include <stdio.h>
 
int buscaBinariaBalao(int arrayBaloes[], int esquerda, int direita, int n, int testes, int baloes){
 
        if(baloes == 0){
            return testes && baloes;
        }
 
        if (direita >= esquerda){
            int meio = esquerda + (direita - esquerda) / 2;
 
            if (arrayBaloes[meio] == n){
                testes++;
                return testes && baloes;
            }
 
            if (arrayBaloes[meio] > n){
                testes++;
                return buscaBinariaBalao(arrayBaloes, esquerda, meio - 1, n, testes, baloes);
                baloes--;
            }
 
            testes++;
            return buscaBinariaBalao(arrayBaloes, meio + 1, direita, n, testes, baloes);
            baloes--;
        }
 
    return testes;
}
 
int main(){
 
    int n, i, testes = 0, baloes;
 
    scanf("%d", &n);
    scanf("%d",  &baloes);
    int arrayBaloes[n + 1];
    int tamanho = sizeof(arrayBaloes) / sizeof(arrayBaloes[0]);
 
 
    for(i = 1; i <= n; i++){
        arrayBaloes[i] = i;
    }
    
    int busca = buscaBinariaBalao(arrayBaloes, 0, tamanho - 1, n, testes, baloes);
 
    printf("%d - %d", busca, baloes);
 
 
    return 0;
}