#include <stdio.h>

int main(){

    int P, i, S, pd, sp;
    scanf("%d", &P);
    int pedras[P];
    for(i = 0; i<P; i++){
        pedras[i] = 0;
    }

    scanf("%d", &S);

    for(i = 0; i<S; i++){
        scanf("%d", &pd);
        pedras[pd-1] = 1;
        scanf("%d", &sp);
        pedras[pd+sp-1] = 1;
        if(pd > sp){
            pedras[pd-sp-1] = 1;
        }
        if(sp * 2 < P){
            pedras[pd + sp * 2 - 1] = 1;
        }
    }
    
    for(i = 0; i<P; i++){
        printf("%d\n", pedras[i]);
    }

    return 0;
}