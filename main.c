#include <stdio.h>
#include <stdlib.h>

#include "PRIORIDADE_HOSPITAL.h"


int main()
{
    int tamanho;
    leitura_dinamica(&tamanho);
    prioridade_sort(&tamanho);
    return 0;
}
