#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "PRIORIDADE_HOSPITAL.h"
//#define DEBUG
int main(){
    int tamanho;
    int i;

    srand(time(NULL));

    paciente_t *paciente;
    paciente = leitura_dinamica(&tamanho);
#ifdef DEBUG
printf("\n\n");
#endif // DEBUG
    heap_t *heap;
    heap = cria_heap();

    random_paciente(paciente, tamanho);
#ifdef DEBUG
printf("\n\n");
#endif // DEBUG

    build_heap(heap, paciente, tamanho);

    for(i = 0; i<tamanho; i++){
        heap_prioritario(heap);
    }

    exportar_heap("heap_dot", heap, 0);

    libera_geral(paciente, heap, tamanho);

    return 0;
}


//github readme.template
