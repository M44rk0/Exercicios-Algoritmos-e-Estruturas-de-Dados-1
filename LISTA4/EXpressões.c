#include <stdio.h>
#include <stdlib.h>

// Estrutura de pilha para verificar a bem definição das expressões
typedef struct StackNode {
    char data;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} Stack;

// Funções para operações na pilha
void push(Stack* stack, char data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

char pop(Stack* stack) {
    if (stack->top == NULL) {
        return '\0';  // Pilha vazia
    }

    char data = stack->top->data;
    StackNode* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);

    return data;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Função para verificar se a expressão é bem definida
char checkWellFormed(char* expression) {
    Stack stack;
    stack.top = NULL;
    int i;
    for (i = 0; expression[i] != '\0'; i++) {
        char currentChar = expression[i];

        if (currentChar == '(' || currentChar == '[' || currentChar == '{') {
            push(&stack, currentChar);
        } else if (currentChar == ')' || currentChar == ']' || currentChar == '}') {
            char poppedChar = pop(&stack);

            if (poppedChar == '\0' ||
                (currentChar == ')' && poppedChar != '(') ||
                (currentChar == ']' && poppedChar != '[') ||
                (currentChar == '}' && poppedChar != '{')) {
                return 'N';
            }
        }
    }

    return isEmpty(&stack) ? 'S' : 'N';
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        char expression[1001];
        scanf("%s", expression);

        char result = checkWellFormed(expression);
        printf("%s\n", result == 'S' ? "bem-formada" : "mal-formada");
    }

    return 0;
}
