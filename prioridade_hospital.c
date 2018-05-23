#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "PRIORIDADE_HOSPITAL.h"
#define TAM_BUFFER 100
//#define DEBUG

struct paciente{
	int id;
	char *nome; //malloc
	int idade;
	char gravidade;
	char tipo;
};

struct heap{
    int tam;
    paciente_t *paciente;
};

paciente_t *leitura_dinamica(int* tamanho){

    FILE *fp;
    int linhas=0,i=0;
    char buffer[100];
    char buffer_nome[100];
    paciente_t *dados;

    fp = fopen("hospital.csv", "r");printf("linhas: %d\n\n",linhas);
    if(fp==NULL){
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    //alocaçao pra saber quantidade de linhas
    while(fgets(buffer, 100, fp) != NULL) linhas++;
#ifdef DEBUG
printf("linhas: %d\n\n",linhas);
#endif


    printf("Legenda: *gravidade -- u->urgente  l->leve  m->moderado  // *tipo -- c->cabeca    t->tronco   i->inferiores\n\n");

    rewind(fp);

     dados = malloc(sizeof(paciente_t)*linhas);

     if (dados == NULL){
        perror("main:");
        exit(-1);
    }

    fgets(buffer,sizeof (buffer), fp); // pegando uma linha, "pulando a linha"
    //para saber quanto de espaço preciso pro nome
    while(fgets(buffer,sizeof (buffer), fp)!= NULL){
        sscanf(buffer,"%*d,%100[^,],%*d,%*c,%*c\n", buffer_nome);//salva no buffer pra saber os tamanhos
        dados[i].nome = malloc(sizeof(char) * strlen(buffer_nome)+1);
        i++;
    }

     rewind(fp);

    fgets(buffer,sizeof (buffer), fp); // pegando uma linha, "pulando a linha"
    i=0;

    // copiar do arquivo para posicoes do vetor
    while(fgets(buffer,sizeof (buffer), fp)!= NULL){
        sscanf(buffer, "%d,%100[^,],%d,%c,%c\n",
               &dados[i].id,
               dados[i].nome,
               &dados[i].idade,
               &dados[i].gravidade,
               &dados[i].tipo);

#ifdef DEBUG
printf("%d; %s; %d; %c; %c\n",dados[i].id, dados[i].nome, dados[i].idade, dados[i].gravidade, dados[i].tipo);
#endif // DEBUG
        i++;
    }

    fclose(fp);
    *tamanho = linhas;
    return dados;

}

void heap(paciente_t *dados, heap_t *heap, int tamanho){



}

void build_heap(heap_t *heap, paciente_t *paciente, int tamanho){   //cria heap de pacientes
    heap->tam = tamanho;

    heap->paciente = malloc((sizeof paciente_t)*tamanho);   //cria espaço pro heap
    memcpy(heap->paciente, paciente, sizeof(paciente_t)*tamanho); //copia pro heap

    for(i = floor(tamanho)/2; i>0; i--){
        max_heapify(heap->paciente, i);
    }
}

void max_heapify(heap_t *heap, int i){
    int e = 2*i + 1;
    int d = 2*i + 2;
    int maior;

    if((e < heap->tam) && (compara_pacientes(heap->paciente[e], heap->paciente[i]))){
        maior = e;
    }
    else
        maior = i;

    if((d < heap->tam) && (compara_pacientes(heap->paciente[d], heap->paciente[maior]))){
        maior = d;
    }
    if(maior != i){
        swap(heap, i, maior);
        max_heapify(heap, maior);
    }
}

void swap_paciente(heap_t *heap, int i, int maior){
    paciente_t paciente_temp;

    paciente_temp = heap->paciente[i]; //um paciente

    heap->paciente[i] = heap->paciente[maior];
    heap->paciente[maior] = paciente_temp;
}

int compara_pacientes(paciente_t *paciente_1, paciente_t *paciente_2){ //1 - paciente1 tem prioridade
    if(paciente_1->gravidade == paciente_2->gravidade){ // g-g --  l-l --  m-m
        if((paciente_1->idade - paciente_2->idade)>0){  //compara quem é mais velho
           return 1;
        }
        else
            return 0;
    }
    if((paciente_1->gravidade == 'g') && (paciente_2->gravidade == 'l')){
        return 1;
    }
    if((paciente_1->gravidade == 'l') && (paciente_2->gravidade == 'g')){
        return 0;
    }
    if((paciente_1->gravidade == 'g') && (paciente_2->gravidade == 'm')){
        return 1;
    }
    if((paciente_1->gravidade == 'm') && (paciente_2->gravidade == 'g')){
        return 0;
    }
    if((paciente_1->gravidade == 'm') && (paciente_2->gravidade == 'l')){
        return 1;
    }
    if((paciente_1->gravidade == 'l') && (paciente_2->gravidade == 'm')){
        return 0;
    }
}

void random_paciente(paciente_t *pacientes, int tamanho){ //embaralhando
    int i, ran;
    paciente_t paciente_copia; //um paciente - uma estrutura MESMO

    for(i = 0; i< tamanho; i++){
        paciente_copia = pacientes[i];  //copia p um auxiliar
        ran = rand() % tamanho;         //random
        pacientes[i] = pacientes[ran];  //troca
        pacientes[ran] = paciente_copia;//copia
    }
}

void libera_geral(paciente_t *paciente){

}


