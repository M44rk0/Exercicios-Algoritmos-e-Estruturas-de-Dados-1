#include <stdio.h>

int main() {
    int mA, nA;
    char operacao;

    scanf("%d", &mA);
    scanf("%d", &nA);

    int matrizA[mA][nA];
    int matrizB[mA][nA];
    int matrizC[mA][nA];

    for (int i = 0; i < mA; i++) {
        for (int j = 0; j < nA; j++) {
            scanf("%d", &matrizA[i][j]);
        }
    }

    scanf(" %c", &operacao);

    for (int i = 0; i < mA; i++) {
        for (int j = 0; j < nA; j++) {
            scanf("%d", &matrizB[i][j]);
        }
    }

    if (operacao == '+') {
        for (int i = 0; i < mA; i++) {
            for (int j = 0; j < nA; j++) {
                matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
            }
        }

        for (int i = 0; i < mA; i++) {
            for (int j = 0; j < nA; j++) {
                printf("%d ", matrizC[i][j]);
            }
            printf("\n");
        }
    } 
    
    else if (operacao == 'x' && nA == mA) {
        for (int i = 0; i < mA; i++) {
            for (int j = 0; j < nA; j++) {
                matrizC[i][j] = 0;
                for (int k = 0; k < nA; k++) {
                    matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
                }
            }
        }

        for (int i = 0; i < mA; i++) {
            for (int j = 0; j < nA; j++) {
                printf("%d ", matrizC[i][j]);
            }
            printf("\n");
        }
    } 
    
    else {
        printf("ERROR\n");
    }

    return 0;
}
