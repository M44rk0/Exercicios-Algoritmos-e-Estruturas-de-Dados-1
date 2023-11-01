#include <stdio.h>

int main(){
    
    int num, num2, numInvertido = 0, numInvertido2 = 0;

    scanf("%d", &num);
    scanf("%d", &num2);

    while (num && num2 != 0) {
        numInvertido = numInvertido * 10 + num % 10;
        numInvertido2 = numInvertido2 * 10 + num2 % 10;
        num /= 10;
        num2 /= 10;
    }

    numInvertido > numInvertido2 ? printf("%d", numInvertido) : printf("%d", numInvertido2);

    return 0;
}

