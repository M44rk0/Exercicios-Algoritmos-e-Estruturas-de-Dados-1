#include <stdio.h>

void conversor(int n) {
    
    if (n == 0) {
        printf("A\n");
        return;
    }

    char base4[20];

    int i = 0;
    while (n > 0) {
        int resto = n % 4;
        if (resto == 0) {
            base4[i] = 'A';
        } else if (resto == 1) {
            base4[i] = 'C';
        } else if (resto == 2) {
            base4[i] = 'G';
        } else {
            base4[i] = 'T';
        }
        n = n / 4;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%c", base4[j]);
    }
}

int main() {
    
    int n;
    scanf("%d", &n);
    int numeros[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &numeros[i]);
        conversor(numeros[i]);
        printf("\n");
    }

    return 0;
}