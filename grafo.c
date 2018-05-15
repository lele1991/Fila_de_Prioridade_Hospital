#include <stdlib.h>
#include <stdio.h>
#include "string.h"

#include "grafo.h"

#define DEBUG


struct vertices {
	int id;
	/* Dados do vértice */
	char *string;
};

struct arestas {
	int adj;
	/* mais informacoes, se necessario */
};

struct grafos{
	int n_vertices;
	vertice_t *vertices;
	aresta_t **matriz_adj;	/* Matriz de adjacencia */
};

void swap_string(grafo_t* grafo, int u, int v){
    char *temporario;

    temporario = obter_string(grafo, u);

    grafo->vertices[u].string = grafo->vertices[v].string;
    grafo->vertices[v].string = temporario;
}

void max_heapify(grafo_t *grafo, int i){
    int maior =0;
    int e = 2*i + 1;
    int d = 2*i + 2;

    if(e < grafo->n_vertices && (strcmp(grafo->vertices[e].string, grafo->vertices[i].string) < 0)){
        maior = e;
    }
    else
        maior = i;
    if(d < grafo->n_vertices && (strcmp(grafo->vertices[d].string, grafo->vertices[maior].string) < 0)){
        maior = d;
    }
    if(maior != i){
        swap_string(grafo, i, maior);
        max_heapify(grafo, maior);
    }
}

void libera_grafo (grafo_t *grafo){
    int i;
    if (grafo == NULL){
		perror("libera_grafo error");
		exit(EXIT_FAILURE);
	}

    for(i=0; i<grafo->n_vertices; i++){     //percorre todos os elementos
        free(grafo->matriz_adj[i]);         //o espaço do elemento
        free(grafo->vertices[i].string);    //o espaço da string
    }

    free(grafo->matriz_adj);                //o espaço da matriz
    free(grafo->vertices);                  //o espaço dos vértices
    free(grafo);                            //o espaço do grafo
}
/********************************************/

grafo_t *cria_grafo(int vertices){

	int i;
	aresta_t **matriz_adj;

	grafo_t *g = malloc(sizeof(grafo_t));
	if (g == NULL){
		perror("cria_grafo (g)");
		exit(EXIT_FAILURE);
	}

	g->n_vertices = vertices;

	g->vertices = malloc(vertices * sizeof(vertice_t));

	if (g->vertices == NULL){
		perror("cria_grafo (vertices)");
		exit(EXIT_FAILURE);
	}

	memset(g->vertices, 0, vertices * sizeof(vertice_t));

	matriz_adj = malloc(vertices * sizeof(aresta_t*));

	if (matriz_adj == NULL){
		perror("cria_grafo (matriz_adj)");
		exit(EXIT_FAILURE);
	}

	for ( i = 0; i < vertices; i++ ){
		matriz_adj[i] = malloc(vertices * sizeof(aresta_t));

		if (matriz_adj[i] == NULL){
			perror("cria_grafo (matriz_adj[i])");
			exit(EXIT_FAILURE);
		}
		/* Nenhuma adjacência */
		matriz_adj[i]->adj = 0;

	}

	g->matriz_adj = matriz_adj;

	return g;

}

/* Adiocina uma string como propriedade do vertice */
void adciona_string(grafo_t *g, int id, char *string){

	int str_size = 0;

	if (g == NULL){
		fprintf(stderr, "adciona_string: g invalido\n");
		exit(EXIT_FAILURE);
	}

	if (id > g->n_vertices)	{
		fprintf(stderr,"adciona_string: id invalido");
		exit(EXIT_FAILURE);
	}

	str_size = strlen(string);

	/* Tamanho da string: letras + '\0' */
	g->vertices[id].string = malloc(str_size + 1);
	strncpy(g->vertices[id].string, string, str_size + 1);

}

char * obter_string(grafo_t *g, int id){

	if (id >= 0 && id < g->n_vertices)
		return g->vertices[id].string;
	else
		return NULL;
}

int cria_adjacencia(grafo_t *g, int u, int v){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices )
		return FALSE;

	g->matriz_adj[u][v].adj = TRUE;
	g->matriz_adj[v][u].adj = TRUE;

	return TRUE;
}

int rem_adjacencia(grafo_t *g, int u, int v){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices)
		return FALSE;

	g->matriz_adj[u][v].adj = FALSE;
	g->matriz_adj[v][u].adj = FALSE;

	return TRUE;

}

int adjacente(grafo_t *g, int u, int v){

	if (u > g->n_vertices || v > g->n_vertices)
		return FALSE;

	return ((g->matriz_adj[u][v].adj));
}

void exportar_grafo_dot(const char *filename, grafo_t *grafo){
	FILE* file;
    int i, j;

	if (filename == NULL || grafo == NULL){
		fprintf(stderr, "exportar_grafp_dot: ponteiros invalidos\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(filename, "w");
	if (file == NULL){
		perror("exportar_grafp_dot:");
		exit(EXIT_FAILURE);
	}

	fprintf(file, "graph {\n");

	/* Exporta as strings dos vértices */
	for (i=0; i < grafo->n_vertices; i++){
		 fprintf(file, "\t%d [ label = \" (%d) %s \"];\n", i, i, grafo->vertices[i].string);
	}


    for( i = 0; i < grafo->n_vertices; i++ )
        for(j = i; j < grafo->n_vertices; j++)	// Exporta adjacencia na diagonal superior
            if( (grafo->matriz_adj[i][j].adj) == TRUE)
                fprintf(file, "\t%d -- %d;\n", i, j);

    fprintf(file, "}\n");
	fclose(file);
}
