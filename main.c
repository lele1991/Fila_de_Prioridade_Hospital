#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "PRIORIDADE_HOSPITAL.h"
//#define DEBUG
int main(){
    int tamanho;
    int i, ran;


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
<<<<<<< HEAD
    exportar_heap("heap_dot", heap, 0);
=======
    exportar_heap("heap_dot", heap);
>>>>>>> Leticia

    for(i = 0; i<tamanho; i++){
        ran = rand() % 7001;        //0 a 9 seg
        Sleep(1000 + ran); //1000ms         chegando paciente
        heap_prioritario(heap);
    }
<<<<<<< HEAD



=======
>>>>>>> Leticia
    libera_geral(paciente, heap, tamanho);

    return 0;
}


//github readme.template
