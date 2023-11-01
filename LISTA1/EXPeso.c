#include <stdio.h>

    float h, pesoIdealM, pesoIdealF;
    char M, F, sexo;

int main()
{
    printf("Digite o sexo da pessoa (M ou F): \n");
    scanf("%c", &sexo);
    
    printf("Digitei a altura da pessoa (em metros): \n");
    scanf("%f", &h);
    
    pesoIdealM = (72.7*h) - 58;
    pesoIdealF = (62.1*h) - 44.7;
    
    if(sexo == 'M'){
        
        printf("o peso ideal dessa pessoa é: %f", pesoIdealM);
    }
    else {
        printf("o peso ideal dessa pessoa é: %f", pesoIdealF);
    }

    return 0;
}