#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include "listaSimplesAlunos.h"

struct listaSimplesAlunos{
    char nome[50] ;
    int ra;
    float nota1;
    float nota2;
    float media;
    struct listaSimplesAlunos *prox;
};

typedef struct listaSimplesAlunos Alunos;


//M�TODOS DE USO INTERNO
int menuAtualiza(){
  int op;
  printf("\nO que deseja editar?");
  printf("\n1-Nome do aluno");
  printf("\n2-Nota 1");
  printf("\n3-Nota 2");
  scanf(" %i", &op);
  return op;
}

float calcularMedia(float n1, float n2){
    return (n1+n2)/2;
}

Alunos *buscar(Alunos *L, int raBusca){
	Alunos *achou, *aux = L;
	achou = NULL;
	while (aux != NULL){
		if (aux->ra == raBusca){
			achou = aux;
		}
		else{
			aux = aux->prox;
		}
	}
	return achou;
}

//M�TODOS PARA A MAIN

Alunos *criar(){
	return NULL;
}

Alunos *alocar(char nome[50] , int ra, float n1, float n2){
	Alunos *novo = (Alunos *) malloc (sizeof(Alunos));
	if(novo == NULL){
		printf("Erro na reserva de memoria");
	}else{
    strcpy(novo->nome, nome);
		novo->ra = ra;
		novo->nota1 = n1;
		novo->nota2 = n2;
		novo->media = calcularMedia(n1, n2);
		novo->prox = NULL;
	}
	return novo;
}

Alunos *inserirInicio(Alunos* L, char nome[50] , int ra, float n1, float n2){
  Alunos *aux, *novo;
  novo = alocar(nome, ra, n1, n2);
  aux = L;
  if(aux == NULL){
  	aux = novo;
  }else{
    novo->prox = aux;
    aux = novo;
  }
	return aux;
}

Alunos *inserirFim(Alunos* L, char nome[50] , int ra, float n1, float n2){
	Alunos *aux, *novo;
	novo = alocar(nome, ra, n1, n2);
  aux = L;
	if (aux == NULL){ // Confere se L ainda est� vazia
		aux = novo;
	}else{ // Se L n�o estiver vazia
		while (aux->prox != NULL){ //roda a lista at� achar o �ltimo
			aux = aux->prox;
		}
		aux->prox = novo;
	}
	return aux;
}



Alunos *buscarMaiorMedia(Alunos *L){
	Alunos *maiorMedia, *aux = L;
	maiorMedia = NULL;
	if(aux == NULL){
        printf("A lista est� vazia");
	}else{
        while (aux != NULL){
            if (aux->media > maiorMedia->media){
                maiorMedia = aux;
            }
            else{
                aux = aux->prox;
            }
        }
	}
  return maiorMedia;
}

void mostraAluno(Alunos *aluno){
  if (aluno == NULL){
		printf("Campo vazio!");
	}else{
      printf("\n__________________________");
			printf("\nNome do aluno: %s", aluno->nome);
      printf("\nRa: %i", aluno->ra);
      printf("\nNota 1: %.2f", aluno->nota1);
      printf("\nNota 2: %.2f", aluno->nota2);
      printf("\nMedia: %.2f", aluno->media);
      printf("\n__________________________");
		}
	}

void alterarDados(Alunos *L, int raAlterar){
  Alunos *alunoPraMudar, *aux = L;
  char nome[50] ;
  float n1, n2;
  alunoPraMudar = buscar(aux, raAlterar);
  if(alunoPraMudar!=NULL){
    int op = menuAtualiza();
    switch(op) {
      case 1:
        printf("\nInforme o nome:");
        scanf("%[^\n]s", nome);
        strcpy(alunoPraMudar->nome, nome);
        printf("\nPronto! O novo nome eh: %s", alunoPraMudar->nome);
        break;
      case 2:
        printf("\nInforme a nota 1:");
        scanf("%f", n1);
        alunoPraMudar->nota1 = n1;
        alunoPraMudar->media = calcularMedia(alunoPraMudar->nota1, alunoPraMudar->nota2);
        printf("\nPronto! A nova nota eh %f e a nova media eh %f", alunoPraMudar->nota1, alunoPraMudar->media);
        break;
      case 3:
        printf("\nInforme a nota 2:");
        scanf("%f", n2);
        alunoPraMudar->nota2 = n2;
        alunoPraMudar->media = calcularMedia(alunoPraMudar->nota1, alunoPraMudar->nota2);
        printf("\nPronto! A nova nota eh %f e a nova media eh %f", alunoPraMudar->nota2, alunoPraMudar->media);
        break;
      default:
        printf("A op��o eh invalida");
        break;
    }
  }
}

void mostrar(Alunos *L){
	Alunos *aux;
	aux = L;
	if (aux == NULL){
		printf("Lista vazia!");
	}
	else{
		while (aux != NULL){
      printf("\n__________________________");
			printf("\nNome do aluno: %s", aux->nome);
      printf("\nRa: %i", aux->ra);
      printf("\nNota 1: %.2f", aux->nota1);
      printf("\nNota 2: %.2f", aux->nota2);
      printf("\nMedia: %.2f", aux->media);
      printf("\n__________________________");
      aux = aux->prox;
		}
	}
}

void mostrarAprovados(Alunos *L){
    Alunos *aux;
    aux = L;
	if (aux == NULL){
		printf("Lista vazia!");
	}else{
        printf("\nLista dos aprovados:");
		while (aux != NULL){
            if(aux->media>=6.0){
                printf("\n__________________________");
                printf("\nNome do aluno: %s", aux->nome);
                printf("\nRa: %i", aux->ra);
                printf("\nNota 1: %f", aux->nota1);
                printf("\nNota 2: %f", aux->nota2);
                printf("\nMedia: %f", aux->media);
                printf("\n__________________________");
            }
            aux = aux->prox;
		}
	}
}

void mostrarReprovados(Alunos *L){
    Alunos *aux;
	aux = L;
	if (aux == NULL){
		printf("Lista vazia!");
	}else{
        printf("\nLista dos reprovados:");
		while (aux != NULL){
            if(aux->media<6.0){
                printf("\n__________________________");
                printf("\nNome do aluno: %s", aux->nome);
                printf("\nRa: %i", aux->ra);
                printf("\nNota 1: %f", aux->nota1);
                printf("\nNota 2: %f", aux->nota2);
                printf("\nMedia: %f", aux->media);
                printf("\n__________________________");
            }
            aux = aux->prox;
		}
	}
}

Alunos *excluir(Alunos *L, int ra){
 	Alunos *excluir, *aux = L;
	excluir = buscar(aux, ra);
	if(excluir != NULL){
		if (aux == excluir){ 	//se for excluir o primeiro
			aux = excluir->prox;
		}else{
			while(aux->prox!= excluir) {
				aux = aux->prox;
			}
			aux->prox = excluir->prox;
		}
		free(excluir); // OU delete excluir; //(em C++)
	}
	else{
		printf("\nElemento nao encontrado");
	}
	return aux;
 }

 void liberar(Alunos *L){
	Alunos *excluir;
	while(L != NULL){
	 	excluir = L;
		L = L->prox;
		free(excluir);
	}
	free(L);
}
