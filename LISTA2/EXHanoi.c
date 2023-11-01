#include <stdio.h>

void torreHanoi(int n, char origem, char destino, char aux){
    if (n == 1){
        printf("(%c,%c)\n", origem, destino);
        return;
    }
    
    torreHanoi(n - 1, origem, aux, destino);
    printf("(%c,%c)\n", origem, destino);
    torreHanoi(n - 1, aux, destino, origem);
}

int main(){

    int n;
    scanf("%d", &n);

    torreHanoi(n, 'O', 'D', 'A');

    return 0;
}
