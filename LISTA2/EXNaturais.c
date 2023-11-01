#include <stdio.h>

void naturais(int n){
    if(n <= 0){
        return;
    }

    naturais(n - 1);
    printf("%d ", n);
}

int main(){
    int n;
    scanf("%d", &n);
    naturais(n);
    return 0;
}