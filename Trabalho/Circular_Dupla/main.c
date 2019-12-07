#include "Circular_Dupla.h"
#include <stdio.h>
#include <stdlib.h>

int menu(){
    int opcao;
    printf("\nOpcoes:");
    printf("\n0. Sair");
    printf("\n1. Inserir um numero no inicio da lista");
    printf("\n2. Inserir um numero no fim da lista");
    printf("\n3. Mostrar a lista");
    printf("\n4. Excluir um elemento da lista");
    printf("\n5. Inserir");
    printf("\nInforme a opcao: ");
    scanf("%d", &opcao);
    return opcao;
    }

int main(){
    int opcao, elemento;
    CircularDupla *L;
    L = criar();
    do{
        opcao = menu();
        switch (opcao)
        {
        case 1:
            printf("\nInforme o valor: ");
            scanf("%d", &elemento);
            L = inserirInicio(L, elemento);
            break;
        case 2:
            printf("\nInforme o valor: ");
            scanf("%d", &elemento);
            L = inserirFim(L, elemento);
            break;
        case 3:
            printf("\nElementos da lista: ");
            mostrar(L);
            break;
        case 4:
            printf("\nInforme o valor a ser excluido: ");
            scanf("%d", &elemento);
            L = excluir(L, elemento);
            break;
        case 5:
          printf("\nInforme o valor: ");
          scanf("%d", &elemento);
          L = inserirOrdem(L, elemento);
         break;
        }
    } while(opcao);
    liberar(L);
    return 0;
}
