# priorityQueue_Hospital

#A cada paciente que chega em um hospital
#é verificado qual a urgência, a idade e o tipo.
#De acordo com a urgência, se chega outro paciente
#com a mesma urgência, é verificada a idade, 
#sendo assim, o mais velho tem a prioridade.
#O tipo recebido, é para que seja levado ao respectivo setor.

#A urgência se dá por: u - urgente
#					   l - leve
#					   m - moderado  

#O tipo se dá por: c - cabeça
#				   t - tronco
#				   i - inferiores

#Utilizando dessa forma O MAX_HEAPIFY.
#-> O heap é uma estrutura de dados que pode ser visto como uma árvore
#binária praticamente completa.
# * máximo: para todo vértice i diferente da raiz:
#dado[pai(i)] >= dado[i]

#exemplo:
#		100 (pai)  
#		/ \
#	  45    36 (dado)
#     /\    /\
#    32 30 25 22

#Pode ser utilizado em qualquer plataforma que receba o código em C.
#há uma lista de pacientes que está em arquivo '.csv' que pode ser modificada como desejar.
