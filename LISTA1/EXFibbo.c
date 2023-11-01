#include <stdio.h>
#include <math.h>

double fiboBinet(double n){
    double phi = (1 + sqrt(5) / 2);
    return round(pow(phi, n) - pow(( - phi) , -n) / sqrt(5));
}

int main(){

    double n;
    scanf("%lf", &n);
    double resultado = fiboBinet(n);
    printf("%lf", resultado);
    return 0;
}