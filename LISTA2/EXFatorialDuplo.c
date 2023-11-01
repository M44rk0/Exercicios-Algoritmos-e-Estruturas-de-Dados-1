#include <stdio.h>

int fatorialDuplo(int n) {
    if (n <= 1) {
        return 1;
    } else {
        if (n % 2 != 0) {
            return n * fatorialDuplo(n - 2);
        } else {
            return fatorialDuplo(n - 1);
        }
    }
}

int main() {
    int numero;
    scanf("%d", &numero);
    int resultado = fatorialDuplo(numero);
    printf("%d", resultado);
    return 0;
}
