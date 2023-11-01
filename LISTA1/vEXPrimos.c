#include <stdio.h>

int main(){

    int N, i;
    long int P;

    scanf("%d", &N);
    int composto[N];

    for(i = 0; i< N; i++){
        scanf("%ld", &P);
        if(P % 2 == 0 && P != 2){
            composto[i] = 1;
        }
        else{
            composto[i] = 0;
        }
    }

    for(i = 0; i < N; i++){
        (composto[i] == 1) ? printf("composto\n") : printf("primo\n");
    }

}