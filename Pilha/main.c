#include "pilha.h"

int menu(){
    puts("----- Menu pilha -----");
    puts("1 - Push");
    puts("2 - Pop");
    puts("3 - Mostrar Todos Elementos");
    puts("4 - Verifica se a pilha esta vazia");
    puts("5 - Zerar pilha");
}

int main(){
    stack *pilha;
    criaPilha(pilha);
    exibirTodosElementos(pilha);
    puts("Foi implementado");
    free(pilha);
    return 0;
}