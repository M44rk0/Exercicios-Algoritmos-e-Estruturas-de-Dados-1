#include <stdio.h>
#include <math.h>

float areaCirculo(int R){
    float pi = 3.14159265;
    float resultado = (pi * R * R);
    return rintf(resultado);
}

float areaElipse(int R, int r){
    float pi = 3.14159265;
    float resultado = R * r * pi;
    return rintf(resultado);
}

float areaTriangulo(int a, int b, int c){
    float p = (a + b + c) / 2.0;
    float resultado = sqrtf(p*((p-a) * (p-b) * (p-c)));
    return rintf(resultado);
}

float areaTrapezio(int B, int b, int H){
    float resultado = ((B + b) * H ) / 2.0;
    return rintf(resultado);
}

int main(){
    
    int N;
    scanf("%d", &N);
    int resultados[N];

    for(int i = 0; i < N; i++){
        char fig;
        scanf(" %c", &fig);

        if(fig == 'C'){
            int raio;
            scanf("%d", &raio);
            resultados[i] = areaCirculo(raio);
        }
        else if(fig == 'E'){
            int R, r;
            scanf("%d", &R);
            scanf("%d", &r);
            resultados[i] = areaElipse(R, r);
        }
        else if(fig == 'T'){
            int a, b, c;
            scanf("%d", &a);
            scanf("%d", &b);
            scanf("%d", &c);
            resultados[i] = areaTriangulo(a, b, c);
        }
        else if(fig == 'Z'){
            int B, b, H;
            scanf("%d", &B);
            scanf("%d", &b);
            scanf("%d", &H);
            resultados[i] = areaTrapezio(B, b, H);
        }
    }

    for(int i = 0; i < N; i++){
        printf("%d\n", resultados[i]);
    }

    return 0;
}