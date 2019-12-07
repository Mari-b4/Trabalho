#include <stdio.h>
#include <stdlib.h>
#include "Circular_Dupla.h"


struct tipo_lista
{
    int valor;
    struct tipo_lista *pred;
    struct tipo_lista *prox;
};

CircularDupla *criar()
{
    return NULL;
}

CircularDupla *alocar(int valor)
{
    CircularDupla *novo = (CircularDupla *) malloc (sizeof(CircularDupla));
    if(novo == NULL)
    {
        printf("Erro na reserva de memoria");
    }
    else
    {
        novo->valor = valor;
        novo->pred = NULL;
        novo->prox = NULL;
    }
    return novo;
}

CircularDupla *inserirFim(CircularDupla* L, int valor)
{
    CircularDupla *novo=alocar(valor);
    if(L==NULL)
    {
        L=novo;
        L->prox=L;
        L->pred=L;
    }
    else
    {
        novo->prox=L;
        novo->pred=L->pred;
        L->pred->prox=novo;
        L->pred=novo;
    }
    return L;
}


CircularDupla *inserirInicio(CircularDupla* L, int valor)
{
    CircularDupla *novo = alocar(valor);
    if(L==NULL)
    {
        L=novo;
        L->prox=L;
        L->pred=L;
    }
    else
    {
        novo->prox=L;
        novo->pred=L->pred;
        L->pred->prox=novo;
        L->pred = novo;
        L=novo;
    }
    return L;
}

CircularDupla *inserirOrdem(CircularDupla *L, int valor)
{
    CircularDupla *aux=L, *novo=alocar(valor);

    if(L==NULL)
    {
        L=novo;
        L->prox=L;
        L->pred=L;
    }
    else
    {
        do
        {
            if(aux->valor>aux->prox->valor)
            {
                //if(aux->pred->valor<aux->valor){
                aux->pred->prox=novo->pred;
                aux->prox->pred=novo->prox;
            }
            //}
            else
            {
                aux=aux->prox;
            }
        }
        while(aux!=L);
    }
    return L;
}

CircularDupla *buscar(CircularDupla *L, int dado)
{
    CircularDupla *aux, *achou=NULL;
    aux = L;
    do
    {
        if(aux->valor==dado)
        {
            achou=aux;
            break;
        }
        else
        {
            aux=aux->prox;
        }
    }
    while(aux!=L);
    return achou;
}

void mostrar(CircularDupla *L)
{
    CircularDupla *aux;
    aux = L;
    if (aux == NULL)
    {
        printf("Lista vazia!");
    }
    else
    {
        do
        {
            printf("\n__________________________");
            printf("\n%i", aux->valor);
            printf("\n__________________________");
            aux = aux->prox;
        }
        while(aux!=L);
    }
}

CircularDupla *excluir (CircularDupla *L, int dado)
{
    CircularDupla *aux = buscar(L, dado);
    printf("%d", aux->valor);
    if (aux != NULL)
    {
        if (aux == L)
        {
            if(aux->prox == L)
            {
                free(aux);
                L = NULL;
                return L;
            }
            L = aux->prox;
        }
        if (aux == L->pred)
        {
            L->pred = aux->pred;
        }
        aux->prox->pred = aux->pred;
        aux->pred->prox = aux->prox;
        free(aux);
        return L;

    }
    else
    {
        printf("\nElemento nao encontrado");
    }
    return L;
}



void liberar(CircularDupla *L)
{
    CircularDupla *excluir;
    while(L!=NULL)
    {
        excluir=L;
        L=L->prox;
        free(excluir);
    }
    free(L);
}

