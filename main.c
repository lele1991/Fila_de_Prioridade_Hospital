#include <stdio.h>
#include <stdlib.h>


#include "PRIORIDADE_HOSPITAL.h"
#include "lista_enc.h"

int main()
{
    lista_enc_t *lista;
    lista = ler_arquivo("hospital.csv");

    imprimir_lista(lista);
    libera_geral(lista);


    return 0;
}
