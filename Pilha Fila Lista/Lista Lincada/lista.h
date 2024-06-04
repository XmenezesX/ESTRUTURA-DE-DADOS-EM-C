#include <stdlib.h>
#include <stdio.h>

typedef struct Lista
{
    int valor;
    int tamanhoLista;
    struct Lista *No;
}list;

void tamanhoLista(list *lista){
    printf("Tamanho da Lista : %d\n\n", lista->tamanhoLista);
}

void iniciaLista(list *lista){
    lista->No = NULL;
    lista->tamanhoLista = 0;
}

list* alocaNovoValor(){
    list *novo = (list *) malloc(sizeof(list));
    if(!novo){
        puts("Erro de alocacao!");
        exit(1);
    }
    novo->No = NULL;
    puts("Digite um novo valor para lista:");
    scanf("%d", &novo->valor);
    return novo;
}

int empty(list *lista){
    if (lista->tamanhoLista == 0)
        return 1;
    else
        return 0;
}

void imprimirLista(list *lista){
    if (empty(lista)){
        puts("Lista vazia\n");
        return;
    }
    
    list *auxiliar = lista->No;
    while (auxiliar != NULL)
    {
        printf("%d ", auxiliar->valor);
        auxiliar = auxiliar->No;
    }
    puts("\n");
}

void push(list *lista){
    list *novo = alocaNovoValor();
    if (empty(lista))
    {
        lista->No = novo;
    }
    else
    {
        
        list *temp = lista->No;
        while (temp->No !=NULL)
        {
            temp = temp->No;
        }
        
        temp->No = novo;
    }
    lista->tamanhoLista++;
    puts("Elemento adicionado com sucesso!\n");
}

void pop(list *lista){
    if (empty(lista))
    {
        puts("Lista Vazia!\n");
        return ;
    }
    int posicao;
    puts("Digite a posicao do elemento que deseja retirar");
    scanf("%d", &posicao);
    while (posicao < 1 || posicao > lista->tamanhoLista)
    {
        printf("Posicao Invalida! Digite novamente: [1 - %d]\n", lista->tamanhoLista);
        scanf("%d", &posicao);
    }
    
    list *temp = lista, *removido, *proximo;
    int valorRemovido;
    for (int i = 0; temp!=NULL && i < posicao - 1; i++)
    {
        temp = temp->No;
    }

    if (temp->No->No != NULL) // verifica se existe proximo elemento do excluido 
    {
        proximo = temp->No->No;
        removido = temp->No;
        valorRemovido = removido->valor;
        free(removido);
        temp->No = proximo;
    }
    else
    {
        removido = temp->No;
        valorRemovido = removido->valor;
        free(removido);
        temp->No = NULL;
    }
    lista->tamanhoLista--;
    printf("Elemento Removido com Sucesso :%d!\n", valorRemovido);
}

