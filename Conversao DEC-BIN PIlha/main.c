#include "pilha.h"

int menu(){
    int opcao;
    puts("----- Menu Conversao -----");
    puts("1 - Transformar Binario para Decimal");
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
            puts("Digite um numero em decimal:");
            scanf("%d", &novoNumero);
            decimalToBinario(novoNumero);
            break;

        default:
            printf("Comando invalido\n\n");
            break;
    }
}

int main(){
    int opcao;
    do{
        opcao = menu();
        menuOpcoes(opcao);
    }while (opcao);

    puts("Programa Encerrado");
    return 0;
}