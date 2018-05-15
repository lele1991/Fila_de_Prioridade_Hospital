#ifndef PRIORIDADE_HOSPITAL_H_INCLUDED
#define PRIORIDADE_HOSPITAL_H_INCLUDED
#include "lista_enc.h"

typedef struct hospital hospital_t;

hospital_t *cria_hospital(int id, char *nome, int idade, char *gravidade, char *tipo);
lista_enc_t *ler_arquivo(char *nome_arquivo);
hospital_t *cria_paciente(int id, char *nome, int idade, char *gravidade, char *tipo);

void imprimir_lista(lista_enc_t *lista);
void libera_geral(lista_enc_t *lista);

#endif // PRIORIDADE_HOSPITAL_H_INCLUDED
