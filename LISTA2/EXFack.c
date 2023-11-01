#include <stdio.h>

unsigned long int fack(unsigned long int m, unsigned long int n){
    if(m == 0){
        return n+1;
    }
    else if(n == 0 && m > 0){
        return fack(m - 1, 1);
    }
    else{
        return fack(m -1, fack(m, n-1));
    }
    return 0;
}


int main(){

    unsigned long int m, n;
    scanf("%lu %lu", &m, &n);

    unsigned long int resultado = fack(m, n);
    printf("%lu", resultado);

    return 0;
}