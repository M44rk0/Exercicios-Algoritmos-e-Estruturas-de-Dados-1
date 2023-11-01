#include <stdio.h>

void binario(int n){
    if(n > 0){
        binario(n / 2);
        printf("%d", n % 2);
    }
}

int main(){

    int i, n, k;

    scanf("%d", &k);
    int numeros[k];

    for(i = 0; i < k; i++){
        scanf("%d", &n);
        numeros[i] = n;
    }

    for(i = 0; i < k; i++){
        binario(numeros[i]);
        printf("\n");
    }

    return 0;
}