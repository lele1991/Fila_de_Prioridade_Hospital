#ifndef PRIORIDADE_HOSPITAL_H_INCLUDED
#define PRIORIDADE_HOSPITAL_H_INCLUDED


typedef struct paciente paciente_t;
typedef struct heap heap_t;

paciente_t *leitura_dinamica(int* tamanho);

void heapsort(int *tamanho);

void max_heapify(heap_t *heap, int i);

void swap_paciente(heap_t *heap, int i, int maior);
void random_paciente(paciente_t *pacientes, int tamanho);
int compara_pacientes(paciente_t *paciente_1, paciente_t *paciente_2);





void libera_geral(paciente_t *paciente);

#endif // PRIORIDADE_HOSPITAL_H_INCLUDED
