#include <stdio.h>

int testes, baloes;

int buscaBinariaBalao(int arrayBaloes[], int esquerda, int direita, int n) {
        if (direita >= esquerda && baloes >= 0) {
            int meio = esquerda + (direita - esquerda) / 2;

            if (arrayBaloes[meio] == n) {
                testes++;
                return testes;
            }

            if (arrayBaloes[meio] > n) {
             baloes--;
                testes++;
                return buscaBinariaBalao(arrayBaloes, esquerda, meio - 1, n);
                return testes;
            }

         baloes--;
            testes++;
            return buscaBinariaBalao(arrayBaloes, meio + 1, direita, n);
            return testes;
        }
        else {
            return testes;
        }

    return -1;
}

int main() {

    int n, i;

    scanf("%d", &n);
    scanf("%d",  &baloes);
    int arrayBaloes[n + 1];
    int tamanho = sizeof(arrayBaloes) / sizeof(arrayBaloes[0]);


    for(i = 1; i <= n; i++){
        arrayBaloes[i] = i;
    }

    int busca = buscaBinariaBalao(arrayBaloes, 0, tamanho - 1, n);

    printf("%d", busca);


    return 0;
}
