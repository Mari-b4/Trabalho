

#ifndef LISTA_DUPLA_H_INCLUDED
#define LISTA_DUPLA_H_INCLUDED

//tipo exportadotypedef
typedef struct tipo_lista CircularDupla;

//funcoes exportadas
CircularDupla*criar();
CircularDupla*alocar(int dado);
CircularDupla* inserirInicio(CircularDupla* L, int valor);
CircularDupla* inserirFim(CircularDupla* L, int valor);
CircularDupla* buscar(CircularDupla* L, int dado);
CircularDupla *excluir (CircularDupla *L, int dado);
CircularDupla *inserirOrdem(CircularDupla *L, int valor);
void mostrar(CircularDupla* L);
void liberar(CircularDupla *L);


#endif // CircularDupla_H_INCLUDED
