#include "fila.h"

int menu(){
    int opcao;
    puts("\n----- Menu pilha -----");
    puts("1 - Push");
    puts("2 - Pop");
    puts("3 - Mostrar Todos Elementos");
    puts("5 - Zerar pilha");
    puts("6 - Tamanho da pilha");
    puts("0 - Sair");
    puts("----------------------");
    puts("Digite sua opcao:");
    scanf("%d", &opcao);
    return opcao;
}

void menuOpcoes(int opcao, Fila *fila){
    switch(opcao){
        case 0:
            liberarFila(fila);
            break;

        case 1:
            push(fila);
            break;

        case 2:
            pop(&fila);
            break;

        case 3:
            exibirTodosElementos(fila);
            break;

        case 5:
            liberarFila(fila);
            criaFila(fila);
            break;

        case 6:
            tamanhoFila(fila);
            break;

        default:
            printf("Comando invalido\n\n");
            break;
    }
}

int main(){
    int opcao;
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    if (fila == NULL)
    {
        puts("Erro na Alocação da fila");
        exit(1);
    }
    criaFila(fila);

    do{
        opcao = menu();
        menuOpcoes(opcao, fila);
    }while (opcao);
    puts("Programa Encerrado");
    return 0;
}