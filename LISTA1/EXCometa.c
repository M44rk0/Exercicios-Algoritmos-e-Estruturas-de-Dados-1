#include <stdio.h>

int main() {
    
	int ano, quantidadeVezes, proximoAno;
	
	scanf("%d", &ano);
	
    quantidadeVezes = (ano - 10) / 76;
    proximoAno = (quantidadeVezes + 1) * 76 + 10;
    printf("%d", proximoAno);
    	
	return 0;
}
