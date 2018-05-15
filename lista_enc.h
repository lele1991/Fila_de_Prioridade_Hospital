#ifndef LISTA_ENC_H_INCLUDED
#define LISTA_ENC_H_INCLUDED

#include "no.h"

typedef struct listas_enc lista_enc_t;

lista_enc_t *cria_lista_enc(void);
void add_cauda(lista_enc_t *lista, no_t* elemento);

no_t * remove_elem(lista_enc_t *lista, int index);

no_t *obtem_cabeca(lista_enc_t *lista);

void swap_list(lista_enc_t *list, no_t *fonte, no_t *destino);

#endif // LISTA_ENC_H_INCLUDED
