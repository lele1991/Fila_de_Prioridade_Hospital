#include <stdio.h>
#include <stdlib.h>

#include "lista_enc.h"
#include "no.h"

// #define DEBUG

struct listas_enc {
    no_t *cabeca;
    no_t *cauda;
    int tamanho;
};

/* Funções privadas */
void swap_nos(lista_enc_t *lista, no_t *fonte, no_t *destino);

//cria uma lista vazia
lista_enc_t *cria_lista_enc (void) {
    lista_enc_t *p = malloc(sizeof(lista_enc_t));

    if (p == NULL){
        perror("cria_lista_enc:");
        exit(EXIT_FAILURE);
    }

    p->cabeca = NULL;
    p->cauda = NULL;
    p->tamanho = 0;

    return p;
}

void add_cauda(lista_enc_t *lista, no_t* elemento){
    if (lista == NULL || elemento == NULL){
        fprintf(stderr,"add_cauda: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

   #ifdef DEBUG
   printf("Adicionando %p --- tamanho: %d\n", elemento, lista->tamanho);
   #endif // DEBUG

   //lista vazia
   if (lista->tamanho == 0)
   {
        #ifdef DEBUG
        printf("add_cauda: add primeiro elemento: %p\n", elemento);
        #endif // DEBUG

        lista->cauda = elemento;
        lista->cabeca = elemento;
        lista->tamanho++;

        desliga_no(elemento);
   }
   else {
        // Remove qualquer ligacao antiga
        desliga_no(elemento);
        // Liga cauda da lista com novo elemento
        liga_nos(lista->cauda, elemento);

        lista->cauda = elemento;
        lista->tamanho++;
   }
}

no_t *obtem_cabeca(lista_enc_t *lista){

    if (lista == NULL){
        fprintf(stderr,"obtem_cabeca: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    return lista->cabeca;
}

no_t * busca_antecessor(lista_enc_t *lista, no_t *no){

    no_t *meu_no, *ant = NULL;

    meu_no = lista->cabeca;

    while (meu_no){

    	if (meu_no == no)
    		return ant;

        ant = meu_no;
        meu_no = obtem_proximo(meu_no);
    }

    return NULL;
}


void swap_nos(lista_enc_t *lista, no_t *fonte, no_t *destino){
    no_t *fonte_anterior = busca_antecessor(lista, fonte);
    no_t *destino_proximo = obtem_proximo(destino);

    if (fonte_anterior != NULL)
        liga_nos(fonte_anterior, destino);

    if (destino_proximo == NULL)
        desliga_no (fonte);
    else
        liga_nos(fonte, destino_proximo);

    liga_nos(destino, fonte);
}

void swap_list(lista_enc_t *list, no_t *fonte, no_t *destino){
    if (list == NULL) {
        fprintf(stderr, "swap_list: Invalid pointer!");
        exit(EXIT_FAILURE);
    }

    if (list->cabeca == fonte)
        list->cabeca = destino;

    if (list->cauda == destino)
        list->cauda = fonte;


    swap_nos(list, fonte, destino);
}


