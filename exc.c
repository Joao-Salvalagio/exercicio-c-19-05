//Atividade 02 - Menu para pilha - Até 19/05/2025 as 23:59
//Utilizado o a pilha estática utilizada em sala de aula, implemente um menu que permita ao usuário escolher entre as ações de empilhar (push), desempilhar (pop) e imprimir a pilha.
//A pilha implementada em sala pode ser acessada nesse link: https://github.com/biazottoj/unicesumar2025/blob/main/estrutura%20de%20dados/src/pilha.cpp.txt
//O atividade vale 0,2 referente a parte prática da disciplina
//Crie um repositório no Github com o código do projeto, e encaminhe o link.
//Para a entrega desse trabalho, utilize o link: https://forms.gle/LwtBTEc2B4Qqt1qp7

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#define TAMANHO 5

int stack[TAMANHO];
int top = -1;

bool isEmpty() {
    return top == -1;
}

void push(int data) {
    if (top == TAMANHO - 1) {
        printf("Pilha Cheia!\n");
        return;
    }
    top++;
    stack[top] = data;
    printf("Valor %d empilhado.\n", data);
}

void imprime_pilha() {
    if (isEmpty()) {
        printf("Pilha Vazia\n");
        return;
    }
    printf("Conteúdo da pilha: ");
    for (int i = 0; i <= top; i++) {
        printf("%d -> ", stack[i]);
    }
    printf("topo\n");
}

void topo() {
    if (isEmpty()) {
        printf("Pilha Vazia!\n");
        return;
    }
    printf("Topo => %d\n", stack[top]);
}

int pop() {
    if (isEmpty()) {
        printf("Pilha Vazia!\n");
        return -1;
    }
    int temp = stack[top];
    top--;
    return temp;
}

int main() {
    int choice, dado;
    setlocale(LC_ALL, "portuguese");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Empilhar (push)\n");
        printf("2. Desempilhar (pop)\n");
        printf("3. Imprimir pilha\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Informe um número para empilhar: ");
                scanf("%d", &dado);
                push(dado);
                break;
            case 2:
                dado = pop();
                if (dado != -1) {
                    printf("Valor removido da pilha: %d\n", dado);
                }
                break;
            case 3:
                imprime_pilha();
                break;
            case 4:
                printf("Encerrando programa...\n");
                exit(0);
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    system ("pause");

    return 0;
}