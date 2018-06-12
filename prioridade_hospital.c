#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "PRIORIDADE_HOSPITAL.h"
#define TAM_BUFFER 100
//#define DEBUG

struct paciente {
    int id;
    char *nome; //malloc
    int idade;
    char gravidade;
    char tipo;
};

struct heap {
    int tam;
    paciente_t *paciente;
};

paciente_t *leitura_dinamica(int* tamanho) {

    FILE *fp;
    int linhas=0,i=0;
    char buffer[100];
    char buffer_nome[100];
    paciente_t *dados;

    fp = fopen("hospital.csv", "r");
    if(fp==NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    fgets(buffer, 100, fp);
    //alocaçao pra saber quantidade de linhas
    while(fgets(buffer, 100, fp) != NULL) linhas++;
#ifdef DEBUG
    printf("linhas: %d\n\n",linhas);
#endif
    printf("Legenda: *gravidade -- u->urgente  l->leve  m->moderado  // *tipo -- c->cabeca    t->tronco   i->inferiores\n\n");
    rewind(fp);
    dados = malloc(sizeof(paciente_t)*linhas);

    if (dados == NULL) {
        perror("main:");
        exit(-1);
    }
    fgets(buffer,sizeof (buffer), fp); // pegando uma linha, "pulando a linha"
    //para saber quanto de espaço preciso pro nome
    while(fgets(buffer,sizeof (buffer), fp)!= NULL) {
        sscanf(buffer,"%*d,%100[^,],%*d,%*c,%*c\n", buffer_nome);//salva no buffer pra saber os tamanhos
        dados[i].nome = malloc(sizeof(char) * strlen(buffer_nome)+1);
        i++;
    }
    rewind(fp);
    fgets(buffer,sizeof (buffer), fp); // pegando uma linha, "pulando a linha"
    i=0;

    // copiar do arquivo para posicoes do vetor
    while(fgets(buffer,sizeof (buffer), fp)!= NULL) {
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

heap_t *cria_heap(){
    heap_t *heap;
    heap = malloc(sizeof(heap_t));
    return heap;
}
<<<<<<< HEAD
<<<<<<< HEAD
=======

void heap(paciente_t *paciente, heap_t *heap, int tamanho){
    build_heap(heap, paciente, tamanho);
    int i;
>>>>>>> Leticia

=======
//=======
>>>>>>> b4868b0fbf223680d1e9ef858ad50a856bd007a0

<<<<<<< HEAD
void random_tempo(){
//>>>>>>> Hellen
}

void build_heap(heap_t *heap, paciente_t *paciente, int tamanho) {  //cria heap de pacientes - ponteiro de ponteiro
=======
void build_heap(heap_t *heap, paciente_t *paciente, int tamanho) {  //cria heap de pacientes
>>>>>>> Leticia
    heap->tam = tamanho;
    int i=0;

    heap->paciente = malloc((sizeof(paciente_t )*tamanho));          //cria espaço pro heap - ponteiro de ponteiro
    memcpy(heap->paciente, paciente, sizeof(paciente_t )*tamanho);   //copia pro heap

    for(i = floor(tamanho)/2; i>0; i--) {
        max_heapify(heap, i);
    }
}

void max_heapify(heap_t *heap, int i) {
    int e = 2*i + 1;
    int d = 2*i + 2;
    int maior;

    if((e < heap->tam) && (compara_pacientes(&heap->paciente[e], &heap->paciente[i]))) {
        maior = e;
    } else
        maior = i;

    if((d < heap->tam) && (compara_pacientes(&heap->paciente[d], &heap->paciente[maior]))){
        maior = d;
    }
    if(maior != i) {
        swap_paciente(heap, i, maior);
        max_heapify(heap, maior);
    }
}

void swap_paciente(heap_t *heap, int i, int maior) {
    paciente_t paciente_temp;

    paciente_temp = heap->paciente[i]; //um paciente

    heap->paciente[i] = heap->paciente[maior];
    heap->paciente[maior] = paciente_temp;
}

int compara_pacientes(paciente_t *paciente_1, paciente_t *paciente_2) { //1 - paciente1 tem prioridade
    if(paciente_1->gravidade == paciente_2->gravidade) { // u-u --  l-l --  m-m
        if((paciente_1->idade - paciente_2->idade)>0) { //compara quem é mais velho
            return 1;
        } else
            return 0;
    }
    if((paciente_1->gravidade == 'u') && (paciente_2->gravidade == 'l')) {
        return 1;
    }
    if((paciente_1->gravidade == 'l') && (paciente_2->gravidade == 'u')) {
        return 0;
    }
    if((paciente_1->gravidade == 'u') && (paciente_2->gravidade == 'm')) {
        return 1;
    }
    if((paciente_1->gravidade == 'm') && (paciente_2->gravidade == 'u')) {
        return 0;
    }
    if((paciente_1->gravidade == 'm') && (paciente_2->gravidade == 'l')) {
        return 1;
    }
    if((paciente_1->gravidade == 'l') && (paciente_2->gravidade == 'm')) {
        return 0;
    }
    return 0;
}

void random_paciente(paciente_t *pacientes, int tamanho) { //embaralhando
    int i, ran;
    paciente_t paciente_copia; //um paciente - uma estrutura MESMO

    for(i = 0; i< tamanho; i++) {
        paciente_copia = pacientes[i];  //copia p um auxiliar
        ran = rand() % tamanho;         //random
        pacientes[i] = pacientes[ran];  //troca
        pacientes[ran] = paciente_copia;//copia
    }
#ifdef DEBUG
for(i = 0; i< tamanho; i++){
    printf("random:%s\n", pacientes[i].nome);
<<<<<<< HEAD
}
#endif // DEBUG
}
<<<<<<< HEAD
=======

void heap_prioritario(heap_t *heap) {   //paciente atendido vai pro final
    max_heapify(heap, 0);   //paciente com maior prioridade
>>>>>>> Leticia

void heap_prioritario(heap_t *heap) {
    max_heapify(heap, 0);                                       //paciente com maior prioridade
    int tamanho = heap->tam;
    // opera no [0]
//#ifdef DEBUG
    printf("Chamando paciente: %s\n", heap->paciente[0].nome);
    printf("Gravidade: %c\n", heap->paciente[0].gravidade);
    printf("Tipo do trauma: %c\n", heap->paciente[0].tipo);
    printf("Idade: %d\n\n", heap->paciente[0].idade);
<<<<<<< HEAD
    swap_paciente(heap, 0, heap->tam-1);                        //"tiro paciente da primeira posicao e jogo pro final
    heap->tam --;
=======
//#endif // DEBUG
    swap_paciente(heap, 0, tamanho-1);    //"tiro paciente da primeira posicao e jogo pro final
    tamanho --;
>>>>>>> b4868b0fbf223680d1e9ef858ad50a856bd007a0
}

void exportar_heap(const char *filename, heap_t *heap){
	FILE* file;
<<<<<<< HEAD
    int j, e, d;

=======
    int j;
>>>>>>> Leticia
	if (filename == NULL || heap == NULL){
		fprintf(stderr, "exportar_heap_dot: ponteiros invalidos\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(filename, "w");
	if (file == NULL){
		perror("exportar_grafo_dot:");
		exit(EXIT_FAILURE);
	}
	fprintf(file, "graph {\n");
<<<<<<< HEAD
    printf("\t tam: %d \n", heap->tam);
=======
	/* Exporta as strings dos vértices */
<<<<<<< HEAD

//	while(heap != NULL){
>>>>>>> b4868b0fbf223680d1e9ef858ad50a856bd007a0
        for(j = 0; j<heap->tam; j++){
            e = 2*j + 1;
            d = 2*j + 2;

            if (e < heap->tam)
                fprintf(file, "\t\"%s\" -- \"%s\";\n",heap->paciente[j].nome , heap->paciente[e].nome);
            if (d < heap->tam)
<<<<<<< HEAD
                fprintf(file, "\t%s -- %s;\n",heap->paciente[j].nome , heap->paciente[d].nome);
=======
                fprintf(file, "\t\"%s\" -- \"%s\";\n",heap->paciente[j].nome , heap->paciente[d].nome);
>>>>>>> b4868b0fbf223680d1e9ef858ad50a856bd007a0
        }
=======
    for(j = 0; j<heap->tam; j++){
        int e = 2*j + 1;
        int d = 2*j + 2;
        if(e<heap->tam)
            fprintf(file, "\t \"%s\" -- \"%s\";\n",heap->paciente[j].nome , heap->paciente[e].nome);
        if(d<heap->tam)
            fprintf(file, "\t \"%s\" -- \"%s\";\n",heap->paciente[j].nome , heap->paciente[d].nome);
    }
>>>>>>> Leticia
    fprintf(file, "}\n");
	fclose(file);
}

void libera_geral(paciente_t *dados, heap_t *heap, int *tamanho){
    int i;
    //liberar o nome (malloc)
    for(i = 0; i<tamanho; i++){
<<<<<<< HEAD
        free(dados[i].nome);            //nome
    }
    free(dados);                        //dados
    free(heap->paciente);               //heap->paciente
    free(heap);                         //heap
=======
        free(dados[i].nome);     //nome
    }
    free(dados);                 //dados
    free(heap->paciente);       //heap->paciente
    free(heap);                //heap
>>>>>>> Leticia
}
