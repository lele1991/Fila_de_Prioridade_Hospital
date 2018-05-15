#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#ifndef GRAFO_H_
#define GRAFO_H_

#define TRUE 1
#define FALSE 0


typedef struct vertices vertice_t;
typedef struct arestas aresta_t;
typedef struct grafos grafo_t;

grafo_t *cria_grafo(int vertices);
void libera_grafo (grafo_t *g);
int cria_adjacencia(grafo_t *g, int u, int v);
int rem_adjacencia(grafo_t *g, int u, int v);
int adjacente(grafo_t *g, int u, int v);

char * obter_string(grafo_t *g, int id);
void adciona_string(grafo_t *g, int id, char *string);
void swap_string(grafo_t *g, int u, int v); /**added*/

void max_heapify(grafo_t *g, int i);

void exportar_grafo_dot(const char *filename, grafo_t *grafo);

#endif /* GRAFO_H_ */


#endif // GRAFO_H_INCLUDED
