#include <stdio.h>

unsigned long int fibonacci(unsigned long int n) {
    if ((n == 1) || (n == 2)) {
        return 1;
    }
    
    unsigned long int a = 1;
    unsigned long int b = 1;
    unsigned long int result = 0;
    unsigned long int i;
    
    for (i = 3; i <= n; i++) {
        result = a + b;
        a = b;
        b = result;
    }
    
    return result;
}

int main() {
    unsigned long int K;
    int N, i;
    scanf("%d", &N);
    unsigned long int numeros[N];

    for (i = 0; i < N; i++) {
        scanf("%lu", &K);
        numeros[i] = fibonacci(K);
    }

    for (i = 0; i < N; i++) {
        printf("%lu\n", numeros[i]);
    }
    return 0;
}
