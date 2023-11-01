
#include <stdio.h>

int main(){
    
    int n, num1, num2;
    char operacao;
    
    scanf("%d", &n);
    scanf("%d", &num1);
    scanf(" %c", &operacao);
    scanf("%d", &num2);

    if(operacao == 'x'){
        int aux = num1 * num2;
        aux > n ? printf("overflow") : printf("no overflow");
    }
    else{
        int aux = num1 + num2;
        aux > n ? printf("overflow") : printf("no overflow");
    }
        
    
    return 0;
}

