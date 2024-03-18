#include "fila.h"

int menu(){
    int opcao;
    puts("----- Menu Fila -----");
    puts("1 - Push");
    puts("2 - Pop");
    puts("3 - Mostrar Todos Elementos");
    puts("4 - Verifica se a fila esta vazia");
    puts("0 - Sair");
    puts("----------------------");
    puts("Digite sua opcao:");
    scanf("%d", &opcao);
    return opcao;
}

void menuOpcoes(int opcao){
    int novoNumero;
    switch(opcao){
        case 0:
            return;
            break;

        case 1:
            puts("Digite um numero para inserir na fila:");
            scanf("%d", &novoNumero);
            push(novoNumero);
            break;

        case 2:
            pop();
            break;

        case 3:
            exibe();
            break;

        case 4:
            if (empty())
                puts("Fila Vazia");
            else
                puts("Fila com elementos");
            break;

        default:
            printf("Comando invalido\n\n");
            break;
    }
}

int main(){
    int opcao;
    inicio = final = 0;

    do{
        opcao = menu();
        menuOpcoes(opcao);
    }while (opcao);

    puts("Programa Encerrado");
    return 0;
}