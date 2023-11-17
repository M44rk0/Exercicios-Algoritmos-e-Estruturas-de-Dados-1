//==============================================================================
// Arquivo conjunto.h
//==============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
//Define o tamanho maximo de elementos no conjunto
#define MAX_ELEMENTOS 1000000 
//Define as constantes
#define SUCESSO 1
#define FALHA 0
#define TRUE 1
#define FALSE 0 
#define CRESCENTE 1
#define DECRESCENTE 0
//Define o cabecalho das funcoes
typedef struct conjunto Conjunto;
int criaConjunto(Conjunto *C);
int conjuntoVazio(Conjunto *C);
int insereElementoConjunto(long int x, Conjunto *C);
int excluirElementoConjunto(long int x, Conjunto *C);
int tamanhoConjunto(Conjunto *C);
int maior(long int x, Conjunto *C);
int menor(long int x, Conjunto *C);
int pertenceConjunto(long int x, Conjunto *C);
int conjuntosIdenticos(Conjunto *C1, Conjunto *C2);
int subConjunto(Conjunto *C1, Conjunto *C2);
Conjunto complemento(Conjunto *C1, Conjunto *C2);
Conjunto uniao(Conjunto *C1, Conjunto *C2);
Conjunto interseccao(Conjunto *C1, Conjunto *C2);
Conjunto diferenca(Conjunto *C1, Conjunto *C2);
Conjunto conjuntoPartes(Conjunto *C);
void mostraConjunto(Conjunto *C, int ordem);
int copiarConjunto(Conjunto *C1, Conjunto *C2);
int destroiConjunto(Conjunto *C);
//==============================================================================
// Arquivo conjunto.c
//==============================================================================

/* Seguinte, o que é a porra de um TAD(TIPO ABSTRATO DE DADOS)? é basicamente e resumidamente a possibilidade de criar um novo tipo de dado, e as operações com esse dado.
Assim como tem o Int, o Double, e por aí vai, com o TAD tu cria o tipo que tu quiser.
Quero um tipo de dado 'Aluno', tranquilo, um aluno tem matricula, nome e email, logo... */

typedef struct aluno{ // aluno é o nome do tipo que tu quer criar
    unsigned int matricula; //( unsigned = sem sinal ) por que matricula negativa é foda
    char *nome;  // char e um ponteiro por que C é uma merda e não te deixa declarar uma String completa, vai ter que alocar o tamanho depois
    char *email;   // char de novo, vambora.
}Aluno; // e Aluno com maiusculo é o "apelido" desse tipo aluno, mas continua sendo Aluno, no fim, tu vai usar Aluno pra declarar.

/* Breve spoiler que tu não pediu mas que vai ser útil no próximo semestre. 
Em C, o TAD é um conceito muito mais simplificado.
Em orientação a objetos, o TAD vai ser um objeto, e as funções são os métodos.
Em C é bem merda o conceito mas nas outras linguagens isso faz mais sentido e a orientação a objetos é mais legal, 
tem Herança, Polimorfismo, escapsulamento e abstração... parece complicado,
mas é tranquilo de explicar, talvez eu consiga usar tua vó, tua mãe e tua irmã de exemplo, 
enfim, se ler isso aqui eu explico na sala.

Dito isso, C é uma merda :D 

Continuando...*/

//Define o struct Conjunto

//Aqui tu vai definir um conjunto, como eu já fiz um typedef ali em cima pq precisa separar essa merda, 
//aí é só passar o struct conjunto e os dados, pq o apelido dele tá declarado ali em cima.

struct conjunto{
    int tamanho; //tamanho pra ter como adicionar/remover/ e pasmem, saber o tamanho do conjunto
    long int *elementos; //aqui é um vetor de elementos, eu poderia simplesmente fazer elementos[MAX_ELEMENTOS] e pronto? sim, mas se eu faço isso o programa trava, então não.
};

//Uma breve explicação

//essa seta aqui que tu vai ver -> significa "Vai lá na mémoria de tal coisa" pq vamo usar ponteiro.
//Exemplo? C->tamanho "vai lá na mémoria do C, e muda algo no tamanho"
//Se não fosse ponteiro não ia ter seta, e sim um ponto, C.tamanho

//Outra breve explicação

//A identação desse código tá um lixo pq eu não queria que ficasse gigante
//Logo, alguns cantos aí não tem else, ou uma linha sem ser pulada
//Mas tá entendível

//Continuando...

//Funcao para criar um conjunto vazio
int criaConjunto(Conjunto *C){
    if(C != NULL){ //Na moralzinha, essa verificação não serve pra nada pq no fundo ele nunca vai ser NULL, já que precisa declarar ele na main, mas tá aí pra ter um return FALHA.
        C->elementos = (long int *)malloc(MAX_ELEMENTOS * sizeof(long int)); //Aqui ele vai alocar 1000000 de elementos (long int) pro vetor, que é o que o professor pediu.
        C->tamanho = 0; //E define o tamanho como 0, pq é pra criar ele vazio.
        return SUCESSO; //Esse SUCESSO e FALHA tá definido ali em cima, SUCESSO é 1, e FALHA  é 0
    }return FALHA;
}
//Funcao pra ver se o conjunto esta vazio
int conjuntoVazio(Conjunto *C){
    return (C != NULL && C->tamanho == 0) ? TRUE : FALSE; 
    //Daqui pra frente ve ser é NULL faz mais sentido, mas nem tanto, aqui ele só verifica se é vazio ou não.
    //Pra relembrar, o nome desse caralho aí é Ternário, o ? siginifica "se a condição for verdadeira" e o : "se a condição for falsa"
    //é basicamente um If que só funciona quando se tem uma unica condição
}
//Funcao pra iserir um elemento no conjunto
int insereElementoConjunto(long int x, Conjunto *C){
    if(C != NULL && C->tamanho < MAX_ELEMENTOS && x < LONG_MAX && x > LONG_MIN){
        for(int i = 0; i < C->tamanho; i++){
            if(C->elementos[i] == x) return FALHA; //aqui ele lança um for básico e vê se o elemento ja existe no conjunto, pq conjunto não tem repetição
        }
        C->elementos[C->tamanho] = x, C->tamanho++; //Se não tem, ele adiciona no vetor lá no inidice do tamanho, e soma +1 no tamanho.
        return SUCESSO;
    }return FALHA;
}
//Funcao pra exlucir um elemento do conjunto
int excluirElementoConjunto(long int x, Conjunto *C){
    if(C != NULL){
        int encontrado = FALSE; 
        for(int i = 0; i<C->tamanho; i++){
            if(C->elementos[i] == x){ //Vai caçar o que tu quer remover, se encontrar, TRUE, se não, ele retorna um FALSE ali em baixo e acaba
                encontrado = TRUE;
                for(int j = 0; j < C->tamanho - 1; j++){
                    C->elementos[j] = C->elementos[j+1]; //Aqui ele vai chegar os elementos pra direita, pra ocupar o lugar do elemento que vai ser excluido no vetor.
                }
                C->tamanho--; // E aí diminui um no tamanho pq tirou um
                break;
            }
        }return encontrado ? SUCESSO : FALHA;
    }return FALHA;
}
//Funcao pra calcular a cardinalidade do conjunto
int tamanhoConjunto(Conjunto *C){
    return (C != NULL) ? C->tamanho : 0; //Aqui retorna o tamanho do conjunto, IZI
}
//Funcao pra ver a quantidade de elementos maiores que X no conjunto
int maior(long int x, Conjunto *C){
    int maiores = 0;
    if(C != NULL){
        for(int i = 0; i < C->tamanho; i++){ 
            if(C->elementos[i] > x){ //Conta quantos elementos no conjunto são maiores que o valor que tu passou, IIZII
                maiores++;
            }
        }
        if(C->tamanho == maiores) return 0; //Aqui é esquisito, mas se todos forem maiores é pra retornar 0, PORÉM, se não tiver nenhum maior, também vai retornar 0
    }return maiores;
}
//Funcao pra ver a quantidade de elementos menores que X no conjunto 
int menor(long int x, Conjunto *C){
    int menores = 0;
    if(C != NULL){
        for(int i = 0; i < C->tamanho; i++){//Mema coisa do de cima, só que com menores
            if(C->elementos[i] < x){
                menores++;
            }
        }
        if(C->tamanho == menores) return 0;
    }return menores;
}
//Funcao pra verificar se o elemento X pertence ao conjunto
int pertenceConjunto(long int x, Conjunto *C){
    if(C != NULL){
        for(int i = 0; i < C->tamanho; i++){
            if(C->elementos[i] == x) return TRUE; //Só vê se o elemento tá lá memo, se tiver retorna TRUE, se não FALSE
        }return FALSE;
    }return FALSE;
}
//Funcao pra comparar se os conjuntos sao idênticos
int conjuntosIdenticos(Conjunto *C1, Conjunto *C2){
    if(C1 != NULL && C2 != NULL && C1->tamanho == C2->tamanho){ //Aqui ele já vê se são do mesmo tamanho, pq se não for já não da pra ser engual
        for(int i = 0; i < C1->tamanho; i++){
            long int elemento = C1->elementos[i]; 
            if(!pertenceConjunto(elemento, C2)) return FALSE; //Se são enguais no tamanho, ele vê se cada elemento do C1 tá no C2, se UMZINHO não tiver , ele já retorna FALSE
        }return TRUE;
    }return FALSE;
}
//Funcao pra verificar se C1 e subconjunto de C2
int subConjunto(Conjunto *C1, Conjunto *C2){
    if(C1 != NULL && C2 != NULL){
        for(int i = 0; i < C1->tamanho; i++){
            long int elemento = C1->elementos[i];
            if(!pertenceConjunto(elemento, C2)) return FALSE; //É mema coisa do de cima, só que sem a verificação do tamanho
        }return TRUE;
    }return FALSE;
}
//Funcao pra gerar o complemento de C1 em relacao a C2
Conjunto complemento(Conjunto *C1, Conjunto *C2){ // Aqui ele vai retonar um conjunto pronto, então o SUCESSO e FALHA vai pro caralho :D
    Conjunto complemento;
    criaConjunto(&complemento); //Cria um conjunto complemento, IZI
    if(C1 != NULL && C2 != NULL){
        for(int i = 0; i < C2->tamanho; i++){
            long int elemento = C2->elementos[i]; 
            if(!pertenceConjunto(elemento, C1)) insereElementoConjunto(elemento, &complemento); //Se o elemento de C2 não pertence ao de C1, ele adiciona esse elemento no Complemento
        }
    }return complemento; //E aí devolve o complemento
    //Mas Marco, e se todos do C2 pertencerem ao C1?? Aí retorna um conjunto vazio :D
}
//Funcao pra gerar a uniao de C1 com C2
Conjunto uniao(Conjunto *C1, Conjunto *C2){ //Mema porra do de cima, mas com uma lógica pra união
    Conjunto uniao;
    criaConjunto(&uniao);
    if(C1 != NULL && C2 != NULL){
        for(int i = 0; i < C1->tamanho; i++){
            insereElementoConjunto(C1->elementos[i], &uniao); //Já que união é o que tem em um ou no outro, ele vai inserir os dois "juntos"
        }
        for(int i = 0; i < C2->tamanho; i++){
            insereElementoConjunto(C2->elementos[i], &uniao); 
        }
    }return uniao;
}
//Funcao pra gerar a interseccao de C1 com C2
Conjunto interseccao(Conjunto *C1, Conjunto *C2){//mema. merda. mas com lógica de inter-sexão 
    Conjunto interseccao;
    criaConjunto(&interseccao);
    if(C1 != NULL && C2 != NULL){
        for(int i = 0; i < C1->tamanho; i++){
            long int elemento = C1->elementos[i];
            if(pertenceConjunto(elemento, C2)) insereElementoConjunto(elemento, &interseccao);
        }
    }return interseccao;
}
//Funcao pra gerar a diferenca de C1 e C2
Conjunto diferenca(Conjunto *C1, Conjunto *C2){//adivinhe
    Conjunto diferenca;
    criaConjunto(&diferenca);
    if(C1 != NULL && C2 != NULL){
        for(int i = 0; i < C1->tamanho; i++){
            long int elemento = C1->elementos[i];
            if(!pertenceConjunto(elemento, C2)) insereElementoConjunto(elemento, &diferenca);
        }
    }return diferenca;
}
//Sinceramente essa aqui eu não consegui pensar em como fazer // um beijao pro GPT <3
Conjunto conjuntoPartes(Conjunto *C) {//kkkkk num vo explica 
    Conjunto resultado;
    criaConjunto(&resultado);  
    if (C != NULL) {
        int n = C->tamanho;
        int numSubconjuntos = pow(2, n);
        for (int i = 0; i < numSubconjuntos; i++) {
            criaConjunto(&resultado);

            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) insereElementoConjunto(C->elementos[j], &resultado);
            }mostraConjunto(&resultado, CRESCENTE);
        }
    }return resultado;
}
//Funcao pra mostrar os elementos no conjunto
void mostraConjunto(Conjunto *C, int ordem){ //Aqui ele só printa, tranquilinho, se for CRESCENTE é de da esquerda pa direita, e DECRESCENTE, da direita pa esquerda
    if(C != NULL){
        if(ordem == CRESCENTE){
            printf("{");
            for(int i = 0; i < C->tamanho; i++){
                printf("%ld ", C->elementos[i]);
            }
        }else if (ordem == DECRESCENTE){
            printf("{");
            for(int i = C->tamanho - 1; i >= 0; i--){
                printf("%ld ", C->elementos[i]);
            }
        }printf("}\n");
    }
}
// Funcao para copiar um conjunto para outro
int copiarConjunto(Conjunto *C1, Conjunto *C2){ //Aqui copia um pro outro
    if (C1 != NULL && C2 != NULL){
        C2->tamanho = C1->tamanho; // Enguala os tamanhos 
        for (int i = 0; i < C1->tamanho; i++){
            C2->elementos[i] = C1->elementos[i]; //E oq tá no C2, recebe o que tá C1
        }return SUCESSO;
    }return FALHA;
}
// Funcao para destruir o conjunto
int destroiConjunto(Conjunto *C){ //Destroi é pra limpar o que tá salvo na memoria lá no conjunto que tu passar
    if (C != NULL){
        C->tamanho = 0;
        free(C->elementos);
        return SUCESSO;
    }return FALHA;
}
//Funcao auxiliar pra criar o conjunto C1 e conjunto C2

void AuxiliarCriarC1C2(Conjunto *C1, Conjunto *C2){ 
    /* Essa aqui é autoexplicativa, ela serve pra criar dois conjuntos pra aquelas operações que precisam de dois conjuntos.
    Eu poderia só criar mais um, e usar as funções com o conjunto C e esse mais um. Mas eu num quis.
    Então eu sempre crio duas novas pra cada operação, e cada vez, o C1 & C2 novos substituem o antigo.
    Eu fiz a função tbm pq, sem ela, eu teria que repetir essa caralhada de código aí pra cada operação com dois conjuntos lá no menu, e isso não é legal.
    E aí com ela aqui, eu só preciso de uma linha */
    criaConjunto(C1), criaConjunto(C2);
    printf("Quantos elementos em C1?: "); //E a diferença é que aqui eu posso escolher quantos elementos eu quero mete no conjunto, no conjunto C é um por vez
    int quantidade;
    while(1){
        scanf("%d", &quantidade);
        if(quantidade <= 0){
            printf("Quantidade invalida, tente novamente.\n");
            printf("Quantos elementos em C1?: ");
        }else break;
    }
    printf("Digite os elementos a serem inseridos em C1:\n");
    for(int i = 0; i<quantidade; i++){
        long int elemento;
        printf("%d elemento: ", i+1);
        scanf("%ld", &elemento);
        if(pertenceConjunto(elemento, C1)){
            printf("Elemento ja pertence ao conjunto, insira um novo elemento: \n"); //Aqui é um "loop" pra verificar se o elemento já tá lá ou não.
            i--;
        }
        else{
            insereElementoConjunto(elemento, C1);
        }
    }
    printf("Quantos elementos em C2?: ");
    int quantidade2;
    while(1){
        scanf("%d", &quantidade2);
        if(quantidade2 <= 0){
            printf("Quantidade invalida, tente novamente\n");
            printf("Quantos elementos em C2?: ");
        }else break;
    }
    printf("Digite os elementos a serem inseridos em C2:\n");
    for(int i = 0; i<quantidade2; i++){
        long int elemento2;
        printf("%d elemento: ", i+1);
        scanf("%ld", &elemento2);
        if(pertenceConjunto(elemento2, C2)){
            printf("Elemento ja pertence ao conjunto, insira um novo elemento: \n");
            i--;
        }
        else{
            insereElementoConjunto(elemento2, C2);
        }
    }
}
//Funcao pra printar linha :O
void printLinha(){
    printf("+-------------------------------------------------------------------------------------------------------------+\n");
}
//Funcao pra printar as opcões :O
void opcoes(){
    printLinha();
    printf("| [ 1] -> [Criar um conjunto C]                          |    [10] -> [Gerar conjunto das partes]             |\n");
    printf("| [ 2] -> [Verificar se o conjunto C e vazio]            |    [11] -> [Comparar conjuntos identicos]          |\n");
    printf("| [ 3] -> [Inserir um elemento no conjunto C]            |    [12] -> [Identificar subconjunto]               |\n");
    printf("| [ 4] -> [Excluir um elemento do conjunto C]            |    [13] -> [Gerar complemento de um conjunto]      |\n");
    printf("| [ 5] -> [Mostrar os elementos do conjunto C]           |    [14] -> [Gerar uniao de dois conjuntos]         |\n");
    printf("| [ 6] -> [Calcular a cardinalidade do conjunto C]       |    [15] -> [Gerar intersecao entre dois conjuntos] |\n");
    printf("| [ 7] -> [Verificar elementos maiores que um numero]    |    [16] -> [Gerar diferenca entre dois conjuntos]  |\n");
    printf("| [ 8] -> [Verificar elementos menores que um numero]    |    [17] -> [Copiar conjunto para outro]            |\n");
    printf("| [ 9] -> [Verificar pertinencia de um elemento]         |    [18] -> [Destruir conjunto]                     |\n");
}
//Funcao pra printar boas vindas :O
void boasVindas(){
    printLinha();
    printf("                                                                                                  _            \n");
    printf("  ___  _ __   ___ _ __ __ _  ___ __ _  ___     ___ ___  _ __ ___     ___ ___  _ __  _ _   _ _ __ | |_ ___  ___ \n");
    printf(" / _ \\| '_ \\ / _ \\ '__/ _` |/ __/ _` |/ _ \\   / __/ _ \\| '_ ` _ \\   / __/ _ \\| '_ \\| | | | | '_ \\| __/ _ \\/ __|\n");
    printf("| (_) | |_) |  __/ | | (_| | (__ (_| | (_) | | (__ (_) | | | | | | | (__ (_) | | | | | |_| | | | | |_ (_) \\__ \\ \n");
    printf(" \\___/| .__/ \\___|_|  \\__,_|\\___\\__,_|\\___/   \\___\\___/|_| |_| |_|  \\___\\___/|_| |_|_|\\__,_|_| |_|\\__\\___/|___/\n");
    printf("      | |                                                                         _/ |                        \n");
    printf("      |_|                                                                        |__/                         \n");
    printLinha();
    printf("|                                            Escolha uma opcao:                                               |\n");
    opcoes();
}

//Daqui pra baixo é quase tudo auto-explicativo 

//==============================================================================
// Corpo Principal
//==============================================================================
int main(){
    boasVindas(); //Funçãozinha ali pra printar bonitinho
    int escolha, criadoC = 0;
    while(escolha != 0){ //Menuzão infinito até que o mano digite 0
        Conjunto C, C1, C2; //Define aqui os conjuntos e pá, pq ngm é de ferro
        printLinha();
        printf("|                   [999] -> [Mostrar opcoes novamente] | [ 0 ] -> [Encerrar programa]                        |\n");
        printLinha();
        scanf("%d", &escolha);
        switch (escolha){
            case 999: {
                opcoes(); //Aqui se o mano digitar 999 vai mostrar as opções de novo, eu podia largar ela pra aparecer toda vez, mas aí fica feio
                break;
            }
            case 1: { //E aí cada case é uma opção
                if(criaConjunto(&C) == 1){ //Aqui especialmente tem um bagulho pica... 
                    printf("Conjunto criado com sucesso.\n");
                    criadoC = 1; //...Se o conjunto for criado, ele muda a variavel ali em cima 'CriadoC' pra 1, pra mostrar pro resto do código que este caralho já foi criado
                }else{printf("Erro na criacao.\n");
                }break;
            }
            case 2: {
                if(criadoC){ //E aí se for criado ele executa a função, e se não for...
                    (conjuntoVazio(&C) == 1) ? printf("Conjunto e vazio.\n") : printf("Conjunto nao e vazio.\n"); 
                    break;
                }printf("Erro, conjunto C ainda nao foi criado.\n"); 
                //...Ele printa que não vai rolar pq não tem conjunto, sem isso aqui,
                //...ia rodar com um conjunto inexsitente, e o código ia travar e explodir
                break;
            }
            case 3: {
                if(criadoC){
                    long int elemento;
                    printf("Digite o elemento a ser inserido no conjunto: ");
                    scanf("%ld", &elemento);
                    (insereElementoConjunto(elemento, &C) == 1) ? printf("Elemento inserido com sucesso.\n") : printf("Erro na insercao do elemento.\n");
                    break;
                }printf("Erro, conjunto C ainda nao foi criado.\n");
                break;
            }
            case 4: {
                if(criadoC){
                    long int elemento;
                    printf("Digite o elemento a ser excluido do conjunto: ");
                    scanf("%ld", &elemento);
                    (excluirElementoConjunto(elemento, &C) == 1) ? printf("Elemento excluido com sucesso.\n") : printf("Erro na exclusao do elemento.\n");
                    break;
                }printf("Erro, conjunto C ainda nao foi criado.\n");
                break;
            }
            case 5: {
                if(criadoC){
                    printf("Mostrar conjunto de forma Crescente[1] ou Descrescente[0]?: ");
                    int cres;
                    scanf("%d", &cres);
                    switch (cres) {
                        case 1:
                            mostraConjunto(&C, CRESCENTE);
                            break;
                        case 0:
                            mostraConjunto(&C, DECRESCENTE);
                            break;
                        default:
                            printf("Forma invalida, tente novamente!\n");
                            break;
                }break;
                }printf("Erro, conjunto C ainda nao foi criado.\n");
                break; 
            }
            case 6: {
                if(criadoC){
                    printf("Tamanho do conjunto: %d\n", tamanhoConjunto(&C));
                    break;
                }printf("Erro, conjunto C ainda nao foi criado.\n");
                break;
            }
            case 7: {
                if(criadoC && conjuntoVazio(&C) == 0){ //Aqui tem que verificar se foi criado E não e vazio, pq o conjunto pode tá criado, mas sem nada dentro, aí não rola
                    long int elemento;
                    printf("Digite um elemento: ");
                    scanf("%ld", &elemento);
                    printf("Elementos maiores que o numero dado: %d\n", maior(elemento, &C));
                    printf("(O valor 0 (zero) indica que todos os elementos de C sao maiores que x)\n");
                    break;
                }printf("Erro, conjunto C ainda nao foi criado ou e vazio.\n");
                break;
            }
            case 8: {
                if(criadoC && conjuntoVazio(&C) == 0){ // mema coisa do de cima
                    long int elemento;
                    printf("Digite um elemento: ");
                    scanf("%ld", &elemento);
                    printf("Elementos menores que o numero dado: %d\n", menor(elemento, &C));
                    printf("(O valor 0 (zero) indica que todos os elementos de C sao maiores que x)\n");
                    break;
                }printf("Erro, conjunto C ainda nao foi criado ou e vazio.\n");
                break;
            }
            case 9: {
                if(criadoC && conjuntoVazio(&C) == 0){ // mema coisa do de cima do de cima
                    long int elemento;
                    printf("Digite um elemento: ");
                    scanf("%ld", &elemento);
                    (pertenceConjunto(elemento, &C) == 1) ? printf("O elemento dado pertence ao conjunto.\n") : printf("O elemento dado nao pertence ao conjunto.\n");
                    break;
                }printf("Erro, conjunto C ainda nao foi criado ou e vazio.\n");
                break;
            }
            case 10: {
                if(criadoC){
                    conjuntoPartes(&C);
                    break;
                }printf("Erro, conjunto C ainda nao foi criado.\n");
                break;
            }
            case 11: {
                AuxiliarCriarC1C2(&C1, &C2);//Aqui cria os dois conjuntos e pá
                (conjuntosIdenticos(&C1, &C2) == 1) ? printf("Os conjuntos sao identicos.\n") : printf("Os conjuntos nao sao identicos.\n");
                break;
            }
            case 12: {
                AuxiliarCriarC1C2(&C1, &C2);
                (subConjunto(&C1, &C2) == 1) ? printf("C1 e subconjunto de C2.\n") : printf("C1 nao e subconjunto de C2.\n");
                break;
            }
            case 13: {
                AuxiliarCriarC1C2(&C1, &C2);
                Conjunto complementoC1 = complemento(&C1, &C2);
                mostraConjunto(&complementoC1, CRESCENTE);
                break;
            }
            case 14: {
                AuxiliarCriarC1C2(&C1, &C2);
                Conjunto uniaoC1 = uniao(&C1, &C2);
                mostraConjunto(&uniaoC1, CRESCENTE);
                break;
            }
            case 15: {
                AuxiliarCriarC1C2(&C1, &C2);
                Conjunto interseccaoC1 = interseccao(&C1, &C2);
                mostraConjunto(&interseccaoC1, CRESCENTE);
                break;
            }
            case 16: {
                AuxiliarCriarC1C2(&C1, &C2);
                Conjunto diferencaC1 = diferenca(&C1, &C2);
                mostraConjunto(&diferencaC1, CRESCENTE);
                break;
            }
            case 17: {
                AuxiliarCriarC1C2(&C1, &C2);
                if(copiarConjunto(&C1, &C2) == 1){
                    printf("Copiado com sucesso!\n");
                    mostraConjunto(&C2, CRESCENTE);
                }else{printf("Erro na copia.\n");
                }break;
            }
            case 18: {//Aqui tu escolhe qual q quer destruir e limpar a mémoria
                printf("Qual conjunto destruir? (C = 0, C1 & C2 = 1): \n");
                int opcao;
                scanf("%d", &opcao);
                switch (opcao){
                case 0: {
                    criadoC = 0;
                    (destroiConjunto(&C) == 1) ? printf("Conjunto C destruido com sucesso.\n") : printf("Erro na destruicao do Conjunto C.\n");
                    break;
                }
                case 1: {
                    (destroiConjunto(&C1) == 1 && destroiConjunto(&C2) == 1) ? printf("Conjunto C1 e C2 destruidos com sucesso.\n") : printf("Erro na destruicao dos Conjuntos.\n");
                    break;
                }
                default:
                    printf("Opcao invalida. Tente novamente.\n");
                    break;
                }break;
            }
            case 0: {//E aqui encerra o programa e destroi todos os conjuntos :D
                printf("Encerrando programa.\n");
                destroiConjunto(&C), destroiConjunto(&C1), destroiConjunto(&C2);
                break;
            }
            default:
                printf("Opcao invalida. Tente novamente.\n"); //E esse aqui é um caso default, se tu tentar escolher um case fora dos que tão definidos ele te joga pro inicio
                break;
        }
    } 
    return 0;
}
