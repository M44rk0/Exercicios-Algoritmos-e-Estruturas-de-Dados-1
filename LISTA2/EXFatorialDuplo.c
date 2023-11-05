#include <stdio.h>

double fatorialDuplo(int n) {
    if (n <= 1) {
        return 1.0;
    } else {
        if (n % 2 != 0) {
            return (double)n * fatorialDuplo(n - 2);
        } else {
            return fatorialDuplo(n - 1);
        }
    }
}

int main() {
    int numero;
    scanf("%d", &numero);
    double resultado = fatorialDuplo(numero);
    printf("%.0f", resultado);
    return 0;
}
