#include <stdio.h>

int main(){
    
    int n, aux, numero, numInvertido;
    
    scanf("%d", &n);
    
    int numeros[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &numeros[i]);
    }
    
    for (int i = 0; i < n; i++) {
        
        aux = numeros[i];
        
        while (aux != 0) {
            numInvertido = numInvertido * 10 + aux % 10;
            aux /= 10;
        }
    
    numeros[i] == numInvertido ? printf("yes ") : printf("no ");
    numInvertido = 0;
    
    }
    
    return 0;
}
