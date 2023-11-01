#include <stdio.h>

int invertido;
int inverter(int n){
    if(n == 0){
        return invertido;
    }
    else{
        invertido = invertido * 10 + n % 10;
        return inverter(n / 10);
    }
    return -1;
}

int main(){
    
    int n;
    scanf("%d", &n);
    int resultado = inverter(n);
    printf("%d", resultado);
    return 0;
}

