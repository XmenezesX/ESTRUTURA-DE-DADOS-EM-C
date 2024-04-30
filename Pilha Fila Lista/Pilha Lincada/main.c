#include "pilha.h"

int menu(){
    int opcao;
    puts("----- Menu pilha -----");
    puts("1 - Push");
    puts("2 - Pop");
    puts("3 - Mostrar Todos Elementos");
    puts("4 - Verifica se a pilha esta vazia");
    puts("5 - Zerar pilha");
    puts("6 - Tamanho da pilha");
    puts("0 - Sair");
    puts("----------------------");
    puts("Digite sua opcao:");
    scanf("%d", &opcao);
    return opcao;
}

void menuOpcoes(int opcao, stack *pilha){
    switch(opcao){
        case 0:
            liberarPilha(pilha);
            break;

        case 1:
            push(pilha);
            break;

        case 2:
            pop(pilha);
            break;

        case 3:
            exibirTodosElementos(pilha);
            break;

        case 4:
            if (empty(pilha))
                puts("Pilha Vazia");
            else
                puts("Pilha com elementos");
            break;

        case 5:
            liberarPilha(pilha);
            criaPilha(pilha);
            break;

        case 6:
            tamanhoPilha(pilha);
            break;

        default:
            printf("Comando invalido\n\n");
            break;
    }
}

int main(){
    int opcao;
    stack *pilha = (stack *)malloc(sizeof(stack));
    if (pilha == NULL)
    {
        puts("Erro na Alocação da pilha");
        exit(1);
    }
    criaPilha(pilha);

    do{
        opcao = menu();
        menuOpcoes(opcao, pilha);
    }while (opcao);
    puts("Programa Encerrado");
    return 0;
}