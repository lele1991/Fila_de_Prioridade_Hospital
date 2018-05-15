#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "PRIORIDADE_HOSPITAL.h"
#include "lista_enc.h"
#include "no.h"

#define TAM_BUFFER 100
#define DEBUG

struct hospital {
	int id;
	char *nome; //malloc
	int idade;
	char *gravidade;
	char *tipo;
};

hospital_t *cria_hospital(int id, char *nome, int idade, char *gravidade, char *tipo){
    hospital_t *hospital;

    hospital = malloc(sizeof(hospital_t));

    if (hospital == NULL){

		perror("cria_hospital(struct)");
		exit(EXIT_FAILURE);
	}

    hospital->nome = malloc(strlen(nome) + 1);

	if (hospital == NULL){
		perror("cria_hospital(nome)");
		exit(EXIT_FAILURE);
	}

    hospital->id = id;
    /* Copia os dados para a lista alocada */
    strncpy(hospital->nome, nome, strlen(nome) + 1);
    hospital->idade = idade;
    hospital->gravidade = gravidade;
    hospital->tipo = tipo;

    return hospital;
}

lista_enc_t *ler_arquivo(char *nome_arquivo){
    char buffer[TAM_BUFFER];

    int id;
    char buffer_nome[TAM_BUFFER];
	int idade;
	char buffer_gravidade[TAM_BUFFER];
	char buffer_tipo[TAM_BUFFER];

    FILE *fp;

    lista_enc_t *lista;
    lista = cria_lista_enc();

    no_t *no;
    hospital_t *hospital;

	fp = fopen(nome_arquivo, "r");

	if (fp == NULL){
		perror("ler_arquivo");
		exit(EXIT_FAILURE);
	}
    sscanf(buffer, "%d, %99[^,], %d, %c, %c\n", &id, buffer_nome, &idade, buffer_gravidade, buffer_tipo);
    while(fgets(buffer, sizeof(buffer), fp) != NULL){
        sscanf(buffer, "%d, %99[^,], %d, %c, %c\n", &id, buffer_nome, &idade, buffer_gravidade, buffer_tipo);
        hospital = cria_paciente(id, buffer_nome, idade, buffer_gravidade, buffer_tipo); //cria uma "caixa" pra cada paciente
        no = cria_no(hospital);
        add_cauda(lista, no);
    }
    fclose(fp);
    return lista;
}

hospital_t *cria_paciente(int id, char *nome, int idade, char *gravidade, char *tipo){
    hospital_t *hospital;
    hospital = malloc(sizeof(hospital_t));

    hospital->id = id;

    hospital->nome = malloc(sizeof(char)*(strlen(nome)+1));
    strcpy(hospital->nome, nome);

    hospital->idade = idade;
    hospital->gravidade = gravidade;
    hospital->tipo = tipo;

    return hospital;
}

void imprimir_lista(lista_enc_t *lista){
    no_t *no;
    no = obtem_cabeca(lista);



    while(no != NULL){
        hospital_t *hospital;
        hospital = obtem_dado(no);
        printf("%d, %s, %d, %c, %c\n", hospital->id, hospital->nome, hospital->idade, hospital->gravidade, hospital->tipo);
        no = obtem_proximo(no);
    }
}

void libera_geral(lista_enc_t *lista){
    hospital_t *hospital;
    no_t *no;
    no_t *no_aux;

    no = obtem_cabeca(lista);
    while(no != NULL){
        hospital = obtem_dado(no);
        free(hospital->nome);
        free(hospital);
        no_aux = obtem_proximo(no);
        free(no);
        no = no_aux;
    }

    free(lista);
}
